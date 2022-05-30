#define FIB_MAIN 1
#if FIB_MAIN

#include <iostream>

// nth term (indexed from 0)
static int fibonacci_i(int n)
{
    if (n < 0)
    {
        std::cerr << "[ERROR] n must be non-negative\n";
        exit(-1);
    }

    if (n <= 1)
        return n;

    int nLL = 0;
    int nL = 1;
    int result = nL + nLL;

    for (int i = 2; i <= n; ++i)
    {
        result = nL + nLL;
        nLL = nL;
        nL = result;
    }
    return result;
}

static int fibonacci_r(int n)
{
    if (n < 0)
    {
        std::cerr << "[ERROR] n must be non-negative.\n";
        exit(-1);
    }

    if (n <= 1)
        return n;

    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

static int fibonacci_r_Opt(int n)
{
    if (n < 0)
    {
        std::cerr << "[ERROR] n must be non-negative.\n";
        exit(-1);
    }

    static int cachedTerms[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    if (n <= 1)
        return n;

    if (cachedTerms[n - 1] == -1)
        cachedTerms[n - 1] = fibonacci_r_Opt(n - 1);
    if (cachedTerms[n - 2] == -1)
        cachedTerms[n - 2] = fibonacci_r_Opt(n - 2);
    return cachedTerms[n - 1] + cachedTerms[n - 2];
}

int main(int argc, char const *argv[])
{
    std::cout << fibonacci_i(atoi(argv[1])) << "\n";
    std::cout << fibonacci_r(atoi(argv[1])) << "\n";
    std::cout << fibonacci_r_Opt(atoi(argv[1])) << "\n";
    return 0;
}

#endif