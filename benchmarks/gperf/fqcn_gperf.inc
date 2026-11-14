/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf fqcn.gperf  */
/* Computed positions: -k'27' */

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

#line 1 "fqcn.gperf"

#include <cstring>
/* A map, like the other benchmark methods: the value is the declaration index.
   %compare-lengths: lengths first, then memcmp: faster than strncmp on this set's long or
   similar keys.
   Regenerate with regenerate.sh. */
#line 15 "fqcn.gperf"
struct FqcnGperfEntry { const char *name; int value; };
/* maximum key range = 65, duplicates = 0 */

class FqcnGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct FqcnGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
FqcnGperf::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 30, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 10, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 45, 10,
       0, 45, 10, 89,  0, 15, 89, 89, 89, 89,
       0, 25, 89, 89, 20, 30,  0, 30, 89, 89,
      89,  0, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89, 89, 89, 89, 89,
      89, 89, 89, 89, 89, 89
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[26])];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 26:
      case 25:
      case 24:
        break;
    }
  return hval;
}

const struct FqcnGperfEntry *
FqcnGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 40,
      MIN_WORD_LENGTH = 24,
      MAX_WORD_LENGTH = 54,
      MIN_HASH_VALUE = 24,
      MAX_HASH_VALUE = 88
    };

  static const unsigned char lengthtable[] =
    {
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 25, 26, 27,
       0, 29, 30, 31,  0, 33,  0,  0, 36,  0, 38, 39, 40, 41,
       0, 43, 29, 45, 46,  0, 38, 39,  0, 41,  0, 43, 54, 35,
       0, 27, 38, 34, 50, 46, 42, 33, 54,  0,  0,  0, 43, 44,
       0,  0, 27, 43, 29,  0,  0,  0, 48, 49,  0,  0,  0, 38,
       0,  0,  0,  0, 43
    };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct FqcnGperfEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 41 "fqcn.gperf"
      {"java.net.http.HttpClient", 24},
#line 37 "fqcn.gperf"
      {"java.io.ObjectInputStream", 20},
#line 30 "fqcn.gperf"
      {"java.util.stream.IntStream", 13},
#line 42 "fqcn.gperf"
      {"java.security.MessageDigest", 25},
      {""},
#line 45 "fqcn.gperf"
      {"java.time.temporal.ChronoUnit", 28},
#line 34 "fqcn.gperf"
      {"java.lang.invoke.MethodHandles", 17},
#line 46 "fqcn.gperf"
      {"javax.crypto.spec.SecretKeySpec", 29},
      {""},
#line 39 "fqcn.gperf"
      {"java.nio.charset.StandardCharsets", 22},
      {""}, {""},
#line 47 "fqcn.gperf"
      {"org.apache.commons.lang3.StringUtils", 30},
      {""},
#line 31 "fqcn.gperf"
      {"java.util.regex.PatternSyntaxException", 14},
#line 25 "fqcn.gperf"
      {"java.util.concurrent.ThreadPoolExecutor", 8},
#line 26 "fqcn.gperf"
      {"java.util.concurrent.LinkedBlockingQueue", 9},
#line 19 "fqcn.gperf"
      {"java.util.concurrent.CopyOnWriteArrayList", 2},
      {""},
#line 38 "fqcn.gperf"
      {"java.nio.channels.AsynchronousSocketChannel", 21},
#line 27 "fqcn.gperf"
      {"java.util.function.BiFunction", 10},
#line 53 "fqcn.gperf"
      {"com.fasterxml.jackson.annotation.JsonProperty", 36},
#line 49 "fqcn.gperf"
      {"org.springframework.context.ApplicationContext", 32},
      {""},
#line 43 "fqcn.gperf"
      {"java.security.spec.PKCS8EncodedKeySpec", 26},
#line 54 "fqcn.gperf"
      {"com.google.common.collect.ImmutableList", 37},
      {""},
#line 20 "fqcn.gperf"
      {"java.util.concurrent.atomic.AtomicInteger", 3},
      {""},
#line 21 "fqcn.gperf"
      {"java.util.concurrent.atomic.AtomicLongArray", 4},
#line 50 "fqcn.gperf"
      {"org.springframework.web.bind.annotation.RequestMapping", 33},
#line 33 "fqcn.gperf"
      {"java.lang.reflect.ParameterizedType", 16},
      {""},
#line 29 "fqcn.gperf"
      {"java.util.stream.Collectors", 12},
#line 17 "fqcn.gperf"
      {"java.util.concurrent.ConcurrentHashMap", 0},
#line 44 "fqcn.gperf"
      {"java.time.format.DateTimeFormatter", 27},
#line 55 "fqcn.gperf"
      {"com.google.common.util.concurrent.ListenableFuture", 38},
#line 48 "fqcn.gperf"
      {"org.apache.commons.collections4.MultiValuedMap", 31},
#line 18 "fqcn.gperf"
      {"java.util.concurrent.ConcurrentLinkedQueue", 1},
#line 28 "fqcn.gperf"
      {"java.util.function.ToLongFunction", 11},
#line 51 "fqcn.gperf"
      {"org.springframework.beans.factory.annotation.Autowired", 34},
      {""}, {""}, {""},
#line 32 "fqcn.gperf"
      {"java.lang.reflect.InvocationTargetException", 15},
#line 56 "fqcn.gperf"
      {"io.netty.channel.socket.nio.NioSocketChannel", 39},
      {""}, {""},
#line 35 "fqcn.gperf"
      {"java.lang.ref.WeakReference", 18},
#line 40 "fqcn.gperf"
      {"java.nio.file.attribute.BasicFileAttributes", 23},
#line 36 "fqcn.gperf"
      {"java.io.ByteArrayOutputStream", 19},
      {""}, {""}, {""},
#line 23 "fqcn.gperf"
      {"java.util.concurrent.ScheduledThreadPoolExecutor", 6},
#line 22 "fqcn.gperf"
      {"java.util.concurrent.locks.ReentrantReadWriteLock", 5},
      {""}, {""}, {""},
#line 24 "fqcn.gperf"
      {"java.util.concurrent.CompletableFuture", 7},
      {""}, {""}, {""}, {""},
#line 52 "fqcn.gperf"
      {"com.fasterxml.jackson.databind.ObjectMapper", 35}
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
  return static_cast<struct FqcnGperfEntry *> (0);
}
#line 57 "fqcn.gperf"

