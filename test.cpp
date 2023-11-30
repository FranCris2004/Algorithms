#include <iostream>
#include <ctime>

#include "include/cppalg/cppalg.hpp"

template<typename T, std::size_t S>
void printArray(std::array<T, S> array, const char* name)
{
    std::size_t aux = array.size() - 1;

    std::cout << name << " : [";
    for (size_t i = 0; i < aux; i++)
        std::cout << array[i] << ",";
    std::cout << array[aux] << "]\n";
}

void mergesort_test()
{
    std::cout << "MERGE SORT\n";

    constexpr std::size_t size = 7;
    std::array<int, size>* arr = new std::array<int, size>();

    for (size_t i = 0; i < size; i++)
        (*arr)[i] = (std::rand() % 10);

    printArray(*arr, "arr before");

    cppalg::mergesort(arr);
    
    printArray(*arr, "arr after");

    delete arr;
}

void max_min_test()
{
    std::cout << "MAX MIN\n";

    constexpr std::size_t size = 7;
    std::array<int, size>* arr = new std::array<int, size>();
    
    for (size_t i = 0; i < size; i++)
        (*arr)[i] = std::rand() % 10 + 1;

    printArray(*arr, "arr");

    std::cout << "arr max : " << cppalg::max(arr) << "\n";
    std::cout << "arr min : " << cppalg::min(arr) << "\n";

    delete arr;
}

void invertions_test()
{
    std::cout << "INVERTIONS\n";

    constexpr std::size_t size = 7;
    std::array<int, size>* arr = new std::array<int, size>();

    for (size_t i = 0; i < arr->size(); i++)
        (*arr)[i] = std::rand() % 10 + 1;

    printArray(*arr, "array");

    std::cout << "invertions : " << cppalg::invertions(arr) << "\n";
}

int main()
{
    std::srand(std::time(NULL));
    
    mergesort_test();
    std::cout << "\n";
    
    max_min_test();
    std::cout << "\n";

    invertions_test();
    std::cout << "\n";

    return 0;
}
