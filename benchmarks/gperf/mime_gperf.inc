/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf mime.gperf  */
/* Computed positions: -k'7,13' */

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

#line 1 "mime.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-lengths: lengths first, then memcmp: faster than strncmp on this set's long or
   similar keys.
   Regenerate with regenerate.sh. */
#line 15 "mime.gperf"
struct MimeGperfEntry { const char *name; int value; };
/* maximum key range = 23, duplicates = 0 */

class MimeGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct MimeGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
MimeGperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31,  0, 31, 31,
      31, 31, 31,  3, 31, 31, 10, 31, 13,  5,
      31,  0, 10, 31, 31,  0,  9, 31, 31,  3,
       9, 31, 15, 31, 31, 31, 31, 31, 31, 31,
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
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[12])];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 12:
      case 11:
      case 10:
      case 9:
      case 8:
      case 7:
        hval += asso_values[static_cast<unsigned char>(str[6])];
        break;
    }
  return hval;
}

const struct MimeGperfEntry *
MimeGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 15,
      MIN_WORD_LENGTH = 8,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 8,
      MAX_HASH_VALUE = 30
    };

  static const unsigned char lengthtable[] =
    {
       0,  0,  0,  0,  0,  0,  0,  0,  8,  9, 10,  0,  9, 10,
       9, 10,  0,  0,  9,  9, 10,  0,  0, 10, 15, 15, 16,  0,
       0,  0, 15
    };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct MimeGperfEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 19 "mime.gperf"
      {"text/css", 2},
#line 31 "mime.gperf"
      {"font/woff", 14},
#line 30 "mime.gperf"
      {"font/woff2", 13},
      {""},
#line 26 "mime.gperf"
      {"image/gif", 9},
#line 27 "mime.gperf"
      {"image/webp", 10},
#line 29 "mime.gperf"
      {"video/mp4", 12},
#line 28 "mime.gperf"
      {"audio/mpeg", 11},
      {""}, {""},
#line 17 "mime.gperf"
      {"text/html", 0},
#line 24 "mime.gperf"
      {"image/png", 7},
#line 25 "mime.gperf"
      {"image/jpeg", 8},
      {""}, {""},
#line 18 "mime.gperf"
      {"text/plain", 1},
#line 21 "mime.gperf"
      {"application/xml", 4},
#line 22 "mime.gperf"
      {"application/pdf", 5},
#line 20 "mime.gperf"
      {"application/json", 3},
      {""}, {""}, {""},
#line 23 "mime.gperf"
      {"application/zip", 6}
    };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic pop
#endif

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == lengthtable[key])
          {
            const char *s = wordlist[key].name;

            if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
              return &wordlist[key];
          }
    }
  return static_cast<struct MimeGperfEntry *> (0);
}
#line 32 "mime.gperf"

