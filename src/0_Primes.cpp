#define PRIMES_MAIN 0
#if PRIMES_MAIN

/**
 * @file 0_Primes.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * Prime numbers: Exactly two factors: (a) 1 (b) The number itself
 * Composite numbers: More than 2 but finite number of factors
 *
 * 0: Neither prime nor composite
 * Infinite factors
 *
 * 1: Neither prime nor composite
 * Only one factor that is 1.
 *
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cmath>

static bool isPrime1(int n)
{
    if (n < 0)
    {
        std::cerr << "Enter a non-negative number\n";
        exit(-1);
    }

    if (n == 0 || n == 1)
    {
        std::cout << "Neither prime nor composite\n";
        return false;
    }

    for (int i = 2; i < n; ++i)
    {
        if (!(n % i))
            return false;
    }
    return true;
}

static bool isPrime2(int n)
{
    if (n < 0)
    {
        std::cerr << "Enter a non-negative number\n";
        exit(-1);
    }

    if (n == 0 or n == 1)
    {
        std::cout << "Neither Prime nor Composite\n";
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (!(n % i))
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::cout << (isPrime1(atoi(argv[1])) ? "Yes\n" : "No\n");
    std::cout << (isPrime2(atoi(argv[1])) ? "Yes\n" : "No\n");
    return 0;
}

#endif