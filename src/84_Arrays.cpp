/**
 * @file 84_Arrays.cpp
 * @author SumanT Kalra (sumantkalra@outlook.com)
 * @brief Increase the size of an existing Array
 * @version 0.1
 * @date 2022-06-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#define ARRAYS_MAIN 1
#if ARRAYS_MAIN

#include <iostream>

int main(int argc, char const *argv[])
{
    // The existing Array
    unsigned int size = 10;
    int *array0 = new int[size];
    for (int i = 0; i < size; ++i)
        array0[i] = i;

    // New Array with Updated size
    unsigned int updatedSize = 20;
    int *array1 = new int[updatedSize];
    memcpy(array1, array0, size * sizeof(int));

    // Clearing the resources from the existing array
    delete[] array0;

    // Point the old pointer to the new array
    // Assign the new array pointer as nullptr
    array0 = array1;
    array1 = nullptr;

    // Test: Array is enlarged
    for (unsigned int i = 0; i < updatedSize; ++i)
        std::cout << array0[i] << " ";
    std::cout << "\n";

    delete[] array0;
    return 0;
}

#endif
