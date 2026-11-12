/* C++ code produced by gperf version 3.3 */
/* Command-line: gperf sp500.gperf  */
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

#line 1 "sp500.gperf"

#include <string.h>
#line 11 "sp500.gperf"
struct Sp500GperfEntry { const char *name; int value; };
/* maximum key range = 1760, duplicates = 0 */

class Sp500Gperf
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct Sp500GperfEntry *lookup (const char *str, size_t len);
};

inline unsigned int
Sp500Gperf::hash (const char *str, size_t len)
{
  static const unsigned short asso_values[] =
    {
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771,    0, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771,    0,   45,  435,   85,  488,  498,
       355,  258,  440,  767,   43,   43,  215,   50,  130,  420,
         5,  391,  250,   85,   10,  230,   15,    0,   25,  150,
       155,    3,   40,  345,   15,   65,  458,  233,  470,  300,
       238,  460,   73,   20,  365,  287,  442,  822,   65, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771, 1771,
      1771, 1771, 1771, 1771
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
        hval += asso_values[static_cast<unsigned char>(str[2]+18)];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[static_cast<unsigned char>(str[1]+11)];
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

const struct Sp500GperfEntry *
Sp500Gperf::lookup (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 503,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 5,
      MIN_HASH_VALUE = 11,
      MAX_HASH_VALUE = 1770
    };

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
  static const struct Sp500GperfEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 438 "sp500.gperf"
      {"T", 425},
      {""}, {""}, {""}, {""},
#line 476 "sp500.gperf"
      {"V", 463},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 379 "sp500.gperf"
      {"PLD", 366},
      {""}, {""},
#line 387 "sp500.gperf"
      {"PPL", 374},
#line 499 "sp500.gperf"
      {"WM", 486},
      {""}, {""}, {""},
#line 451 "sp500.gperf"
      {"TPL", 438},
#line 381 "sp500.gperf"
      {"PM", 368},
#line 443 "sp500.gperf"
      {"TEL", 430},
      {""}, {""}, {""}, {""},
#line 500 "sp500.gperf"
      {"WMB", 487},
#line 477 "sp500.gperf"
      {"VEEV", 464},
      {""}, {""}, {""}, {""},
#line 268 "sp500.gperf"
      {"J", 255},
      {""},
#line 13 "sp500.gperf"
      {"A", 0},
      {""},
#line 508 "sp500.gperf"
      {"XEL", 495},
      {""}, {""}, {""}, {""},
#line 25 "sp500.gperf"
      {"AEE", 12},
      {""}, {""}, {""}, {""},
#line 33 "sp500.gperf"
      {"ALB", 20},
      {""}, {""}, {""}, {""},
#line 35 "sp500.gperf"
      {"ALL", 22},
      {""}, {""},
#line 49 "sp500.gperf"
      {"APD", 36},
#line 330 "sp500.gperf"
      {"MS", 317},
#line 493 "sp500.gperf"
      {"WBD", 480},
      {""}, {""},
#line 333 "sp500.gperf"
      {"MSI", 320},
      {""},
#line 40 "sp500.gperf"
      {"AME", 27},
#line 283 "sp500.gperf"
      {"KMI", 270},
      {""}, {""},
#line 460 "sp500.gperf"
      {"TT", 447},
      {""}, {""}, {""},
#line 282 "sp500.gperf"
      {"KMB", 269},
      {""},
#line 503 "sp500.gperf"
      {"WSM", 490},
      {""}, {""},
#line 85 "sp500.gperf"
      {"C", 72},
#line 106 "sp500.gperf"
      {"CL", 93},
#line 39 "sp500.gperf"
      {"AMD", 26},
#line 458 "sp500.gperf"
      {"TSLA", 445},
      {""},
#line 504 "sp500.gperf"
      {"WST", 491},
#line 376 "sp500.gperf"
      {"PH", 363},
#line 461 "sp500.gperf"
      {"TTD", 448},
      {""}, {""}, {""},
#line 103 "sp500.gperf"
      {"CI", 90},
#line 417 "sp500.gperf"
      {"SLB", 404},
      {""}, {""},
#line 501 "sp500.gperf"
      {"WMT", 488},
      {""}, {""},
#line 332 "sp500.gperf"
      {"MSFT", 319},
      {""},
#line 487 "sp500.gperf"
      {"VST", 474},
      {""},
#line 389 "sp500.gperf"
      {"PSA", 376},
      {""}, {""},
#line 270 "sp500.gperf"
      {"JBL", 257},
      {""},
#line 109 "sp500.gperf"
      {"CME", 96},
#line 274 "sp500.gperf"
      {"JPM", 261},
      {""},
#line 111 "sp500.gperf"
      {"CMI", 98},
      {""},
#line 319 "sp500.gperf"
      {"MLM", 306},
      {""}, {""},
#line 279 "sp500.gperf"
      {"KIM", 266},
      {""},
#line 30 "sp500.gperf"
      {"AIZ", 17},
#line 15 "sp500.gperf"
      {"ABBV", 2},
      {""}, {""}, {""},
#line 334 "sp500.gperf"
      {"MTB", 321},
      {""}, {""},
#line 315 "sp500.gperf"
      {"MET", 302},
      {""},
#line 335 "sp500.gperf"
      {"MTD", 322},
      {""}, {""},
#line 48 "sp500.gperf"
      {"APA", 35},
#line 90 "sp500.gperf"
      {"CB", 77},
#line 340 "sp500.gperf"
      {"NEE", 327},
      {""},
#line 53 "sp500.gperf"
      {"APTV", 40},
      {""},
#line 343 "sp500.gperf"
      {"NI", 330},
#line 320 "sp500.gperf"
      {"MMM", 307},
#line 450 "sp500.gperf"
      {"TMUS", 437},
      {""},
#line 43 "sp500.gperf"
      {"AMT", 30},
      {""},
#line 344 "sp500.gperf"
      {"NKE", 331},
      {""}, {""}, {""}, {""},
#line 427 "sp500.gperf"
      {"STE", 414},
      {""}, {""}, {""}, {""},
#line 377 "sp500.gperf"
      {"PHM", 364},
      {""}, {""},
#line 386 "sp500.gperf"
      {"PPG", 373},
      {""},
#line 370 "sp500.gperf"
      {"PEG", 357},
#line 124 "sp500.gperf"
      {"CPT", 111},
      {""}, {""}, {""}, {""},
#line 37 "sp500.gperf"
      {"AMAT", 24},
      {""},
#line 17 "sp500.gperf"
      {"ABT", 4},
      {""},
#line 378 "sp500.gperf"
      {"PKG", 365},
      {""}, {""}, {""},
#line 316 "sp500.gperf"
      {"META", 303},
      {""},
#line 271 "sp500.gperf"
      {"JCI", 258},
      {""}, {""}, {""}, {""},
#line 413 "sp500.gperf"
      {"SBUX", 400},
      {""}, {""}, {""},
#line 100 "sp500.gperf"
      {"CHD", 87},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 309 "sp500.gperf"
      {"MCD", 296},
#line 32 "sp500.gperf"
      {"AKAM", 19},
#line 284 "sp500.gperf"
      {"KO", 271},
      {""}, {""},
#line 341 "sp500.gperf"
      {"NEM", 328},
      {""}, {""},
#line 50 "sp500.gperf"
      {"APH", 37},
#line 322 "sp500.gperf"
      {"MO", 309},
#line 29 "sp500.gperf"
      {"AIG", 16},
#line 45 "sp500.gperf"
      {"ANET", 32},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 287 "sp500.gperf"
      {"L", 274},
#line 281 "sp500.gperf"
      {"KLAC", 268},
#line 431 "sp500.gperf"
      {"STZ", 418},
      {""}, {""},
#line 93 "sp500.gperf"
      {"CCI", 80},
      {""}, {""}, {""}, {""},
#line 429 "sp500.gperf"
      {"STT", 416},
      {""},
#line 491 "sp500.gperf"
      {"WAB", 478},
#line 104 "sp500.gperf"
      {"CIEN", 91},
      {""},
#line 292 "sp500.gperf"
      {"LII", 279},
      {""},
#line 94 "sp500.gperf"
      {"CCL", 81},
      {""}, {""},
#line 273 "sp500.gperf"
      {"JNJ", 260},
      {""},
#line 496 "sp500.gperf"
      {"WEC", 483},
#line 497 "sp500.gperf"
      {"WELL", 484},
#line 506 "sp500.gperf"
      {"WY", 493},
#line 424 "sp500.gperf"
      {"SPG", 411},
#line 422 "sp500.gperf"
      {"SO", 409},
#line 97 "sp500.gperf"
      {"CEG", 84},
      {""}, {""}, {""}, {""},
#line 509 "sp500.gperf"
      {"XOM", 496},
      {""}, {""},
#line 479 "sp500.gperf"
      {"VLO", 466},
#line 403 "sp500.gperf"
      {"RL", 390},
      {""},
#line 452 "sp500.gperf"
      {"TPR", 439},
      {""},
#line 444 "sp500.gperf"
      {"TER", 431},
#line 374 "sp500.gperf"
      {"PG", 361},
#line 475 "sp500.gperf"
      {"USB", 462},
#line 130 "sp500.gperf"
      {"CSGP", 117},
#line 219 "sp500.gperf"
      {"GL", 206},
#line 448 "sp500.gperf"
      {"TKO", 435},
#line 269 "sp500.gperf"
      {"JBHT", 256},
#line 110 "sp500.gperf"
      {"CMG", 97},
      {""},
#line 213 "sp500.gperf"
      {"GE", 200},
#line 465 "sp500.gperf"
      {"TYL", 452},
#line 305 "sp500.gperf"
      {"MA", 292},
#line 115 "sp500.gperf"
      {"COF", 102},
#line 44 "sp500.gperf"
      {"AMZN", 31},
      {""},
#line 449 "sp500.gperf"
      {"TMO", 436},
      {""},
#line 481 "sp500.gperf"
      {"VMC", 468},
#line 423 "sp500.gperf"
      {"SOLV", 410},
#line 228 "sp500.gperf"
      {"GS", 215},
      {""}, {""}, {""}, {""}, {""},
#line 510 "sp500.gperf"
      {"XYL", 497},
      {""}, {""},
#line 51 "sp500.gperf"
      {"APO", 38},
#line 221 "sp500.gperf"
      {"GM", 208},
#line 324 "sp500.gperf"
      {"MPC", 311},
      {""},
#line 369 "sp500.gperf"
      {"PCG", 356},
#line 349 "sp500.gperf"
      {"NTAP", 336},
      {""},
#line 492 "sp500.gperf"
      {"WAT", 479},
      {""},
#line 404 "sp500.gperf"
      {"RMD", 391},
      {""}, {""}, {""},
#line 420 "sp500.gperf"
      {"SNDK", 407},
#line 318 "sp500.gperf"
      {"MKC", 305},
#line 280 "sp500.gperf"
      {"KKR", 267},
      {""}, {""},
#line 290 "sp500.gperf"
      {"LH", 277},
#line 392 "sp500.gperf"
      {"PTC", 379},
      {""}, {""}, {""}, {""}, {""},
#line 412 "sp500.gperf"
      {"SBAC", 399},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 296 "sp500.gperf"
      {"LMT", 283},
      {""}, {""}, {""}, {""},
#line 488 "sp500.gperf"
      {"VTR", 475},
      {""},
#line 419 "sp500.gperf"
      {"SNA", 406},
#line 132 "sp500.gperf"
      {"CTAS", 119},
#line 482 "sp500.gperf"
      {"VMRK", 469},
      {""},
#line 122 "sp500.gperf"
      {"CPAY", 109},
      {""},
#line 34 "sp500.gperf"
      {"ALGN", 21},
      {""},
#line 511 "sp500.gperf"
      {"XYZ", 498},
#line 380 "sp500.gperf"
      {"PLTR", 367},
      {""}, {""}, {""},
#line 446 "sp500.gperf"
      {"TGT", 433},
      {""}, {""}, {""},
#line 123 "sp500.gperf"
      {"CPRT", 110},
      {""}, {""}, {""},
#line 310 "sp500.gperf"
      {"MCHP", 297},
      {""},
#line 56 "sp500.gperf"
      {"ATO", 43},
      {""}, {""}, {""}, {""},
#line 435 "sp500.gperf"
      {"SYF", 422},
#line 470 "sp500.gperf"
      {"ULTA", 457},
#line 306 "sp500.gperf"
      {"MAA", 293},
#line 41 "sp500.gperf"
      {"AMGN", 28},
#line 505 "sp500.gperf"
      {"WTW", 492},
#line 189 "sp500.gperf"
      {"F", 176},
      {""},
#line 502 "sp500.gperf"
      {"WRB", 489},
      {""}, {""},
#line 278 "sp500.gperf"
      {"KHC", 265},
#line 196 "sp500.gperf"
      {"FE", 183},
#line 513 "sp500.gperf"
      {"ZBH", 500},
      {""}, {""}, {""},
#line 272 "sp500.gperf"
      {"JKHY", 259},
#line 317 "sp500.gperf"
      {"MGM", 304},
      {""}, {""}, {""}, {""},
#line 388 "sp500.gperf"
      {"PRU", 375},
#line 414 "sp500.gperf"
      {"SCHW", 401},
      {""},
#line 89 "sp500.gperf"
      {"CAT", 76},
#line 117 "sp500.gperf"
      {"COIN", 104},
#line 348 "sp500.gperf"
      {"NSC", 335},
      {""}, {""}, {""}, {""},
#line 416 "sp500.gperf"
      {"SJM", 403},
#line 204 "sp500.gperf"
      {"FLEX", 191},
      {""},
#line 464 "sp500.gperf"
      {"TXT", 451},
      {""},
#line 382 "sp500.gperf"
      {"PNC", 369},
      {""},
#line 285 "sp500.gperf"
      {"KR", 272},
      {""},
#line 395 "sp500.gperf"
      {"Q", 382},
#line 54 "sp500.gperf"
      {"ARE", 41},
      {""}, {""},
#line 383 "sp500.gperf"
      {"PNR", 370},
      {""},
#line 397 "sp500.gperf"
      {"RCL", 384},
#line 372 "sp500.gperf"
      {"PFE", 359},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 489 "sp500.gperf"
      {"VTRS", 476},
#line 399 "sp500.gperf"
      {"REG", 386},
      {""}, {""}, {""},
#line 101 "sp500.gperf"
      {"CHRW", 88},
      {""}, {""}, {""},
#line 312 "sp500.gperf"
      {"MCO", 299},
      {""},
#line 409 "sp500.gperf"
      {"RSG", 396},
      {""}, {""},
#line 357 "sp500.gperf"
      {"O", 344},
      {""},
#line 406 "sp500.gperf"
      {"ROL", 393},
      {""}, {""}, {""},
#line 352 "sp500.gperf"
      {"NVDA", 339},
#line 31 "sp500.gperf"
      {"AJG", 18},
      {""},
#line 108 "sp500.gperf"
      {"CMCSA", 95},
      {""}, {""},
#line 426 "sp500.gperf"
      {"SRE", 413},
      {""}, {""},
#line 485 "sp500.gperf"
      {"VRT", 472},
      {""},
#line 359 "sp500.gperf"
      {"OKE", 346},
      {""}, {""},
#line 297 "sp500.gperf"
      {"LNT", 284},
      {""}, {""}, {""},
#line 384 "sp500.gperf"
      {"PNW", 371},
#line 241 "sp500.gperf"
      {"HPE", 228},
      {""},
#line 126 "sp500.gperf"
      {"CRL", 113},
      {""}, {""}, {""}, {""}, {""},
#line 28 "sp500.gperf"
      {"AFL", 15},
      {""},
#line 236 "sp500.gperf"
      {"HII", 223},
      {""},
#line 86 "sp500.gperf"
      {"CAH", 73},
      {""},
#line 415 "sp500.gperf"
      {"SHW", 402},
      {""},
#line 486 "sp500.gperf"
      {"VRTX", 473},
#line 466 "sp500.gperf"
      {"UAL", 453},
      {""},
#line 391 "sp500.gperf"
      {"PSX", 378},
#line 303 "sp500.gperf"
      {"LYB", 290},
      {""},
#line 113 "sp500.gperf"
      {"CNC", 100},
      {""}, {""},
#line 21 "sp500.gperf"
      {"ADI", 8},
      {""}, {""},
#line 368 "sp500.gperf"
      {"PCAR", 355},
      {""},
#line 118 "sp500.gperf"
      {"COO", 105},
#line 490 "sp500.gperf"
      {"VZ", 477},
#line 98 "sp500.gperf"
      {"CF", 85},
#line 55 "sp500.gperf"
      {"ARES", 42},
      {""},
#line 120 "sp500.gperf"
      {"COR", 107},
      {""},
#line 371 "sp500.gperf"
      {"PEP", 358},
      {""}, {""},
#line 459 "sp500.gperf"
      {"TSN", 446},
      {""}, {""},
#line 138 "sp500.gperf"
      {"D", 125},
      {""}, {""},
#line 514 "sp500.gperf"
      {"ZBRA", 501},
      {""},
#line 225 "sp500.gperf"
      {"GPC", 212},
#line 143 "sp500.gperf"
      {"DE", 130},
#line 375 "sp500.gperf"
      {"PGR", 362},
#line 102 "sp500.gperf"
      {"CHTR", 89},
#line 127 "sp500.gperf"
      {"CRM", 114},
      {""},
#line 170 "sp500.gperf"
      {"EL", 157},
      {""}, {""}, {""}, {""}, {""},
#line 307 "sp500.gperf"
      {"MAR", 294},
#line 214 "sp500.gperf"
      {"GEHC", 201},
#line 402 "sp500.gperf"
      {"RJF", 389},
      {""},
#line 336 "sp500.gperf"
      {"MU", 323},
      {""},
#line 480 "sp500.gperf"
      {"VLTO", 467},
#line 27 "sp500.gperf"
      {"AES", 14},
#line 453 "sp500.gperf"
      {"TRGP", 440},
#line 178 "sp500.gperf"
      {"ES", 165},
#line 237 "sp500.gperf"
      {"HLT", 224},
      {""},
#line 345 "sp500.gperf"
      {"NOC", 332},
#line 390 "sp500.gperf"
      {"PSKY", 377},
      {""},
#line 52 "sp500.gperf"
      {"APP", 39},
#line 350 "sp500.gperf"
      {"NTRS", 337},
#line 26 "sp500.gperf"
      {"AEP", 13},
      {""}, {""},
#line 172 "sp500.gperf"
      {"EME", 159},
      {""},
#line 311 "sp500.gperf"
      {"MCK", 298},
      {""},
#line 107 "sp500.gperf"
      {"CLX", 94},
#line 245 "sp500.gperf"
      {"HST", 232},
      {""},
#line 22 "sp500.gperf"
      {"ADM", 9},
#line 467 "sp500.gperf"
      {"UBER", 454},
      {""}, {""}, {""},
#line 471 "sp500.gperf"
      {"UNH", 458},
#line 400 "sp500.gperf"
      {"REGN", 387},
      {""}, {""}, {""},
#line 42 "sp500.gperf"
      {"AMP", 29},
#line 18 "sp500.gperf"
      {"ACGL", 5},
#line 131 "sp500.gperf"
      {"CSX", 118},
#line 314 "sp500.gperf"
      {"MDT", 301},
#line 244 "sp500.gperf"
      {"HSIC", 231},
#line 220 "sp500.gperf"
      {"GLW", 207},
#line 373 "sp500.gperf"
      {"PFG", 360},
      {""}, {""}, {""}, {""},
#line 38 "sp500.gperf"
      {"AMCR", 25},
      {""},
#line 158 "sp500.gperf"
      {"DTE", 145},
#line 432 "sp500.gperf"
      {"SW", 419},
      {""},
#line 156 "sp500.gperf"
      {"DPZ", 143},
      {""}, {""},
#line 36 "sp500.gperf"
      {"ALLE", 23},
      {""},
#line 134 "sp500.gperf"
      {"CTVA", 121},
#line 342 "sp500.gperf"
      {"NFLX", 329},
      {""}, {""}, {""}, {""},
#line 175 "sp500.gperf"
      {"EQIX", 162},
      {""},
#line 361 "sp500.gperf"
      {"ON", 348},
#line 112 "sp500.gperf"
      {"CMS", 99},
      {""},
#line 346 "sp500.gperf"
      {"NOW", 333},
      {""},
#line 364 "sp500.gperf"
      {"OTIS", 351},
      {""},
#line 148 "sp500.gperf"
      {"DHI", 135},
      {""},
#line 474 "sp500.gperf"
      {"URI", 461},
      {""},
#line 440 "sp500.gperf"
      {"TDG", 427},
      {""}, {""}, {""}, {""},
#line 125 "sp500.gperf"
      {"CRH", 112},
      {""}, {""},
#line 351 "sp500.gperf"
      {"NUE", 338},
#line 455 "sp500.gperf"
      {"TROW", 442},
      {""},
#line 325 "sp500.gperf"
      {"MPWR", 312},
#line 430 "sp500.gperf"
      {"STX", 417},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 235 "sp500.gperf"
      {"HIG", 222},
#line 353 "sp500.gperf"
      {"NVR", 340},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 176 "sp500.gperf"
      {"EQT", 163},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 498 "sp500.gperf"
      {"WFC", 485},
      {""}, {""}, {""},
#line 347 "sp500.gperf"
      {"NRG", 334},
#line 99 "sp500.gperf"
      {"CFG", 86},
      {""},
#line 216 "sp500.gperf"
      {"GEV", 203},
      {""}, {""},
#line 445 "sp500.gperf"
      {"TFC", 432},
      {""},
#line 19 "sp500.gperf"
      {"ACN", 6},
      {""}, {""},
#line 208 "sp500.gperf"
      {"FSLR", 195},
      {""}, {""}, {""},
#line 401 "sp500.gperf"
      {"RF", 388},
#line 313 "sp500.gperf"
      {"MDLZ", 300},
      {""},
#line 165 "sp500.gperf"
      {"ECL", 152},
      {""}, {""},
#line 116 "sp500.gperf"
      {"COHR", 103},
      {""}, {""},
#line 63 "sp500.gperf"
      {"BA", 50},
#line 495 "sp500.gperf"
      {"WDC", 482},
      {""}, {""}, {""},
#line 428 "sp500.gperf"
      {"STLD", 415},
#line 233 "sp500.gperf"
      {"HCA", 220},
#line 494 "sp500.gperf"
      {"WDAY", 481},
#line 298 "sp500.gperf"
      {"LOW", 285},
#line 46 "sp500.gperf"
      {"AON", 33},
      {""},
#line 47 "sp500.gperf"
      {"AOS", 34},
      {""}, {""}, {""},
#line 385 "sp500.gperf"
      {"PODD", 372},
#line 323 "sp500.gperf"
      {"MOS", 310},
      {""}, {""},
#line 436 "sp500.gperf"
      {"SYK", 423},
      {""},
#line 230 "sp500.gperf"
      {"HAL", 217},
#line 321 "sp500.gperf"
      {"MNST", 308},
      {""},
#line 512 "sp500.gperf"
      {"YUM", 499},
      {""},
#line 360 "sp500.gperf"
      {"OMC", 347},
#line 457 "sp500.gperf"
      {"TSCO", 444},
#line 211 "sp500.gperf"
      {"GD", 198},
#line 289 "sp500.gperf"
      {"LEN", 276},
#line 366 "sp500.gperf"
      {"PANW", 353},
#line 515 "sp500.gperf"
      {"ZTS", 502},
      {""},
#line 447 "sp500.gperf"
      {"TJX", 434},
#line 293 "sp500.gperf"
      {"LIN", 280},
#line 71 "sp500.gperf"
      {"BG", 58},
      {""},
#line 442 "sp500.gperf"
      {"TECH", 429},
      {""},
#line 74 "sp500.gperf"
      {"BKR", 61},
      {""}, {""}, {""}, {""},
#line 473 "sp500.gperf"
      {"UPS", 460},
      {""},
#line 439 "sp500.gperf"
      {"TAP", 426},
#line 398 "sp500.gperf"
      {"RDDT", 385},
      {""}, {""}, {""}, {""},
#line 75 "sp500.gperf"
      {"BLDR", 62},
      {""}, {""}, {""},
#line 114 "sp500.gperf"
      {"CNP", 101},
#line 232 "sp500.gperf"
      {"HBAN", 219},
#line 411 "sp500.gperf"
      {"RVTY", 398},
      {""},
#line 60 "sp500.gperf"
      {"AXON", 47},
#line 119 "sp500.gperf"
      {"COP", 106},
#line 121 "sp500.gperf"
      {"COST", 108},
      {""},
#line 393 "sp500.gperf"
      {"PWR", 380},
      {""}, {""},
#line 337 "sp500.gperf"
      {"NCLH", 324},
      {""},
#line 139 "sp500.gperf"
      {"DAL", 126},
#line 226 "sp500.gperf"
      {"GPN", 213},
#line 456 "sp500.gperf"
      {"TRV", 443},
#line 215 "sp500.gperf"
      {"GEN", 202},
      {""}, {""},
#line 145 "sp500.gperf"
      {"DELL", 132},
#line 308 "sp500.gperf"
      {"MAS", 295},
#line 151 "sp500.gperf"
      {"DLR", 138},
      {""},
#line 218 "sp500.gperf"
      {"GIS", 205},
      {""}, {""}, {""},
#line 222 "sp500.gperf"
      {"GNRC", 209},
      {""},
#line 83 "sp500.gperf"
      {"BX", 70},
      {""}, {""},
#line 146 "sp500.gperf"
      {"DG", 133},
#line 62 "sp500.gperf"
      {"AZO", 49},
      {""},
#line 326 "sp500.gperf"
      {"MRK", 313},
      {""},
#line 291 "sp500.gperf"
      {"LHX", 278},
#line 242 "sp500.gperf"
      {"HPQ", 229},
      {""}, {""}, {""},
#line 168 "sp500.gperf"
      {"EG", 155},
      {""}, {""},
#line 405 "sp500.gperf"
      {"ROK", 392},
#line 129 "sp500.gperf"
      {"CSCO", 116},
      {""}, {""}, {""}, {""}, {""},
#line 410 "sp500.gperf"
      {"RTX", 397},
      {""}, {""},
#line 137 "sp500.gperf"
      {"CVX", 124},
#line 173 "sp500.gperf"
      {"EMR", 160},
      {""}, {""}, {""},
#line 198 "sp500.gperf"
      {"FFIV", 185},
      {""},
#line 144 "sp500.gperf"
      {"DECK", 131},
#line 463 "sp500.gperf"
      {"TXN", 450},
#line 260 "sp500.gperf"
      {"IP", 247},
      {""}, {""},
#line 217 "sp500.gperf"
      {"GILD", 204},
#line 207 "sp500.gperf"
      {"FRT", 194},
      {""},
#line 469 "sp500.gperf"
      {"UHS", 456},
      {""}, {""},
#line 136 "sp500.gperf"
      {"CVS", 123},
#line 79 "sp500.gperf"
      {"BR", 66},
#line 76 "sp500.gperf"
      {"BLK", 63},
      {""}, {""},
#line 462 "sp500.gperf"
      {"TTWO", 449},
#line 163 "sp500.gperf"
      {"EBAY", 150},
#line 210 "sp500.gperf"
      {"FTV", 197},
      {""}, {""}, {""},
#line 87 "sp500.gperf"
      {"CARR", 74},
      {""},
#line 421 "sp500.gperf"
      {"SNPS", 408},
#line 96 "sp500.gperf"
      {"CDW", 83},
      {""}, {""},
#line 286 "sp500.gperf"
      {"KVUE", 273},
      {""},
#line 294 "sp500.gperf"
      {"LITE", 281},
#line 185 "sp500.gperf"
      {"EXE", 172},
#line 227 "sp500.gperf"
      {"GRMN", 214},
#line 243 "sp500.gperf"
      {"HRL", 230},
#line 181 "sp500.gperf"
      {"ETR", 168},
      {""},
#line 174 "sp500.gperf"
      {"EOG", 161},
      {""},
#line 396 "sp500.gperf"
      {"QCOM", 383},
#line 160 "sp500.gperf"
      {"DVA", 147},
#line 203 "sp500.gperf"
      {"FIX", 190},
      {""}, {""}, {""},
#line 149 "sp500.gperf"
      {"DHR", 136},
#line 152 "sp500.gperf"
      {"DLTR", 139},
      {""}, {""},
#line 61 "sp500.gperf"
      {"AXP", 48},
#line 299 "sp500.gperf"
      {"LRCX", 286},
      {""},
#line 304 "sp500.gperf"
      {"LYV", 291},
      {""}, {""}, {""},
#line 135 "sp500.gperf"
      {"CVNA", 122},
      {""}, {""},
#line 200 "sp500.gperf"
      {"FIS", 187},
      {""},
#line 507 "sp500.gperf"
      {"WYNN", 494},
      {""}, {""}, {""},
#line 265 "sp500.gperf"
      {"IT", 252},
      {""}, {""}, {""}, {""},
#line 157 "sp500.gperf"
      {"DRI", 144},
      {""}, {""}, {""}, {""},
#line 201 "sp500.gperf"
      {"FISV", 188},
      {""}, {""},
#line 212 "sp500.gperf"
      {"GDDY", 199},
      {""}, {""}, {""}, {""},
#line 57 "sp500.gperf"
      {"AVGO", 44},
#line 472 "sp500.gperf"
      {"UNP", 459},
      {""}, {""}, {""}, {""}, {""},
#line 454 "sp500.gperf"
      {"TRMB", 441},
#line 197 "sp500.gperf"
      {"FERG", 184},
      {""},
#line 234 "sp500.gperf"
      {"HD", 221},
#line 59 "sp500.gperf"
      {"AWK", 46},
      {""}, {""},
#line 171 "sp500.gperf"
      {"ELV", 158},
#line 483 "sp500.gperf"
      {"VRSK", 470},
      {""}, {""},
#line 91 "sp500.gperf"
      {"CBOE", 78},
      {""}, {""},
#line 276 "sp500.gperf"
      {"KEY", 263},
      {""},
#line 92 "sp500.gperf"
      {"CBRE", 79},
#line 153 "sp500.gperf"
      {"DOC", 140},
#line 202 "sp500.gperf"
      {"FITB", 189},
#line 407 "sp500.gperf"
      {"ROP", 394},
#line 408 "sp500.gperf"
      {"ROST", 395},
      {""}, {""}, {""},
#line 64 "sp500.gperf"
      {"BAC", 51},
#line 65 "sp500.gperf"
      {"BALL", 52},
#line 251 "sp500.gperf"
      {"IBM", 238},
      {""},
#line 72 "sp500.gperf"
      {"BIIB", 59},
      {""}, {""}, {""},
#line 468 "sp500.gperf"
      {"UDR", 455},
#line 209 "sp500.gperf"
      {"FTNT", 196},
      {""}, {""},
#line 82 "sp500.gperf"
      {"BSX", 69},
      {""}, {""}, {""}, {""},
#line 252 "sp500.gperf"
      {"ICE", 239},
#line 69 "sp500.gperf"
      {"BEN", 56},
#line 327 "sp500.gperf"
      {"MRNA", 314},
#line 433 "sp500.gperf"
      {"SWK", 420},
      {""}, {""}, {""}, {""},
#line 223 "sp500.gperf"
      {"GOOG", 210},
#line 224 "sp500.gperf"
      {"GOOGL", 211},
#line 141 "sp500.gperf"
      {"DD", 128},
#line 302 "sp500.gperf"
      {"LVS", 289},
#line 105 "sp500.gperf"
      {"CINF", 92},
      {""},
#line 88 "sp500.gperf"
      {"CASY", 75},
      {""}, {""}, {""}, {""}, {""},
#line 166 "sp500.gperf"
      {"ED", 153},
      {""},
#line 300 "sp500.gperf"
      {"LULU", 287},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 192 "sp500.gperf"
      {"FCX", 179},
      {""},
#line 394 "sp500.gperf"
      {"PYPL", 381},
#line 155 "sp500.gperf"
      {"DOW", 142},
#line 363 "sp500.gperf"
      {"ORLY", 350},
      {""},
#line 275 "sp500.gperf"
      {"KDP", 262},
      {""},
#line 23 "sp500.gperf"
      {"ADP", 10},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 14 "sp500.gperf"
      {"AAPL", 1},
      {""}, {""}, {""},
#line 169 "sp500.gperf"
      {"EIX", 156},
#line 484 "sp500.gperf"
      {"VRSN", 471},
#line 205 "sp500.gperf"
      {"FOX", 192},
      {""},
#line 288 "sp500.gperf"
      {"LDOS", 275},
      {""},
#line 277 "sp500.gperf"
      {"KEYS", 264},
      {""},
#line 150 "sp500.gperf"
      {"DIS", 137},
      {""}, {""}, {""}, {""},
#line 248 "sp500.gperf"
      {"HUM", 235},
      {""}, {""}, {""},
#line 183 "sp500.gperf"
      {"EW", 170},
      {""},
#line 24 "sp500.gperf"
      {"ADSK", 11},
      {""}, {""}, {""},
#line 179 "sp500.gperf"
      {"ESS", 166},
#line 20 "sp500.gperf"
      {"ADBE", 7},
#line 249 "sp500.gperf"
      {"HWM", 236},
#line 329 "sp500.gperf"
      {"MRVL", 316},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 434 "sp500.gperf"
      {"SWKS", 421},
      {""}, {""},
#line 16 "sp500.gperf"
      {"ABNB", 3},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 206 "sp500.gperf"
      {"FOXA", 193},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 425 "sp500.gperf"
      {"SPGI", 412},
      {""},
#line 154 "sp500.gperf"
      {"DOV", 141},
      {""}, {""}, {""}, {""},
#line 81 "sp500.gperf"
      {"BRO", 68},
      {""},
#line 229 "sp500.gperf"
      {"GWW", 216},
#line 199 "sp500.gperf"
      {"FICO", 186},
      {""}, {""}, {""}, {""},
#line 180 "sp500.gperf"
      {"ETN", 167},
      {""},
#line 478 "sp500.gperf"
      {"VICI", 465},
      {""}, {""}, {""},
#line 338 "sp500.gperf"
      {"NDAQ", 325},
#line 184 "sp500.gperf"
      {"EXC", 171},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 188 "sp500.gperf"
      {"EXR", 175},
#line 295 "sp500.gperf"
      {"LLY", 282},
#line 301 "sp500.gperf"
      {"LUV", 288},
      {""}, {""},
#line 191 "sp500.gperf"
      {"FAST", 178},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 95 "sp500.gperf"
      {"CDNS", 82},
      {""},
#line 133 "sp500.gperf"
      {"CTSH", 120},
      {""},
#line 238 "sp500.gperf"
      {"HON", 225},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 354 "sp500.gperf"
      {"NWS", 341},
      {""}, {""},
#line 331 "sp500.gperf"
      {"MSCI", 318},
      {""},
#line 267 "sp500.gperf"
      {"IVZ", 254},
      {""}, {""},
#line 367 "sp500.gperf"
      {"PAYX", 354},
#line 162 "sp500.gperf"
      {"DXCM", 149},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 257 "sp500.gperf"
      {"INTC", 244},
      {""}, {""}, {""}, {""},
#line 358 "sp500.gperf"
      {"ODFL", 345},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 66 "sp500.gperf"
      {"BAX", 53},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 239 "sp500.gperf"
      {"HONA", 226},
#line 58 "sp500.gperf"
      {"AVY", 45},
      {""}, {""}, {""}, {""}, {""},
#line 355 "sp500.gperf"
      {"NWSA", 342},
      {""},
#line 418 "sp500.gperf"
      {"SMCI", 405},
      {""}, {""},
#line 262 "sp500.gperf"
      {"IR", 249},
      {""}, {""}, {""},
#line 231 "sp500.gperf"
      {"HAS", 218},
      {""}, {""}, {""},
#line 266 "sp500.gperf"
      {"ITW", 253},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 80 "sp500.gperf"
      {"BRK.B", 67},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 339 "sp500.gperf"
      {"NDSN", 326},
      {""}, {""}, {""},
#line 437 "sp500.gperf"
      {"SYY", 424},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 73 "sp500.gperf"
      {"BKNG", 60},
      {""}, {""}, {""}, {""},
#line 261 "sp500.gperf"
      {"IQV", 248},
      {""}, {""}, {""}, {""},
#line 263 "sp500.gperf"
      {"IRM", 250},
      {""},
#line 161 "sp500.gperf"
      {"DVN", 148},
#line 147 "sp500.gperf"
      {"DGX", 134},
      {""}, {""},
#line 255 "sp500.gperf"
      {"IFF", 242},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 164 "sp500.gperf"
      {"ECHO", 151},
#line 84 "sp500.gperf"
      {"BXP", 71},
#line 128 "sp500.gperf"
      {"CRWD", 115},
      {""}, {""}, {""}, {""},
#line 362 "sp500.gperf"
      {"ORCL", 349},
      {""}, {""},
#line 254 "sp500.gperf"
      {"IEX", 241},
      {""}, {""},
#line 194 "sp500.gperf"
      {"FDX", 181},
      {""}, {""}, {""},
#line 258 "sp500.gperf"
      {"INTU", 245},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 182 "sp500.gperf"
      {"EVRG", 169},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 193 "sp500.gperf"
      {"FDS", 180},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 441 "sp500.gperf"
      {"TDY", 428},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 70 "sp500.gperf"
      {"BF.B", 57},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 246 "sp500.gperf"
      {"HSY", 233},
      {""},
#line 264 "sp500.gperf"
      {"ISRG", 251},
      {""}, {""},
#line 77 "sp500.gperf"
      {"BMY", 64},
      {""}, {""}, {""}, {""},
#line 190 "sp500.gperf"
      {"FANG", 177},
      {""}, {""}, {""},
#line 159 "sp500.gperf"
      {"DUK", 146},
      {""}, {""}, {""}, {""},
#line 328 "sp500.gperf"
      {"MRSH", 315},
#line 68 "sp500.gperf"
      {"BDX", 55},
#line 256 "sp500.gperf"
      {"INCY", 243},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 67 "sp500.gperf"
      {"BBY", 54},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 240 "sp500.gperf"
      {"HOOD", 227},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 167 "sp500.gperf"
      {"EFX", 154},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 247 "sp500.gperf"
      {"HUBB", 234},
#line 177 "sp500.gperf"
      {"ERIE", 164},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 142 "sp500.gperf"
      {"DDOG", 129},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 78 "sp500.gperf"
      {"BNY", 65},
      {""}, {""}, {""}, {""}, {""},
#line 250 "sp500.gperf"
      {"IBKR", 237},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
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
#line 365 "sp500.gperf"
      {"OXY", 352},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 195 "sp500.gperf"
      {"FDXF", 182},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 140 "sp500.gperf"
      {"DASH", 127},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""},
#line 253 "sp500.gperf"
      {"IDXX", 240},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 356 "sp500.gperf"
      {"NXPI", 343},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 259 "sp500.gperf"
      {"INVH", 246},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 186 "sp500.gperf"
      {"EXPD", 173},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 187 "sp500.gperf"
      {"EXPE", 174}
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
  return static_cast<struct Sp500GperfEntry *> (0);
}
#line 516 "sp500.gperf"

