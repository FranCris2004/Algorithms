
#include "./invertions.hpp"

// macros

#define __CPPALG_MACRO_INVERTIONS(ARRAY, SIZE)\
std::size_t size = SIZE;\
\
if (size <= 1)\
    return 0;\
\
std::size_t r = size / 2;\
std::size_t l = (size % 2 == 1 ? r + 1 : r);\
\
T* left  = (T*)std::calloc(l, sizeof(T));\
T* right = (T*)std::calloc(r, sizeof(T));\
\
for (size_t i = 0; i < l; i++)\
    left[i] = ARRAY[i];\
\
for (size_t i = 0; i < r; i++)\
    right[i] = ARRAY[l + i];\
\
std::size_t left_invertions  = cppalg::invertions(left, l);\
std::size_t right_invertions = cppalg::invertions(right, r);\
std::size_t split_invertions = __cppalg_split_invertions(left, l, right, r);\
\
std::free(left);\
std::free(right);\
\
return left_invertions + right_invertions + split_invertions;

// functions

template <typename T>
std::size_t __cppalg_split_invertions(T* left, std::size_t l, T* right, std::size_t r)
{
    std::size_t split_invertions_count = 0;
    
    for (size_t i = 0; i < l; i++)
        for (size_t j = 0; j < r; j++)
            if (left[i] > right[j])
                split_invertions_count++;
    
    return split_invertions_count;
}

template <typename T>
std::size_t cppalg::invertions(T* array, std::size_t lenght)
{
    __CPPALG_MACRO_INVERTIONS(array, lenght);
}

template <typename T, std::size_t S>
std::size_t cppalg::invertions(std::array<T, S>* array)
{
    __CPPALG_MACRO_INVERTIONS((*array), S);
}

template <template <class> class C, typename T>
std::size_t cppalg::invertions(C<T> container)
{
    __CPPALG_MACRO_INVERTIONS((*container), container->size());
}
