/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf stock.gperf  */
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
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "stock.gperf"

#include <cstring>
/* maximum key range = 238, duplicates = 0 */

class StockGperf
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static const char *lookup (const char *str, unsigned int len);
};

inline unsigned int
StockGperf::hash (const char *str, unsigned int len)
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
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

const char *
StockGperf::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 100,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 5,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 238
    };

  static const char * const wordlist[] =
    {
      "",
      "T",
      "",
      "MMM",
      "",
      "WMT",
      "C",
      "MS",
      "", "",
      "CRM",
      "",
      "MO",
      "TMO",
      "", "", "",
      "SO",
      "V",
      "QCOM",
      "CMCSA",
      "",
      "GM",
      "TGT",
      "COST",
      "", "",
      "GS",
      "MDT",
      "CSCO",
      "CVS",
      "",
      "PM",
      "MCD",
      "", "", "",
      "MA",
      "AMT",
      "",
      "DOW",
      "",
      "RTX",
      "CAT",
      "", "", "",
      "GD",
      "COP",
      "", "", "",
      "PG",
      "MET",
      "VZ",
      "EMR",
      "", "",
      "SPG",
      "",
      "MRK",
      "",
      "CVX",
      "AMD",
      "GOOG",
      "TXN",
      "",
      "KO",
      "ACN",
      "", "",
      "F",
      "GE",
      "JPM",
      "", "", "",
      "DE",
      "LMT",
      "MSFT",
      "WFC",
      "",
      "CL",
      "",
      "AMGN",
      "",
      "AVGO",
      "",
      "COF",
      "META",
      "LOW",
      "ISRG",
      "",
      "DIS",
      "INTC",
      "EXC",
      "ORCL",
      "BA",
      "ABT",
      "AMZN",
      "", "", "",
      "BAC",
      "",
      "AXP",
      "NVDA",
      "",
      "JNJ",
      "TMUS",
      "", "", "",
      "PEP",
      "", "", "",
      "BK",
      "AIG",
      "TSLA",
      "",
      "CHTR",
      "",
      "IBM",
      "", "",
      "SCHW",
      "",
      "NEE",
      "", "", "", "",
      "NKE",
      "",
      "FDX",
      "",
      "HD",
      "UPS",
      "MDLZ",
      "DHR",
      "", "",
      "BMY",
      "", "", "", "",
      "HON",
      "", "", "", "",
      "PFE",
      "", "", "", "",
      "UNP",
      "", "", "", "",
      "LIN",
      "BKNG",
      "", "", "",
      "USB",
      "", "", "", "",
      "KHC",
      "ADBE",
      "",
      "ABBV",
      "", "",
      "AAPL",
      "", "", "",
      "DUK",
      "GILD",
      "", "", "", "",
      "INTU",
      "", "", "",
      "BLK",
      "", "", "", "", "", "", "", "", "",
      "", "", "",
      "SBUX",
      "", "", "", "",
      "NFLX",
      "", "", "", "", "", "", "",
      "PYPL",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "",
      "LLY",
      "", "", "", "",
      "UNH"
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          const char *s = wordlist[key];

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return s;
        }
    }
  return 0;
}
#line 111 "stock.gperf"

