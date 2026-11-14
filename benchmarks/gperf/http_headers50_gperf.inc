/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf http_headers50.gperf  */
/* Computed positions: -k'1,$' */

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

#line 1 "http_headers50.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-strncmp: strncmp without a length table: faster on this set's short keys.
   Regenerate with regenerate.sh. */
#line 14 "http_headers50.gperf"
struct HttpHeaders50GperfEntry { const char *name; int value; };
/* maximum key range = 58, duplicates = 0 */

class HttpHeaders50Gperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct HttpHeaders50GperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
HttpHeaders50Gperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 10, 62,  0,  0, 15,
       0, 62,  0,  0, 62,  5,  0, 25, 62,  0,
      25, 62, 30, 40, 10,  0, 25, 30, 15, 62,
      62, 62, 62, 62, 62, 62, 62, 10, 62, 62,
      45,  5, 62, 10, 20, 62, 62, 62, 40,  0,
       0, 62, 62, 62, 15, 20, 15, 62, 62,  0,
      62, 20, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62
    };
  return len + asso_values[static_cast<unsigned char>(str[len - 1])] + asso_values[static_cast<unsigned char>(str[0])];
}

const struct HttpHeaders50GperfEntry *
HttpHeaders50Gperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 50,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 61
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct HttpHeaders50GperfEntry wordlist[] =
    {
      {""}, {""}, {""}, {""},
#line 36 "http_headers50.gperf"
      {"From", 20},
      {""},
#line 47 "http_headers50.gperf"
      {"Origin", 31},
      {""},
#line 45 "http_headers50.gperf"
      {"Location", 29},
#line 32 "http_headers50.gperf"
      {"Date", 16},
#line 25 "http_headers50.gperf"
      {"Connection", 9},
#line 31 "http_headers50.gperf"
      {"Cookie", 15},
#line 59 "http_headers50.gperf"
      {"Upgrade", 43},
#line 41 "http_headers50.gperf"
      {"If-Range", 25},
      {""},
#line 22 "http_headers50.gperf"
      {"Allow", 6},
#line 29 "http_headers50.gperf"
      {"Content-Location", 13},
#line 30 "http_headers50.gperf"
      {"Content-Type", 14},
#line 21 "http_headers50.gperf"
      {"Age", 5},
#line 37 "http_headers50.gperf"
      {"Host", 21},
#line 43 "http_headers50.gperf"
      {"Keep-Alive", 27},
#line 27 "http_headers50.gperf"
      {"Content-Language", 11},
#line 39 "http_headers50.gperf"
      {"If-Modified-Since", 23},
#line 23 "http_headers50.gperf"
      {"Authorization", 7},
#line 42 "http_headers50.gperf"
      {"If-Unmodified-Since", 26},
#line 60 "http_headers50.gperf"
      {"User-Agent", 44},
#line 26 "http_headers50.gperf"
      {"Content-Encoding", 10},
#line 56 "http_headers50.gperf"
      {"TE", 40},
#line 38 "http_headers50.gperf"
      {"If-Match", 22},
#line 33 "http_headers50.gperf"
      {"ETag", 17},
#line 19 "http_headers50.gperf"
      {"Accept-Language", 3},
#line 16 "http_headers50.gperf"
      {"Accept", 0},
#line 57 "http_headers50.gperf"
      {"Trailer", 41},
#line 40 "http_headers50.gperf"
      {"If-None-Match", 24},
#line 28 "http_headers50.gperf"
      {"Content-Length", 12},
#line 18 "http_headers50.gperf"
      {"Accept-Encoding", 2},
#line 34 "http_headers50.gperf"
      {"Expect", 18},
#line 58 "http_headers50.gperf"
      {"Transfer-Encoding", 42},
#line 62 "http_headers50.gperf"
      {"Via", 46},
#line 17 "http_headers50.gperf"
      {"Accept-Charset", 1},
#line 51 "http_headers50.gperf"
      {"Range", 35},
#line 48 "http_headers50.gperf"
      {"Pragma", 32},
#line 35 "http_headers50.gperf"
      {"Expires", 19},
#line 20 "http_headers50.gperf"
      {"Accept-Ranges", 4},
#line 50 "http_headers50.gperf"
      {"Proxy-Authorization", 34},
#line 65 "http_headers50.gperf"
      {"X-Forwarded-For", 49},
      {""},
#line 64 "http_headers50.gperf"
      {"Warning", 48},
#line 49 "http_headers50.gperf"
      {"Proxy-Authenticate", 33},
#line 61 "http_headers50.gperf"
      {"Vary", 45},
      {""},
#line 63 "http_headers50.gperf"
      {"WWW-Authenticate", 47},
#line 52 "http_headers50.gperf"
      {"Referer", 36},
#line 24 "http_headers50.gperf"
      {"Cache-Control", 8},
      {""},
#line 55 "http_headers50.gperf"
      {"Set-Cookie", 39},
#line 53 "http_headers50.gperf"
      {"Retry-After", 37},
#line 46 "http_headers50.gperf"
      {"Max-Forwards", 30},
#line 44 "http_headers50.gperf"
      {"Last-Modified", 28},
      {""}, {""},
#line 54 "http_headers50.gperf"
      {"Server", 38}
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
  return static_cast<struct HttpHeaders50GperfEntry *> (0);
}
#line 66 "http_headers50.gperf"

