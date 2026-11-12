# gperf baselines

The `*_gperf.inc` files are generated from the `.gperf` inputs next to them
(and, for the ticker sets, from `../data/sp500.gperf` and `../data/nasdaq.gperf`,
which `../data/gen_symbol_headers.py` writes) with
[GNU gperf](https://www.gnu.org/software/gperf/) 3.3.

## Regenerating

```bash
benchmarks/gperf/regenerate.sh            # uses `gperf` from PATH
benchmarks/gperf/regenerate.sh /opt/homebrew/bin/gperf
```

Use gperf 3.1 or newer. Apple's `/usr/bin/gperf` is 3.0.3, which emits
`register`, a keyword C++17 removed.

## Options

Every input is a map, like the other methods in the benchmark: `%struct-type`
with an `int` value (the key's declaration index), and the wrapper returns
`entry->value`. All inputs also use `%readonly-tables` and `%enum`.

The string comparison is chosen per set, by measurement (Apple M3 Max, clang 22,
issue #29):

| Option | Sets | Why |
|---|---|---|
| `%compare-lengths` | MIME types, letters, counters, Java FQCNs | Checking the length table and then calling `memcmp` beats `strncmp` on long or similar keys. FQCN hits went from 12.2 to 4.3 ns, MIME from 9.0 to 6.4 ns. |
| `%compare-strncmp` | the other sets, and the S&P 500 / Nasdaq tickers | On short keys the length table costs more than it saves. S&P 100 misses went from 1.8 to 4.0 ns with it. |

Two more options were measured and are not used:

- `%switch=1` was slower on every set, up to 2.6x on hits.
- `-m 10000` (more iterations for smaller asso values) shrank some tables but
  made no consistent difference to lookup time.
