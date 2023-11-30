// mergesort.hpp

#ifndef CPPALG_MERGESORT_HPP
#define CPPALG_MERGESORT_HPP

#include "../common.hpp"

namespace cppalg
{
    template<typename T>
    void mergesort(T* array, std::size_t lenght);

    template<typename T, std::size_t S>
    void mergesort(std::array<T, S>* array);

    template<template <class> class C, typename T>
    void mergesort(C<T>* container);
} // namespace cppalg

#include "./mergesort.tcc"

#endif // CPPALG_MERGESORT_HPP
