#define MAIN_COMBINATION 1
#if MAIN_COMBINATION

#include <iostream>

static int factorial(int n)
{
    if (n < 0)
    {
        std::cerr << "[ERROR] Invalid Input to the factorial function! The number must be non-negative\n";
        exit(-1);
    }

    int result = 1;

    for (int i = 1; i <= n; ++i)
        result *= i;

    return result;
}

static int nCr_i(int n, int r)
{
    int numr = factorial(n);
    int denom = factorial(r) * factorial(n - r);
    return numr / denom;
}

static int nCr_r(int n, int r)
{
    if (r == 0 || r == n)
        return 1;

    return nCr_r(n - 1, r - 1) + nCr_r(n - 1, r);
}

int main(int argc, char const *argv[])
{
    std::cout << nCr_i(atoi(argv[1]), atoi(argv[2])) << "\n";
    std::cout << nCr_r(atoi(argv[1]), atoi(argv[2])) << "\n";

    return 0;
}

#endif
