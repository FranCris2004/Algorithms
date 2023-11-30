
#include "./mergesort.hpp"

// macros

#define __CPPALG_MACRO_MERGESORT_MERGE(ARRAY)\
std::size_t i = 0;\
std::size_t j = 0;\
std::size_t k = 0;\
\
while (i < l && j < r)\
{\
    if (left[i] <= right[j])\
        ARRAY[k] = left[i++];\
    else\
        ARRAY[k] = right[j++];\
    k++;\
}\
\
while (i < l)\
    ARRAY[k++] = left[i++];\
\
while (j < r)\
    ARRAY[k++] = right[j++];

#define __CPPALG_MACRO_MERGESORT(SIZE, ARRAY1, ARRAY2)\
std::size_t size = SIZE;\
if (size > 1)\
{\
    std::size_t l = size / 2;\
    std::size_t r = (size % 2 == 1 ? l + 1 : l);\
    \
    T* left  = (T*)std::calloc(l, sizeof(T));\
    T* right = (T*)std::calloc(r, sizeof(T));\
    \
    for (size_t i = 0; i < l; i++)\
        left[i] = ARRAY1[i];\
    \
    for (size_t i = 0; i < r; i++)\
        right[i] = ARRAY1[l + i];\
    \
    cppalg::mergesort(left, l);\
    cppalg::mergesort(right, r);\
    __cppalg_mergesort_merge(ARRAY2, left, l, right, r);\
    \
    std::free(left);\
    std::free(right);\
}

// functions

template<typename T>
void __cppalg_mergesort_merge(T* array, T* left, std::size_t l,  T* right, std::size_t r)
{
    __CPPALG_MACRO_MERGESORT_MERGE(array);
}

template<typename T, std::size_t S>
void __cppalg_mergesort_merge(std::array<T, S>* array, T* left, std::size_t l,  T* right, std::size_t r)
{
    __CPPALG_MACRO_MERGESORT_MERGE((*array));
}

template<template <class> class C, typename T>
void __cppalg_mergesort_merge(C<T>* container, T* left, std::size_t l,  T* right, std::size_t r)
{
    __CPPALG_MACRO_MERGESORT_MERGE((*container));
}

template<typename T>
void cppalg::mergesort(T* array, std::size_t lenght)
{
    __CPPALG_MACRO_MERGESORT(lenght, array, array);
}

template<typename T, std::size_t S>
void cppalg::mergesort(std::array<T, S>* array)
{
    __CPPALG_MACRO_MERGESORT(array->size(), (*array), array);
}

template<template <class> class C, typename T>
void cppalg::mergesort(C<T>* container)
{
    __CPPALG_MACRO_MERGESORT(container->size(), (*container), container);
}

#undef __CPPALG_MACRO_MERGESORT_MERGE
#undef __CPPALG_MACRO_MERGESORT
