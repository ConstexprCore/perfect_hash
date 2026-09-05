// Tests for the wide (N > 255) container and the > 32-byte comparison path.
#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>
#include <ConstexprCore/wide_perfect_hash.h>

#include <array>
#include <string>
#include <string_view>

using namespace ConstexprCore;

// ---------------------------------------------------------------------------
// Synthetic key sets with static storage (needed for the reference NTTP).
// ---------------------------------------------------------------------------
namespace {

// 300 short keys "k0".."k299" (≤ 4 bytes → single lane, length folded in).
constexpr auto short300 = [] {
    std::array<std::array<char, 5>, 300> buf{};
    for (std::size_t i = 0; i < 300; ++i) {
        buf[i][0] = 'k';
        std::size_t n = i, p = 1;
        char tmp[4]{}; int t = 0;
        do { tmp[t++] = static_cast<char>('0' + n % 10); n /= 10; } while (n);
        while (t) buf[i][p++] = tmp[--t];
    }
    return buf;
}();
constexpr auto short300_keys = [] {
    std::array<std::string_view, 300> k{};
    for (std::size_t i = 0; i < 300; ++i) k[i] = std::string_view(short300[i].data());
    return k;
}();

// 40 medium keys of 9..15 bytes (two lanes, length folded into lane 1).
constexpr auto medium40 = [] {
    std::array<std::array<char, 16>, 40> buf{};
    for (std::size_t i = 0; i < 40; ++i) {
        const char* base = "medium_key_";
        std::size_t p = 0;
        for (; base[p]; ++p) buf[i][p] = base[p];
        buf[i][p++] = static_cast<char>('a' + i % 26);
        if (i >= 26) buf[i][p++] = static_cast<char>('a' + (i * 7) % 26);
        if (i % 3 == 0) buf[i][p++] = 'x';
    }
    return buf;
}();
constexpr auto medium40_keys = [] {
    std::array<std::string_view, 40> k{};
    for (std::size_t i = 0; i < 40; ++i) k[i] = std::string_view(medium40[i].data());
    return k;
}();

// Long keys (24..54 bytes): chunked compare + separate length.
inline constexpr std::array<std::string_view, 12> long_keys = {
    "java.util.concurrent.ConcurrentHashMap",
    "java.util.concurrent.ConcurrentLinkedQueue",
    "java.util.concurrent.CopyOnWriteArrayList",
    "java.util.concurrent.atomic.AtomicInteger",
    "java.util.concurrent.locks.ReentrantReadWriteLock",
    "java.util.function.BiFunction",
    "java.lang.reflect.InvocationTargetException",
    "java.nio.channels.AsynchronousSocketChannel",
    "org.springframework.web.bind.annotation.RequestMapping",
    "com.fasterxml.jackson.databind.ObjectMapper",
    "com.google.common.util.concurrent.ListenableFuture",
    "io.netty.channel.socket.nio.NioSocketChannel",
};

} // namespace

// ---------------------------------------------------------------------------
// wide set: 300 short keys
// ---------------------------------------------------------------------------
static constexpr auto wide300 = make_wide_perfect_set<short300_keys>();

TEST_CASE("wide set: 300 short keys, all hits at compile time and run time") {
    static_assert(wide300.size() == 300);
    static_assert(wide300.table_size() == 512);
    static_assert(wide300.contains("k0"));
    static_assert(wide300.contains("k299"));
    static_assert(!wide300.contains("k300"));
    static_assert(!wide300.contains(""));
    for (std::size_t i = 0; i < 300; ++i) {
        CAPTURE(i);
        CHECK(wide300.contains(short300_keys[i]));
        auto idx = wide300.index_of(short300_keys[i]);
        REQUIRE(idx.has_value());
        CHECK(*idx == i);
        CHECK(wide300.key_at(i) == short300_keys[i]);
    }
    CHECK_FALSE(wide300.contains("k"));
    CHECK_FALSE(wide300.contains("k30000"));
    CHECK_FALSE(wide300.contains("K12"));
    CHECK_FALSE(wide300.contains(std::string_view("k12\0", 4)));
    CHECK_FALSE(wide300.contains("this key is far longer than any stored key"));
}

// ---------------------------------------------------------------------------
// wide map: 40 medium keys (two lanes) with values
// ---------------------------------------------------------------------------
inline constexpr auto medium40_values = [] {
    std::array<int, 40> v{};
    for (int i = 0; i < 40; ++i) v[i] = i * 10;
    return v;
}();
static constexpr auto wide_medium = make_wide_perfect_map<medium40_keys, medium40_values>();

