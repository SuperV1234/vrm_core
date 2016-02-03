#include "../../utils/test_utils.hpp"
#include <vrm/core/type_traits/copy_if_rvalue.hpp>
#include <vrm/core/assert.hpp>

using namespace vrm::core;

SA_TYPE((copy_if_rvalue(1)), (int));
SA_TYPE((copy_if_rvalue(1.f)), (float));
SA_TYPE((copy_if_rvalue(1.0)), (double));

void x()
{
    int lv = 1;
    const int clv = 1;
    volatile int vlv = 1;
    const volatile int cvlv = 1;

    SA_TYPE((copy_if_rvalue(1)), (int));
    SA_TYPE((copy_if_rvalue(lv)), (int&));
    SA_TYPE((copy_if_rvalue(clv)), (const int&));
    SA_TYPE((copy_if_rvalue(vlv)), (volatile int&));
    SA_TYPE((copy_if_rvalue(cvlv)), (volatile const int&));
}

template <typename T>
decltype(auto) id(T&& x)
{
    return FWD(x);
}

void y()
{
    int v = 1;
    const int cv = 1;
    volatile int vv = 1;
    const volatile int cvv = 1;

    SA_TYPE((std::move(v)), (int&&));
    SA_SAME((decltype(v)), (int));
    SA_TYPE((id(std::move(v))), (int&&));
    SA_SAME((std::remove_reference_t<decltype(FWD(v))>), (int));
    SA_TYPE((copy_if_rvalue(std::move(v))), (int));

    SA_TYPE((std::move(cv)), (const int&&));
    SA_SAME((decltype(cv)), (const int));
    SA_TYPE((id(std::move(cv))), (const int&&));
    SA_SAME((std::remove_reference_t<decltype(FWD(cv))>), (const int));

    SA_SAME((decltype(id(std::move(cv)))), (const int&&));
    SA_SAME(
        (std::remove_reference_t < decltype(id(std::move(cv)))) >, (const int));

    // TODO:
    // SA_TYPE((copy_if_rvalue(std::move(cv))), (const int));


    SA_TYPE((std::move(vv)), (volatile int&&));
    SA_SAME((decltype(vv)), (volatile int));
    SA_TYPE((id(std::move(vv))), (volatile int&&));
    SA_SAME((std::remove_reference_t<decltype(FWD(vv))>), (volatile int));

    // TODO:
    // SA_TYPE((copy_if_rvalue(std::move(vv))), (volatile int));

    SA_TYPE((std::move(cvv)), (const volatile int&&));
    SA_SAME((decltype(cvv)), (const volatile int));
    SA_TYPE((id(std::move(cvv))), (const volatile int&&));
    SA_SAME(
        (std::remove_reference_t<decltype(FWD(cvv))>), (const volatile int));

    // TODO:
    // SA_TYPE((copy_if_rvalue(std::move(cvv))), (const volatile int));
}

TEST_MAIN()
{
    x();
    y();
    return 0;
}
