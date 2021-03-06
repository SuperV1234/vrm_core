// Copyright (c) 2015-2020 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <type_traits>
#include <vrm/core/assert.hpp>
#include <vrm/core/type_aliases/integral_constant.hpp>

namespace vrm::core::literals
{
    namespace impl
    {
        [[nodiscard]] VRM_CORE_ALWAYS_INLINE constexpr auto combine(
            long long x) noexcept
        {
            return x;
        }

        template <typename... Ts>
        [[nodiscard]] VRM_CORE_ALWAYS_INLINE constexpr auto combine(
            long long val, long long x, Ts... xs) noexcept
        {
            return combine(val * 10 + x, xs...);
        }

        [[nodiscard]] VRM_CORE_ALWAYS_INLINE constexpr auto parse(
            char c) noexcept
        {
            VRM_CORE_CONSTEXPR_ASSERT(c >= '0' && c <= '9');
            return c - '0';
        }
    } // namespace impl

    template <char... TCs>
    [[nodiscard]] VRM_CORE_ALWAYS_INLINE constexpr auto operator"" _c() noexcept
    {
        return llong_<impl::combine(0, impl::parse(TCs)...)>{};
    }
} // namespace vrm::core::literals