TEST_CASE("wide map: 9-15 byte keys use two lanes with folded length") {
    static_assert(wide_medium.size() == 40);
    static_assert(*wide_medium.lookup(medium40_keys[3]) == 30);
    for (std::size_t i = 0; i < 40; ++i) {
        CAPTURE(medium40_keys[i]);
        auto v = wide_medium.lookup(medium40_keys[i]);
        REQUIRE(v.has_value());
        CHECK(*v == static_cast<int>(i) * 10);
        // a one-byte-longer / shorter probe must miss
        std::string longer(medium40_keys[i]); longer.push_back('_');
        CHECK_FALSE(wide_medium.contains(longer));
        std::string shorter(medium40_keys[i]); shorter.pop_back();
        bool shorter_is_a_key = false;
        for (auto k : medium40_keys) shorter_is_a_key |= (k == shorter);
        if (!shorter_is_a_key) CHECK_FALSE(wide_medium.contains(shorter));
    }
}

// ---------------------------------------------------------------------------
// wide set with long keys (chunk path) and the classic set with long keys
// ---------------------------------------------------------------------------
static constexpr auto wide_long = make_wide_perfect_set<long_keys>();
static constexpr auto classic_long = make_perfect_map<
    kv<"java.util.concurrent.ConcurrentHashMap", 0>,
    kv<"java.util.concurrent.ConcurrentLinkedQueue", 1>,
    kv<"java.util.concurrent.CopyOnWriteArrayList", 2>,
    kv<"java.util.concurrent.atomic.AtomicInteger", 3>,
    kv<"java.util.concurrent.locks.ReentrantReadWriteLock", 4>,
    kv<"java.util.function.BiFunction", 5>,
    kv<"java.lang.reflect.InvocationTargetException", 6>,
    kv<"java.nio.channels.AsynchronousSocketChannel", 7>,
    kv<"org.springframework.web.bind.annotation.RequestMapping", 8>,
    kv<"com.fasterxml.jackson.databind.ObjectMapper", 9>,
    kv<"com.google.common.util.concurrent.ListenableFuture", 10>,
    kv<"io.netty.channel.socket.nio.NioSocketChannel", 11>>();

TEST_CASE("long keys (> 32 bytes): wide set and classic map agree, chunked compare rejects near misses") {
    static_assert(wide_long.contains("org.springframework.web.bind.annotation.RequestMapping"));
    static_assert(*classic_long.lookup("org.springframework.web.bind.annotation.RequestMapping") == 8);
    for (std::size_t i = 0; i < long_keys.size(); ++i) {
        CAPTURE(long_keys[i]);
        CHECK(wide_long.contains(long_keys[i]));
        CHECK(*wide_long.index_of(long_keys[i]) == i);
        auto v = classic_long.lookup(long_keys[i]);
        REQUIRE(v.has_value());
        CHECK(*v == static_cast<int>(i));
        // Mutate a byte in every 16-byte chunk: each must be caught.
        std::string s(long_keys[i]);
        for (std::size_t pos = 0; pos < s.size(); pos += 16) {
            std::string m = s; m[pos] = (m[pos] == 'z') ? 'a' : 'z';
            CAPTURE(m);
            CHECK_FALSE(wide_long.contains(m));
            CHECK_FALSE(classic_long.lookup(m).has_value());
        }
        // Prefix / extension must miss.
        CHECK_FALSE(wide_long.contains(s.substr(0, s.size() - 1)));
        CHECK_FALSE(classic_long.lookup(s.substr(0, s.size() - 1)).has_value());
        CHECK_FALSE(wide_long.contains(s + "s"));
        CHECK_FALSE(classic_long.lookup(s + "s").has_value());
    }
    // Keys near a page boundary: place a copy in the last bytes of a page.
    alignas(4096) static char page[8192];
    for (auto k : long_keys) {
        char* dst = page + 4096 - k.size();
        for (std::size_t c = 0; c < k.size(); ++c) dst[c] = k[c];
        CHECK(wide_long.contains(std::string_view(dst, k.size())));
        CHECK(classic_long.lookup(std::string_view(dst, k.size())).has_value());
    }
}

