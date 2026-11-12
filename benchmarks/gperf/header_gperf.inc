/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf header.gperf  */
/* Computed positions: -k'1' */

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

#line 1 "header.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-strncmp: strncmp without a length table: faster on this set's short keys.
   Regenerate with regenerate.sh. */
#line 14 "header.gperf"
struct HeaderGperfEntry { const char *name; int value; };
/* maximum key range = 28, duplicates = 0 */

class HeaderGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct HeaderGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
HeaderGperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31,  5, 31,  0, 15, 31,
      31, 31,  5, 10, 31, 31,  0, 31, 31, 10,
      31, 31,  0, 15, 31, 20,  0, 31,  0, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31
    };
  return len + asso_values[static_cast<unsigned char>(str[0])];
}

const struct HeaderGperfEntry *
HeaderGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 20,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 15,
      MIN_HASH_VALUE = 3,
      MAX_HASH_VALUE = 30
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct HeaderGperfEntry wordlist[] =
    {
      {""}, {""}, {""},
#line 34 "header.gperf"
      {"Via", 18},
#line 33 "header.gperf"
      {"Vary", 17},
      {""},
#line 23 "header.gperf"
      {"Cookie", 7},
#line 29 "header.gperf"
      {"Referer", 13},
#line 27 "header.gperf"
      {"Location", 11},
#line 25 "header.gperf"
      {"Host", 9},
#line 20 "header.gperf"
      {"Connection", 4},
#line 16 "header.gperf"
      {"Accept", 0},
#line 22 "header.gperf"
      {"Content-Type", 6},
#line 19 "header.gperf"
      {"Cache-Control", 3},
#line 21 "header.gperf"
      {"Content-Length", 5},
#line 35 "header.gperf"
      {"X-Forwarded-For", 19},
#line 28 "header.gperf"
      {"Origin", 12},
      {""},
#line 18 "header.gperf"
      {"Authorization", 2},
#line 24 "header.gperf"
      {"Date", 8},
#line 17 "header.gperf"
      {"Accept-Encoding", 1},
#line 30 "header.gperf"
      {"Server", 14},
      {""},
#line 26 "header.gperf"
      {"If-None-Match", 10},
      {""},
#line 31 "header.gperf"
      {"Set-Cookie", 15},
      {""}, {""}, {""}, {""},
#line 32 "header.gperf"
      {"User-Agent", 16}
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
  return static_cast<struct HeaderGperfEntry *> (0);
}
#line 36 "header.gperf"

