
#ifndef CPPALG_INVERTIONS_HPP
#define CPPALG_INVERTIONS_HPP

#include "../common.hpp"

namespace cppalg
{
    template <typename T>
    std::size_t invertions(const T* const array, std::size_t lenght);

    template <typename T, std::size_t S>
    std::size_t invertions(const std::array<T, S>* const array);

    template <template <class> class C, typename T>
    std::size_t invertions(const C<T>* const container);

    template <typename T>
    std::size_t invertions(const T* const array, std::size_t lenght);

    template <typename T, std::size_t S>
    std::size_t invertions(std::array<T, S> array);

    template <template <class> class C, typename T>
    std::size_t invertions(C<T> container);
} // namespace cppalg

#include "./invertions.tcc"

#endif // CPPALG_INVERTIONS_HPP