// ---------------------------------------------------------------------------
// fused values: the value rides inside the spare bytes of the stored lane
// ---------------------------------------------------------------------------
inline constexpr auto short300_u16 = [] {
    std::array<std::uint16_t, 300> v{};
    for (std::size_t i = 0; i < 300; ++i) v[i] = static_cast<std::uint16_t>(65535 - i * 219);
    return v;
}();
static constexpr auto fused_u16 = make_wide_perfect_map<short300_keys, short300_u16>();
inline constexpr auto short300_i8 = [] {
    std::array<std::int8_t, 300> v{};
    for (std::size_t i = 0; i < 300; ++i) v[i] = static_cast<std::int8_t>(static_cast<int>(i % 200) - 100);
    return v;
}();
static constexpr auto fused_i8 = make_wide_perfect_map<short300_keys, short300_i8>();
inline constexpr auto short300_i32 = [] {
    std::array<int, 300> v{};
    for (std::size_t i = 0; i < 300; ++i) v[i] = -1000000 * static_cast<int>(i);
    return v;
}();
static constexpr auto unfused_i32 = make_wide_perfect_map<short300_keys, short300_i32>();

TEST_CASE("wide map: values fused into the key lane round-trip exactly, incl. extremes and signed") {
    static_assert(decltype(fused_u16)::FUSED);
    static_assert(decltype(fused_i8)::FUSED);
    static_assert(!decltype(unfused_i32)::FUSED);   // 32 bits do not fit in 2 spare bytes
    static_assert(*fused_u16.lookup("k0") == 65535);
    static_assert(*fused_i8.lookup("k0") == -100);
    CHECK(fused_u16.algorithm_name() == "wide-pilot/fused");
    for (std::size_t i = 0; i < 300; ++i) {
        CAPTURE(i);
        auto a = fused_u16.lookup(short300_keys[i]);
        REQUIRE(a.has_value());
        CHECK(*a == short300_u16[i]);
        auto b = fused_i8.lookup(short300_keys[i]);
        REQUIRE(b.has_value());
        CHECK(*b == short300_i8[i]);
        auto c = unfused_i32.lookup(short300_keys[i]);
        REQUIRE(c.has_value());
        CHECK(*c == short300_i32[i]);
        CHECK(fused_u16.key_at(i) == short300_keys[i]);
    }
    // the fused bytes must not leak into the compare: a key with junk in bytes 5-6 must miss
    CHECK_FALSE(fused_u16.contains(std::string_view("k12\0\0\x12\x34", 7)));
    CHECK_FALSE(fused_u16.contains(std::string_view("k12\0\0\xff\xff", 7)));
    CHECK_FALSE(fused_u16.contains("k1234567"));
}

TEST_CASE("wide: algorithm description mentions the pilot scheme") {
    CHECK(wide300.algorithm_name().starts_with("wide-pilot"));
    CHECK(wide300.algorithm_description().find("pilot") != std::string::npos);
}

