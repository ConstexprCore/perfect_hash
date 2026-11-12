/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf nasdaq.gperf  */
/* Computed positions: -k'1-5' */

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

#line 1 "nasdaq.gperf"

#include <string.h>
#line 11 "nasdaq.gperf"
struct NasdaqGperfEntry { const char *name; int value; };
/* maximum key range = 70232, duplicates = 0 */

class NasdaqGperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct NasdaqGperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
NasdaqGperf::hash (const char *str, size_t len)
{
  static const unsigned int asso_values[] =
    {
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265,    95,  2690,   295, 15219, 15722,
       1290,  7835, 14902,  7364,  2775,  9213, 11417,   310, 11997, 21464,
        655, 21774,  7440,  1910,   185, 15643,     5,  3665,    15,     0,
      10822,  1540,   193, 23184,    20,   115, 26674,  5509, 17999,  1173,
       5195, 15228, 13172,  6581,   855,  1375, 12863, 11628, 20169,    10,
        490,    25, 15084,  5693, 13299,  7796, 19274,  5855,   215, 15703,
       4965,    13,  2150, 10897, 14397,  6495,  1230,  4423,   420,   100,
         85,    60,    40,   290,  8957,  6685, 16529,  5915,    35, 20944,
        415,  1550,  7428,    58,  7752,  1015,    15,  3115,  3645, 15957,
      15717, 16939,  4549, 15363,  7990, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265,
      70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265, 70265
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[4]+4)];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[static_cast<unsigned char>(str[3]+21)];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[static_cast<unsigned char>(str[2]+44)];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[static_cast<unsigned char>(str[1]+64)];
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

const struct NasdaqGperfEntry *
NasdaqGperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 5581,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 5,
      MIN_HASH_VALUE = 33,
      MAX_HASH_VALUE = 70264
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct NasdaqGperfEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5278 "nasdaq.gperf"
      {"VRA", 5265},
      {""}, {""},
#line 5284 "nasdaq.gperf"
      {"VRM", 5271},
#line 5532 "nasdaq.gperf"
      {"YJ", 5519},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5279 "nasdaq.gperf"
      {"VRAX", 5266},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5280 "nasdaq.gperf"
      {"VRCA", 5267},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5197 "nasdaq.gperf"
      {"VC", 5184},
      {""},
#line 5292 "nasdaq.gperf"
      {"VRXA", 5279},
      {""}, {""}, {""},
#line 5496 "nasdaq.gperf"
      {"XRX", 5483},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5515 "nasdaq.gperf"
      {"YB", 5502},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5480 "nasdaq.gperf"
      {"XOMX", 5467},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5186 "nasdaq.gperf"
      {"VBCD", 5173},
      {""}, {""}, {""}, {""},
#line 5183 "nasdaq.gperf"
      {"VBCA", 5170},
      {""},
#line 405 "nasdaq.gperf"
      {"ARM", 392},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5185 "nasdaq.gperf"
      {"VBCC", 5172},
      {""}, {""}, {""}, {""},
#line 5191 "nasdaq.gperf"
      {"VBCI", 5178},
      {""}, {""}, {""}, {""},
#line 382 "nasdaq.gperf"
      {"ARAI", 369},
      {""}, {""}, {""}, {""},
#line 5444 "nasdaq.gperf"
      {"XBCI", 5431},
      {""}, {""}, {""}, {""},
#line 389 "nasdaq.gperf"
      {"ARCC", 376},
      {""}, {""},
#line 118 "nasdaq.gperf"
      {"ADMA", 105},
      {""},
#line 390 "nasdaq.gperf"
      {"ARCI", 377},
#line 391 "nasdaq.gperf"
      {"ARCIU", 378},
      {""}, {""}, {""},
#line 97 "nasdaq.gperf"
      {"ADAC", 84},
#line 98 "nasdaq.gperf"
      {"ADACU", 85},
      {""}, {""}, {""},
#line 61 "nasdaq.gperf"
      {"ACAD", 48},
      {""}, {""}, {""}, {""},
#line 58 "nasdaq.gperf"
      {"ACAA", 45},
#line 59 "nasdaq.gperf"
      {"ACAAU", 46},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5182 "nasdaq.gperf"
      {"VAVX", 5169},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4982 "nasdaq.gperf"
      {"TRMD", 4969},
      {""}, {""}, {""}, {""}, {""},
#line 127 "nasdaq.gperf"
      {"ADV", 114},
#line 4970 "nasdaq.gperf"
      {"TRAX", 4957},
      {""}, {""}, {""}, {""},
#line 95 "nasdaq.gperf"
      {"ACWX", 82},
      {""}, {""}, {""}, {""},
#line 5192 "nasdaq.gperf"
      {"VBCJ", 5179},
      {""}, {""}, {""}, {""},
#line 94 "nasdaq.gperf"
      {"ACWI", 81},
      {""}, {""}, {""}, {""},
#line 15 "nasdaq.gperf"
      {"AACI", 2},
#line 16 "nasdaq.gperf"
      {"AACIU", 3},
      {""},
#line 4832 "nasdaq.gperf"
      {"TC", 4819},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4846 "nasdaq.gperf"
      {"TDAC", 4833},
#line 4847 "nasdaq.gperf"
      {"TDACU", 4834},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4840 "nasdaq.gperf"
      {"TCMD", 4827},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 57 "nasdaq.gperf"
      {"ABVX", 44},
      {""}, {""}, {""}, {""},
#line 56 "nasdaq.gperf"
      {"ABVC", 43},
#line 4955 "nasdaq.gperf"
      {"TOMZ", 4942},
      {""}, {""},
#line 4845 "nasdaq.gperf"
      {"TCX", 4832},
#line 4859 "nasdaq.gperf"
      {"TDWD", 4846},
#line 4861 "nasdaq.gperf"
      {"TDWDU", 4848},
      {""}, {""}, {""}, {""},
#line 4860 "nasdaq.gperf"
      {"TDWDR", 4847},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4993 "nasdaq.gperf"
      {"TRUD", 4980},
      {""}, {""},
#line 5459 "nasdaq.gperf"
      {"XE", 5446},
      {""},
#line 5006 "nasdaq.gperf"
      {"TRVI", 4993},
      {""}, {""},
#line 5189 "nasdaq.gperf"
      {"VBCG", 5176},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4992 "nasdaq.gperf"
      {"TRUC", 4979},
#line 406 "nasdaq.gperf"
      {"ARMG", 393},
      {""}, {""}, {""},
#line 4997 "nasdaq.gperf"
      {"TRUI", 4984},
      {""}, {""},
#line 1244 "nasdaq.gperf"
      {"CRMD", 1231},
#line 4819 "nasdaq.gperf"
      {"TAX", 4806},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 991 "nasdaq.gperf"
      {"CD", 978},
#line 3243 "nasdaq.gperf"
      {"MRA", 3230},
#line 1220 "nasdaq.gperf"
      {"CRAC", 1207},
#line 1222 "nasdaq.gperf"
      {"CRACU", 1209},
#line 3255 "nasdaq.gperf"
      {"MRM", 3242},
#line 100 "nasdaq.gperf"
      {"ADAG", 87},
      {""},
#line 1224 "nasdaq.gperf"
      {"CRAI", 1211},
#line 1221 "nasdaq.gperf"
      {"CRACR", 1208},
      {""}, {""}, {""},
#line 4821 "nasdaq.gperf"
      {"TAXI", 4808},
      {""}, {""}, {""}, {""},
#line 41 "nasdaq.gperf"
      {"AAXJ", 28},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 992 "nasdaq.gperf"
      {"CDC", 979},
      {""}, {""}, {""}, {""},
#line 3263 "nasdaq.gperf"
      {"MRX", 3250},
      {""}, {""}, {""}, {""}, {""},
#line 1263 "nasdaq.gperf"
      {"CRWD", 1250},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 964 "nasdaq.gperf"
      {"CCC", 951},
#line 3104 "nasdaq.gperf"
      {"MDAI", 3091},
      {""}, {""}, {""}, {""},
#line 3108 "nasdaq.gperf"
      {"MDCX", 3095},
      {""}, {""}, {""}, {""},
#line 4816 "nasdaq.gperf"
      {"TAVI", 4803},
#line 4818 "nasdaq.gperf"
      {"TAVIU", 4805},
      {""},
#line 3066 "nasdaq.gperf"
      {"MB", 3053},
#line 1006 "nasdaq.gperf"
      {"CDW", 993},
#line 965 "nasdaq.gperf"
      {"CCCC", 952},
#line 4817 "nasdaq.gperf"
      {"TAVIR", 4804},
      {""},
#line 139 "nasdaq.gperf"
      {"AEMD", 126},
      {""}, {""}, {""}, {""}, {""},
#line 948 "nasdaq.gperf"
      {"CBC", 935},
      {""}, {""}, {""}, {""},
#line 134 "nasdaq.gperf"
      {"AEC", 121},
#line 3116 "nasdaq.gperf"
      {"MDWD", 3103},
      {""}, {""},
#line 14 "nasdaq.gperf"
      {"AACG", 1},
      {""},
#line 988 "nasdaq.gperf"
      {"CCXI", 975},
#line 989 "nasdaq.gperf"
      {"CCXIU", 976},
      {""}, {""},
#line 905 "nasdaq.gperf"
      {"CAC", 892},
      {""}, {""}, {""}, {""}, {""},
#line 3067 "nasdaq.gperf"
      {"MBAI", 3054},
      {""}, {""},
#line 3050 "nasdaq.gperf"
      {"MAMA", 3037},
      {""},
#line 3260 "nasdaq.gperf"
      {"MRVI", 3247},
      {""}, {""}, {""},
#line 3085 "nasdaq.gperf"
      {"MBX", 3072},
#line 906 "nasdaq.gperf"
      {"CACC", 893},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5291 "nasdaq.gperf"
      {"VRTX", 5278},
      {""}, {""}, {""}, {""},
#line 3045 "nasdaq.gperf"
      {"MACI", 3032},
#line 3046 "nasdaq.gperf"
      {"MACIU", 3033},
      {""}, {""}, {""},
#line 5495 "nasdaq.gperf"
      {"XRTX", 5482},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3063 "nasdaq.gperf"
      {"MAXI", 3050},
      {""}, {""}, {""}, {""},
#line 149 "nasdaq.gperf"
      {"AEVA", 136},
      {""}, {""},
#line 5005 "nasdaq.gperf"
      {"TRVG", 4992},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4862 "nasdaq.gperf"
      {"TEAD", 4849},
      {""},
#line 4871 "nasdaq.gperf"
      {"TEM", 4858},
      {""}, {""}, {""}, {""}, {""},
#line 4995 "nasdaq.gperf"
      {"TRUG", 4982},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3081 "nasdaq.gperf"
      {"MBVI", 3068},
#line 3082 "nasdaq.gperf"
      {"MBVIU", 3069},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4865 "nasdaq.gperf"
      {"TECX", 4852},
      {""}, {""}, {""}, {""}, {""},
#line 1245 "nasdaq.gperf"
      {"CRMG", 1232},
      {""}, {""}, {""}, {""}, {""},
#line 255 "nasdaq.gperf"
      {"ALM", 242},
      {""}, {""},
#line 4877 "nasdaq.gperf"
      {"TEXX", 4864},
      {""}, {""},
#line 1233 "nasdaq.gperf"
      {"CRCG", 1220},
      {""},
#line 5488 "nasdaq.gperf"
      {"XRAY", 5475},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 414 "nasdaq.gperf"
      {"ARTC", 401},
#line 415 "nasdaq.gperf"
      {"ARTCU", 402},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1166 "nasdaq.gperf"
      {"COAG", 1153},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1264 "nasdaq.gperf"
      {"CRWG", 1251},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 91 "nasdaq.gperf"
      {"ACT", 78},
#line 4824 "nasdaq.gperf"
      {"TAYD", 4811},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3117 "nasdaq.gperf"
      {"MDXG", 3104},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5465 "nasdaq.gperf"
      {"XEY", 5452},
      {""}, {""}, {""}, {""},
#line 1268 "nasdaq.gperf"
      {"CRY", 1255},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1203 "nasdaq.gperf"
      {"COWG", 1190},
      {""}, {""},
#line 4911 "nasdaq.gperf"
      {"TLA", 4898},
#line 383 "nasdaq.gperf"
      {"ARAY", 370},
      {""}, {""},
#line 407 "nasdaq.gperf"
      {"ARMY", 394},
      {""},
#line 53 "nasdaq.gperf"
      {"ABTC", 40},
      {""}, {""},
#line 3124 "nasdaq.gperf"
      {"MEMA", 3111},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4926 "nasdaq.gperf"
      {"TLX", 4913},
      {""}, {""}, {""}, {""},
#line 62 "nasdaq.gperf"
      {"ACB", 49},
      {""}, {""}, {""},
#line 1205 "nasdaq.gperf"
      {"COYA", 1192},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1031 "nasdaq.gperf"
      {"CEVA", 1018},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3968 "nasdaq.gperf"
      {"PRAA", 3955},
      {""}, {""}, {""}, {""},
#line 3969 "nasdaq.gperf"
      {"PRAX", 3956},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5252 "nasdaq.gperf"
      {"VLY", 5239},
      {""}, {""}, {""},
#line 3798 "nasdaq.gperf"
      {"PC", 3785},
      {""}, {""}, {""}, {""}, {""},
#line 3817 "nasdaq.gperf"
      {"PDC", 3804},
      {""}, {""}, {""}, {""}, {""},
#line 3944 "nasdaq.gperf"
      {"POM", 3931},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3187 "nasdaq.gperf"
      {"MLAA", 3174},
#line 3188 "nasdaq.gperf"
      {"MLAAU", 3175},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3790 "nasdaq.gperf"
      {"PBM", 3777},
      {""},
#line 1003 "nasdaq.gperf"
      {"CDT", 990},
#line 4834 "nasdaq.gperf"
      {"TCBI", 4821},
      {""}, {""},
#line 3936 "nasdaq.gperf"
      {"POCI", 3923},
      {""},
#line 3995 "nasdaq.gperf"
      {"PRVA", 3982},
      {""}, {""}, {""},
#line 3747 "nasdaq.gperf"
      {"PAA", 3734},
      {""},
#line 345 "nasdaq.gperf"
      {"AOTG", 332},
      {""},
#line 92 "nasdaq.gperf"
      {"ACTG", 79},
      {""},
#line 3191 "nasdaq.gperf"
      {"MLCI", 3178},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3748 "nasdaq.gperf"
      {"PAAC", 3735},
#line 3749 "nasdaq.gperf"
      {"PAACU", 3736},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3950 "nasdaq.gperf"
      {"POWI", 3937},
#line 3779 "nasdaq.gperf"
      {"PAX", 3766},
#line 3103 "nasdaq.gperf"
      {"MCTA", 3090},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3813 "nasdaq.gperf"
      {"PCVX", 3800},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 112 "nasdaq.gperf"
      {"ADBG", 99},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3059 "nasdaq.gperf"
      {"MAT", 3046},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3106 "nasdaq.gperf"
      {"MDB", 3093},
#line 3250 "nasdaq.gperf"
      {"MRCY", 3237},
      {""}, {""}, {""},
#line 962 "nasdaq.gperf"
      {"CCB", 949},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3223 "nasdaq.gperf"
      {"MOB", 3210},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3226 "nasdaq.gperf"
      {"MOBX", 3213},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3225 "nasdaq.gperf"
      {"MOBI", 3212},
      {""}, {""}, {""}, {""}, {""},
#line 3068 "nasdaq.gperf"
      {"MBB", 3055},
      {""}, {""}, {""}, {""}, {""},
#line 903 "nasdaq.gperf"
      {"CABA", 890},
      {""}, {""}, {""}, {""},
#line 133 "nasdaq.gperf"
      {"AEBI", 120},
      {""}, {""}, {""}, {""},
#line 3069 "nasdaq.gperf"
      {"MBBC", 3056},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3044 "nasdaq.gperf"
      {"MAAY", 3031},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 273 "nasdaq.gperf"
      {"ALT", 260},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1004 "nasdaq.gperf"
      {"CDTG", 991},
      {""},
#line 274 "nasdaq.gperf"
      {"ALTI", 261},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5513 "nasdaq.gperf"
      {"YAAS", 5500},
#line 1202 "nasdaq.gperf"
      {"COTG", 1189},
      {""},
#line 987 "nasdaq.gperf"
      {"CCTG", 974},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4866 "nasdaq.gperf"
      {"TECY", 4853},
      {""}, {""}, {""}, {""},
#line 5517 "nasdaq.gperf"
      {"YBTY", 5504},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 424 "nasdaq.gperf"
      {"ARXS", 411},
      {""}, {""}, {""}, {""},
#line 5450 "nasdaq.gperf"
      {"XBTY", 5437},
      {""}, {""},
#line 5540 "nasdaq.gperf"
      {"YQ", 5527},
      {""},
#line 1029 "nasdaq.gperf"
      {"CETX", 1016},
      {""}, {""}, {""},
#line 4925 "nasdaq.gperf"
      {"TLT", 4912},
#line 3138 "nasdaq.gperf"
      {"METD", 3125},
      {""}, {""}, {""}, {""},
#line 3133 "nasdaq.gperf"
      {"META", 3120},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3134 "nasdaq.gperf"
      {"METC", 3121},
      {""}, {""},
#line 963 "nasdaq.gperf"
      {"CCBG", 950},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3797 "nasdaq.gperf"
      {"PBYI", 3784},
      {""}, {""}, {""}, {""},
#line 3783 "nasdaq.gperf"
      {"PAYX", 3770},
#line 3137 "nasdaq.gperf"
      {"METCZ", 3124},
      {""}, {""}, {""},
#line 44 "nasdaq.gperf"
      {"ABCS", 31},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3886 "nasdaq.gperf"
      {"PLA", 3873},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 126 "nasdaq.gperf"
      {"ADUS", 113},
      {""}, {""}, {""}, {""},
#line 3992 "nasdaq.gperf"
      {"PRTA", 3979},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3893 "nasdaq.gperf"
      {"PLCI", 3880},
#line 3895 "nasdaq.gperf"
      {"PLCIU", 3882},
      {""}, {""}, {""}, {""},
#line 3894 "nasdaq.gperf"
      {"PLCIR", 3881},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1206 "nasdaq.gperf"
      {"COYY", 1193},
#line 3809 "nasdaq.gperf"
      {"PCT", 3796},
#line 55 "nasdaq.gperf"
      {"ABUS", 42},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 39 "nasdaq.gperf"
      {"AAUS", 26},
      {""}, {""}, {""}, {""},
#line 3198 "nasdaq.gperf"
      {"MLTX", 3185},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 381 "nasdaq.gperf"
      {"AQWA", 368},
      {""}, {""}, {""}, {""},
#line 4822 "nasdaq.gperf"
      {"TAXS", 4809},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3815 "nasdaq.gperf"
      {"PDBA", 3802},
      {""}, {""},
#line 230 "nasdaq.gperf"
      {"ALBG", 217},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3816 "nasdaq.gperf"
      {"PDBC", 3803},
      {""}, {""}, {""},
#line 3803 "nasdaq.gperf"
      {"PCB", 3790},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1266 "nasdaq.gperf"
      {"CRWS", 1253},
      {""}, {""}, {""}, {""},
#line 1007 "nasdaq.gperf"
      {"CDXS", 994},
      {""}, {""}, {""},
#line 3844 "nasdaq.gperf"
      {"PEY", 3831},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3751 "nasdaq.gperf"
      {"PABD", 3738},
      {""}, {""}, {""}, {""},
#line 1262 "nasdaq.gperf"
      {"CRVS", 1249},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 902 "nasdaq.gperf"
      {"CAAS", 889},
      {""}, {""}, {""}, {""},
#line 1259 "nasdaq.gperf"
      {"CRUS", 1246},
      {""}, {""},
#line 1204 "nasdaq.gperf"
      {"COWS", 1191},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3043 "nasdaq.gperf"
      {"MAAS", 3030},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5274 "nasdaq.gperf"
      {"VOR", 5261},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 946 "nasdaq.gperf"
      {"CATY", 933},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3241 "nasdaq.gperf"
      {"MQ", 3228},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 957 "nasdaq.gperf"
      {"CBUS", 944},
      {""}, {""},
#line 1910 "nasdaq.gperf"
      {"FRMI", 1897},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3136 "nasdaq.gperf"
      {"METCI", 3123},
      {""},
#line 129 "nasdaq.gperf"
      {"ADXN", 116},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1744 "nasdaq.gperf"
      {"FCA", 1731},
      {""}, {""}, {""},
#line 3912 "nasdaq.gperf"
      {"PLUG", 3899},
      {""},
#line 1921 "nasdaq.gperf"
      {"FRWD", 1908},
      {""}, {""},
#line 421 "nasdaq.gperf"
      {"ARVN", 408},
      {""},
#line 3918 "nasdaq.gperf"
      {"PLYX", 3905},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 257 "nasdaq.gperf"
      {"ALMS", 244},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1893 "nasdaq.gperf"
      {"FOX", 1880},
#line 1713 "nasdaq.gperf"
      {"FA", 1700},
      {""},
#line 3843 "nasdaq.gperf"
      {"PETZ", 3830},
      {""}, {""},
#line 1894 "nasdaq.gperf"
      {"FOXA", 1881},
      {""}, {""}, {""}, {""},
#line 1896 "nasdaq.gperf"
      {"FOXX", 1883},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1714 "nasdaq.gperf"
      {"FAAA", 1701},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1718 "nasdaq.gperf"
      {"FAC", 1705},
      {""}, {""}, {""}, {""}, {""},
#line 276 "nasdaq.gperf"
      {"ALTY", 263},
      {""}, {""},
#line 1725 "nasdaq.gperf"
      {"FAMI", 1712},
      {""},
#line 37 "nasdaq.gperf"
      {"AARD", 24},
#line 3192 "nasdaq.gperf"
      {"MLCIL", 3179},
      {""},
#line 4833 "nasdaq.gperf"
      {"TCAN", 4820},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 54 "nasdaq.gperf"
      {"ABTS", 41},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3125 "nasdaq.gperf"
      {"MEMS", 3112},
      {""}, {""}, {""}, {""},
#line 4999 "nasdaq.gperf"
      {"TRUN", 4986},
      {""}, {""},
#line 4960 "nasdaq.gperf"
      {"TOWN", 4947},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4844 "nasdaq.gperf"
      {"TCRX", 4831},
      {""}, {""}, {""}, {""},
#line 3905 "nasdaq.gperf"
      {"PLTD", 3892},
      {""}, {""},
#line 1225 "nasdaq.gperf"
      {"CRAN", 1212},
#line 1227 "nasdaq.gperf"
      {"CRANU", 1214},
#line 1030 "nasdaq.gperf"
      {"CETY", 1017},
      {""}, {""}, {""},
#line 1226 "nasdaq.gperf"
      {"CRANR", 1213},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 397 "nasdaq.gperf"
      {"ARCT", 384},
      {""}, {""}, {""}, {""},
#line 3911 "nasdaq.gperf"
      {"PLTZ", 3898},
      {""}, {""}, {""}, {""},
#line 4811 "nasdaq.gperf"
      {"TARA", 4798},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5214 "nasdaq.gperf"
      {"VERA", 5201},
      {""}, {""}, {""}, {""},
#line 5217 "nasdaq.gperf"
      {"VERX", 5204},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5215 "nasdaq.gperf"
      {"VERI", 5202},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3064 "nasdaq.gperf"
      {"MAYS", 3051},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 42 "nasdaq.gperf"
      {"ABAT", 29},
      {""}, {""}, {""}, {""},
#line 3888 "nasdaq.gperf"
      {"PLAY", 3875},
      {""}, {""}, {""}, {""},
#line 3889 "nasdaq.gperf"
      {"PLBC", 3876},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1761 "nasdaq.gperf"
      {"FCXG", 1748},
      {""},
#line 5475 "nasdaq.gperf"
      {"XMAX", 5462},
      {""}, {""}, {""}, {""},
#line 4837 "nasdaq.gperf"
      {"TCBS", 4824},
      {""},
#line 1786 "nasdaq.gperf"
      {"FEM", 1773},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 377 "nasdaq.gperf"
      {"AQB", 364},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5293 "nasdaq.gperf"
      {"VRXAW", 5280},
      {""},
#line 1197 "nasdaq.gperf"
      {"CORZ", 1184},
      {""}, {""},
#line 5497 "nasdaq.gperf"
      {"XRXDW", 5484},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1798 "nasdaq.gperf"
      {"FEX", 1785},
#line 3102 "nasdaq.gperf"
      {"MCRI", 3089},
      {""}, {""}, {""},
#line 933 "nasdaq.gperf"
      {"CAR", 920},
#line 3812 "nasdaq.gperf"
      {"PCTY", 3799},
      {""}, {""},
#line 346 "nasdaq.gperf"
      {"AOUT", 333},
#line 1199 "nasdaq.gperf"
      {"CORZZ", 1186},
      {""}, {""}, {""}, {""}, {""},
#line 3078 "nasdaq.gperf"
      {"MBRX", 3065},
      {""}, {""}, {""},
#line 3054 "nasdaq.gperf"
      {"MAR", 3041},
      {""}, {""}, {""}, {""}, {""},
#line 3055 "nasdaq.gperf"
      {"MARA", 3042},
      {""}, {""}, {""}, {""},
#line 939 "nasdaq.gperf"
      {"CARZ", 926},
      {""}, {""}, {""},
#line 281 "nasdaq.gperf"
      {"AMA", 268},
#line 5188 "nasdaq.gperf"
      {"VBCF", 5175},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1740 "nasdaq.gperf"
      {"FBYD", 1727},
      {""}, {""}, {""}, {""}, {""},
#line 282 "nasdaq.gperf"
      {"AMACU", 269},
      {""}, {""}, {""},
#line 5003 "nasdaq.gperf"
      {"TRUT", 4990},
      {""}, {""}, {""}, {""},
#line 289 "nasdaq.gperf"
      {"AMCX", 276},
      {""}, {""},
#line 3906 "nasdaq.gperf"
      {"PLTG", 3893},
      {""},
#line 4806 "nasdaq.gperf"
      {"TACT", 4793},
      {""}, {""},
#line 4876 "nasdaq.gperf"
      {"TEXN", 4863},
      {""},
#line 288 "nasdaq.gperf"
      {"AMCI", 275},
      {""}, {""}, {""}, {""},
#line 3778 "nasdaq.gperf"
      {"PAVS", 3765},
#line 392 "nasdaq.gperf"
      {"ARCIW", 379},
      {""},
#line 1248 "nasdaq.gperf"
      {"CRMT", 1235},
      {""},
#line 4823 "nasdaq.gperf"
      {"TAXT", 4810},
#line 99 "nasdaq.gperf"
      {"ADACW", 86},
      {""}, {""},
#line 4874 "nasdaq.gperf"
      {"TER", 4861},
#line 1797 "nasdaq.gperf"
      {"FEUZ", 1784},
      {""}, {""}, {""}, {""},
#line 1234 "nasdaq.gperf"
      {"CRCT", 1221},
#line 60 "nasdaq.gperf"
      {"ACAAW", 47},
      {""}, {""}, {""},
#line 3089 "nasdaq.gperf"
      {"MCBS", 3076},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 124 "nasdaq.gperf"
      {"ADTN", 111},
      {""},
#line 5206 "nasdaq.gperf"
      {"VCYT", 5193},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1185 "nasdaq.gperf"
      {"COMT", 1172},
      {""}, {""},
#line 1856 "nasdaq.gperf"
      {"FLX", 1843},
      {""}, {""}, {""}, {""},
#line 1777 "nasdaq.gperf"
      {"FDT", 1764},
      {""}, {""}, {""}, {""}, {""},
#line 966 "nasdaq.gperf"
      {"CCCT", 953},
#line 967 "nasdaq.gperf"
      {"CCCTU", 954},
      {""}, {""},
#line 4928 "nasdaq.gperf"
      {"TMC", 4915},
#line 1779 "nasdaq.gperf"
      {"FDTX", 1766},
      {""}, {""}, {""}, {""},
#line 947 "nasdaq.gperf"
      {"CBAT", 934},
      {""}, {""},
#line 5474 "nasdaq.gperf"
      {"XMAG", 5461},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4929 "nasdaq.gperf"
      {"TMCI", 4916},
#line 17 "nasdaq.gperf"
      {"AACIW", 4},
      {""},
#line 921 "nasdaq.gperf"
      {"CAMT", 908},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4848 "nasdaq.gperf"
      {"TDACW", 4835},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1902 "nasdaq.gperf"
      {"FRBA", 1889},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1854 "nasdaq.gperf"
      {"FLUX", 1841},
      {""}, {""},
#line 935 "nasdaq.gperf"
      {"CARG", 922},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 413 "nasdaq.gperf"
      {"ARRY", 400},
      {""}, {""}, {""}, {""},
#line 1762 "nasdaq.gperf"
      {"FDBC", 1749},
      {""}, {""}, {""}, {""},
#line 4994 "nasdaq.gperf"
      {"TRUF", 4981},
      {""}, {""}, {""}, {""},
#line 3128 "nasdaq.gperf"
      {"MERC", 3115},
      {""}, {""}, {""}, {""},
#line 3919 "nasdaq.gperf"
      {"PLYY", 3906},
#line 1741 "nasdaq.gperf"
      {"FBYDP", 1728},
      {""}, {""}, {""},
#line 1747 "nasdaq.gperf"
      {"FCBC", 1734},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3199 "nasdaq.gperf"
      {"MLYS", 3186},
      {""}, {""}, {""}, {""}, {""},
#line 1223 "nasdaq.gperf"
      {"CRACW", 1210},
      {""}, {""},
#line 1716 "nasdaq.gperf"
      {"FAB", 1703},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3965 "nasdaq.gperf"
      {"PQJA", 3952},
      {""}, {""}, {""}, {""},
#line 1717 "nasdaq.gperf"
      {"FABC", 1704},
      {""}, {""},
#line 4875 "nasdaq.gperf"
      {"TERG", 4862},
      {""},
#line 3782 "nasdaq.gperf"
      {"PAYS", 3769},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3259 "nasdaq.gperf"
      {"MRTN", 3246},
      {""}, {""},
#line 3105 "nasdaq.gperf"
      {"MDAIW", 3092},
      {""}, {""}, {""}, {""},
#line 3109 "nasdaq.gperf"
      {"MDCXW", 3096},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4688 "nasdaq.gperf"
      {"SRAD", 4675},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4533 "nasdaq.gperf"
      {"SJ", 4520},
      {""},
#line 3994 "nasdaq.gperf"
      {"PRTS", 3981},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3807 "nasdaq.gperf"
      {"PCRX", 3794},
#line 990 "nasdaq.gperf"
      {"CCXIW", 977},
      {""}, {""},
#line 4440 "nasdaq.gperf"
      {"SDA", 4427},
      {""}, {""}, {""}, {""}, {""},
#line 3917 "nasdaq.gperf"
      {"PLXS", 3904},
      {""}, {""}, {""},
#line 5535 "nasdaq.gperf"
      {"YMT", 5522},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 379 "nasdaq.gperf"
      {"AQMS", 366},
#line 4416 "nasdaq.gperf"
      {"SCA", 4403},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3770 "nasdaq.gperf"
      {"PARA", 3757},
      {""}, {""}, {""},
#line 1858 "nasdaq.gperf"
      {"FLY", 1845},
      {""},
#line 3047 "nasdaq.gperf"
      {"MACIW", 3034},
      {""},
#line 4622 "nasdaq.gperf"
      {"SOCA", 4609},
#line 4623 "nasdaq.gperf"
      {"SOCAU", 4610},
#line 113 "nasdaq.gperf"
      {"ADBT", 100},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4648 "nasdaq.gperf"
      {"SOXX", 4635},
#line 4405 "nasdaq.gperf"
      {"SBC", 4392},
#line 4404 "nasdaq.gperf"
      {"SBAC", 4391},
      {""}, {""}, {""}, {""},
#line 3915 "nasdaq.gperf"
      {"PLUS", 3902},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3083 "nasdaq.gperf"
      {"MBVIW", 3070},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3891 "nasdaq.gperf"
      {"PLBY", 3878},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3971 "nasdaq.gperf"
      {"PRCT", 3958},
      {""}, {""}, {""}, {""},
#line 314 "nasdaq.gperf"
      {"AMTX", 301},
      {""}, {""},
#line 4645 "nasdaq.gperf"
      {"SOUX", 4632},
      {""},
#line 4815 "nasdaq.gperf"
      {"TATT", 4802},
      {""}, {""},
#line 1789 "nasdaq.gperf"
      {"FEMY", 1776},
      {""}, {""},
#line 416 "nasdaq.gperf"
      {"ARTCW", 403},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1117 "nasdaq.gperf"
      {"CLMT", 1104},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4415 "nasdaq.gperf"
      {"SBUX", 4402},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 938 "nasdaq.gperf"
      {"CARY", 925},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 286 "nasdaq.gperf"
      {"AMBA", 273},
      {""}, {""},
#line 3766 "nasdaq.gperf"
      {"PAMT", 3753},
      {""},
#line 1132 "nasdaq.gperf"
      {"CLWT", 1119},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1743 "nasdaq.gperf"
      {"FBYY", 1730},
      {""}, {""},
#line 3825 "nasdaq.gperf"
      {"PDYN", 3812},
      {""}, {""}, {""}, {""},
#line 3795 "nasdaq.gperf"
      {"PBRG", 3782},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4417 "nasdaq.gperf"
      {"SCAG", 4404},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3840 "nasdaq.gperf"
      {"PERI", 3827},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3920 "nasdaq.gperf"
      {"PMA", 3907},
      {""},
#line 4396 "nasdaq.gperf"
      {"SAMG", 4383},
      {""}, {""}, {""},
#line 3842 "nasdaq.gperf"
      {"PETS", 3829},
#line 4646 "nasdaq.gperf"
      {"SOWG", 4633},
      {""}, {""},
#line 4927 "nasdaq.gperf"
      {"TMB", 4914},
#line 3921 "nasdaq.gperf"
      {"PMAX", 3908},
      {""}, {""}, {""}, {""},
#line 4971 "nasdaq.gperf"
      {"TRBF", 4958},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 87 "nasdaq.gperf"
      {"ACRS", 74},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4437 "nasdaq.gperf"
      {"SCYX", 4424},
      {""}, {""}, {""}, {""},
#line 5181 "nasdaq.gperf"
      {"VANI", 5168},
      {""}, {""}, {""}, {""}, {""},
#line 3189 "nasdaq.gperf"
      {"MLAAW", 3176},
      {""}, {""},
#line 4474 "nasdaq.gperf"
      {"SEV", 4461},
#line 1780 "nasdaq.gperf"
      {"FDUS", 1767},
      {""}, {""}, {""}, {""},
#line 3203 "nasdaq.gperf"
      {"MMTX", 3190},
#line 3204 "nasdaq.gperf"
      {"MMTXU", 3191},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3901 "nasdaq.gperf"
      {"PLRX", 3888},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4920 "nasdaq.gperf"
      {"TLRY", 4907},
#line 3750 "nasdaq.gperf"
      {"PAACW", 3737},
      {""}, {""}, {""},
#line 3902 "nasdaq.gperf"
      {"PLRZ", 3889},
#line 3135 "nasdaq.gperf"
      {"METCB", 3122},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4561 "nasdaq.gperf"
      {"SLM", 4548},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3909 "nasdaq.gperf"
      {"PLTS", 3896},
      {""}, {""},
#line 3776 "nasdaq.gperf"
      {"PATN", 3763},
      {""},
#line 4694 "nasdaq.gperf"
      {"SRTA", 4681},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4813 "nasdaq.gperf"
      {"TARS", 4800},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5464 "nasdaq.gperf"
      {"XERS", 5451},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4435 "nasdaq.gperf"
      {"SCTX", 4422},
      {""}, {""},
#line 4956 "nasdaq.gperf"
      {"TONX", 4943},
      {""}, {""},
#line 5272 "nasdaq.gperf"
      {"VONG", 5259},
      {""}, {""},
#line 3227 "nasdaq.gperf"
      {"MOBXW", 3214},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 317 "nasdaq.gperf"
      {"AMYY", 304},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4401 "nasdaq.gperf"
      {"SATA", 4388},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1788 "nasdaq.gperf"
      {"FEMS", 1775},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 955 "nasdaq.gperf"
      {"CBRS", 942},
      {""}, {""}, {""}, {""},
#line 1252 "nasdaq.gperf"
      {"CRNX", 1239},
      {""}, {""}, {""}, {""},
#line 1250 "nasdaq.gperf"
      {"CRNC", 1237},
      {""}, {""}, {""}, {""},
#line 3256 "nasdaq.gperf"
      {"MRNA", 3243},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 998 "nasdaq.gperf"
      {"CDNA", 985},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3810 "nasdaq.gperf"
      {"PCTTU", 3797},
      {""},
#line 1188 "nasdaq.gperf"
      {"CONX", 1175},
      {""},
#line 4946 "nasdaq.gperf"
      {"TMYY", 4933},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1186 "nasdaq.gperf"
      {"CONI", 1173},
      {""},
#line 4452 "nasdaq.gperf"
      {"SDVY", 4439},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 922 "nasdaq.gperf"
      {"CAN", 909},
#line 3916 "nasdaq.gperf"
      {"PLUT", 3903},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 923 "nasdaq.gperf"
      {"CANC", 910},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1775 "nasdaq.gperf"
      {"FDRX", 1762},
      {""}, {""}, {""}, {""},
#line 1109 "nasdaq.gperf"
      {"CLBT", 1096},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 272 "nasdaq.gperf"
      {"ALRS", 259},
      {""}, {""}, {""}, {""},
#line 1857 "nasdaq.gperf"
      {"FLXS", 1844},
      {""}, {""}, {""}, {""},
#line 1778 "nasdaq.gperf"
      {"FDTS", 1765},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1855 "nasdaq.gperf"
      {"FLWS", 1842},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4873 "nasdaq.gperf"
      {"TENX", 4860},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4835 "nasdaq.gperf"
      {"TCBIO", 4822},
      {""}, {""}, {""},
#line 1027 "nasdaq.gperf"
      {"CERS", 1014},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4942 "nasdaq.gperf"
      {"TMUS", 4929},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4464 "nasdaq.gperf"
      {"SEMY", 4451},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4945 "nasdaq.gperf"
      {"TMUSZ", 4932},
      {""}, {""}, {""},
#line 5455 "nasdaq.gperf"
      {"XCNY", 5442},
      {""}, {""},
#line 1772 "nasdaq.gperf"
      {"FDMT", 1759},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 773 "nasdaq.gperf"
      {"BRAI", 760},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 600 "nasdaq.gperf"
      {"BDMD", 587},
      {""},
#line 1020 "nasdaq.gperf"
      {"CENX", 1007},
      {""}, {""}, {""},
#line 4915 "nasdaq.gperf"
      {"TLN", 4902},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 88 "nasdaq.gperf"
      {"ACRT", 75},
      {""}, {""}, {""}, {""},
#line 4916 "nasdaq.gperf"
      {"TLNC", 4903},
#line 4917 "nasdaq.gperf"
      {"TLNCU", 4904},
      {""}, {""}, {""},
#line 577 "nasdaq.gperf"
      {"BCAX", 564},
#line 3233 "nasdaq.gperf"
      {"MORN", 3220},
      {""}, {""}, {""},
#line 596 "nasdaq.gperf"
      {"BDCI", 583},
#line 597 "nasdaq.gperf"
      {"BDCIU", 584},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1719 "nasdaq.gperf"
      {"FACT", 1706},
#line 1720 "nasdaq.gperf"
      {"FACTU", 1707},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1793 "nasdaq.gperf"
      {"FER", 1780},
#line 1760 "nasdaq.gperf"
      {"FCVT", 1747},
      {""}, {""},
#line 2694 "nasdaq.gperf"
      {"JD", 2681},
      {""},
#line 1794 "nasdaq.gperf"
      {"FERA", 1781},
#line 1796 "nasdaq.gperf"
      {"FERAU", 1783},
      {""}, {""},
#line 3983 "nasdaq.gperf"
      {"PRN", 3970},
      {""},
#line 1795 "nasdaq.gperf"
      {"FERAR", 1782},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 284 "nasdaq.gperf"
      {"AMAN", 271},
      {""},
#line 541 "nasdaq.gperf"
      {"BACC", 528},
#line 543 "nasdaq.gperf"
      {"BACCU", 530},
      {""}, {""}, {""}, {""},
#line 542 "nasdaq.gperf"
      {"BACCR", 529},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4843 "nasdaq.gperf"
      {"TCRT", 4830},
      {""}, {""}, {""}, {""},
#line 1901 "nasdaq.gperf"
      {"FRAF", 1888},
      {""}, {""}, {""}, {""},
#line 4451 "nasdaq.gperf"
      {"SDTY", 4438},
      {""}, {""}, {""}, {""},
#line 1861 "nasdaq.gperf"
      {"FMAC", 1848},
#line 1863 "nasdaq.gperf"
      {"FMACU", 1850},
      {""}, {""}, {""}, {""},
#line 1862 "nasdaq.gperf"
      {"FMACR", 1849},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 309 "nasdaq.gperf"
      {"AMRX", 296},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1763 "nasdaq.gperf"
      {"FDCF", 1750},
      {""}, {""}, {""}, {""},
#line 5257 "nasdaq.gperf"
      {"VMBS", 5244},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 772 "nasdaq.gperf"
      {"BRAG", 759},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 315 "nasdaq.gperf"
      {"AMUN", 302},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1895 "nasdaq.gperf"
      {"FOXF", 1882},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5534 "nasdaq.gperf"
      {"YMAT", 5521},
      {""}, {""}, {""},
#line 1897 "nasdaq.gperf"
      {"FOXXW", 1884},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1196 "nasdaq.gperf"
      {"CORT", 1183},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1729 "nasdaq.gperf"
      {"FATN", 1716},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 143 "nasdaq.gperf"
      {"AERT", 130},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 937 "nasdaq.gperf"
      {"CART", 924},
#line 4943 "nasdaq.gperf"
      {"TMUSI", 4930},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4939 "nasdaq.gperf"
      {"TMTS", 4926},
#line 4940 "nasdaq.gperf"
      {"TMTSU", 4927},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5286 "nasdaq.gperf"
      {"VRNS", 5273},
      {""}, {""}, {""}, {""},
#line 285 "nasdaq.gperf"
      {"AMAT", 272},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 595 "nasdaq.gperf"
      {"BCYC", 582},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2697 "nasdaq.gperf"
      {"JEM", 2684},
      {""}, {""}, {""}, {""}, {""},
#line 2698 "nasdaq.gperf"
      {"JEMA", 2685},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1144 "nasdaq.gperf"
      {"CMRC", 1131},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3767 "nasdaq.gperf"
      {"PANG", 3754},
      {""},
#line 1919 "nasdaq.gperf"
      {"FRTT", 1906},
      {""}, {""},
#line 696 "nasdaq.gperf"
      {"BL", 683},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5294 "nasdaq.gperf"
      {"VS", 5281},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5295 "nasdaq.gperf"
      {"VSA", 5282},
      {""}, {""}, {""}, {""}, {""},
#line 800 "nasdaq.gperf"
      {"BRTX", 787},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1198 "nasdaq.gperf"
      {"CORZW", 1185},
#line 260 "nasdaq.gperf"
      {"ALNY", 247},
      {""}, {""}, {""}, {""},
#line 4473 "nasdaq.gperf"
      {"SEUS", 4460},
      {""}, {""}, {""}, {""},
#line 604 "nasdaq.gperf"
      {"BDTX", 591},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 757 "nasdaq.gperf"
      {"BOT", 744},
      {""}, {""},
#line 1903 "nasdaq.gperf"
      {"FRBT", 1890},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 592 "nasdaq.gperf"
      {"BCTX", 579},
      {""}, {""},
#line 607 "nasdaq.gperf"
      {"BEAG", 594},
#line 609 "nasdaq.gperf"
      {"BEAGU", 596},
      {""}, {""}, {""},
#line 2710 "nasdaq.gperf"
      {"JL", 2697},
#line 608 "nasdaq.gperf"
      {"BEAGR", 595},
#line 1028 "nasdaq.gperf"
      {"CERT", 1015},
      {""}, {""},
#line 760 "nasdaq.gperf"
      {"BOTZ", 747},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4695 "nasdaq.gperf"
      {"SRTS", 4682},
#line 594 "nasdaq.gperf"
      {"BCTXZ", 581},
      {""},
#line 4638 "nasdaq.gperf"
      {"SORA", 4625},
      {""},
#line 4985 "nasdaq.gperf"
      {"TRNS", 4972},
#line 1742 "nasdaq.gperf"
      {"FBYDW", 1729},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 774 "nasdaq.gperf"
      {"BRBI", 761},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4414 "nasdaq.gperf"
      {"SBRA", 4401},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4643 "nasdaq.gperf"
      {"SOUN", 4630},
      {""}, {""}, {""},
#line 1137 "nasdaq.gperf"
      {"CMCT", 1124},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 427 "nasdaq.gperf"
      {"ASCI", 414},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 562 "nasdaq.gperf"
      {"BBB", 549},
      {""}, {""}, {""}, {""}, {""},
#line 2693 "nasdaq.gperf"
      {"JCTC", 2680},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 758 "nasdaq.gperf"
      {"BOTJ", 745},
      {""}, {""}, {""}, {""},
#line 3835 "nasdaq.gperf"
      {"PENG", 3822},
      {""},
#line 540 "nasdaq.gperf"
      {"BABX", 527},
      {""}, {""}, {""}, {""}, {""},
#line 968 "nasdaq.gperf"
      {"CCCTW", 955},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5543 "nasdaq.gperf"
      {"YSAG", 5530},
      {""}, {""}, {""}, {""},
#line 5024 "nasdaq.gperf"
      {"TSMX", 5011},
      {""}, {""}, {""}, {""}, {""},
#line 1865 "nasdaq.gperf"
      {"FMB", 1852},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5025 "nasdaq.gperf"
      {"TSMZ", 5012},
      {""},
#line 1000 "nasdaq.gperf"
      {"CDNS", 987},
      {""}, {""}, {""}, {""}, {""},
#line 4944 "nasdaq.gperf"
      {"TMUSL", 4931},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3948 "nasdaq.gperf"
      {"PONY", 3935},
      {""},
#line 4386 "nasdaq.gperf"
      {"SABS", 4373},
#line 4419 "nasdaq.gperf"
      {"SCATU", 4406},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2675 "nasdaq.gperf"
      {"JAB", 2662},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1774 "nasdaq.gperf"
      {"FDRS", 1761},
#line 432 "nasdaq.gperf"
      {"ASMG", 419},
      {""}, {""}, {""},
#line 5028 "nasdaq.gperf"
      {"TSUI", 5015},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4470 "nasdaq.gperf"
      {"SERA", 4457},
      {""}, {""}, {""}, {""},
#line 1269 "nasdaq.gperf"
      {"CSAI", 1256},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1285 "nasdaq.gperf"
      {"CSX", 1272},
      {""}, {""}, {""}, {""}, {""},
#line 3264 "nasdaq.gperf"
      {"MSAI", 3251},
      {""}, {""},
#line 4475 "nasdaq.gperf"
      {"SEVN", 4462},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3929 "nasdaq.gperf"
      {"PMTS", 3916},
      {""}, {""}, {""}, {""},
#line 1284 "nasdaq.gperf"
      {"CSWC", 1271},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4583 "nasdaq.gperf"
      {"SMCX", 4570},
      {""}, {""}, {""},
#line 4598 "nasdaq.gperf"
      {"SMX", 4585},
#line 1773 "nasdaq.gperf"
      {"FDNI", 1760},
      {""}, {""}, {""}, {""},
#line 4579 "nasdaq.gperf"
      {"SMCI", 4566},
#line 5022 "nasdaq.gperf"
      {"TSMG", 5009},
      {""}, {""}, {""},
#line 4584 "nasdaq.gperf"
      {"SMCZ", 4571},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3206 "nasdaq.gperf"
      {"MMYT", 3193},
      {""}, {""}, {""}, {""}, {""},
#line 3771 "nasdaq.gperf"
      {"PARAW", 3758},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4575 "nasdaq.gperf"
      {"SLXN", 4562},
#line 4624 "nasdaq.gperf"
      {"SOCAW", 4611},
#line 1738 "nasdaq.gperf"
      {"FBNC", 1725},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3922 "nasdaq.gperf"
      {"PMBS", 3909},
      {""}, {""}, {""}, {""},
#line 574 "nasdaq.gperf"
      {"BBYY", 561},
      {""}, {""}, {""}, {""},
#line 4406 "nasdaq.gperf"
      {"SBCF", 4393},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4570 "nasdaq.gperf"
      {"SLRC", 4557},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4453 "nasdaq.gperf"
      {"SEAT", 4440},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 697 "nasdaq.gperf"
      {"BLBD", 684},
      {""}, {""}, {""}, {""},
#line 5029 "nasdaq.gperf"
      {"TSYX", 5016},
      {""}, {""}, {""}, {""},
#line 3126 "nasdaq.gperf"
      {"MENS", 3113},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2718 "nasdaq.gperf"
      {"JOYY", 2705},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 446 "nasdaq.gperf"
      {"ASTC", 433},
      {""}, {""}, {""}, {""},
#line 449 "nasdaq.gperf"
      {"ASTI", 436},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5503 "nasdaq.gperf"
      {"XT", 5490},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5546 "nasdaq.gperf"
      {"YSWY", 5533},
      {""}, {""}, {""}, {""}, {""},
#line 1005 "nasdaq.gperf"
      {"CDTTW", 992},
      {""}, {""},
#line 5306 "nasdaq.gperf"
      {"VTC", 5293},
      {""}, {""}, {""}, {""}, {""},
#line 82 "nasdaq.gperf"
      {"ACNT", 69},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4580 "nasdaq.gperf"
      {"SMCIP", 4567},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3826 "nasdaq.gperf"
      {"PDYNW", 3813},
      {""},
#line 1757 "nasdaq.gperf"
      {"FCNCP", 1744},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4563 "nasdaq.gperf"
      {"SLMT", 4550},
#line 4418 "nasdaq.gperf"
      {"SCAGW", 4405},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5348 "nasdaq.gperf"
      {"WDC", 5335},
      {""}, {""}, {""},
#line 1726 "nasdaq.gperf"
      {"FANG", 1713},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1790 "nasdaq.gperf"
      {"FENC", 1777},
      {""}, {""},
#line 5339 "nasdaq.gperf"
      {"WB", 5326},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 457 "nasdaq.gperf"
      {"ATC", 444},
      {""}, {""}, {""}, {""}, {""},
#line 455 "nasdaq.gperf"
      {"ATAI", 442},
      {""}, {""}, {""}, {""},
#line 458 "nasdaq.gperf"
      {"ATCX", 445},
      {""}, {""}, {""}, {""},
#line 5184 "nasdaq.gperf"
      {"VBCB", 5171},
      {""}, {""},
#line 5332 "nasdaq.gperf"
      {"WAMA", 5319},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3997 "nasdaq.gperf"
      {"PSC", 3984},
#line 3999 "nasdaq.gperf"
      {"PSCD", 3986},
      {""}, {""}, {""}, {""},
#line 388 "nasdaq.gperf"
      {"ARCB", 375},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3998 "nasdaq.gperf"
      {"PSCC", 3985},
      {""}, {""}, {""}, {""},
#line 4003 "nasdaq.gperf"
      {"PSCI", 3990},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4021 "nasdaq.gperf"
      {"PSWD", 4008},
#line 3205 "nasdaq.gperf"
      {"MMTXW", 3192},
      {""}, {""}, {""},
#line 1251 "nasdaq.gperf"
      {"CRNT", 1238},
#line 593 "nasdaq.gperf"
      {"BCTXL", 580},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3278 "nasdaq.gperf"
      {"MST", 3265},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1850 "nasdaq.gperf"
      {"FLN", 1837},
#line 3281 "nasdaq.gperf"
      {"MSTX", 3268},
      {""}, {""}, {""}, {""},
#line 1851 "nasdaq.gperf"
      {"FLNA", 1838},
      {""}, {""},
#line 5037 "nasdaq.gperf"
      {"TTMI", 5024},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1852 "nasdaq.gperf"
      {"FLNC", 1839},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4981 "nasdaq.gperf"
      {"TRMB", 4968},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 128 "nasdaq.gperf"
      {"ADVB", 115},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4595 "nasdaq.gperf"
      {"SMTC", 4582},
      {""}, {""}, {""},
#line 1270 "nasdaq.gperf"
      {"CSB", 1257},
#line 4596 "nasdaq.gperf"
      {"SMTI", 4583},
      {""}, {""},
#line 5314 "nasdaq.gperf"
      {"VTWG", 5301},
      {""}, {""}, {""}, {""},
#line 1017 "nasdaq.gperf"
      {"CENN", 1004},
      {""},
#line 140 "nasdaq.gperf"
      {"AENT", 127},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 795 "nasdaq.gperf"
      {"BRR", 782},
#line 3266 "nasdaq.gperf"
      {"MSBI", 3253},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1286 "nasdaq.gperf"
      {"CTAA", 1273},
#line 1288 "nasdaq.gperf"
      {"CTAAU", 1275},
      {""}, {""}, {""},
#line 38 "nasdaq.gperf"
      {"AAUB", 25},
#line 1287 "nasdaq.gperf"
      {"CTAAR", 1274},
      {""},
#line 1293 "nasdaq.gperf"
      {"CTMX", 1280},
      {""},
#line 4577 "nasdaq.gperf"
      {"SMBC", 4564},
      {""}, {""}, {""}, {""},
#line 602 "nasdaq.gperf"
      {"BDRX", 589},
      {""}, {""},
#line 482 "nasdaq.gperf"
      {"ATXG", 469},
      {""},
#line 686 "nasdaq.gperf"
      {"BJRI", 673},
      {""}, {""},
#line 801 "nasdaq.gperf"
      {"BRUN", 788},
#line 3283 "nasdaq.gperf"
      {"MTC", 3270},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 590 "nasdaq.gperf"
      {"BCRX", 577},
      {""}, {""}, {""}, {""},
#line 1140 "nasdaq.gperf"
      {"CMND", 1127},
      {""}, {""}, {""},
#line 1301 "nasdaq.gperf"
      {"CTW", 1288},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1106 "nasdaq.gperf"
      {"CJMB", 1093},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1119 "nasdaq.gperf"
      {"CLNN", 1106},
      {""},
#line 259 "nasdaq.gperf"
      {"ALNT", 246},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3292 "nasdaq.gperf"
      {"MTVA", 3279},
      {""}, {""},
#line 308 "nasdaq.gperf"
      {"AMRN", 295},
      {""}, {""},
#line 3811 "nasdaq.gperf"
      {"PCTTW", 3798},
      {""}, {""},
#line 5338 "nasdaq.gperf"
      {"WAY", 5325},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5030 "nasdaq.gperf"
      {"TSYY", 5017},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5471 "nasdaq.gperf"
      {"XLAB", 5458},
      {""}, {""}, {""}, {""},
#line 1018 "nasdaq.gperf"
      {"CENT", 1005},
      {""}, {""},
#line 1876 "nasdaq.gperf"
      {"FMUN", 1863},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3267 "nasdaq.gperf"
      {"MSBIP", 3254},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4429 "nasdaq.gperf"
      {"SCNX", 4416},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4428 "nasdaq.gperf"
      {"SCNI", 4415},
      {""}, {""}, {""},
#line 5345 "nasdaq.gperf"
      {"WCT", 5332},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4397 "nasdaq.gperf"
      {"SANA", 4384},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 228 "nasdaq.gperf"
      {"ALAB", 215},
      {""}, {""}, {""}, {""},
#line 4553 "nasdaq.gperf"
      {"SLBT", 4540},
      {""}, {""},
#line 606 "nasdaq.gperf"
      {"BDYN", 593},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5347 "nasdaq.gperf"
      {"WDAY", 5334},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4601 "nasdaq.gperf"
      {"SMYY", 4588},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 726 "nasdaq.gperf"
      {"BMM", 713},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 384 "nasdaq.gperf"
      {"ARBB", 371},
      {""}, {""},
#line 3836 "nasdaq.gperf"
      {"PENN", 3823},
      {""},
#line 5325 "nasdaq.gperf"
      {"WABC", 5312},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 601 "nasdaq.gperf"
      {"BDMDW", 588},
      {""}, {""}, {""}, {""}, {""},
#line 1274 "nasdaq.gperf"
      {"CSCS", 1261},
#line 705 "nasdaq.gperf"
      {"BLMN", 692},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4918 "nasdaq.gperf"
      {"TLNCW", 4905},
      {""},
#line 2716 "nasdaq.gperf"
      {"JOUT", 2703},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 598 "nasdaq.gperf"
      {"BDCIW", 585},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4025 "nasdaq.gperf"
      {"PTC", 4012},
#line 4022 "nasdaq.gperf"
      {"PTAC", 4009},
#line 4023 "nasdaq.gperf"
      {"PTACU", 4010},
      {""}, {""}, {""}, {""},
#line 1721 "nasdaq.gperf"
      {"FACTW", 1708},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5342 "nasdaq.gperf"
      {"WBUY", 5329},
      {""}, {""}, {""}, {""},
#line 711 "nasdaq.gperf"
      {"BLRX", 698},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4398 "nasdaq.gperf"
      {"SANG", 4385},
#line 3925 "nasdaq.gperf"
      {"PMN", 3912},
#line 454 "nasdaq.gperf"
      {"ASYS", 441},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 611 "nasdaq.gperf"
      {"BEAT", 598},
      {""}, {""}, {""}, {""}, {""},
#line 4639 "nasdaq.gperf"
      {"SORN", 4626},
#line 4640 "nasdaq.gperf"
      {"SORNU", 4627},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1116 "nasdaq.gperf"
      {"CLMB", 1103},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3190 "nasdaq.gperf"
      {"MLAB", 3177},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3753 "nasdaq.gperf"
      {"PACB", 3740},
      {""}, {""}, {""}, {""},
#line 1290 "nasdaq.gperf"
      {"CTBI", 1277},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4564 "nasdaq.gperf"
      {"SLN", 4551},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 452 "nasdaq.gperf"
      {"ASTS", 439},
      {""}, {""}, {""},
#line 1935 "nasdaq.gperf"
      {"FSV", 1922},
      {""}, {""}, {""}, {""}, {""},
#line 5481 "nasdaq.gperf"
      {"XOS", 5468},
      {""}, {""},
#line 2717 "nasdaq.gperf"
      {"JOYT", 2704},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5296 "nasdaq.gperf"
      {"VSAT", 5283},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5547 "nasdaq.gperf"
      {"YSXT", 5534},
#line 144 "nasdaq.gperf"
      {"AERTW", 131},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 759 "nasdaq.gperf"
      {"BOTT", 746},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4941 "nasdaq.gperf"
      {"TMTSW", 4928},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5511 "nasdaq.gperf"
      {"XXX", 5498},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4989 "nasdaq.gperf"
      {"TRS", 4976},
#line 52 "nasdaq.gperf"
      {"ABSI", 39},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3276 "nasdaq.gperf"
      {"MSR", 3263},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4856 "nasdaq.gperf"
      {"TDSC", 4843},
      {""}, {""}, {""}, {""},
#line 4565 "nasdaq.gperf"
      {"SLNG", 4552},
      {""},
#line 2684 "nasdaq.gperf"
      {"JATT", 2671},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5007 "nasdaq.gperf"
      {"TSAT", 4994},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4592 "nasdaq.gperf"
      {"SMRI", 4579},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3293 "nasdaq.gperf"
      {"MTYY", 3280},
      {""}, {""}, {""}, {""},
#line 4935 "nasdaq.gperf"
      {"TMNS", 4922},
      {""}, {""}, {""}, {""},
#line 3887 "nasdaq.gperf"
      {"PLAB", 3874},
      {""},
#line 5069 "nasdaq.gperf"
      {"TXMD", 5056},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5074 "nasdaq.gperf"
      {"TXXD", 5061},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4644 "nasdaq.gperf"
      {"SOUNW", 4631},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 985 "nasdaq.gperf"
      {"CCSI", 972},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1289 "nasdaq.gperf"
      {"CTAS", 1276},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4990 "nasdaq.gperf"
      {"TRSG", 4977},
#line 3079 "nasdaq.gperf"
      {"MBS", 3066},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4589 "nasdaq.gperf"
      {"SMMT", 4576},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 793 "nasdaq.gperf"
      {"BRNX", 780},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1326 "nasdaq.gperf"
      {"CXAI", 1313},
#line 4599 "nasdaq.gperf"
      {"SMXT", 4586},
      {""}, {""}, {""}, {""},
#line 5548 "nasdaq.gperf"
      {"YTRA", 5535},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4387 "nasdaq.gperf"
      {"SABSW", 4374},
#line 754 "nasdaq.gperf"
      {"BON", 741},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1922 "nasdaq.gperf"
      {"FSBC", 1909},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 570 "nasdaq.gperf"
      {"BBNX", 557},
      {""}, {""}, {""}, {""},
#line 551 "nasdaq.gperf"
      {"BAND", 538},
      {""}, {""}, {""},
#line 1937 "nasdaq.gperf"
      {"FTA", 1924},
      {""}, {""}, {""}, {""}, {""},
#line 556 "nasdaq.gperf"
      {"BANX", 543},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1941 "nasdaq.gperf"
      {"FTC", 1928},
#line 5202 "nasdaq.gperf"
      {"VCRB", 5189},
      {""}, {""}, {""}, {""},
#line 1939 "nasdaq.gperf"
      {"FTAI", 1926},
      {""}, {""},
#line 5549 "nasdaq.gperf"
      {"YXT", 5536},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 478 "nasdaq.gperf"
      {"ATRA", 465},
      {""}, {""}, {""}, {""},
#line 1942 "nasdaq.gperf"
      {"FTCI", 1929},
      {""}, {""}, {""}, {""},
#line 479 "nasdaq.gperf"
      {"ATRC", 466},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3265 "nasdaq.gperf"
      {"MSAIW", 3252},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5031 "nasdaq.gperf"
      {"TTAN", 5018},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4921 "nasdaq.gperf"
      {"TLS", 4908},
      {""}, {""},
#line 4578 "nasdaq.gperf"
      {"SMCF", 4565},
      {""},
#line 5073 "nasdaq.gperf"
      {"TXUG", 5060},
#line 4922 "nasdaq.gperf"
      {"TLSA", 4909},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2682 "nasdaq.gperf"
      {"JANX", 2669},
      {""},
#line 4706 "nasdaq.gperf"
      {"SSM", 4693},
      {""}, {""}, {""}, {""}, {""},
#line 4923 "nasdaq.gperf"
      {"TLSI", 4910},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4697 "nasdaq.gperf"
      {"SSAC", 4684},
#line 4699 "nasdaq.gperf"
      {"SSACU", 4686},
      {""}, {""}, {""}, {""},
#line 4698 "nasdaq.gperf"
      {"SSACR", 4685},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5038 "nasdaq.gperf"
      {"TTRX", 5025},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4576 "nasdaq.gperf"
      {"SLXNW", 4563},
      {""}, {""}, {""}, {""},
#line 531 "nasdaq.gperf"
      {"AXTI", 518},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5360 "nasdaq.gperf"
      {"WEYS", 5347},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5313 "nasdaq.gperf"
      {"VTVT", 5300},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 456 "nasdaq.gperf"
      {"ATAT", 443},
#line 4454 "nasdaq.gperf"
      {"SEATW", 4441},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1938 "nasdaq.gperf"
      {"FTAG", 1925},
      {""}, {""}, {""}, {""},
#line 3808 "nasdaq.gperf"
      {"PCSA", 3795},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4014 "nasdaq.gperf"
      {"PSMT", 4001},
#line 27 "nasdaq.gperf"
      {"AAL", 14},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1964 "nasdaq.gperf"
      {"FTXG", 1951},
      {""},
#line 4005 "nasdaq.gperf"
      {"PSCT", 3992},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3796 "nasdaq.gperf"
      {"PBSC", 3783},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3290 "nasdaq.gperf"
      {"MTRX", 3277},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4467 "nasdaq.gperf"
      {"SENS", 4454},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1853 "nasdaq.gperf"
      {"FLNT", 1840},
      {""}, {""}, {""}, {""},
#line 4830 "nasdaq.gperf"
      {"TBLD", 4817},
      {""}, {""}, {""}, {""},
#line 4829 "nasdaq.gperf"
      {"TBLA", 4816},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5346 "nasdaq.gperf"
      {"WDAF", 5333},
      {""}, {""},
#line 1787 "nasdaq.gperf"
      {"FEMB", 1774},
      {""}, {""}, {""}, {""},
#line 5178 "nasdaq.gperf"
      {"VALG", 5165},
      {""},
#line 3101 "nasdaq.gperf"
      {"MCRB", 3088},
      {""}, {""}, {""},
#line 5460 "nasdaq.gperf"
      {"XEL", 5447},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1924 "nasdaq.gperf"
      {"FSCS", 1911},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 563 "nasdaq.gperf"
      {"BBBYW", 550},
      {""}, {""},
#line 996 "nasdaq.gperf"
      {"CDL", 983},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 943 "nasdaq.gperf"
      {"CASY", 930},
      {""},
#line 997 "nasdaq.gperf"
      {"CDLX", 984},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 979 "nasdaq.gperf"
      {"CCLD", 966},
      {""}, {""},
#line 1179 "nasdaq.gperf"
      {"COLA", 1166},
#line 1181 "nasdaq.gperf"
      {"COLAU", 1168},
      {""}, {""}, {""}, {""},
#line 1180 "nasdaq.gperf"
      {"COLAR", 1167},
      {""}, {""}, {""}, {""}, {""},
#line 4001 "nasdaq.gperf"
      {"PSCF", 3988},
      {""}, {""}, {""}, {""},
#line 3114 "nasdaq.gperf"
      {"MDLZ", 3101},
      {""}, {""},
#line 5341 "nasdaq.gperf"
      {"WBTN", 5328},
      {""},
#line 794 "nasdaq.gperf"
      {"BRNY", 781},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 28 "nasdaq.gperf"
      {"AALG", 15},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 435 "nasdaq.gperf"
      {"ASND", 422},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3773 "nasdaq.gperf"
      {"PASG", 3760},
      {""}, {""}, {""},
#line 917 "nasdaq.gperf"
      {"CALC", 904},
      {""}, {""}, {""}, {""},
#line 918 "nasdaq.gperf"
      {"CALI", 905},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3841 "nasdaq.gperf"
      {"PESI", 3828},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 18 "nasdaq.gperf"
      {"AACO", 5},
#line 19 "nasdaq.gperf"
      {"AACOU", 6},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1756 "nasdaq.gperf"
      {"FCNCO", 1743},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4869 "nasdaq.gperf"
      {"TELA", 4856},
      {""}, {""}, {""}, {""}, {""},
#line 141 "nasdaq.gperf"
      {"AENTW", 128},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4711 "nasdaq.gperf"
      {"SSTI", 4698},
      {""}, {""}, {""},
#line 729 "nasdaq.gperf"
      {"BMR", 716},
      {""}, {""}, {""}, {""}, {""},
#line 730 "nasdaq.gperf"
      {"BMRA", 717},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 731 "nasdaq.gperf"
      {"BMRC", 718},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5000 "nasdaq.gperf"
      {"TRUO", 4987},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4803 "nasdaq.gperf"
      {"TACO", 4790},
#line 4804 "nasdaq.gperf"
      {"TACOU", 4791},
      {""}, {""},
#line 5322 "nasdaq.gperf"
      {"VXUS", 5309},
      {""}, {""}, {""}, {""}, {""},
#line 5207 "nasdaq.gperf"
      {"VECO", 5194},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1139 "nasdaq.gperf"
      {"CMMB", 1126},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4701 "nasdaq.gperf"
      {"SSBI", 4688},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3247 "nasdaq.gperf"
      {"MRCO", 3234},
#line 3248 "nasdaq.gperf"
      {"MRCOU", 3235},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5336 "nasdaq.gperf"
      {"WATT", 5323},
      {""}, {""}, {""}, {""},
#line 1013 "nasdaq.gperf"
      {"CELC", 1000},
      {""}, {""}, {""}, {""},
#line 4713 "nasdaq.gperf"
      {"STAA", 4700},
      {""}, {""},
#line 1169 "nasdaq.gperf"
      {"COCO", 1156},
      {""},
#line 1016 "nasdaq.gperf"
      {"CELZ", 1003},
#line 3231 "nasdaq.gperf"
      {"MOMO", 3218},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3123 "nasdaq.gperf"
      {"MELI", 3110},
      {""}, {""}, {""}, {""},
#line 1261 "nasdaq.gperf"
      {"CRVO", 1248},
      {""}, {""}, {""},
#line 4744 "nasdaq.gperf"
      {"STX", 4731},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1126 "nasdaq.gperf"
      {"CLRB", 1113},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5289 "nasdaq.gperf"
      {"VRSN", 5276},
      {""},
#line 3052 "nasdaq.gperf"
      {"MAMO", 3039},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5076 "nasdaq.gperf"
      {"TXXS", 5063},
      {""}, {""}, {""}, {""},
#line 5394 "nasdaq.gperf"
      {"WMT", 5381},
#line 3980 "nasdaq.gperf"
      {"PRLD", 3967},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 393 "nasdaq.gperf"
      {"ARCL", 380},
#line 395 "nasdaq.gperf"
      {"ARCLU", 382},
#line 5472 "nasdaq.gperf"
      {"XLABW", 5459},
      {""}, {""}, {""},
#line 394 "nasdaq.gperf"
      {"ARCLR", 381},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5539 "nasdaq.gperf"
      {"YOUL", 5526},
      {""}, {""}, {""}, {""}, {""},
#line 941 "nasdaq.gperf"
      {"CASS", 928},
      {""}, {""}, {""}, {""},
#line 1934 "nasdaq.gperf"
      {"FSUN", 1921},
      {""}, {""}, {""}, {""},
#line 3940 "nasdaq.gperf"
      {"POLA", 3927},
      {""},
#line 3804 "nasdaq.gperf"
      {"PCLA", 3791},
      {""}, {""},
#line 3058 "nasdaq.gperf"
      {"MASS", 3045},
#line 63 "nasdaq.gperf"
      {"ACCL", 50},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4026 "nasdaq.gperf"
      {"PTCT", 4013},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 792 "nasdaq.gperf"
      {"BRNS", 779},
      {""}, {""}, {""},
#line 43 "nasdaq.gperf"
      {"ABCL", 30},
      {""}, {""}, {""}, {""},
#line 3759 "nasdaq.gperf"
      {"PAL", 3746},
#line 3760 "nasdaq.gperf"
      {"PALD", 3747},
      {""}, {""},
#line 5282 "nasdaq.gperf"
      {"VREX", 5269},
      {""}, {""}, {""}, {""},
#line 4961 "nasdaq.gperf"
      {"TOYO", 4948},
      {""},
#line 231 "nasdaq.gperf"
      {"ALCO", 218},
      {""}, {""}, {""}, {""},
#line 5311 "nasdaq.gperf"
      {"VTRS", 5298},
      {""}, {""},
#line 1918 "nasdaq.gperf"
      {"FRSX", 1905},
      {""},
#line 3761 "nasdaq.gperf"
      {"PALI", 3748},
      {""}, {""}, {""}, {""},
#line 279 "nasdaq.gperf"
      {"ALXO", 266},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4849 "nasdaq.gperf"
      {"TDCL", 4836},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 277 "nasdaq.gperf"
      {"ALVO", 264},
      {""}, {""}, {""}, {""},
#line 5326 "nasdaq.gperf"
      {"WABF", 5313},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1010 "nasdaq.gperf"
      {"CECO", 997},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1943 "nasdaq.gperf"
      {"FTCS", 1930},
      {""}, {""},
#line 399 "nasdaq.gperf"
      {"AREC", 386},
      {""},
#line 804 "nasdaq.gperf"
      {"BSAA", 791},
#line 806 "nasdaq.gperf"
      {"BSAAU", 793},
      {""}, {""}, {""}, {""},
#line 805 "nasdaq.gperf"
      {"BSAAR", 792},
      {""}, {""}, {""},
#line 5404 "nasdaq.gperf"
      {"WRND", 5391},
      {""},
#line 1246 "nasdaq.gperf"
      {"CRML", 1233},
#line 114 "nasdaq.gperf"
      {"ADEA", 101},
      {""},
#line 808 "nasdaq.gperf"
      {"BSCA", 795},
      {""}, {""}, {""}, {""},
#line 816 "nasdaq.gperf"
      {"BSCX", 803},
      {""}, {""},
#line 841 "nasdaq.gperf"
      {"BSMZ", 828},
#line 3244 "nasdaq.gperf"
      {"MRAL", 3231},
      {""}, {""}, {""}, {""}, {""},
#line 3075 "nasdaq.gperf"
      {"MBLY", 3062},
      {""}, {""}, {""}, {""},
#line 818 "nasdaq.gperf"
      {"BSCZ", 805},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1998 "nasdaq.gperf"
      {"FXAC", 1985},
#line 1999 "nasdaq.gperf"
      {"FXACU", 1986},
#line 4024 "nasdaq.gperf"
      {"PTACW", 4011},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1265 "nasdaq.gperf"
      {"CRWL", 1252},
#line 3141 "nasdaq.gperf"
      {"MEVO", 3128},
#line 3142 "nasdaq.gperf"
      {"MEVOU", 3129},
      {""},
#line 5516 "nasdaq.gperf"
      {"YBST", 5503},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3923 "nasdaq.gperf"
      {"PMCB", 3910},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2724 "nasdaq.gperf"
      {"JSM", 2711},
#line 2725 "nasdaq.gperf"
      {"JSMD", 2712},
#line 1260 "nasdaq.gperf"
      {"CRVL", 1247},
#line 5195 "nasdaq.gperf"
      {"VBNB", 5182},
#line 612 "nasdaq.gperf"
      {"BEATW", 599},
      {""}, {""}, {""},
#line 474 "nasdaq.gperf"
      {"ATNI", 461},
      {""},
#line 4641 "nasdaq.gperf"
      {"SORNW", 4628},
#line 5527 "nasdaq.gperf"
      {"YI", 5514},
      {""}, {""}, {""}, {""}, {""},
#line 3261 "nasdaq.gperf"
      {"MRVL", 3248},
      {""}, {""}, {""}, {""}, {""},
#line 1258 "nasdaq.gperf"
      {"CRTO", 1245},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3193 "nasdaq.gperf"
      {"MLCO", 3180},
      {""}, {""}, {""},
#line 5290 "nasdaq.gperf"
      {"VRTL", 5277},
      {""}, {""}, {""}, {""}, {""},
#line 5529 "nasdaq.gperf"
      {"YICC", 5516},
#line 5530 "nasdaq.gperf"
      {"YICCU", 5517},
      {""}, {""},
#line 5177 "nasdaq.gperf"
      {"VAI", 5164},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 81 "nasdaq.gperf"
      {"ACNB", 68},
      {""}, {""}, {""}, {""},
#line 79 "nasdaq.gperf"
      {"ACLS", 66},
      {""}, {""}, {""}, {""},
#line 5443 "nasdaq.gperf"
      {"XAIX", 5430},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 116 "nasdaq.gperf"
      {"ADI", 103},
      {""}, {""}, {""},
#line 5208 "nasdaq.gperf"
      {"VEEA", 5195},
      {""},
#line 50 "nasdaq.gperf"
      {"ABNB", 37},
      {""}, {""},
#line 4991 "nasdaq.gperf"
      {"TRST", 4978},
      {""},
#line 4552 "nasdaq.gperf"
      {"SLAB", 4539},
      {""},
#line 1238 "nasdaq.gperf"
      {"CRE", 1225},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1240 "nasdaq.gperf"
      {"CREX", 1227},
      {""}, {""}, {""}, {""}, {""},
#line 187 "nasdaq.gperf"
      {"AIA", 174},
      {""}, {""}, {""},
#line 199 "nasdaq.gperf"
      {"AIMD", 186},
      {""},
#line 76 "nasdaq.gperf"
      {"ACIC", 63},
      {""}, {""}, {""}, {""},
#line 831 "nasdaq.gperf"
      {"BSJX", 818},
      {""}, {""}, {""},
#line 46 "nasdaq.gperf"
      {"ABI", 33},
      {""}, {""}, {""}, {""},
#line 417 "nasdaq.gperf"
      {"ARTL", 404},
#line 188 "nasdaq.gperf"
      {"AIAI", 175},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 220 "nasdaq.gperf"
      {"AIX", 207},
#line 4715 "nasdaq.gperf"
      {"STBA", 4702},
      {""}, {""}, {""},
#line 4978 "nasdaq.gperf"
      {"TRI", 4965},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 970 "nasdaq.gperf"
      {"CCEC", 957},
#line 3224 "nasdaq.gperf"
      {"MOBBW", 3211},
#line 221 "nasdaq.gperf"
      {"AIXC", 208},
      {""}, {""},
#line 5283 "nasdaq.gperf"
      {"VRIG", 5270},
      {""},
#line 222 "nasdaq.gperf"
      {"AIXI", 209},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4850 "nasdaq.gperf"
      {"TDI", 4837},
      {""}, {""}, {""},
#line 310 "nasdaq.gperf"
      {"AMSC", 297},
      {""}, {""}, {""},
#line 908 "nasdaq.gperf"
      {"CAE", 895},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 850 "nasdaq.gperf"
      {"BSY", 837},
#line 4851 "nasdaq.gperf"
      {"TDIC", 4838},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5352 "nasdaq.gperf"
      {"WEN", 5339},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5199 "nasdaq.gperf"
      {"VCIG", 5186},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 275 "nasdaq.gperf"
      {"ALTO", 262},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1967 "nasdaq.gperf"
      {"FTXN", 1954},
      {""}, {""},
#line 1201 "nasdaq.gperf"
      {"COST", 1188},
      {""}, {""}, {""}, {""}, {""},
#line 4936 "nasdaq.gperf"
      {"TMS", 4923},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3833 "nasdaq.gperf"
      {"PECO", 3820},
      {""}, {""}, {""}, {""},
#line 4712 "nasdaq.gperf"
      {"SSYS", 4699},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1961 "nasdaq.gperf"
      {"FTRI", 1948},
      {""}, {""}, {""},
#line 4562 "nasdaq.gperf"
      {"SLMBP", 4549},
      {""}, {""}, {""},
#line 942 "nasdaq.gperf"
      {"CAST", 929},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3814 "nasdaq.gperf"
      {"PCYO", 3801},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3111 "nasdaq.gperf"
      {"MDIA", 3098},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 236 "nasdaq.gperf"
      {"ALEC", 223},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 47 "nasdaq.gperf"
      {"ABIG", 34},
      {""},
#line 976 "nasdaq.gperf"
      {"CCII", 963},
#line 977 "nasdaq.gperf"
      {"CCIIU", 964},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 137 "nasdaq.gperf"
      {"AEI", 124},
#line 3780 "nasdaq.gperf"
      {"PAYO", 3767},
      {""}, {""},
#line 5179 "nasdaq.gperf"
      {"VALN", 5166},
      {""}, {""}, {""}, {""}, {""},
#line 911 "nasdaq.gperf"
      {"CAI", 898},
#line 3166 "nasdaq.gperf"
      {"MIAC", 3153},
#line 3167 "nasdaq.gperf"
      {"MIACU", 3154},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3171 "nasdaq.gperf"
      {"MIMI", 3158},
#line 3310 "nasdaq.gperf"
      {"MXCT", 3297},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 378 "nasdaq.gperf"
      {"AQLG", 365},
      {""},
#line 912 "nasdaq.gperf"
      {"CAII", 899},
#line 913 "nasdaq.gperf"
      {"CAIIU", 900},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3951 "nasdaq.gperf"
      {"POWL", 3938},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4872 "nasdaq.gperf"
      {"TENB", 4859},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3202 "nasdaq.gperf"
      {"MMSI", 3189},
      {""}, {""}, {""}, {""},
#line 840 "nasdaq.gperf"
      {"BSMY", 827},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 817 "nasdaq.gperf"
      {"BSCY", 804},
      {""}, {""}, {""}, {""},
#line 945 "nasdaq.gperf"
      {"CATLU", 932},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1735 "nasdaq.gperf"
      {"FBL", 1722},
      {""}, {""}, {""},
#line 1298 "nasdaq.gperf"
      {"CTRN", 1285},
      {""},
#line 1736 "nasdaq.gperf"
      {"FBLA", 1723},
      {""}, {""},
#line 862 "nasdaq.gperf"
      {"BTMD", 849},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5356 "nasdaq.gperf"
      {"WERN", 5343},
      {""}, {""}, {""},
#line 3973 "nasdaq.gperf"
      {"PRE", 3960},
      {""}, {""},
#line 851 "nasdaq.gperf"
      {"BTAI", 838},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 993 "nasdaq.gperf"
      {"CDIG", 980},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4448 "nasdaq.gperf"
      {"SDSI", 4435},
      {""},
#line 775 "nasdaq.gperf"
      {"BRCB", 762},
      {""}, {""},
#line 3820 "nasdaq.gperf"
      {"PDEX", 3807},
      {""}, {""},
#line 1176 "nasdaq.gperf"
      {"COIG", 1163},
      {""},
#line 5270 "nasdaq.gperf"
      {"VOLT", 5257},
      {""},
#line 5201 "nasdaq.gperf"
      {"VCLT", 5188},
      {""}, {""},
#line 4434 "nasdaq.gperf"
      {"SCSC", 4421},
      {""},
#line 4016 "nasdaq.gperf"
      {"PSNY", 4003},
      {""}, {""}, {""}, {""},
#line 1327 "nasdaq.gperf"
      {"CXAIW", 1314},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 575 "nasdaq.gperf"
      {"BCAB", 562},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3194 "nasdaq.gperf"
      {"MLEC", 3181},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4034 "nasdaq.gperf"
      {"PTN", 4021},
#line 2729 "nasdaq.gperf"
      {"JTAI", 2716},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3254 "nasdaq.gperf"
      {"MRLN", 3241},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 552 "nasdaq.gperf"
      {"BANF", 539},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3113 "nasdaq.gperf"
      {"MDLN", 3100},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3230 "nasdaq.gperf"
      {"MOLN", 3217},
      {""},
#line 1131 "nasdaq.gperf"
      {"CLST", 1118},
      {""},
#line 832 "nasdaq.gperf"
      {"BSJY", 819},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 189 "nasdaq.gperf"
      {"AIBZ", 176},
      {""}, {""}, {""},
#line 3139 "nasdaq.gperf"
      {"METL", 3126},
#line 1115 "nasdaq.gperf"
      {"CLLS", 1102},
      {""}, {""},
#line 1737 "nasdaq.gperf"
      {"FBLG", 1724},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3789 "nasdaq.gperf"
      {"PBLS", 3776},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3875 "nasdaq.gperf"
      {"PI", 3862},
      {""},
#line 1748 "nasdaq.gperf"
      {"FCCO", 1735},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 727 "nasdaq.gperf"
      {"BMNG", 714},
#line 4924 "nasdaq.gperf"
      {"TLSIW", 4911},
#line 1920 "nasdaq.gperf"
      {"FRVO", 1907},
      {""}, {""},
#line 5519 "nasdaq.gperf"
      {"YDES", 5506},
      {""}, {""},
#line 4700 "nasdaq.gperf"
      {"SSACW", 4687},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 409 "nasdaq.gperf"
      {"ARQ", 396},
#line 1875 "nasdaq.gperf"
      {"FMUB", 1862},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 301 "nasdaq.gperf"
      {"AMLX", 288},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3828 "nasdaq.gperf"
      {"PEBO", 3815},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 732 "nasdaq.gperf"
      {"BMRN", 719},
      {""},
#line 5302 "nasdaq.gperf"
      {"VSNT", 5289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 553 "nasdaq.gperf"
      {"BANFP", 540},
      {""},
#line 4958 "nasdaq.gperf"
      {"TORO", 4945},
#line 1849 "nasdaq.gperf"
      {"FLL", 1836},
#line 621 "nasdaq.gperf"
      {"BENF", 608},
      {""}, {""},
#line 835 "nasdaq.gperf"
      {"BSMS", 822},
      {""}, {""}, {""}, {""}, {""},
#line 3913 "nasdaq.gperf"
      {"PLUL", 3900},
      {""}, {""}, {""}, {""},
#line 5276 "nasdaq.gperf"
      {"VOXR", 5263},
#line 811 "nasdaq.gperf"
      {"BSCS", 798},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4040 "nasdaq.gperf"
      {"PTRN", 4027},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5482 "nasdaq.gperf"
      {"XOVR", 5469},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4571 "nasdaq.gperf"
      {"SLS", 4558},
      {""},
#line 80 "nasdaq.gperf"
      {"ACMR", 67},
      {""},
#line 423 "nasdaq.gperf"
      {"ARWR", 410},
      {""}, {""}, {""}, {""},
#line 5457 "nasdaq.gperf"
      {"XCUR", 5444},
      {""}, {""}, {""},
#line 1001 "nasdaq.gperf"
      {"CDRO", 988},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 868 "nasdaq.gperf"
      {"BTTC", 855},
      {""}, {""}, {""}, {""}, {""},
#line 422 "nasdaq.gperf"
      {"ARVR", 409},
      {""},
#line 1195 "nasdaq.gperf"
      {"CORO", 1182},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4734 "nasdaq.gperf"
      {"STRD", 4721},
      {""}, {""}, {""}, {""},
#line 4732 "nasdaq.gperf"
      {"STRA", 4719},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4733 "nasdaq.gperf"
      {"STRC", 4720},
      {""}, {""}, {""},
#line 5410 "nasdaq.gperf"
      {"WSC", 5397},
      {""}, {""}, {""}, {""}, {""},
#line 4742 "nasdaq.gperf"
      {"STRZ", 4729},
      {""}, {""},
#line 169 "nasdaq.gperf"
      {"AGMI", 156},
      {""}, {""},
#line 125 "nasdaq.gperf"
      {"ADUR", 112},
      {""}, {""}, {""},
#line 161 "nasdaq.gperf"
      {"AGCC", 148},
      {""}, {""}, {""}, {""},
#line 852 "nasdaq.gperf"
      {"BTBD", 839},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 253 "nasdaq.gperf"
      {"ALLT", 240},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5246 "nasdaq.gperf"
      {"VIVS", 5233},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1745 "nasdaq.gperf"
      {"FCAL", 1732},
      {""}, {""}, {""}, {""}, {""},
#line 826 "nasdaq.gperf"
      {"BSJS", 813},
      {""}, {""},
#line 201 "nasdaq.gperf"
      {"AIMS", 188},
      {""}, {""},
#line 5002 "nasdaq.gperf"
      {"TRUR", 4989},
#line 1887 "nasdaq.gperf"
      {"FOCL", 1874},
#line 5070 "nasdaq.gperf"
      {"TXN", 5057},
      {""}, {""}, {""}, {""},
#line 431 "nasdaq.gperf"
      {"ASMB", 418},
#line 930 "nasdaq.gperf"
      {"CAQ", 917},
      {""}, {""}, {""}, {""},
#line 4787 "nasdaq.gperf"
      {"SXTC", 4774},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 380 "nasdaq.gperf"
      {"AQST", 367},
      {""},
#line 4535 "nasdaq.gperf"
      {"SJLD", 4522},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 312 "nasdaq.gperf"
      {"AMSS", 299},
#line 4959 "nasdaq.gperf"
      {"TOUR", 4946},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 909 "nasdaq.gperf"
      {"CAES", 896},
      {""},
#line 4426 "nasdaq.gperf"
      {"SCLX", 4413},
      {""}, {""},
#line 4631 "nasdaq.gperf"
      {"SOLC", 4618},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 20 "nasdaq.gperf"
      {"AACOW", 7},
      {""},
#line 4634 "nasdaq.gperf"
      {"SOLZ", 4621},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1037 "nasdaq.gperf"
      {"CG", 1024},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1040 "nasdaq.gperf"
      {"CGC", 1027},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1905 "nasdaq.gperf"
      {"FREI", 1892},
      {""},
#line 1243 "nasdaq.gperf"
      {"CRIS", 1230},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3164 "nasdaq.gperf"
      {"MGX", 3151},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4805 "nasdaq.gperf"
      {"TACOW", 4792},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 848 "nasdaq.gperf"
      {"BSVN", 835},
      {""},
#line 1135 "nasdaq.gperf"
      {"CMCO", 1122},
#line 5205 "nasdaq.gperf"
      {"VCTR", 5192},
      {""}, {""},
#line 3890 "nasdaq.gperf"
      {"PLBL", 3877},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 845 "nasdaq.gperf"
      {"BSTS", 832},
      {""}, {""}, {""}, {""}, {""},
#line 3249 "nasdaq.gperf"
      {"MRCOW", 3236},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 138 "nasdaq.gperf"
      {"AEIS", 125},
      {""}, {""}, {""}, {""}, {""},
#line 229 "nasdaq.gperf"
      {"ALAR", 216},
      {""},
#line 1917 "nasdaq.gperf"
      {"FRST", 1904},
#line 256 "nasdaq.gperf"
      {"ALMR", 243},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 954 "nasdaq.gperf"
      {"CBRL", 941},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 936 "nasdaq.gperf"
      {"CARL", 923},
#line 1127 "nasdaq.gperf"
      {"CLRO", 1114},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5240 "nasdaq.gperf"
      {"VIR", 5227},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 603 "nasdaq.gperf"
      {"BDSX", 590},
#line 283 "nasdaq.gperf"
      {"AMAL", 270},
#line 5241 "nasdaq.gperf"
      {"VIRC", 5228},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 396 "nasdaq.gperf"
      {"ARCLW", 383},
#line 756 "nasdaq.gperf"
      {"BOSC", 743},
      {""},
#line 1727 "nasdaq.gperf"
      {"FAST", 1714},
      {""},
#line 4707 "nasdaq.gperf"
      {"SSNC", 4694},
      {""}, {""},
#line 836 "nasdaq.gperf"
      {"BSMT", 823},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 812 "nasdaq.gperf"
      {"BSCT", 799},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 855 "nasdaq.gperf"
      {"BTCS", 842},
      {""}, {""},
#line 572 "nasdaq.gperf"
      {"BBSI", 559},
      {""},
#line 246 "nasdaq.gperf"
      {"ALIS", 233},
#line 248 "nasdaq.gperf"
      {"ALISU", 235},
      {""},
#line 66 "nasdaq.gperf"
      {"ACET", 53},
      {""},
#line 4436 "nasdaq.gperf"
      {"SCWO", 4423},
#line 247 "nasdaq.gperf"
      {"ALISR", 234},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1837 "nasdaq.gperf"
      {"FIXD", 1824},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1734 "nasdaq.gperf"
      {"FBIZ", 1721},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3982 "nasdaq.gperf"
      {"PRMR", 3969},
#line 1782 "nasdaq.gperf"
      {"FEBO", 1769},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1783 "nasdaq.gperf"
      {"FEED", 1770},
      {""}, {""}, {""}, {""},
#line 5353 "nasdaq.gperf"
      {"WENN", 5340},
#line 5354 "nasdaq.gperf"
      {"WENNU", 5341},
      {""}, {""}, {""}, {""}, {""},
#line 5406 "nasdaq.gperf"
      {"WSBC", 5393},
      {""}, {""},
#line 5458 "nasdaq.gperf"
      {"XDEF", 5445},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5200 "nasdaq.gperf"
      {"VCIT", 5187},
      {""}, {""}, {""}, {""},
#line 4884 "nasdaq.gperf"
      {"TGTX", 4871},
#line 1107 "nasdaq.gperf"
      {"CLAR", 1094},
      {""}, {""}, {""}, {""},
#line 3802 "nasdaq.gperf"
      {"PCAR", 3789},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5447 "nasdaq.gperf"
      {"XBIT", 5434},
#line 278 "nasdaq.gperf"
      {"ALVOW", 265},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4687 "nasdaq.gperf"
      {"SQS", 4674},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 211 "nasdaq.gperf"
      {"AIRJ", 198},
      {""}, {""},
#line 294 "nasdaq.gperf"
      {"AMEI", 281},
      {""}, {""}, {""}, {""}, {""},
#line 3861 "nasdaq.gperf"
      {"PGC", 3848},
#line 3858 "nasdaq.gperf"
      {"PGAC", 3845},
#line 3860 "nasdaq.gperf"
      {"PGACU", 3847},
      {""}, {""},
#line 5431 "nasdaq.gperf"
      {"WTW", 5418},
      {""},
#line 3859 "nasdaq.gperf"
      {"PGACR", 3846},
      {""},
#line 1247 "nasdaq.gperf"
      {"CRMLW", 1234},
      {""}, {""}, {""}, {""},
#line 1766 "nasdaq.gperf"
      {"FDIG", 1753},
      {""}, {""},
#line 1177 "nasdaq.gperf"
      {"COIN", 1164},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2633 "nasdaq.gperf"
      {"IRMD", 2620},
      {""},
#line 3966 "nasdaq.gperf"
      {"PQJL", 3953},
#line 827 "nasdaq.gperf"
      {"BSJT", 814},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2000 "nasdaq.gperf"
      {"FXACW", 1987},
#line 558 "nasdaq.gperf"
      {"BASG", 545},
      {""},
#line 1847 "nasdaq.gperf"
      {"FLEX", 1834},
      {""},
#line 1052 "nasdaq.gperf"
      {"CGTX", 1039},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3143 "nasdaq.gperf"
      {"MEVOW", 3130},
      {""},
#line 3070 "nasdaq.gperf"
      {"MBIN", 3057},
      {""},
#line 3163 "nasdaq.gperf"
      {"MGTX", 3150},
      {""}, {""},
#line 4933 "nasdaq.gperf"
      {"TMED", 4920},
#line 2469 "nasdaq.gperf"
      {"IDAC", 2456},
#line 2470 "nasdaq.gperf"
      {"IDACU", 2457},
      {""}, {""},
#line 210 "nasdaq.gperf"
      {"AIRG", 197},
#line 2472 "nasdaq.gperf"
      {"IDAI", 2459},
      {""}, {""}, {""}, {""},
#line 2636 "nasdaq.gperf"
      {"IRWD", 2623},
      {""}, {""}, {""},
#line 313 "nasdaq.gperf"
      {"AMST", 300},
#line 2473 "nasdaq.gperf"
      {"IDCC", 2460},
      {""}, {""}, {""}, {""}, {""},
#line 3876 "nasdaq.gperf"
      {"PICS", 3863},
      {""}, {""},
#line 4337 "nasdaq.gperf"
      {"RR", 4324},
#line 2477 "nasdaq.gperf"
      {"IDXX", 2464},
#line 1102 "nasdaq.gperf"
      {"CIRC", 1089},
      {""}, {""}, {""}, {""},
#line 3173 "nasdaq.gperf"
      {"MIRA", 3160},
      {""},
#line 2416 "nasdaq.gperf"
      {"IA", 2403},
      {""},
#line 2456 "nasdaq.gperf"
      {"ICCC", 2443},
#line 1295 "nasdaq.gperf"
      {"CTNT", 1282},
#line 904 "nasdaq.gperf"
      {"CABR", 891},
      {""}, {""}, {""},
#line 1039 "nasdaq.gperf"
      {"CGBD", 1026},
      {""}, {""}, {""},
#line 2425 "nasdaq.gperf"
      {"IBAC", 2412},
      {""}, {""}, {""}, {""}, {""},
#line 2426 "nasdaq.gperf"
      {"IBACR", 2413},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5531 "nasdaq.gperf"
      {"YICCW", 5518},
      {""}, {""}, {""},
#line 298 "nasdaq.gperf"
      {"AMID", 285},
      {""},
#line 4625 "nasdaq.gperf"
      {"SOCL", 4612},
      {""}, {""},
#line 4200 "nasdaq.gperf"
      {"RDAC", 4187},
#line 4202 "nasdaq.gperf"
      {"RDACU", 4189},
      {""},
#line 4319 "nasdaq.gperf"
      {"ROAD", 4306},
      {""},
#line 299 "nasdaq.gperf"
      {"AMIX", 286},
#line 4201 "nasdaq.gperf"
      {"RDACR", 4188},
#line 2593 "nasdaq.gperf"
      {"IOVA", 2580},
      {""}, {""}, {""},
#line 4328 "nasdaq.gperf"
      {"ROMA", 4315},
      {""}, {""}, {""},
#line 4190 "nasdaq.gperf"
      {"RCAX", 4177},
      {""},
#line 4321 "nasdaq.gperf"
      {"ROC", 4308},
#line 2466 "nasdaq.gperf"
      {"ICU", 2453},
      {""}, {""}, {""}, {""},
#line 1724 "nasdaq.gperf"
      {"FALN", 1711},
      {""},
#line 1134 "nasdaq.gperf"
      {"CMBO", 1121},
      {""}, {""}, {""},
#line 5209 "nasdaq.gperf"
      {"VEEAW", 5196},
      {""}, {""},
#line 1138 "nasdaq.gperf"
      {"CME", 1125},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2468 "nasdaq.gperf"
      {"ICUI", 2455},
#line 5487 "nasdaq.gperf"
      {"XQQI", 5474},
      {""}, {""}, {""},
#line 4165 "nasdaq.gperf"
      {"RAA", 4152},
      {""}, {""}, {""},
#line 3200 "nasdaq.gperf"
      {"MMED", 3187},
#line 3863 "nasdaq.gperf"
      {"PGJ", 3850},
#line 5222 "nasdaq.gperf"
      {"VGAS", 5209},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 200 "nasdaq.gperf"
      {"AIMDW", 187},
#line 4167 "nasdaq.gperf"
      {"RACD", 4154},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4166 "nasdaq.gperf"
      {"RACC", 4153},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4573 "nasdaq.gperf"
      {"SLVO", 4560},
      {""},
#line 341 "nasdaq.gperf"
      {"ANV", 328},
#line 311 "nasdaq.gperf"
      {"AMSF", 298},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3865 "nasdaq.gperf"
      {"PGY", 3852},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5228 "nasdaq.gperf"
      {"VGUS", 5215},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3899 "nasdaq.gperf"
      {"PLMR", 3886},
      {""}, {""}, {""}, {""}, {""},
#line 3257 "nasdaq.gperf"
      {"MRNO", 3244},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4203 "nasdaq.gperf"
      {"RDAG", 4190},
#line 4204 "nasdaq.gperf"
      {"RDAGU", 4191},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4906 "nasdaq.gperf"
      {"TITN", 4893},
      {""}, {""}, {""}, {""},
#line 4937 "nasdaq.gperf"
      {"TMSF", 4924},
#line 2478 "nasdaq.gperf"
      {"IDYA", 2465},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 752 "nasdaq.gperf"
      {"BOLD", 739},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4729 "nasdaq.gperf"
      {"STNC", 4716},
#line 712 "nasdaq.gperf"
      {"BLSG", 699},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 856 "nasdaq.gperf"
      {"BTCT", 843},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5027 "nasdaq.gperf"
      {"TSSI", 5014},
      {""}, {""}, {""}, {""},
#line 4449 "nasdaq.gperf"
      {"SDST", 4436},
      {""},
#line 4222 "nasdaq.gperf"
      {"REAX", 4209},
#line 3914 "nasdaq.gperf"
      {"PLUR", 3901},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4220 "nasdaq.gperf"
      {"REAI", 4207},
      {""}, {""}, {""}, {""},
#line 5483 "nasdaq.gperf"
      {"XP", 5470},
      {""}, {""}, {""}, {""}, {""},
#line 978 "nasdaq.gperf"
      {"CCIIW", 965},
      {""}, {""},
#line 1145 "nasdaq.gperf"
      {"CMTL", 1132},
      {""}, {""}, {""},
#line 1163 "nasdaq.gperf"
      {"CNXC", 1150},
      {""}, {""},
#line 3939 "nasdaq.gperf"
      {"POET", 3926},
      {""}, {""}, {""},
#line 4242 "nasdaq.gperf"
      {"REXC", 4229},
      {""}, {""},
#line 4632 "nasdaq.gperf"
      {"SOLS", 4619},
      {""}, {""},
#line 3168 "nasdaq.gperf"
      {"MIACW", 3155},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5420 "nasdaq.gperf"
      {"WTBA", 5407},
      {""}, {""}, {""}, {""}, {""},
#line 914 "nasdaq.gperf"
      {"CAIIW", 901},
#line 342 "nasdaq.gperf"
      {"ANY", 329},
#line 5430 "nasdaq.gperf"
      {"WTMY", 5417},
#line 2635 "nasdaq.gperf"
      {"IRTC", 2622},
      {""}, {""}, {""},
#line 2503 "nasdaq.gperf"
      {"IJT", 2490},
#line 4949 "nasdaq.gperf"
      {"TNMG", 4936},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4181 "nasdaq.gperf"
      {"RAY", 4168},
      {""}, {""}, {""}, {""}, {""},
#line 4182 "nasdaq.gperf"
      {"RAYA", 4169},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4525 "nasdaq.gperf"
      {"SIMA", 4512},
#line 4526 "nasdaq.gperf"
      {"SIMAU", 4513},
#line 4422 "nasdaq.gperf"
      {"SCII", 4409},
#line 4424 "nasdaq.gperf"
      {"SCIIU", 4411},
#line 3277 "nasdaq.gperf"
      {"MSS", 3264},
      {""}, {""}, {""},
#line 4423 "nasdaq.gperf"
      {"SCIIR", 4410},
      {""}, {""}, {""}, {""},
#line 347 "nasdaq.gperf"
      {"APA", 334},
#line 2479 "nasdaq.gperf"
      {"IEAG", 2466},
#line 2481 "nasdaq.gperf"
      {"IEAGU", 2468},
      {""},
#line 361 "nasdaq.gperf"
      {"APMD", 348},
      {""}, {""},
#line 2480 "nasdaq.gperf"
      {"IEAGR", 2467},
      {""}, {""}, {""}, {""},
#line 4293 "nasdaq.gperf"
      {"RLMD", 4280},
#line 5269 "nasdaq.gperf"
      {"VOGX", 5256},
#line 4391 "nasdaq.gperf"
      {"SAIA", 4378},
#line 351 "nasdaq.gperf"
      {"APC", 338},
#line 348 "nasdaq.gperf"
      {"APAC", 335},
#line 350 "nasdaq.gperf"
      {"APACU", 337},
      {""},
#line 358 "nasdaq.gperf"
      {"APMC", 345},
#line 360 "nasdaq.gperf"
      {"APMCU", 347},
      {""},
#line 349 "nasdaq.gperf"
      {"APACR", 336},
      {""},
#line 4392 "nasdaq.gperf"
      {"SAIC", 4379},
#line 359 "nasdaq.gperf"
      {"APMCR", 346},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2447 "nasdaq.gperf"
      {"IBTI", 2434},
      {""},
#line 2133 "nasdaq.gperf"
      {"GO", 2120},
      {""},
#line 4456 "nasdaq.gperf"
      {"SEED", 4443},
      {""}, {""}, {""}, {""}, {""},
#line 2032 "nasdaq.gperf"
      {"GDC", 2019},
      {""}, {""}, {""},
#line 4593 "nasdaq.gperf"
      {"SMSI", 4580},
      {""}, {""}, {""}, {""},
#line 4954 "nasdaq.gperf"
      {"TNYA", 4941},
#line 2184 "nasdaq.gperf"
      {"GRW", 2171},
      {""}, {""}, {""},
#line 3924 "nasdaq.gperf"
      {"PMEC", 3911},
      {""}, {""},
#line 400 "nasdaq.gperf"
      {"ARGX", 387},
      {""}, {""},
#line 4199 "nasdaq.gperf"
      {"RCT", 4186},
      {""},
#line 4572 "nasdaq.gperf"
      {"SLSN", 4559},
#line 372 "nasdaq.gperf"
      {"APWC", 359},
#line 2134 "nasdaq.gperf"
      {"GOAI", 2121},
      {""},
#line 181 "nasdaq.gperf"
      {"AGYS", 168},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 568 "nasdaq.gperf"
      {"BBLG", 555},
      {""}, {""},
#line 4235 "nasdaq.gperf"
      {"REMG", 4222},
      {""},
#line 2428 "nasdaq.gperf"
      {"IBB", 2415},
#line 4402 "nasdaq.gperf"
      {"SATL", 4389},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 339 "nasdaq.gperf"
      {"ANTA", 326},
      {""}, {""},
#line 4017 "nasdaq.gperf"
      {"PSNYW", 4004},
      {""},
#line 340 "nasdaq.gperf"
      {"ANTX", 327},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4338 "nasdaq.gperf"
      {"RRBI", 4325},
#line 68 "nasdaq.gperf"
      {"ACGC", 55},
#line 69 "nasdaq.gperf"
      {"ACGCU", 56},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3195 "nasdaq.gperf"
      {"MLECW", 3182},
      {""}, {""}, {""}, {""},
#line 2476 "nasdaq.gperf"
      {"IDVY", 2463},
#line 412 "nasdaq.gperf"
      {"ARQT", 399},
#line 1715 "nasdaq.gperf"
      {"FAAR", 1702},
#line 2505 "nasdaq.gperf"
      {"ILAG", 2492},
      {""},
#line 2448 "nasdaq.gperf"
      {"IBTJ", 2435},
#line 1838 "nasdaq.gperf"
      {"FIYY", 1825},
      {""},
#line 1812 "nasdaq.gperf"
      {"FGM", 1799},
#line 2147 "nasdaq.gperf"
      {"GOVX", 2134},
      {""}, {""}, {""},
#line 2145 "nasdaq.gperf"
      {"GOU", 2132},
      {""},
#line 999 "nasdaq.gperf"
      {"CDNL", 986},
      {""}, {""}, {""},
#line 2146 "nasdaq.gperf"
      {"GOVI", 2133},
      {""}, {""}, {""}, {""}, {""},
#line 2002 "nasdaq.gperf"
      {"FXNC", 1989},
#line 4191 "nasdaq.gperf"
      {"RCBC", 4178},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1187 "nasdaq.gperf"
      {"CONL", 1174},
#line 4324 "nasdaq.gperf"
      {"ROCY", 4311},
#line 4183 "nasdaq.gperf"
      {"RBB", 4170},
      {""}, {""},
#line 4558 "nasdaq.gperf"
      {"SLE", 4545},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2018 "nasdaq.gperf"
      {"GAVA", 2005},
      {""},
#line 3220 "nasdaq.gperf"
      {"MNY", 3207},
      {""}, {""}, {""},
#line 4907 "nasdaq.gperf"
      {"TJGC", 4894},
      {""}, {""}, {""},
#line 180 "nasdaq.gperf"
      {"AGRZ", 167},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1864 "nasdaq.gperf"
      {"FMAO", 1851},
      {""}, {""}, {""}, {""}, {""},
#line 4838 "nasdaq.gperf"
      {"TCGX", 4825},
      {""},
#line 2165 "nasdaq.gperf"
      {"GRAG", 2152},
      {""},
#line 4216 "nasdaq.gperf"
      {"RDVY", 4203},
      {""}, {""},
#line 3945 "nasdaq.gperf"
      {"PONO", 3932},
#line 3947 "nasdaq.gperf"
      {"PONOU", 3934},
#line 2017 "nasdaq.gperf"
      {"GAUZ", 2004},
      {""},
#line 2445 "nasdaq.gperf"
      {"IBTG", 2432},
      {""},
#line 3946 "nasdaq.gperf"
      {"PONOR", 3933},
      {""}, {""}, {""}, {""}, {""},
#line 4460 "nasdaq.gperf"
      {"SEIC", 4447},
#line 3908 "nasdaq.gperf"
      {"PLTR", 3895},
      {""}, {""}, {""}, {""}, {""},
#line 3235 "nasdaq.gperf"
      {"MPAA", 3222},
      {""},
#line 3071 "nasdaq.gperf"
      {"MBINL", 3058},
      {""},
#line 3931 "nasdaq.gperf"
      {"PN", 3918},
      {""},
#line 534 "nasdaq.gperf"
      {"AZ", 521},
      {""},
#line 1819 "nasdaq.gperf"
      {"FICS", 1806},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5312 "nasdaq.gperf"
      {"VTSI", 5299},
      {""},
#line 215 "nasdaq.gperf"
      {"AIRS", 202},
      {""}, {""}, {""}, {""}, {""},
#line 2029 "nasdaq.gperf"
      {"GCMG", 2016},
      {""},
#line 2185 "nasdaq.gperf"
      {"GRWG", 2172},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4883 "nasdaq.gperf"
      {"TGRZ", 4870},
      {""}, {""}, {""},
#line 5520 "nasdaq.gperf"
      {"YDESW", 5507},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2690 "nasdaq.gperf"
      {"JBSS", 2677},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5256 "nasdaq.gperf"
      {"VMAR", 5243},
#line 376 "nasdaq.gperf"
      {"APYX", 363},
      {""}, {""},
#line 973 "nasdaq.gperf"
      {"CCG", 960},
      {""}, {""},
#line 1160 "nasdaq.gperf"
      {"CNTX", 1147},
      {""}, {""}, {""}, {""},
#line 2049 "nasdaq.gperf"
      {"GEMI", 2036},
      {""},
#line 4741 "nasdaq.gperf"
      {"STRT", 4728},
#line 3115 "nasdaq.gperf"
      {"MDRR", 3102},
      {""}, {""}, {""},
#line 2039 "nasdaq.gperf"
      {"GECC", 2026},
      {""}, {""}, {""}, {""}, {""},
#line 3092 "nasdaq.gperf"
      {"MCGA", 3079},
#line 3093 "nasdaq.gperf"
      {"MCGAU", 3080},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2060 "nasdaq.gperf"
      {"GEW", 2047},
#line 4968 "nasdaq.gperf"
      {"TQQY", 4955},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 854 "nasdaq.gperf"
      {"BTBT", 841},
      {""},
#line 2594 "nasdaq.gperf"
      {"IOYY", 2581},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 622 "nasdaq.gperf"
      {"BENFW", 609},
      {""},
#line 2022 "nasdaq.gperf"
      {"GBUG", 2009},
      {""},
#line 2731 "nasdaq.gperf"
      {"JTTT", 2718},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5438 "nasdaq.gperf"
      {"WXM", 5425},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3162 "nasdaq.gperf"
      {"MGRX", 3149},
      {""}, {""}, {""}, {""},
#line 3160 "nasdaq.gperf"
      {"MGRC", 3147},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1207 "nasdaq.gperf"
      {"CPAG", 1194},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2098 "nasdaq.gperf"
      {"GLAD", 2085},
      {""}, {""},
#line 2108 "nasdaq.gperf"
      {"GLMD", 2095},
#line 5015 "nasdaq.gperf"
      {"TSL", 5002},
      {""}, {""}, {""}, {""},
#line 576 "nasdaq.gperf"
      {"BCAL", 563},
#line 5016 "nasdaq.gperf"
      {"TSLA", 5003},
      {""},
#line 588 "nasdaq.gperf"
      {"BCML", 575},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 761 "nasdaq.gperf"
      {"BOXL", 748},
      {""}, {""}, {""},
#line 1002 "nasdaq.gperf"
      {"CDROW", 989},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4633 "nasdaq.gperf"
      {"SOLT", 4620},
      {""},
#line 2037 "nasdaq.gperf"
      {"GDTC", 2024},
      {""}, {""},
#line 4855 "nasdaq.gperf"
      {"TDSB", 4842},
#line 2030 "nasdaq.gperf"
      {"GCT", 2017},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 605 "nasdaq.gperf"
      {"BDVL", 592},
#line 4735 "nasdaq.gperf"
      {"STRF", 4722},
      {""}, {""}, {""}, {""}, {""},
#line 2048 "nasdaq.gperf"
      {"GEMG", 2035},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4930 "nasdaq.gperf"
      {"TMCR", 4917},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4292 "nasdaq.gperf"
      {"RLAY", 4279},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1344 "nasdaq.gperf"
      {"CZWI", 1331},
#line 853 "nasdaq.gperf"
      {"BTBDW", 840},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5417 "nasdaq.gperf"
      {"WSTN", 5404},
#line 5419 "nasdaq.gperf"
      {"WSTNU", 5406},
#line 3172 "nasdaq.gperf"
      {"MIND", 3159},
      {""},
#line 2619 "nasdaq.gperf"
      {"IQ", 2606},
      {""},
#line 5418 "nasdaq.gperf"
      {"WSTNR", 5405},
#line 1012 "nasdaq.gperf"
      {"CEG", 999},
      {""}, {""}, {""},
#line 573 "nasdaq.gperf"
      {"BBUL", 560},
      {""}, {""}, {""}, {""}, {""},
#line 4214 "nasdaq.gperf"
      {"RDTY", 4201},
      {""}, {""}, {""}, {""},
#line 4913 "nasdaq.gperf"
      {"TLG", 4900},
      {""}, {""},
#line 3291 "nasdaq.gperf"
      {"MTSI", 3278},
      {""},
#line 2023 "nasdaq.gperf"
      {"GCBC", 2010},
      {""},
#line 2620 "nasdaq.gperf"
      {"IQMX", 2607},
#line 2058 "nasdaq.gperf"
      {"GEVG", 2045},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3768 "nasdaq.gperf"
      {"PANL", 3755},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 778 "nasdaq.gperf"
      {"BREZ", 765},
      {""},
#line 2183 "nasdaq.gperf"
      {"GRVY", 2170},
      {""}, {""}, {""},
#line 779 "nasdaq.gperf"
      {"BREZR", 766},
      {""},
#line 3955 "nasdaq.gperf"
      {"PPC", 3942},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2006 "nasdaq.gperf"
      {"GABC", 1993},
      {""}, {""},
#line 984 "nasdaq.gperf"
      {"CCSB", 971},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5017 "nasdaq.gperf"
      {"TSLG", 5004},
      {""},
#line 1958 "nasdaq.gperf"
      {"FTNT", 1945},
      {""}, {""},
#line 1836 "nasdaq.gperf"
      {"FIVN", 1823},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2042 "nasdaq.gperf"
      {"GECCI", 2029},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2119 "nasdaq.gperf"
      {"GLXG", 2106},
      {""},
#line 1804 "nasdaq.gperf"
      {"FGBI", 1791},
#line 4427 "nasdaq.gperf"
      {"SCLXW", 4414},
      {""}, {""}, {""},
#line 1932 "nasdaq.gperf"
      {"FSTB", 1919},
      {""}, {""}, {""}, {""},
#line 4179 "nasdaq.gperf"
      {"RAUS", 4166},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2118 "nasdaq.gperf"
      {"GLWG", 2105},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 537 "nasdaq.gperf"
      {"AZTA", 524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5010 "nasdaq.gperf"
      {"TSCO", 4997},
      {""}, {""}, {""}, {""},
#line 789 "nasdaq.gperf"
      {"BRLS", 776},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1867 "nasdaq.gperf"
      {"FMED", 1854},
      {""}, {""},
#line 1208 "nasdaq.gperf"
      {"CPB", 1195},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1041 "nasdaq.gperf"
      {"CGCF", 1028},
#line 1042 "nasdaq.gperf"
      {"CGCFU", 1029},
      {""}, {""}, {""}, {""},
#line 3236 "nasdaq.gperf"
      {"MPB", 3223},
      {""},
#line 1100 "nasdaq.gperf"
      {"CING", 1087},
      {""}, {""}, {""},
#line 1209 "nasdaq.gperf"
      {"CPBI", 1196},
      {""}, {""},
#line 782 "nasdaq.gperf"
      {"BRID", 769},
      {""}, {""}, {""}, {""}, {""},
#line 5476 "nasdaq.gperf"
      {"XMTR", 5463},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1749 "nasdaq.gperf"
      {"FCEF", 1736},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4486 "nasdaq.gperf"
      {"SGA", 4473},
      {""}, {""}, {""}, {""},
#line 2486 "nasdaq.gperf"
      {"IEUS", 2473},
      {""}, {""}, {""}, {""}, {""},
#line 216 "nasdaq.gperf"
      {"AIRT", 203},
      {""}, {""}, {""},
#line 4487 "nasdaq.gperf"
      {"SGC", 4474},
#line 586 "nasdaq.gperf"
      {"BCIC", 573},
      {""}, {""},
#line 5259 "nasdaq.gperf"
      {"VMET", 5246},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1273 "nasdaq.gperf"
      {"CSCO", 1260},
      {""}, {""},
#line 1161 "nasdaq.gperf"
      {"CNTY", 1148},
#line 748 "nasdaq.gperf"
      {"BOEG", 735},
      {""}, {""}, {""},
#line 1872 "nasdaq.gperf"
      {"FMST", 1859},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5403 "nasdaq.gperf"
      {"WRLD", 5390},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1871 "nasdaq.gperf"
      {"FMNB", 1858},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1162 "nasdaq.gperf"
      {"CNVS", 1149},
      {""},
#line 681 "nasdaq.gperf"
      {"BIXI", 668},
#line 682 "nasdaq.gperf"
      {"BIXIU", 669},
      {""}, {""}, {""}, {""},
#line 1805 "nasdaq.gperf"
      {"FGBIP", 1792},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4582 "nasdaq.gperf"
      {"SMCO", 4569},
      {""}, {""},
#line 616 "nasdaq.gperf"
      {"BEEX", 603},
#line 4343 "nasdaq.gperf"
      {"RRR", 4330},
#line 4494 "nasdaq.gperf"
      {"SGVA", 4481},
      {""}, {""}, {""},
#line 2444 "nasdaq.gperf"
      {"IBRX", 2431},
#line 5344 "nasdaq.gperf"
      {"WCLD", 5331},
      {""}, {""}, {""}, {""}, {""},
#line 3935 "nasdaq.gperf"
      {"PNTG", 3922},
      {""},
#line 617 "nasdaq.gperf"
      {"BEEZ", 604},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4463 "nasdaq.gperf"
      {"SELF", 4450},
      {""}, {""}, {""}, {""},
#line 679 "nasdaq.gperf"
      {"BIVI", 666},
      {""}, {""}, {""}, {""},
#line 473 "nasdaq.gperf"
      {"ATLX", 460},
#line 287 "nasdaq.gperf"
      {"AMBR", 274},
      {""}, {""}, {""},
#line 468 "nasdaq.gperf"
      {"ATLC", 455},
      {""}, {""}, {""}, {""},
#line 1765 "nasdaq.gperf"
      {"FDIF", 1752},
      {""}, {""}, {""}, {""},
#line 5330 "nasdaq.gperf"
      {"WALD", 5317},
      {""},
#line 433 "nasdaq.gperf"
      {"ASML", 420},
      {""},
#line 4013 "nasdaq.gperf"
      {"PSL", 4000},
      {""}, {""}, {""}, {""}, {""},
#line 3343 "nasdaq.gperf"
      {"MZTI", 3330},
#line 471 "nasdaq.gperf"
      {"ATLCZ", 458},
      {""}, {""}, {""}, {""},
#line 3834 "nasdaq.gperf"
      {"PEGA", 3821},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1885 "nasdaq.gperf"
      {"FNX", 1872},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2708 "nasdaq.gperf"
      {"JJSF", 2695},
      {""}, {""}, {""}, {""},
#line 1884 "nasdaq.gperf"
      {"FNWD", 1871},
      {""},
#line 2120 "nasdaq.gperf"
      {"GLXY", 2107},
      {""}, {""},
#line 3824 "nasdaq.gperf"
      {"PDSB", 3811},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 217 "nasdaq.gperf"
      {"AIRTP", 204},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5408 "nasdaq.gperf"
      {"WSBF", 5395},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4962 "nasdaq.gperf"
      {"TPCS", 4949},
      {""},
#line 5355 "nasdaq.gperf"
      {"WENNW", 5342},
#line 4569 "nasdaq.gperf"
      {"SLQD", 4556},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5298 "nasdaq.gperf"
      {"VSEC", 5285},
#line 5299 "nasdaq.gperf"
      {"VSECU", 5286},
      {""}, {""},
#line 3963 "nasdaq.gperf"
      {"PPTA", 3950},
#line 1882 "nasdaq.gperf"
      {"FNUC", 1869},
#line 2427 "nasdaq.gperf"
      {"IBAT", 2414},
      {""}, {""}, {""},
#line 548 "nasdaq.gperf"
      {"BAIG", 535},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5467 "nasdaq.gperf"
      {"XGN", 5454},
      {""},
#line 4975 "nasdaq.gperf"
      {"TRGS", 4962},
#line 4977 "nasdaq.gperf"
      {"TRGSU", 4964},
      {""}, {""}, {""}, {""},
#line 4976 "nasdaq.gperf"
      {"TRGSR", 4963},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 538 "nasdaq.gperf"
      {"AZYY", 525},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4189 "nasdaq.gperf"
      {"RCAT", 4176},
      {""}, {""},
#line 4197 "nasdaq.gperf"
      {"RCMT", 4184},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 212 "nasdaq.gperf"
      {"AIRJW", 199},
      {""}, {""}, {""},
#line 684 "nasdaq.gperf"
      {"BIYA", 671},
      {""}, {""}, {""}, {""},
#line 5315 "nasdaq.gperf"
      {"VTWO", 5302},
#line 470 "nasdaq.gperf"
      {"ATLCP", 457},
      {""}, {""}, {""},
#line 4462 "nasdaq.gperf"
      {"SEIS", 4449},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 429 "nasdaq.gperf"
      {"ASEC", 416},
      {""}, {""}, {""}, {""},
#line 2514 "nasdaq.gperf"
      {"IMA", 2501},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4984 "nasdaq.gperf"
      {"TRNR", 4971},
      {""}, {""}, {""},
#line 5461 "nasdaq.gperf"
      {"XELB", 5448},
#line 1164 "nasdaq.gperf"
      {"CNXN", 1151},
#line 2522 "nasdaq.gperf"
      {"IMMX", 2509},
      {""}, {""},
#line 4215 "nasdaq.gperf"
      {"RDVT", 4202},
      {""}, {""}, {""},
#line 1272 "nasdaq.gperf"
      {"CSCL", 1259},
#line 170 "nasdaq.gperf"
      {"AGNC", 157},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2515 "nasdaq.gperf"
      {"IMCC", 2502},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2512 "nasdaq.gperf"
      {"ILMN", 2499},
#line 176 "nasdaq.gperf"
      {"AGNCZ", 163},
      {""}, {""}, {""},
#line 2471 "nasdaq.gperf"
      {"IDACW", 2458},
      {""}, {""},
#line 5421 "nasdaq.gperf"
      {"WTBN", 5408},
#line 2537 "nasdaq.gperf"
      {"IMXI", 2524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1182 "nasdaq.gperf"
      {"COLB", 1169},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4574 "nasdaq.gperf"
      {"SLVR", 4561},
      {""},
#line 4691 "nasdaq.gperf"
      {"SRET", 4678},
#line 4581 "nasdaq.gperf"
      {"SMCL", 4568},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1886 "nasdaq.gperf"
      {"FNY", 1873},
#line 445 "nasdaq.gperf"
      {"ASST", 432},
      {""}, {""}, {""}, {""},
#line 3218 "nasdaq.gperf"
      {"MNTS", 3205},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2535 "nasdaq.gperf"
      {"IMUX", 2522},
      {""}, {""}, {""},
#line 4953 "nasdaq.gperf"
      {"TNXT", 4940},
      {""},
#line 677 "nasdaq.gperf"
      {"BITA", 664},
      {""}, {""},
#line 2167 "nasdaq.gperf"
      {"GRAN", 2154},
      {""}, {""}, {""}, {""}, {""},
#line 4621 "nasdaq.gperf"
      {"SOBR", 4608},
      {""}, {""}, {""}, {""}, {""},
#line 791 "nasdaq.gperf"
      {"BRLT", 778},
      {""}, {""}, {""},
#line 5304 "nasdaq.gperf"
      {"VSTL", 5291},
      {""},
#line 1898 "nasdaq.gperf"
      {"FPA", 1885},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4408 "nasdaq.gperf"
      {"SBET", 4395},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4531 "nasdaq.gperf"
      {"SIRI", 4518},
      {""},
#line 3974 "nasdaq.gperf"
      {"PRENW", 3961},
      {""}, {""},
#line 2467 "nasdaq.gperf"
      {"ICUCW", 2454},
#line 4385 "nasdaq.gperf"
      {"SABR", 4372},
      {""}, {""}, {""},
#line 5039 "nasdaq.gperf"
      {"TTWO", 5026},
#line 982 "nasdaq.gperf"
      {"CCNR", 969},
      {""},
#line 753 "nasdaq.gperf"
      {"BOLT", 740},
      {""}, {""}, {""}, {""}, {""},
#line 662 "nasdaq.gperf"
      {"BIB", 649},
      {""},
#line 5223 "nasdaq.gperf"
      {"VGASW", 5210},
      {""}, {""}, {""}, {""}, {""},
#line 1900 "nasdaq.gperf"
      {"FPXI", 1887},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2035 "nasdaq.gperf"
      {"GDRX", 2022},
      {""}, {""}, {""}, {""},
#line 5021 "nasdaq.gperf"
      {"TSLS", 5008},
      {""}, {""},
#line 177 "nasdaq.gperf"
      {"AGNG", 164},
      {""}, {""}, {""}, {""},
#line 3268 "nasdaq.gperf"
      {"MSEX", 3255},
      {""},
#line 4224 "nasdaq.gperf"
      {"RECT", 4211},
#line 175 "nasdaq.gperf"
      {"AGNCP", 162},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 450 "nasdaq.gperf"
      {"ASTL", 437},
#line 1047 "nasdaq.gperf"
      {"CGNX", 1034},
      {""}, {""}, {""},
#line 3156 "nasdaq.gperf"
      {"MGN", 3143},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3158 "nasdaq.gperf"
      {"MGNX", 3145},
      {""}, {""}, {""},
#line 1890 "nasdaq.gperf"
      {"FORR", 1877},
      {""},
#line 242 "nasdaq.gperf"
      {"ALGS", 229},
      {""}, {""}, {""},
#line 3157 "nasdaq.gperf"
      {"MGNI", 3144},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4184 "nasdaq.gperf"
      {"RBBN", 4171},
      {""}, {""}, {""}, {""},
#line 4243 "nasdaq.gperf"
      {"REYN", 4230},
      {""}, {""},
#line 5407 "nasdaq.gperf"
      {"WSBCO", 5394},
      {""},
#line 3219 "nasdaq.gperf"
      {"MNVT", 3206},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3926 "nasdaq.gperf"
      {"PMTR", 3913},
#line 3927 "nasdaq.gperf"
      {"PMTRU", 3914},
      {""}, {""}, {""},
#line 3258 "nasdaq.gperf"
      {"MRNOW", 3245},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4205 "nasdaq.gperf"
      {"RDAGW", 4192},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2819 "nasdaq.gperf"
      {"KRMD", 2806},
      {""},
#line 704 "nasdaq.gperf"
      {"BLLN", 691},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 777 "nasdaq.gperf"
      {"BRES", 764},
      {""}, {""}, {""}, {""},
#line 4594 "nasdaq.gperf"
      {"SMST", 4581},
      {""}, {""},
#line 1032 "nasdaq.gperf"
      {"CFA", 1019},
#line 373 "nasdaq.gperf"
      {"APXT", 360},
#line 374 "nasdaq.gperf"
      {"APXTU", 361},
      {""},
#line 3144 "nasdaq.gperf"
      {"MF", 3131},
      {""}, {""}, {""}, {""},
#line 151 "nasdaq.gperf"
      {"AFCG", 138},
#line 2756 "nasdaq.gperf"
      {"KC", 2743},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4450 "nasdaq.gperf"
      {"SDSTW", 4437},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5382 "nasdaq.gperf"
      {"WLCO", 5369},
#line 5383 "nasdaq.gperf"
      {"WLCOU", 5370},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1008 "nasdaq.gperf"
      {"CDZI", 995},
#line 4636 "nasdaq.gperf"
      {"SONO", 4623},
      {""},
#line 4588 "nasdaq.gperf"
      {"SMID", 4575},
#line 1159 "nasdaq.gperf"
      {"CNTN", 1146},
      {""}, {""}, {""}, {""},
#line 3977 "nasdaq.gperf"
      {"PRGS", 3964},
      {""}, {""}, {""},
#line 3822 "nasdaq.gperf"
      {"PDLB", 3809},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2038 "nasdaq.gperf"
      {"GDYN", 2025},
#line 1283 "nasdaq.gperf"
      {"CSTL", 1270},
      {""}, {""}, {""}, {""},
#line 2534 "nasdaq.gperf"
      {"IMTX", 2521},
      {""}, {""},
#line 160 "nasdaq.gperf"
      {"AFYA", 147},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 481 "nasdaq.gperf"
      {"ATTO", 468},
      {""}, {""},
#line 2753 "nasdaq.gperf"
      {"KBWD", 2740},
      {""}, {""}, {""}, {""},
#line 4320 "nasdaq.gperf"
      {"ROBT", 4307},
      {""},
#line 1829 "nasdaq.gperf"
      {"FINX", 1816},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 469 "nasdaq.gperf"
      {"ATLCL", 456},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4527 "nasdaq.gperf"
      {"SIMAW", 4514},
      {""}, {""},
#line 643 "nasdaq.gperf"
      {"BGM", 630},
      {""}, {""}, {""}, {""}, {""},
#line 4223 "nasdaq.gperf"
      {"REBN", 4210},
#line 4934 "nasdaq.gperf"
      {"TMNL", 4921},
      {""}, {""},
#line 2124 "nasdaq.gperf"
      {"GMM", 2111},
      {""},
#line 633 "nasdaq.gperf"
      {"BGC", 620},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1776 "nasdaq.gperf"
      {"FDSB", 1763},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4305 "nasdaq.gperf"
      {"RMTI", 4292},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 461 "nasdaq.gperf"
      {"ATEX", 448},
      {""}, {""}, {""},
#line 4710 "nasdaq.gperf"
      {"SSS", 4697},
#line 459 "nasdaq.gperf"
      {"ATEC", 446},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2723 "nasdaq.gperf"
      {"JRVR", 2710},
      {""},
#line 2704 "nasdaq.gperf"
      {"JG", 2691},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 569 "nasdaq.gperf"
      {"BBLGW", 556},
      {""}, {""}, {""},
#line 4007 "nasdaq.gperf"
      {"PSEC", 3994},
#line 241 "nasdaq.gperf"
      {"ALGN", 228},
#line 4403 "nasdaq.gperf"
      {"SATLW", 4390},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4516 "nasdaq.gperf"
      {"SIBN", 4503},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1009 "nasdaq.gperf"
      {"CDZIP", 996},
      {""},
#line 4295 "nasdaq.gperf"
      {"RMBI", 4282},
#line 2763 "nasdaq.gperf"
      {"KE", 2750},
      {""}, {""}, {""}, {""},
#line 3934 "nasdaq.gperf"
      {"PNRG", 3921},
#line 70 "nasdaq.gperf"
      {"ACGCW", 57},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1343 "nasdaq.gperf"
      {"CZR", 1330},
#line 5310 "nasdaq.gperf"
      {"VTIX", 5297},
      {""}, {""}, {""}, {""},
#line 5507 "nasdaq.gperf"
      {"XTIA", 5494},
      {""}, {""}, {""},
#line 1174 "nasdaq.gperf"
      {"COGT", 1161},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5033 "nasdaq.gperf"
      {"TTEC", 5020},
      {""}, {""},
#line 4602 "nasdaq.gperf"
      {"SNAG", 4589},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2475 "nasdaq.gperf"
      {"IDN", 2462},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5359 "nasdaq.gperf"
      {"WETO", 5346},
      {""},
#line 2585 "nasdaq.gperf"
      {"IOND", 2572},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2589 "nasdaq.gperf"
      {"IONX", 2576},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 634 "nasdaq.gperf"
      {"BGCG", 621},
      {""},
#line 2100 "nasdaq.gperf"
      {"GLBS", 2087},
      {""},
#line 2590 "nasdaq.gperf"
      {"IONZ", 2577},
#line 5373 "nasdaq.gperf"
      {"WIMA", 5360},
      {""},
#line 3161 "nasdaq.gperf"
      {"MGRT", 3148},
#line 171 "nasdaq.gperf"
      {"AGNCL", 158},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5374 "nasdaq.gperf"
      {"WIMI", 5361},
      {""},
#line 465 "nasdaq.gperf"
      {"ATII", 452},
#line 466 "nasdaq.gperf"
      {"ATIIU", 453},
      {""}, {""},
#line 5378 "nasdaq.gperf"
      {"WIX", 5365},
      {""}, {""}, {""}, {""},
#line 3853 "nasdaq.gperf"
      {"PFM", 3840},
      {""},
#line 4055 "nasdaq.gperf"
      {"PXS", 4042},
#line 4619 "nasdaq.gperf"
      {"SNY", 4606},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4011 "nasdaq.gperf"
      {"PSIX", 3998},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3846 "nasdaq.gperf"
      {"PFAI", 3833},
      {""}, {""}, {""}, {""},
#line 2825 "nasdaq.gperf"
      {"KRT", 2812},
#line 1291 "nasdaq.gperf"
      {"CTEC", 1278},
      {""}, {""},
#line 3856 "nasdaq.gperf"
      {"PFX", 3843},
      {""},
#line 2787 "nasdaq.gperf"
      {"KLAC", 2774},
      {""},
#line 2015 "nasdaq.gperf"
      {"GARY", 2002},
      {""}, {""},
#line 3288 "nasdaq.gperf"
      {"MTEX", 3275},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5351 "nasdaq.gperf"
      {"WEEI", 5338},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 335 "nasdaq.gperf"
      {"ANNA", 322},
#line 1112 "nasdaq.gperf"
      {"CLGN", 1099},
      {""},
#line 243 "nasdaq.gperf"
      {"ALGT", 230},
      {""},
#line 337 "nasdaq.gperf"
      {"ANNX", 324},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4172 "nasdaq.gperf"
      {"RAND", 4159},
      {""},
#line 4649 "nasdaq.gperf"
      {"SPAI", 4636},
      {""}, {""}, {""}, {""},
#line 4656 "nasdaq.gperf"
      {"SPCX", 4643},
      {""}, {""},
#line 202 "nasdaq.gperf"
      {"AINF", 189},
      {""},
#line 4680 "nasdaq.gperf"
      {"SPXD", 4667},
      {""}, {""}, {""},
#line 799 "nasdaq.gperf"
      {"BRTR", 786},
      {""}, {""}, {""},
#line 4176 "nasdaq.gperf"
      {"RANI", 4163},
#line 698 "nasdaq.gperf"
      {"BLCR", 685},
#line 3094 "nasdaq.gperf"
      {"MCGAW", 3081},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4979 "nasdaq.gperf"
      {"TRIB", 4966},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2744 "nasdaq.gperf"
      {"KAT", 2731},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4442 "nasdaq.gperf"
      {"SDG", 4429},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5357 "nasdaq.gperf"
      {"WEST", 5344},
      {""}, {""}, {""},
#line 4615 "nasdaq.gperf"
      {"SNT", 4602},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3289 "nasdaq.gperf"
      {"MTLS", 3276},
      {""}, {""},
#line 4617 "nasdaq.gperf"
      {"SNTI", 4604},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4412 "nasdaq.gperf"
      {"SBGI", 4399},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4010 "nasdaq.gperf"
      {"PSIG", 3997},
      {""}, {""}, {""}, {""},
#line 3311 "nasdaq.gperf"
      {"MXL", 3298},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2788 "nasdaq.gperf"
      {"KLAG", 2775},
      {""}, {""}, {""},
#line 675 "nasdaq.gperf"
      {"BIRD", 662},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1830 "nasdaq.gperf"
      {"FINY", 1817},
      {""}, {""},
#line 2755 "nasdaq.gperf"
      {"KBWY", 2742},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1931 "nasdaq.gperf"
      {"FSLY", 1918},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 678 "nasdaq.gperf"
      {"BITS", 665},
      {""}, {""},
#line 4173 "nasdaq.gperf"
      {"RANG", 4160},
#line 4175 "nasdaq.gperf"
      {"RANGU", 4162},
      {""}, {""}, {""}, {""},
#line 4174 "nasdaq.gperf"
      {"RANGR", 4161},
#line 4237 "nasdaq.gperf"
      {"RENX", 4224},
#line 453 "nasdaq.gperf"
      {"ASUR", 440},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1099 "nasdaq.gperf"
      {"CINF", 1086},
#line 3845 "nasdaq.gperf"
      {"PEZ", 3832},
      {""}, {""},
#line 1281 "nasdaq.gperf"
      {"CSQ", 1268},
      {""}, {""}, {""},
#line 1868 "nasdaq.gperf"
      {"FMET", 1855},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 723 "nasdaq.gperf"
      {"BMEA", 710},
      {""}, {""}, {""}, {""},
#line 2621 "nasdaq.gperf"
      {"IQMXW", 2608},
      {""}, {""}, {""},
#line 2677 "nasdaq.gperf"
      {"JABRU", 2664},
      {""}, {""}, {""},
#line 4616 "nasdaq.gperf"
      {"SNTG", 4603},
#line 2676 "nasdaq.gperf"
      {"JABRR", 2663},
      {""}, {""},
#line 5389 "nasdaq.gperf"
      {"WLII", 5376},
#line 5390 "nasdaq.gperf"
      {"WLIIU", 5377},
      {""}, {""}, {""},
#line 1105 "nasdaq.gperf"
      {"CIVB", 1092},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 986 "nasdaq.gperf"
      {"CCSO", 973},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3864 "nasdaq.gperf"
      {"PGNY", 3851},
#line 624 "nasdaq.gperf"
      {"BETR", 611},
      {""},
#line 4491 "nasdaq.gperf"
      {"SGMT", 4478},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 790 "nasdaq.gperf"
      {"BRLSW", 777},
      {""}, {""},
#line 2424 "nasdaq.gperf"
      {"IART", 2411},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4675 "nasdaq.gperf"
      {"SPT", 4662},
      {""}, {""}, {""},
#line 344 "nasdaq.gperf"
      {"AOSL", 331},
#line 1043 "nasdaq.gperf"
      {"CGCFW", 1030},
      {""}, {""}, {""}, {""}, {""},
#line 4676 "nasdaq.gperf"
      {"SPTX", 4663},
      {""},
#line 1101 "nasdaq.gperf"
      {"CINGW", 1088},
#line 2014 "nasdaq.gperf"
      {"GANX", 2001},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1925 "nasdaq.gperf"
      {"FSEA", 1912},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3847 "nasdaq.gperf"
      {"PFBC", 3834},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 701 "nasdaq.gperf"
      {"BLIN", 688},
      {""},
#line 1813 "nasdaq.gperf"
      {"FGNX", 1800},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 735 "nasdaq.gperf"
      {"BNC", 722},
      {""}, {""}, {""}, {""}, {""},
#line 733 "nasdaq.gperf"
      {"BNAI", 720},
      {""}, {""}, {""}, {""}, {""},
#line 2530 "nasdaq.gperf"
      {"IMRX", 2517},
#line 660 "nasdaq.gperf"
      {"BIAF", 647},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 480 "nasdaq.gperf"
      {"ATRO", 467},
      {""},
#line 4652 "nasdaq.gperf"
      {"SPBC", 4639},
      {""}, {""},
#line 1968 "nasdaq.gperf"
      {"FTXO", 1955},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1873 "nasdaq.gperf"
      {"FMSTW", 1860},
#line 2713 "nasdaq.gperf"
      {"JMID", 2700},
      {""}, {""},
#line 2826 "nasdaq.gperf"
      {"KRUS", 2813},
      {""}, {""}, {""}, {""}, {""},
#line 4459 "nasdaq.gperf"
      {"SEGG", 4446},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 683 "nasdaq.gperf"
      {"BIXIW", 670},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3132 "nasdaq.gperf"
      {"MESO", 3119},
#line 4302 "nasdaq.gperf"
      {"RMR", 4289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 844 "nasdaq.gperf"
      {"BSSX", 831},
#line 722 "nasdaq.gperf"
      {"BMBL", 709},
      {""}, {""}, {""},
#line 644 "nasdaq.gperf"
      {"BGMS", 631},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 680 "nasdaq.gperf"
      {"BIVIW", 667},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5331 "nasdaq.gperf"
      {"WALDW", 5318},
#line 3954 "nasdaq.gperf"
      {"PPBT", 3941},
      {""},
#line 2050 "nasdaq.gperf"
      {"GEN", 2037},
      {""},
#line 1275 "nasdaq.gperf"
      {"CSEN", 1262},
#line 1799 "nasdaq.gperf"
      {"FFAI", 1786},
      {""}, {""}, {""}, {""}, {""},
#line 2769 "nasdaq.gperf"
      {"KEYY", 2756},
#line 2770 "nasdaq.gperf"
      {"KEYYU", 2757},
      {""}, {""}, {""},
#line 3991 "nasdaq.gperf"
      {"PRSO", 3978},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2054 "nasdaq.gperf"
      {"GENZ", 2041},
      {""},
#line 156 "nasdaq.gperf"
      {"AFRI", 143},
      {""}, {""},
#line 178 "nasdaq.gperf"
      {"AGNT", 165},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4493 "nasdaq.gperf"
      {"SGRY", 4480},
      {""}, {""}, {""}, {""}, {""},
#line 1814 "nasdaq.gperf"
      {"FGNXP", 1801},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 647 "nasdaq.gperf"
      {"BGUS", 634},
      {""}, {""}, {""}, {""},
#line 4296 "nasdaq.gperf"
      {"RMBS", 4283},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2827 "nasdaq.gperf"
      {"KRYS", 2814},
#line 2536 "nasdaq.gperf"
      {"IMVT", 2523},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5364 "nasdaq.gperf"
      {"WGMI", 5351},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2109 "nasdaq.gperf"
      {"GLND", 2096},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3280 "nasdaq.gperf"
      {"MSTR", 3267},
#line 2588 "nasdaq.gperf"
      {"IONS", 2575},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5510 "nasdaq.gperf"
      {"XXII", 5497},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 554 "nasdaq.gperf"
      {"BANL", 541},
#line 1342 "nasdaq.gperf"
      {"CZNC", 1329},
      {""}, {""}, {""}, {""},
#line 5212 "nasdaq.gperf"
      {"VELO", 5199},
      {""}, {""},
#line 167 "nasdaq.gperf"
      {"AGMB", 154},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 762 "nasdaq.gperf"
      {"BPAC", 749},
#line 764 "nasdaq.gperf"
      {"BPACU", 751},
      {""}, {""}, {""}, {""},
#line 763 "nasdaq.gperf"
      {"BPACR", 750},
      {""}, {""},
#line 1906 "nasdaq.gperf"
      {"FRGT", 1893},
      {""}, {""}, {""}, {""},
#line 1271 "nasdaq.gperf"
      {"CSBR", 1258},
      {""}, {""},
#line 1966 "nasdaq.gperf"
      {"FTXL", 1953},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1046 "nasdaq.gperf"
      {"CGNT", 1033},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 796 "nasdaq.gperf"
      {"BRRR", 783},
      {""}, {""}, {""},
#line 4726 "nasdaq.gperf"
      {"STLD", 4713},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2057 "nasdaq.gperf"
      {"GERN", 2044},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4905 "nasdaq.gperf"
      {"TISC", 4892},
      {""}, {""}, {""}, {""},
#line 2742 "nasdaq.gperf"
      {"KARD", 2729},
      {""},
#line 584 "nasdaq.gperf"
      {"BCG", 571},
      {""}, {""},
#line 746 "nasdaq.gperf"
      {"BNTX", 733},
      {""}, {""}, {""}, {""},
#line 745 "nasdaq.gperf"
      {"BNTC", 732},
      {""},
#line 4297 "nasdaq.gperf"
      {"RMCF", 4284},
      {""}, {""}, {""}, {""}, {""},
#line 1302 "nasdaq.gperf"
      {"CTXR", 1289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 565 "nasdaq.gperf"
      {"BBGI", 552},
      {""},
#line 2111 "nasdaq.gperf"
      {"GLNG", 2098},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 318 "nasdaq.gperf"
      {"AMZD", 305},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 483 "nasdaq.gperf"
      {"ATYR", 470},
      {""}, {""},
#line 296 "nasdaq.gperf"
      {"AMGN", 283},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 321 "nasdaq.gperf"
      {"AMZZ", 308},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4870 "nasdaq.gperf"
      {"TELO", 4857},
      {""}, {""}, {""}, {""},
#line 280 "nasdaq.gperf"
      {"ALZN", 267},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1215 "nasdaq.gperf"
      {"CPRT", 1202},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 251 "nasdaq.gperf"
      {"ALLO", 238},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 896 "nasdaq.gperf"
      {"BZ", 883},
      {""},
#line 451 "nasdaq.gperf"
      {"ASTLW", 438},
#line 2680 "nasdaq.gperf"
      {"JAGX", 2667},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 897 "nasdaq.gperf"
      {"BZAI", 884},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1329 "nasdaq.gperf"
      {"CXII", 1316},
#line 1330 "nasdaq.gperf"
      {"CXIIU", 1317},
      {""}, {""},
#line 4702 "nasdaq.gperf"
      {"SSEA", 4689},
#line 4704 "nasdaq.gperf"
      {"SSEAU", 4691},
      {""}, {""}, {""}, {""},
#line 4703 "nasdaq.gperf"
      {"SSEAR", 4690},
      {""}, {""}, {""}, {""},
#line 2807 "nasdaq.gperf"
      {"KOYN", 2794},
#line 2808 "nasdaq.gperf"
      {"KOYNU", 2795},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3928 "nasdaq.gperf"
      {"PMTRW", 3915},
      {""}, {""}, {""}, {""},
#line 1800 "nasdaq.gperf"
      {"FFBC", 1787},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2738 "nasdaq.gperf"
      {"JZ", 2725},
      {""}, {""},
#line 5335 "nasdaq.gperf"
      {"WATR", 5322},
      {""}, {""}, {""}, {""},
#line 4020 "nasdaq.gperf"
      {"PSTR", 4007},
      {""}, {""}, {""},
#line 618 "nasdaq.gperf"
      {"BEG", 605},
#line 620 "nasdaq.gperf"
      {"BELFB", 607},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5343 "nasdaq.gperf"
      {"WCBR", 5330},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 375 "nasdaq.gperf"
      {"APXTW", 362},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2721 "nasdaq.gperf"
      {"JPY", 2708},
      {""}, {""},
#line 5552 "nasdaq.gperf"
      {"Z", 5539},
      {""},
#line 3287 "nasdaq.gperf"
      {"MTEN", 3274},
      {""}, {""}, {""}, {""}, {""},
#line 1183 "nasdaq.gperf"
      {"COLL", 1170},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4008 "nasdaq.gperf"
      {"PSET", 3995},
      {""}, {""},
#line 5384 "nasdaq.gperf"
      {"WLCOW", 5371},
      {""}, {""}, {""}, {""},
#line 3857 "nasdaq.gperf"
      {"PFXNZ", 3844},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 952 "nasdaq.gperf"
      {"CBLL", 939},
#line 5285 "nasdaq.gperf"
      {"VRME", 5272},
#line 174 "nasdaq.gperf"
      {"AGNCO", 161},
      {""}, {""}, {""},
#line 5558 "nasdaq.gperf"
      {"ZD", 5545},
      {""}, {""},
#line 2790 "nasdaq.gperf"
      {"KLRA", 2777},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1848 "nasdaq.gperf"
      {"FLGT", 1835},
      {""}, {""},
#line 4482 "nasdaq.gperf"
      {"SFM", 4469},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2764 "nasdaq.gperf"
      {"KEAT", 2751},
      {""}, {""}, {""},
#line 5559 "nasdaq.gperf"
      {"ZDAI", 5546},
      {""}, {""},
#line 5557 "nasdaq.gperf"
      {"ZCMD", 5544},
      {""}, {""}, {""}, {""},
#line 4705 "nasdaq.gperf"
      {"SSII", 4692},
      {""},
#line 4672 "nasdaq.gperf"
      {"SPRX", 4659},
      {""}, {""}, {""}, {""},
#line 4670 "nasdaq.gperf"
      {"SPRC", 4657},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3762 "nasdaq.gperf"
      {"PALO", 3749},
#line 3763 "nasdaq.gperf"
      {"PALOU", 3750},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4438 "nasdaq.gperf"
      {"SCZ", 4425},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5187 "nasdaq.gperf"
      {"VBCE", 5174},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 866 "nasdaq.gperf"
      {"BTSG", 853},
#line 867 "nasdaq.gperf"
      {"BTSGU", 854},
      {""}, {""}, {""},
#line 1755 "nasdaq.gperf"
      {"FCNCN", 1742},
      {""}, {""}, {""}, {""}, {""},
#line 2196 "nasdaq.gperf"
      {"GSM", 2183},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2637 "nasdaq.gperf"
      {"ISBA", 2624},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4211 "nasdaq.gperf"
      {"RDNT", 4198},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 29 "nasdaq.gperf"
      {"AAME", 16},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4053 "nasdaq.gperf"
      {"PXI", 4040},
      {""}, {""}, {""},
#line 4655 "nasdaq.gperf"
      {"SPCT", 4642},
      {""},
#line 4901 "nasdaq.gperf"
      {"TIL", 4888},
      {""}, {""}, {""},
#line 45 "nasdaq.gperf"
      {"ABEO", 32},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4902 "nasdaq.gperf"
      {"TILC", 4889},
      {""}, {""}, {""}, {""},
#line 849 "nasdaq.gperf"
      {"BSVO", 836},
      {""}, {""},
#line 4974 "nasdaq.gperf"
      {"TREO", 4961},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2463 "nasdaq.gperf"
      {"ICMB", 2450},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4346 "nasdaq.gperf"
      {"RTAC", 4333},
#line 4347 "nasdaq.gperf"
      {"RTACU", 4334},
#line 30 "nasdaq.gperf"
      {"AAOI", 17},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1881 "nasdaq.gperf"
      {"FNRN", 1868},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5194 "nasdaq.gperf"
      {"VBIO", 5181},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4820 "nasdaq.gperf"
      {"TAXE", 4807},
      {""}, {""},
#line 5446 "nasdaq.gperf"
      {"XBIO", 5433},
      {""},
#line 5396 "nasdaq.gperf"
      {"WNW", 5383},
      {""}, {""}, {""},
#line 467 "nasdaq.gperf"
      {"ATIIW", 454},
      {""}, {""}, {""},
#line 4301 "nasdaq.gperf"
      {"RMNI", 4288},
      {""}, {""}, {""}, {""}, {""},
#line 4027 "nasdaq.gperf"
      {"PTEN", 4014},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4390 "nasdaq.gperf"
      {"SAGT", 4377},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4809 "nasdaq.gperf"
      {"TAOX", 4796},
      {""}, {""}, {""}, {""}, {""},
#line 322 "nasdaq.gperf"
      {"ANAB", 309},
      {""},
#line 5245 "nasdaq.gperf"
      {"VIVO", 5232},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4810 "nasdaq.gperf"
      {"TAOZ", 4797},
      {""}, {""}, {""}, {""}, {""},
#line 3252 "nasdaq.gperf"
      {"MREO", 3239},
      {""}, {""}, {""},
#line 1255 "nasdaq.gperf"
      {"CROX", 1242},
      {""},
#line 336 "nasdaq.gperf"
      {"ANNAW", 323},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 83 "nasdaq.gperf"
      {"ACOG", 70},
      {""}, {""}, {""},
#line 1189 "nasdaq.gperf"
      {"COO", 1176},
      {""}, {""},
#line 2795 "nasdaq.gperf"
      {"KMB", 2782},
      {""}, {""},
#line 4236 "nasdaq.gperf"
      {"RENT", 4223},
      {""}, {""},
#line 4717 "nasdaq.gperf"
      {"STEX", 4704},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3232 "nasdaq.gperf"
      {"MOOD", 3219},
      {""},
#line 5198 "nasdaq.gperf"
      {"VCEL", 5185},
      {""}, {""}, {""}, {""},
#line 983 "nasdaq.gperf"
      {"CCOI", 970},
      {""}, {""},
#line 3234 "nasdaq.gperf"
      {"MOVE", 3221},
      {""}, {""}, {""}, {""},
#line 1892 "nasdaq.gperf"
      {"FOSL", 1879},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5275 "nasdaq.gperf"
      {"VOTE", 5262},
      {""}, {""}, {""}, {""}, {""},
#line 1038 "nasdaq.gperf"
      {"CGABL", 1025},
      {""}, {""},
#line 1257 "nasdaq.gperf"
      {"CRSR", 1244},
#line 4853 "nasdaq.gperf"
      {"TDOG", 4840},
      {""},
#line 2529 "nasdaq.gperf"
      {"IMRN", 2516},
#line 4351 "nasdaq.gperf"
      {"RTXG", 4338},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5473 "nasdaq.gperf"
      {"XLO", 5460},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 744 "nasdaq.gperf"
      {"BNR", 731},
      {""}, {""},
#line 4529 "nasdaq.gperf"
      {"SINT", 4516},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4477 "nasdaq.gperf"
      {"SFBC", 4464},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 599 "nasdaq.gperf"
      {"BDGS", 586},
#line 4673 "nasdaq.gperf"
      {"SPRY", 4660},
      {""}, {""},
#line 994 "nasdaq.gperf"
      {"CDIO", 981},
      {""},
#line 5451 "nasdaq.gperf"
      {"XCBE", 5438},
#line 5452 "nasdaq.gperf"
      {"XCBEU", 5439},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1933 "nasdaq.gperf"
      {"FSTR", 1920},
      {""}, {""},
#line 4721 "nasdaq.gperf"
      {"STI", 4708},
      {""}, {""},
#line 2726 "nasdaq.gperf"
      {"JSML", 2713},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 385 "nasdaq.gperf"
      {"ARBE", 372},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4015 "nasdaq.gperf"
      {"PSNL", 4002},
#line 950 "nasdaq.gperf"
      {"CBIO", 937},
      {""}, {""}, {""}, {""},
#line 5462 "nasdaq.gperf"
      {"XELLL", 5449},
      {""}, {""}, {""}, {""},
#line 1957 "nasdaq.gperf"
      {"FTLF", 1944},
      {""}, {""}, {""}, {""},
#line 3074 "nasdaq.gperf"
      {"MBIO", 3061},
      {""},
#line 111 "nasdaq.gperf"
      {"ADBE", 98},
      {""}, {""},
#line 1959 "nasdaq.gperf"
      {"FTQI", 1946},
      {""}, {""}, {""},
#line 5193 "nasdaq.gperf"
      {"VBIL", 5180},
#line 2187 "nasdaq.gperf"
      {"GSBC", 2174},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5445 "nasdaq.gperf"
      {"XBIL", 5432},
      {""}, {""},
#line 2996 "nasdaq.gperf"
      {"LRCX", 2983},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2204 "nasdaq.gperf"
      {"GT", 2191},
      {""},
#line 4240 "nasdaq.gperf"
      {"REVB", 4227},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2678 "nasdaq.gperf"
      {"JABRW", 2665},
#line 1104 "nasdaq.gperf"
      {"CISS", 1091},
      {""}, {""}, {""},
#line 2216 "nasdaq.gperf"
      {"GTM", 2203},
      {""}, {""}, {""},
#line 5391 "nasdaq.gperf"
      {"WLIIW", 5378},
#line 150 "nasdaq.gperf"
      {"AEYE", 137},
      {""},
#line 117 "nasdaq.gperf"
      {"ADIL", 104},
      {""}, {""}, {""}, {""}, {""},
#line 3981 "nasdaq.gperf"
      {"PRME", 3968},
      {""}, {""}, {""}, {""},
#line 1753 "nasdaq.gperf"
      {"FCLO", 1740},
      {""}, {""}, {""}, {""}, {""},
#line 5242 "nasdaq.gperf"
      {"VISN", 5229},
#line 2874 "nasdaq.gperf"
      {"LCCC", 2861},
#line 2876 "nasdaq.gperf"
      {"LCCCU", 2863},
#line 2221 "nasdaq.gperf"
      {"GTX", 2208},
      {""},
#line 555 "nasdaq.gperf"
      {"BANR", 542},
#line 625 "nasdaq.gperf"
      {"BETRW", 612},
#line 2875 "nasdaq.gperf"
      {"LCCCR", 2862},
      {""},
#line 2163 "nasdaq.gperf"
      {"GRAB", 2150},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1969 "nasdaq.gperf"
      {"FTXR", 1956},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4349 "nasdaq.gperf"
      {"RTB", 4336},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5528 "nasdaq.gperf"
      {"YIBO", 5515},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1121 "nasdaq.gperf"
      {"CLOD", 1108},
      {""}, {""}, {""}, {""},
#line 1120 "nasdaq.gperf"
      {"CLOA", 1107},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4828 "nasdaq.gperf"
      {"TBIL", 4815},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1832 "nasdaq.gperf"
      {"FISI", 1819},
      {""}, {""}, {""},
#line 3060 "nasdaq.gperf"
      {"MATE", 3047},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 626 "nasdaq.gperf"
      {"BFC", 613},
#line 526 "nasdaq.gperf"
      {"AXIN", 513},
#line 528 "nasdaq.gperf"
      {"AXINU", 515},
      {""}, {""}, {""}, {""},
#line 527 "nasdaq.gperf"
      {"AXINR", 514},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 734 "nasdaq.gperf"
      {"BNAIW", 721},
      {""}, {""}, {""},
#line 4727 "nasdaq.gperf"
      {"STLN", 4714},
      {""}, {""},
#line 661 "nasdaq.gperf"
      {"BIAFW", 648},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2886 "nasdaq.gperf"
      {"LE", 2873},
      {""}, {""}, {""}, {""}, {""},
#line 3274 "nasdaq.gperf"
      {"MSGY", 3261},
      {""},
#line 2791 "nasdaq.gperf"
      {"KLRS", 2778},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1803 "nasdaq.gperf"
      {"FFUT", 1790},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2700 "nasdaq.gperf"
      {"JF", 2687},
      {""}, {""}, {""}, {""},
#line 5375 "nasdaq.gperf"
      {"WINA", 5362},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2897 "nasdaq.gperf"
      {"LEXX", 2884},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2896 "nasdaq.gperf"
      {"LEXI", 2883},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 319 "nasdaq.gperf"
      {"AMZN", 306},
      {""}, {""},
#line 645 "nasdaq.gperf"
      {"BGRN", 632},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3829 "nasdaq.gperf"
      {"PECE", 3816},
#line 3831 "nasdaq.gperf"
      {"PECEU", 3818},
      {""}, {""}, {""}, {""},
#line 3830 "nasdaq.gperf"
      {"PECER", 3817},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5470 "nasdaq.gperf"
      {"XIIIU", 5457},
      {""},
#line 1158 "nasdaq.gperf"
      {"CNTB", 1145},
      {""},
#line 4294 "nasdaq.gperf"
      {"RLYB", 4281},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2771 "nasdaq.gperf"
      {"KEYYW", 2758},
      {""}, {""}, {""}, {""}, {""},
#line 3792 "nasdaq.gperf"
      {"PBOG", 3779},
#line 2703 "nasdaq.gperf"
      {"JFU", 2690},
      {""}, {""},
#line 4882 "nasdaq.gperf"
      {"TGL", 4869},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 157 "nasdaq.gperf"
      {"AFRIW", 144},
      {""}, {""}, {""}, {""}, {""},
#line 5243 "nasdaq.gperf"
      {"VITL", 5230},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2685 "nasdaq.gperf"
      {"JAZZ", 2672},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4352 "nasdaq.gperf"
      {"RTYY", 4339},
      {""}, {""},
#line 2821 "nasdaq.gperf"
      {"KRNY", 2808},
      {""}, {""}, {""}, {""}, {""},
#line 245 "nasdaq.gperf"
      {"ALIL", 232},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2976 "nasdaq.gperf"
      {"LOT", 2963},
      {""}, {""},
#line 264 "nasdaq.gperf"
      {"ALOY", 251},
      {""}, {""}, {""}, {""},
#line 2645 "nasdaq.gperf"
      {"ISRG", 2632},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2977 "nasdaq.gperf"
      {"LOTI", 2964},
      {""},
#line 3892 "nasdaq.gperf"
      {"PLCE", 3879},
      {""}, {""}, {""}, {""}, {""},
#line 5376 "nasdaq.gperf"
      {"WING", 5363},
#line 4827 "nasdaq.gperf"
      {"TBCVU", 4814},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 51 "nasdaq.gperf"
      {"ABOS", 38},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2110 "nasdaq.gperf"
      {"GLNDW", 2097},
#line 2864 "nasdaq.gperf"
      {"LATA", 2851},
#line 2865 "nasdaq.gperf"
      {"LATAU", 2852},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 901 "nasdaq.gperf"
      {"BZUN", 888},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2696 "nasdaq.gperf"
      {"JDZG", 2683},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2739 "nasdaq.gperf"
      {"JZXN", 2726},
      {""},
#line 4738 "nasdaq.gperf"
      {"STRO", 4725},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1267 "nasdaq.gperf"
      {"CRWV", 1254},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2850 "nasdaq.gperf"
      {"LAB", 2837},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3175 "nasdaq.gperf"
      {"MIST", 3162},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3488 "nasdaq.gperf"
      {"NRC", 3475},
      {""},
#line 2799 "nasdaq.gperf"
      {"KMTS", 2786},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3392 "nasdaq.gperf"
      {"NDAA", 3379},
      {""}, {""},
#line 4696 "nasdaq.gperf"
      {"SRZN", 4683},
#line 252 "nasdaq.gperf"
      {"ALLR", 239},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3478 "nasdaq.gperf"
      {"NOMA", 3465},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3360 "nasdaq.gperf"
      {"NB", 3347},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3378 "nasdaq.gperf"
      {"NCMI", 3365},
      {""},
#line 2485 "nasdaq.gperf"
      {"IESC", 2472},
      {""}, {""},
#line 3344 "nasdaq.gperf"
      {"NA", 3331},
      {""},
#line 3956 "nasdaq.gperf"
      {"PPCB", 3943},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4029 "nasdaq.gperf"
      {"PTGX", 4016},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5203 "nasdaq.gperf"
      {"VCRE", 5190},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3349 "nasdaq.gperf"
      {"NAMI", 3336},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1908 "nasdaq.gperf"
      {"FRME", 1895},
      {""},
#line 5556 "nasdaq.gperf"
      {"ZBRA", 5543},
      {""}, {""}, {""}, {""},
#line 4879 "nasdaq.gperf"
      {"TFNS", 4866},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 419 "nasdaq.gperf"
      {"ARTV", 406},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5249 "nasdaq.gperf"
      {"VLOS", 5236},
#line 5250 "nasdaq.gperf"
      {"VLOSU", 5237},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3358 "nasdaq.gperf"
      {"NAVI", 3345},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2701 "nasdaq.gperf"
      {"JFB", 2688},
      {""},
#line 2203 "nasdaq.gperf"
      {"GSUN", 2190},
      {""},
#line 84 "nasdaq.gperf"
      {"ACON", 71},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2524 "nasdaq.gperf"
      {"IMNN", 2511},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 898 "nasdaq.gperf"
      {"BZAIW", 885},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2656 "nasdaq.gperf"
      {"ITRI", 2643},
#line 1331 "nasdaq.gperf"
      {"CXIIW", 1318},
      {""},
#line 3878 "nasdaq.gperf"
      {"PIE", 3865},
      {""}, {""},
#line 31 "nasdaq.gperf"
      {"AAON", 18},
      {""}, {""}, {""}, {""},
#line 4986 "nasdaq.gperf"
      {"TRON", 4973},
      {""}, {""},
#line 2182 "nasdaq.gperf"
      {"GRSD", 2169},
      {""},
#line 2809 "nasdaq.gperf"
      {"KOYNW", 2796},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5508 "nasdaq.gperf"
      {"XTLB", 5495},
      {""}, {""}, {""},
#line 4737 "nasdaq.gperf"
      {"STRL", 4724},
      {""}, {""},
#line 2036 "nasdaq.gperf"
      {"GDS", 2023},
      {""}, {""}, {""}, {""},
#line 5415 "nasdaq.gperf"
      {"WSML", 5402},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1909 "nasdaq.gperf"
      {"FRMEP", 1896},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2186 "nasdaq.gperf"
      {"GSAT", 2173},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3170 "nasdaq.gperf"
      {"MILN", 3157},
      {""},
#line 5213 "nasdaq.gperf"
      {"VEON", 5200},
      {""}, {""}, {""}, {""},
#line 5574 "nasdaq.gperf"
      {"ZM", 5561},
      {""},
#line 3416 "nasdaq.gperf"
      {"NEWZ", 3403},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1254 "nasdaq.gperf"
      {"CRON", 1241},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1913 "nasdaq.gperf"
      {"FROG", 1900},
      {""}, {""}, {""},
#line 834 "nasdaq.gperf"
      {"BSMR", 821},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4373 "nasdaq.gperf"
      {"RXT", 4360},
      {""}, {""},
#line 810 "nasdaq.gperf"
      {"BSCR", 797},
      {""},
#line 2714 "nasdaq.gperf"
      {"JMSB", 2701},
#line 2232 "nasdaq.gperf"
      {"GXAI", 2219},
      {""}, {""}, {""},
#line 1815 "nasdaq.gperf"
      {"FGSI", 1802},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1732 "nasdaq.gperf"
      {"FBIO", 1719},
      {""}, {""}, {""}, {""},
#line 2993 "nasdaq.gperf"
      {"LQ", 2980},
      {""}, {""}, {""}, {""},
#line 213 "nasdaq.gperf"
      {"AIRO", 200},
      {""}, {""}, {""},
#line 524 "nasdaq.gperf"
      {"AXG", 511},
      {""}, {""}, {""},
#line 1883 "nasdaq.gperf"
      {"FNWB", 1870},
      {""},
#line 3879 "nasdaq.gperf"
      {"PIII", 3866},
      {""},
#line 934 "nasdaq.gperf"
      {"CARE", 921},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3764 "nasdaq.gperf"
      {"PALOW", 3751},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5411 "nasdaq.gperf"
      {"WSE", 5398},
#line 861 "nasdaq.gperf"
      {"BTLN", 848},
      {""}, {""},
#line 3390 "nasdaq.gperf"
      {"NCT", 3377},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 334 "nasdaq.gperf"
      {"ANL", 321},
      {""}, {""}, {""}, {""}, {""},
#line 3399 "nasdaq.gperf"
      {"NEMG", 3386},
      {""}, {""}, {""},
#line 4854 "nasdaq.gperf"
      {"TDOT", 4841},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 208 "nasdaq.gperf"
      {"AIQ", 195},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3372 "nasdaq.gperf"
      {"NBTX", 3359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5235 "nasdaq.gperf"
      {"VICR", 5222},
      {""}, {""},
#line 5068 "nasdaq.gperf"
      {"TXG", 5055},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 302 "nasdaq.gperf"
      {"AMOD", 289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5442 "nasdaq.gperf"
      {"XAIR", 5429},
#line 1750 "nasdaq.gperf"
      {"FCEL", 1737},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3967 "nasdaq.gperf"
      {"PQOC", 3954},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1758 "nasdaq.gperf"
      {"FCTE", 1745},
      {""}, {""}, {""}, {""}, {""},
#line 623 "nasdaq.gperf"
      {"BESO", 610},
      {""}, {""},
#line 825 "nasdaq.gperf"
      {"BSJR", 812},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1733 "nasdaq.gperf"
      {"FBIOP", 1720},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5307 "nasdaq.gperf"
      {"VTGN", 5294},
      {""}, {""}, {""}, {""}, {""},
#line 1191 "nasdaq.gperf"
      {"COOT", 1178},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1728 "nasdaq.gperf"
      {"FATE", 1715},
      {""}, {""}, {""},
#line 1157 "nasdaq.gperf"
      {"CNSY", 1144},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 166 "nasdaq.gperf"
      {"AGIX", 153},
      {""}, {""}, {""}, {""}, {""},
#line 4348 "nasdaq.gperf"
      {"RTACW", 4335},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2968 "nasdaq.gperf"
      {"LOAN", 2955},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3077 "nasdaq.gperf"
      {"MBOT", 3064},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2417 "nasdaq.gperf"
      {"IACO", 2404},
#line 2418 "nasdaq.gperf"
      {"IACOU", 2405},
      {""},
#line 1152 "nasdaq.gperf"
      {"CNL", 1139},
      {""}, {""}, {""}, {""}, {""},
#line 2116 "nasdaq.gperf"
      {"GLSI", 2103},
      {""}, {""}, {""},
#line 2884 "nasdaq.gperf"
      {"LDRX", 2871},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2220 "nasdaq.gperf"
      {"GTR", 2207},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1948 "nasdaq.gperf"
      {"FTG", 1935},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2870 "nasdaq.gperf"
      {"LBRX", 2857},
      {""}, {""}, {""},
#line 1949 "nasdaq.gperf"
      {"FTGC", 1936},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2820 "nasdaq.gperf"
      {"KRNT", 2807},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4690 "nasdaq.gperf"
      {"SRCE", 4677},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1833 "nasdaq.gperf"
      {"FISN", 1820},
      {""}, {""}, {""},
#line 4523 "nasdaq.gperf"
      {"SILC", 4510},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 355 "nasdaq.gperf"
      {"APLD", 342},
      {""}, {""}, {""}, {""},
#line 1859 "nasdaq.gperf"
      {"FLYE", 1846},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 865 "nasdaq.gperf"
      {"BTQ", 852},
      {""}, {""}, {""},
#line 823 "nasdaq.gperf"
      {"BSIN", 810},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 767 "nasdaq.gperf"
      {"BPRN", 754},
      {""}, {""}, {""}, {""},
#line 3962 "nasdaq.gperf"
      {"PPSI", 3949},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2027 "nasdaq.gperf"
      {"GCL", 2014},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2672 "nasdaq.gperf"
      {"IXUS", 2659},
      {""}, {""}, {""}, {""},
#line 820 "nasdaq.gperf"
      {"BSET", 807},
      {""}, {""}, {""}, {""},
#line 2136 "nasdaq.gperf"
      {"GOLI", 2123},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 630 "nasdaq.gperf"
      {"BFRI", 617},
#line 2831 "nasdaq.gperf"
      {"KTCC", 2818},
      {""},
#line 3408 "nasdaq.gperf"
      {"NETG", 3395},
      {""}, {""}, {""}, {""},
#line 2021 "nasdaq.gperf"
      {"GBLI", 2008},
      {""}, {""}, {""},
#line 1051 "nasdaq.gperf"
      {"CGTL", 1038},
#line 587 "nasdaq.gperf"
      {"BCLO", 574},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 995 "nasdaq.gperf"
      {"CDIOW", 982},
      {""},
#line 5453 "nasdaq.gperf"
      {"XCBEW", 5440},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1811 "nasdaq.gperf"
      {"FGL", 1798},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2882 "nasdaq.gperf"
      {"LCUT", 2869},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3345 "nasdaq.gperf"
      {"NAAS", 3332},
#line 386 "nasdaq.gperf"
      {"ARBEW", 373},
      {""},
#line 3352 "nasdaq.gperf"
      {"NAMS", 3339},
      {""},
#line 3391 "nasdaq.gperf"
      {"NCTY", 3378},
      {""}, {""}, {""}, {""}, {""},
#line 2746 "nasdaq.gperf"
      {"KBAB", 2733},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5036 "nasdaq.gperf"
      {"TTGT", 5023},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5393 "nasdaq.gperf"
      {"WMG", 5380},
      {""}, {""},
#line 89 "nasdaq.gperf"
      {"ACRV", 76},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4241 "nasdaq.gperf"
      {"REVBW", 4228},
      {""},
#line 2752 "nasdaq.gperf"
      {"KBWB", 2739},
      {""}, {""}, {""},
#line 676 "nasdaq.gperf"
      {"BIS", 663},
      {""}, {""},
#line 5225 "nasdaq.gperf"
      {"VGLT", 5212},
      {""},
#line 4483 "nasdaq.gperf"
      {"SFNC", 4470},
#line 4528 "nasdaq.gperf"
      {"SIMO", 4515},
      {""},
#line 5271 "nasdaq.gperf"
      {"VONE", 5258},
      {""}, {""}, {""}, {""}, {""},
#line 5350 "nasdaq.gperf"
      {"WDGF", 5337},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1926 "nasdaq.gperf"
      {"FSGS", 1913},
      {""}, {""}, {""},
#line 2121 "nasdaq.gperf"
      {"GMAB", 2108},
      {""}, {""}, {""},
#line 2452 "nasdaq.gperf"
      {"IBTO", 2439},
      {""},
#line 2164 "nasdaq.gperf"
      {"GRABW", 2151},
      {""}, {""}, {""},
#line 628 "nasdaq.gperf"
      {"BFRG", 615},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1759 "nasdaq.gperf"
      {"FCUV", 1746},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3984 "nasdaq.gperf"
      {"PROF", 3971},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 371 "nasdaq.gperf"
      {"APVO", 358},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1114 "nasdaq.gperf"
      {"CLIR", 1101},
      {""}, {""}, {""}, {""}, {""},
#line 2431 "nasdaq.gperf"
      {"IBEX", 2418},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5004 "nasdaq.gperf"
      {"TRUU", 4991},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2144 "nasdaq.gperf"
      {"GOSS", 2131},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4234 "nasdaq.gperf"
      {"RELY", 4221},
#line 1249 "nasdaq.gperf"
      {"CRMU", 1236},
      {""}, {""}, {""},
#line 4325 "nasdaq.gperf"
      {"ROE", 4312},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2016 "nasdaq.gperf"
      {"GASS", 2003},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4371 "nasdaq.gperf"
      {"RXRX", 4358},
      {""}, {""}, {""}, {""},
#line 4728 "nasdaq.gperf"
      {"STLNW", 4715},
      {""}, {""}, {""},
#line 890 "nasdaq.gperf"
      {"BXBL", 877},
      {""}, {""}, {""}, {""}, {""},
#line 2632 "nasdaq.gperf"
      {"IRIX", 2619},
      {""}, {""}, {""}, {""},
#line 4221 "nasdaq.gperf"
      {"REAL", 4208},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2627 "nasdaq.gperf"
      {"IREG", 2614},
      {""},
#line 5560 "nasdaq.gperf"
      {"ZENA", 5547},
      {""}, {""}, {""}, {""},
#line 3395 "nasdaq.gperf"
      {"NDRA", 3382},
#line 3262 "nasdaq.gperf"
      {"MRVU", 3249},
      {""}, {""}, {""},
#line 5463 "nasdaq.gperf"
      {"XENE", 5450},
      {""}, {""}, {""},
#line 1093 "nasdaq.gperf"
      {"CIBR", 1080},
      {""},
#line 2833 "nasdaq.gperf"
      {"KTTA", 2820},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3388 "nasdaq.gperf"
      {"NCRA", 3375},
      {""}, {""}, {""},
#line 4331 "nasdaq.gperf"
      {"ROST", 4318},
      {""}, {""}, {""}, {""},
#line 1241 "nasdaq.gperf"
      {"CRGO", 1228},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1217 "nasdaq.gperf"
      {"CPSS", 1204},
      {""},
#line 980 "nasdaq.gperf"
      {"CCNE", 967},
      {""}, {""}, {""}, {""}, {""},
#line 3832 "nasdaq.gperf"
      {"PECEW", 3819},
#line 4209 "nasdaq.gperf"
      {"RDI", 4196},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4239 "nasdaq.gperf"
      {"RETO", 4226},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4653 "nasdaq.gperf"
      {"SPCB", 4640},
      {""}, {""},
#line 3359 "nasdaq.gperf"
      {"NAVN", 3346},
      {""}, {""},
#line 3080 "nasdaq.gperf"
      {"MBUU", 3067},
      {""}, {""},
#line 1936 "nasdaq.gperf"
      {"FSZ", 1923},
      {""}, {""}, {""}, {""},
#line 4739 "nasdaq.gperf"
      {"STRR", 4726},
      {""}, {""},
#line 2166 "nasdaq.gperf"
      {"GRAL", 2153},
      {""}, {""},
#line 2175 "nasdaq.gperf"
      {"GRML", 2162},
      {""},
#line 4395 "nasdaq.gperf"
      {"SAIL", 4382},
      {""}, {""}, {""},
#line 2450 "nasdaq.gperf"
      {"IBTL", 2437},
      {""}, {""}, {""},
#line 2851 "nasdaq.gperf"
      {"LABT", 2838},
      {""},
#line 5220 "nasdaq.gperf"
      {"VFS", 5207},
      {""},
#line 258 "nasdaq.gperf"
      {"ALMU", 245},
      {""},
#line 333 "nasdaq.gperf"
      {"ANIX", 320},
      {""}, {""}, {""},
#line 3961 "nasdaq.gperf"
      {"PPLI", 3948},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2059 "nasdaq.gperf"
      {"GEVO", 2046},
      {""}, {""}, {""},
#line 4213 "nasdaq.gperf"
      {"RDTL", 4200},
      {""}, {""},
#line 2657 "nasdaq.gperf"
      {"ITRN", 2644},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 93 "nasdaq.gperf"
      {"ACTU", 80},
      {""},
#line 1098 "nasdaq.gperf"
      {"CIIT", 1085},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2956 "nasdaq.gperf"
      {"LMB", 2943},
      {""}, {""}, {""},
#line 71 "nasdaq.gperf"
      {"ACGL", 58},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2866 "nasdaq.gperf"
      {"LATAW", 2853},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 159 "nasdaq.gperf"
      {"AFSC", 146},
      {""},
#line 1228 "nasdaq.gperf"
      {"CRAQ", 1215},
#line 1230 "nasdaq.gperf"
      {"CRAQU", 1217},
      {""}, {""}, {""}, {""},
#line 1229 "nasdaq.gperf"
      {"CRAQR", 1216},
      {""},
#line 3418 "nasdaq.gperf"
      {"NEXN", 3405},
      {""}, {""}, {""}, {""},
#line 3368 "nasdaq.gperf"
      {"NBRG", 3355},
#line 3370 "nasdaq.gperf"
      {"NBRGU", 3357},
      {""},
#line 2483 "nasdaq.gperf"
      {"IEI", 2470},
      {""}, {""},
#line 3369 "nasdaq.gperf"
      {"NBRGR", 3356},
      {""},
#line 981 "nasdaq.gperf"
      {"CCNEP", 968},
      {""},
#line 3479 "nasdaq.gperf"
      {"NOVT", 3466},
#line 3480 "nasdaq.gperf"
      {"NOVTU", 3467},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3216 "nasdaq.gperf"
      {"MNST", 3203},
#line 959 "nasdaq.gperf"
      {"CCAQ", 946},
#line 960 "nasdaq.gperf"
      {"CCAQU", 947},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4740 "nasdaq.gperf"
      {"STRRP", 4727},
      {""}, {""}, {""}, {""},
#line 3457 "nasdaq.gperf"
      {"NMAD", 3444},
#line 1300 "nasdaq.gperf"
      {"CTSO", 1287},
      {""},
#line 352 "nasdaq.gperf"
      {"APEI", 339},
      {""},
#line 2461 "nasdaq.gperf"
      {"ICLN", 2448},
      {""}, {""}, {""}, {""},
#line 130 "nasdaq.gperf"
      {"AEAQ", 117},
#line 131 "nasdaq.gperf"
      {"AEAQU", 118},
      {""}, {""}, {""},
#line 3357 "nasdaq.gperf"
      {"NAUT", 3344},
      {""}, {""}, {""}, {""},
#line 5277 "nasdaq.gperf"
      {"VPLS", 5264},
      {""}, {""}, {""}, {""},
#line 3001 "nasdaq.gperf"
      {"LRND", 2988},
      {""}, {""}, {""},
#line 1950 "nasdaq.gperf"
      {"FTGS", 1937},
      {""}, {""}, {""},
#line 669 "nasdaq.gperf"
      {"BILI", 656},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5211 "nasdaq.gperf"
      {"VEFA", 5198},
      {""}, {""}, {""}, {""},
#line 5498 "nasdaq.gperf"
      {"XSLL", 5485},
#line 5499 "nasdaq.gperf"
      {"XSLLU", 5486},
#line 4303 "nasdaq.gperf"
      {"RMSG", 4290},
      {""}, {""}, {""}, {""}, {""},
#line 802 "nasdaq.gperf"
      {"BRVE", 789},
#line 525 "nasdaq.gperf"
      {"AXGN", 512},
      {""}, {""},
#line 843 "nasdaq.gperf"
      {"BSRR", 830},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2973 "nasdaq.gperf"
      {"LONA", 2960},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5575 "nasdaq.gperf"
      {"ZMUN", 5562},
#line 163 "nasdaq.gperf"
      {"AGEN", 150},
#line 1739 "nasdaq.gperf"
      {"FBOT", 1726},
      {""}, {""}, {""}, {""}, {""},
#line 5484 "nasdaq.gperf"
      {"XPEG", 5471},
      {""},
#line 3110 "nasdaq.gperf"
      {"MDGL", 3097},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1232 "nasdaq.gperf"
      {"CRBU", 1219},
      {""}, {""}, {""},
#line 2858 "nasdaq.gperf"
      {"LAND", 2845},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1118 "nasdaq.gperf"
      {"CLNE", 1105},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1880 "nasdaq.gperf"
      {"FNLC", 1867},
      {""}, {""},
#line 354 "nasdaq.gperf"
      {"API", 341},
#line 3421 "nasdaq.gperf"
      {"NEXT", 3408},
#line 2872 "nasdaq.gperf"
      {"LBTYB", 2859},
#line 2172 "nasdaq.gperf"
      {"GRI", 2159},
#line 2173 "nasdaq.gperf"
      {"GRID", 2160},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5251 "nasdaq.gperf"
      {"VLOSW", 5238},
      {""}, {""},
#line 3196 "nasdaq.gperf"
      {"MLGO", 3183},
      {""}, {""}, {""},
#line 2197 "nasdaq.gperf"
      {"GSRF", 2184},
#line 2199 "nasdaq.gperf"
      {"GSRFU", 2186},
#line 3410 "nasdaq.gperf"
      {"NEWT", 3397},
      {""}, {""}, {""},
#line 2198 "nasdaq.gperf"
      {"GSRFR", 2185},
#line 2695 "nasdaq.gperf"
      {"JDOC", 2682},
      {""}, {""}, {""},
#line 2751 "nasdaq.gperf"
      {"KBSX", 2738},
      {""}, {""}, {""},
#line 4966 "nasdaq.gperf"
      {"TPST", 4953},
#line 5236 "nasdaq.gperf"
      {"VIGI", 5223},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3990 "nasdaq.gperf"
      {"PRQR", 3977},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4965 "nasdaq.gperf"
      {"TPLS", 4952},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 85 "nasdaq.gperf"
      {"ACONW", 72},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5018 "nasdaq.gperf"
      {"TSLL", 5005},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4559 "nasdaq.gperf"
      {"SLGB", 4546},
      {""}, {""},
#line 2094 "nasdaq.gperf"
      {"GIX", 2081},
      {""}, {""}, {""}, {""}, {""},
#line 2007 "nasdaq.gperf"
      {"GAIA", 1994},
      {""}, {""}, {""}, {""}, {""},
#line 2096 "nasdaq.gperf"
      {"GIXXU", 2083},
      {""}, {""},
#line 2423 "nasdaq.gperf"
      {"IALT", 2410},
      {""},
#line 2095 "nasdaq.gperf"
      {"GIXXR", 2082},
      {""},
#line 237 "nasdaq.gperf"
      {"ALF", 224},
#line 2091 "nasdaq.gperf"
      {"GIW", 2078},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 214 "nasdaq.gperf"
      {"AIRR", 201},
      {""}, {""}, {""},
#line 567 "nasdaq.gperf"
      {"BBIO", 554},
      {""}, {""}, {""},
#line 1806 "nasdaq.gperf"
      {"FGI", 1793},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5273 "nasdaq.gperf"
      {"VONV", 5260},
      {""}, {""}, {""}, {""},
#line 1045 "nasdaq.gperf"
      {"CGEN", 1032},
      {""}, {""}, {""},
#line 1807 "nasdaq.gperf"
      {"FGII", 1794},
#line 1808 "nasdaq.gperf"
      {"FGIIU", 1795},
#line 5363 "nasdaq.gperf"
      {"WFRD", 5350},
#line 2860 "nasdaq.gperf"
      {"LANDP", 2847},
      {""}, {""}, {""},
#line 2893 "nasdaq.gperf"
      {"LEND", 2880},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3165 "nasdaq.gperf"
      {"MGYR", 3152},
#line 1213 "nasdaq.gperf"
      {"CPLS", 1200},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2894 "nasdaq.gperf"
      {"LENZ", 2881},
#line 3140 "nasdaq.gperf"
      {"METU", 3127},
      {""}, {""}, {""},
#line 910 "nasdaq.gperf"
      {"CAFG", 897},
      {""},
#line 1011 "nasdaq.gperf"
      {"CEFA", 998},
      {""}, {""}, {""},
#line 1146 "nasdaq.gperf"
      {"CMTV", 1133},
      {""}, {""}, {""}, {""},
#line 4912 "nasdaq.gperf"
      {"TLF", 4899},
      {""},
#line 472 "nasdaq.gperf"
      {"ATLO", 459},
      {""}, {""}, {""}, {""},
#line 3122 "nasdaq.gperf"
      {"MEGL", 3109},
#line 1151 "nasdaq.gperf"
      {"CNEY", 1138},
      {""},
#line 3415 "nasdaq.gperf"
      {"NEWTP", 3402},
      {""},
#line 2688 "nasdaq.gperf"
      {"JBIO", 2675},
      {""},
#line 1212 "nasdaq.gperf"
      {"CPIX", 1199},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5224 "nasdaq.gperf"
      {"VGIT", 5211},
      {""},
#line 3238 "nasdaq.gperf"
      {"MPIA", 3225},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5580 "nasdaq.gperf"
      {"ZS", 5567},
      {""}, {""}, {""},
#line 535 "nasdaq.gperf"
      {"AZI", 522},
#line 2051 "nasdaq.gperf"
      {"GENB", 2038},
      {""},
#line 2104 "nasdaq.gperf"
      {"GLE", 2091},
      {""}, {""},
#line 2046 "nasdaq.gperf"
      {"GELS", 2033},
      {""}, {""},
#line 5267 "nasdaq.gperf"
      {"VNQI", 5254},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5300 "nasdaq.gperf"
      {"VSME", 5287},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1218 "nasdaq.gperf"
      {"CPTL", 1205},
      {""}, {""},
#line 3975 "nasdaq.gperf"
      {"PRFX", 3962},
      {""}, {""},
#line 3466 "nasdaq.gperf"
      {"NMTC", 3453},
      {""}, {""}, {""},
#line 3880 "nasdaq.gperf"
      {"PIIIW", 3867},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3976 "nasdaq.gperf"
      {"PRFZ", 3963},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1111 "nasdaq.gperf"
      {"CLFD", 1098},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5400 "nasdaq.gperf"
      {"WPRT", 5387},
      {""}, {""}, {""},
#line 1096 "nasdaq.gperf"
      {"CIGI", 1083},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3413 "nasdaq.gperf"
      {"NEWTI", 3400},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3855 "nasdaq.gperf"
      {"PFSA", 3842},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5477 "nasdaq.gperf"
      {"XNCR", 5464},
#line 4489 "nasdaq.gperf"
      {"SGLY", 4476},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2492 "nasdaq.gperf"
      {"IGAC", 2479},
#line 2494 "nasdaq.gperf"
      {"IGACU", 2481},
      {""}, {""}, {""}, {""},
#line 2493 "nasdaq.gperf"
      {"IGACR", 2480},
      {""}, {""},
#line 303 "nasdaq.gperf"
      {"AMODW", 290},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4674 "nasdaq.gperf"
      {"SPSC", 4661},
      {""}, {""}, {""}, {""}, {""},
#line 436 "nasdaq.gperf"
      {"ASO", 423},
      {""},
#line 3752 "nasdaq.gperf"
      {"PABU", 3739},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4490 "nasdaq.gperf"
      {"SGML", 4477},
      {""}, {""}, {""},
#line 4217 "nasdaq.gperf"
      {"RDWR", 4204},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 860 "nasdaq.gperf"
      {"BTGD", 847},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4253 "nasdaq.gperf"
      {"RGC", 4240},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3213 "nasdaq.gperf"
      {"MNRO", 3200},
      {""}, {""},
#line 1192 "nasdaq.gperf"
      {"COOTW", 1179},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2624 "nasdaq.gperf"
      {"IQST", 2611},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5361 "nasdaq.gperf"
      {"WFCF", 5348},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3862 "nasdaq.gperf"
      {"PGEN", 3849},
      {""}, {""}, {""},
#line 4298 "nasdaq.gperf"
      {"RMCO", 4285},
      {""},
#line 3379 "nasdaq.gperf"
      {"NCNA", 3366},
      {""}, {""}, {""}, {""},
#line 2959 "nasdaq.gperf"
      {"LMRI", 2946},
      {""}, {""}, {""}, {""},
#line 4447 "nasdaq.gperf"
      {"SDOT", 4434},
      {""}, {""},
#line 2419 "nasdaq.gperf"
      {"IACOW", 2406},
      {""}, {""}, {""}, {""}, {""},
#line 3366 "nasdaq.gperf"
      {"NBN", 3353},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3150 "nasdaq.gperf"
      {"MFLX", 3137},
      {""}, {""},
#line 2628 "nasdaq.gperf"
      {"IREN", 2615},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3959 "nasdaq.gperf"
      {"PPI", 3946},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2012 "nasdaq.gperf"
      {"GALT", 1999},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2740 "nasdaq.gperf"
      {"KALA", 2727},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2957 "nasdaq.gperf"
      {"LMBS", 2944},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 640 "nasdaq.gperf"
      {"BGL", 627},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 714 "nasdaq.gperf"
      {"BLTE", 701},
      {""}, {""}, {""}, {""},
#line 2955 "nasdaq.gperf"
      {"LMAT", 2942},
#line 3910 "nasdaq.gperf"
      {"PLTU", 3897},
      {""},
#line 641 "nasdaq.gperf"
      {"BGLC", 628},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5216 "nasdaq.gperf"
      {"VERU", 5203},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3239 "nasdaq.gperf"
      {"MPLT", 3226},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2592 "nasdaq.gperf"
      {"IOTR", 2579},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 631 "nasdaq.gperf"
      {"BFRIW", 618},
      {""}, {""}, {""},
#line 5489 "nasdaq.gperf"
      {"XRPC", 5476},
      {""}, {""}, {""}, {""},
#line 5490 "nasdaq.gperf"
      {"XRPI", 5477},
      {""}, {""},
#line 2455 "nasdaq.gperf"
      {"IBTR", 2442},
      {""},
#line 447 "nasdaq.gperf"
      {"ASTE", 434},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4033 "nasdaq.gperf"
      {"PTLO", 4020},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4458 "nasdaq.gperf"
      {"SEER", 4445},
#line 3151 "nasdaq.gperf"
      {"MFMO", 3138},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5448 "nasdaq.gperf"
      {"XBP", 5435},
      {""}, {""}, {""}, {""},
#line 5262 "nasdaq.gperf"
      {"VNET", 5249},
#line 5012 "nasdaq.gperf"
      {"TSEL", 4999},
      {""}, {""}, {""},
#line 3353 "nasdaq.gperf"
      {"NAMSW", 3340},
#line 1173 "nasdaq.gperf"
      {"COFS", 1160},
      {""}, {""}, {""},
#line 5479 "nasdaq.gperf"
      {"XNET", 5466},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 369 "nasdaq.gperf"
      {"APUR", 356},
      {""}, {""},
#line 119 "nasdaq.gperf"
      {"ADP", 106},
      {""}, {""},
#line 370 "nasdaq.gperf"
      {"APURR", 357},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 557 "nasdaq.gperf"
      {"BAOS", 544},
#line 4285 "nasdaq.gperf"
      {"RJET", 4272},
      {""}, {""}, {""}, {""}, {""},
#line 2806 "nasdaq.gperf"
      {"KOSS", 2793},
      {""}, {""}, {""}, {""}, {""},
#line 4263 "nasdaq.gperf"
      {"RGTX", 4250},
      {""},
#line 4669 "nasdaq.gperf"
      {"SPRB", 4656},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2646 "nasdaq.gperf"
      {"ISTB", 2633},
#line 4261 "nasdaq.gperf"
      {"RGTI", 4248},
      {""}, {""},
#line 4170 "nasdaq.gperf"
      {"RAIN", 4157},
      {""},
#line 4264 "nasdaq.gperf"
      {"RGTZ", 4251},
      {""},
#line 3004 "nasdaq.gperf"
      {"LSCC", 2991},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 164 "nasdaq.gperf"
      {"AGGA", 151},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 33 "nasdaq.gperf"
      {"AAPD", 20},
      {""}, {""}, {""}, {""}, {""},
#line 3933 "nasdaq.gperf"
      {"PNQI", 3920},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 316 "nasdaq.gperf"
      {"AMUU", 303},
      {""}, {""},
#line 629 "nasdaq.gperf"
      {"BFRGW", 616},
      {""},
#line 4284 "nasdaq.gperf"
      {"RIVN", 4271},
      {""}, {""}, {""},
#line 4000 "nasdaq.gperf"
      {"PSCE", 3987},
      {""},
#line 2056 "nasdaq.gperf"
      {"GEQ", 2043},
#line 5398 "nasdaq.gperf"
      {"WOOD", 5385},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 67 "nasdaq.gperf"
      {"ACFN", 54},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2474 "nasdaq.gperf"
      {"IDEF", 2461},
      {""},
#line 4957 "nasdaq.gperf"
      {"TOP", 4944},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1282 "nasdaq.gperf"
      {"CSTE", 1269},
      {""}, {""}, {""}, {""},
#line 4842 "nasdaq.gperf"
      {"TCPC", 4829},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5337 "nasdaq.gperf"
      {"WAVE", 5324},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2440 "nasdaq.gperf"
      {"IBIT", 2427},
#line 1731 "nasdaq.gperf"
      {"FBGL", 1718},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3240 "nasdaq.gperf"
      {"MPWR", 3227},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5301 "nasdaq.gperf"
      {"VSMV", 5288},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5365 "nasdaq.gperf"
      {"WGS", 5352},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 142 "nasdaq.gperf"
      {"AEP", 129},
#line 3464 "nasdaq.gperf"
      {"NMRA", 3451},
      {""}, {""},
#line 34 "nasdaq.gperf"
      {"AAPG", 21},
      {""}, {""}, {""}, {""}, {""},
#line 1150 "nasdaq.gperf"
      {"CNET", 1137},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2562 "nasdaq.gperf"
      {"INM", 2549},
#line 2564 "nasdaq.gperf"
      {"INMD", 2551},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2539 "nasdaq.gperf"
      {"INAC", 2526},
#line 2541 "nasdaq.gperf"
      {"INACU", 2528},
      {""}, {""}, {""},
#line 3996 "nasdaq.gperf"
      {"PRZO", 3983},
#line 2540 "nasdaq.gperf"
      {"INACR", 2527},
#line 2834 "nasdaq.gperf"
      {"KTTAW", 2821},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1242 "nasdaq.gperf"
      {"CRGOW", 1229},
      {""}, {""}, {""},
#line 5020 "nasdaq.gperf"
      {"TSLR", 5007},
      {""}, {""},
#line 3821 "nasdaq.gperf"
      {"PDFS", 3808},
      {""}, {""}, {""}, {""}, {""},
#line 4300 "nasdaq.gperf"
      {"RMIX", 4287},
#line 2101 "nasdaq.gperf"
      {"GLCR", 2088},
#line 4603 "nasdaq.gperf"
      {"SNAL", 4590},
      {""}, {""}, {""},
#line 3153 "nasdaq.gperf"
      {"MFVL", 3140},
      {""}, {""},
#line 3073 "nasdaq.gperf"
      {"MBINN", 3060},
#line 1193 "nasdaq.gperf"
      {"COPJ", 1180},
      {""},
#line 1962 "nasdaq.gperf"
      {"FTSL", 1949},
      {""}, {""}, {""}, {""},
#line 1253 "nasdaq.gperf"
      {"CROB", 1240},
#line 2622 "nasdaq.gperf"
      {"IQQ", 2609},
      {""}, {""},
#line 2581 "nasdaq.gperf"
      {"INV", 2568},
#line 4306 "nasdaq.gperf"
      {"RNA", 4293},
#line 2174 "nasdaq.gperf"
      {"GRIN", 2161},
      {""}, {""}, {""},
#line 2582 "nasdaq.gperf"
      {"INVA", 2569},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4307 "nasdaq.gperf"
      {"RNAC", 4294},
#line 3786 "nasdaq.gperf"
      {"PBFS", 3773},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2584 "nasdaq.gperf"
      {"INVZ", 2571},
#line 4309 "nasdaq.gperf"
      {"RNAZ", 4296},
      {""},
#line 4265 "nasdaq.gperf"
      {"RGYY", 4252},
#line 265 "nasdaq.gperf"
      {"ALP", 252},
      {""}, {""}, {""}, {""}, {""},
#line 5573 "nasdaq.gperf"
      {"ZLAB", 5560},
#line 2176 "nasdaq.gperf"
      {"GRMLW", 2163},
      {""}, {""}, {""},
#line 267 "nasdaq.gperf"
      {"ALPX", 254},
#line 269 "nasdaq.gperf"
      {"ALPXU", 256},
      {""}, {""}, {""}, {""},
#line 268 "nasdaq.gperf"
      {"ALPXR", 255},
      {""}, {""}, {""},
#line 4317 "nasdaq.gperf"
      {"RNW", 4304},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3006 "nasdaq.gperf"
      {"LSTA", 2993},
      {""}, {""},
#line 4231 "nasdaq.gperf"
      {"REIT", 4218},
      {""}, {""},
#line 2008 "nasdaq.gperf"
      {"GAIN", 1995},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2271 "nasdaq.gperf"
      {"HCM", 2258},
      {""},
#line 822 "nasdaq.gperf"
      {"BSGT", 809},
      {""}, {""}, {""},
#line 2272 "nasdaq.gperf"
      {"HCMA", 2259},
#line 2273 "nasdaq.gperf"
      {"HCMAU", 2260},
      {""}, {""},
#line 2011 "nasdaq.gperf"
      {"GAINZ", 1998},
      {""}, {""},
#line 2261 "nasdaq.gperf"
      {"HCAC", 2248},
#line 2263 "nasdaq.gperf"
      {"HCACU", 2250},
      {""}, {""}, {""},
#line 2264 "nasdaq.gperf"
      {"HCAI", 2251},
#line 2262 "nasdaq.gperf"
      {"HCACR", 2249},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1022 "nasdaq.gperf"
      {"CEPI", 1009},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2506 "nasdaq.gperf"
      {"ILIT", 2493},
      {""},
#line 1824 "nasdaq.gperf"
      {"FIGX", 1811},
#line 1825 "nasdaq.gperf"
      {"FIGXU", 1812},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2090 "nasdaq.gperf"
      {"GITS", 2077},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4609 "nasdaq.gperf"
      {"SNEX", 4596},
      {""}, {""},
#line 3091 "nasdaq.gperf"
      {"MCFT", 3078},
      {""}, {""},
#line 571 "nasdaq.gperf"
      {"BBOT", 558},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4471 "nasdaq.gperf"
      {"SERV", 4458},
      {""}, {""}, {""}, {""}, {""},
#line 544 "nasdaq.gperf"
      {"BAER", 531},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 961 "nasdaq.gperf"
      {"CCAQW", 948},
      {""}, {""},
#line 2586 "nasdaq.gperf"
      {"IONL", 2573},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2122 "nasdaq.gperf"
      {"GMEX", 2109},
      {""}, {""},
#line 3823 "nasdaq.gperf"
      {"PDP", 3810},
#line 2246 "nasdaq.gperf"
      {"HAVA", 2233},
#line 2248 "nasdaq.gperf"
      {"HAVAU", 2235},
      {""}, {""}, {""}, {""},
#line 2247 "nasdaq.gperf"
      {"HAVAR", 2234},
      {""}, {""}, {""},
#line 3009 "nasdaq.gperf"
      {"LTCC", 2996},
      {""}, {""},
#line 5425 "nasdaq.gperf"
      {"WTG", 5412},
      {""}, {""},
#line 132 "nasdaq.gperf"
      {"AEAQW", 119},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2735 "nasdaq.gperf"
      {"JXG", 2722},
      {""},
#line 3145 "nasdaq.gperf"
      {"MFI", 3132},
      {""}, {""}, {""}, {""},
#line 2804 "nasdaq.gperf"
      {"KOID", 2791},
      {""},
#line 2607 "nasdaq.gperf"
      {"IPM", 2594},
      {""}, {""}, {""},
#line 3806 "nasdaq.gperf"
      {"PCPI", 3793},
      {""}, {""}, {""}, {""},
#line 3146 "nasdaq.gperf"
      {"MFIC", 3133},
      {""}, {""}, {""}, {""}, {""},
#line 3496 "nasdaq.gperf"
      {"NSAIU", 3483},
      {""},
#line 5500 "nasdaq.gperf"
      {"XSLLW", 5487},
#line 5268 "nasdaq.gperf"
      {"VOD", 5255},
#line 4304 "nasdaq.gperf"
      {"RMSGW", 4291},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2615 "nasdaq.gperf"
      {"IPX", 2602},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2613 "nasdaq.gperf"
      {"IPW", 2600},
      {""}, {""}, {""}, {""},
#line 4647 "nasdaq.gperf"
      {"SOXQ", 4634},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4382 "nasdaq.gperf"
      {"SAAQ", 4369},
#line 4383 "nasdaq.gperf"
      {"SAAQU", 4370},
#line 1822 "nasdaq.gperf"
      {"FIGG", 1809},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 398 "nasdaq.gperf"
      {"ARDX", 385},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2572 "nasdaq.gperf"
      {"INTA", 2559},
      {""},
#line 2459 "nasdaq.gperf"
      {"ICG", 2446},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2573 "nasdaq.gperf"
      {"INTC", 2560},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 638 "nasdaq.gperf"
      {"BGIA", 625},
      {""},
#line 2580 "nasdaq.gperf"
      {"INTZ", 2567},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2432 "nasdaq.gperf"
      {"IBG", 2419},
      {""}, {""}, {""}, {""}, {""},
#line 2433 "nasdaq.gperf"
      {"IBGA", 2420},
      {""},
#line 1458 "nasdaq.gperf"
      {"DRMA", 1445},
      {""},
#line 64 "nasdaq.gperf"
      {"ACDC", 51},
      {""}, {""}, {""}, {""}, {""},
#line 2435 "nasdaq.gperf"
      {"IBGC", 2422},
#line 636 "nasdaq.gperf"
      {"BGEG", 623},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4626 "nasdaq.gperf"
      {"SOFA", 4613},
      {""},
#line 2010 "nasdaq.gperf"
      {"GAINI", 1997},
      {""}, {""},
#line 4628 "nasdaq.gperf"
      {"SOFX", 4615},
      {""}, {""}, {""},
#line 2127 "nasdaq.gperf"
      {"GNMA", 2114},
      {""}, {""}, {""}, {""}, {""},
#line 4627 "nasdaq.gperf"
      {"SOFI", 4614},
      {""},
#line 4972 "nasdaq.gperf"
      {"TRDA", 4959},
      {""}, {""},
#line 2545 "nasdaq.gperf"
      {"INBX", 2532},
      {""}, {""}, {""}, {""}, {""},
#line 4316 "nasdaq.gperf"
      {"RNTX", 4303},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2547 "nasdaq.gperf"
      {"INCY", 2534},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3148 "nasdaq.gperf"
      {"MFIG", 3135},
#line 1446 "nasdaq.gperf"
      {"DOX", 1433},
      {""},
#line 1371 "nasdaq.gperf"
      {"DCX", 1358},
#line 4389 "nasdaq.gperf"
      {"SAFX", 4376},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2575 "nasdaq.gperf"
      {"INTJ", 2562},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1361 "nasdaq.gperf"
      {"DBCA", 1348},
#line 1362 "nasdaq.gperf"
      {"DBCAU", 1349},
      {""}, {""},
#line 5316 "nasdaq.gperf"
      {"VTWV", 5303},
#line 327 "nasdaq.gperf"
      {"ANGI", 314},
      {""},
#line 3837 "nasdaq.gperf"
      {"PEP", 3824},
      {""},
#line 1366 "nasdaq.gperf"
      {"DBX", 1353},
      {""}, {""}, {""},
#line 2355 "nasdaq.gperf"
      {"HRTX", 2342},
      {""},
#line 2616 "nasdaq.gperf"
      {"IPXG", 2603},
#line 2617 "nasdaq.gperf"
      {"IPXGU", 2604},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1360 "nasdaq.gperf"
      {"DAX", 1347},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2674 "nasdaq.gperf"
      {"IZM", 2661},
      {""}, {""}, {""}, {""},
#line 73 "nasdaq.gperf"
      {"ACGLO", 60},
#line 2318 "nasdaq.gperf"
      {"HLXC", 2305},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 121 "nasdaq.gperf"
      {"ADSE", 108},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1809 "nasdaq.gperf"
      {"FGIIW", 1796},
      {""},
#line 5550 "nasdaq.gperf"
      {"YYAI", 5537},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5324 "nasdaq.gperf"
      {"VYMI", 5311},
#line 2277 "nasdaq.gperf"
      {"HCTI", 2264},
      {""}, {""},
#line 2574 "nasdaq.gperf"
      {"INTG", 2561},
#line 2260 "nasdaq.gperf"
      {"HBT", 2247},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4948 "nasdaq.gperf"
      {"TNGX", 4935},
#line 2352 "nasdaq.gperf"
      {"HRMY", 2339},
      {""}, {""},
#line 96 "nasdaq.gperf"
      {"ACXP", 83},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 13 "nasdaq.gperf"
      {"AAAP", 0},
      {""}, {""}, {""}, {""},
#line 969 "nasdaq.gperf"
      {"CCD", 956},
      {""}, {""}, {""},
#line 1171 "nasdaq.gperf"
      {"CODA", 1158},
      {""}, {""}, {""}, {""},
#line 1172 "nasdaq.gperf"
      {"CODX", 1159},
#line 21 "nasdaq.gperf"
      {"AACP", 8},
#line 23 "nasdaq.gperf"
      {"AACPU", 10},
      {""}, {""},
#line 3228 "nasdaq.gperf"
      {"MODD", 3215},
      {""},
#line 22 "nasdaq.gperf"
      {"AACPR", 9},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3851 "nasdaq.gperf"
      {"PFI", 3838},
#line 532 "nasdaq.gperf"
      {"AYA", 519},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3900 "nasdaq.gperf"
      {"PLPC", 3887},
      {""}, {""}, {""}, {""},
#line 4409 "nasdaq.gperf"
      {"SBFG", 4396},
      {""}, {""}, {""}, {""},
#line 476 "nasdaq.gperf"
      {"ATOS", 463},
      {""}, {""}, {""}, {""}, {""},
#line 2789 "nasdaq.gperf"
      {"KLIC", 2776},
      {""}, {""}, {""}, {""}, {""},
#line 1751 "nasdaq.gperf"
      {"FCFS", 1738},
      {""}, {""}, {""},
#line 2521 "nasdaq.gperf"
      {"IMMR", 2508},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2516 "nasdaq.gperf"
      {"IMCR", 2503},
      {""}, {""}, {""}, {""},
#line 4227 "nasdaq.gperf"
      {"REG", 4214},
#line 3882 "nasdaq.gperf"
      {"PIZ", 3869},
#line 1463 "nasdaq.gperf"
      {"DRUG", 1450},
#line 5001 "nasdaq.gperf"
      {"TRUP", 4988},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3838 "nasdaq.gperf"
      {"PEPG", 3825},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1377 "nasdaq.gperf"
      {"DEMZ", 1364},
#line 4657 "nasdaq.gperf"
      {"SPEG", 4644},
#line 4659 "nasdaq.gperf"
      {"SPEGU", 4646},
      {""}, {""}, {""},
#line 4858 "nasdaq.gperf"
      {"TDUP", 4845},
#line 4658 "nasdaq.gperf"
      {"SPEGR", 4645},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2859 "nasdaq.gperf"
      {"LANDO", 2846},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2148 "nasdaq.gperf"
      {"GP", 2135},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 958 "nasdaq.gperf"
      {"CCAP", 945},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5491 "nasdaq.gperf"
      {"XRPN", 5478},
#line 5492 "nasdaq.gperf"
      {"XRPNU", 5479},
      {""}, {""},
#line 235 "nasdaq.gperf"
      {"ALDX", 222},
      {""},
#line 1170 "nasdaq.gperf"
      {"COCP", 1157},
      {""}, {""}, {""}, {""}, {""},
#line 2149 "nasdaq.gperf"
      {"GPAC", 2136},
#line 2150 "nasdaq.gperf"
      {"GPACU", 2137},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4520 "nasdaq.gperf"
      {"SIGA", 4507},
      {""}, {""}, {""},
#line 4560 "nasdaq.gperf"
      {"SLGL", 4547},
      {""}, {""},
#line 3414 "nasdaq.gperf"
      {"NEWTO", 3401},
      {""}, {""},
#line 920 "nasdaq.gperf"
      {"CAMP", 907},
      {""}, {""}, {""}, {""},
#line 4521 "nasdaq.gperf"
      {"SIGI", 4508},
      {""}, {""}, {""}, {""}, {""},
#line 929 "nasdaq.gperf"
      {"CAPS", 916},
      {""}, {""}, {""}, {""}, {""},
#line 2824 "nasdaq.gperf"
      {"KRRO", 2811},
      {""}, {""},
#line 5072 "nasdaq.gperf"
      {"TXUE", 5059},
      {""}, {""}, {""}, {""},
#line 2180 "nasdaq.gperf"
      {"GRRR", 2167},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1411 "nasdaq.gperf"
      {"DJT", 1398},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2131 "nasdaq.gperf"
      {"GNTA", 2118},
      {""}, {""}, {""},
#line 4332 "nasdaq.gperf"
      {"RPAY", 4319},
#line 2132 "nasdaq.gperf"
      {"GNTX", 2119},
#line 3121 "nasdaq.gperf"
      {"MEDX", 3108},
      {""}, {""}, {""},
#line 4280 "nasdaq.gperf"
      {"RING", 4267},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3332 "nasdaq.gperf"
      {"MYMI", 3319},
      {""}, {""}, {""}, {""}, {""},
#line 3339 "nasdaq.gperf"
      {"MYX", 3326},
      {""}, {""}, {""}, {""},
#line 924 "nasdaq.gperf"
      {"CANQ", 911},
#line 3315 "nasdaq.gperf"
      {"MYCI", 3302},
      {""}, {""},
#line 1841 "nasdaq.gperf"
      {"FJP", 1828},
      {""}, {""},
#line 3341 "nasdaq.gperf"
      {"MYXXU", 3328},
      {""}, {""},
#line 4229 "nasdaq.gperf"
      {"REGCP", 4216},
      {""},
#line 3340 "nasdaq.gperf"
      {"MYXXR", 3327},
      {""}, {""},
#line 4963 "nasdaq.gperf"
      {"TPG", 4950},
      {""}, {""}, {""}, {""},
#line 182 "nasdaq.gperf"
      {"AGZD", 169},
#line 2743 "nasdaq.gperf"
      {"KARO", 2730},
      {""},
#line 2343 "nasdaq.gperf"
      {"HOYY", 2330},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2797 "nasdaq.gperf"
      {"KMLI", 2784},
#line 2071 "nasdaq.gperf"
      {"GGR", 2058},
      {""},
#line 4299 "nasdaq.gperf"
      {"RMCOW", 4286},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 266 "nasdaq.gperf"
      {"ALPS", 253},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4018 "nasdaq.gperf"
      {"PSQL", 4005},
      {""}, {""}, {""},
#line 3818 "nasdaq.gperf"
      {"PDD", 3805},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3147 "nasdaq.gperf"
      {"MFICL", 3134},
      {""}, {""}, {""},
#line 3938 "nasdaq.gperf"
      {"PODD", 3925},
      {""}, {""},
#line 646 "nasdaq.gperf"
      {"BGRO", 633},
#line 3333 "nasdaq.gperf"
      {"MYMJ", 3320},
#line 5494 "nasdaq.gperf"
      {"XRPT", 5481},
      {""},
#line 1110 "nasdaq.gperf"
      {"CLDX", 1097},
      {""},
#line 2715 "nasdaq.gperf"
      {"JONEU", 2702},
      {""}, {""}, {""}, {""}, {""},
#line 3937 "nasdaq.gperf"
      {"PODC", 3924},
#line 3316 "nasdaq.gperf"
      {"MYCJ", 3303},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1538 "nasdaq.gperf"
      {"ECX", 1525},
      {""}, {""}, {""}, {""},
#line 3214 "nasdaq.gperf"
      {"MNSB", 3201},
#line 4522 "nasdaq.gperf"
      {"SIGIP", 4509},
#line 1103 "nasdaq.gperf"
      {"CISO", 1090},
      {""}, {""},
#line 1527 "nasdaq.gperf"
      {"EBC", 1514},
      {""},
#line 4344 "nasdaq.gperf"
      {"RSSS", 4331},
      {""}, {""}, {""},
#line 1025 "nasdaq.gperf"
      {"CEPS", 1012},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 519 "nasdaq.gperf"
      {"AVX", 506},
      {""}, {""}, {""}, {""}, {""},
#line 3237 "nasdaq.gperf"
      {"MPG", 3224},
      {""}, {""}, {""}, {""},
#line 522 "nasdaq.gperf"
      {"AVXX", 509},
      {""}, {""}, {""}, {""},
#line 520 "nasdaq.gperf"
      {"AVXC", 507},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1547 "nasdaq.gperf"
      {"EDUC", 1534},
      {""},
#line 3330 "nasdaq.gperf"
      {"MYMG", 3317},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4608 "nasdaq.gperf"
      {"SNES", 4595},
      {""}, {""}, {""}, {""},
#line 3313 "nasdaq.gperf"
      {"MYCG", 3300},
      {""}, {""}, {""}, {""},
#line 2776 "nasdaq.gperf"
      {"KG", 2763},
      {""}, {""}, {""},
#line 2086 "nasdaq.gperf"
      {"GIND", 2073},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 120 "nasdaq.gperf"
      {"ADPT", 107},
      {""}, {""},
#line 2087 "nasdaq.gperf"
      {"GINX", 2074},
#line 5046 "nasdaq.gperf"
      {"TVA", 5033},
      {""}, {""}, {""},
#line 2347 "nasdaq.gperf"
      {"HQ", 2334},
      {""}, {""}, {""}, {""},
#line 2043 "nasdaq.gperf"
      {"GEG", 2030},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5047 "nasdaq.gperf"
      {"TVACU", 5034},
      {""}, {""}, {""},
#line 5049 "nasdaq.gperf"
      {"TVAI", 5036},
#line 5051 "nasdaq.gperf"
      {"TVAIU", 5038},
#line 5504 "nasdaq.gperf"
      {"XTER", 5491},
#line 5505 "nasdaq.gperf"
      {"XTERU", 5492},
#line 5521 "nasdaq.gperf"
      {"YDKG", 5508},
      {""},
#line 5050 "nasdaq.gperf"
      {"TVAIR", 5037},
#line 1379 "nasdaq.gperf"
      {"DETX", 1366},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 579 "nasdaq.gperf"
      {"BCCQ", 566},
#line 580 "nasdaq.gperf"
      {"BCCQU", 567},
      {""}, {""},
#line 1930 "nasdaq.gperf"
      {"FSLR", 1917},
      {""},
#line 3799 "nasdaq.gperf"
      {"PCAP", 3786},
#line 3800 "nasdaq.gperf"
      {"PCAPU", 3787},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1124 "nasdaq.gperf"
      {"CLPS", 1111},
      {""},
#line 3034 "nasdaq.gperf"
      {"LX", 3021},
#line 925 "nasdaq.gperf"
      {"CAPN", 912},
#line 927 "nasdaq.gperf"
      {"CAPNU", 914},
      {""}, {""}, {""}, {""},
#line 926 "nasdaq.gperf"
      {"CAPNR", 913},
      {""}, {""}, {""}, {""},
#line 1791 "nasdaq.gperf"
      {"FEP", 1778},
#line 3397 "nasdaq.gperf"
      {"NECB", 3384},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5544 "nasdaq.gperf"
      {"YSAU", 5531},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1792 "nasdaq.gperf"
      {"FEPI", 1779},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2161 "nasdaq.gperf"
      {"GPT", 2148},
      {""}, {""}, {""},
#line 1313 "nasdaq.gperf"
      {"CV", 1300},
      {""},
#line 3215 "nasdaq.gperf"
      {"MNSBP", 3202},
      {""},
#line 460 "nasdaq.gperf"
      {"ATER", 447},
      {""},
#line 4056 "nasdaq.gperf"
      {"PY", 4043},
      {""}, {""}, {""}, {""}, {""},
#line 297 "nasdaq.gperf"
      {"AMGR", 284},
      {""}, {""}, {""}, {""}, {""},
#line 1231 "nasdaq.gperf"
      {"CRBP", 1218},
      {""},
#line 1551 "nasdaq.gperf"
      {"EEMA", 1538},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 750 "nasdaq.gperf"
      {"BOF", 737},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2577 "nasdaq.gperf"
      {"INTS", 2564},
#line 444 "nasdaq.gperf"
      {"ASRV", 431},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 485 "nasdaq.gperf"
      {"AUC", 472},
#line 706 "nasdaq.gperf"
      {"BLNE", 693},
      {""}, {""}, {""}, {""},
#line 951 "nasdaq.gperf"
      {"CBK", 938},
      {""}, {""},
#line 489 "nasdaq.gperf"
      {"AUMI", 476},
#line 434 "nasdaq.gperf"
      {"ASMU", 421},
#line 4671 "nasdaq.gperf"
      {"SPRO", 4658},
#line 2649 "nasdaq.gperf"
      {"ISUL", 2636},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1320 "nasdaq.gperf"
      {"CVV", 1307},
      {""},
#line 5108 "nasdaq.gperf"
      {"ULCC", 5095},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4262 "nasdaq.gperf"
      {"RGTIW", 4249},
      {""}, {""},
#line 4171 "nasdaq.gperf"
      {"RAINW", 4158},
      {""}, {""},
#line 5554 "nasdaq.gperf"
      {"ZBAO", 5541},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5255 "nasdaq.gperf"
      {"VLYPP", 5242},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2544 "nasdaq.gperf"
      {"INBS", 2531},
      {""}, {""}, {""}, {""}, {""},
#line 539 "nasdaq.gperf"
      {"BABU", 526},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5093 "nasdaq.gperf"
      {"UECG", 5080},
#line 496 "nasdaq.gperf"
      {"AUUD", 483},
#line 2587 "nasdaq.gperf"
      {"IONR", 2574},
#line 1869 "nasdaq.gperf"
      {"FMFC", 1856},
      {""}, {""}, {""}, {""}, {""},
#line 5399 "nasdaq.gperf"
      {"WOOF", 5386},
      {""}, {""}, {""},
#line 1422 "nasdaq.gperf"
      {"DLXY", 1409},
      {""}, {""},
#line 3371 "nasdaq.gperf"
      {"NBTB", 3358},
      {""},
#line 1764 "nasdaq.gperf"
      {"FDFF", 1751},
#line 2249 "nasdaq.gperf"
      {"HBAN", 2236},
      {""}, {""}, {""}, {""}, {""},
#line 5023 "nasdaq.gperf"
      {"TSMU", 5010},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1839 "nasdaq.gperf"
      {"FIZZ", 1826},
#line 4867 "nasdaq.gperf"
      {"TEKX", 4854},
      {""}, {""},
#line 2253 "nasdaq.gperf"
      {"HBANZ", 2240},
#line 2354 "nasdaq.gperf"
      {"HRTS", 2341},
      {""}, {""}, {""}, {""},
#line 3839 "nasdaq.gperf"
      {"PEPS", 3826},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2351 "nasdaq.gperf"
      {"HQY", 2338},
      {""}, {""},
#line 4620 "nasdaq.gperf"
      {"SNYR", 4607},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2259 "nasdaq.gperf"
      {"HBR", 2246},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1588 "nasdaq.gperf"
      {"ELVA", 1575},
      {""}, {""}, {""},
#line 516 "nasdaq.gperf"
      {"AVT", 503},
      {""}, {""}, {""},
#line 304 "nasdaq.gperf"
      {"AMPG", 291},
      {""}, {""}, {""},
#line 2105 "nasdaq.gperf"
      {"GLGG", 2092},
      {""}, {""},
#line 517 "nasdaq.gperf"
      {"AVTX", 504},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2767 "nasdaq.gperf"
      {"KELYB", 2754},
      {""}, {""},
#line 1143 "nasdaq.gperf"
      {"CMPX", 1130},
      {""}, {""}, {""},
#line 305 "nasdaq.gperf"
      {"AMPGZ", 292},
#line 3504 "nasdaq.gperf"
      {"NSYS", 3491},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3294 "nasdaq.gperf"
      {"MU", 3281},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3781 "nasdaq.gperf"
      {"PAYP", 3768},
      {""}, {""}, {""},
#line 5281 "nasdaq.gperf"
      {"VRDN", 5268},
      {""}, {""}, {""}, {""}, {""},
#line 4318 "nasdaq.gperf"
      {"RNXT", 4305},
      {""},
#line 4258 "nasdaq.gperf"
      {"RGNX", 4245},
      {""}, {""}, {""}, {""}, {""},
#line 4315 "nasdaq.gperf"
      {"RNRG", 4302},
#line 4987 "nasdaq.gperf"
      {"TROO", 4974},
      {""}, {""},
#line 3149 "nasdaq.gperf"
      {"MFIN", 3136},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3015 "nasdaq.gperf"
      {"LTRX", 3002},
#line 4678 "nasdaq.gperf"
      {"SPWR", 4665},
      {""}, {""}, {""},
#line 1526 "nasdaq.gperf"
      {"EBAY", 1513},
      {""},
#line 3090 "nasdaq.gperf"
      {"MCDS", 3077},
      {""}, {""}, {""}, {""}, {""},
#line 3903 "nasdaq.gperf"
      {"PLSE", 3890},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3852 "nasdaq.gperf"
      {"PFIS", 3839},
      {""}, {""}, {""}, {""},
#line 4443 "nasdaq.gperf"
      {"SDGR", 4430},
      {""}, {""}, {""}, {""},
#line 5058 "nasdaq.gperf"
      {"TVTX", 5045},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2265 "nasdaq.gperf"
      {"HCAT", 2252},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2252 "nasdaq.gperf"
      {"HBANP", 2239},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3298 "nasdaq.gperf"
      {"MUU", 3285},
      {""}, {""}, {""},
#line 4036 "nasdaq.gperf"
      {"PTON", 4023},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 173 "nasdaq.gperf"
      {"AGNCN", 160},
#line 3503 "nasdaq.gperf"
      {"NSTS", 3490},
#line 1904 "nasdaq.gperf"
      {"FRD", 1891},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4964 "nasdaq.gperf"
      {"TPGXL", 4951},
      {""}, {""}, {""},
#line 639 "nasdaq.gperf"
      {"BGIN", 626},
#line 2339 "nasdaq.gperf"
      {"HOVNP", 2326},
#line 2491 "nasdaq.gperf"
      {"IFV", 2478},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2289 "nasdaq.gperf"
      {"HERD", 2276},
      {""}, {""}, {""}, {""},
#line 4244 "nasdaq.gperf"
      {"RFAI", 4231},
#line 4246 "nasdaq.gperf"
      {"RFAIU", 4233},
      {""},
#line 1840 "nasdaq.gperf"
      {"FJDIU", 1827},
      {""},
#line 4336 "nasdaq.gperf"
      {"RPRX", 4323},
#line 4245 "nasdaq.gperf"
      {"RFAIR", 4232},
      {""}, {""},
#line 4485 "nasdaq.gperf"
      {"SFWL", 4472},
      {""}, {""}, {""}, {""}, {""},
#line 3788 "nasdaq.gperf"
      {"PBK", 3775},
      {""}, {""}, {""}, {""},
#line 2292 "nasdaq.gperf"
      {"HERZ", 2279},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 270 "nasdaq.gperf"
      {"ALPXW", 257},
      {""}, {""}, {""}, {""},
#line 4466 "nasdaq.gperf"
      {"SENEB", 4453},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1723 "nasdaq.gperf"
      {"FAD", 1710},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1125 "nasdaq.gperf"
      {"CLPT", 1112},
#line 5110 "nasdaq.gperf"
      {"ULTA", 5097},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1464 "nasdaq.gperf"
      {"DRVN", 1451},
      {""}, {""}, {""}, {""}, {""},
#line 5111 "nasdaq.gperf"
      {"ULTI", 5098},
      {""},
#line 3941 "nasdaq.gperf"
      {"POLE", 3928},
#line 3942 "nasdaq.gperf"
      {"POLEU", 3929},
      {""},
#line 2314 "nasdaq.gperf"
      {"HLMN", 2301},
      {""}, {""}, {""}, {""}, {""},
#line 1461 "nasdaq.gperf"
      {"DRTS", 1448},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2274 "nasdaq.gperf"
      {"HCMAW", 2261},
#line 1021 "nasdaq.gperf"
      {"CEPF", 1008},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3120 "nasdaq.gperf"
      {"MEDS", 3107},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1826 "nasdaq.gperf"
      {"FIGXW", 1813},
#line 5522 "nasdaq.gperf"
      {"YHC", 5509},
      {""}, {""}, {""}, {""},
#line 5229 "nasdaq.gperf"
      {"VHC", 5216},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1586 "nasdaq.gperf"
      {"ELTX", 1573},
#line 5107 "nasdaq.gperf"
      {"ULBI", 5094},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3251 "nasdaq.gperf"
      {"MRDN", 3238},
      {""}, {""}, {""}, {""}, {""},
#line 1746 "nasdaq.gperf"
      {"FCAP", 1733},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1637 "nasdaq.gperf"
      {"ERAS", 1624},
      {""}, {""},
#line 545 "nasdaq.gperf"
      {"BAERW", 532},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 627 "nasdaq.gperf"
      {"BFLX", 614},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2792 "nasdaq.gperf"
      {"KLTR", 2779},
      {""}, {""}, {""}, {""},
#line 1451 "nasdaq.gperf"
      {"DRCT", 1438},
      {""}, {""}, {""},
#line 5258 "nasdaq.gperf"
      {"VMD", 5245},
      {""}, {""}, {""},
#line 186 "nasdaq.gperf"
      {"AHMA", 173},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4207 "nasdaq.gperf"
      {"RDGT", 4194},
      {""}, {""}, {""}, {""},
#line 5568 "nasdaq.gperf"
      {"ZJYL", 5555},
      {""},
#line 4006 "nasdaq.gperf"
      {"PSCU", 3993},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4484 "nasdaq.gperf"
      {"SFST", 4471},
#line 4476 "nasdaq.gperf"
      {"SEZL", 4463},
      {""},
#line 4868 "nasdaq.gperf"
      {"TEKY", 4855},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2003 "nasdaq.gperf"
      {"FYC", 1990},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4388 "nasdaq.gperf"
      {"SAFT", 4375},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2005 "nasdaq.gperf"
      {"FYX", 1992},
      {""}, {""},
#line 2970 "nasdaq.gperf"
      {"LOCO", 2957},
      {""}, {""}, {""},
#line 4230 "nasdaq.gperf"
      {"REGN", 4217},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4885 "nasdaq.gperf"
      {"TH", 4872},
      {""},
#line 529 "nasdaq.gperf"
      {"AXON", 516},
#line 4973 "nasdaq.gperf"
      {"TREE", 4960},
      {""}, {""}, {""}, {""}, {""},
#line 4568 "nasdaq.gperf"
      {"SLP", 4555},
      {""}, {""},
#line 3269 "nasdaq.gperf"
      {"MSFD", 3256},
      {""}, {""}, {""},
#line 290 "nasdaq.gperf"
      {"AMD", 277},
#line 291 "nasdaq.gperf"
      {"AMDD", 278},
      {""}, {""},
#line 4480 "nasdaq.gperf"
      {"SFIX", 4467},
#line 4384 "nasdaq.gperf"
      {"SAAQW", 4371},
      {""},
#line 1632 "nasdaq.gperf"
      {"EQ", 1619},
#line 4031 "nasdaq.gperf"
      {"PTIR", 4018},
      {""}, {""}, {""}, {""},
#line 1303 "nasdaq.gperf"
      {"CUB", 1290},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4892 "nasdaq.gperf"
      {"THMZ", 4879},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1190 "nasdaq.gperf"
      {"COOL", 1177},
      {""}, {""}, {""}, {""},
#line 1365 "nasdaq.gperf"
      {"DBVT", 1352},
      {""}, {""}, {""}, {""}, {""},
#line 2044 "nasdaq.gperf"
      {"GEGGL", 2031},
      {""}, {""},
#line 48 "nasdaq.gperf"
      {"ABLV", 35},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5078 "nasdaq.gperf"
      {"TYRA", 5065},
#line 1423 "nasdaq.gperf"
      {"DMAA", 1410},
#line 1425 "nasdaq.gperf"
      {"DMAAU", 1412},
      {""}, {""},
#line 1844 "nasdaq.gperf"
      {"FLD", 1831},
      {""},
#line 1424 "nasdaq.gperf"
      {"DMAAR", 1411},
      {""}, {""}, {""},
#line 1426 "nasdaq.gperf"
      {"DMAC", 1413},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5210 "nasdaq.gperf"
      {"VEEE", 5197},
#line 2487 "nasdaq.gperf"
      {"IFBD", 2474},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2061 "nasdaq.gperf"
      {"GFAI", 2048},
      {""}, {""}, {""},
#line 2250 "nasdaq.gperf"
      {"HBANL", 2237},
      {""}, {""},
#line 4932 "nasdaq.gperf"
      {"TMDX", 4919},
      {""}, {""}, {""},
#line 1053 "nasdaq.gperf"
      {"CHA", 1040},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1054 "nasdaq.gperf"
      {"CHAI", 1041},
      {""},
#line 1334 "nasdaq.gperf"
      {"CYCN", 1321},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1058 "nasdaq.gperf"
      {"CHCI", 1045},
      {""},
#line 3320 "nasdaq.gperf"
      {"MYCN", 3307},
      {""}, {""}, {""},
#line 1363 "nasdaq.gperf"
      {"DBCAW", 1350},
      {""},
#line 3515 "nasdaq.gperf"
      {"NTRA", 3502},
      {""},
#line 2654 "nasdaq.gperf"
      {"ITIC", 2641},
#line 4281 "nasdaq.gperf"
      {"RINT", 4268},
      {""}, {""},
#line 1090 "nasdaq.gperf"
      {"CHW", 1077},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2618 "nasdaq.gperf"
      {"IPXGW", 2605},
      {""},
#line 4662 "nasdaq.gperf"
      {"SPIT", 4649},
      {""}, {""}, {""}, {""}, {""},
#line 1339 "nasdaq.gperf"
      {"CYRX", 1326},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3964 "nasdaq.gperf"
      {"PQAP", 3951},
      {""}, {""}, {""}, {""},
#line 4060 "nasdaq.gperf"
      {"PYXS", 4047},
      {""}, {""}, {""},
#line 2066 "nasdaq.gperf"
      {"GFUZ", 2053},
      {""}, {""}, {""},
#line 122 "nasdaq.gperf"
      {"ADSEW", 109},
#line 292 "nasdaq.gperf"
      {"AMDG", 279},
#line 2784 "nasdaq.gperf"
      {"KITT", 2771},
      {""}, {""}, {""},
#line 2887 "nasdaq.gperf"
      {"LECO", 2874},
      {""}, {""}, {""}, {""}, {""},
#line 5090 "nasdaq.gperf"
      {"UCRD", 5077},
#line 1235 "nasdaq.gperf"
      {"CRDF", 1222},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4878 "nasdaq.gperf"
      {"TFGZ", 4865},
      {""},
#line 3572 "nasdaq.gperf"
      {"NXT", 3559},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2152 "nasdaq.gperf"
      {"GPAT", 2139},
#line 2153 "nasdaq.gperf"
      {"GPATU", 2140},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3573 "nasdaq.gperf"
      {"NXTC", 3560},
      {""}, {""}, {""}, {""}, {""},
#line 1960 "nasdaq.gperf"
      {"FTRE", 1947},
      {""},
#line 24 "nasdaq.gperf"
      {"AACPW", 11},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4210 "nasdaq.gperf"
      {"RDIB", 4197},
      {""}, {""},
#line 1219 "nasdaq.gperf"
      {"CPZ", 1206},
      {""},
#line 1982 "nasdaq.gperf"
      {"FV", 1969},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5349 "nasdaq.gperf"
      {"WDFC", 5336},
      {""}, {""},
#line 3377 "nasdaq.gperf"
      {"NCLD", 3364},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1069 "nasdaq.gperf"
      {"CHMG", 1056},
#line 1984 "nasdaq.gperf"
      {"FVC", 1971},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 514 "nasdaq.gperf"
      {"AVR", 501},
#line 3508 "nasdaq.gperf"
      {"NTCT", 3495},
      {""}, {""},
#line 462 "nasdaq.gperf"
      {"ATGL", 449},
      {""},
#line 3299 "nasdaq.gperf"
      {"MUYY", 3286},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 196 "nasdaq.gperf"
      {"AIIO", 183},
      {""}, {""}, {""},
#line 5327 "nasdaq.gperf"
      {"WAFD", 5314},
      {""}, {""}, {""},
#line 249 "nasdaq.gperf"
      {"ALKS", 236},
      {""}, {""}, {""},
#line 2004 "nasdaq.gperf"
      {"FYT", 1991},
      {""}, {""}, {""}, {""},
#line 1915 "nasdaq.gperf"
      {"FRPT", 1902},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3336 "nasdaq.gperf"
      {"MYRG", 3323},
#line 1142 "nasdaq.gperf"
      {"CMPS", 1129},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2332 "nasdaq.gperf"
      {"HON", 2319},
      {""}, {""}, {""},
#line 1091 "nasdaq.gperf"
      {"CHY", 1078},
      {""},
#line 2333 "nasdaq.gperf"
      {"HONA", 2320},
      {""}, {""}, {""},
#line 3949 "nasdaq.gperf"
      {"POOL", 3936},
      {""}, {""},
#line 5059 "nasdaq.gperf"
      {"TW", 5046},
      {""},
#line 2997 "nasdaq.gperf"
      {"LRE", 2984},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5057 "nasdaq.gperf"
      {"TVRD", 5044},
      {""},
#line 232 "nasdaq.gperf"
      {"ALDF", 219},
#line 233 "nasdaq.gperf"
      {"ALDFU", 220},
      {""}, {""}, {""}, {""}, {""},
#line 5493 "nasdaq.gperf"
      {"XRPNW", 5480},
      {""}, {""},
#line 4611 "nasdaq.gperf"
      {"SNGX", 4598},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2258 "nasdaq.gperf"
      {"HBNC", 2245},
#line 2151 "nasdaq.gperf"
      {"GPACW", 2138},
      {""}, {""}, {""}, {""}, {""},
#line 3574 "nasdaq.gperf"
      {"NXTG", 3561},
#line 2969 "nasdaq.gperf"
      {"LOBO", 2956},
      {""},
#line 589 "nasdaq.gperf"
      {"BCPC", 576},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4518 "nasdaq.gperf"
      {"SIEB", 4505},
      {""}, {""}, {""}, {""},
#line 2206 "nasdaq.gperf"
      {"GTEC", 2193},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1530 "nasdaq.gperf"
      {"EBMT", 1517},
      {""},
#line 498 "nasdaq.gperf"
      {"AVAT", 485},
#line 4534 "nasdaq.gperf"
      {"SJCP", 4521},
      {""}, {""}, {""},
#line 2181 "nasdaq.gperf"
      {"GRRRW", 2168},
      {""}, {""}, {""},
#line 3037 "nasdaq.gperf"
      {"LXRX", 3024},
      {""}, {""}, {""}, {""},
#line 5115 "nasdaq.gperf"
      {"UMMA", 5102},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4345 "nasdaq.gperf"
      {"RSVR", 4332},
#line 583 "nasdaq.gperf"
      {"BCFN", 570},
      {""}, {""}, {""},
#line 3329 "nasdaq.gperf"
      {"MYMF", 3316},
      {""}, {""}, {""}, {""}, {""},
#line 2321 "nasdaq.gperf"
      {"HMYY", 2308},
      {""}, {""}, {""}, {""}, {""},
#line 3312 "nasdaq.gperf"
      {"MYCF", 3299},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 863 "nasdaq.gperf"
      {"BTOC", 850},
      {""}, {""},
#line 5328 "nasdaq.gperf"
      {"WAFDP", 5315},
      {""},
#line 1319 "nasdaq.gperf"
      {"CVRX", 1306},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 700 "nasdaq.gperf"
      {"BLFS", 687},
      {""}, {""},
#line 547 "nasdaq.gperf"
      {"BAFN", 534},
      {""},
#line 3342 "nasdaq.gperf"
      {"MYXXW", 3329},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4790 "nasdaq.gperf"
      {"SY", 4777},
      {""},
#line 3307 "nasdaq.gperf"
      {"MWC", 3294},
      {""},
#line 1801 "nasdaq.gperf"
      {"FFIN", 1788},
      {""}, {""}, {""}, {""}, {""},
#line 491 "nasdaq.gperf"
      {"AUR", 478},
      {""}, {""}, {""},
#line 4792 "nasdaq.gperf"
      {"SYM", 4779},
      {""},
#line 492 "nasdaq.gperf"
      {"AURA", 479},
      {""}, {""}, {""}, {""},
#line 2881 "nasdaq.gperf"
      {"LCNB", 2868},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4019 "nasdaq.gperf"
      {"PSQLW", 4006},
      {""}, {""}, {""}, {""}, {""},
#line 5132 "nasdaq.gperf"
      {"URBN", 5119},
      {""}, {""}, {""}, {""}, {""},
#line 1604 "nasdaq.gperf"
      {"EMXC", 1591},
      {""}, {""},
#line 2923 "nasdaq.gperf"
      {"LI", 2910},
      {""},
#line 2880 "nasdaq.gperf"
      {"LCID", 2867},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2280 "nasdaq.gperf"
      {"HDRN", 2267},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 637 "nasdaq.gperf"
      {"BGGG", 624},
      {""}, {""},
#line 1785 "nasdaq.gperf"
      {"FELE", 1772},
      {""}, {""}, {""},
#line 5042 "nasdaq.gperf"
      {"TUR", 5029},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2040 "nasdaq.gperf"
      {"GECCG", 2027},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5388 "nasdaq.gperf"
      {"WLFC", 5375},
#line 1589 "nasdaq.gperf"
      {"ELVN", 1576},
      {""}, {""}, {""},
#line 2889 "nasdaq.gperf"
      {"LEE", 2876},
      {""}, {""}, {""}, {""}, {""},
#line 2813 "nasdaq.gperf"
      {"KPTI", 2800},
      {""},
#line 3850 "nasdaq.gperf"
      {"PFG", 3837},
      {""},
#line 1459 "nasdaq.gperf"
      {"DRNZ", 1446},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2885 "nasdaq.gperf"
      {"LDSF", 2872},
      {""}, {""}, {""}, {""},
#line 864 "nasdaq.gperf"
      {"BTOG", 851},
#line 418 "nasdaq.gperf"
      {"ARTNA", 405},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 632 "nasdaq.gperf"
      {"BFST", 619},
#line 838 "nasdaq.gperf"
      {"BSMV", 825},
      {""}, {""}, {""}, {""}, {""},
#line 4228 "nasdaq.gperf"
      {"REGCO", 4215},
      {""}, {""}, {""}, {""}, {""},
#line 814 "nasdaq.gperf"
      {"BSCV", 801},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3014 "nasdaq.gperf"
      {"LTRN", 3001},
#line 3881 "nasdaq.gperf"
      {"PIO", 3868},
      {""},
#line 5048 "nasdaq.gperf"
      {"TVACW", 5035},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5506 "nasdaq.gperf"
      {"XTERW", 5493},
      {""},
#line 4455 "nasdaq.gperf"
      {"SEDG", 4442},
      {""}, {""},
#line 2648 "nasdaq.gperf"
      {"ISTR", 2635},
      {""},
#line 1544 "nasdaq.gperf"
      {"EDRY", 1531},
      {""}, {""}, {""}, {""}, {""},
#line 581 "nasdaq.gperf"
      {"BCCQW", 568},
      {""}, {""}, {""},
#line 1311 "nasdaq.gperf"
      {"CURX", 1298},
      {""},
#line 3801 "nasdaq.gperf"
      {"PCAPW", 3788},
      {""}, {""}, {""},
#line 5091 "nasdaq.gperf"
      {"UCTT", 5078},
      {""}, {""}, {""},
#line 1309 "nasdaq.gperf"
      {"CURI", 1296},
      {""}, {""},
#line 5563 "nasdaq.gperf"
      {"ZG", 5550},
      {""}, {""}, {""}, {""},
#line 4266 "nasdaq.gperf"
      {"RIBB", 4253},
#line 4268 "nasdaq.gperf"
      {"RIBBU", 4255},
      {""}, {""}, {""}, {""},
#line 4267 "nasdaq.gperf"
      {"RIBBR", 4254},
      {""},
#line 3930 "nasdaq.gperf"
      {"PMVP", 3917},
      {""}, {""}, {""}, {""},
#line 1325 "nasdaq.gperf"
      {"CWY", 1312},
      {""},
#line 1580 "nasdaq.gperf"
      {"ELMT", 1567},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5501 "nasdaq.gperf"
      {"XSPC", 5488},
      {""}, {""},
#line 724 "nasdaq.gperf"
      {"BMGL", 711},
      {""},
#line 5502 "nasdaq.gperf"
      {"XSPI", 5489},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5234 "nasdaq.gperf"
      {"VIAV", 5221},
      {""}, {""},
#line 2490 "nasdaq.gperf"
      {"IFRX", 2477},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1591 "nasdaq.gperf"
      {"ELWT", 1578},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 250 "nasdaq.gperf"
      {"ALKT", 237},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4028 "nasdaq.gperf"
      {"PTF", 4015},
#line 4682 "nasdaq.gperf"
      {"SQFT", 4669},
      {""},
#line 3197 "nasdaq.gperf"
      {"MLKN", 3184},
      {""}, {""}, {""}, {""}, {""},
#line 4062 "nasdaq.gperf"
      {"PZZA", 4049},
#line 3493 "nasdaq.gperf"
      {"NRSN", 3480},
      {""},
#line 4218 "nasdaq.gperf"
      {"RDZN", 4205},
      {""},
#line 1587 "nasdaq.gperf"
      {"ELUT", 1574},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 437 "nasdaq.gperf"
      {"ASPC", 424},
#line 439 "nasdaq.gperf"
      {"ASPCU", 426},
#line 3481 "nasdaq.gperf"
      {"NOWL", 3468},
      {""}, {""},
#line 440 "nasdaq.gperf"
      {"ASPI", 427},
#line 438 "nasdaq.gperf"
      {"ASPCR", 425},
      {""}, {""}, {""}, {""},
#line 3396 "nasdaq.gperf"
      {"NDSN", 3383},
      {""}, {""},
#line 4761 "nasdaq.gperf"
      {"SVA", 4748},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 829 "nasdaq.gperf"
      {"BSJV", 816},
      {""}, {""},
#line 4765 "nasdaq.gperf"
      {"SVC", 4752},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4766 "nasdaq.gperf"
      {"SVCC", 4753},
#line 4767 "nasdaq.gperf"
      {"SVCCU", 4754},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2320 "nasdaq.gperf"
      {"HMR", 2307},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5227 "nasdaq.gperf"
      {"VGSR", 5214},
      {""}, {""},
#line 4692 "nasdaq.gperf"
      {"SRPT", 4679},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4852 "nasdaq.gperf"
      {"TDIV", 4839},
      {""}, {""}, {""},
#line 3355 "nasdaq.gperf"
      {"NATO", 3342},
      {""}, {""},
#line 484 "nasdaq.gperf"
      {"AUBN", 471},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3519 "nasdaq.gperf"
      {"NTRS", 3506},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1321 "nasdaq.gperf"
      {"CWBC", 1308},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2719 "nasdaq.gperf"
      {"JPEF", 2706},
#line 1593 "nasdaq.gperf"
      {"EMB", 1580},
#line 203 "nasdaq.gperf"
      {"AIOS", 190},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4468 "nasdaq.gperf"
      {"SEPN", 4455},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1594 "nasdaq.gperf"
      {"EMBC", 1581},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4683 "nasdaq.gperf"
      {"SQFTP", 4670},
      {""},
#line 4372 "nasdaq.gperf"
      {"RXST", 4359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3514 "nasdaq.gperf"
      {"NTNX", 3501},
      {""}, {""}, {""}, {""},
#line 1337 "nasdaq.gperf"
      {"CYN", 1324},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 685 "nasdaq.gperf"
      {"BJDX", 672},
      {""},
#line 3575 "nasdaq.gperf"
      {"NXTS", 3562},
      {""}, {""}, {""}, {""}, {""},
#line 1280 "nasdaq.gperf"
      {"CSPI", 1267},
      {""}, {""},
#line 165 "nasdaq.gperf"
      {"AGIO", 152},
      {""}, {""},
#line 3112 "nasdaq.gperf"
      {"MDIV", 3099},
#line 1730 "nasdaq.gperf"
      {"FBDT", 1717},
      {""}, {""}, {""}, {""},
#line 582 "nasdaq.gperf"
      {"BCDA", 569},
      {""},
#line 4045 "nasdaq.gperf"
      {"PUR", 4032},
      {""}, {""},
#line 4679 "nasdaq.gperf"
      {"SPWRW", 4666},
      {""}, {""}, {""}, {""},
#line 5254 "nasdaq.gperf"
      {"VLYPO", 5241},
      {""}, {""},
#line 747 "nasdaq.gperf"
      {"BODI", 734},
#line 847 "nasdaq.gperf"
      {"BSTV", 834},
      {""}, {""}, {""},
#line 3394 "nasdaq.gperf"
      {"NDLS", 3381},
      {""}, {""},
#line 1980 "nasdaq.gperf"
      {"FUTG", 1967},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1048 "nasdaq.gperf"
      {"CGO", 1035},
#line 3492 "nasdaq.gperf"
      {"NRIX", 3479},
#line 5083 "nasdaq.gperf"
      {"UBND", 5070},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4749 "nasdaq.gperf"
      {"SUMA", 4736},
#line 4751 "nasdaq.gperf"
      {"SUMAU", 4738},
      {""}, {""}, {""}, {""},
#line 4750 "nasdaq.gperf"
      {"SUMAR", 4737},
#line 1642 "nasdaq.gperf"
      {"ERNA", 1629},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4420 "nasdaq.gperf"
      {"SCDS", 4407},
      {""},
#line 3375 "nasdaq.gperf"
      {"NCI", 3362},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5134 "nasdaq.gperf"
      {"URNJ", 5121},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5180 "nasdaq.gperf"
      {"VALU", 5167},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3365 "nasdaq.gperf"
      {"NBIX", 3352},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3577 "nasdaq.gperf"
      {"NXXT", 3564},
#line 3452 "nasdaq.gperf"
      {"NIXX", 3439},
      {""},
#line 2686 "nasdaq.gperf"
      {"JBDI", 2673},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3347 "nasdaq.gperf"
      {"NAII", 3334},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4524 "nasdaq.gperf"
      {"SILO", 4511},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5545 "nasdaq.gperf"
      {"YSPY", 5532},
      {""},
#line 1431 "nasdaq.gperf"
      {"DMRA", 1418},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3448 "nasdaq.gperf"
      {"NIU", 3435},
      {""}, {""},
#line 1432 "nasdaq.gperf"
      {"DMRC", 1419},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5542 "nasdaq.gperf"
      {"YRAM", 5529},
      {""},
#line 3000 "nasdaq.gperf"
      {"LRMR", 2987},
      {""},
#line 564 "nasdaq.gperf"
      {"BBCP", 551},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3943 "nasdaq.gperf"
      {"POLEW", 3930},
#line 1314 "nasdaq.gperf"
      {"CVBF", 1301},
      {""}, {""}, {""}, {""},
#line 2357 "nasdaq.gperf"
      {"HSAI", 2344},
      {""}, {""},
#line 1462 "nasdaq.gperf"
      {"DRTSW", 1449},
      {""}, {""},
#line 1076 "nasdaq.gperf"
      {"CHR", 1063},
#line 1077 "nasdaq.gperf"
      {"CHRD", 1064},
      {""}, {""},
#line 3303 "nasdaq.gperf"
      {"MVBF", 3290},
      {""}, {""}, {""}, {""},
#line 209 "nasdaq.gperf"
      {"AIRE", 196},
      {""}, {""},
#line 2852 "nasdaq.gperf"
      {"LAES", 2839},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2691 "nasdaq.gperf"
      {"JCAP", 2678},
#line 1078 "nasdaq.gperf"
      {"CHRI", 1065},
      {""}, {""}, {""}, {""}, {""},
#line 2692 "nasdaq.gperf"
      {"JCSE", 2679},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4748 "nasdaq.gperf"
      {"SUJA", 4735},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3271 "nasdaq.gperf"
      {"MSFT", 3258},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2857 "nasdaq.gperf"
      {"LAMR", 2844},
#line 1835 "nasdaq.gperf"
      {"FIVE", 1822},
#line 2835 "nasdaq.gperf"
      {"KTWO", 2822},
#line 2837 "nasdaq.gperf"
      {"KTWOU", 2824},
      {""}, {""}, {""}, {""},
#line 2836 "nasdaq.gperf"
      {"KTWOR", 2823},
      {""}, {""}, {""}, {""},
#line 3874 "nasdaq.gperf"
      {"PHVS", 3861},
#line 668 "nasdaq.gperf"
      {"BIIB", 655},
      {""}, {""}, {""}, {""},
#line 3362 "nasdaq.gperf"
      {"NBIG", 3349},
      {""}, {""},
#line 2782 "nasdaq.gperf"
      {"KINS", 2769},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 101 "nasdaq.gperf"
      {"ADAM", 88},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 477 "nasdaq.gperf"
      {"ATPC", 464},
      {""}, {""}, {""}, {""}, {""},
#line 2868 "nasdaq.gperf"
      {"LAWR", 2855},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 110 "nasdaq.gperf"
      {"ADAMZ", 97},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2194 "nasdaq.gperf"
      {"GSIT", 2181},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5026 "nasdaq.gperf"
      {"TSPY", 5013},
      {""}, {""}, {""}, {""},
#line 5238 "nasdaq.gperf"
      {"VIOT", 5225},
      {""}, {""}, {""}, {""}, {""},
#line 2867 "nasdaq.gperf"
      {"LAUR", 2854},
      {""}, {""}, {""}, {""}, {""},
#line 4233 "nasdaq.gperf"
      {"RELL", 4220},
#line 2812 "nasdaq.gperf"
      {"KPRX", 2799},
      {""}, {""}, {""},
#line 5297 "nasdaq.gperf"
      {"VSDA", 5284},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1817 "nasdaq.gperf"
      {"FHTX", 1804},
      {""}, {""}, {""}, {""},
#line 1989 "nasdaq.gperf"
      {"FWAC", 1976},
#line 1991 "nasdaq.gperf"
      {"FWACU", 1978},
      {""},
#line 32 "nasdaq.gperf"
      {"AAPB", 19},
      {""}, {""},
#line 1990 "nasdaq.gperf"
      {"FWACR", 1977},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5263 "nasdaq.gperf"
      {"VNME", 5250},
#line 5264 "nasdaq.gperf"
      {"VNMEU", 5251},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 40 "nasdaq.gperf"
      {"AAVM", 27},
#line 5260 "nasdaq.gperf"
      {"VNCE", 5247},
      {""},
#line 204 "nasdaq.gperf"
      {"AIOT", 191},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 428 "nasdaq.gperf"
      {"ASD", 415},
      {""}, {""}, {""}, {""}, {""},
#line 4998 "nasdaq.gperf"
      {"TRUM", 4985},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1816 "nasdaq.gperf"
      {"FHB", 1803},
      {""}, {""}, {""}, {""}, {""},
#line 49 "nasdaq.gperf"
      {"ABLVW", 36},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3016 "nasdaq.gperf"
      {"LTRYW", 3003},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1846 "nasdaq.gperf"
      {"FLDDW", 1833},
      {""}, {""}, {""},
#line 3245 "nasdaq.gperf"
      {"MRAM", 3232},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3576 "nasdaq.gperf"
      {"NXTT", 3563},
      {""}, {""}, {""}, {""},
#line 2207 "nasdaq.gperf"
      {"GTEN", 2194},
#line 2208 "nasdaq.gperf"
      {"GTENU", 2195},
      {""},
#line 1433 "nasdaq.gperf"
      {"DMXF", 1420},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2159 "nasdaq.gperf"
      {"GPRF", 2146},
#line 1468 "nasdaq.gperf"
      {"DSC", 1455},
#line 1465 "nasdaq.gperf"
      {"DSAC", 1452},
#line 1466 "nasdaq.gperf"
      {"DSACU", 1453},
#line 2442 "nasdaq.gperf"
      {"IBOC", 2429},
      {""},
#line 2062 "nasdaq.gperf"
      {"GFAIW", 2049},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5011 "nasdaq.gperf"
      {"TSDD", 4998},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1015 "nasdaq.gperf"
      {"CELU", 1002},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1524 "nasdaq.gperf"
      {"EART", 1511},
      {""}, {""}, {""},
#line 880 "nasdaq.gperf"
      {"BVC", 867},
      {""}, {""},
#line 4895 "nasdaq.gperf"
      {"THRY", 4882},
      {""},
#line 2362 "nasdaq.gperf"
      {"HST", 2349},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2683 "nasdaq.gperf"
      {"JAPN", 2670},
#line 198 "nasdaq.gperf"
      {"AIIR", 185},
#line 4180 "nasdaq.gperf"
      {"RAVE", 4167},
#line 1136 "nasdaq.gperf"
      {"CMCSA", 1123},
      {""}, {""}, {""},
#line 4504 "nasdaq.gperf"
      {"SHMD", 4491},
      {""},
#line 3084 "nasdaq.gperf"
      {"MBWM", 3071},
#line 104 "nasdaq.gperf"
      {"ADAMI", 91},
      {""},
#line 3873 "nasdaq.gperf"
      {"PHUN", 3860},
#line 2067 "nasdaq.gperf"
      {"GFUZW", 2054},
      {""}, {""}, {""},
#line 441 "nasdaq.gperf"
      {"ASPS", 428},
#line 4497 "nasdaq.gperf"
      {"SHC", 4484},
#line 2785 "nasdaq.gperf"
      {"KITTW", 2772},
      {""}, {""},
#line 2538 "nasdaq.gperf"
      {"INAB", 2525},
#line 578 "nasdaq.gperf"
      {"BCBP", 565},
      {""},
#line 2563 "nasdaq.gperf"
      {"INMB", 2550},
      {""}, {""}, {""},
#line 4495 "nasdaq.gperf"
      {"SHAZ", 4482},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 443 "nasdaq.gperf"
      {"ASPSZ", 430},
#line 4863 "nasdaq.gperf"
      {"TEAM", 4850},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2439 "nasdaq.gperf"
      {"IBIO", 2426},
      {""},
#line 2733 "nasdaq.gperf"
      {"JVA", 2720},
      {""},
#line 2712 "nasdaq.gperf"
      {"JLVP", 2699},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2154 "nasdaq.gperf"
      {"GPATW", 2141},
      {""}, {""}, {""}, {""},
#line 2933 "nasdaq.gperf"
      {"LIMN", 2920},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4730 "nasdaq.gperf"
      {"STNE", 4717},
      {""}, {""},
#line 2924 "nasdaq.gperf"
      {"LICN", 2911},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4260 "nasdaq.gperf"
      {"RGS", 4247},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 613 "nasdaq.gperf"
      {"BEDY", 600},
      {""}, {""}, {""}, {""}, {""},
#line 3490 "nasdaq.gperf"
      {"NRES", 3477},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3868 "nasdaq.gperf"
      {"PHAT", 3855},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3765 "nasdaq.gperf"
      {"PALU", 3752},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2946 "nasdaq.gperf"
      {"LIVN", 2933},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 197 "nasdaq.gperf"
      {"AIIOW", 184},
      {""}, {""}, {""}, {""}, {""},
#line 2944 "nasdaq.gperf"
      {"LITS", 2931},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1474 "nasdaq.gperf"
      {"DSY", 1461},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 719 "nasdaq.gperf"
      {"BLZR", 706},
#line 720 "nasdaq.gperf"
      {"BLZRU", 707},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1592 "nasdaq.gperf"
      {"EMAT", 1579},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 234 "nasdaq.gperf"
      {"ALDFW", 221},
      {""}, {""}, {""}, {""}, {""},
#line 837 "nasdaq.gperf"
      {"BSMU", 824},
      {""}, {""},
#line 5524 "nasdaq.gperf"
      {"YHNA", 5511},
#line 5526 "nasdaq.gperf"
      {"YHNAU", 5513},
      {""},
#line 2278 "nasdaq.gperf"
      {"HCWB", 2265},
      {""}, {""},
#line 5525 "nasdaq.gperf"
      {"YHNAR", 5512},
      {""}, {""},
#line 813 "nasdaq.gperf"
      {"BSCU", 800},
      {""}, {""}, {""},
#line 2168 "nasdaq.gperf"
      {"GRCE", 2155},
      {""}, {""}, {""}, {""},
#line 4192 "nasdaq.gperf"
      {"RCEL", 4179},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3309 "nasdaq.gperf"
      {"MWYN", 3296},
      {""}, {""},
#line 2084 "nasdaq.gperf"
      {"GILD", 2071},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 324 "nasdaq.gperf"
      {"ANEL", 311},
      {""},
#line 3805 "nasdaq.gperf"
      {"PCMM", 3792},
#line 4515 "nasdaq.gperf"
      {"SHY", 4502},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5576 "nasdaq.gperf"
      {"ZNB", 5563},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3784 "nasdaq.gperf"
      {"PBAM", 3771},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2702 "nasdaq.gperf"
      {"JFIN", 2689},
      {""}, {""},
#line 5402 "nasdaq.gperf"
      {"WRD", 5389},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2013 "nasdaq.gperf"
      {"GAME", 2000},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5152 "nasdaq.gperf"
      {"USMC", 5139},
      {""}, {""}, {""},
#line 2137 "nasdaq.gperf"
      {"GOOD", 2124},
      {""},
#line 3364 "nasdaq.gperf"
      {"NBIS", 3351},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 106 "nasdaq.gperf"
      {"ADAML", 93},
      {""}, {""}, {""},
#line 2650 "nasdaq.gperf"
      {"ITG", 2637},
      {""}, {""}, {""}, {""}, {""},
#line 4272 "nasdaq.gperf"
      {"RILY", 4259},
      {""}, {""},
#line 1768 "nasdaq.gperf"
      {"FDIV", 1755},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4051 "nasdaq.gperf"
      {"PWRD", 4038},
      {""},
#line 4277 "nasdaq.gperf"
      {"RILYT", 4264},
      {""}, {""}, {""}, {""},
#line 4278 "nasdaq.gperf"
      {"RILYZ", 4265},
      {""},
#line 5340 "nasdaq.gperf"
      {"WBD", 5327},
      {""}, {""}, {""}, {""}, {""},
#line 3777 "nasdaq.gperf"
      {"PAVM", 3764},
      {""},
#line 559 "nasdaq.gperf"
      {"BASV", 546},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1605 "nasdaq.gperf"
      {"EMXF", 1592},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4773 "nasdaq.gperf"
      {"SVRA", 4760},
      {""}, {""}, {""}, {""},
#line 1644 "nasdaq.gperf"
      {"ESCA", 1631},
      {""}, {""}, {""}, {""}, {""},
#line 77 "nasdaq.gperf"
      {"ACIU", 64},
      {""},
#line 2961 "nasdaq.gperf"
      {"LNAI", 2948},
      {""},
#line 4461 "nasdaq.gperf"
      {"SEIE", 4448},
      {""}, {""}, {""}, {""}, {""},
#line 828 "nasdaq.gperf"
      {"BSJU", 815},
      {""}, {""},
#line 2281 "nasdaq.gperf"
      {"HDRNW", 2268},
      {""}, {""},
#line 4186 "nasdaq.gperf"
      {"RBIL", 4173},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2960 "nasdaq.gperf"
      {"LMTL", 2947},
#line 2358 "nasdaq.gperf"
      {"HSCS", 2345},
      {""},
#line 1477 "nasdaq.gperf"
      {"DTCX", 1464},
      {""}, {""}, {""}, {""},
#line 4169 "nasdaq.gperf"
      {"RAIL", 4156},
      {""}, {""}, {""},
#line 3419 "nasdaq.gperf"
      {"NEXR", 3406},
#line 1080 "nasdaq.gperf"
      {"CHRS", 1067},
#line 2434 "nasdaq.gperf"
      {"IBGB", 2421},
      {""},
#line 5044 "nasdaq.gperf"
      {"TURF", 5031},
#line 5032 "nasdaq.gperf"
      {"TTD", 5019},
      {""}, {""},
#line 4342 "nasdaq.gperf"
      {"RRGB", 4329},
      {""},
#line 5401 "nasdaq.gperf"
      {"WRAP", 5388},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 425 "nasdaq.gperf"
      {"ASBP", 412},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 362 "nasdaq.gperf"
      {"APOG", 349},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4496 "nasdaq.gperf"
      {"SHBI", 4483},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2047 "nasdaq.gperf"
      {"GEME", 2034},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5485 "nasdaq.gperf"
      {"XPEL", 5472},
#line 2462 "nasdaq.gperf"
      {"ICLR", 2449},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2140 "nasdaq.gperf"
      {"GOOG", 2127},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 833 "nasdaq.gperf"
      {"BSMQ", 820},
      {""}, {""}, {""}, {""}, {""},
#line 4276 "nasdaq.gperf"
      {"RILYP", 4263},
#line 430 "nasdaq.gperf"
      {"ASLE", 417},
      {""},
#line 1133 "nasdaq.gperf"
      {"CLYM", 1120},
      {""}, {""},
#line 809 "nasdaq.gperf"
      {"BSCQ", 796},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4425 "nasdaq.gperf"
      {"SCKT", 4412},
      {""},
#line 1049 "nasdaq.gperf"
      {"CGON", 1036},
      {""},
#line 4777 "nasdaq.gperf"
      {"SWAG", 4764},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 26 "nasdaq.gperf"
      {"AAEQ", 13},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3279 "nasdaq.gperf"
      {"MSTP", 3266},
#line 4880 "nasdaq.gperf"
      {"TFSL", 4867},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 846 "nasdaq.gperf"
      {"BSTU", 833},
      {""},
#line 4256 "nasdaq.gperf"
      {"RGLD", 4243},
#line 4898 "nasdaq.gperf"
      {"TIGO", 4885},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3356 "nasdaq.gperf"
      {"NATR", 3343},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5219 "nasdaq.gperf"
      {"VFLO", 5206},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2501 "nasdaq.gperf"
      {"III", 2488},
      {""},
#line 536 "nasdaq.gperf"
      {"AZIO", 523},
      {""}, {""},
#line 4791 "nasdaq.gperf"
      {"SYBT", 4778},
      {""},
#line 4684 "nasdaq.gperf"
      {"SQFTW", 4671},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3494 "nasdaq.gperf"
      {"NRSNW", 3481},
      {""},
#line 4219 "nasdaq.gperf"
      {"RDZNW", 4206},
      {""}, {""}, {""}, {""},
#line 1986 "nasdaq.gperf"
      {"FVN", 1973},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2117 "nasdaq.gperf"
      {"GLUE", 2104},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2980 "nasdaq.gperf"
      {"LPAA", 2967},
#line 2981 "nasdaq.gperf"
      {"LPAAU", 2968},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 824 "nasdaq.gperf"
      {"BSJQ", 811},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4768 "nasdaq.gperf"
      {"SVCCW", 4755},
      {""},
#line 2640 "nasdaq.gperf"
      {"ISNR", 2627},
#line 2641 "nasdaq.gperf"
      {"ISNRU", 2628},
#line 3275 "nasdaq.gperf"
      {"MSLE", 3262},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5113 "nasdaq.gperf"
      {"UMBF", 5100},
      {""}, {""}, {""},
#line 1079 "nasdaq.gperf"
      {"CHRN", 1066},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1754 "nasdaq.gperf"
      {"FCNCA", 1741},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5287 "nasdaq.gperf"
      {"VRRM", 5274},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1657 "nasdaq.gperf"
      {"ESTA", 1644},
      {""},
#line 2964 "nasdaq.gperf"
      {"LNT", 2951},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4757 "nasdaq.gperf"
      {"SURG", 4744},
#line 2971 "nasdaq.gperf"
      {"LOGI", 2958},
      {""}, {""}, {""}, {""},
#line 3785 "nasdaq.gperf"
      {"PBEU", 3772},
      {""}, {""}, {""}, {""},
#line 5163 "nasdaq.gperf"
      {"UTMD", 5150},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 193 "nasdaq.gperf"
      {"AIFD", 180},
      {""}, {""}, {""}, {""},
#line 191 "nasdaq.gperf"
      {"AIFA", 178},
      {""}, {""},
#line 1911 "nasdaq.gperf"
      {"FRMM", 1898},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 192 "nasdaq.gperf"
      {"AIFC", 179},
#line 2507 "nasdaq.gperf"
      {"ILLR", 2494},
      {""},
#line 3451 "nasdaq.gperf"
      {"NIXT", 3438},
      {""}, {""}, {""}, {""}, {""},
#line 1333 "nasdaq.gperf"
      {"CYAB", 1320},
#line 2706 "nasdaq.gperf"
      {"JHAI", 2693},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1769 "nasdaq.gperf"
      {"FDMM", 1756},
#line 1770 "nasdaq.gperf"
      {"FDMMU", 1757},
      {""},
#line 4254 "nasdaq.gperf"
      {"RGCO", 4241},
      {""}, {""},
#line 5454 "nasdaq.gperf"
      {"XCH", 5441},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4779 "nasdaq.gperf"
      {"SWBI", 4766},
#line 2920 "nasdaq.gperf"
      {"LGVN", 2907},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1976 "nasdaq.gperf"
      {"FUND", 1963},
      {""}, {""}, {""}, {""},
#line 3380 "nasdaq.gperf"
      {"NCNO", 3367},
      {""}, {""},
#line 3041 "nasdaq.gperf"
      {"LZ", 3028},
      {""}, {""},
#line 2570 "nasdaq.gperf"
      {"INSG", 2557},
      {""}, {""}, {""},
#line 1975 "nasdaq.gperf"
      {"FUNC", 1962},
#line 2869 "nasdaq.gperf"
      {"LBGJ", 2856},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4708 "nasdaq.gperf"
      {"SSP", 4695},
#line 915 "nasdaq.gperf"
      {"CAIQ", 902},
#line 3467 "nasdaq.gperf"
      {"NN", 3454},
#line 2245 "nasdaq.gperf"
      {"HAS", 2232},
#line 5397 "nasdaq.gperf"
      {"WOK", 5384},
      {""}, {""},
#line 4793 "nasdaq.gperf"
      {"SYNA", 4780},
      {""}, {""}, {""}, {""},
#line 1643 "nasdaq.gperf"
      {"ERNAW", 1630},
      {""},
#line 2078 "nasdaq.gperf"
      {"GIBO", 2065},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 74 "nasdaq.gperf"
      {"ACHC", 61},
      {""}, {""}, {""},
#line 4430 "nasdaq.gperf"
      {"SCOR", 4417},
#line 2634 "nasdaq.gperf"
      {"IRON", 2621},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1996 "nasdaq.gperf"
      {"FWRD", 1983},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4274 "nasdaq.gperf"
      {"RILYL", 4261},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2935 "nasdaq.gperf"
      {"LIN", 2922},
#line 2937 "nasdaq.gperf"
      {"LIND", 2924},
      {""}, {""}, {""}, {""},
#line 5434 "nasdaq.gperf"
      {"WVVI", 5421},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2464 "nasdaq.gperf"
      {"ICON", 2451},
      {""}, {""},
#line 2936 "nasdaq.gperf"
      {"LINC", 2923},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 670 "nasdaq.gperf"
      {"BIOA", 657},
      {""}, {""}, {""}, {""},
#line 673 "nasdaq.gperf"
      {"BIOX", 660},
      {""}, {""},
#line 1097 "nasdaq.gperf"
      {"CIGL", 1084},
      {""}, {""},
#line 4685 "nasdaq.gperf"
      {"SQLV", 4672},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5303 "nasdaq.gperf"
      {"VSOL", 5290},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3449 "nasdaq.gperf"
      {"NIVF", 3436},
      {""},
#line 4839 "nasdaq.gperf"
      {"TCHI", 4826},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3502 "nasdaq.gperf"
      {"NSSC", 3489},
      {""}, {""}, {""},
#line 2608 "nasdaq.gperf"
      {"IPSC", 2595},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2099 "nasdaq.gperf"
      {"GLBE", 2086},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4198 "nasdaq.gperf"
      {"RCON", 4185},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2276 "nasdaq.gperf"
      {"HCSG", 2263},
      {""}, {""}, {""}, {""},
#line 2041 "nasdaq.gperf"
      {"GECCH", 2028},
      {""}, {""}, {""}, {""}, {""},
#line 1781 "nasdaq.gperf"
      {"FEAM", 1768},
      {""}, {""},
#line 4178 "nasdaq.gperf"
      {"RARE", 4165},
      {""}, {""}, {""}, {""},
#line 2707 "nasdaq.gperf"
      {"JIVE", 2694},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1947 "nasdaq.gperf"
      {"FTFT", 1934},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2705 "nasdaq.gperf"
      {"JGLO", 2692},
      {""},
#line 4035 "nasdaq.gperf"
      {"PTNQ", 4022},
      {""}, {""},
#line 2083 "nasdaq.gperf"
      {"GIII", 2070},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 859 "nasdaq.gperf"
      {"BTF", 846},
      {""}, {""}, {""}, {""},
#line 3520 "nasdaq.gperf"
      {"NTRSO", 3507},
#line 2141 "nasdaq.gperf"
      {"GOOGL", 2128},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1997 "nasdaq.gperf"
      {"FWRG", 1984},
      {""},
#line 3100 "nasdaq.gperf"
      {"MCHX", 3087},
      {""},
#line 1460 "nasdaq.gperf"
      {"DRS", 1447},
      {""},
#line 5092 "nasdaq.gperf"
      {"UCYB", 5079},
      {""}, {""}, {""}, {""}, {""},
#line 3096 "nasdaq.gperf"
      {"MCHI", 3083},
      {""}, {""},
#line 2911 "nasdaq.gperf"
      {"LGCF", 2898},
      {""}, {""}, {""}, {""}, {""},
#line 5435 "nasdaq.gperf"
      {"WVVIP", 5422},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4950 "nasdaq.gperf"
      {"TNON", 4937},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5536 "nasdaq.gperf"
      {"YNOT", 5523},
      {""},
#line 1094 "nasdaq.gperf"
      {"CIFG", 1081},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4718 "nasdaq.gperf"
      {"STFS", 4705},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2443 "nasdaq.gperf"
      {"IBOT", 2430},
#line 5588 "nasdaq.gperf"
      {"ZTWO", 5575},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 271 "nasdaq.gperf"
      {"ALRM", 258},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 931 "nasdaq.gperf"
      {"CAQUU", 918},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4329 "nasdaq.gperf"
      {"ROOT", 4316},
      {""}, {""}, {""},
#line 3482 "nasdaq.gperf"
      {"NPAC", 3469},
#line 3483 "nasdaq.gperf"
      {"NPACU", 3470},
      {""},
#line 410 "nasdaq.gperf"
      {"ARQQ", 397},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1992 "nasdaq.gperf"
      {"FWACW", 1979},
      {""}, {""}, {""},
#line 244 "nasdaq.gperf"
      {"ALHC", 231},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 90 "nasdaq.gperf"
      {"ACSP", 77},
      {""}, {""},
#line 5265 "nasdaq.gperf"
      {"VNMEW", 5252},
      {""}, {""},
#line 1574 "nasdaq.gperf"
      {"ELAB", 1561},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 86 "nasdaq.gperf"
      {"ACQQ", 73},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1019 "nasdaq.gperf"
      {"CENTA", 1006},
      {""}, {""}, {""},
#line 5486 "nasdaq.gperf"
      {"XPON", 5473},
#line 5167 "nasdaq.gperf"
      {"UTWY", 5154},
      {""}, {""}, {""},
#line 1888 "nasdaq.gperf"
      {"FOFO", 1875},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2055 "nasdaq.gperf"
      {"GEOS", 2042},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2209 "nasdaq.gperf"
      {"GTENW", 2196},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4530 "nasdaq.gperf"
      {"SION", 4517},
      {""}, {""}, {""},
#line 368 "nasdaq.gperf"
      {"APRE", 355},
#line 1467 "nasdaq.gperf"
      {"DSACW", 1454},
      {""}, {""}, {""},
#line 1899 "nasdaq.gperf"
      {"FPXE", 1886},
      {""},
#line 2279 "nasdaq.gperf"
      {"HDL", 2266},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 343 "nasdaq.gperf"
      {"AOHY", 330},
#line 2531 "nasdaq.gperf"
      {"IMSR", 2518},
#line 2497 "nasdaq.gperf"
      {"IGIC", 2484},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1256 "nasdaq.gperf"
      {"CRSP", 1243},
      {""},
#line 4012 "nasdaq.gperf"
      {"PSKY", 3999},
#line 3978 "nasdaq.gperf"
      {"PRHI", 3965},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3979 "nasdaq.gperf"
      {"PRHIZ", 3966},
      {""}, {""}, {""}, {""}, {""},
#line 751 "nasdaq.gperf"
      {"BOKF", 738},
#line 674 "nasdaq.gperf"
      {"BIOY", 661},
#line 4505 "nasdaq.gperf"
      {"SHMDW", 4492},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 442 "nasdaq.gperf"
      {"ASPSW", 429},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3580 "nasdaq.gperf"
      {"NZAC", 3567},
      {""}, {""}, {""},
#line 5158 "nasdaq.gperf"
      {"USVN", 5145},
      {""}, {""},
#line 5386 "nasdaq.gperf"
      {"WLDS", 5373},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3787 "nasdaq.gperf"
      {"PBHC", 3774},
#line 4776 "nasdaq.gperf"
      {"SVRN", 4763},
      {""}, {""}, {""}, {""}, {""},
#line 145 "nasdaq.gperf"
      {"AESP", 132},
#line 147 "nasdaq.gperf"
      {"AESPU", 134},
      {""},
#line 2068 "nasdaq.gperf"
      {"GGAL", 2055},
      {""}, {""},
#line 146 "nasdaq.gperf"
      {"AESPR", 133},
      {""},
#line 3758 "nasdaq.gperf"
      {"PAHC", 3745},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 109 "nasdaq.gperf"
      {"ADAMO", 96},
      {""}, {""}, {""},
#line 2934 "nasdaq.gperf"
      {"LIMNW", 2921},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1827 "nasdaq.gperf"
      {"FIMU", 1814},
      {""}, {""}, {""}, {""}, {""},
#line 4032 "nasdaq.gperf"
      {"PTLE", 4019},
      {""},
#line 1332 "nasdaq.gperf"
      {"CXSE", 1319},
#line 2085 "nasdaq.gperf"
      {"GILT", 2072},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 35 "nasdaq.gperf"
      {"AAPL", 22},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2215 "nasdaq.gperf"
      {"GTLB", 2202},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 884 "nasdaq.gperf"
      {"BWB", 871},
      {""}, {""},
#line 3338 "nasdaq.gperf"
      {"MYSZ", 3325},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 883 "nasdaq.gperf"
      {"BWAY", 870},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1036 "nasdaq.gperf"
      {"CFO", 1023},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2533 "nasdaq.gperf"
      {"IMTE", 2520},
      {""}, {""},
#line 4514 "nasdaq.gperf"
      {"SHRY", 4501},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3487 "nasdaq.gperf"
      {"NPT", 3474},
      {""}, {""},
#line 5085 "nasdaq.gperf"
      {"UBSI", 5072},
      {""}, {""}, {""}, {""}, {""},
#line 1024 "nasdaq.gperf"
      {"CEPO", 1011},
      {""}, {""}, {""}, {""},
#line 821 "nasdaq.gperf"
      {"BSGR", 808},
      {""},
#line 721 "nasdaq.gperf"
      {"BLZRW", 708},
      {""},
#line 5429 "nasdaq.gperf"
      {"WTMU", 5416},
      {""}, {""},
#line 3065 "nasdaq.gperf"
      {"MAZE", 3052},
#line 1545 "nasdaq.gperf"
      {"EDSA", 1532},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 842 "nasdaq.gperf"
      {"BSP", 829},
      {""},
#line 893 "nasdaq.gperf"
      {"BYND", 880},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5333 "nasdaq.gperf"
      {"WARP", 5320},
#line 3005 "nasdaq.gperf"
      {"LSE", 2992},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 515 "nasdaq.gperf"
      {"AVS", 502},
      {""}, {""}, {""},
#line 2126 "nasdaq.gperf"
      {"GNLX", 2113},
#line 401 "nasdaq.gperf"
      {"ARHS", 388},
#line 4612 "nasdaq.gperf"
      {"SNOA", 4599},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2916 "nasdaq.gperf"
      {"LGN", 2903},
#line 2917 "nasdaq.gperf"
      {"LGND", 2904},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3989 "nasdaq.gperf"
      {"PRPO", 3976},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 549 "nasdaq.gperf"
      {"BAIV", 536},
      {""}, {""},
#line 3398 "nasdaq.gperf"
      {"NEGG", 3385},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1693 "nasdaq.gperf"
      {"EXC", 1680},
      {""}, {""}, {""},
#line 5233 "nasdaq.gperf"
      {"VHUB", 5220},
      {""}, {""},
#line 2115 "nasdaq.gperf"
      {"GLRE", 2102},
#line 404 "nasdaq.gperf"
      {"ARLP", 391},
#line 1354 "nasdaq.gperf"
      {"DALI", 1341},
      {""}, {""}, {""},
#line 5136 "nasdaq.gperf"
      {"USAF", 5123},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5239 "nasdaq.gperf"
      {"VIP", 5226},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1988 "nasdaq.gperf"
      {"FVNNU", 1975},
      {""}, {""}, {""}, {""},
#line 1987 "nasdaq.gperf"
      {"FVNNR", 1974},
#line 5385 "nasdaq.gperf"
      {"WLDN", 5372},
#line 5159 "nasdaq.gperf"
      {"USXF", 5146},
      {""},
#line 2070 "nasdaq.gperf"
      {"GGLS", 2057},
      {""},
#line 4614 "nasdaq.gperf"
      {"SNSR", 4601},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4283 "nasdaq.gperf"
      {"RITR", 4270},
#line 1767 "nasdaq.gperf"
      {"FDIQ", 1754},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2986 "nasdaq.gperf"
      {"LPCN", 2973},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4969 "nasdaq.gperf"
      {"TRAW", 4956},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2902 "nasdaq.gperf"
      {"LFMD", 2889},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2898 "nasdaq.gperf"
      {"LFAC", 2885},
#line 2899 "nasdaq.gperf"
      {"LFACU", 2886},
      {""}, {""}, {""}, {""}, {""},
#line 205 "nasdaq.gperf"
      {"AIP", 192},
#line 3794 "nasdaq.gperf"
      {"PBQQ", 3781},
      {""}, {""}, {""}, {""},
#line 2284 "nasdaq.gperf"
      {"HECO", 2271},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 206 "nasdaq.gperf"
      {"AIPI", 193},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2910 "nasdaq.gperf"
      {"LFWD", 2897},
      {""}, {""}, {""},
#line 2359 "nasdaq.gperf"
      {"HSCSW", 2346},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3420 "nasdaq.gperf"
      {"NEXRW", 3407},
      {""},
#line 5395 "nasdaq.gperf"
      {"WNEB", 5382},
      {""}, {""},
#line 1845 "nasdaq.gperf"
      {"FLDB", 1832},
      {""},
#line 894 "nasdaq.gperf"
      {"BYRN", 881},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 426 "nasdaq.gperf"
      {"ASBPW", 413},
#line 2193 "nasdaq.gperf"
      {"GSIB", 2180},
      {""}, {""}, {""},
#line 1410 "nasdaq.gperf"
      {"DJCO", 1397},
      {""}, {""},
#line 4899 "nasdaq.gperf"
      {"TIGR", 4886},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1443 "nasdaq.gperf"
      {"DOMO", 1430},
      {""}, {""}, {""}, {""},
#line 2793 "nasdaq.gperf"
      {"KLXE", 2780},
#line 1023 "nasdaq.gperf"
      {"CEPL", 1010},
      {""}, {""}, {""}, {""},
#line 2794 "nasdaq.gperf"
      {"KLXER", 2781},
#line 4188 "nasdaq.gperf"
      {"RBNE", 4175},
      {""},
#line 3099 "nasdaq.gperf"
      {"MCHS", 3086},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 329 "nasdaq.gperf"
      {"ANGO", 316},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2342 "nasdaq.gperf"
      {"HOWL", 2329},
      {""}, {""}, {""}, {""},
#line 3056 "nasdaq.gperf"
      {"MARPS", 3043},
      {""}, {""},
#line 3516 "nasdaq.gperf"
      {"NTRB", 3503},
#line 2282 "nasdaq.gperf"
      {"HDSN", 2269},
      {""}, {""},
#line 2130 "nasdaq.gperf"
      {"GNSS", 2117},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2517 "nasdaq.gperf"
      {"IMCV", 2504},
      {""}, {""}, {""}, {""}, {""},
#line 2903 "nasdaq.gperf"
      {"LFMDP", 2890},
      {""}, {""},
#line 3988 "nasdaq.gperf"
      {"PRPL", 3975},
#line 1889 "nasdaq.gperf"
      {"FORM", 1876},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 702 "nasdaq.gperf"
      {"BLIV", 689},
#line 1237 "nasdaq.gperf"
      {"CRDO", 1224},
      {""}, {""}, {""},
#line 4778 "nasdaq.gperf"
      {"SWAGW", 4765},
#line 1907 "nasdaq.gperf"
      {"FRHC", 1894},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5436 "nasdaq.gperf"
      {"WW", 5423},
      {""}, {""}, {""}, {""}, {""},
#line 5422 "nasdaq.gperf"
      {"WTF", 5409},
      {""}, {""}, {""},
#line 3513 "nasdaq.gperf"
      {"NTLA", 3500},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4472 "nasdaq.gperf"
      {"SETM", 4459},
      {""}, {""}, {""}, {""},
#line 5423 "nasdaq.gperf"
      {"WTFC", 5410},
      {""},
#line 1165 "nasdaq.gperf"
      {"CNXU", 1152},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5518 "nasdaq.gperf"
      {"YDDL", 5505},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2420 "nasdaq.gperf"
      {"IACQ", 2407},
#line 2421 "nasdaq.gperf"
      {"IACQU", 2408},
      {""}, {""}, {""},
#line 2526 "nasdaq.gperf"
      {"IMOS", 2513},
#line 5089 "nasdaq.gperf"
      {"UCL", 5076},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2891 "nasdaq.gperf"
      {"LEGN", 2878},
      {""}, {""}, {""}, {""}, {""},
#line 5541 "nasdaq.gperf"
      {"YQQQ", 5528},
      {""}, {""}, {""}, {""}, {""},
#line 2689 "nasdaq.gperf"
      {"JBLU", 2676},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4323 "nasdaq.gperf"
      {"ROCQ", 4310},
      {""},
#line 1985 "nasdaq.gperf"
      {"FVCB", 1972},
      {""},
#line 420 "nasdaq.gperf"
      {"ARTW", 407},
      {""},
#line 2139 "nasdaq.gperf"
      {"GOODO", 2126},
      {""}, {""}, {""},
#line 2765 "nasdaq.gperf"
      {"KEEL", 2752},
      {""},
#line 5081 "nasdaq.gperf"
      {"UAL", 5068},
      {""}, {""}, {""},
#line 2283 "nasdaq.gperf"
      {"HEAL", 2270},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2982 "nasdaq.gperf"
      {"LPAAW", 2969},
      {""}, {""}, {""},
#line 1375 "nasdaq.gperf"
      {"DECO", 1362},
      {""}, {""}, {""}, {""}, {""},
#line 1525 "nasdaq.gperf"
      {"EASY", 1512},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2458 "nasdaq.gperf"
      {"ICFI", 2445},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2642 "nasdaq.gperf"
      {"ISNRW", 2629},
#line 4666 "nasdaq.gperf"
      {"SPOG", 4653},
      {""},
#line 2437 "nasdaq.gperf"
      {"IBGL", 2424},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 508 "nasdaq.gperf"
      {"AVL", 495},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2843 "nasdaq.gperf"
      {"KXIN", 2830},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2257 "nasdaq.gperf"
      {"HBNB", 2244},
      {""},
#line 155 "nasdaq.gperf"
      {"AFOS", 142},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 889 "nasdaq.gperf"
      {"BWMN", 876},
      {""}, {""}, {""},
#line 2597 "nasdaq.gperf"
      {"IPEX", 2584},
#line 2599 "nasdaq.gperf"
      {"IPEXU", 2586},
      {""}, {""}, {""}, {""},
#line 2598 "nasdaq.gperf"
      {"IPEXR", 2585},
      {""}, {""},
#line 328 "nasdaq.gperf"
      {"ANGL", 315},
      {""}, {""}, {""},
#line 2267 "nasdaq.gperf"
      {"HCIC", 2254},
#line 2269 "nasdaq.gperf"
      {"HCICU", 2256},
      {""}, {""},
#line 2312 "nasdaq.gperf"
      {"HLAL", 2299},
      {""},
#line 2268 "nasdaq.gperf"
      {"HCICR", 2255},
      {""},
#line 2302 "nasdaq.gperf"
      {"HIMX", 2289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 194 "nasdaq.gperf"
      {"AIFF", 181},
      {""}, {""}, {""}, {""}, {""},
#line 2303 "nasdaq.gperf"
      {"HIMZ", 2290},
      {""},
#line 2940 "nasdaq.gperf"
      {"LINT", 2927},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2508 "nasdaq.gperf"
      {"ILLRW", 2495},
#line 4967 "nasdaq.gperf"
      {"TQQQ", 4954},
      {""}, {""}, {""}, {""},
#line 4753 "nasdaq.gperf"
      {"SUNS", 4740},
      {""},
#line 1945 "nasdaq.gperf"
      {"FTDS", 1932},
      {""}, {""},
#line 671 "nasdaq.gperf"
      {"BIOT", 658},
      {""}, {""}, {""}, {""}, {""},
#line 1771 "nasdaq.gperf"
      {"FDMMW", 1758},
#line 2135 "nasdaq.gperf"
      {"GOGO", 2122},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3321 "nasdaq.gperf"
      {"MYCO", 3308},
      {""}, {""}, {""},
#line 3523 "nasdaq.gperf"
      {"NTWO", 3510},
#line 3524 "nasdaq.gperf"
      {"NTWOU", 3511},
      {""}, {""},
#line 72 "nasdaq.gperf"
      {"ACGLN", 59},
      {""},
#line 1236 "nasdaq.gperf"
      {"CRDL", 1223},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2609 "nasdaq.gperf"
      {"IPST", 2596},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 550 "nasdaq.gperf"
      {"BALQ", 537},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5412 "nasdaq.gperf"
      {"WSFS", 5399},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3952 "nasdaq.gperf"
      {"POWW", 3939},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3972 "nasdaq.gperf"
      {"PRDO", 3959},
      {""}, {""},
#line 2482 "nasdaq.gperf"
      {"IEF", 2469},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3229 "nasdaq.gperf"
      {"MODL", 3216},
#line 1595 "nasdaq.gperf"
      {"EMCB", 1582},
      {""},
#line 1367 "nasdaq.gperf"
      {"DCBO", 1354},
      {""},
#line 3497 "nasdaq.gperf"
      {"NSI", 3484},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2079 "nasdaq.gperf"
      {"GIBOW", 2066},
      {""}, {""}, {""},
#line 2823 "nasdaq.gperf"
      {"KROS", 2810},
      {""}, {""}, {""}, {""}, {""},
#line 1653 "nasdaq.gperf"
      {"ESN", 1640},
      {""},
#line 907 "nasdaq.gperf"
      {"CADL", 894},
#line 610 "nasdaq.gperf"
      {"BEAM", 597},
      {""},
#line 4255 "nasdaq.gperf"
      {"RGEN", 4242},
#line 3242 "nasdaq.gperf"
      {"MQQQ", 3229},
      {""}, {""}, {""}, {""},
#line 1511 "nasdaq.gperf"
      {"DXR", 1498},
      {""},
#line 3062 "nasdaq.gperf"
      {"MATW", 3049},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 402 "nasdaq.gperf"
      {"ARKO", 389},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4618 "nasdaq.gperf"
      {"SNWV", 4605},
#line 4481 "nasdaq.gperf"
      {"SFLO", 4468},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5043 "nasdaq.gperf"
      {"TURB", 5030},
      {""}, {""},
#line 4047 "nasdaq.gperf"
      {"PUSA", 4034},
#line 2454 "nasdaq.gperf"
      {"IBTQ", 2441},
      {""}, {""}, {""}, {""}, {""},
#line 4335 "nasdaq.gperf"
      {"RPID", 4322},
      {""},
#line 4225 "nasdaq.gperf"
      {"REFI", 4212},
      {""}, {""},
#line 2673 "nasdaq.gperf"
      {"IZEA", 2660},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2802 "nasdaq.gperf"
      {"KNSA", 2789},
      {""}, {""}, {""}, {""},
#line 4554 "nasdaq.gperf"
      {"SLDB", 4541},
      {""},
#line 65 "nasdaq.gperf"
      {"ACEP", 52},
      {""},
#line 3450 "nasdaq.gperf"
      {"NIVFW", 3437},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 190 "nasdaq.gperf"
      {"AIDX", 177},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2429 "nasdaq.gperf"
      {"IBBQ", 2416},
      {""},
#line 1372 "nasdaq.gperf"
      {"DDI", 1359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 798 "nasdaq.gperf"
      {"BRTMU", 785},
      {""}, {""},
#line 3953 "nasdaq.gperf"
      {"POWWP", 3940},
      {""}, {""}, {""}, {""}, {""},
#line 5114 "nasdaq.gperf"
      {"UMBFO", 5101},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3505 "nasdaq.gperf"
      {"NTAL", 3492},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3507 "nasdaq.gperf"
      {"NTCL", 3494},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1349 "nasdaq.gperf"
      {"DAIC", 1336},
      {""}, {""},
#line 5416 "nasdaq.gperf"
      {"WSPC", 5403},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3318 "nasdaq.gperf"
      {"MYCL", 3305},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2065 "nasdaq.gperf"
      {"GFS", 2052},
      {""}, {""},
#line 2568 "nasdaq.gperf"
      {"INRO", 2555},
      {""},
#line 1409 "nasdaq.gperf"
      {"DIVD", 1396},
      {""}, {""}, {""}, {""},
#line 4951 "nasdaq.gperf"
      {"TNONW", 4938},
      {""},
#line 1702 "nasdaq.gperf"
      {"EXUS", 1689},
      {""}, {""}, {""}, {""}, {""},
#line 1315 "nasdaq.gperf"
      {"CVCO", 1302},
      {""}, {""}, {""},
#line 2307 "nasdaq.gperf"
      {"HIT", 2294},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4444 "nasdaq.gperf"
      {"SDHI", 4431},
#line 4446 "nasdaq.gperf"
      {"SDHIU", 4433},
      {""}, {""}, {""}, {""},
#line 4445 "nasdaq.gperf"
      {"SDHIR", 4432},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2308 "nasdaq.gperf"
      {"HITI", 2295},
      {""},
#line 1874 "nasdaq.gperf"
      {"FMTM", 1861},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 971 "nasdaq.gperf"
      {"CCEP", 958},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4980 "nasdaq.gperf"
      {"TRIP", 4967},
      {""}, {""}, {""}, {""},
#line 3819 "nasdaq.gperf"
      {"PDDL", 3806},
      {""}, {""}, {""}, {""}, {""},
#line 932 "nasdaq.gperf"
      {"CAQUW", 919},
      {""}, {""},
#line 2561 "nasdaq.gperf"
      {"INLF", 2548},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 749 "nasdaq.gperf"
      {"BOEU", 736},
      {""}, {""}, {""},
#line 3049 "nasdaq.gperf"
      {"MAKO", 3036},
#line 3169 "nasdaq.gperf"
      {"MIDD", 3156},
      {""}, {""}, {""}, {""}, {""},
#line 3484 "nasdaq.gperf"
      {"NPACW", 3471},
      {""}, {""},
#line 411 "nasdaq.gperf"
      {"ARQQW", 398},
      {""}, {""}, {""}, {""}, {""},
#line 5009 "nasdaq.gperf"
      {"TSCM", 4996},
      {""}, {""}, {""}, {""},
#line 2908 "nasdaq.gperf"
      {"LFUS", 2895},
      {""}, {""}, {""},
#line 5584 "nasdaq.gperf"
      {"ZTEN", 5571},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4048 "nasdaq.gperf"
      {"PVLA", 4035},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 521 "nasdaq.gperf"
      {"AVXL", 508},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2748 "nasdaq.gperf"
      {"KBON", 2735},
#line 2749 "nasdaq.gperf"
      {"KBONU", 2736},
      {""}, {""}, {""},
#line 928 "nasdaq.gperf"
      {"CAPR", 915},
      {""}, {""}, {""}, {""}, {""},
#line 5247 "nasdaq.gperf"
      {"VKTX", 5234},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2546 "nasdaq.gperf"
      {"INCR", 2533},
      {""}, {""},
#line 2125 "nasdaq.gperf"
      {"GNLN", 2112},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3159 "nasdaq.gperf"
      {"MGPI", 3146},
      {""}, {""}, {""}, {""}, {""},
#line 1296 "nasdaq.gperf"
      {"CTOR", 1283},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5080 "nasdaq.gperf"
      {"UAE", 5067},
      {""},
#line 5019 "nasdaq.gperf"
      {"TSLQ", 5006},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1086 "nasdaq.gperf"
      {"CHSCP", 1073},
      {""}, {""}, {""},
#line 2157 "nasdaq.gperf"
      {"GPIX", 2144},
      {""},
#line 1912 "nasdaq.gperf"
      {"FRNM", 1899},
      {""}, {""},
#line 5538 "nasdaq.gperf"
      {"YORW", 5525},
      {""},
#line 2532 "nasdaq.gperf"
      {"IMSRW", 2519},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 227 "nasdaq.gperf"
      {"AKTX", 214},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5514 "nasdaq.gperf"
      {"YARW", 5501},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5469 "nasdaq.gperf"
      {"XHLD", 5456},
#line 3568 "nasdaq.gperf"
      {"NXL", 3555},
      {""},
#line 3512 "nasdaq.gperf"
      {"NTIC", 3499},
      {""},
#line 3691 "nasdaq.gperf"
      {"ORCX", 3678},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3007 "nasdaq.gperf"
      {"LSTR", 2994},
#line 225 "nasdaq.gperf"
      {"AKBA", 212},
      {""}, {""}, {""}, {""},
#line 5305 "nasdaq.gperf"
      {"VSTM", 5292},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3595 "nasdaq.gperf"
      {"OCC", 3582},
      {""}, {""},
#line 307 "nasdaq.gperf"
      {"AMPL", 294},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3586 "nasdaq.gperf"
      {"OBA", 3573},
      {""},
#line 5387 "nasdaq.gperf"
      {"WLDSW", 5374},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3596 "nasdaq.gperf"
      {"OCCI", 3583},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4043 "nasdaq.gperf"
      {"PUL", 4030},
#line 148 "nasdaq.gperf"
      {"AESPW", 135},
      {""},
#line 3587 "nasdaq.gperf"
      {"OBAI", 3574},
      {""}, {""},
#line 1823 "nasdaq.gperf"
      {"FIGR", 1810},
      {""}, {""}, {""}, {""}, {""},
#line 3594 "nasdaq.gperf"
      {"OBX", 3581},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1625 "nasdaq.gperf"
      {"EOLS", 1612},
#line 1831 "nasdaq.gperf"
      {"FIP", 1818},
      {""}, {""},
#line 3583 "nasdaq.gperf"
      {"OACC", 3570},
#line 3584 "nasdaq.gperf"
      {"OACCU", 3571},
      {""},
#line 1639 "nasdaq.gperf"
      {"ERIC", 1626},
      {""}, {""}, {""},
#line 2777 "nasdaq.gperf"
      {"KGEI", 2764},
#line 1641 "nasdaq.gperf"
      {"ERII", 1628},
      {""},
#line 4519 "nasdaq.gperf"
      {"SIFY", 4506},
      {""}, {""},
#line 2291 "nasdaq.gperf"
      {"HERO", 2278},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2340 "nasdaq.gperf"
      {"HOVR", 2327},
      {""}, {""}, {""}, {""}, {""},
#line 2909 "nasdaq.gperf"
      {"LFVN", 2896},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2895 "nasdaq.gperf"
      {"LESL", 2882},
      {""},
#line 2338 "nasdaq.gperf"
      {"HOUR", 2325},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3877 "nasdaq.gperf"
      {"PID", 3864},
      {""}, {""}, {""}, {""},
#line 3885 "nasdaq.gperf"
      {"PKW", 3872},
      {""}, {""},
#line 1528 "nasdaq.gperf"
      {"EBI", 1515},
      {""},
#line 2737 "nasdaq.gperf"
      {"JYNT", 2724},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3185 "nasdaq.gperf"
      {"MKTX", 3172},
      {""}, {""},
#line 1529 "nasdaq.gperf"
      {"EBIZ", 1516},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2958 "nasdaq.gperf"
      {"LMNR", 2945},
      {""}, {""}, {""}, {""}, {""},
#line 1548 "nasdaq.gperf"
      {"EEE", 1535},
      {""}, {""},
#line 2595 "nasdaq.gperf"
      {"IPAR", 2582},
      {""}, {""},
#line 1603 "nasdaq.gperf"
      {"EMSC", 1590},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1703 "nasdaq.gperf"
      {"EXYN", 1690},
      {""}, {""},
#line 2732 "nasdaq.gperf"
      {"JUNS", 2719},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2614 "nasdaq.gperf"
      {"IPWR", 2601},
      {""}, {""}, {""},
#line 1540 "nasdaq.gperf"
      {"EDBL", 1527},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4379 "nasdaq.gperf"
      {"RZLT", 4366},
#line 2349 "nasdaq.gperf"
      {"HQI", 2336},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4037 "nasdaq.gperf"
      {"PTOR", 4024},
#line 4038 "nasdaq.gperf"
      {"PTORU", 4025},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2576 "nasdaq.gperf"
      {"INTR", 2563},
#line 4004 "nasdaq.gperf"
      {"PSCM", 3991},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5578 "nasdaq.gperf"
      {"ZOOZ", 5565},
#line 5094 "nasdaq.gperf"
      {"UEIC", 5081},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4134 "nasdaq.gperf"
      {"QRMI", 4121},
      {""}, {""},
#line 3306 "nasdaq.gperf"
      {"MVST", 3293},
      {""}, {""}, {""},
#line 1577 "nasdaq.gperf"
      {"ELE", 1564},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 183 "nasdaq.gperf"
      {"AHCO", 170},
      {""},
#line 1312 "nasdaq.gperf"
      {"CUVL", 1299},
#line 4078 "nasdaq.gperf"
      {"QCMD", 4065},
      {""},
#line 3427 "nasdaq.gperf"
      {"NFXS", 3414},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4069 "nasdaq.gperf"
      {"QB", 4056},
      {""}, {""},
#line 25 "nasdaq.gperf"
      {"AADR", 12},
      {""}, {""}, {""},
#line 3425 "nasdaq.gperf"
      {"NFTY", 3412},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4904 "nasdaq.gperf"
      {"TIPT", 4891},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4903 "nasdaq.gperf"
      {"TILE", 4890},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4330 "nasdaq.gperf"
      {"ROP", 4317},
      {""},
#line 4314 "nasdaq.gperf"
      {"RNIN", 4301},
#line 3639 "nasdaq.gperf"
      {"OLMA", 3626},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 488 "nasdaq.gperf"
      {"AUID", 475},
      {""},
#line 2053 "nasdaq.gperf"
      {"GENVR", 2040},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4108 "nasdaq.gperf"
      {"QOWZ", 4095},
#line 1082 "nasdaq.gperf"
      {"CHSCL", 1069},
      {""}, {""},
#line 2655 "nasdaq.gperf"
      {"ITOC", 2642},
      {""}, {""}, {""},
#line 338 "nasdaq.gperf"
      {"ANPA", 325},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3612 "nasdaq.gperf"
      {"ODTX", 3599},
      {""}, {""}, {""}, {""}, {""},
#line 2900 "nasdaq.gperf"
      {"LFACW", 2887},
      {""}, {""}, {""},
#line 1306 "nasdaq.gperf"
      {"CUE", 1293},
      {""}, {""}, {""}, {""}, {""},
#line 509 "nasdaq.gperf"
      {"AVLN", 496},
      {""}, {""}, {""},
#line 1400 "nasdaq.gperf"
      {"DGXX", 1387},
      {""}, {""},
#line 5555 "nasdaq.gperf"
      {"ZBIO", 5542},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3592 "nasdaq.gperf"
      {"OBT", 3579},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3688 "nasdaq.gperf"
      {"ORBX", 3675},
      {""},
#line 495 "nasdaq.gperf"
      {"AUTL", 482},
      {""}, {""},
#line 3593 "nasdaq.gperf"
      {"OBTC", 3580},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2171 "nasdaq.gperf"
      {"GRFS", 2158},
      {""}, {""}, {""},
#line 5561 "nasdaq.gperf"
      {"ZEO", 5548},
      {""}, {""}, {""},
#line 2160 "nasdaq.gperf"
      {"GPRO", 2147},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2241 "nasdaq.gperf"
      {"HAIN", 2228},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1059 "nasdaq.gperf"
      {"CHCO", 1046},
      {""}, {""}, {""},
#line 566 "nasdaq.gperf"
      {"BBH", 553},
      {""},
#line 2484 "nasdaq.gperf"
      {"IEP", 2471},
      {""}, {""},
#line 3201 "nasdaq.gperf"
      {"MMLP", 3188},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3581 "nasdaq.gperf"
      {"OABI", 3568},
      {""}, {""}, {""},
#line 3517 "nasdaq.gperf"
      {"NTRBW", 3504},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4788 "nasdaq.gperf"
      {"SXTP", 4775},
      {""}, {""}, {""}, {""}, {""},
#line 4725 "nasdaq.gperf"
      {"STKS", 4712},
      {""}, {""}, {""},
#line 4635 "nasdaq.gperf"
      {"SONM", 4622},
      {""}, {""}, {""}, {""}, {""},
#line 4088 "nasdaq.gperf"
      {"QEW", 4075},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3008 "nasdaq.gperf"
      {"LTBR", 2995},
#line 1870 "nasdaq.gperf"
      {"FMHI", 1857},
      {""}, {""},
#line 2499 "nasdaq.gperf"
      {"IGSB", 2486},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4074 "nasdaq.gperf"
      {"QBY", 4061},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4399 "nasdaq.gperf"
      {"SANM", 4386},
      {""}, {""}, {""}, {""},
#line 1860 "nasdaq.gperf"
      {"FLYW", 1847},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3509 "nasdaq.gperf"
      {"NTES", 3496},
      {""}, {""},
#line 2155 "nasdaq.gperf"
      {"GPCR", 2142},
#line 3424 "nasdaq.gperf"
      {"NFRX", 3411},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2422 "nasdaq.gperf"
      {"IACQW", 2409},
      {""},
#line 3222 "nasdaq.gperf"
      {"MNZL", 3209},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 224 "nasdaq.gperf"
      {"AKAN", 211},
      {""}, {""}, {""}, {""},
#line 1972 "nasdaq.gperf"
      {"FULC", 1959},
      {""}, {""}, {""}, {""}, {""},
#line 3270 "nasdaq.gperf"
      {"MSFL", 3257},
      {""}, {""},
#line 1601 "nasdaq.gperf"
      {"EML", 1588},
      {""},
#line 293 "nasdaq.gperf"
      {"AMDL", 280},
      {""}, {""}, {""}, {""},
#line 363 "nasdaq.gperf"
      {"APP", 350},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 367 "nasdaq.gperf"
      {"APPX", 354},
      {""}, {""}, {""}, {""}, {""},
#line 5218 "nasdaq.gperf"
      {"VFF", 5205},
      {""},
#line 5585 "nasdaq.gperf"
      {"ZTG", 5572},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2024 "nasdaq.gperf"
      {"GCGR", 2011},
#line 2025 "nasdaq.gperf"
      {"GCGRU", 2012},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1153 "nasdaq.gperf"
      {"CNOB", 1140},
      {""}, {""},
#line 1820 "nasdaq.gperf"
      {"FID", 1807},
      {""}, {""}, {""}, {""},
#line 4068 "nasdaq.gperf"
      {"QAT", 4055},
#line 5086 "nasdaq.gperf"
      {"UCAR", 5073},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2929 "nasdaq.gperf"
      {"LILA", 2916},
      {""},
#line 4072 "nasdaq.gperf"
      {"QBTZ", 4059},
#line 4759 "nasdaq.gperf"
      {"SUSC", 4746},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 226 "nasdaq.gperf"
      {"AKTS", 213},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5103 "nasdaq.gperf"
      {"UG", 5090},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1842 "nasdaq.gperf"
      {"FKU", 1829},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3498 "nasdaq.gperf"
      {"NSIT", 3485},
      {""},
#line 3571 "nasdaq.gperf"
      {"NXST", 3558},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5441 "nasdaq.gperf"
      {"WYNN", 5428},
#line 1318 "nasdaq.gperf"
      {"CVLT", 1305},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3689 "nasdaq.gperf"
      {"ORCS", 3676},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3636 "nasdaq.gperf"
      {"OLB", 3623},
#line 4063 "nasdaq.gperf"
      {"QABA", 4050},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2979 "nasdaq.gperf"
      {"LOVE", 2966},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 403 "nasdaq.gperf"
      {"ARKR", 390},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2815 "nasdaq.gperf"
      {"KRAQ", 2802},
#line 2816 "nasdaq.gperf"
      {"KRAQU", 2803},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 672 "nasdaq.gperf"
      {"BIOTW", 659},
      {""},
#line 1087 "nasdaq.gperf"
      {"CHSN", 1074},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1279 "nasdaq.gperf"
      {"CSIQ", 1266},
#line 3525 "nasdaq.gperf"
      {"NTWOW", 3512},
#line 1341 "nasdaq.gperf"
      {"CZFS", 1328},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5139 "nasdaq.gperf"
      {"USCB", 5126},
      {""}, {""}, {""}, {""}, {""},
#line 1322 "nasdaq.gperf"
      {"CWCO", 1309},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2625 "nasdaq.gperf"
      {"IRD", 2612},
#line 3791 "nasdaq.gperf"
      {"PBMWW", 3778},
      {""}, {""},
#line 4042 "nasdaq.gperf"
      {"PUI", 4029},
#line 5084 "nasdaq.gperf"
      {"UBRL", 5071},
      {""},
#line 781 "nasdaq.gperf"
      {"BRHY", 768},
      {""},
#line 1154 "nasdaq.gperf"
      {"CNOBP", 1141},
      {""},
#line 703 "nasdaq.gperf"
      {"BLKB", 690},
      {""}, {""}, {""}, {""}, {""},
#line 1405 "nasdaq.gperf"
      {"DIBS", 1392},
      {""}, {""}, {""}, {""},
#line 803 "nasdaq.gperf"
      {"BRZE", 790},
      {""},
#line 2072 "nasdaq.gperf"
      {"GGROW", 2059},
      {""},
#line 2931 "nasdaq.gperf"
      {"LILAP", 2918},
#line 4085 "nasdaq.gperf"
      {"QETA", 4072},
#line 4087 "nasdaq.gperf"
      {"QETAU", 4074},
      {""}, {""}, {""}, {""},
#line 4086 "nasdaq.gperf"
      {"QETAR", 4073},
#line 895 "nasdaq.gperf"
      {"BYSI", 882},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2863 "nasdaq.gperf"
      {"LASR", 2850},
#line 5261 "nasdaq.gperf"
      {"VNDA", 5248},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1061 "nasdaq.gperf"
      {"CHEC", 1048},
#line 1062 "nasdaq.gperf"
      {"CHECU", 1049},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2313 "nasdaq.gperf"
      {"HLIT", 2300},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1034 "nasdaq.gperf"
      {"CFFI", 1021},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5014 "nasdaq.gperf"
      {"TSHA", 5001},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4686 "nasdaq.gperf"
      {"SQQQ", 4673},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1633 "nasdaq.gperf"
      {"EQIX", 1620},
      {""}, {""}, {""}, {""},
#line 3297 "nasdaq.gperf"
      {"MULT", 3284},
      {""},
#line 3253 "nasdaq.gperf"
      {"MRKR", 3240},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4168 "nasdaq.gperf"
      {"RADX", 4155},
#line 1421 "nasdaq.gperf"
      {"DLTR", 1408},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1427 "nasdaq.gperf"
      {"DMII", 1414},
#line 1429 "nasdaq.gperf"
      {"DMIIU", 1416},
      {""}, {""}, {""},
#line 3613 "nasdaq.gperf"
      {"ODYS", 3600},
#line 1428 "nasdaq.gperf"
      {"DMIIR", 1415},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2114 "nasdaq.gperf"
      {"GLPI", 2101},
      {""}, {""},
#line 1435 "nasdaq.gperf"
      {"DNMX", 1422},
#line 1436 "nasdaq.gperf"
      {"DNMXU", 1423},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1067 "nasdaq.gperf"
      {"CHI", 1054},
      {""}, {""}, {""}, {""}, {""},
#line 2344 "nasdaq.gperf"
      {"HPAI", 2331},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5035 "nasdaq.gperf"
      {"TTEQ", 5022},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2430 "nasdaq.gperf"
      {"IBCP", 2417},
      {""}, {""}, {""}, {""}, {""},
#line 3702 "nasdaq.gperf"
      {"ORR", 3689},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4084 "nasdaq.gperf"
      {"QDTY", 4071},
      {""}, {""}, {""}, {""}, {""},
#line 1350 "nasdaq.gperf"
      {"DAICW", 1337},
      {""}, {""},
#line 4585 "nasdaq.gperf"
      {"SMH", 4572},
      {""}, {""}, {""},
#line 3304 "nasdaq.gperf"
      {"MVIS", 3291},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4587 "nasdaq.gperf"
      {"SMHX", 4574},
      {""}, {""}, {""},
#line 3471 "nasdaq.gperf"
      {"NNNN", 3458},
#line 4586 "nasdaq.gperf"
      {"SMHC", 4573},
      {""}, {""},
#line 1050 "nasdaq.gperf"
      {"CGPT", 1037},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1200 "nasdaq.gperf"
      {"COSM", 1187},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4110 "nasdaq.gperf"
      {"QQA", 4097},
      {""}, {""}, {""}, {""},
#line 1590 "nasdaq.gperf"
      {"ELVR", 1577},
      {""},
#line 1638 "nasdaq.gperf"
      {"ERET", 1625},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4376 "nasdaq.gperf"
      {"RYM", 4363},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1141 "nasdaq.gperf"
      {"CMPR", 1128},
#line 3687 "nasdaq.gperf"
      {"ORBS", 3674},
      {""}, {""}, {""}, {""},
#line 882 "nasdaq.gperf"
      {"BVS", 869},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5156 "nasdaq.gperf"
      {"USTB", 5143},
#line 4651 "nasdaq.gperf"
      {"SPAQ", 4638},
      {""}, {""},
#line 4769 "nasdaq.gperf"
      {"SVCO", 4756},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4130 "nasdaq.gperf"
      {"QQWZ", 4117},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4952 "nasdaq.gperf"
      {"TNXP", 4939},
      {""}, {""},
#line 718 "nasdaq.gperf"
      {"BLZE", 705},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2750 "nasdaq.gperf"
      {"KBONW", 2737},
#line 3849 "nasdaq.gperf"
      {"PFF", 3836},
      {""}, {""}, {""},
#line 4543 "nasdaq.gperf"
      {"SKWD", 4530},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5067 "nasdaq.gperf"
      {"TWST", 5054},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3411 "nasdaq.gperf"
      {"NEWTG", 3398},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2169 "nasdaq.gperf"
      {"GRDX", 2156},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3381 "nasdaq.gperf"
      {"NCO", 3368},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2304 "nasdaq.gperf"
      {"HIND", 2291},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4660 "nasdaq.gperf"
      {"SPFI", 4647},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4492 "nasdaq.gperf"
      {"SGP", 4479},
#line 1543 "nasdaq.gperf"
      {"EDIT", 1530},
      {""}, {""},
#line 4115 "nasdaq.gperf"
      {"QQMG", 4102},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3641 "nasdaq.gperf"
      {"OM", 3628},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2019 "nasdaq.gperf"
      {"GBDC", 2006},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1324 "nasdaq.gperf"
      {"CWST", 1311},
      {""}, {""},
#line 261 "nasdaq.gperf"
      {"ALOV", 248},
#line 262 "nasdaq.gperf"
      {"ALOVU", 249},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2849 "nasdaq.gperf"
      {"KZIA", 2836},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1449 "nasdaq.gperf"
      {"DPU", 1436},
      {""}, {""}, {""},
#line 3769 "nasdaq.gperf"
      {"PANW", 3756},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2662 "nasdaq.gperf"
      {"IVA", 2649},
      {""}, {""}, {""}, {""},
#line 1877 "nasdaq.gperf"
      {"FNGR", 1864},
      {""},
#line 2453 "nasdaq.gperf"
      {"IBTP", 2440},
#line 1441 "nasdaq.gperf"
      {"DOGZ", 1428},
#line 366 "nasdaq.gperf"
      {"APPS", 353},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 742 "nasdaq.gperf"
      {"BNGO", 729},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1364 "nasdaq.gperf"
      {"DBGI", 1351},
      {""}, {""}, {""},
#line 4681 "nasdaq.gperf"
      {"SPYQ", 4668},
#line 1722 "nasdaq.gperf"
      {"FACWW", 1709},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1130 "nasdaq.gperf"
      {"CLSM", 1117},
      {""},
#line 4071 "nasdaq.gperf"
      {"QBTS", 4058},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3585 "nasdaq.gperf"
      {"OACCW", 3572},
      {""}, {""}, {""},
#line 4544 "nasdaq.gperf"
      {"SKYA", 4531},
      {""}, {""}, {""}, {""},
#line 4550 "nasdaq.gperf"
      {"SKYX", 4537},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2670 "nasdaq.gperf"
      {"IVVD", 2657},
#line 2341 "nasdaq.gperf"
      {"HOVRW", 2328},
      {""},
#line 1297 "nasdaq.gperf"
      {"CTRM", 1284},
#line 4361 "nasdaq.gperf"
      {"RVMD", 4348},
      {""},
#line 2177 "nasdaq.gperf"
      {"GRNQ", 2164},
#line 1085 "nasdaq.gperf"
      {"CHSCO", 1072},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3400 "nasdaq.gperf"
      {"NEO", 3387},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3987 "nasdaq.gperf"
      {"PROV", 3974},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1123 "nasdaq.gperf"
      {"CLOV", 1110},
      {""},
#line 4009 "nasdaq.gperf"
      {"PSHG", 3996},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1623 "nasdaq.gperf"
      {"ENVX", 1610},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1834 "nasdaq.gperf"
      {"FISV", 1821},
      {""}, {""},
#line 3373 "nasdaq.gperf"
      {"NCEL", 3360},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1704 "nasdaq.gperf"
      {"EXYNW", 1691},
      {""}, {""},
#line 4185 "nasdaq.gperf"
      {"RBCAA", 4172},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3407 "nasdaq.gperf"
      {"NESR", 3394},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5237 "nasdaq.gperf"
      {"VINP", 5224},
#line 5190 "nasdaq.gperf"
      {"VBCH", 5177},
      {""}, {""},
#line 1541 "nasdaq.gperf"
      {"EDBLW", 1528},
      {""}, {""},
#line 2811 "nasdaq.gperf"
      {"KPLT", 2798},
      {""}, {""},
#line 1292 "nasdaq.gperf"
      {"CTKB", 1279},
#line 3095 "nasdaq.gperf"
      {"MCHB", 3082},
      {""}, {""},
#line 3209 "nasdaq.gperf"
      {"MNDY", 3196},
      {""}, {""}, {""}, {""},
#line 1184 "nasdaq.gperf"
      {"COLM", 1171},
      {""},
#line 4039 "nasdaq.gperf"
      {"PTORW", 4026},
      {""}, {""}, {""}, {""},
#line 2983 "nasdaq.gperf"
      {"LPBB", 2970},
#line 2984 "nasdaq.gperf"
      {"LPBBU", 2971},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4094 "nasdaq.gperf"
      {"QLYS", 4081},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5579 "nasdaq.gperf"
      {"ZOOZW", 5566},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2103 "nasdaq.gperf"
      {"GLDI", 2090},
      {""}, {""}, {""}, {""},
#line 919 "nasdaq.gperf"
      {"CALM", 906},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4591 "nasdaq.gperf"
      {"SMPL", 4578},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 715 "nasdaq.gperf"
      {"BLUW", 702},
#line 716 "nasdaq.gperf"
      {"BLUWU", 703},
      {""},
#line 3401 "nasdaq.gperf"
      {"NEOG", 3388},
      {""},
#line 5253 "nasdaq.gperf"
      {"VLYPN", 5240},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4354 "nasdaq.gperf"
      {"RUM", 4341},
      {""}, {""}, {""}, {""}, {""},
#line 1055 "nasdaq.gperf"
      {"CHAR", 1042},
#line 1057 "nasdaq.gperf"
      {"CHARU", 1044},
#line 365 "nasdaq.gperf"
      {"APPN", 352},
      {""},
#line 5126 "nasdaq.gperf"
      {"UPC", 5113},
#line 2179 "nasdaq.gperf"
      {"GRPN", 2166},
#line 1056 "nasdaq.gperf"
      {"CHARR", 1043},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3210 "nasdaq.gperf"
      {"MNKD", 3197},
      {""}, {""}, {""}, {""},
#line 3363 "nasdaq.gperf"
      {"NBIL", 3350},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5131 "nasdaq.gperf"
      {"UPXI", 5118},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 320 "nasdaq.gperf"
      {"AMZU", 307},
      {""}, {""}, {""}, {""},
#line 4931 "nasdaq.gperf"
      {"TMCWW", 4918},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4826 "nasdaq.gperf"
      {"TBCH", 4813},
      {""}, {""}, {""}, {""},
#line 4996 "nasdaq.gperf"
      {"TRUH", 4983},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3904 "nasdaq.gperf"
      {"PLSM", 3891},
      {""},
#line 4800 "nasdaq.gperf"
      {"TACH", 4787},
#line 4801 "nasdaq.gperf"
      {"TACHU", 4788},
      {""}, {""}, {""},
#line 4073 "nasdaq.gperf"
      {"QBUF", 4060},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2687 "nasdaq.gperf"
      {"JBHT", 2674},
#line 3154 "nasdaq.gperf"
      {"MGEE", 3141},
      {""},
#line 2368 "nasdaq.gperf"
      {"HTLD", 2355},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2513 "nasdaq.gperf"
      {"ILPT", 2500},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5116 "nasdaq.gperf"
      {"UNB", 5103},
      {""},
#line 1167 "nasdaq.gperf"
      {"COCH", 1154},
      {""},
#line 3086 "nasdaq.gperf"
      {"MCAH", 3073},
#line 3088 "nasdaq.gperf"
      {"MCAHU", 3075},
      {""}, {""}, {""},
#line 2496 "nasdaq.gperf"
      {"IGIB", 2483},
#line 3087 "nasdaq.gperf"
      {"MCAHR", 3074},
      {""}, {""},
#line 4030 "nasdaq.gperf"
      {"PTH", 4017},
#line 3118 "nasdaq.gperf"
      {"MDXH", 3105},
#line 1619 "nasdaq.gperf"
      {"ENTA", 1606},
      {""}, {""}, {""}, {""},
#line 1621 "nasdaq.gperf"
      {"ENTX", 1608},
      {""}, {""}, {""}, {""}, {""},
#line 5117 "nasdaq.gperf"
      {"UNCY", 5104},
#line 1973 "nasdaq.gperf"
      {"FULT", 1960},
      {""}, {""},
#line 1559 "nasdaq.gperf"
      {"EGAN", 1546},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 873 "nasdaq.gperf"
      {"BULD", 860},
      {""}, {""},
#line 3582 "nasdaq.gperf"
      {"OABIW", 3569},
      {""}, {""},
#line 506 "nasdaq.gperf"
      {"AVGX", 493},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4551 "nasdaq.gperf"
      {"SKYY", 4538},
      {""},
#line 2912 "nasdaq.gperf"
      {"LGCL", 2899},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4789 "nasdaq.gperf"
      {"SXTPW", 4776},
#line 2762 "nasdaq.gperf"
      {"KDP", 2749},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3152 "nasdaq.gperf"
      {"MFP", 3139},
      {""}, {""}, {""},
#line 691 "nasdaq.gperf"
      {"BKMI", 678},
      {""}, {""},
#line 4441 "nasdaq.gperf"
      {"SDAWW", 4428},
      {""},
#line 5175 "nasdaq.gperf"
      {"UZX", 5162},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4864 "nasdaq.gperf"
      {"TECH", 4851},
      {""}, {""}, {""},
#line 663 "nasdaq.gperf"
      {"BID", 650},
      {""}, {""}, {""}, {""},
#line 4196 "nasdaq.gperf"
      {"RCKY", 4183},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1821 "nasdaq.gperf"
      {"FIEE", 1808},
      {""}, {""}, {""},
#line 1035 "nasdaq.gperf"
      {"CFFN", 1022},
      {""}, {""}, {""}, {""}, {""},
#line 4407 "nasdaq.gperf"
      {"SBCWW", 4394},
#line 5165 "nasdaq.gperf"
      {"UTSI", 5152},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2324 "nasdaq.gperf"
      {"HNRG", 2311},
      {""},
#line 2212 "nasdaq.gperf"
      {"GTERU", 2199},
      {""}, {""}, {""}, {""},
#line 2211 "nasdaq.gperf"
      {"GTERR", 2198},
#line 2557 "nasdaq.gperf"
      {"INGN", 2544},
      {""},
#line 1620 "nasdaq.gperf"
      {"ENTG", 1607},
      {""}, {""}, {""},
#line 2364 "nasdaq.gperf"
      {"HTCO", 2351},
      {""}, {""}, {""}, {""}, {""},
#line 1974 "nasdaq.gperf"
      {"FULTP", 1961},
      {""},
#line 3867 "nasdaq.gperf"
      {"PHAR", 3854},
      {""}, {""}, {""},
#line 3757 "nasdaq.gperf"
      {"PAGP", 3744},
      {""}, {""}, {""}, {""},
#line 364 "nasdaq.gperf"
      {"APPF", 351},
      {""}, {""}, {""}, {""},
#line 1663 "nasdaq.gperf"
      {"ETS", 1650},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 503 "nasdaq.gperf"
      {"AVGG", 490},
      {""}, {""}, {""},
#line 874 "nasdaq.gperf"
      {"BULG", 861},
      {""},
#line 1649 "nasdaq.gperf"
      {"ESLA", 1636},
#line 2200 "nasdaq.gperf"
      {"GSRV", 2187},
#line 2202 "nasdaq.gperf"
      {"GSRVU", 2189},
      {""}, {""}, {""},
#line 2026 "nasdaq.gperf"
      {"GCGRW", 2013},
#line 2201 "nasdaq.gperf"
      {"GSRVR", 2188},
      {""}, {""},
#line 2222 "nasdaq.gperf"
      {"GUAC", 2209},
#line 2223 "nasdaq.gperf"
      {"GUACU", 2210},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1088 "nasdaq.gperf"
      {"CHTR", 1075},
      {""}, {""},
#line 1316 "nasdaq.gperf"
      {"CVGI", 1303},
#line 4857 "nasdaq.gperf"
      {"TDTH", 4844},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3970 "nasdaq.gperf"
      {"PRCH", 3957},
      {""}, {""},
#line 664 "nasdaq.gperf"
      {"BIDG", 651},
      {""},
#line 5124 "nasdaq.gperf"
      {"UPB", 5111},
#line 5125 "nasdaq.gperf"
      {"UPBD", 5112},
      {""},
#line 2361 "nasdaq.gperf"
      {"HSIC", 2348},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 615 "nasdaq.gperf"
      {"BEEP", 602},
      {""},
#line 1473 "nasdaq.gperf"
      {"DSWL", 1460},
      {""}, {""}, {""},
#line 4353 "nasdaq.gperf"
      {"RUBI", 4340},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4746 "nasdaq.gperf"
      {"SUIG", 4733},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2296 "nasdaq.gperf"
      {"HFWA", 2283},
      {""}, {""}, {""}, {""},
#line 300 "nasdaq.gperf"
      {"AMKR", 287},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5040 "nasdaq.gperf"
      {"TUG", 5027},
      {""}, {""}, {""},
#line 2188 "nasdaq.gperf"
      {"GSGO", 2175},
      {""}, {""},
#line 695 "nasdaq.gperf"
      {"BKYI", 682},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2817 "nasdaq.gperf"
      {"KRAQW", 2804},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3754 "nasdaq.gperf"
      {"PACH", 3741},
#line 3755 "nasdaq.gperf"
      {"PACHU", 3742},
      {""}, {""}, {""}, {""},
#line 885 "nasdaq.gperf"
      {"BWBBP", 872},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 899 "nasdaq.gperf"
      {"BZFD", 886},
      {""},
#line 5121 "nasdaq.gperf"
      {"UNTY", 5108},
#line 1599 "nasdaq.gperf"
      {"EMIS", 1586},
      {""}, {""}, {""}, {""}, {""},
#line 1600 "nasdaq.gperf"
      {"EMISR", 1587},
#line 1398 "nasdaq.gperf"
      {"DGRS", 1385},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 944 "nasdaq.gperf"
      {"CATH", 931},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2518 "nasdaq.gperf"
      {"IMDX", 2505},
      {""}, {""},
#line 1089 "nasdaq.gperf"
      {"CHTRP", 1076},
      {""}, {""},
#line 3061 "nasdaq.gperf"
      {"MATH", 3048},
      {""}, {""}, {""},
#line 494 "nasdaq.gperf"
      {"AUROW", 481},
      {""}, {""}, {""}, {""}, {""},
#line 3107 "nasdaq.gperf"
      {"MDBH", 3094},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4311 "nasdaq.gperf"
      {"RNGT", 4298},
#line 4312 "nasdaq.gperf"
      {"RNGTU", 4299},
      {""}, {""}, {""}, {""},
#line 2773 "nasdaq.gperf"
      {"KFII", 2760},
#line 2775 "nasdaq.gperf"
      {"KFIIU", 2762},
      {""}, {""}, {""}, {""},
#line 2774 "nasdaq.gperf"
      {"KFIIR", 2761},
      {""}, {""}, {""}, {""}, {""},
#line 1064 "nasdaq.gperf"
      {"CHEF", 1051},
      {""}, {""}, {""}, {""}, {""},
#line 1310 "nasdaq.gperf"
      {"CURR", 1297},
#line 1396 "nasdaq.gperf"
      {"DGNX", 1383},
      {""}, {""}, {""}, {""}, {""},
#line 1560 "nasdaq.gperf"
      {"EGBN", 1547},
      {""}, {""},
#line 1063 "nasdaq.gperf"
      {"CHECW", 1050},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1294 "nasdaq.gperf"
      {"CTNM", 1281},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 658 "nasdaq.gperf"
      {"BHRB", 645},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1439 "nasdaq.gperf"
      {"DNUT", 1426},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4910 "nasdaq.gperf"
      {"TKNS", 4897},
      {""}, {""}, {""}, {""},
#line 2990 "nasdaq.gperf"
      {"LPLA", 2977},
      {""}, {""},
#line 1483 "nasdaq.gperf"
      {"DTSS", 1470},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5063 "nasdaq.gperf"
      {"TWIN", 5050},
      {""}, {""},
#line 2520 "nasdaq.gperf"
      {"IMMP", 2507},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2009 "nasdaq.gperf"
      {"GAING", 1996},
      {""},
#line 5577 "nasdaq.gperf"
      {"ZNTL", 5564},
      {""}, {""},
#line 1149 "nasdaq.gperf"
      {"CNDT", 1136},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4279 "nasdaq.gperf"
      {"RIME", 4266},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2926 "nasdaq.gperf"
      {"LIEN", 2913},
      {""}, {""}, {""}, {""}, {""},
#line 4132 "nasdaq.gperf"
      {"QQXT", 4119},
      {""}, {""}, {""},
#line 1951 "nasdaq.gperf"
      {"FTH", 1938},
      {""}, {""},
#line 1437 "nasdaq.gperf"
      {"DNMXW", 1424},
      {""}, {""},
#line 1952 "nasdaq.gperf"
      {"FTHA", 1939},
#line 1953 "nasdaq.gperf"
      {"FTHAU", 1940},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2345 "nasdaq.gperf"
      {"HPAIW", 2332},
      {""}, {""}, {""},
#line 1955 "nasdaq.gperf"
      {"FTHI", 1942},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3703 "nasdaq.gperf"
      {"ORRF", 3690},
      {""}, {""}, {""}, {""},
#line 4709 "nasdaq.gperf"
      {"SSRM", 4696},
      {""}, {""}, {""}, {""},
#line 4503 "nasdaq.gperf"
      {"SHLS", 4490},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5079 "nasdaq.gperf"
      {"TZOO", 5066},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3993 "nasdaq.gperf"
      {"PRTH", 3980},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4257 "nasdaq.gperf"
      {"RGLO", 4244},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5140 "nasdaq.gperf"
      {"USCL", 5127},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2786 "nasdaq.gperf"
      {"KJD", 2773},
      {""},
#line 4052 "nasdaq.gperf"
      {"PWRL", 4039},
      {""}, {""}, {""}, {""}, {""},
#line 5468 "nasdaq.gperf"
      {"XHG", 5455},
      {""}, {""},
#line 2112 "nasdaq.gperf"
      {"GLOO", 2099},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2803 "nasdaq.gperf"
      {"KOD", 2790},
      {""}, {""},
#line 3402 "nasdaq.gperf"
      {"NEON", 3389},
      {""}, {""}, {""}, {""},
#line 2073 "nasdaq.gperf"
      {"GH", 2060},
      {""}, {""}, {""},
#line 4797 "nasdaq.gperf"
      {"SZZL", 4784},
#line 4799 "nasdaq.gperf"
      {"SZZLU", 4786},
      {""}, {""}, {""}, {""},
#line 4798 "nasdaq.gperf"
      {"SZZLR", 4785},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1615 "nasdaq.gperf"
      {"ENRD", 1602},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 185 "nasdaq.gperf"
      {"AHG", 172},
#line 1878 "nasdaq.gperf"
      {"FNK", 1865},
#line 4604 "nasdaq.gperf"
      {"SND", 4591},
      {""},
#line 4046 "nasdaq.gperf"
      {"PURR", 4033},
#line 2075 "nasdaq.gperf"
      {"GHXI", 2062},
#line 2076 "nasdaq.gperf"
      {"GHXIU", 2063},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4607 "nasdaq.gperf"
      {"SNDX", 4594},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5523 "nasdaq.gperf"
      {"YHGJ", 5510},
      {""}, {""},
#line 4785 "nasdaq.gperf"
      {"SWVL", 4772},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5144 "nasdaq.gperf"
      {"USEA", 5131},
      {""}, {""}, {""}, {""}, {""},
#line 2801 "nasdaq.gperf"
      {"KNGZ", 2788},
      {""}, {""}, {""},
#line 2972 "nasdaq.gperf"
      {"LOGO", 2959},
      {""}, {""}, {""},
#line 1122 "nasdaq.gperf"
      {"CLOU", 1109},
      {""}, {""}, {""}, {""}, {""},
#line 972 "nasdaq.gperf"
      {"CCFE", 959},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2323 "nasdaq.gperf"
      {"HNNA", 2310},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 692 "nasdaq.gperf"
      {"BKMS", 679},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2919 "nasdaq.gperf"
      {"LGRO", 2906},
#line 5512 "nasdaq.gperf"
      {"XYZG", 5499},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1645 "nasdaq.gperf"
      {"ESEA", 1632},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5166 "nasdaq.gperf"
      {"UTWO", 5153},
      {""}, {""}, {""}, {""},
#line 1636 "nasdaq.gperf"
      {"EQRR", 1623},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 263 "nasdaq.gperf"
      {"ALOVW", 250},
#line 4747 "nasdaq.gperf"
      {"SUIS", 4734},
#line 4194 "nasdaq.gperf"
      {"RCKT", 4181},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2754 "nasdaq.gperf"
      {"KBWP", 2741},
      {""}, {""}, {""},
#line 4613 "nasdaq.gperf"
      {"SNPS", 4600},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1390 "nasdaq.gperf"
      {"DFTX", 1377},
      {""}, {""}, {""},
#line 2832 "nasdaq.gperf"
      {"KTOS", 2819},
      {""}, {""}, {""},
#line 3705 "nasdaq.gperf"
      {"OSCX", 3692},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1065 "nasdaq.gperf"
      {"CHGA", 1052},
      {""},
#line 5133 "nasdaq.gperf"
      {"URGN", 5120},
      {""}, {""},
#line 1066 "nasdaq.gperf"
      {"CHGX", 1053},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3714 "nasdaq.gperf"
      {"OSW", 3701},
      {""}, {""}, {""},
#line 3323 "nasdaq.gperf"
      {"MYGN", 3310},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1484 "nasdaq.gperf"
      {"DTST", 1471},
      {""}, {""}, {""}, {""},
#line 1598 "nasdaq.gperf"
      {"EMIF", 1585},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4545 "nasdaq.gperf"
      {"SKYAW", 4532},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4362 "nasdaq.gperf"
      {"RVMDW", 4349},
      {""}, {""},
#line 1629 "nasdaq.gperf"
      {"EPRX", 1616},
      {""}, {""}, {""},
#line 1478 "nasdaq.gperf"
      {"DTI", 1465},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5309 "nasdaq.gperf"
      {"VTIP", 5296},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2991 "nasdaq.gperf"
      {"LPSN", 2978},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4339 "nasdaq.gperf"
      {"RREV", 4326},
#line 4340 "nasdaq.gperf"
      {"RREVU", 4327},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2904 "nasdaq.gperf"
      {"LFS", 2891},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5148 "nasdaq.gperf"
      {"USIG", 5135},
      {""}, {""}, {""}, {""}, {""},
#line 2905 "nasdaq.gperf"
      {"LFSC", 2892},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2853 "nasdaq.gperf"
      {"LAFA", 2840},
#line 2855 "nasdaq.gperf"
      {"LAFAU", 2842},
      {""}, {""},
#line 5377 "nasdaq.gperf"
      {"WISE", 5364},
      {""},
#line 2854 "nasdaq.gperf"
      {"LAFAR", 2841},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2805 "nasdaq.gperf"
      {"KOPN", 2792},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2745 "nasdaq.gperf"
      {"KAZR", 2732},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 694 "nasdaq.gperf"
      {"BKR", 681},
      {""},
#line 2985 "nasdaq.gperf"
      {"LPBBW", 2972},
      {""}, {""}, {""}, {""}, {""},
#line 5052 "nasdaq.gperf"
      {"TVGN", 5039},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4367 "nasdaq.gperf"
      {"RWAY", 4354},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4136 "nasdaq.gperf"
      {"QS", 4123},
      {""}, {""}, {""},
#line 2643 "nasdaq.gperf"
      {"ISPC", 2630},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 717 "nasdaq.gperf"
      {"BLUWW", 704},
      {""}, {""}, {""},
#line 5062 "nasdaq.gperf"
      {"TWG", 5049},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1509 "nasdaq.gperf"
      {"DXLG", 1496},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5317 "nasdaq.gperf"
      {"VUZI", 5304},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1711 "nasdaq.gperf"
      {"EZRA", 1698},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2760 "nasdaq.gperf"
      {"KDK", 2747},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4061 "nasdaq.gperf"
      {"PYZ", 4048},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4326 "nasdaq.gperf"
      {"ROIV", 4313},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 786 "nasdaq.gperf"
      {"BRKR", 773},
      {""}, {""},
#line 4629 "nasdaq.gperf"
      {"SOGP", 4616},
      {""},
#line 2069 "nasdaq.gperf"
      {"GGLL", 2056},
      {""}, {""}, {""},
#line 3712 "nasdaq.gperf"
      {"OST", 3699},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2848 "nasdaq.gperf"
      {"KYTX", 2835},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 659 "nasdaq.gperf"
      {"BHST", 646},
      {""}, {""}, {""},
#line 2170 "nasdaq.gperf"
      {"GREEL", 2157},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4802 "nasdaq.gperf"
      {"TACHW", 4789},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2356 "nasdaq.gperf"
      {"HRZN", 2343},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1923 "nasdaq.gperf"
      {"FSBW", 1910},
      {""}, {""},
#line 2227 "nasdaq.gperf"
      {"GUTS", 2214},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5433 "nasdaq.gperf"
      {"WVE", 5420},
#line 1658 "nasdaq.gperf"
      {"ETEC", 1645},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3704 "nasdaq.gperf"
      {"OSBC", 3691},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1168 "nasdaq.gperf"
      {"COCHW", 1155},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3470 "nasdaq.gperf"
      {"NNE", 3457},
      {""}, {""},
#line 2330 "nasdaq.gperf"
      {"HOLO", 2317},
      {""}, {""},
#line 1328 "nasdaq.gperf"
      {"CXDO", 1315},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3412 "nasdaq.gperf"
      {"NEWTH", 3399},
      {""}, {""}, {""}, {""},
#line 3406 "nasdaq.gperf"
      {"NERV", 3393},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2365 "nasdaq.gperf"
      {"HTCR", 2352},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2242 "nasdaq.gperf"
      {"HALO", 2229},
      {""}, {""}, {""}, {""}, {""},
#line 135 "nasdaq.gperf"
      {"AEHL", 122},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 787 "nasdaq.gperf"
      {"BRKRP", 774},
      {""},
#line 1651 "nasdaq.gperf"
      {"ESLT", 1638},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4368 "nasdaq.gperf"
      {"RWAYI", 4355},
      {""}, {""}, {""}, {""}, {""},
#line 2033 "nasdaq.gperf"
      {"GDEV", 2020},
      {""}, {""}, {""}, {""},
#line 738 "nasdaq.gperf"
      {"BND", 725},
#line 2941 "nasdaq.gperf"
      {"LIQT", 2928},
      {""}, {""}, {""}, {""}, {""},
#line 619 "nasdaq.gperf"
      {"BELFA", 606},
      {""},
#line 4600 "nasdaq.gperf"
      {"SMXWW", 4587},
      {""},
#line 741 "nasdaq.gperf"
      {"BNDX", 728},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3393 "nasdaq.gperf"
      {"NDAQ", 3380},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2305 "nasdaq.gperf"
      {"HIS", 2292},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2878 "nasdaq.gperf"
      {"LCFY", 2865},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2213 "nasdaq.gperf"
      {"GTERW", 2200},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4498 "nasdaq.gperf"
      {"SHEN", 4485},
      {""},
#line 949 "nasdaq.gperf"
      {"CBFV", 936},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5553 "nasdaq.gperf"
      {"ZAP", 5540},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1656 "nasdaq.gperf"
      {"ESQ", 1643},
      {""}, {""}, {""},
#line 1977 "nasdaq.gperf"
      {"FUSB", 1964},
      {""},
#line 295 "nasdaq.gperf"
      {"AMEM", 282},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3774 "nasdaq.gperf"
      {"PASW", 3761},
#line 1650 "nasdaq.gperf"
      {"ESLAW", 1637},
#line 5137 "nasdaq.gperf"
      {"USAR", 5124},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2224 "nasdaq.gperf"
      {"GUACW", 2211},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4900 "nasdaq.gperf"
      {"TIH", 4887},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5413 "nasdaq.gperf"
      {"WSGE", 5400},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1784 "nasdaq.gperf"
      {"FEIM", 1771},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4783 "nasdaq.gperf"
      {"SWMR", 4770},
      {""}, {""}, {""}, {""},
#line 2457 "nasdaq.gperf"
      {"ICCM", 2444},
      {""}, {""}, {""}, {""}, {""},
#line 3174 "nasdaq.gperf"
      {"MIRM", 3161},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1476 "nasdaq.gperf"
      {"DTCR", 1463},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5096 "nasdaq.gperf"
      {"UFCS", 5083},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4206 "nasdaq.gperf"
      {"RDCM", 4193},
#line 3756 "nasdaq.gperf"
      {"PACHW", 3743},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 560 "nasdaq.gperf"
      {"BATRA", 547},
      {""}, {""}, {""}, {""}, {""},
#line 900 "nasdaq.gperf"
      {"BZFDW", 887},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 713 "nasdaq.gperf"
      {"BLSM", 700},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4369 "nasdaq.gperf"
      {"RWAYL", 4356},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1552 "nasdaq.gperf"
      {"EFAS", 1539},
      {""},
#line 4356 "nasdaq.gperf"
      {"RUN", 4343},
      {""},
#line 3428 "nasdaq.gperf"
      {"NGEN", 3415},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1070 "nasdaq.gperf"
      {"CHNR", 1057},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1512 "nasdaq.gperf"
      {"DXST", 1499},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4313 "nasdaq.gperf"
      {"RNGTW", 4300},
      {""}, {""}, {""}, {""},
#line 108 "nasdaq.gperf"
      {"ADAMN", 95},
      {""}, {""}, {""},
#line 1558 "nasdaq.gperf"
      {"EFTY", 1545},
      {""}, {""}, {""}, {""},
#line 1391 "nasdaq.gperf"
      {"DGCB", 1378},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 207 "nasdaq.gperf"
      {"AIPO", 194},
      {""}, {""}, {""}, {""},
#line 2509 "nasdaq.gperf"
      {"ILLU", 2496},
#line 2510 "nasdaq.gperf"
      {"ILLUU", 2497},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4807 "nasdaq.gperf"
      {"TANH", 4794},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4282 "nasdaq.gperf"
      {"RIOT", 4269},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5104 "nasdaq.gperf"
      {"UITB", 5091},
#line 254 "nasdaq.gperf"
      {"ALLW", 241},
#line 797 "nasdaq.gperf"
      {"BRRWW", 784},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 218 "nasdaq.gperf"
      {"AISP", 205},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2556 "nasdaq.gperf"
      {"INEO", 2543},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2566 "nasdaq.gperf"
      {"INO", 2553},
#line 2567 "nasdaq.gperf"
      {"INOD", 2554},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3183 "nasdaq.gperf"
      {"MKSI", 3170},
      {""},
#line 2583 "nasdaq.gperf"
      {"INVE", 2570},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3053 "nasdaq.gperf"
      {"MANH", 3040},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1954 "nasdaq.gperf"
      {"FTHAW", 1941},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2778 "nasdaq.gperf"
      {"KHC", 2765},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5149 "nasdaq.gperf"
      {"USIN", 5136},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2559 "nasdaq.gperf"
      {"INIO", 2546},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2796 "nasdaq.gperf"
      {"KMDA", 2783},
      {""}, {""}, {""}, {""},
#line 2334 "nasdaq.gperf"
      {"HOOD", 2321},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2336 "nasdaq.gperf"
      {"HOOX", 2323},
#line 2451 "nasdaq.gperf"
      {"IBTM", 2438},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4457 "nasdaq.gperf"
      {"SEEM", 4444},
      {""}, {""}, {""}, {""}, {""},
#line 2243 "nasdaq.gperf"
      {"HAO", 2230},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1554 "nasdaq.gperf"
      {"EFRA", 1541},
      {""}, {""}, {""}, {""}, {""},
#line 5362 "nasdaq.gperf"
      {"WFF", 5349},
#line 1616 "nasdaq.gperf"
      {"ENRDW", 1603},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3423 "nasdaq.gperf"
      {"NFLX", 3410},
#line 115 "nasdaq.gperf"
      {"ADGM", 102},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3603 "nasdaq.gperf"
      {"OCS", 3590},
      {""}, {""}, {""},
#line 4478 "nasdaq.gperf"
      {"SFD", 4465},
      {""}, {""}, {""}, {""},
#line 4758 "nasdaq.gperf"
      {"SUSB", 4745},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1694 "nasdaq.gperf"
      {"EXE", 1681},
      {""},
#line 2077 "nasdaq.gperf"
      {"GHXIW", 2064},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 693 "nasdaq.gperf"
      {"BKNG", 680},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4786 "nasdaq.gperf"
      {"SWVLW", 4773},
      {""}, {""},
#line 839 "nasdaq.gperf"
      {"BSMW", 826},
      {""},
#line 2907 "nasdaq.gperf"
      {"LFTO", 2894},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 815 "nasdaq.gperf"
      {"BSCW", 802},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2256 "nasdaq.gperf"
      {"HBIO", 2243},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2335 "nasdaq.gperf"
      {"HOOG", 2322},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2892 "nasdaq.gperf"
      {"LEGR", 2879},
      {""}, {""}, {""}, {""}, {""},
#line 1095 "nasdaq.gperf"
      {"CIFR", 1082},
#line 1697 "nasdaq.gperf"
      {"EXLS", 1684},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1417 "nasdaq.gperf"
      {"DLLL", 1404},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4193 "nasdaq.gperf"
      {"RCGE", 4180},
#line 4195 "nasdaq.gperf"
      {"RCKTW", 4182},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5432 "nasdaq.gperf"
      {"WULF", 5419},
#line 2063 "nasdaq.gperf"
      {"GFGF", 2050},
      {""}, {""}, {""}, {""},
#line 1752 "nasdaq.gperf"
      {"FCHL", 1739},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1471 "nasdaq.gperf"
      {"DSGX", 1458},
      {""}, {""}, {""}, {""}, {""},
#line 771 "nasdaq.gperf"
      {"BPYPP", 758},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5160 "nasdaq.gperf"
      {"UTEN", 5147},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2841 "nasdaq.gperf"
      {"KWM", 2828},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2906 "nasdaq.gperf"
      {"LFST", 2893},
#line 1444 "nasdaq.gperf"
      {"DOO", 1431},
      {""}, {""}, {""}, {""}, {""},
#line 78 "nasdaq.gperf"
      {"ACIW", 65},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3614 "nasdaq.gperf"
      {"OESX", 3601},
      {""},
#line 830 "nasdaq.gperf"
      {"BSJW", 817},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1358 "nasdaq.gperf"
      {"DAVE", 1345},
      {""}, {""},
#line 4796 "nasdaq.gperf"
      {"SYZ", 4783},
      {""},
#line 2138 "nasdaq.gperf"
      {"GOODN", 2125},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 136 "nasdaq.gperf"
      {"AEHR", 123},
      {""}, {""}, {""},
#line 4532 "nasdaq.gperf"
      {"SITM", 4519},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4275 "nasdaq.gperf"
      {"RILYN", 4262},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1456 "nasdaq.gperf"
      {"DRIO", 1443},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 240 "nasdaq.gperf"
      {"ALGM", 227},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4341 "nasdaq.gperf"
      {"RREVW", 4328},
      {""}, {""}, {""},
#line 5533 "nasdaq.gperf"
      {"YLDE", 5520},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1374 "nasdaq.gperf"
      {"DDOG", 1361},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1351 "nasdaq.gperf"
      {"DAIO", 1338},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 776 "nasdaq.gperf"
      {"BREM", 763},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2838 "nasdaq.gperf"
      {"KURA", 2825},
      {""}, {""}, {""}, {""},
#line 4808 "nasdaq.gperf"
      {"TAOP", 4795},
      {""},
#line 5053 "nasdaq.gperf"
      {"TVGNW", 5040},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2143 "nasdaq.gperf"
      {"GOOGN", 2130},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1276 "nasdaq.gperf"
      {"CSGP", 1263},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 872 "nasdaq.gperf"
      {"BUG", 859},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2074 "nasdaq.gperf"
      {"GHRS", 2061},
#line 5466 "nasdaq.gperf"
      {"XFOR", 5453},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 353 "nasdaq.gperf"
      {"APGE", 340},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4716 "nasdaq.gperf"
      {"STEP", 4703},
      {""},
#line 3367 "nasdaq.gperf"
      {"NBP", 3354},
      {""}, {""},
#line 2489 "nasdaq.gperf"
      {"IFLO", 2476},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 886 "nasdaq.gperf"
      {"BWEN", 873},
#line 3468 "nasdaq.gperf"
      {"NNBR", 3455},
      {""},
#line 2500 "nasdaq.gperf"
      {"IHRT", 2487},
      {""}, {""},
#line 3305 "nasdaq.gperf"
      {"MVLL", 3292},
      {""},
#line 3426 "nasdaq.gperf"
      {"NFXL", 3413},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1866 "nasdaq.gperf"
      {"FMBH", 1853},
      {""}, {""}, {""}, {""},
#line 5587 "nasdaq.gperf"
      {"ZTRE", 5574},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1418 "nasdaq.gperf"
      {"DLO", 1405},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5567 "nasdaq.gperf"
      {"ZJK", 5554},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5537 "nasdaq.gperf"
      {"YOKE", 5524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1944 "nasdaq.gperf"
      {"FTDR", 1931},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1026 "nasdaq.gperf"
      {"CEPV", 1013},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1646 "nasdaq.gperf"
      {"ESGD", 1633},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3422 "nasdaq.gperf"
      {"NFE", 3409},
      {""},
#line 4147 "nasdaq.gperf"
      {"QTR", 4134},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 888 "nasdaq.gperf"
      {"BWIN", 875},
#line 3499 "nasdaq.gperf"
      {"NSLR", 3486},
#line 4148 "nasdaq.gperf"
      {"QTRX", 4135},
#line 4271 "nasdaq.gperf"
      {"RIGL", 4258},
#line 2331 "nasdaq.gperf"
      {"HOLOW", 2318},
      {""}, {""}, {""}, {""},
#line 1369 "nasdaq.gperf"
      {"DCOY", 1356},
      {""}, {""}, {""}, {""}, {""},
#line 614 "nasdaq.gperf"
      {"BEEM", 601},
#line 238 "nasdaq.gperf"
      {"ALFUU", 225},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3642 "nasdaq.gperf"
      {"OMAB", 3629},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 511 "nasdaq.gperf"
      {"AVO", 498},
#line 3180 "nasdaq.gperf"
      {"MKLY", 3167},
#line 3182 "nasdaq.gperf"
      {"MKLYU", 3169},
      {""}, {""}, {""}, {""},
#line 3181 "nasdaq.gperf"
      {"MKLYR", 3168},
      {""}, {""}, {""}, {""},
#line 4357 "nasdaq.gperf"
      {"RUNN", 4344},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1940 "nasdaq.gperf"
      {"FTAIM", 1927},
#line 3296 "nasdaq.gperf"
      {"MULL", 3283},
      {""}, {""}, {""},
#line 2830 "nasdaq.gperf"
      {"KSPI", 2817},
      {""},
#line 5146 "nasdaq.gperf"
      {"USGG", 5133},
      {""}, {""}, {""}, {""}, {""},
#line 4421 "nasdaq.gperf"
      {"SCHL", 4408},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2862 "nasdaq.gperf"
      {"LASE", 2849},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2306 "nasdaq.gperf"
      {"HISF", 2293},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3986 "nasdaq.gperf"
      {"PROP", 3973},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2879 "nasdaq.gperf"
      {"LCFYW", 2866},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 448 "nasdaq.gperf"
      {"ASTH", 435},
      {""}, {""},
#line 5589 "nasdaq.gperf"
      {"ZUMZ", 5576},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2610 "nasdaq.gperf"
      {"IPVV", 2597},
#line 2611 "nasdaq.gperf"
      {"IPVVU", 2598},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3036 "nasdaq.gperf"
      {"LXEO", 3023},
      {""}, {""}, {""}, {""},
#line 2231 "nasdaq.gperf"
      {"GWRS", 2218},
#line 5449 "nasdaq.gperf"
      {"XBPEW", 5436},
#line 3458 "nasdaq.gperf"
      {"NMFC", 3445},
      {""}, {""},
#line 3638 "nasdaq.gperf"
      {"OLLI", 3625},
      {""}, {""}, {""},
#line 2727 "nasdaq.gperf"
      {"JSPR", 2714},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1178 "nasdaq.gperf"
      {"COKE", 1165},
      {""}, {""}, {""},
#line 3459 "nasdaq.gperf"
      {"NMFCZ", 3446},
      {""}, {""}, {""}, {""},
#line 4983 "nasdaq.gperf"
      {"TRMK", 4970},
      {""}, {""}, {""}, {""}, {""},
#line 4187 "nasdaq.gperf"
      {"RBKB", 4174},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1622 "nasdaq.gperf"
      {"ENVB", 1609},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 546 "nasdaq.gperf"
      {"BAFE", 533},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 916 "nasdaq.gperf"
      {"CAKE", 903},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 857 "nasdaq.gperf"
      {"BTDL", 844},
      {""}, {""}, {""}, {""}, {""},
#line 3700 "nasdaq.gperf"
      {"ORLY", 3687},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4002 "nasdaq.gperf"
      {"PSCH", 3989},
#line 2901 "nasdaq.gperf"
      {"LFCR", 2888},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5013 "nasdaq.gperf"
      {"TSEM", 5000},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2102 "nasdaq.gperf"
      {"GLDB", 2089},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5581 "nasdaq.gperf"
      {"ZSQR", 5568},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1583 "nasdaq.gperf"
      {"ELOX", 1570},
#line 5135 "nasdaq.gperf"
      {"UROY", 5122},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 530 "nasdaq.gperf"
      {"AXSM", 517},
      {""}, {""},
#line 4135 "nasdaq.gperf"
      {"QRVO", 4122},
      {""}, {""}, {""},
#line 2591 "nasdaq.gperf"
      {"IOSP", 2578},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3051 "nasdaq.gperf"
      {"MAMK", 3038},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3607 "nasdaq.gperf"
      {"OCUL", 3594},
      {""}, {""}, {""}, {""},
#line 1891 "nasdaq.gperf"
      {"FORTY", 1878},
      {""}, {""},
#line 2741 "nasdaq.gperf"
      {"KALU", 2728},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2511 "nasdaq.gperf"
      {"ILLUW", 2498},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3284 "nasdaq.gperf"
      {"MTCH", 3271},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1386 "nasdaq.gperf"
      {"DFNS", 1373},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2205 "nasdaq.gperf"
      {"GTBP", 2192},
      {""}, {""}, {""},
#line 219 "nasdaq.gperf"
      {"AISPW", 206},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5170 "nasdaq.gperf"
      {"UXIN", 5157},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1581 "nasdaq.gperf"
      {"ELOG", 1568},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2290 "nasdaq.gperf"
      {"HERE", 2277},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5176 "nasdaq.gperf"
      {"VABK", 5163},
      {""}, {""},
#line 1701 "nasdaq.gperf"
      {"EXTR", 1688},
#line 502 "nasdaq.gperf"
      {"AVGB", 489},
#line 387 "nasdaq.gperf"
      {"ARBK", 374},
      {""}, {""}, {""}, {""}, {""},
#line 3495 "nasdaq.gperf"
      {"NRXP", 3482},
      {""}, {""}, {""},
#line 5405 "nasdaq.gperf"
      {"WRTH", 5392},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1469 "nasdaq.gperf"
      {"DSGN", 1456},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3500 "nasdaq.gperf"
      {"NSLRL", 3487},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1210 "nasdaq.gperf"
      {"CPHC", 1197},
      {""}, {""}, {""}, {""}, {""},
#line 2034 "nasdaq.gperf"
      {"GDHG", 2021},
      {""}, {""}, {""}, {""},
#line 2495 "nasdaq.gperf"
      {"IGF", 2482},
      {""},
#line 3693 "nasdaq.gperf"
      {"ORIC", 3680},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4079 "nasdaq.gperf"
      {"QCML", 4066},
#line 1963 "nasdaq.gperf"
      {"FTSM", 1950},
#line 102 "nasdaq.gperf"
      {"ADAMG", 89},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1356 "nasdaq.gperf"
      {"DARE", 1343},
      {""}, {""},
#line 1156 "nasdaq.gperf"
      {"CNSP", 1143},
      {""}, {""}, {""}, {""}, {""},
#line 3578 "nasdaq.gperf"
      {"NYAX", 3565},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1155 "nasdaq.gperf"
      {"CNQQ", 1142},
#line 3626 "nasdaq.gperf"
      {"OIM", 3613},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3627 "nasdaq.gperf"
      {"OIMAU", 3614},
#line 3017 "nasdaq.gperf"
      {"LUCD", 3004},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4836 "nasdaq.gperf"
      {"TCBK", 4823},
      {""}, {""}, {""}, {""},
#line 2045 "nasdaq.gperf"
      {"GEHC", 2032},
      {""},
#line 2877 "nasdaq.gperf"
      {"LCDS", 2864},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4825 "nasdaq.gperf"
      {"TBBK", 4812},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 499 "nasdaq.gperf"
      {"AVAV", 486},
      {""}, {""}, {""}, {""},
#line 36 "nasdaq.gperf"
      {"AAPU", 23},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5318 "nasdaq.gperf"
      {"VVOS", 5305},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3246 "nasdaq.gperf"
      {"MRBK", 3233},
      {""}, {""}, {""},
#line 3604 "nasdaq.gperf"
      {"OCSAW", 3591},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1579 "nasdaq.gperf"
      {"ELIL", 1566},
      {""},
#line 2372 "nasdaq.gperf"
      {"HTZ", 2359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2669 "nasdaq.gperf"
      {"IVSX", 2656},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2994 "nasdaq.gperf"
      {"LQDA", 2981},
      {""}, {""},
#line 2667 "nasdaq.gperf"
      {"IVSI", 2654},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5358 "nasdaq.gperf"
      {"WETH", 5345},
      {""}, {""}, {""}, {""},
#line 512 "nasdaq.gperf"
      {"AVOS", 499},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3637 "nasdaq.gperf"
      {"OLED", 3624},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2828 "nasdaq.gperf"
      {"KSCP", 2815},
      {""}, {""}, {""}, {""},
#line 2297 "nasdaq.gperf"
      {"HGBL", 2284},
      {""},
#line 1617 "nasdaq.gperf"
      {"ENSC", 1604},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4887 "nasdaq.gperf"
      {"THEO", 4874},
#line 4889 "nasdaq.gperf"
      {"THEOU", 4876},
      {""}, {""}, {""}, {""},
#line 4888 "nasdaq.gperf"
      {"THEOR", 4875},
      {""},
#line 4226 "nasdaq.gperf"
      {"REFR", 4213},
      {""}, {""}, {""}, {""},
#line 3409 "nasdaq.gperf"
      {"NEUP", 3396},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1434 "nasdaq.gperf"
      {"DNLI", 1421},
      {""},
#line 4908 "nasdaq.gperf"
      {"TKLF", 4895},
      {""},
#line 4238 "nasdaq.gperf"
      {"REPL", 4225},
      {""}, {""},
#line 2158 "nasdaq.gperf"
      {"GPRE", 2145},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2888 "nasdaq.gperf"
      {"LEDS", 2875},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4077 "nasdaq.gperf"
      {"QCLS", 4064},
      {""}, {""}, {""}, {""},
#line 4566 "nasdaq.gperf"
      {"SLNH", 4553},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4650 "nasdaq.gperf"
      {"SPAM", 4637},
#line 5204 "nasdaq.gperf"
      {"VCSH", 5191},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3957 "nasdaq.gperf"
      {"PPH", 3944},
      {""},
#line 5456 "nasdaq.gperf"
      {"XCSH", 5443},
      {""},
#line 5392 "nasdaq.gperf"
      {"WLTH", 5379},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3958 "nasdaq.gperf"
      {"PPHC", 3945},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1802 "nasdaq.gperf"
      {"FFIV", 1789},
      {""}, {""}, {""},
#line 3537 "nasdaq.gperf"
      {"NVAX", 3524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2658 "nasdaq.gperf"
      {"IUS", 2645},
      {""}, {""}, {""},
#line 3548 "nasdaq.gperf"
      {"NVMI", 3535},
      {""}, {""}, {""}, {""}, {""},
#line 3554 "nasdaq.gperf"
      {"NVX", 3541},
      {""}, {""}, {""},
#line 3896 "nasdaq.gperf"
      {"PLMK", 3883},
#line 3897 "nasdaq.gperf"
      {"PLMKU", 3884},
      {""}, {""},
#line 4252 "nasdaq.gperf"
      {"RFIL", 4239},
      {""}, {""}, {""}, {""},
#line 1618 "nasdaq.gperf"
      {"ENSG", 1605},
#line 1359 "nasdaq.gperf"
      {"DAVEW", 1346},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5591 "nasdaq.gperf"
      {"ZVRA", 5578},
      {""}, {""}, {""}, {""},
#line 1394 "nasdaq.gperf"
      {"DGII", 1381},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4760 "nasdaq.gperf"
      {"SUSL", 4747},
      {""}, {""}, {""},
#line 1843 "nasdaq.gperf"
      {"FKWL", 1830},
      {""},
#line 3348 "nasdaq.gperf"
      {"NAKA", 3335},
      {""},
#line 2966 "nasdaq.gperf"
      {"LNZA", 2953},
      {""}, {""}, {""},
#line 1211 "nasdaq.gperf"
      {"CPHY", 1198},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4358 "nasdaq.gperf"
      {"RUSC", 4345},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4567 "nasdaq.gperf"
      {"SLNHP", 4554},
      {""}, {""}, {""},
#line 3775 "nasdaq.gperf"
      {"PATK", 3762},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3602 "nasdaq.gperf"
      {"OCLTU", 3589},
      {""}, {""},
#line 4938 "nasdaq.gperf"
      {"TMSWW", 4925},
      {""}, {""},
#line 770 "nasdaq.gperf"
      {"BPYPO", 757},
      {""}, {""},
#line 1108 "nasdaq.gperf"
      {"CLBK", 1095},
      {""}, {""},
#line 1531 "nasdaq.gperf"
      {"EBON", 1518},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3018 "nasdaq.gperf"
      {"LUCY", 3005},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4070 "nasdaq.gperf"
      {"QBIG", 4057},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2660 "nasdaq.gperf"
      {"IUSG", 2647},
      {""}, {""}, {""}, {""}, {""},
#line 3461 "nasdaq.gperf"
      {"NMP", 3448},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3463 "nasdaq.gperf"
      {"NMPAU", 3450},
#line 3489 "nasdaq.gperf"
      {"NRDS", 3476},
      {""}, {""}, {""},
#line 3462 "nasdaq.gperf"
      {"NMPAR", 3449},
      {""}, {""},
#line 5075 "nasdaq.gperf"
      {"TXXH", 5062},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5427 "nasdaq.gperf"
      {"WTGUU", 5414},
      {""},
#line 4075 "nasdaq.gperf"
      {"QCLN", 4062},
#line 2711 "nasdaq.gperf"
      {"JLHL", 2698},
      {""},
#line 5426 "nasdaq.gperf"
      {"WTGUR", 5413},
#line 2921 "nasdaq.gperf"
      {"LHAI", 2908},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3526 "nasdaq.gperf"
      {"NUAI", 3513},
      {""}, {""},
#line 956 "nasdaq.gperf"
      {"CBSH", 943},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 858 "nasdaq.gperf"
      {"BTDR", 845},
      {""},
#line 940 "nasdaq.gperf"
      {"CASH", 927},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5590 "nasdaq.gperf"
      {"ZURA", 5577},
      {""}, {""},
#line 3207 "nasdaq.gperf"
      {"MNDO", 3194},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4273 "nasdaq.gperf"
      {"RILYG", 4260},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2623 "nasdaq.gperf"
      {"IQQQ", 2610},
      {""}, {""}, {""},
#line 5592 "nasdaq.gperf"
      {"ZYBT", 5579},
#line 4308 "nasdaq.gperf"
      {"RNAQU", 4295},
      {""},
#line 3010 "nasdaq.gperf"
      {"LTGO", 2997},
      {""},
#line 3040 "nasdaq.gperf"
      {"LYTS", 3027},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5424 "nasdaq.gperf"
      {"WTFCN", 5411},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2578 "nasdaq.gperf"
      {"INTU", 2565},
      {""}, {""}, {""}, {""},
#line 3870 "nasdaq.gperf"
      {"PHO", 3857},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 493 "nasdaq.gperf"
      {"AURE", 480},
      {""}, {""}, {""}, {""},
#line 3827 "nasdaq.gperf"
      {"PEBK", 3814},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2325 "nasdaq.gperf"
      {"HNST", 2312},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2871 "nasdaq.gperf"
      {"LBTYA", 2858},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3383 "nasdaq.gperf"
      {"NCOOU", 3370},
      {""}, {""}, {""}, {""},
#line 3382 "nasdaq.gperf"
      {"NCOOR", 3369},
#line 5509 "nasdaq.gperf"
      {"XWEL", 5496},
      {""}, {""},
#line 1965 "nasdaq.gperf"
      {"FTXH", 1952},
      {""}, {""}, {""}, {""},
#line 3907 "nasdaq.gperf"
      {"PLTK", 3894},
#line 1440 "nasdaq.gperf"
      {"DOCU", 1427},
      {""},
#line 2932 "nasdaq.gperf"
      {"LIME", 2919},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 330 "nasdaq.gperf"
      {"ANGU", 317},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4812 "nasdaq.gperf"
      {"TARK", 4799},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2237 "nasdaq.gperf"
      {"HACQ", 2224},
#line 2238 "nasdaq.gperf"
      {"HACQU", 2225},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3129 "nasdaq.gperf"
      {"MESH", 3116},
#line 3130 "nasdaq.gperf"
      {"MESHU", 3117},
      {""}, {""}, {""}, {""},
#line 239 "nasdaq.gperf"
      {"ALFUW", 226},
#line 4067 "nasdaq.gperf"
      {"QALT", 4054},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4555 "nasdaq.gperf"
      {"SLDE", 4542},
      {""}, {""},
#line 3869 "nasdaq.gperf"
      {"PHIO", 3856},
      {""}, {""}, {""}, {""},
#line 2945 "nasdaq.gperf"
      {"LIVE", 2932},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 507 "nasdaq.gperf"
      {"AVIR", 494},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1368 "nasdaq.gperf"
      {"DCGO", 1355},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 158 "nasdaq.gperf"
      {"AFRM", 145},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2315 "nasdaq.gperf"
      {"HLNE", 2302},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2240 "nasdaq.gperf"
      {"HAFC", 2227},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4131 "nasdaq.gperf"
      {"QQXL", 4118},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2668 "nasdaq.gperf"
      {"IVSS", 2655},
#line 5128 "nasdaq.gperf"
      {"UPLD", 5115},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2612 "nasdaq.gperf"
      {"IPVVW", 2599},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3029 "nasdaq.gperf"
      {"LWAC", 3016},
#line 3030 "nasdaq.gperf"
      {"LWACU", 3017},
      {""},
#line 3535 "nasdaq.gperf"
      {"NUTX", 3522},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5428 "nasdaq.gperf"
      {"WTIP", 5415},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2728 "nasdaq.gperf"
      {"JSPRW", 2715},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2081 "nasdaq.gperf"
      {"GIFT", 2068},
#line 2600 "nasdaq.gperf"
      {"IPFX", 2587},
#line 2601 "nasdaq.gperf"
      {"IPFXU", 2588},
      {""}, {""}, {""},
#line 1447 "nasdaq.gperf"
      {"DOYU", 1434},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4909 "nasdaq.gperf"
      {"TKNO", 4896},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3555 "nasdaq.gperf"
      {"NVYY", 3542},
      {""}, {""},
#line 4334 "nasdaq.gperf"
      {"RPGL", 4321},
      {""}, {""}, {""},
#line 1345 "nasdaq.gperf"
      {"DAAQ", 1332},
#line 1346 "nasdaq.gperf"
      {"DAAQU", 1333},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2162 "nasdaq.gperf"
      {"GQQQ", 2149},
      {""}, {""}, {""},
#line 4259 "nasdaq.gperf"
      {"RGP", 4246},
#line 1415 "nasdaq.gperf"
      {"DLCU", 1402},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5077 "nasdaq.gperf"
      {"TYGO", 5064},
      {""}, {""}, {""}, {""},
#line 4095 "nasdaq.gperf"
      {"QMCO", 4082},
      {""},
#line 1335 "nasdaq.gperf"
      {"CYCU", 1322},
      {""},
#line 3643 "nasdaq.gperf"
      {"OMCL", 3630},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2565 "nasdaq.gperf"
      {"INNV", 2552},
      {""}, {""}, {""},
#line 2942 "nasdaq.gperf"
      {"LITE", 2929},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5319 "nasdaq.gperf"
      {"VWAV", 5306},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2663 "nasdaq.gperf"
      {"IVAL", 2650},
      {""}, {""}, {""}, {""}, {""},
#line 332 "nasdaq.gperf"
      {"ANIP", 319},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1388 "nasdaq.gperf"
      {"DFSC", 1375},
      {""},
#line 4355 "nasdaq.gperf"
      {"RUMBW", 4342},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1983 "nasdaq.gperf"
      {"FVAV", 1970},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3772 "nasdaq.gperf"
      {"PARK", 3759},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5122 "nasdaq.gperf"
      {"UONE", 5109},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1084 "nasdaq.gperf"
      {"CHSCN", 1071},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3212 "nasdaq.gperf"
      {"MNPR", 3199},
#line 3646 "nasdaq.gperf"
      {"OMEX", 3633},
      {""}, {""}, {""}, {""},
#line 1387 "nasdaq.gperf"
      {"DFNSW", 1374},
      {""}, {""}, {""}, {""},
#line 2504 "nasdaq.gperf"
      {"IKT", 2491},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1014 "nasdaq.gperf"
      {"CELH", 1001},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 533 "nasdaq.gperf"
      {"AYTU", 520},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4365 "nasdaq.gperf"
      {"RVSN", 4352},
      {""}, {""}, {""}, {""}, {""},
#line 3441 "nasdaq.gperf"
      {"NICE", 3428},
      {""}, {""},
#line 5060 "nasdaq.gperf"
      {"TWAV", 5047},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 504 "nasdaq.gperf"
      {"AVGO", 491},
      {""}, {""}, {""},
#line 5565 "nasdaq.gperf"
      {"ZION", 5552},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3032 "nasdaq.gperf"
      {"LWAY", 3019},
      {""}, {""}, {""}, {""},
#line 2768 "nasdaq.gperf"
      {"KEQU", 2755},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3649 "nasdaq.gperf"
      {"ON", 3636},
#line 2995 "nasdaq.gperf"
      {"LQDT", 2982},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2647 "nasdaq.gperf"
      {"ISTM", 2634},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3666 "nasdaq.gperf"
      {"ONMD", 3653},
      {""}, {""},
#line 2348 "nasdaq.gperf"
      {"HQGO", 2335},
      {""}, {""}, {""},
#line 1916 "nasdaq.gperf"
      {"FRSH", 1903},
      {""},
#line 5196 "nasdaq.gperf"
      {"VBNK", 5183},
      {""},
#line 3653 "nasdaq.gperf"
      {"ONC", 3640},
      {""}, {""}, {""},
#line 1709 "nasdaq.gperf"
      {"EZMO", 1696},
      {""}, {""}, {""}, {""}, {""},
#line 4439 "nasdaq.gperf"
      {"SCZM", 4426},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3872 "nasdaq.gperf"
      {"PHOS", 3859},
      {""},
#line 3628 "nasdaq.gperf"
      {"OIMAW", 3615},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3440 "nasdaq.gperf"
      {"NHTC", 3427},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3553 "nasdaq.gperf"
      {"NVTS", 3540},
      {""}, {""}, {""},
#line 5566 "nasdaq.gperf"
      {"ZIONP", 5553},
      {""}, {""},
#line 2326 "nasdaq.gperf"
      {"HNVR", 2313},
      {""},
#line 2918 "nasdaq.gperf"
      {"LGO", 2905},
      {""}, {""},
#line 3711 "nasdaq.gperf"
      {"OSS", 3698},
#line 3446 "nasdaq.gperf"
      {"NIOG", 3433},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3598 "nasdaq.gperf"
      {"OCCIN", 3585},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5087 "nasdaq.gperf"
      {"UCFI", 5074},
#line 725 "nasdaq.gperf"
      {"BMHL", 712},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 487 "nasdaq.gperf"
      {"AUGO", 474},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4642 "nasdaq.gperf"
      {"SOTK", 4629},
#line 2523 "nasdaq.gperf"
      {"IMNM", 2510},
      {""},
#line 1393 "nasdaq.gperf"
      {"DGICB", 1380},
      {""}, {""}, {""}, {""},
#line 1631 "nasdaq.gperf"
      {"EPSN", 1618},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 518 "nasdaq.gperf"
      {"AVUQ", 505},
      {""},
#line 523 "nasdaq.gperf"
      {"AWRE", 510},
      {""}, {""},
#line 4689 "nasdaq.gperf"
      {"SRBK", 4676},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3539 "nasdaq.gperf"
      {"NVCT", 3526},
      {""}, {""},
#line 1555 "nasdaq.gperf"
      {"EFSC", 1542},
      {""}, {""}, {""},
#line 875 "nasdaq.gperf"
      {"BULL", 862},
#line 1557 "nasdaq.gperf"
      {"EFSI", 1544},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4841 "nasdaq.gperf"
      {"TCOM", 4828},
      {""}, {""},
#line 4097 "nasdaq.gperf"
      {"QMLS", 4084},
      {""}, {""}, {""},
#line 5071 "nasdaq.gperf"
      {"TXRH", 5058},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1384 "nasdaq.gperf"
      {"DFLI", 1371},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4096 "nasdaq.gperf"
      {"QMID", 4083},
      {""}, {""}, {""},
#line 3533 "nasdaq.gperf"
      {"NUR", 3520},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5129 "nasdaq.gperf"
      {"UPST", 5116},
      {""}, {""}, {""}, {""},
#line 3072 "nasdaq.gperf"
      {"MBINM", 3059},
      {""}, {""}, {""}, {""}, {""},
#line 953 "nasdaq.gperf"
      {"CBNK", 940},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3273 "nasdaq.gperf"
      {"MSGM", 3260},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4100 "nasdaq.gperf"
      {"QNCX", 4087},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4488 "nasdaq.gperf"
      {"SGHT", 4475},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1277 "nasdaq.gperf"
      {"CSHR", 1264},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4116 "nasdaq.gperf"
      {"QQQ", 4103},
      {""}, {""}, {""}, {""}, {""},
#line 4117 "nasdaq.gperf"
      {"QQQA", 4104},
      {""}, {""}, {""}, {""},
#line 4127 "nasdaq.gperf"
      {"QQQX", 4114},
      {""}, {""}, {""},
#line 3898 "nasdaq.gperf"
      {"PLMKW", 3885},
      {""}, {""}, {""}, {""},
#line 1556 "nasdaq.gperf"
      {"EFSCP", 1543},
#line 4121 "nasdaq.gperf"
      {"QQQI", 4108},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3600 "nasdaq.gperf"
      {"OCG", 3587},
      {""}, {""}, {""}, {""}, {""},
#line 4795 "nasdaq.gperf"
      {"SYRE", 4782},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3866 "nasdaq.gperf"
      {"PGYWW", 3853},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2967 "nasdaq.gperf"
      {"LNZAW", 2954},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3650 "nasdaq.gperf"
      {"ONB", 3637},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1448 "nasdaq.gperf"
      {"DPRO", 1435},
      {""}, {""},
#line 4122 "nasdaq.gperf"
      {"QQQJ", 4109},
      {""}, {""}, {""},
#line 3208 "nasdaq.gperf"
      {"MNDR", 3195},
      {""}, {""}, {""},
#line 3658 "nasdaq.gperf"
      {"ONCY", 3645},
      {""},
#line 4722 "nasdaq.gperf"
      {"STIM", 4709},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5120 "nasdaq.gperf"
      {"UNIY", 5107},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3019 "nasdaq.gperf"
      {"LUCYW", 3006},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3011 "nasdaq.gperf"
      {"LTGR", 2998},
#line 3012 "nasdaq.gperf"
      {"LTGRU", 2999},
      {""}, {""},
#line 2370 "nasdaq.gperf"
      {"HTO", 2357},
      {""}, {""},
#line 3556 "nasdaq.gperf"
      {"NWBI", 3543},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4119 "nasdaq.gperf"
      {"QQQG", 4106},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1612 "nasdaq.gperf"
      {"ENLT", 1599},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 819 "nasdaq.gperf"
      {"BSEM", 806},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4149 "nasdaq.gperf"
      {"QTTB", 4136},
#line 5308 "nasdaq.gperf"
      {"VTHR", 5295},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2123 "nasdaq.gperf"
      {"GMHS", 2110},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1828 "nasdaq.gperf"
      {"FINW", 1815},
#line 3527 "nasdaq.gperf"
      {"NUAIW", 3514},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4431 "nasdaq.gperf"
      {"SCPQ", 4418},
#line 4432 "nasdaq.gperf"
      {"SCPQU", 4419},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3564 "nasdaq.gperf"
      {"NWTG", 3551},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 103 "nasdaq.gperf"
      {"ADAMH", 90},
      {""}, {""}, {""}, {""}, {""},
#line 4668 "nasdaq.gperf"
      {"SPPL", 4655},
      {""}, {""}, {""},
#line 4894 "nasdaq.gperf"
      {"THRV", 4881},
      {""},
#line 2679 "nasdaq.gperf"
      {"JACK", 2666},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3272 "nasdaq.gperf"
      {"MSFU", 3259},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 464 "nasdaq.gperf"
      {"ATHR", 451},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1879 "nasdaq.gperf"
      {"FNKO", 1866},
      {""}, {""}, {""}, {""},
#line 4105 "nasdaq.gperf"
      {"QNT", 4092},
      {""},
#line 2236 "nasdaq.gperf"
      {"GYRO", 2223},
      {""}, {""},
#line 2488 "nasdaq.gperf"
      {"IFGL", 2475},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2329 "nasdaq.gperf"
      {"HOFT", 2316},
      {""},
#line 4109 "nasdaq.gperf"
      {"QPUX", 4096},
      {""}, {""},
#line 4914 "nasdaq.gperf"
      {"TLIH", 4901},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3683 "nasdaq.gperf"
      {"OPTX", 3670},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3685 "nasdaq.gperf"
      {"OPTZ", 3672},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2129 "nasdaq.gperf"
      {"GNPX", 2116},
      {""}, {""}, {""}, {""},
#line 5153 "nasdaq.gperf"
      {"USOI", 5140},
      {""}, {""}, {""},
#line 4774 "nasdaq.gperf"
      {"SVRE", 4761},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4091 "nasdaq.gperf"
      {"QGRD", 4078},
#line 3384 "nasdaq.gperf"
      {"NCOOW", 3371},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4099 "nasdaq.gperf"
      {"QNBC", 4086},
      {""}, {""}, {""}, {""}, {""},
#line 2316 "nasdaq.gperf"
      {"HLP", 2303},
      {""}, {""}, {""},
#line 3022 "nasdaq.gperf"
      {"LUNG", 3009},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2441 "nasdaq.gperf"
      {"IBKR", 2428},
      {""}, {""}, {""}, {""},
#line 3221 "nasdaq.gperf"
      {"MNYWW", 3208},
#line 1654 "nasdaq.gperf"
      {"ESOA", 1641},
#line 2239 "nasdaq.gperf"
      {"HACQW", 2226},
      {""}, {""}, {""}, {""},
#line 5323 "nasdaq.gperf"
      {"VYGR", 5310},
      {""}, {""},
#line 3131 "nasdaq.gperf"
      {"MESHW", 3118},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4469 "nasdaq.gperf"
      {"SEPQ", 4456},
      {""}, {""}, {""}, {""},
#line 4128 "nasdaq.gperf"
      {"QQQY", 4115},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4212 "nasdaq.gperf"
      {"RDNW", 4199},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5150 "nasdaq.gperf"
      {"USIO", 5137},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4693 "nasdaq.gperf"
      {"SRRK", 4680},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 591 "nasdaq.gperf"
      {"BCTK", 578},
      {""}, {""}, {""}, {""},
#line 2963 "nasdaq.gperf"
      {"LNSR", 2950},
      {""},
#line 3565 "nasdaq.gperf"
      {"NXGL", 3552},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2293 "nasdaq.gperf"
      {"HFBL", 2280},
      {""}, {""},
#line 974 "nasdaq.gperf"
      {"CCGWW", 961},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4375 "nasdaq.gperf"
      {"RYET", 4362},
      {""}, {""}, {""},
#line 2548 "nasdaq.gperf"
      {"IND", 2535},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4538 "nasdaq.gperf"
      {"SKIN", 4525},
      {""},
#line 3549 "nasdaq.gperf"
      {"NVNI", 3536},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2814 "nasdaq.gperf"
      {"KQQQ", 2801},
#line 2551 "nasdaq.gperf"
      {"INDI", 2538},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4400 "nasdaq.gperf"
      {"SARK", 4387},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3031 "nasdaq.gperf"
      {"LWACW", 3018},
      {""}, {""}, {""},
#line 1578 "nasdaq.gperf"
      {"ELFY", 1565},
#line 5329 "nasdaq.gperf"
      {"WAFU", 5316},
      {""}, {""}, {""},
#line 4606 "nasdaq.gperf"
      {"SNDL", 4593},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2638 "nasdaq.gperf"
      {"ISHG", 2625},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2602 "nasdaq.gperf"
      {"IPFXW", 2589},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 168 "nasdaq.gperf"
      {"AGMH", 155},
#line 1194 "nasdaq.gperf"
      {"COPP", 1181},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4232 "nasdaq.gperf"
      {"REKR", 4219},
      {""}, {""}, {""}, {""},
#line 3510 "nasdaq.gperf"
      {"NTGR", 3497},
      {""}, {""}, {""}, {""},
#line 4720 "nasdaq.gperf"
      {"STHO", 4707},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2569 "nasdaq.gperf"
      {"INSE", 2556},
      {""}, {""}, {""}, {""},
#line 1347 "nasdaq.gperf"
      {"DAAQW", 1334},
#line 1239 "nasdaq.gperf"
      {"CRESY", 1226},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2998 "nasdaq.gperf"
      {"LRGE", 2985},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2255 "nasdaq.gperf"
      {"HBDC", 2242},
#line 1336 "nasdaq.gperf"
      {"CYCUW", 1323},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3350 "nasdaq.gperf"
      {"NAMM", 3337},
      {""},
#line 3686 "nasdaq.gperf"
      {"OPXS", 3673},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3385 "nasdaq.gperf"
      {"NCPB", 3372},
      {""}, {""}, {""},
#line 5320 "nasdaq.gperf"
      {"VWAVW", 5307},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1712 "nasdaq.gperf"
      {"EZRO", 1699},
      {""},
#line 4125 "nasdaq.gperf"
      {"QQQS", 4112},
      {""}, {""}, {""}, {""}, {""},
#line 5154 "nasdaq.gperf"
      {"USOY", 5141},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1389 "nasdaq.gperf"
      {"DFSCW", 1376},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2097 "nasdaq.gperf"
      {"GKAT", 2084},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1376 "nasdaq.gperf"
      {"DEFT", 1363},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2189 "nasdaq.gperf"
      {"GSHD", 2176},
      {""}, {""}, {""},
#line 1479 "nasdaq.gperf"
      {"DTIL", 1466},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2780 "nasdaq.gperf"
      {"KIDZ", 2767},
      {""}, {""},
#line 2254 "nasdaq.gperf"
      {"HBCP", 2241},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3211 "nasdaq.gperf"
      {"MNOV", 3198},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4333 "nasdaq.gperf"
      {"RPD", 4320},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2651 "nasdaq.gperf"
      {"ITHA", 2638},
#line 2652 "nasdaq.gperf"
      {"ITHAU", 2639},
      {""}, {""}, {""},
#line 2408 "nasdaq.gperf"
      {"HYMC", 2395},
#line 4366 "nasdaq.gperf"
      {"RVSNW", 4353},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5119 "nasdaq.gperf"
      {"UNIT", 5106},
      {""}, {""},
#line 2938 "nasdaq.gperf"
      {"LINE", 2925},
      {""}, {""}, {""},
#line 2001 "nasdaq.gperf"
      {"FXHO", 1988},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3417 "nasdaq.gperf"
      {"NEXM", 3404},
      {""}, {""}, {""}, {""}, {""},
#line 3472 "nasdaq.gperf"
      {"NNOX", 3459},
#line 737 "nasdaq.gperf"
      {"BNCWZ", 724},
#line 4479 "nasdaq.gperf"
      {"SFHG", 4466},
      {""}, {""}, {""},
#line 4054 "nasdaq.gperf"
      {"PXLW", 4041},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4350 "nasdaq.gperf"
      {"RTH", 4337},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 728 "nasdaq.gperf"
      {"BMOP", 715},
#line 2555 "nasdaq.gperf"
      {"INDY", 2542},
      {""}, {""}, {""}, {""}, {""},
#line 1537 "nasdaq.gperf"
      {"ECPG", 1524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2847 "nasdaq.gperf"
      {"KYNB", 2834},
      {""}, {""}, {""}, {""}, {""},
#line 2722 "nasdaq.gperf"
      {"JRSH", 2709},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4142 "nasdaq.gperf"
      {"QSML", 4129},
      {""}, {""}, {""},
#line 4057 "nasdaq.gperf"
      {"PYPD", 4044},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4103 "nasdaq.gperf"
      {"QNRX", 4090},
      {""},
#line 2287 "nasdaq.gperf"
      {"HEPS", 2274},
      {""},
#line 3667 "nasdaq.gperf"
      {"ONMDW", 3654},
      {""}, {""}, {""}, {""},
#line 3679 "nasdaq.gperf"
      {"OPRA", 3666},
      {""}, {""}, {""}, {""},
#line 3681 "nasdaq.gperf"
      {"OPRX", 3668},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5008 "nasdaq.gperf"
      {"TSBK", 4995},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 162 "nasdaq.gperf"
      {"AGEM", 149},
      {""}, {""}, {""}, {""}, {""},
#line 1652 "nasdaq.gperf"
      {"ESMV", 1639},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3601 "nasdaq.gperf"
      {"OCGN", 3588},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1981 "nasdaq.gperf"
      {"FUTU", 1968},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4597 "nasdaq.gperf"
      {"SMTK", 4584},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5088 "nasdaq.gperf"
      {"UCFIW", 5075},
#line 3721 "nasdaq.gperf"
      {"OTLY", 3708},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2244 "nasdaq.gperf"
      {"HAPN", 2231},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4137 "nasdaq.gperf"
      {"QSEA", 4124},
#line 4139 "nasdaq.gperf"
      {"QSEAU", 4126},
      {""}, {""}, {""}, {""},
#line 4138 "nasdaq.gperf"
      {"QSEAR", 4125},
      {""}, {""},
#line 3485 "nasdaq.gperf"
      {"NPCE", 3472},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4058 "nasdaq.gperf"
      {"PYPG", 4045},
      {""}, {""}, {""},
#line 1513 "nasdaq.gperf"
      {"DYAI", 1500},
      {""}, {""}, {""},
#line 5061 "nasdaq.gperf"
      {"TWFG", 5048},
#line 4107 "nasdaq.gperf"
      {"QNXT", 4094},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2927 "nasdaq.gperf"
      {"LIF", 2914},
      {""}, {""}, {""},
#line 2699 "nasdaq.gperf"
      {"JEPQ", 2686},
      {""}, {""}, {""}, {""}, {""},
#line 3282 "nasdaq.gperf"
      {"MTAKU", 3269},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2390 "nasdaq.gperf"
      {"HVMC", 2377},
#line 2391 "nasdaq.gperf"
      {"HVMCU", 2378},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4126 "nasdaq.gperf"
      {"QQQT", 4113},
      {""}, {""},
#line 876 "nasdaq.gperf"
      {"BULLW", 863},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1044 "nasdaq.gperf"
      {"CGEM", 1031},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2766 "nasdaq.gperf"
      {"KELYA", 2753},
      {""}, {""}, {""}, {""},
#line 1549 "nasdaq.gperf"
      {"EEFT", 1536},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1385 "nasdaq.gperf"
      {"DFLIW", 1372},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4509 "nasdaq.gperf"
      {"SHOT", 4496},
#line 4511 "nasdaq.gperf"
      {"SHOTU", 4498},
      {""}, {""},
#line 3346 "nasdaq.gperf"
      {"NAGE", 3333},
      {""},
#line 4510 "nasdaq.gperf"
      {"SHOTR", 4497},
      {""}, {""},
#line 172 "nasdaq.gperf"
      {"AGNCM", 159},
#line 2999 "nasdaq.gperf"
      {"LRHC", 2986},
      {""}, {""}, {""}, {""}, {""},
#line 4290 "nasdaq.gperf"
      {"RKNG", 4277},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4140 "nasdaq.gperf"
      {"QSI", 4127},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4141 "nasdaq.gperf"
      {"QSIX", 4128},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2502 "nasdaq.gperf"
      {"IIIV", 2489},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2403 "nasdaq.gperf"
      {"HYBI", 2390},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5379 "nasdaq.gperf"
      {"WKEY", 5366},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1278 "nasdaq.gperf"
      {"CSHRW", 1265},
      {""}, {""},
#line 4762 "nasdaq.gperf"
      {"SVAQ", 4749},
#line 4763 "nasdaq.gperf"
      {"SVAQU", 4750},
#line 356 "nasdaq.gperf"
      {"APLM", 343},
#line 3715 "nasdaq.gperf"
      {"OTEX", 3702},
      {""}, {""}, {""},
#line 4363 "nasdaq.gperf"
      {"RVNL", 4350},
      {""}, {""}, {""}, {""}, {""},
#line 2987 "nasdaq.gperf"
      {"LPCV", 2974},
#line 2988 "nasdaq.gperf"
      {"LPCVU", 2975},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4752 "nasdaq.gperf"
      {"SUNE", 4739},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 648 "nasdaq.gperf"
      {"BHAV", 635},
#line 650 "nasdaq.gperf"
      {"BHAVU", 637},
      {""}, {""}, {""}, {""},
#line 649 "nasdaq.gperf"
      {"BHAVR", 636},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4663 "nasdaq.gperf"
      {"SPKL", 4650},
#line 4664 "nasdaq.gperf"
      {"SPKLU", 4651},
      {""},
#line 2381 "nasdaq.gperf"
      {"HUMA", 2368},
      {""}, {""},
#line 3506 "nasdaq.gperf"
      {"NTAP", 3493},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4465 "nasdaq.gperf"
      {"SENEA", 4452},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3119 "nasdaq.gperf"
      {"MEDP", 3106},
      {""}, {""}, {""},
#line 2734 "nasdaq.gperf"
      {"JWEL", 2721},
      {""},
#line 3337 "nasdaq.gperf"
      {"MYSE", 3324},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3335 "nasdaq.gperf"
      {"MYPS", 3322},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3569 "nasdaq.gperf"
      {"NXPI", 3556},
      {""}, {""}, {""}, {""},
#line 2839 "nasdaq.gperf"
      {"KUST", 2826},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2285 "nasdaq.gperf"
      {"HELE", 2272},
#line 3013 "nasdaq.gperf"
      {"LTGRW", 3000},
#line 5082 "nasdaq.gperf"
      {"UBCP", 5069},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3730 "nasdaq.gperf"
      {"OXLC", 3717},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1523 "nasdaq.gperf"
      {"DYTA", 1510},
      {""},
#line 708 "nasdaq.gperf"
      {"BLRK", 695},
#line 709 "nasdaq.gperf"
      {"BLRKU", 696},
      {""}, {""}, {""},
#line 3737 "nasdaq.gperf"
      {"OXLCZ", 3724},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1352 "nasdaq.gperf"
      {"DAK", 1339},
      {""}, {""}, {""},
#line 1626 "nasdaq.gperf"
      {"EOSE", 1613},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4393 "nasdaq.gperf"
      {"SAIH", 4380},
      {""}, {""}, {""},
#line 2446 "nasdaq.gperf"
      {"IBTH", 2433},
      {""}, {""}, {""},
#line 75 "nasdaq.gperf"
      {"ACHV", 62},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2779 "nasdaq.gperf"
      {"KIDS", 2766},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4433 "nasdaq.gperf"
      {"SCPQW", 4420},
      {""}, {""}, {""},
#line 3376 "nasdaq.gperf"
      {"NCIQ", 3363},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5288 "nasdaq.gperf"
      {"VRSK", 5275},
      {""}, {""}, {""}, {""},
#line 4144 "nasdaq.gperf"
      {"QTEX", 4131},
      {""}, {""}, {""}, {""},
#line 4143 "nasdaq.gperf"
      {"QTEC", 4130},
      {""}, {""},
#line 3076 "nasdaq.gperf"
      {"MBNKO", 3063},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 486 "nasdaq.gperf"
      {"AUDC", 473},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2846 "nasdaq.gperf"
      {"KYMR", 2833},
      {""}, {""}, {""}, {""}, {""},
#line 408 "nasdaq.gperf"
      {"AROW", 395},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3684 "nasdaq.gperf"
      {"OPTXW", 3671},
      {""}, {""}, {""}, {""}, {""},
#line 1698 "nasdaq.gperf"
      {"EXOZ", 1685},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1419 "nasdaq.gperf"
      {"DLPN", 1406},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4775 "nasdaq.gperf"
      {"SVREW", 4762},
      {""}, {""}, {""}, {""},
#line 1501 "nasdaq.gperf"
      {"DVY", 1488},
      {""}, {""}, {""}, {""}, {""},
#line 1075 "nasdaq.gperf"
      {"CHPX", 1062},
#line 123 "nasdaq.gperf"
      {"ADSK", 110},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4364 "nasdaq.gperf"
      {"RVSB", 4351},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 561 "nasdaq.gperf"
      {"BATRK", 548},
      {""},
#line 1348 "nasdaq.gperf"
      {"DADS", 1335},
      {""},
#line 3713 "nasdaq.gperf"
      {"OSUR", 3700},
      {""}, {""}, {""}, {""}, {""},
#line 4988 "nasdaq.gperf"
      {"TROW", 4975},
      {""}, {""}, {""}, {""},
#line 788 "nasdaq.gperf"
      {"BRKU", 775},
      {""},
#line 4145 "nasdaq.gperf"
      {"QTI", 4132},
      {""}, {""}, {""}, {""},
#line 2385 "nasdaq.gperf"
      {"HUT", 2372},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4161 "nasdaq.gperf"
      {"QXL", 4148},
      {""},
#line 3706 "nasdaq.gperf"
      {"OSIS", 3693},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3732 "nasdaq.gperf"
      {"OXLCI", 3719},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3854 "nasdaq.gperf"
      {"PFOE", 3841},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5164 "nasdaq.gperf"
      {"UTRE", 5151},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3295 "nasdaq.gperf"
      {"MUD", 3282},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2374 "nasdaq.gperf"
      {"HUBC", 2361},
      {""}, {""},
#line 892 "nasdaq.gperf"
      {"BYFC", 879},
      {""}, {""}, {""}, {""},
#line 5334 "nasdaq.gperf"
      {"WASH", 5321},
#line 2596 "nasdaq.gperf"
      {"IPDN", 2583},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4814 "nasdaq.gperf"
      {"TASK", 4801},
      {""}, {""},
#line 2376 "nasdaq.gperf"
      {"HUBCZ", 2363},
      {""}, {""}, {""}, {""},
#line 3048 "nasdaq.gperf"
      {"MAGH", 3035},
      {""},
#line 3566 "nasdaq.gperf"
      {"NXGLW", 3553},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4370 "nasdaq.gperf"
      {"RWIN", 4357},
      {""},
#line 2659 "nasdaq.gperf"
      {"IUSB", 2646},
      {""}, {""}, {""}, {""},
#line 1071 "nasdaq.gperf"
      {"CHPG", 1058},
#line 1073 "nasdaq.gperf"
      {"CHPGU", 1060},
      {""}, {""}, {""}, {""},
#line 1072 "nasdaq.gperf"
      {"CHPGR", 1059},
      {""}, {""}, {""}, {""},
#line 3550 "nasdaq.gperf"
      {"NVNIW", 3537},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1661 "nasdaq.gperf"
      {"ETON", 1648},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3605 "nasdaq.gperf"
      {"OCSL", 3592},
#line 2644 "nasdaq.gperf"
      {"ISPR", 2631},
      {""},
#line 1671 "nasdaq.gperf"
      {"EVAX", 1658},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2386 "nasdaq.gperf"
      {"HUTG", 2373},
#line 1695 "nasdaq.gperf"
      {"EXEL", 1682},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2234 "nasdaq.gperf"
      {"GYGY", 2221},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4250 "nasdaq.gperf"
      {"RFDI", 4237},
      {""}, {""}, {""}, {""},
#line 5321 "nasdaq.gperf"
      {"VWOB", 5308},
#line 3057 "nasdaq.gperf"
      {"MASK", 3044},
      {""}, {""}, {""}, {""},
#line 2818 "nasdaq.gperf"
      {"KRKR", 2805},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 501 "nasdaq.gperf"
      {"AVBP", 488},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2377 "nasdaq.gperf"
      {"HUBG", 2364},
      {""}, {""}, {""}, {""},
#line 1299 "nasdaq.gperf"
      {"CTSH", 1286},
      {""}, {""}, {""}, {""}, {""},
#line 4890 "nasdaq.gperf"
      {"THFF", 4877},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 513 "nasdaq.gperf"
      {"AVPT", 500},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 879 "nasdaq.gperf"
      {"BUUU", 866},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5138 "nasdaq.gperf"
      {"USAU", 5125},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 755 "nasdaq.gperf"
      {"BOOM", 742},
      {""}, {""}, {""}, {""},
#line 3733 "nasdaq.gperf"
      {"OXLCL", 3720},
#line 3351 "nasdaq.gperf"
      {"NAMMW", 3338},
      {""}, {""},
#line 4881 "nasdaq.gperf"
      {"TGHL", 4868},
#line 3430 "nasdaq.gperf"
      {"NGNE", 3417},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1602 "nasdaq.gperf"
      {"EMPD", 1589},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1664 "nasdaq.gperf"
      {"EU", 1651},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 184 "nasdaq.gperf"
      {"AHD", 171},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1317 "nasdaq.gperf"
      {"CVKD", 1304},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2309 "nasdaq.gperf"
      {"HIVE", 2296},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5368 "nasdaq.gperf"
      {"WHLR", 5355},
      {""}, {""}, {""}, {""},
#line 2800 "nasdaq.gperf"
      {"KNDI", 2787},
#line 1401 "nasdaq.gperf"
      {"DH", 1388},
      {""}, {""},
#line 5147 "nasdaq.gperf"
      {"USGO", 5134},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1402 "nasdaq.gperf"
      {"DHC", 1389},
      {""}, {""}, {""}, {""}, {""},
#line 2781 "nasdaq.gperf"
      {"KIDZW", 2768},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5230 "nasdaq.gperf"
      {"VHCP", 5217},
#line 5231 "nasdaq.gperf"
      {"VHCPU", 5218},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1609 "nasdaq.gperf"
      {"ENGS", 1596},
      {""}, {""}, {""}, {""}, {""},
#line 1128 "nasdaq.gperf"
      {"CLSK", 1115},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3680 "nasdaq.gperf"
      {"OPRT", 3667},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2653 "nasdaq.gperf"
      {"ITHAW", 2640},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2414 "nasdaq.gperf"
      {"HYXF", 2401},
      {""}, {""},
#line 2629 "nasdaq.gperf"
      {"IRHO", 2616},
#line 2631 "nasdaq.gperf"
      {"IRHOU", 2618},
      {""}, {""}, {""},
#line 736 "nasdaq.gperf"
      {"BNCWW", 723},
#line 2630 "nasdaq.gperf"
      {"IRHOR", 2617},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2394 "nasdaq.gperf"
      {"HWC", 2381},
      {""}, {""}, {""}, {""},
#line 2560 "nasdaq.gperf"
      {"INKT", 2547},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5168 "nasdaq.gperf"
      {"UUUG", 5155},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5371 "nasdaq.gperf"
      {"WHLRP", 5358},
#line 1450 "nasdaq.gperf"
      {"DPZ", 1437},
      {""},
#line 707 "nasdaq.gperf"
      {"BLNK", 694},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 869 "nasdaq.gperf"
      {"BUFC", 856},
      {""},
#line 3386 "nasdaq.gperf"
      {"NCPL", 3373},
      {""}, {""},
#line 870 "nasdaq.gperf"
      {"BUFI", 857},
      {""}, {""},
#line 1406 "nasdaq.gperf"
      {"DIME", 1393},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1383 "nasdaq.gperf"
      {"DFGX", 1370},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4050 "nasdaq.gperf"
      {"PWP", 4037},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4380 "nasdaq.gperf"
      {"RZLV", 4367},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1408 "nasdaq.gperf"
      {"DIOD", 1395},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2270 "nasdaq.gperf"
      {"HCKT", 2257},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2810 "nasdaq.gperf"
      {"KPDD", 2797},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1395 "nasdaq.gperf"
      {"DGLO", 1382},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1074 "nasdaq.gperf"
      {"CHPS", 1061},
#line 5145 "nasdaq.gperf"
      {"USFI", 5132},
      {""}, {""},
#line 4723 "nasdaq.gperf"
      {"STKE", 4710},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2382 "nasdaq.gperf"
      {"HURA", 2369},
      {""}, {""}, {""}, {""}, {""},
#line 3518 "nasdaq.gperf"
      {"NTRP", 3505},
      {""}, {""}, {""},
#line 2383 "nasdaq.gperf"
      {"HURC", 2370},
      {""}, {""}, {""}, {""}, {""},
#line 3722 "nasdaq.gperf"
      {"OTTR", 3709},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1607 "nasdaq.gperf"
      {"ENGN", 1594},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 195 "nasdaq.gperf"
      {"AIFU", 182},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2392 "nasdaq.gperf"
      {"HVMCW", 2379},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4897 "nasdaq.gperf"
      {"THYP", 4884},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4714 "nasdaq.gperf"
      {"STAK", 4701},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1566 "nasdaq.gperf"
      {"EH", 1553},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 585 "nasdaq.gperf"
      {"BCGWW", 572},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4208 "nasdaq.gperf"
      {"RDHL", 4195},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4756 "nasdaq.gperf"
      {"SUPX", 4743},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1323 "nasdaq.gperf"
      {"CWD", 1310},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5439 "nasdaq.gperf"
      {"WYFI", 5426},
      {""}, {""},
#line 4764 "nasdaq.gperf"
      {"SVAQW", 4751},
      {""},
#line 357 "nasdaq.gperf"
      {"APLMW", 344},
      {""}, {""}, {""},
#line 4590 "nasdaq.gperf"
      {"SMOM", 4577},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2989 "nasdaq.gperf"
      {"LPCVW", 2976},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1576 "nasdaq.gperf"
      {"ELDN", 1563},
#line 5097 "nasdaq.gperf"
      {"UFG", 5084},
#line 5370 "nasdaq.gperf"
      {"WHLRL", 5357},
#line 1353 "nasdaq.gperf"
      {"DAKT", 1340},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1640 "nasdaq.gperf"
      {"ERIE", 1627},
#line 4665 "nasdaq.gperf"
      {"SPKLW", 4652},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1175 "nasdaq.gperf"
      {"COHU", 1162},
      {""},
#line 1978 "nasdaq.gperf"
      {"FUSE", 1965},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3447 "nasdaq.gperf"
      {"NIPG", 3434},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1634 "nasdaq.gperf"
      {"EQPT", 1621},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 652 "nasdaq.gperf"
      {"BHF", 639},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3694 "nasdaq.gperf"
      {"ORIO", 3681},
      {""}, {""},
#line 3020 "nasdaq.gperf"
      {"LULG", 3007},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1582 "nasdaq.gperf"
      {"ELOL", 1569},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 710 "nasdaq.gperf"
      {"BLRKW", 697},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1627 "nasdaq.gperf"
      {"EOSEW", 1614},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1506 "nasdaq.gperf"
      {"DWTX", 1493},
      {""},
#line 4394 "nasdaq.gperf"
      {"SAIHW", 4381},
      {""}, {""},
#line 4499 "nasdaq.gperf"
      {"SHFS", 4486},
      {""}, {""}, {""}, {""}, {""},
#line 3591 "nasdaq.gperf"
      {"OBIO", 3578},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2080 "nasdaq.gperf"
      {"GIEQ", 2067},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 475 "nasdaq.gperf"
      {"ATOM", 462},
#line 4556 "nasdaq.gperf"
      {"SLDP", 4543},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4743 "nasdaq.gperf"
      {"STTK", 4730},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5244 "nasdaq.gperf"
      {"VIVK", 5231},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 657 "nasdaq.gperf"
      {"BHFAP", 644},
      {""},
#line 1470 "nasdaq.gperf"
      {"DSGR", 1457},
      {""}, {""}, {""}, {""}, {""},
#line 1457 "nasdaq.gperf"
      {"DRIV", 1444},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1472 "nasdaq.gperf"
      {"DSP", 1459},
#line 1515 "nasdaq.gperf"
      {"DYN", 1502},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1373 "nasdaq.gperf"
      {"DDIV", 1360},
      {""}, {""}, {""},
#line 3611 "nasdaq.gperf"
      {"ODTE", 3598},
#line 1517 "nasdaq.gperf"
      {"DYNC", 1504},
#line 1518 "nasdaq.gperf"
      {"DYNCU", 1505},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3640 "nasdaq.gperf"
      {"OLOX", 3627},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4162 "nasdaq.gperf"
      {"QXQ", 4149},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1677 "nasdaq.gperf"
      {"EVMT", 1664},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1683 "nasdaq.gperf"
      {"EVRG", 1670},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3736 "nasdaq.gperf"
      {"OXLCO", 3723},
#line 2375 "nasdaq.gperf"
      {"HUBCW", 2362},
#line 4677 "nasdaq.gperf"
      {"SPWH", 4664},
      {""}, {""}, {""},
#line 3716 "nasdaq.gperf"
      {"OTGA", 3703},
#line 3717 "nasdaq.gperf"
      {"OTGAU", 3704},
      {""},
#line 3590 "nasdaq.gperf"
      {"OBIL", 3577},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 807 "nasdaq.gperf"
      {"BSBK", 794},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2943 "nasdaq.gperf"
      {"LITP", 2930},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4083 "nasdaq.gperf"
      {"QDEL", 4070},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1502 "nasdaq.gperf"
      {"DWAS", 1489},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3486 "nasdaq.gperf"
      {"NPFI", 3473},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2761 "nasdaq.gperf"
      {"KDKRW", 2748},
      {""}, {""},
#line 1060 "nasdaq.gperf"
      {"CHDN", 1047},
      {""}, {""},
#line 3728 "nasdaq.gperf"
      {"OXBR", 3715},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1691 "nasdaq.gperf"
      {"EWTX", 1678},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1507 "nasdaq.gperf"
      {"DWUS", 1494},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 887 "nasdaq.gperf"
      {"BWFG", 874},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1689 "nasdaq.gperf"
      {"EWBC", 1676},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 653 "nasdaq.gperf"
      {"BHFAL", 640},
      {""}, {""},
#line 3026 "nasdaq.gperf"
      {"LVIG", 3013},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2736 "nasdaq.gperf"
      {"JYD", 2723},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4270 "nasdaq.gperf"
      {"RIFR", 4257},
      {""}, {""}, {""},
#line 1113 "nasdaq.gperf"
      {"CLIK", 1100},
      {""}, {""}, {""}, {""},
#line 2438 "nasdaq.gperf"
      {"IBGM", 2425},
#line 4784 "nasdaq.gperf"
      {"SWP", 4771},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1403 "nasdaq.gperf"
      {"DHCNI", 1390},
      {""}, {""},
#line 1535 "nasdaq.gperf"
      {"ECOR", 1522},
      {""},
#line 2384 "nasdaq.gperf"
      {"HURN", 2371},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2460 "nasdaq.gperf"
      {"ICHR", 2447},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4410 "nasdaq.gperf"
      {"SBFM", 4397},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3176 "nasdaq.gperf"
      {"MITK", 3163},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5232 "nasdaq.gperf"
      {"VHCPW", 5219},
      {""}, {""}, {""}, {""},
#line 1993 "nasdaq.gperf"
      {"FWDI", 1980},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1129 "nasdaq.gperf"
      {"CLSKW", 1116},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3562 "nasdaq.gperf"
      {"NWS", 3549},
#line 4288 "nasdaq.gperf"
      {"RKLX", 4275},
      {""}, {""}, {""}, {""},
#line 3563 "nasdaq.gperf"
      {"NWSA", 3550},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3456 "nasdaq.gperf"
      {"NKTX", 3443},
      {""}, {""},
#line 4289 "nasdaq.gperf"
      {"RKLZ", 4276},
      {""}, {""}, {""}, {""}, {""},
#line 4076 "nasdaq.gperf"
      {"QCLR", 4063},
      {""}, {""}, {""}, {""},
#line 5054 "nasdaq.gperf"
      {"TVIV", 5041},
#line 5055 "nasdaq.gperf"
      {"TVIVU", 5042},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 769 "nasdaq.gperf"
      {"BPYPN", 756},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 699 "nasdaq.gperf"
      {"BLDP", 686},
      {""}, {""}, {""}, {""},
#line 3547 "nasdaq.gperf"
      {"NVEC", 3534},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 323 "nasdaq.gperf"
      {"ANDE", 310},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4754 "nasdaq.gperf"
      {"SUPN", 4741},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4736 "nasdaq.gperf"
      {"STRK", 4723},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3528 "nasdaq.gperf"
      {"NUCL", 3515},
      {""}, {""}, {""},
#line 5366 "nasdaq.gperf"
      {"WHF", 5353},
#line 2106 "nasdaq.gperf"
      {"GLIBA", 2093},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3387 "nasdaq.gperf"
      {"NCPLW", 3374},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3033 "nasdaq.gperf"
      {"LWLG", 3020},
      {""}, {""}, {""}, {""}, {""},
#line 4719 "nasdaq.gperf"
      {"STGW", 4706},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2549 "nasdaq.gperf"
      {"INDB", 2536},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2465 "nasdaq.gperf"
      {"ICOP", 2452},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4381 "nasdaq.gperf"
      {"RZLVW", 4368},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3606 "nasdaq.gperf"
      {"OCTV", 3593},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1404 "nasdaq.gperf"
      {"DHCNL", 1391},
      {""}, {""},
#line 2978 "nasdaq.gperf"
      {"LOTWW", 2965},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4413 "nasdaq.gperf"
      {"SBLK", 4400},
#line 3443 "nasdaq.gperf"
      {"NIKI", 3430},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1608 "nasdaq.gperf"
      {"ENGNW", 1595},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3319 "nasdaq.gperf"
      {"MYCM", 3306},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5064 "nasdaq.gperf"
      {"TWLV", 5051},
#line 5066 "nasdaq.gperf"
      {"TWLVU", 5053},
      {""}, {""}, {""}, {""},
#line 5065 "nasdaq.gperf"
      {"TWLVR", 5052},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4377 "nasdaq.gperf"
      {"RYOJ", 4364},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 463 "nasdaq.gperf"
      {"ATHE", 450},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5143 "nasdaq.gperf"
      {"USDX", 5130},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2873 "nasdaq.gperf"
      {"LBTYK", 2860},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 877 "nasdaq.gperf"
      {"BUSE", 864},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3560 "nasdaq.gperf"
      {"NWL", 3547},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5409 "nasdaq.gperf"
      {"WSBK", 5396},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1397 "nasdaq.gperf"
      {"DGRE", 1384},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4546 "nasdaq.gperf"
      {"SKYE", 4533},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2093 "nasdaq.gperf"
      {"GIWWU", 2080},
      {""}, {""},
#line 1452 "nasdaq.gperf"
      {"DRDB", 1439},
#line 1453 "nasdaq.gperf"
      {"DRDBU", 1440},
#line 2092 "nasdaq.gperf"
      {"GIWWR", 2079},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4291 "nasdaq.gperf"
      {"RKTO", 4278},
      {""}, {""}, {""},
#line 3622 "nasdaq.gperf"
      {"OGI", 3609},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3445 "nasdaq.gperf"
      {"NIOBW", 3432},
      {""},
#line 5095 "nasdaq.gperf"
      {"UEVM", 5082},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1979 "nasdaq.gperf"
      {"FUSEW", 1966},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 179 "nasdaq.gperf"
      {"AGPU", 166},
#line 2913 "nasdaq.gperf"
      {"LGDS", 2900},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1696 "nasdaq.gperf"
      {"EXFY", 1683},
      {""}, {""}, {""}, {""}, {""},
#line 2558 "nasdaq.gperf"
      {"INHD", 2545},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 878 "nasdaq.gperf"
      {"BUSEP", 865},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4630 "nasdaq.gperf"
      {"SOHU", 4617},
#line 1407 "nasdaq.gperf"
      {"DINE", 1394},
      {""}, {""}, {""}, {""}, {""},
#line 3657 "nasdaq.gperf"
      {"ONCO", 3644},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4500 "nasdaq.gperf"
      {"SHFSW", 4487},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5112 "nasdaq.gperf"
      {"ULVM", 5099},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5367 "nasdaq.gperf"
      {"WHFCL", 5354},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1214 "nasdaq.gperf"
      {"CPOP", 1201},
      {""}, {""}, {""}, {""}, {""},
#line 4557 "nasdaq.gperf"
      {"SLDPW", 4544},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4322 "nasdaq.gperf"
      {"ROCK", 4309},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1519 "nasdaq.gperf"
      {"DYNCW", 1506},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5226 "nasdaq.gperf"
      {"VGSH", 5213},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3538 "nasdaq.gperf"
      {"NVCR", 3525},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3690 "nasdaq.gperf"
      {"ORCU", 3677},
      {""},
#line 1818 "nasdaq.gperf"
      {"FIBK", 1805},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2604 "nasdaq.gperf"
      {"IPHA", 2591},
#line 3431 "nasdaq.gperf"
      {"NHIC", 3418},
#line 3432 "nasdaq.gperf"
      {"NHICU", 3419},
      {""}, {""}, {""},
#line 2605 "nasdaq.gperf"
      {"IPHXU", 2592},
      {""}, {""}, {""}, {""},
#line 4247 "nasdaq.gperf"
      {"RFAM", 4234},
#line 4249 "nasdaq.gperf"
      {"RFAMU", 4236},
      {""}, {""}, {""}, {""},
#line 4248 "nasdaq.gperf"
      {"RFAMR", 4235},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1147 "nasdaq.gperf"
      {"CNCK", 1134},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 656 "nasdaq.gperf"
      {"BHFAO", 643},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4661 "nasdaq.gperf"
      {"SPHL", 4648},
      {""}, {""}, {""}, {""}, {""},
#line 3718 "nasdaq.gperf"
      {"OTGAW", 3705},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3692 "nasdaq.gperf"
      {"ORGO", 3679},
      {""}, {""}, {""}, {""}, {""},
#line 2360 "nasdaq.gperf"
      {"HSDT", 2347},
      {""}, {""},
#line 3389 "nasdaq.gperf"
      {"NCSM", 3376},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 651 "nasdaq.gperf"
      {"BHDG", 638},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1445 "nasdaq.gperf"
      {"DORM", 1432},
#line 1455 "nasdaq.gperf"
      {"DRH", 1442},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4507 "nasdaq.gperf"
      {"SHOO", 4494},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2449 "nasdaq.gperf"
      {"IBTK", 2436},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2028 "nasdaq.gperf"
      {"GCLWW", 2015},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2156 "nasdaq.gperf"
      {"GPIQ", 2143},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3729 "nasdaq.gperf"
      {"OXBRW", 3716},
#line 1575 "nasdaq.gperf"
      {"ELBM", 1562},
      {""},
#line 3557 "nasdaq.gperf"
      {"NWE", 3544},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2371 "nasdaq.gperf"
      {"HTOO", 2358},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3127 "nasdaq.gperf"
      {"MEOH", 3114},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4080 "nasdaq.gperf"
      {"QCMU", 4067},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2088 "nasdaq.gperf"
      {"GIPR", 2075},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3668 "nasdaq.gperf"
      {"OPAL", 3655},
      {""}, {""},
#line 1378 "nasdaq.gperf"
      {"DERM", 1365},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5248 "nasdaq.gperf"
      {"VLGEA", 5235},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3661 "nasdaq.gperf"
      {"ONEG", 3648},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2783 "nasdaq.gperf"
      {"KIQQ", 2770},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3403 "nasdaq.gperf"
      {"NEOV", 3390},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3217 "nasdaq.gperf"
      {"MNTK", 3204},
      {""},
#line 4411 "nasdaq.gperf"
      {"SBFMW", 4398},
      {""}, {""}, {""},
#line 3599 "nasdaq.gperf"
      {"OCFC", 3586},
      {""}, {""}, {""}, {""},
#line 3618 "nasdaq.gperf"
      {"OFS", 3605},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2288 "nasdaq.gperf"
      {"HEQQ", 2275},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3097 "nasdaq.gperf"
      {"MCHP", 3084},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4541 "nasdaq.gperf"
      {"SKRE", 4528},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1416 "nasdaq.gperf"
      {"DLHC", 1403},
      {""}, {""},
#line 5056 "nasdaq.gperf"
      {"TVIVW", 5043},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3511 "nasdaq.gperf"
      {"NTHI", 3498},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3327 "nasdaq.gperf"
      {"MYHD", 3314},
      {""}, {""}, {""}, {""},
#line 3324 "nasdaq.gperf"
      {"MYHA", 3311},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3326 "nasdaq.gperf"
      {"MYHC", 3313},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2300 "nasdaq.gperf"
      {"HIFS", 2287},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2031 "nasdaq.gperf"
      {"GCTK", 2018},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4104 "nasdaq.gperf"
      {"QNST", 4091},
      {""}, {""},
#line 4896 "nasdaq.gperf"
      {"THYM", 4883},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3529 "nasdaq.gperf"
      {"NUCLW", 3516},
#line 1572 "nasdaq.gperf"
      {"EJH", 1559},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1550 "nasdaq.gperf"
      {"EEIQ", 1537},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3098 "nasdaq.gperf"
      {"MCHPP", 3085},
#line 3551 "nasdaq.gperf"
      {"NVNO", 3538},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1534 "nasdaq.gperf"
      {"ECHX", 1521},
      {""}, {""}, {""},
#line 3676 "nasdaq.gperf"
      {"OPI", 3663},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5221 "nasdaq.gperf"
      {"VFSWW", 5208},
      {""}, {""}, {""}, {""}, {""},
#line 4041 "nasdaq.gperf"
      {"PUBM", 4028},
#line 3671 "nasdaq.gperf"
      {"OPEG", 3658},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4770 "nasdaq.gperf"
      {"SVIV", 4757},
#line 4771 "nasdaq.gperf"
      {"SVIVU", 4758},
      {""},
#line 1092 "nasdaq.gperf"
      {"CHYM", 1079},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2772 "nasdaq.gperf"
      {"KFFB", 2759},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2883 "nasdaq.gperf"
      {"LDEM", 2870},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2327 "nasdaq.gperf"
      {"HODO", 2314},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3932 "nasdaq.gperf"
      {"PNBK", 3919},
      {""}, {""},
#line 2235 "nasdaq.gperf"
      {"GYRE", 2222},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 635 "nasdaq.gperf"
      {"BGDE", 622},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3645 "nasdaq.gperf"
      {"OMER", 3632},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5109 "nasdaq.gperf"
      {"ULH", 5096},
      {""}, {""},
#line 2214 "nasdaq.gperf"
      {"GTIM", 2201},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3532 "nasdaq.gperf"
      {"NUIF", 3519},
      {""}, {""}, {""},
#line 2822 "nasdaq.gperf"
      {"KROP", 2809},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2579 "nasdaq.gperf"
      {"INTW", 2566},
      {""}, {""}, {""},
#line 2286 "nasdaq.gperf"
      {"HELP", 2273},
      {""}, {""}, {""}, {""},
#line 5478 "nasdaq.gperf"
      {"XNDU", 5465},
      {""}, {""}, {""}, {""}, {""},
#line 3617 "nasdaq.gperf"
      {"OFLX", 3604},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2962 "nasdaq.gperf"
      {"LNKS", 2949},
      {""}, {""}, {""},
#line 4782 "nasdaq.gperf"
      {"SWKS", 4769},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5172 "nasdaq.gperf"
      {"UYSC", 5159},
#line 5174 "nasdaq.gperf"
      {"UYSCU", 5161},
      {""}, {""}, {""}, {""},
#line 5173 "nasdaq.gperf"
      {"UYSCR", 5160},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5099 "nasdaq.gperf"
      {"UFO", 5086},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5100 "nasdaq.gperf"
      {"UFOX", 5087},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3848 "nasdaq.gperf"
      {"PFDE", 3835},
      {""}, {""}, {""}, {""}, {""},
#line 1454 "nasdaq.gperf"
      {"DRDBW", 1441},
#line 2829 "nasdaq.gperf"
      {"KSMH", 2816},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1810 "nasdaq.gperf"
      {"FGIWW", 1797},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2218 "nasdaq.gperf"
      {"GTOQ", 2205},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1553 "nasdaq.gperf"
      {"EFOI", 1540},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4049 "nasdaq.gperf"
      {"PWCM", 4036},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1216 "nasdaq.gperf"
      {"CPSH", 1203},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5437 "nasdaq.gperf"
      {"WWD", 5424},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3354 "nasdaq.gperf"
      {"NATH", 3341},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2319 "nasdaq.gperf"
      {"HMH", 2306},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3474 "nasdaq.gperf"
      {"NOEM", 3461},
#line 3476 "nasdaq.gperf"
      {"NOEMU", 3463},
#line 3530 "nasdaq.gperf"
      {"NUG", 3517},
      {""}, {""}, {""},
#line 3475 "nasdaq.gperf"
      {"NOEMR", 3462},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4517 "nasdaq.gperf"
      {"SIDU", 4504},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1493 "nasdaq.gperf"
      {"DUSG", 1480},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4542 "nasdaq.gperf"
      {"SKUU", 4529},
      {""},
#line 3567 "nasdaq.gperf"
      {"NXH", 3554},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2225 "nasdaq.gperf"
      {"GURE", 2212},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2298 "nasdaq.gperf"
      {"HHS", 2285},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1684 "nasdaq.gperf"
      {"EVSD", 1671},
      {""}, {""}, {""},
#line 3491 "nasdaq.gperf"
      {"NRIM", 3478},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4059 "nasdaq.gperf"
      {"PYPL", 4046},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3442 "nasdaq.gperf"
      {"NICM", 3429},
#line 3433 "nasdaq.gperf"
      {"NHICW", 3420},
      {""}, {""},
#line 3615 "nasdaq.gperf"
      {"OFAL", 3602},
#line 152 "nasdaq.gperf"
      {"AFJK", 139},
#line 154 "nasdaq.gperf"
      {"AFJKU", 141},
#line 4893 "nasdaq.gperf"
      {"THRM", 4880},
      {""}, {""}, {""},
#line 153 "nasdaq.gperf"
      {"AFJKR", 140},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1148 "nasdaq.gperf"
      {"CNCKW", 1135},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5171 "nasdaq.gperf"
      {"UYLD", 5158},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4891 "nasdaq.gperf"
      {"THH", 4878},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4548 "nasdaq.gperf"
      {"SKYU", 4535},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3155 "nasdaq.gperf"
      {"MGIH", 3142},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3534 "nasdaq.gperf"
      {"NUSB", 3521},
      {""}, {""}, {""},
#line 3300 "nasdaq.gperf"
      {"MUZE", 3287},
#line 3301 "nasdaq.gperf"
      {"MUZEU", 3288},
      {""}, {""},
#line 642 "nasdaq.gperf"
      {"BGLWW", 629},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4327 "nasdaq.gperf"
      {"ROKU", 4314},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3672 "nasdaq.gperf"
      {"OPEN", 3659},
      {""}, {""},
#line 2407 "nasdaq.gperf"
      {"HYLS", 2394},
      {""}, {""}, {""}, {""},
#line 3501 "nasdaq.gperf"
      {"NSPR", 3488},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3675 "nasdaq.gperf"
      {"OPENZ", 3662},
      {""},
#line 3023 "nasdaq.gperf"
      {"LUNR", 3010},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1597 "nasdaq.gperf"
      {"EMEQ", 1584},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5034 "nasdaq.gperf"
      {"TTEK", 5021},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3531 "nasdaq.gperf"
      {"NUGY", 3518},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2089 "nasdaq.gperf"
      {"GIPRW", 2076},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3616 "nasdaq.gperf"
      {"OFIX", 3603},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4547 "nasdaq.gperf"
      {"SKYQ", 4534},
      {""}, {""}, {""}, {""}, {""},
#line 3285 "nasdaq.gperf"
      {"MTEK", 3272},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5266 "nasdaq.gperf"
      {"VNOM", 5253},
      {""}, {""}, {""}, {""}, {""},
#line 5041 "nasdaq.gperf"
      {"TULP", 5028},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3404 "nasdaq.gperf"
      {"NEOVW", 3391},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4654 "nasdaq.gperf"
      {"SPCK", 4641},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2666 "nasdaq.gperf"
      {"IVF", 2653},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1516 "nasdaq.gperf"
      {"DYNB", 1503},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1635 "nasdaq.gperf"
      {"EQQQ", 1622},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2230 "nasdaq.gperf"
      {"GWAV", 2217},
      {""}, {""}, {""},
#line 1033 "nasdaq.gperf"
      {"CFBK", 1020},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2363 "nasdaq.gperf"
      {"HSTM", 2350},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1307 "nasdaq.gperf"
      {"CULP", 1294},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3570 "nasdaq.gperf"
      {"NXPL", 3557},
      {""}, {""},
#line 1494 "nasdaq.gperf"
      {"DVAL", 1481},
      {""}, {""}, {""},
#line 1480 "nasdaq.gperf"
      {"DTSQ", 1467},
#line 1482 "nasdaq.gperf"
      {"DTSQU", 1469},
      {""}, {""}, {""}, {""},
#line 1481 "nasdaq.gperf"
      {"DTSQR", 1468},
      {""}, {""}, {""}, {""}, {""},
#line 505 "nasdaq.gperf"
      {"AVGU", 492},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2387 "nasdaq.gperf"
      {"HVII", 2374},
#line 2389 "nasdaq.gperf"
      {"HVIIU", 2376},
      {""}, {""}, {""}, {""},
#line 2388 "nasdaq.gperf"
      {"HVIIR", 2375},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3308 "nasdaq.gperf"
      {"MWH", 3295},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 665 "nasdaq.gperf"
      {"BIDU", 652},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 765 "nasdaq.gperf"
      {"BPOP", 752},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2498 "nasdaq.gperf"
      {"IGOV", 2485},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5106 "nasdaq.gperf"
      {"UK", 5093},
      {""},
#line 3608 "nasdaq.gperf"
      {"ODD", 3595},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4772 "nasdaq.gperf"
      {"SVIVW", 4759},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2975 "nasdaq.gperf"
      {"LOPE", 2962},
      {""},
#line 2671 "nasdaq.gperf"
      {"IXHL", 2658},
      {""}, {""},
#line 2219 "nasdaq.gperf"
      {"GTPE", 2206},
      {""}, {""}, {""},
#line 1708 "nasdaq.gperf"
      {"EZGO", 1695},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3701 "nasdaq.gperf"
      {"ORMP", 3688},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3673 "nasdaq.gperf"
      {"OPENL", 3660},
#line 2380 "nasdaq.gperf"
      {"HUIZ", 2367},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1705 "nasdaq.gperf"
      {"EYE", 1692},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3186 "nasdaq.gperf"
      {"MKZR", 3173},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2190 "nasdaq.gperf"
      {"GSHR", 2177},
#line 2191 "nasdaq.gperf"
      {"GSHRU", 2178},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5157 "nasdaq.gperf"
      {"USVM", 5144},
      {""}, {""},
#line 1662 "nasdaq.gperf"
      {"ETOR", 1649},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1304 "nasdaq.gperf"
      {"CUBWU", 1291},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2052 "nasdaq.gperf"
      {"GENK", 2039},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1430 "nasdaq.gperf"
      {"DMLP", 1417},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1706 "nasdaq.gperf"
      {"EYEG", 1693},
      {""}, {""},
#line 2195 "nasdaq.gperf"
      {"GSIW", 2182},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4287 "nasdaq.gperf"
      {"RKLB", 4274},
      {""}, {""}, {""}, {""}, {""},
#line 5593 "nasdaq.gperf"
      {"ZYME", 5580},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4177 "nasdaq.gperf"
      {"RAPP", 4164},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3698 "nasdaq.gperf"
      {"ORKA", 3685},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2571 "nasdaq.gperf"
      {"INSM", 2558},
#line 881 "nasdaq.gperf"
      {"BVFL", 868},
#line 1568 "nasdaq.gperf"
      {"EHLD", 1555},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1308 "nasdaq.gperf"
      {"CUPR", 1295},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2747 "nasdaq.gperf"
      {"KBDU", 2734},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1496 "nasdaq.gperf"
      {"DVLT", 1483},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3477 "nasdaq.gperf"
      {"NOEMW", 3464},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1946 "nasdaq.gperf"
      {"FTEK", 1933},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2294 "nasdaq.gperf"
      {"HFFG", 2281},
      {""}, {""}, {""},
#line 2366 "nasdaq.gperf"
      {"HTFL", 2353},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1412 "nasdaq.gperf"
      {"DJTWW", 1399},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3609 "nasdaq.gperf"
      {"ODDS", 3596},
      {""}, {""},
#line 3960 "nasdaq.gperf"
      {"PPIH", 3947},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1647 "nasdaq.gperf"
      {"ESGE", 1634},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1539 "nasdaq.gperf"
      {"ECXWW", 1526},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3302 "nasdaq.gperf"
      {"MUZEW", 3289},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2974 "nasdaq.gperf"
      {"LOOP", 2961},
      {""}, {""}, {""}, {""},
#line 2217 "nasdaq.gperf"
      {"GTOP", 2204},
      {""}, {""}, {""}, {""},
#line 3620 "nasdaq.gperf"
      {"OFSSO", 3607},
      {""}, {""}, {""}, {""}, {""},
#line 1624 "nasdaq.gperf"
      {"ENZL", 1611},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3674 "nasdaq.gperf"
      {"OPENW", 3661},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3724 "nasdaq.gperf"
      {"OVBC", 3711},
#line 2350 "nasdaq.gperf"
      {"HQWWW", 2337},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4159 "nasdaq.gperf"
      {"QVCG", 4146},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1505 "nasdaq.gperf"
      {"DWSN", 1492},
      {""}, {""}, {""}, {""},
#line 4090 "nasdaq.gperf"
      {"QFIN", 4077},
      {""}, {""}, {""},
#line 4093 "nasdaq.gperf"
      {"QLDY", 4080},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5127 "nasdaq.gperf"
      {"UPGR", 5114},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1508 "nasdaq.gperf"
      {"DXCM", 1495},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2525 "nasdaq.gperf"
      {"IMOM", 2512},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4831 "nasdaq.gperf"
      {"TBPH", 4818},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3286 "nasdaq.gperf"
      {"MTEKW", 3273},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3374 "nasdaq.gperf"
      {"NCEW", 3361},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4536 "nasdaq.gperf"
      {"SKDD", 4523},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2251 "nasdaq.gperf"
      {"HBANM", 2238},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3038 "nasdaq.gperf"
      {"LYEL", 3025},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3623 "nasdaq.gperf"
      {"OHAC", 3610},
#line 3625 "nasdaq.gperf"
      {"OHACU", 3612},
      {""}, {""}, {""}, {""},
#line 3624 "nasdaq.gperf"
      {"OHACR", 3611},
      {""}, {""}, {""}, {""}, {""},
#line 3028 "nasdaq.gperf"
      {"LVO", 3015},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2856 "nasdaq.gperf"
      {"LAKE", 2843},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1569 "nasdaq.gperf"
      {"EHLS", 1556},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3644 "nasdaq.gperf"
      {"OMDA", 3631},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4129 "nasdaq.gperf"
      {"QQUP", 4116},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 510 "nasdaq.gperf"
      {"AVNW", 497},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2603 "nasdaq.gperf"
      {"IPGP", 2590},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2664 "nasdaq.gperf"
      {"IVDA", 2651},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4919 "nasdaq.gperf"
      {"TLPH", 4906},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1081 "nasdaq.gperf"
      {"CHRW", 1068},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3985 "nasdaq.gperf"
      {"PROK", 3972},
      {""}, {""}, {""}, {""},
#line 4152 "nasdaq.gperf"
      {"QUCY", 4139},
      {""}, {""}, {""}, {""},
#line 4794 "nasdaq.gperf"
      {"SYPR", 4781},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3648 "nasdaq.gperf"
      {"OMSE", 3635},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3629 "nasdaq.gperf"
      {"OIO", 3616},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4092 "nasdaq.gperf"
      {"QH", 4079},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3793 "nasdaq.gperf"
      {"PBPH", 3780},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2192 "nasdaq.gperf"
      {"GSHRW", 2179},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2346 "nasdaq.gperf"
      {"HPK", 2333},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4610 "nasdaq.gperf"
      {"SNFCA", 4597},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3719 "nasdaq.gperf"
      {"OTGL", 3706},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1655 "nasdaq.gperf"
      {"ESPO", 1642},
      {""}, {""}, {""}, {""},
#line 3735 "nasdaq.gperf"
      {"OXLCN", 3722},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5564 "nasdaq.gperf"
      {"ZHOG", 5551},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1305 "nasdaq.gperf"
      {"CUBWW", 1292},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1442 "nasdaq.gperf"
      {"DOMH", 1429},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5440 "nasdaq.gperf"
      {"WYHG", 5427},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 325 "nasdaq.gperf"
      {"ANGH", 312},
      {""}, {""},
#line 1414 "nasdaq.gperf"
      {"DKNG", 1401},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1571 "nasdaq.gperf"
      {"EIKN", 1558},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2527 "nasdaq.gperf"
      {"IMPP", 2514},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4539 "nasdaq.gperf"
      {"SKK", 4526},
#line 3699 "nasdaq.gperf"
      {"ORKT", 3686},
      {""}, {""},
#line 4310 "nasdaq.gperf"
      {"RNEM", 4297},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4154 "nasdaq.gperf"
      {"QUMS", 4141},
#line 4156 "nasdaq.gperf"
      {"QUMSU", 4143},
      {""}, {""}, {""}, {""},
#line 4155 "nasdaq.gperf"
      {"QUMSR", 4142},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3325 "nasdaq.gperf"
      {"MYHB", 3312},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1659 "nasdaq.gperf"
      {"ETHA", 1646},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2798 "nasdaq.gperf"
      {"KMRK", 2785},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2528 "nasdaq.gperf"
      {"IMPPP", 2515},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2402 "nasdaq.gperf"
      {"HXHX", 2389},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2730 "nasdaq.gperf"
      {"JTEK", 2717},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5569 "nasdaq.gperf"
      {"ZKIN", 5556},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3536 "nasdaq.gperf"
      {"NUWE", 3523},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2949 "nasdaq.gperf"
      {"LKQ", 2936},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3331 "nasdaq.gperf"
      {"MYMH", 3318},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3314 "nasdaq.gperf"
      {"MYCH", 3301},
#line 1370 "nasdaq.gperf"
      {"DCTH", 1357},
      {""}, {""},
#line 1914 "nasdaq.gperf"
      {"FRPH", 1901},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3871 "nasdaq.gperf"
      {"PHOE", 3858},
      {""}, {""}, {""},
#line 1927 "nasdaq.gperf"
      {"FSHP", 1914},
#line 1929 "nasdaq.gperf"
      {"FSHPU", 1916},
      {""}, {""}, {""}, {""},
#line 1928 "nasdaq.gperf"
      {"FSHPR", 1915},
      {""}, {""},
#line 2178 "nasdaq.gperf"
      {"GROW", 2165},
      {""}, {""}, {""}, {""},
#line 2317 "nasdaq.gperf"
      {"HLTH", 2304},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2925 "nasdaq.gperf"
      {"LIDR", 2912},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 497 "nasdaq.gperf"
      {"AVAH", 484},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5101 "nasdaq.gperf"
      {"UFPI", 5088},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2226 "nasdaq.gperf"
      {"GUSE", 2213},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4111 "nasdaq.gperf"
      {"QQDN", 4098},
      {""},
#line 223 "nasdaq.gperf"
      {"AKAM", 210},
      {""}, {""}, {""},
#line 5162 "nasdaq.gperf"
      {"UTHY", 5149},
      {""},
#line 2720 "nasdaq.gperf"
      {"JPFP", 2707},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3444 "nasdaq.gperf"
      {"NIKL", 3431},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 780 "nasdaq.gperf"
      {"BRFH", 767},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2367 "nasdaq.gperf"
      {"HTHT", 2354},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2415 "nasdaq.gperf"
      {"HYZD", 2402},
      {""}, {""}, {""},
#line 306 "nasdaq.gperf"
      {"AMPH", 293},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2107 "nasdaq.gperf"
      {"GLIBK", 2094},
      {""}, {""},
#line 1420 "nasdaq.gperf"
      {"DLTH", 1407},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3361 "nasdaq.gperf"
      {"NBBK", 3348},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3177 "nasdaq.gperf"
      {"MKAM", 3164},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2113 "nasdaq.gperf"
      {"GLOW", 2100},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3429 "nasdaq.gperf"
      {"NGHT", 3416},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2229 "nasdaq.gperf"
      {"GVLE", 2216},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2661 "nasdaq.gperf"
      {"IUSV", 2648},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4114 "nasdaq.gperf"
      {"QQLV", 4101},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2861 "nasdaq.gperf"
      {"LARK", 2848},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2953 "nasdaq.gperf"
      {"LLYVA", 2940},
      {""}, {""}, {""},
#line 2210 "nasdaq.gperf"
      {"GTERA", 2197},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 500 "nasdaq.gperf"
      {"AVBH", 487},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1648 "nasdaq.gperf"
      {"ESGU", 1635},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4502 "nasdaq.gperf"
      {"SHIP", 4489},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2082 "nasdaq.gperf"
      {"GIGM", 2069},
      {""}, {""}, {""},
#line 4637 "nasdaq.gperf"
      {"SOPH", 4624},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4044 "nasdaq.gperf"
      {"PULM", 4031},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4151 "nasdaq.gperf"
      {"QUBT", 4138},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 105 "nasdaq.gperf"
      {"ADAMK", 92},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5105 "nasdaq.gperf"
      {"UIVM", 5092},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2665 "nasdaq.gperf"
      {"IVDAW", 2652},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1613 "nasdaq.gperf"
      {"ENLV", 1600},
      {""},
#line 2266 "nasdaq.gperf"
      {"HCHL", 2253},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1700 "nasdaq.gperf"
      {"EXPO", 1687},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 107 "nasdaq.gperf"
      {"ADAMM", 94},
      {""}, {""}, {""},
#line 4886 "nasdaq.gperf"
      {"THCH", 4873},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3455 "nasdaq.gperf"
      {"NKTR", 3442},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 655 "nasdaq.gperf"
      {"BHFAN", 642},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4102 "nasdaq.gperf"
      {"QNME", 4089},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 326 "nasdaq.gperf"
      {"ANGHW", 313},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 331 "nasdaq.gperf"
      {"ANIK", 318},
      {""},
#line 4269 "nasdaq.gperf"
      {"RICK", 4256},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4251 "nasdaq.gperf"
      {"RFEM", 4238},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4118 "nasdaq.gperf"
      {"QQQE", 4105},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3707 "nasdaq.gperf"
      {"OSPN", 3694},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4506 "nasdaq.gperf"
      {"SHOE", 4493},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2757 "nasdaq.gperf"
      {"KCHV", 2744},
#line 2759 "nasdaq.gperf"
      {"KCHVU", 2746},
      {""}, {""},
#line 2337 "nasdaq.gperf"
      {"HOPE", 2324},
      {""},
#line 2758 "nasdaq.gperf"
      {"KCHVR", 2745},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3731 "nasdaq.gperf"
      {"OXLCG", 3718},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1533 "nasdaq.gperf"
      {"ECHO", 1520},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3610 "nasdaq.gperf"
      {"ODFL", 3597},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4540 "nasdaq.gperf"
      {"SKOR", 4527},
      {""},
#line 1475 "nasdaq.gperf"
      {"DSYWW", 1462},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5102 "nasdaq.gperf"
      {"UFPT", 5089},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1674 "nasdaq.gperf"
      {"EVGN", 1661},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 739 "nasdaq.gperf"
      {"BNDP", 726},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2626 "nasdaq.gperf"
      {"IRDM", 2613},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3695 "nasdaq.gperf"
      {"ORIQ", 3682},
#line 3696 "nasdaq.gperf"
      {"ORIQU", 3683},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1542 "nasdaq.gperf"
      {"EDHL", 1529},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5586 "nasdaq.gperf"
      {"ZTOP", 5573},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4947 "nasdaq.gperf"
      {"TNDM", 4934},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2142 "nasdaq.gperf"
      {"GOOGM", 2129},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4745 "nasdaq.gperf"
      {"SUGP", 4732},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1596 "nasdaq.gperf"
      {"EMEM", 1583},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5582 "nasdaq.gperf"
      {"ZSTK", 5569},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4133 "nasdaq.gperf"
      {"QRHC", 4120},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3002 "nasdaq.gperf"
      {"LSAK", 2989},
      {""}, {""}, {""}, {""}, {""},
#line 4378 "nasdaq.gperf"
      {"RYTM", 4365},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 891 "nasdaq.gperf"
      {"BYAH", 878},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5414 "nasdaq.gperf"
      {"WSHP", 5401},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3465 "nasdaq.gperf"
      {"NMRK", 3452},
      {""},
#line 2928 "nasdaq.gperf"
      {"LIFE", 2915},
#line 3039 "nasdaq.gperf"
      {"LYFT", 3026},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2554 "nasdaq.gperf"
      {"INDV", 2541},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2369 "nasdaq.gperf"
      {"HTLM", 2356},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 783 "nasdaq.gperf"
      {"BRKH", 770},
#line 784 "nasdaq.gperf"
      {"BRKHU", 771},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1562 "nasdaq.gperf"
      {"EGHA", 1549},
#line 1564 "nasdaq.gperf"
      {"EGHAU", 1551},
      {""}, {""}, {""}, {""},
#line 1563 "nasdaq.gperf"
      {"EGHAR", 1550},
      {""}, {""}, {""},
#line 3003 "nasdaq.gperf"
      {"LSBK", 2990},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2519 "nasdaq.gperf"
      {"IMKTA", 2506},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5151 "nasdaq.gperf"
      {"USLM", 5138},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3588 "nasdaq.gperf"
      {"OBAWU", 3575},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3184 "nasdaq.gperf"
      {"MKTW", 3171},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2436 "nasdaq.gperf"
      {"IBGK", 2423},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2064 "nasdaq.gperf"
      {"GFLW", 2051},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2542 "nasdaq.gperf"
      {"INBK", 2529},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2543 "nasdaq.gperf"
      {"INBKZ", 2530},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1413 "nasdaq.gperf"
      {"DKI", 1400},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3697 "nasdaq.gperf"
      {"ORIQW", 3684},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2844 "nasdaq.gperf"
      {"KYIV", 2831},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1489 "nasdaq.gperf"
      {"DUO", 1476},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5098 "nasdaq.gperf"
      {"UFIV", 5085},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4163 "nasdaq.gperf"
      {"QYLD", 4150},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1956 "nasdaq.gperf"
      {"FTHM", 1943},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3559 "nasdaq.gperf"
      {"NWGL", 3546},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4113 "nasdaq.gperf"
      {"QQHG", 4100},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1490 "nasdaq.gperf"
      {"DUOG", 1477},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3647 "nasdaq.gperf"
      {"OMH", 3634},
      {""}, {""}, {""}, {""}, {""},
#line 4501 "nasdaq.gperf"
      {"SHIM", 4488},
      {""},
#line 4164 "nasdaq.gperf"
      {"QYLG", 4151},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1660 "nasdaq.gperf"
      {"ETHB", 1647},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1678 "nasdaq.gperf"
      {"EVO", 1665},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1679 "nasdaq.gperf"
      {"EVOX", 1666},
#line 1680 "nasdaq.gperf"
      {"EVOXU", 1667},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3334 "nasdaq.gperf"
      {"MYMK", 3321},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3317 "nasdaq.gperf"
      {"MYCK", 3304},
      {""}, {""}, {""},
#line 3522 "nasdaq.gperf"
      {"NTWK", 3509},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1610 "nasdaq.gperf"
      {"ENHI", 1597},
      {""}, {""}, {""}, {""},
#line 2965 "nasdaq.gperf"
      {"LNTH", 2952},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1692 "nasdaq.gperf"
      {"EWZS", 1679},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5118 "nasdaq.gperf"
      {"UNHG", 5105},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3460 "nasdaq.gperf"
      {"NMIH", 3447},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3042 "nasdaq.gperf"
      {"LZMH", 3029},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4537 "nasdaq.gperf"
      {"SKHY", 4524},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3726 "nasdaq.gperf"
      {"OVLY", 3713},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2890 "nasdaq.gperf"
      {"LEGH", 2877},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4780 "nasdaq.gperf"
      {"SWIM", 4767},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2400 "nasdaq.gperf"
      {"HWO", 2387},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1340 "nasdaq.gperf"
      {"CYTK", 1327},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2992 "nasdaq.gperf"
      {"LPTH", 2979},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3540 "nasdaq.gperf"
      {"NVD", 3527},
#line 3542 "nasdaq.gperf"
      {"NVDD", 3529},
      {""}, {""}, {""}, {""},
#line 3541 "nasdaq.gperf"
      {"NVDA", 3528},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 975 "nasdaq.gperf"
      {"CCHH", 962},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2228 "nasdaq.gperf"
      {"GVH", 2215},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3632 "nasdaq.gperf"
      {"OKTA", 3619},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1546 "nasdaq.gperf"
      {"EDTK", 1533},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2914 "nasdaq.gperf"
      {"LGHL", 2901},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2328 "nasdaq.gperf"
      {"HODU", 2315},
      {""}, {""}, {""}, {""}, {""},
#line 688 "nasdaq.gperf"
      {"BKHA", 675},
#line 690 "nasdaq.gperf"
      {"BKHAU", 677},
      {""}, {""}, {""}, {""},
#line 689 "nasdaq.gperf"
      {"BKHAR", 676},
      {""}, {""},
#line 3437 "nasdaq.gperf"
      {"NHP", 3424},
#line 2322 "nasdaq.gperf"
      {"HNDL", 2309},
      {""}, {""},
#line 1357 "nasdaq.gperf"
      {"DASH", 1344},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1532 "nasdaq.gperf"
      {"ECBK", 1519},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3552 "nasdaq.gperf"
      {"NVPS", 3539},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3543 "nasdaq.gperf"
      {"NVDG", 3530},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4158 "nasdaq.gperf"
      {"QVAL", 4145},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3633 "nasdaq.gperf"
      {"OKTG", 3620},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3725 "nasdaq.gperf"
      {"OVID", 3712},
#line 1083 "nasdaq.gperf"
      {"CHSCM", 1070},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2553 "nasdaq.gperf"
      {"INDQ", 2540},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1565 "nasdaq.gperf"
      {"EGHT", 1552},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3024 "nasdaq.gperf"
      {"LVDS", 3011},
      {""}, {""},
#line 2310 "nasdaq.gperf"
      {"HKIT", 2297},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3438 "nasdaq.gperf"
      {"NHPAP", 3425},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4731 "nasdaq.gperf"
      {"STOK", 4718},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 785 "nasdaq.gperf"
      {"BRKHW", 772},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3723 "nasdaq.gperf"
      {"OUST", 3710},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1585 "nasdaq.gperf"
      {"ELTK", 1572},
      {""}, {""}, {""}, {""}, {""},
#line 2409 "nasdaq.gperf"
      {"HYNE", 2396},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3589 "nasdaq.gperf"
      {"OBAWW", 3576},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1399 "nasdaq.gperf"
      {"DGRW", 1386},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4549 "nasdaq.gperf"
      {"SKYW", 4536},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3561 "nasdaq.gperf"
      {"NWPX", 3548},
#line 3597 "nasdaq.gperf"
      {"OCCIM", 3584},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1561 "nasdaq.gperf"
      {"EGGQ", 1548},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1970 "nasdaq.gperf"
      {"FUFU", 1957},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1492 "nasdaq.gperf"
      {"DUOT", 1479},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4286 "nasdaq.gperf"
      {"RKDA", 4273},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2709 "nasdaq.gperf"
      {"JKHY", 2696},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1392 "nasdaq.gperf"
      {"DGICA", 1379},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2295 "nasdaq.gperf"
      {"HFSP", 2282},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4150 "nasdaq.gperf"
      {"QTUM", 4137},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4064 "nasdaq.gperf"
      {"QADR", 4051},
#line 4065 "nasdaq.gperf"
      {"QADRU", 4052},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2845 "nasdaq.gperf"
      {"KYIVW", 2832},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3738 "nasdaq.gperf"
      {"OXSQ", 3725},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3545 "nasdaq.gperf"
      {"NVDS", 3532},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1673 "nasdaq.gperf"
      {"EVER", 1660},
      {""}, {""}, {""}, {""}, {""},
#line 5562 "nasdaq.gperf"
      {"ZEOWW", 5549},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3678 "nasdaq.gperf"
      {"OPPJ", 3665},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2930 "nasdaq.gperf"
      {"LILAK", 2917},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 667 "nasdaq.gperf"
      {"BIDWU", 654},
      {""}, {""}, {""}, {""},
#line 666 "nasdaq.gperf"
      {"BIDWR", 653},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1681 "nasdaq.gperf"
      {"EVOXW", 1668},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1514 "nasdaq.gperf"
      {"DYFI", 1501},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4089 "nasdaq.gperf"
      {"QFF", 4076},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2128 "nasdaq.gperf"
      {"GNOM", 2115},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3659 "nasdaq.gperf"
      {"ONDG", 3646},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3727 "nasdaq.gperf"
      {"OWLS", 3714},
#line 2840 "nasdaq.gperf"
      {"KVHI", 2827},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5381 "nasdaq.gperf"
      {"WKSP", 5368},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4101 "nasdaq.gperf"
      {"QNDX", 4088},
      {""}, {""},
#line 1686 "nasdaq.gperf"
      {"EWAV", 1673},
#line 1688 "nasdaq.gperf"
      {"EWAVU", 1675},
      {""}, {""}, {""}, {""},
#line 1687 "nasdaq.gperf"
      {"EWAVR", 1674},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2020 "nasdaq.gperf"
      {"GBFH", 2007},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1675 "nasdaq.gperf"
      {"EVGO", 1662},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4724 "nasdaq.gperf"
      {"STKH", 4711},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1573 "nasdaq.gperf"
      {"EKG", 1560},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3453 "nasdaq.gperf"
      {"NKLR", 3440},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1690 "nasdaq.gperf"
      {"EWJV", 1677},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4124 "nasdaq.gperf"
      {"QQQP", 4111},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4508 "nasdaq.gperf"
      {"SHOP", 4495},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2410 "nasdaq.gperf"
      {"HYP", 2397},
#line 2411 "nasdaq.gperf"
      {"HYPD", 2398},
      {""},
#line 5141 "nasdaq.gperf"
      {"USDE", 5128},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5380 "nasdaq.gperf"
      {"WKHS", 5367},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3652 "nasdaq.gperf"
      {"ONBPP", 3639},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3660 "nasdaq.gperf"
      {"ONDS", 3647},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3035 "nasdaq.gperf"
      {"LXEH", 3022},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2412 "nasdaq.gperf"
      {"HYPG", 2399},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3677 "nasdaq.gperf"
      {"OPK", 3664},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2406 "nasdaq.gperf"
      {"HYFT", 2393},
      {""}, {""}, {""}, {""},
#line 1355 "nasdaq.gperf"
      {"DAPP", 1342},
      {""}, {""}, {""}, {""}, {""},
#line 1971 "nasdaq.gperf"
      {"FUFUW", 1958},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3027 "nasdaq.gperf"
      {"LVLU", 3014},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2639 "nasdaq.gperf"
      {"ISHP", 2626},
      {""}, {""}, {""}, {""}, {""},
#line 1510 "nasdaq.gperf"
      {"DXPE", 1497},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4066 "nasdaq.gperf"
      {"QADRW", 4053},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2552 "nasdaq.gperf"
      {"INDP", 2539},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5161 "nasdaq.gperf"
      {"UTHR", 5148},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3745 "nasdaq.gperf"
      {"OZK", 3732},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3021 "nasdaq.gperf"
      {"LULU", 3008},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2954 "nasdaq.gperf"
      {"LLYVK", 2941},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1567 "nasdaq.gperf"
      {"EHGO", 1554},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2681 "nasdaq.gperf"
      {"JAKK", 2668},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2301 "nasdaq.gperf"
      {"HIHO", 2288},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1495 "nasdaq.gperf"
      {"DVGR", 1482},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3746 "nasdaq.gperf"
      {"OZKAP", 3733},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 740 "nasdaq.gperf"
      {"BNDW", 727},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1699 "nasdaq.gperf"
      {"EXPE", 1686},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3708 "nasdaq.gperf"
      {"OSPR", 3695},
#line 3709 "nasdaq.gperf"
      {"OSPRU", 3696},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4513 "nasdaq.gperf"
      {"SHPU", 4500},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3328 "nasdaq.gperf"
      {"MYHE", 3315},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1630 "nasdaq.gperf"
      {"EPSM", 1617},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2378 "nasdaq.gperf"
      {"HUDI", 2365},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2353 "nasdaq.gperf"
      {"HROW", 2340},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 4374 "nasdaq.gperf"
      {"RYAAY", 4361},
      {""}, {""}, {""}, {""}, {""},
#line 3434 "nasdaq.gperf"
      {"NHIV", 3421},
#line 3435 "nasdaq.gperf"
      {"NHIVU", 3422},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1994 "nasdaq.gperf"
      {"FWONA", 1981},
      {""}, {""}, {""}, {""}, {""},
#line 2275 "nasdaq.gperf"
      {"HCOW", 2262},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1667 "nasdaq.gperf"
      {"EUFN", 1654},
      {""}, {""}, {""}, {""},
#line 2939 "nasdaq.gperf"
      {"LINK", 2926},
      {""}, {""}, {""}, {""}, {""},
#line 5570 "nasdaq.gperf"
      {"ZKP", 5557},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 5142 "nasdaq.gperf"
      {"USDEW", 5129},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4082 "nasdaq.gperf"
      {"QCRH", 4069},
      {""}, {""},
#line 1438 "nasdaq.gperf"
      {"DNTH", 1425},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 5551 "nasdaq.gperf"
      {"YYGH", 5538},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5155 "nasdaq.gperf"
      {"USSH", 5142},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3025 "nasdaq.gperf"
      {"LVHD", 3012},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3651 "nasdaq.gperf"
      {"ONBPO", 3638},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5369 "nasdaq.gperf"
      {"WHLRD", 5356},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2299 "nasdaq.gperf"
      {"HIDE", 2286},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3521 "nasdaq.gperf"
      {"NTSK", 3508},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1665 "nasdaq.gperf"
      {"EUDA", 1652},
      {""}, {""}, {""}, {""}, {""},
#line 3439 "nasdaq.gperf"
      {"NHPBP", 3426},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 2947 "nasdaq.gperf"
      {"LKFN", 2934},
#line 5583 "nasdaq.gperf"
      {"ZTEK", 5570},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 687 "nasdaq.gperf"
      {"BKCH", 674},
      {""}, {""}, {""}, {""},
#line 1536 "nasdaq.gperf"
      {"ECOW", 1523},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1707 "nasdaq.gperf"
      {"EYPT", 1694},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1488 "nasdaq.gperf"
      {"DUKX", 1475},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5372 "nasdaq.gperf"
      {"WHWK", 5359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2948 "nasdaq.gperf"
      {"LKFT", 2935},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3710 "nasdaq.gperf"
      {"OSPRW", 3697},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2395 "nasdaq.gperf"
      {"HWCPZ", 2382},
      {""},
#line 3619 "nasdaq.gperf"
      {"OFSSH", 3606},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2915 "nasdaq.gperf"
      {"LGIH", 2902},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1382 "nasdaq.gperf"
      {"DFGP", 1369},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 4667 "nasdaq.gperf"
      {"SPOK", 4654},
      {""}, {""}, {""}, {""}, {""},
#line 5045 "nasdaq.gperf"
      {"TUSK", 5032},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4123 "nasdaq.gperf"
      {"QQQM", 4110},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1498 "nasdaq.gperf"
      {"DVOL", 1485},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1682 "nasdaq.gperf"
      {"EVPF", 1669},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3664 "nasdaq.gperf"
      {"ONFO", 3651},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 4755 "nasdaq.gperf"
      {"SUPP", 4742},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3436 "nasdaq.gperf"
      {"NHIVW", 3423},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1491 "nasdaq.gperf"
      {"DUOL", 1478},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4106 "nasdaq.gperf"
      {"QNTM", 4093},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2233 "nasdaq.gperf"
      {"GXDW", 2220},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 768 "nasdaq.gperf"
      {"BPYPM", 755},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3558 "nasdaq.gperf"
      {"NWFL", 3545},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1068 "nasdaq.gperf"
      {"CHKP", 1055},
      {""},
#line 3662 "nasdaq.gperf"
      {"ONEQ", 3649},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2842 "nasdaq.gperf"
      {"KWMWW", 2829},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3635 "nasdaq.gperf"
      {"OKYO", 3622},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1676 "nasdaq.gperf"
      {"EVLV", 1663},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1520 "nasdaq.gperf"
      {"DYOR", 1507},
#line 1521 "nasdaq.gperf"
      {"DYORU", 1508},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 3544 "nasdaq.gperf"
      {"NVDL", 3531},
      {""},
#line 1666 "nasdaq.gperf"
      {"EUDAW", 1653},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4112 "nasdaq.gperf"
      {"QQEW", 4099},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2399 "nasdaq.gperf"
      {"HWKN", 2386},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3883 "nasdaq.gperf"
      {"PKBK", 3870},
#line 1497 "nasdaq.gperf"
      {"DVLU", 1484},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3665 "nasdaq.gperf"
      {"ONFOW", 3652},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3634 "nasdaq.gperf"
      {"OKUR", 3621},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3322 "nasdaq.gperf"
      {"MYFW", 3309},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2373 "nasdaq.gperf"
      {"HTZWW", 2360},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2398 "nasdaq.gperf"
      {"HWIV", 2385},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1672 "nasdaq.gperf"
      {"EVCM", 1659},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1522 "nasdaq.gperf"
      {"DYORW", 1509},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1685 "nasdaq.gperf"
      {"EVYM", 1672},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4157 "nasdaq.gperf"
      {"QURE", 4144},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3405 "nasdaq.gperf"
      {"NEPH", 3392},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 871 "nasdaq.gperf"
      {"BUFM", 858},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 5130 "nasdaq.gperf"
      {"UPWK", 5117},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 5123 "nasdaq.gperf"
      {"UONEK", 5110},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2311 "nasdaq.gperf"
      {"HKPD", 2298},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3579 "nasdaq.gperf"
      {"NYXH", 3566},
      {""}, {""},
#line 1500 "nasdaq.gperf"
      {"DVSP", 1487},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 1499 "nasdaq.gperf"
      {"DVQQ", 1486},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1584 "nasdaq.gperf"
      {"ELPW", 1571},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4081 "nasdaq.gperf"
      {"QCOM", 4068},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1380 "nasdaq.gperf"
      {"DFDV", 1367},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2606 "nasdaq.gperf"
      {"IPKW", 2593},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 5169 "nasdaq.gperf"
      {"UVSP", 5156},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 4605 "nasdaq.gperf"
      {"SNDK", 4592},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2397 "nasdaq.gperf"
      {"HWH", 2384},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2413 "nasdaq.gperf"
      {"HYPR", 2400},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2396 "nasdaq.gperf"
      {"HWGV", 2383},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4146 "nasdaq.gperf"
      {"QTOP", 4133},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1995 "nasdaq.gperf"
      {"FWONK", 1982},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2404 "nasdaq.gperf"
      {"HYDR", 2391},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2950 "nasdaq.gperf"
      {"LKSP", 2937},
#line 2952 "nasdaq.gperf"
      {"LKSPU", 2939},
      {""}, {""}, {""}, {""},
#line 2951 "nasdaq.gperf"
      {"LKSPR", 2938},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3741 "nasdaq.gperf"
      {"OYSE", 3728},
#line 3743 "nasdaq.gperf"
      {"OYSEU", 3730},
      {""}, {""}, {""}, {""},
#line 3742 "nasdaq.gperf"
      {"OYSER", 3729},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3654 "nasdaq.gperf"
      {"ONCH", 3641},
#line 3655 "nasdaq.gperf"
      {"ONCHU", 3642},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4098 "nasdaq.gperf"
      {"QMOM", 4085},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4360 "nasdaq.gperf"
      {"RUSHB", 4347},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1503 "nasdaq.gperf"
      {"DWAW", 1490},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3670 "nasdaq.gperf"
      {"OPCH", 3657},
      {""}, {""}, {""},
#line 1381 "nasdaq.gperf"
      {"DFDVW", 1368},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4120 "nasdaq.gperf"
      {"QQQH", 4107},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 743 "nasdaq.gperf"
      {"BNKK", 730},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3469 "nasdaq.gperf"
      {"NNDM", 3456},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 2922 "nasdaq.gperf"
      {"LHSW", 2909},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3734 "nasdaq.gperf"
      {"OXLCM", 3721},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3682 "nasdaq.gperf"
      {"OPTH", 3669},
      {""},
#line 3739 "nasdaq.gperf"
      {"OXSQG", 3726},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 3631 "nasdaq.gperf"
      {"OKLL", 3618},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 2550 "nasdaq.gperf"
      {"INDH", 2537},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3744 "nasdaq.gperf"
      {"OZEM", 3731},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1338 "nasdaq.gperf"
      {"CYPH", 1325},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1486 "nasdaq.gperf"
      {"DUKR", 1473},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 490 "nasdaq.gperf"
      {"AUPH", 477},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3656 "nasdaq.gperf"
      {"ONCHW", 3643},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3473 "nasdaq.gperf"
      {"NODK", 3460},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4160 "nasdaq.gperf"
      {"QVOL", 4147},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 2401 "nasdaq.gperf"
      {"HWSM", 2388},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 654 "nasdaq.gperf"
      {"BHFAM", 641},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1628 "nasdaq.gperf"
      {"EPOW", 1615},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3663 "nasdaq.gperf"
      {"ONEW", 3650},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1487 "nasdaq.gperf"
      {"DUKRW", 1474},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3740 "nasdaq.gperf"
      {"OXSQH", 3727},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1611 "nasdaq.gperf"
      {"ENHU", 1598},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3546 "nasdaq.gperf"
      {"NVDU", 3533},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3884 "nasdaq.gperf"
      {"PKOH", 3871},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 1570 "nasdaq.gperf"
      {"EHTH", 1557},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 4512 "nasdaq.gperf"
      {"SHPH", 4499},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3621 "nasdaq.gperf"
      {"OGGWZ", 3608},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 3669 "nasdaq.gperf"
      {"OPBK", 3656},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 3178 "nasdaq.gperf"
      {"MKDW", 3165},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 3720 "nasdaq.gperf"
      {"OTLK", 3707},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3179 "nasdaq.gperf"
      {"MKDWW", 3166},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1710 "nasdaq.gperf"
      {"EZPW", 1697},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 766 "nasdaq.gperf"
      {"BPOPM", 753},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 4781 "nasdaq.gperf"
      {"SWKHL", 4768},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 1606 "nasdaq.gperf"
      {"ENDW", 1593},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 2393 "nasdaq.gperf"
      {"HWBK", 2380},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 5571 "nasdaq.gperf"
      {"ZKPU", 5558},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 1668 "nasdaq.gperf"
      {"EURK", 1655},
#line 1670 "nasdaq.gperf"
      {"EURKU", 1657},
      {""}, {""}, {""}, {""},
#line 1669 "nasdaq.gperf"
      {"EURKR", 1656},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 1504 "nasdaq.gperf"
      {"DWSH", 1491},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 3630 "nasdaq.gperf"
      {"OIOWW", 3617},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 3454 "nasdaq.gperf"
      {"NKSH", 3441},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 1614 "nasdaq.gperf"
      {"ENPH", 1601},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 2405 "nasdaq.gperf"
      {"HYFM", 2392},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 2379 "nasdaq.gperf"
      {"HUHU", 2366},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 5572 "nasdaq.gperf"
      {"ZKPW", 5559},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4359 "nasdaq.gperf"
      {"RUSHA", 4346},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 1485 "nasdaq.gperf"
      {"DUKH", 1472},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 4153 "nasdaq.gperf"
      {"QUIK", 4140}
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
  return static_cast<struct NasdaqGperfEntry *> (0);
}
#line 5594 "nasdaq.gperf"

