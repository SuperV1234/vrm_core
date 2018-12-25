// Copyright (c) 2015-2019 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <vrm/core/config.hpp>
#include <vrm/core/args_utils/args_slice_aliases/args_slice_aliases.hpp>
#include <vrm/core/type_aliases/numerical.hpp>
#include <vrm/core/type_traits/copy_if_rvalue.hpp>
#include <vrm/core/args_utils/nth_arg.hpp>
#include <vrm/core/args_utils/args_slice.hpp>

namespace vrm::core
{
    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto first_n_args(Ts && ... xs) noexcept
    {
        return args_slice<0, TN>(FWD(xs)...);
    }

    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto last_n_args(Ts && ... xs) noexcept
    {
        constexpr auto begin_idx(sizeof...(xs)-TN);
        return args_slice<begin_idx, begin_idx + TN>(FWD(xs)...);
    }

    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto all_args_from(Ts && ... xs) noexcept
    {
        return args_slice<TN, sizeof...(xs)>(FWD(xs)...);
    }

    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto all_args_after(Ts && ... xs) noexcept
    {
        return all_args_from<TN + 1>(FWD(xs)...);
    }

    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto all_args_until(Ts && ... xs) noexcept
    {
        return first_n_args<TN + 1>(FWD(xs)...);
    }

    template <sz_t TN, typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr auto all_args_before(Ts && ... xs) noexcept
    {
        return first_n_args<TN>(FWD(xs)...);
    }

    template <typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr decltype(auto) first_arg(
        Ts && ... xs) noexcept
    {
        return copy_if_rvalue(std::get<0>(first_n_args<1>(FWD(xs)...)));
    }

    template <typename... Ts>
    VRM_CORE_ALWAYS_INLINE constexpr decltype(auto) last_arg(
        Ts && ... xs) noexcept
    {
        return copy_if_rvalue(std::get<0>(last_n_args<1>(FWD(xs)...)));
    }
}
