#ifndef __VECTOR_HPP_
#define __VECTOR_HPP_

#include <cstddef>
#include <bits/allocator.h>
#include <bits/alloc_traits.h>
#include <bits/stl_iterator.h>

namespace yc {
    template<typename T, typename Allocator = std::allocator<T>>
    class vector {
        using value_type = T;
        using allocator_type = Allocator;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using iterator = __gnu_cxx::__normal_iterator<pointer, vector>;
        using const_iterator = __gnu_cxx::__normal_iterator<const_pointer, vector>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        constexpr vector() noexcept(noexcept(Allocator())) : vector(Allocator()){

        }

        constexpr explicit vector(const Allocator& alloc) noexcept :
        allocator(alloc),size(0),capacity(0),data(nullptr) {

        }

    private:
        Allocator allocator;
        size_type size;
        size_type capacity;
        pointer data;


    };
}

#endif