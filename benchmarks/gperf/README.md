# gperf generated files

The `*_gperf.inc` files are generated from the corresponding `.gperf` input files
using [GNU gperf](https://www.gnu.org/software/gperf/).

## Regenerating

```bash
cd benchmarks/gperf
for f in protocol stock keyword header mime; do
  gperf "${f}.gperf" > "${f}_gperf.inc"
done
```

The generated files use `register`, which is removed since it is not valid in C++17:

```bash
sed -i 's/register //g' *_gperf.inc
```

On macOS, use `sed -i ''` instead.
