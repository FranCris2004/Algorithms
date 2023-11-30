
#include "./max_min.hpp"

// macros

#define __CPPALG_MACRO_MAX_MIN(SIZE, ARRAY, OPERATOR)\
    const std::size_t size = SIZE;          \
    if (size == 1)                          \
        return ARRAY[0];                    \
    T aux = ARRAY[0];                       \
    for (std::size_t i = 1; i < size; i++)  \
    {                                       \
        T num = ARRAY[i];                   \
        if (num OPERATOR aux)               \
            aux = num;                      \
    }                                       \
return aux;

// max

template <typename T>
T cppalg::max(T a, T b)
{
    return (a > b) ? a : b;
}


template <typename T>
T cppalg::max(T* array, std::size_t lenght)
{
    __CPPALG_MACRO_MAX_MIN(lenght, array, >);
}

template <typename T, std::size_t S>
T cppalg::max(std::array<T, S>* array)
{
    __CPPALG_MACRO_MAX_MIN(array->size(), (*array), >);
}

template <template <class> class C, typename T>
T cppalg::max(C<T>* container)
{
    __CPPALG_MACRO_MAX_MIN(container->size(), (*container), >);
}

// min

template <typename T>
T cppalg::min(T a, T b)
{
    return (a < b) ? a : b;
}


template <typename T>
T cppalg::min(T* array, std::size_t lenght)
{
    __CPPALG_MACRO_MAX_MIN(lenght, array, <);
}

template <typename T, std::size_t S>
T cppalg::min(std::array<T, S>* array)
{
    __CPPALG_MACRO_MAX_MIN(array->size(), (*array), <);
}

template <template <class> class C, typename T>
T cppalg::min(C<T>* container)
{
    __CPPALG_MACRO_MAX_MIN(container->size(), (*container), <);
}

#undef __CPPALG_MACRO_MAX_MIN
