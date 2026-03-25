#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("edge_cases") {

    TEST_CASE("prefix strings") {
        constexpr auto prefix_set = ConstexprCore::make_perfect_set<"a", "ab", "abc", "abcd">();
        static_assert(prefix_set.contains("a"));
        static_assert(prefix_set.contains("ab"));
        static_assert(prefix_set.contains("abc"));
        static_assert(prefix_set.contains("abcd"));
        static_assert(!prefix_set.contains("abcde"));
        static_assert(!prefix_set.contains(""));
        static_assert(!prefix_set.contains("b"));
        CHECK(prefix_set.contains("a"));
        CHECK(prefix_set.contains("ab"));
        CHECK(prefix_set.contains("abc"));
        CHECK(prefix_set.contains("abcd"));
        CHECK_FALSE(prefix_set.contains("abcde"));
        CHECK_FALSE(prefix_set.contains(""));
        CHECK_FALSE(prefix_set.contains("b"));
    }

    TEST_CASE("similar strings") {
        constexpr auto similar_set = ConstexprCore::make_perfect_set<
            "foo", "fop", "foq", "goo", "boo"
        >();
        static_assert(similar_set.contains("foo"));
        static_assert(similar_set.contains("fop"));
        static_assert(similar_set.contains("foq"));
        static_assert(similar_set.contains("goo"));
        static_assert(similar_set.contains("boo"));
        static_assert(!similar_set.contains("for"));
        static_assert(!similar_set.contains("zoo"));
        CHECK(similar_set.contains("foo"));
        CHECK(similar_set.contains("fop"));
        CHECK(similar_set.contains("foq"));
        CHECK(similar_set.contains("goo"));
        CHECK(similar_set.contains("boo"));
        CHECK_FALSE(similar_set.contains("for"));
        CHECK_FALSE(similar_set.contains("zoo"));
    }

    TEST_CASE("26 single-char strings") {
        constexpr auto letters = ConstexprCore::make_perfect_set<
            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
            "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
            "u", "v", "w", "x", "y", "z"
        >();
        static_assert(letters.size() == 26);
        static_assert(letters.contains("a"));
        static_assert(letters.contains("m"));
        static_assert(letters.contains("z"));
        static_assert(!letters.contains("A"));
        static_assert(!letters.contains("1"));
        static_assert(!letters.contains(""));
        CHECK(letters.size() == 26);
        CHECK(letters.contains("a"));
        CHECK(letters.contains("m"));
        CHECK(letters.contains("z"));
        CHECK_FALSE(letters.contains("A"));
        CHECK_FALSE(letters.contains("1"));
        CHECK_FALSE(letters.contains(""));
    }

    TEST_CASE("single-char strings small set") {
        constexpr auto xyz_set = ConstexprCore::make_perfect_set<"x", "y", "z">();
        static_assert(xyz_set.contains("x"));
        static_assert(xyz_set.contains("y"));
        static_assert(xyz_set.contains("z"));
        static_assert(!xyz_set.contains("w"));
        static_assert(xyz_set.index_of("x") == 0);
        static_assert(xyz_set.index_of("y") == 1);
        static_assert(xyz_set.index_of("z") == 2);
        CHECK(xyz_set.contains("x"));
        CHECK(xyz_set.contains("y"));
        CHECK(xyz_set.contains("z"));
        CHECK_FALSE(xyz_set.contains("w"));
    }

    TEST_CASE("two element set") {
        constexpr auto bool_set = ConstexprCore::make_perfect_set<"true", "false">();
        static_assert(bool_set.size() == 2);
        static_assert(bool_set.contains("true"));
        static_assert(bool_set.contains("false"));
        static_assert(!bool_set.contains("maybe"));
        static_assert(bool_set.index_of("true") == 0);
        static_assert(bool_set.index_of("false") == 1);
        CHECK(bool_set.size() == 2);
        CHECK(bool_set.contains("true"));
        CHECK(bool_set.contains("false"));
        CHECK_FALSE(bool_set.contains("maybe"));
    }

    // --- Tests that stress multi-position selection and backtracking ---

    TEST_CASE("all same length - position-only discrimination") {
        // 5 three-letter keys with all-distinct first chars.
        // Length can't help (all length 3), forces position selection.
        constexpr auto animals_set = ConstexprCore::make_perfect_set<
            "cat", "dog", "bat", "rat", "hat"
        >();
        static_assert(animals_set.size() == 5);
        static_assert(animals_set.contains("cat"));
        static_assert(animals_set.contains("dog"));
        static_assert(animals_set.contains("hat"));
        static_assert(!animals_set.contains("car"));
        static_assert(!animals_set.contains("mat"));
        CHECK(animals_set.size() == 5);
        CHECK(animals_set.contains("cat"));
        CHECK(animals_set.contains("dog"));
        CHECK(animals_set.contains("hat"));
        CHECK_FALSE(animals_set.contains("car"));
        CHECK_FALSE(animals_set.contains("mat"));
    }

    TEST_CASE("differ only at last char") {
        // All share prefix "ab", differ only in final character
        constexpr auto lastchar_set = ConstexprCore::make_perfect_set<
            "abp", "abq", "abr", "abs", "abt"
        >();
        static_assert(lastchar_set.size() == 5);
        static_assert(lastchar_set.contains("abp"));
        static_assert(lastchar_set.contains("abt"));
        static_assert(!lastchar_set.contains("abx"));
        static_assert(!lastchar_set.contains("ab"));
        CHECK(lastchar_set.contains("abp"));
        CHECK(lastchar_set.contains("abt"));
        CHECK_FALSE(lastchar_set.contains("abx"));
        CHECK_FALSE(lastchar_set.contains("ab"));
    }

    TEST_CASE("differ only at first char") {
        constexpr auto firstchar_set = ConstexprCore::make_perfect_set<
            "a_end", "b_end", "c_end", "d_end", "e_end"
        >();
        static_assert(firstchar_set.size() == 5);
        static_assert(firstchar_set.contains("a_end"));
        static_assert(firstchar_set.contains("e_end"));
        static_assert(!firstchar_set.contains("z_end"));
        CHECK(firstchar_set.contains("a_end"));
        CHECK(firstchar_set.contains("e_end"));
        CHECK_FALSE(firstchar_set.contains("z_end"));
    }

    TEST_CASE("interior position only differs") {
        // All 3 chars, same first and last, differ only at position 1
        constexpr auto interior_set = ConstexprCore::make_perfect_set<
            "xax", "xbx", "xcx", "xdx"
        >();
        static_assert(interior_set.size() == 4);
        static_assert(interior_set.contains("xax"));
        static_assert(interior_set.contains("xdx"));
        static_assert(!interior_set.contains("xzx"));
        static_assert(!interior_set.contains("xxx"));
        CHECK(interior_set.contains("xax"));
        CHECK(interior_set.contains("xdx"));
        CHECK_FALSE(interior_set.contains("xzx"));
    }

    TEST_CASE("needs two positions - strategy 3 catches") {
        // No single position distinguishes all pairs (pos0: {a,b}, pos1: {x,y}).
        // Strategy 3 {0, LAST_CHAR} works since LAST_CHAR == pos1 for 2-char keys.
        constexpr auto twopos_set = ConstexprCore::make_perfect_set<
            "ax", "ay", "bx", "by"
        >();
        static_assert(twopos_set.size() == 4);
        static_assert(twopos_set.contains("ax"));
        static_assert(twopos_set.contains("ay"));
        static_assert(twopos_set.contains("bx"));
        static_assert(twopos_set.contains("by"));
        static_assert(!twopos_set.contains("cx"));
        static_assert(!twopos_set.contains("az"));
        CHECK(twopos_set.contains("ax"));
        CHECK(twopos_set.contains("by"));
        CHECK_FALSE(twopos_set.contains("cx"));
    }

    TEST_CASE("forces backtracking search") {
        // Crafted so strategies 1-3 all fail and backtracking (strategy 4) is needed:
        //   - All same length → strategy 1 (empty) fails
        //   - pos0: {c,c,b,b}, pos1: {a,o,a,o}, pos2/LAST: {t,t,t,t}
        //   - No single position has all-distinct chars → strategy 2 fails
        //   - {0, LAST_CHAR}={0,2}: (cat,cot) share pos0='c' AND last='t' → strategy 3 fails
        //   - Backtracking finds {0, 1}: pos0 splits {c,b} groups, pos1 splits within
        constexpr auto backtrack_set = ConstexprCore::make_perfect_set<
            "cat", "cot", "bat", "bot"
        >();
        static_assert(backtrack_set.size() == 4);
        static_assert(backtrack_set.contains("cat"));
        static_assert(backtrack_set.contains("cot"));
        static_assert(backtrack_set.contains("bat"));
        static_assert(backtrack_set.contains("bot"));
        static_assert(!backtrack_set.contains("cut"));
        static_assert(!backtrack_set.contains("bit"));
        static_assert(!backtrack_set.contains("ca"));
        CHECK(backtrack_set.contains("cat"));
        CHECK(backtrack_set.contains("cot"));
        CHECK(backtrack_set.contains("bat"));
        CHECK(backtrack_set.contains("bot"));
        CHECK_FALSE(backtrack_set.contains("cut"));
        CHECK_FALSE(backtrack_set.contains("bit"));
    }

    TEST_CASE("backtracking with 5 keys") {
        // Same pattern: pos0={x,x,x,y,y}, LAST={p,p,p,q,q}
        // {0, LAST_CHAR} fails for pairs like (xap, xbp). Needs {0,1} or {1,LAST}.
        constexpr auto backtrack5_set = ConstexprCore::make_perfect_set<
            "xap", "xbp", "xcp", "yaq", "ybq"
        >();
        static_assert(backtrack5_set.size() == 5);
        static_assert(backtrack5_set.contains("xap"));
        static_assert(backtrack5_set.contains("ybq"));
        static_assert(!backtrack5_set.contains("xdp"));
        static_assert(!backtrack5_set.contains("yap"));
        CHECK(backtrack5_set.contains("xap"));
        CHECK(backtrack5_set.contains("ybq"));
        CHECK_FALSE(backtrack5_set.contains("xdp"));
    }

    TEST_CASE("mixed lengths with shared characters") {
        // Varying lengths ensure some pairs are separated by length alone,
        // while same-length pairs still need position coverage.
        constexpr auto mixedlen_set = ConstexprCore::make_perfect_set<
            "a", "ab", "ba", "abc", "bca"
        >();
        static_assert(mixedlen_set.size() == 5);
        static_assert(mixedlen_set.contains("a"));
        static_assert(mixedlen_set.contains("ab"));
        static_assert(mixedlen_set.contains("ba"));
        static_assert(mixedlen_set.contains("abc"));
        static_assert(mixedlen_set.contains("bca"));
        static_assert(!mixedlen_set.contains("b"));
        static_assert(!mixedlen_set.contains("cab"));
        CHECK(mixedlen_set.contains("a"));
        CHECK(mixedlen_set.contains("ab"));
        CHECK(mixedlen_set.contains("bca"));
        CHECK_FALSE(mixedlen_set.contains("b"));
        CHECK_FALSE(mixedlen_set.contains("cab"));
    }

    TEST_CASE("non-minimal table size (M > N)") {
        constexpr ConstexprCore::perfect_hash_set<3, 5, 5> non_min{
            std::array<std::string_view, 3>{"alpha", "beta", "gamma"}
        };
        static_assert(non_min.size() == 3);
        static_assert(non_min.table_size() == 5);
        static_assert(non_min.contains("alpha"));
        static_assert(non_min.contains("beta"));
        static_assert(non_min.contains("gamma"));
        static_assert(!non_min.contains("delta"));
        static_assert(!non_min.contains(""));
        // index_of rejects non-keys (empty sentinel slots)
        static_assert(!non_min.index_of("delta").has_value());
        CHECK(non_min.size() == 3);
        CHECK(non_min.table_size() == 5);
        CHECK(non_min.contains("alpha"));
        CHECK(non_min.contains("beta"));
        CHECK(non_min.contains("gamma"));
        CHECK_FALSE(non_min.contains("delta"));
    }

    TEST_CASE("table_size() accessor") {
        constexpr auto set3 = ConstexprCore::make_perfect_set<"one", "two", "three">();
        static_assert(set3.size() == 3);
        static_assert(set3.table_size() >= set3.size());

        constexpr auto map2 = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"a", 1>,
            ConstexprCore::kv<"b", 2>
        >();
        static_assert(map2.size() == 2);
        static_assert(map2.table_size() >= map2.size());
        CHECK(set3.table_size() >= set3.size());
        CHECK(map2.table_size() >= map2.size());
    }

    TEST_CASE("large key set - 15 C++ keywords") {
        constexpr auto keywords = ConstexprCore::make_perfect_set<
            "auto", "bool", "break", "case", "char",
            "class", "const", "do", "double", "else",
            "enum", "float", "for", "goto", "if"
        >();
        static_assert(keywords.size() == 15);
        static_assert(keywords.contains("auto"));
        static_assert(keywords.contains("if"));
        static_assert(keywords.contains("const"));
        static_assert(keywords.contains("for"));
        static_assert(!keywords.contains("string"));
        static_assert(!keywords.contains("vector"));
        static_assert(!keywords.contains(""));
        CHECK(keywords.size() == 15);
        CHECK(keywords.contains("auto"));
        CHECK(keywords.contains("if"));
        CHECK(keywords.contains("const"));
        CHECK_FALSE(keywords.contains("string"));
        CHECK_FALSE(keywords.contains("vector"));
    }

    TEST_CASE("long keys (>16 chars, exercising MAX_POSITIONS cap)") {
        constexpr auto long_keys = ConstexprCore::make_perfect_set<
            "authentication_service",
            "database_connection_pool",
            "distributed_lock_manager",
            "event_processing_pipeline",
            "message_serialization_layer"
        >();
        static_assert(long_keys.size() == 5);
        static_assert(long_keys.contains("authentication_service"));
        static_assert(long_keys.contains("database_connection_pool"));
        static_assert(long_keys.contains("distributed_lock_manager"));
        static_assert(long_keys.contains("event_processing_pipeline"));
        static_assert(long_keys.contains("message_serialization_layer"));
        static_assert(!long_keys.contains("authentication_services"));
        static_assert(!long_keys.contains("database_connection"));
        CHECK(long_keys.contains("authentication_service"));
        CHECK(long_keys.contains("message_serialization_layer"));
        CHECK_FALSE(long_keys.contains("authentication_services"));
        CHECK_FALSE(long_keys.contains("database_connection"));
    }

    TEST_CASE("empty string as key") {
        constexpr auto set = ConstexprCore::make_perfect_set<"", "a", "ab">();
        static_assert(set.contains(""));
        static_assert(set.contains("a"));
        static_assert(set.contains("ab"));
        static_assert(!set.contains("b"));
        CHECK(set.contains(""));
        CHECK(set.contains("a"));
        CHECK(set.contains("ab"));
        CHECK_FALSE(set.contains("b"));
    }

    TEST_CASE("map with same-length keys") {
        constexpr auto weekday_map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"mon", 1>,
            ConstexprCore::kv<"tue", 2>,
            ConstexprCore::kv<"wed", 3>,
            ConstexprCore::kv<"thu", 4>,
            ConstexprCore::kv<"fri", 5>
        >();
        static_assert(weekday_map.size() == 5);
        static_assert(weekday_map.lookup("mon") == 1);
        static_assert(weekday_map.lookup("fri") == 5);
        static_assert(!weekday_map.lookup("xyz").has_value());
        CHECK(weekday_map.lookup("mon") == 1);
        CHECK(weekday_map.lookup("fri") == 5);
        CHECK_FALSE(weekday_map.lookup("xyz").has_value());
    }

    // Issue #12: overlap encoding correctness for keys sharing first/last 2 bytes
    TEST_CASE("overlap encoding: middle bytes differ (len > 4)") {
        constexpr auto set = ConstexprCore::make_perfect_set<
            "abXcd", "abYcd", "abZcd">();
        static_assert(set.contains("abXcd"));
        static_assert(set.contains("abYcd"));
        static_assert(set.contains("abZcd"));
        static_assert(!set.contains("abWcd")); // same overlap, different middle
        static_assert(!set.contains("ab_cd")); // same overlap, different middle
        CHECK(set.contains("abXcd"));
        CHECK(set.contains("abYcd"));
        CHECK(set.contains("abZcd"));
        CHECK_FALSE(set.contains("abWcd"));
        CHECK_FALSE(set.contains("ab_cd"));
    }

    // Issue #13: H&D generator with larger key set (N > 15)
    TEST_CASE("H&D mode: 20 stock tickers") {
        constexpr auto set = ConstexprCore::make_perfect_set<
            "AAPL","AMD","AMZN","BA","C","COST","CVX","DIS","F","GE",
            "GOOG","GS","HD","IBM","JPM","MA","META","MSFT","NVDA","TSLA">();
        static_assert(set.size() == 20);
        static_assert(set.contains("AAPL"));
        static_assert(set.contains("TSLA"));
        static_assert(set.contains("C"));   // single-char key
        static_assert(set.contains("F"));   // single-char key
        static_assert(!set.contains("PLTR"));
        static_assert(!set.contains("UBER"));
        static_assert(!set.contains("G"));  // not in set
        CHECK(set.contains("AAPL"));
        CHECK(set.contains("TSLA"));
        CHECK(set.contains("C"));
        CHECK(set.contains("F"));
        CHECK_FALSE(set.contains("PLTR"));
        CHECK_FALSE(set.contains("UBER"));
        CHECK_FALSE(set.contains("G"));
    }

}