// ---------------------------------------------------------------------------
// the ordinary factories dispatch to wide mode past 255 entries
// ---------------------------------------------------------------------------
static constexpr auto big_map = make_perfect_map<
    kv<"w0", 0>,
    kv<"w1", 1>,
    kv<"w2", 2>,
    kv<"w3", 3>,
    kv<"w4", 4>,
    kv<"w5", 5>,
    kv<"w6", 6>,
    kv<"w7", 7>,
    kv<"w8", 8>,
    kv<"w9", 9>,
    kv<"w10", 10>,
    kv<"w11", 11>,
    kv<"w12", 12>,
    kv<"w13", 13>,
    kv<"w14", 14>,
    kv<"w15", 15>,
    kv<"w16", 16>,
    kv<"w17", 17>,
    kv<"w18", 18>,
    kv<"w19", 19>,
    kv<"w20", 20>,
    kv<"w21", 21>,
    kv<"w22", 22>,
    kv<"w23", 23>,
    kv<"w24", 24>,
    kv<"w25", 25>,
    kv<"w26", 26>,
    kv<"w27", 27>,
    kv<"w28", 28>,
    kv<"w29", 29>,
    kv<"w30", 30>,
    kv<"w31", 31>,
    kv<"w32", 32>,
    kv<"w33", 33>,
    kv<"w34", 34>,
    kv<"w35", 35>,
    kv<"w36", 36>,
    kv<"w37", 37>,
    kv<"w38", 38>,
    kv<"w39", 39>,
    kv<"w40", 40>,
    kv<"w41", 41>,
    kv<"w42", 42>,
    kv<"w43", 43>,
    kv<"w44", 44>,
    kv<"w45", 45>,
    kv<"w46", 46>,
    kv<"w47", 47>,
    kv<"w48", 48>,
    kv<"w49", 49>,
    kv<"w50", 50>,
    kv<"w51", 51>,
    kv<"w52", 52>,
    kv<"w53", 53>,
    kv<"w54", 54>,
    kv<"w55", 55>,
    kv<"w56", 56>,
    kv<"w57", 57>,
    kv<"w58", 58>,
    kv<"w59", 59>,
    kv<"w60", 60>,
    kv<"w61", 61>,
    kv<"w62", 62>,
    kv<"w63", 63>,
    kv<"w64", 64>,
    kv<"w65", 65>,
    kv<"w66", 66>,
    kv<"w67", 67>,
    kv<"w68", 68>,
    kv<"w69", 69>,
    kv<"w70", 70>,
    kv<"w71", 71>,
    kv<"w72", 72>,
    kv<"w73", 73>,
    kv<"w74", 74>,
    kv<"w75", 75>,
    kv<"w76", 76>,
    kv<"w77", 77>,
    kv<"w78", 78>,
    kv<"w79", 79>,
    kv<"w80", 80>,
    kv<"w81", 81>,
    kv<"w82", 82>,
    kv<"w83", 83>,
    kv<"w84", 84>,
    kv<"w85", 85>,
    kv<"w86", 86>,
    kv<"w87", 87>,
    kv<"w88", 88>,
    kv<"w89", 89>,
    kv<"w90", 90>,
    kv<"w91", 91>,
    kv<"w92", 92>,
    kv<"w93", 93>,
    kv<"w94", 94>,
    kv<"w95", 95>,
    kv<"w96", 96>,
    kv<"w97", 97>,
    kv<"w98", 98>,
    kv<"w99", 99>,
    kv<"w100", 100>,
    kv<"w101", 101>,
    kv<"w102", 102>,
    kv<"w103", 103>,
    kv<"w104", 104>,
    kv<"w105", 105>,
    kv<"w106", 106>,
    kv<"w107", 107>,
    kv<"w108", 108>,
    kv<"w109", 109>,
    kv<"w110", 110>,
    kv<"w111", 111>,
    kv<"w112", 112>,
    kv<"w113", 113>,
    kv<"w114", 114>,
    kv<"w115", 115>,
    kv<"w116", 116>,
    kv<"w117", 117>,
    kv<"w118", 118>,
    kv<"w119", 119>,
    kv<"w120", 120>,
    kv<"w121", 121>,
    kv<"w122", 122>,
    kv<"w123", 123>,
    kv<"w124", 124>,
    kv<"w125", 125>,
    kv<"w126", 126>,
    kv<"w127", 127>,
    kv<"w128", 128>,
    kv<"w129", 129>,
    kv<"w130", 130>,
    kv<"w131", 131>,
    kv<"w132", 132>,
    kv<"w133", 133>,
    kv<"w134", 134>,
    kv<"w135", 135>,
    kv<"w136", 136>,
    kv<"w137", 137>,
    kv<"w138", 138>,
    kv<"w139", 139>,
    kv<"w140", 140>,
    kv<"w141", 141>,
    kv<"w142", 142>,
    kv<"w143", 143>,
    kv<"w144", 144>,
    kv<"w145", 145>,
    kv<"w146", 146>,
    kv<"w147", 147>,
    kv<"w148", 148>,
    kv<"w149", 149>,
    kv<"w150", 150>,
    kv<"w151", 151>,
    kv<"w152", 152>,
    kv<"w153", 153>,
    kv<"w154", 154>,
    kv<"w155", 155>,
    kv<"w156", 156>,
    kv<"w157", 157>,
    kv<"w158", 158>,
    kv<"w159", 159>,
    kv<"w160", 160>,
    kv<"w161", 161>,
    kv<"w162", 162>,
    kv<"w163", 163>,
    kv<"w164", 164>,
    kv<"w165", 165>,
    kv<"w166", 166>,
    kv<"w167", 167>,
    kv<"w168", 168>,
    kv<"w169", 169>,
    kv<"w170", 170>,
    kv<"w171", 171>,
    kv<"w172", 172>,
    kv<"w173", 173>,
    kv<"w174", 174>,
    kv<"w175", 175>,
    kv<"w176", 176>,
    kv<"w177", 177>,
    kv<"w178", 178>,
    kv<"w179", 179>,
    kv<"w180", 180>,
    kv<"w181", 181>,
    kv<"w182", 182>,
    kv<"w183", 183>,
    kv<"w184", 184>,
    kv<"w185", 185>,
    kv<"w186", 186>,
    kv<"w187", 187>,
    kv<"w188", 188>,
    kv<"w189", 189>,
    kv<"w190", 190>,
    kv<"w191", 191>,
    kv<"w192", 192>,
    kv<"w193", 193>,
    kv<"w194", 194>,
    kv<"w195", 195>,
    kv<"w196", 196>,
    kv<"w197", 197>,
    kv<"w198", 198>,
    kv<"w199", 199>,
    kv<"w200", 200>,
    kv<"w201", 201>,
    kv<"w202", 202>,
    kv<"w203", 203>,
    kv<"w204", 204>,
    kv<"w205", 205>,
    kv<"w206", 206>,
    kv<"w207", 207>,
    kv<"w208", 208>,
    kv<"w209", 209>,
    kv<"w210", 210>,
    kv<"w211", 211>,
    kv<"w212", 212>,
    kv<"w213", 213>,
    kv<"w214", 214>,
    kv<"w215", 215>,
    kv<"w216", 216>,
    kv<"w217", 217>,
    kv<"w218", 218>,
    kv<"w219", 219>,
    kv<"w220", 220>,
    kv<"w221", 221>,
    kv<"w222", 222>,
    kv<"w223", 223>,
    kv<"w224", 224>,
    kv<"w225", 225>,
    kv<"w226", 226>,
    kv<"w227", 227>,
    kv<"w228", 228>,
    kv<"w229", 229>,
    kv<"w230", 230>,
    kv<"w231", 231>,
    kv<"w232", 232>,
    kv<"w233", 233>,
    kv<"w234", 234>,
    kv<"w235", 235>,
    kv<"w236", 236>,
    kv<"w237", 237>,
    kv<"w238", 238>,
    kv<"w239", 239>,
    kv<"w240", 240>,
    kv<"w241", 241>,
    kv<"w242", 242>,
    kv<"w243", 243>,
    kv<"w244", 244>,
    kv<"w245", 245>,
    kv<"w246", 246>,
    kv<"w247", 247>,
    kv<"w248", 248>,
    kv<"w249", 249>,
    kv<"w250", 250>,
    kv<"w251", 251>,
    kv<"w252", 252>,
    kv<"w253", 253>,
    kv<"w254", 254>,
    kv<"w255", 255>,
    kv<"w256", 256>,
    kv<"w257", 257>,
    kv<"w258", 258>,
    kv<"w259", 259>,
    kv<"w260", 260>,
    kv<"w261", 261>,
    kv<"w262", 262>,
    kv<"w263", 263>,
    kv<"w264", 264>,
    kv<"w265", 265>,
    kv<"w266", 266>,
    kv<"w267", 267>,
    kv<"w268", 268>,
    kv<"w269", 269>,
    kv<"w270", 270>,
    kv<"w271", 271>,
    kv<"w272", 272>,
    kv<"w273", 273>,
    kv<"w274", 274>,
    kv<"w275", 275>,
    kv<"w276", 276>,
    kv<"w277", 277>,
    kv<"w278", 278>,
    kv<"w279", 279>,
    kv<"w280", 280>,
    kv<"w281", 281>,
    kv<"w282", 282>,
    kv<"w283", 283>,
    kv<"w284", 284>,
    kv<"w285", 285>,
    kv<"w286", 286>,
    kv<"w287", 287>,
    kv<"w288", 288>,
    kv<"w289", 289>,
    kv<"w290", 290>,
    kv<"w291", 291>,
    kv<"w292", 292>,
    kv<"w293", 293>,
    kv<"w294", 294>,
    kv<"w295", 295>,
    kv<"w296", 296>,
    kv<"w297", 297>,
    kv<"w298", 298>,
    kv<"w299", 299>>();
