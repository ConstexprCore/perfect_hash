/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf stock.gperf  */
/* Computed positions: -k'1-4' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "stock.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-strncmp: strncmp without a length table: faster on this set's short keys.
   Regenerate with regenerate.sh. */
#line 14 "stock.gperf"
struct StockGperfEntry { const char *name; int value; };
/* maximum key range = 238, duplicates = 0 */

class StockGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct StockGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
StockGperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239,  35,  60,   5,  25,  50,
       70,  20, 110,  60,  40,  55,  75,   0,  25,  10,
       30,   0,   2,   5,   0, 100,  17,   2,  37,  80,
       35, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239, 239, 239, 239, 239,
      239, 239, 239, 239, 239, 239
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[3])];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[static_cast<unsigned char>(str[2])];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[static_cast<unsigned char>(str[1])];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[static_cast<unsigned char>(str[0])];
        break;
    }
  return hval;
}

const struct StockGperfEntry *
StockGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 100,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 5,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 238
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct StockGperfEntry wordlist[] =
    {
      {""},
#line 102 "stock.gperf"
      {"T", 86},
      {""},
#line 81 "stock.gperf"
      {"MMM", 65},
      {""},
#line 115 "stock.gperf"
      {"WMT", 99},
#line 34 "stock.gperf"
      {"C", 18},
#line 84 "stock.gperf"
      {"MS", 68},
      {""}, {""},
#line 42 "stock.gperf"
      {"CRM", 26},
      {""},
#line 82 "stock.gperf"
      {"MO", 66},
#line 104 "stock.gperf"
      {"TMO", 88},
      {""}, {""}, {""},
#line 100 "stock.gperf"
      {"SO", 84},
#line 112 "stock.gperf"
      {"V", 96},
#line 96 "stock.gperf"
      {"QCOM", 80},
#line 38 "stock.gperf"
      {"CMCSA", 22},
      {""},
#line 58 "stock.gperf"
      {"GM", 42},
#line 103 "stock.gperf"
      {"TGT", 87},
#line 41 "stock.gperf"
      {"COST", 25},
      {""}, {""},
#line 60 "stock.gperf"
      {"GS", 44},
#line 78 "stock.gperf"
      {"MDT", 62},
#line 43 "stock.gperf"
      {"CSCO", 27},
#line 44 "stock.gperf"
      {"CVS", 28},
      {""},
#line 94 "stock.gperf"
      {"PM", 78},
#line 76 "stock.gperf"
      {"MCD", 60},
      {""}, {""}, {""},
#line 75 "stock.gperf"
      {"MA", 59},
#line 24 "stock.gperf"
      {"AMT", 8},
      {""},
#line 49 "stock.gperf"
      {"DOW", 33},
      {""},
#line 97 "stock.gperf"
      {"RTX", 81},
#line 35 "stock.gperf"
      {"CAT", 19},
      {""}, {""}, {""},
#line 55 "stock.gperf"
      {"GD", 39},
#line 40 "stock.gperf"
      {"COP", 24},
      {""}, {""}, {""},
#line 93 "stock.gperf"
      {"PG", 77},
#line 79 "stock.gperf"
      {"MET", 63},
#line 113 "stock.gperf"
      {"VZ", 97},
#line 51 "stock.gperf"
      {"EMR", 35},
      {""}, {""},
#line 101 "stock.gperf"
      {"SPG", 85},
      {""},
#line 83 "stock.gperf"
      {"MRK", 67},
      {""},
#line 45 "stock.gperf"
      {"CVX", 29},
#line 22 "stock.gperf"
      {"AMD", 6},
#line 59 "stock.gperf"
      {"GOOG", 43},
#line 107 "stock.gperf"
      {"TXN", 91},
      {""},
#line 70 "stock.gperf"
      {"KO", 54},
#line 19 "stock.gperf"
      {"ACN", 3},
      {""}, {""},
#line 53 "stock.gperf"
      {"F", 37},
#line 56 "stock.gperf"
      {"GE", 40},
#line 68 "stock.gperf"
      {"JPM", 52},
      {""}, {""}, {""},
#line 46 "stock.gperf"
      {"DE", 30},
#line 73 "stock.gperf"
      {"LMT", 57},
#line 85 "stock.gperf"
      {"MSFT", 69},
#line 114 "stock.gperf"
      {"WFC", 98},
      {""},
#line 37 "stock.gperf"
      {"CL", 21},
      {""},
#line 23 "stock.gperf"
      {"AMGN", 7},
      {""},
#line 26 "stock.gperf"
      {"AVGO", 10},
      {""},
#line 39 "stock.gperf"
      {"COF", 23},
#line 80 "stock.gperf"
      {"META", 64},
#line 74 "stock.gperf"
      {"LOW", 58},
#line 66 "stock.gperf"
      {"ISRG", 50},
      {""},
#line 48 "stock.gperf"
      {"DIS", 32},
#line 64 "stock.gperf"
      {"INTC", 48},
#line 52 "stock.gperf"
      {"EXC", 36},
#line 90 "stock.gperf"
      {"ORCL", 74},
#line 28 "stock.gperf"
      {"BA", 12},
#line 18 "stock.gperf"
      {"ABT", 2},
#line 25 "stock.gperf"
      {"AMZN", 9},
      {""}, {""}, {""},
#line 29 "stock.gperf"
      {"BAC", 13},
      {""},
#line 27 "stock.gperf"
      {"AXP", 11},
#line 89 "stock.gperf"
      {"NVDA", 73},
      {""},
#line 67 "stock.gperf"
      {"JNJ", 51},
#line 105 "stock.gperf"
      {"TMUS", 89},
      {""}, {""}, {""},
#line 91 "stock.gperf"
      {"PEP", 75},
      {""}, {""}, {""},
#line 30 "stock.gperf"
      {"BK", 14},
#line 21 "stock.gperf"
      {"AIG", 5},
#line 106 "stock.gperf"
      {"TSLA", 90},
      {""},
#line 36 "stock.gperf"
      {"CHTR", 20},
      {""},
#line 63 "stock.gperf"
      {"IBM", 47},
      {""}, {""},
#line 99 "stock.gperf"
      {"SCHW", 83},
      {""},
#line 86 "stock.gperf"
      {"NEE", 70},
      {""}, {""}, {""}, {""},
#line 88 "stock.gperf"
      {"NKE", 72},
      {""},
#line 54 "stock.gperf"
      {"FDX", 38},
      {""},
#line 61 "stock.gperf"
      {"HD", 45},
#line 110 "stock.gperf"
      {"UPS", 94},
#line 77 "stock.gperf"
      {"MDLZ", 61},
#line 47 "stock.gperf"
      {"DHR", 31},
      {""}, {""},
#line 33 "stock.gperf"
      {"BMY", 17},
      {""}, {""}, {""}, {""},
#line 62 "stock.gperf"
      {"HON", 46},
      {""}, {""}, {""}, {""},
#line 92 "stock.gperf"
      {"PFE", 76},
      {""}, {""}, {""}, {""},
#line 109 "stock.gperf"
      {"UNP", 93},
      {""}, {""}, {""}, {""},
#line 71 "stock.gperf"
      {"LIN", 55},
#line 31 "stock.gperf"
      {"BKNG", 15},
      {""}, {""}, {""},
#line 111 "stock.gperf"
      {"USB", 95},
      {""}, {""}, {""}, {""},
#line 69 "stock.gperf"
      {"KHC", 53},
#line 20 "stock.gperf"
      {"ADBE", 4},
      {""},
#line 17 "stock.gperf"
      {"ABBV", 1},
      {""}, {""},
#line 16 "stock.gperf"
      {"AAPL", 0},
      {""}, {""}, {""},
#line 50 "stock.gperf"
      {"DUK", 34},
#line 57 "stock.gperf"
      {"GILD", 41},
      {""}, {""}, {""}, {""},
#line 65 "stock.gperf"
      {"INTU", 49},
      {""}, {""}, {""},
#line 32 "stock.gperf"
      {"BLK", 16},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 98 "stock.gperf"
      {"SBUX", 82},
      {""}, {""}, {""}, {""},
#line 87 "stock.gperf"
      {"NFLX", 71},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 95 "stock.gperf"
      {"PYPL", 79},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 72 "stock.gperf"
      {"LLY", 56},
      {""}, {""}, {""}, {""},
#line 108 "stock.gperf"
      {"UNH", 92}
    };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic pop
#endif

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          const char *s = wordlist[key].name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &wordlist[key];
        }
    }
  return static_cast<struct StockGperfEntry *> (0);
}
#line 116 "stock.gperf"

