#include "../../utils/test_utils.hpp"
#include <vrm/core/for_args.hpp>

int main()
{
    using namespace vrm::core;

    {
        int acc{0};
        for_args([&acc](auto x) { acc += x; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }

    {
        int acc{0};
        for_args([&acc](auto&& x) { acc += x; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }

    {
        int steps = 0;
        int ctrl = 0;

        auto a = [&steps, &ctrl] {
            ++steps;
            ctrl = 1;
            return 1;
        };
        auto b = [&steps, &ctrl] {
            ++steps;
            ctrl = 2;
            return 2;
        };
        auto c = [&steps, &ctrl] {
            ++steps;
            ctrl = 3;
            return 3;
        };
        auto d = [&steps, &ctrl] {
            ++steps;
            ctrl = 4;
            return 4;
        };
        auto e = [&steps, &ctrl] {
            ++steps;
            ctrl = 5;
            return 5;
        };

        int acc{0};
        for_args(
            [&](auto x) {
                auto val(x());
                acc += val;

                if(steps == 1) TEST_ASSERT_OP(ctrl, ==, 2);
                if(steps == 2) TEST_ASSERT_OP(ctrl, ==, 1);
                if(steps == 3) TEST_ASSERT_OP(ctrl, ==, 4);
                if(steps == 4) TEST_ASSERT_OP(ctrl, ==, 3);
                if(steps == 5) TEST_ASSERT_OP(ctrl, ==, 5);
            },
            b, a, d, c, e);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }

    {
        int acc{0};
        for_args<1>([&acc](auto x) { acc += x; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));

        acc = 0;
        for_args<1>([&acc](auto&& x) { acc += x; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }

    {
        int acc{0};
        for_args<2>([&acc](auto x, auto y) { acc += x + y; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));

        acc = 0;
        for_args<2>(
            [&acc](auto&& x, auto&& y) { acc += x + y; }, 0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }

    {
        int acc{0};
        for_args<3>([&acc](auto x, auto y, auto z) { acc += x + y + z; }, 0, 1,
            2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));

        acc = 0;
        for_args<3>([&acc](auto&& x, auto&& y, auto&& z) { acc += x + y + z; },
            0, 1, 2, 3, 4, 5);
        TEST_ASSERT_OP(acc, ==, (0 + 1 + 2 + 3 + 4 + 5));
    }
}
