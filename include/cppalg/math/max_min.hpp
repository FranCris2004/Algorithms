// max_min.hpp

#ifndef CPPALG_MAX_MIN_HPP
#define CPPALG_MAX_MIN_HPP

#include "../common.hpp"

namespace cppalg
{
    // max

    template <typename T>
    T max(T a, T b);

    template <typename T>
    T max(T* array, std::size_t lenght);

    template <typename T, std::size_t S>
    T max(std::array<T, S>* array);

    template <template <class> class C, typename T>
    T max(C<T>* container);

    // min

    template <typename T>
    T min(T a, T b);

    template <typename T>
    T min(T* array, std::size_t lenght);

    template <typename T, std::size_t S>
    T min(std::array<T, S>* array);

    template <template <class> class C, typename T>
    T min(C<T>* container);
} // namespace cppalg

#include "./max_min.tcc"

#endif // CPPALG_MAX_MIN_HPP
