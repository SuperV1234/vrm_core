// Copyright (c) 2015-2020 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <memory>
#include <vrm/core/config.hpp>
#include <vrm/core/type_aliases/numerical.hpp>
#include <vrm/core/type_traits/common.hpp>

namespace vrm::core
{
    template <typename T, typename TAllocator = ::std::allocator<T>>
    class resizable_buffer;

    template <typename T, typename TAllocator>
    void swap(resizable_buffer<T, TAllocator>& lhs,
        resizable_buffer<T, TAllocator>& rhs) // .
        noexcept(noexcept(lhs.swap(rhs)));

    template <typename T, typename TAllocator>
    class VRM_CORE_CLASS_API resizable_buffer
    {
    private:
        using this_type = resizable_buffer<T, TAllocator>;

    public:
        using size_type = sz_t;
        using value_type = T;
        using data_ptr_type = T*;
        using allocator_type = TAllocator;
        using allocator_traits = ::std::allocator_traits<allocator_type>;

    private:
        allocator_type _allocator;
        T* _data{nullptr};

    public:
        resizable_buffer(const TAllocator& allocator = TAllocator{});

        resizable_buffer(const resizable_buffer&) = delete;
        resizable_buffer& operator=(const resizable_buffer&) = delete;

        resizable_buffer(resizable_buffer&& rhs) noexcept;
        resizable_buffer& operator=(resizable_buffer&& rhs) noexcept;

        ~resizable_buffer() noexcept;

        void construct_at(size_type idx);
        void destroy_at(size_type idx);

        void destroy(size_type from, size_type to);
        void deallocate(size_type n);
        void destroy_and_deallocate(size_type n);

        /// @brief Grows the internal storage from `old_capacity` to
        /// `new_capacity`.
        /// @details The new capacity must be greater or equal than the old one.
        void grow(size_type old_capacity, size_type new_capacity);
        void construct(size_type from, size_type to);
        void grow_and_construct(size_type old_capacity, size_type new_capacity);

        void swap(resizable_buffer&) noexcept;

        auto copy(size_type n);

        auto data() noexcept;
        [[nodiscard]] auto data() const noexcept;

        auto& operator[](size_type idx) noexcept;
        const auto& operator[](size_type idx) const noexcept;

        /// @brief Returns `true` if the internal storage points to `nullptr'.
        /// @details Occurs if the buffer was not initialized or was moved.
        [[nodiscard]] auto null() const noexcept;
    };
} // namespace vrm::core
