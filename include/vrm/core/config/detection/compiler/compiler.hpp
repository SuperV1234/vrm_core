// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <vrm/core/config/names.hpp>

VRM_CORE_NAMESPACE
{
    namespace detection
    {
        enum class compiler
        {
            clang,
            gcc,
            mscv,
            unknown
        };

        constexpr auto current_compiler() noexcept;
    }
}
VRM_CORE_NAMESPACE_END

#include <vrm/core/config/detection/compiler/compiler.inl>