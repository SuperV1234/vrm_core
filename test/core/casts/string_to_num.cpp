#include "../../utils/test_utils.hpp"
#include <utility>
#include <vrm/core/casts/string_to_num.hpp>
#include <vrm/core/type_aliases/numerical.hpp>

TEST_MAIN()
{
    using namespace vrm::core;
    using namespace std::literals;

    TEST_ASSERT(str_to_int("0") == 0);
    TEST_ASSERT(str_to_int("1") == 1);
    TEST_ASSERT(str_to_int("2") == 2);

    TEST_ASSERT(str_to_float("0.f") == 0.f);
    TEST_ASSERT(str_to_float("1.f") == 1.f);
    TEST_ASSERT(str_to_float("2.f") == 2.f);

    TEST_ASSERT(str_to_double("0.0") == 0.0);
    TEST_ASSERT(str_to_double("1.0") == 1.0);
    TEST_ASSERT(str_to_double("2.0") == 2.0);

    TEST_ASSERT(str_to_size_t("0") == sz_t(0));
    TEST_ASSERT(str_to_size_t("1") == sz_t(1));
    TEST_ASSERT(str_to_size_t("2") == sz_t(2));

    TEST_ASSERT(str_to_int("0"s) == 0);
    TEST_ASSERT(str_to_int("1"s) == 1);
    TEST_ASSERT(str_to_int("2"s) == 2);

    TEST_ASSERT(str_to_float("0.f"s) == 0.f);
    TEST_ASSERT(str_to_float("1.f"s) == 1.f);
    TEST_ASSERT(str_to_float("2.f"s) == 2.f);

    TEST_ASSERT(str_to_double("0.0"s) == 0.0);
    TEST_ASSERT(str_to_double("1.0"s) == 1.0);
    TEST_ASSERT(str_to_double("2.0"s) == 2.0);

    TEST_ASSERT(str_to_size_t("0"s) == sz_t(0));
    TEST_ASSERT(str_to_size_t("1"s) == sz_t(1));
    TEST_ASSERT(str_to_size_t("2"s) == sz_t(2));

    return 0;
}