static constexpr auto big_set = make_perfect_set<
    "s0",
    "s1",
    "s2",
    "s3",
    "s4",
    "s5",
    "s6",
    "s7",
    "s8",
    "s9",
    "s10",
    "s11",
    "s12",
    "s13",
    "s14",
    "s15",
    "s16",
    "s17",
    "s18",
    "s19",
    "s20",
    "s21",
    "s22",
    "s23",
    "s24",
    "s25",
    "s26",
    "s27",
    "s28",
    "s29",
    "s30",
    "s31",
    "s32",
    "s33",
    "s34",
    "s35",
    "s36",
    "s37",
    "s38",
    "s39",
    "s40",
    "s41",
    "s42",
    "s43",
    "s44",
    "s45",
    "s46",
    "s47",
    "s48",
    "s49",
    "s50",
    "s51",
    "s52",
    "s53",
    "s54",
    "s55",
    "s56",
    "s57",
    "s58",
    "s59",
    "s60",
    "s61",
    "s62",
    "s63",
    "s64",
    "s65",
    "s66",
    "s67",
    "s68",
    "s69",
    "s70",
    "s71",
    "s72",
    "s73",
    "s74",
    "s75",
    "s76",
    "s77",
    "s78",
    "s79",
    "s80",
    "s81",
    "s82",
    "s83",
    "s84",
    "s85",
    "s86",
    "s87",
    "s88",
    "s89",
    "s90",
    "s91",
    "s92",
    "s93",
    "s94",
    "s95",
    "s96",
    "s97",
    "s98",
    "s99",
    "s100",
    "s101",
    "s102",
    "s103",
    "s104",
    "s105",
    "s106",
    "s107",
    "s108",
    "s109",
    "s110",
    "s111",
    "s112",
    "s113",
    "s114",
    "s115",
    "s116",
    "s117",
    "s118",
    "s119",
    "s120",
    "s121",
    "s122",
    "s123",
    "s124",
    "s125",
    "s126",
    "s127",
    "s128",
    "s129",
    "s130",
    "s131",
    "s132",
    "s133",
    "s134",
    "s135",
    "s136",
    "s137",
    "s138",
    "s139",
    "s140",
    "s141",
    "s142",
    "s143",
    "s144",
    "s145",
    "s146",
    "s147",
    "s148",
    "s149",
    "s150",
    "s151",
    "s152",
    "s153",
    "s154",
    "s155",
    "s156",
    "s157",
    "s158",
    "s159",
    "s160",
    "s161",
    "s162",
    "s163",
    "s164",
    "s165",
    "s166",
    "s167",
    "s168",
    "s169",
    "s170",
    "s171",
    "s172",
    "s173",
    "s174",
    "s175",
    "s176",
    "s177",
    "s178",
    "s179",
    "s180",
    "s181",
    "s182",
    "s183",
    "s184",
    "s185",
    "s186",
    "s187",
    "s188",
    "s189",
    "s190",
    "s191",
    "s192",
    "s193",
    "s194",
    "s195",
    "s196",
    "s197",
    "s198",
    "s199",
    "s200",
    "s201",
    "s202",
    "s203",
    "s204",
    "s205",
    "s206",
    "s207",
    "s208",
    "s209",
    "s210",
    "s211",
    "s212",
    "s213",
    "s214",
    "s215",
    "s216",
    "s217",
    "s218",
    "s219",
    "s220",
    "s221",
    "s222",
    "s223",
    "s224",
    "s225",
    "s226",
    "s227",
    "s228",
    "s229",
    "s230",
    "s231",
    "s232",
    "s233",
    "s234",
    "s235",
    "s236",
    "s237",
    "s238",
    "s239",
    "s240",
    "s241",
    "s242",
    "s243",
    "s244",
    "s245",
    "s246",
    "s247",
    "s248",
    "s249",
    "s250",
    "s251",
    "s252",
    "s253",
    "s254",
    "s255",
    "s256",
    "s257",
    "s258",
    "s259",
    "s260",
    "s261",
    "s262",
    "s263",
    "s264",
    "s265",
    "s266",
    "s267",
    "s268",
    "s269",
    "s270",
    "s271",
    "s272",
    "s273",
    "s274",
    "s275",
    "s276",
    "s277",
    "s278",
    "s279",
    "s280",
    "s281",
    "s282",
    "s283",
    "s284",
    "s285",
    "s286",
    "s287",
    "s288",
    "s289",
    "s290",
    "s291",
    "s292",
    "s293",
    "s294",
    "s295",
    "s296",
    "s297",
    "s298",
    "s299">();

TEST_CASE("make_perfect_map / make_perfect_set with N > 255 build a wide container") {
    static_assert(big_map.size() == 300);
    static_assert(big_set.size() == 300);
    static_assert(*big_map.lookup("w299") == 299);
    static_assert(big_set.contains("s0") && !big_set.contains("s300"));
    CHECK(big_map.algorithm_name().starts_with("wide-pilot"));
    for (int i = 0; i < 300; ++i) {
        CAPTURE(i);
        auto v = big_map.lookup("w" + std::to_string(i));
        REQUIRE(v.has_value());
        CHECK(*v == i);
        CHECK(big_set.contains("s" + std::to_string(i)));
    }
    CHECK_FALSE(big_map.lookup("w").has_value());
    CHECK_FALSE(big_set.contains("s"));
}
