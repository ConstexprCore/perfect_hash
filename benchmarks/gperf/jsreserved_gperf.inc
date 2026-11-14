/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf jsreserved.gperf  */
/* Computed positions: -k'1-2' */

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

#line 1 "jsreserved.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-strncmp: strncmp without a length table: faster on this set's short keys.
   Regenerate with regenerate.sh. */
#line 14 "jsreserved.gperf"
struct JsReservedGperfEntry { const char *name; int value; };
/* maximum key range = 64, duplicates = 0 */

class JsReservedGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct JsReservedGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
JsReservedGperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 15, 40,  0,
       0,  0, 10, 66, 25,  0, 66, 66, 55,  5,
       0, 20,  5, 66, 20, 10, 20, 20, 30, 25,
      40, 35, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66
    };
  return len + asso_values[static_cast<unsigned char>(str[1])] + asso_values[static_cast<unsigned char>(str[0])];
}

const struct JsReservedGperfEntry *
JsReservedGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 45,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 10,
      MIN_HASH_VALUE = 2,
      MAX_HASH_VALUE = 65
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct JsReservedGperfEntry wordlist[] =
    {
      {""}, {""},
#line 37 "jsreserved.gperf"
      {"in", 21},
#line 39 "jsreserved.gperf"
      {"new", 23},
#line 28 "jsreserved.gperf"
      {"enum", 12},
      {""},
#line 25 "jsreserved.gperf"
      {"delete", 9},
#line 24 "jsreserved.gperf"
      {"default", 8},
#line 23 "jsreserved.gperf"
      {"debugger", 7},
#line 55 "jsreserved.gperf"
      {"interface", 39},
#line 38 "jsreserved.gperf"
      {"instanceof", 22},
#line 36 "jsreserved.gperf"
      {"import", 20},
#line 35 "jsreserved.gperf"
      {"if", 19},
      {""}, {""},
#line 54 "jsreserved.gperf"
      {"implements", 38},
      {""},
#line 32 "jsreserved.gperf"
      {"finally", 16},
      {""},
#line 18 "jsreserved.gperf"
      {"case", 2},
#line 19 "jsreserved.gperf"
      {"catch", 3},
      {""},
#line 26 "jsreserved.gperf"
      {"do", 10},
      {""},
#line 40 "jsreserved.gperf"
      {"null", 24},
#line 21 "jsreserved.gperf"
      {"const", 5},
#line 41 "jsreserved.gperf"
      {"return", 25},
#line 56 "jsreserved.gperf"
      {"package", 40},
#line 22 "jsreserved.gperf"
      {"continue", 6},
#line 52 "jsreserved.gperf"
      {"with", 36},
#line 31 "jsreserved.gperf"
      {"false", 15},
#line 59 "jsreserved.gperf"
      {"public", 43},
#line 57 "jsreserved.gperf"
      {"private", 41},
#line 33 "jsreserved.gperf"
      {"for", 17},
#line 58 "jsreserved.gperf"
      {"protected", 42},
#line 42 "jsreserved.gperf"
      {"super", 26},
#line 60 "jsreserved.gperf"
      {"static", 44},
      {""},
#line 34 "jsreserved.gperf"
      {"function", 18},
      {""},
#line 53 "jsreserved.gperf"
      {"yield", 37},
#line 43 "jsreserved.gperf"
      {"switch", 27},
      {""},
#line 47 "jsreserved.gperf"
      {"try", 31},
#line 46 "jsreserved.gperf"
      {"true", 30},
#line 16 "jsreserved.gperf"
      {"await", 0},
#line 29 "jsreserved.gperf"
      {"export", 13},
#line 30 "jsreserved.gperf"
      {"extends", 14},
#line 49 "jsreserved.gperf"
      {"var", 33},
#line 44 "jsreserved.gperf"
      {"this", 28},
#line 45 "jsreserved.gperf"
      {"throw", 29},
      {""}, {""}, {""},
#line 50 "jsreserved.gperf"
      {"void", 34},
#line 51 "jsreserved.gperf"
      {"while", 35},
      {""}, {""}, {""},
#line 27 "jsreserved.gperf"
      {"else", 11},
#line 20 "jsreserved.gperf"
      {"class", 4},
#line 48 "jsreserved.gperf"
      {"typeof", 32},
      {""}, {""}, {""},
#line 17 "jsreserved.gperf"
      {"break", 1}
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
  return static_cast<struct JsReservedGperfEntry *> (0);
}
#line 61 "jsreserved.gperf"

