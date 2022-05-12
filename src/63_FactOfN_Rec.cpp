#define FACT_N 1
#if FACT_N

#include <iostream>

static int fact_R(int n)
{
    if (n == 0)
        return 1;
    return n * fact_R(n - 1);
}

static int fact_I(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main(int argc, char *argv[])
{
    std::cout << fact_R(atoi(argv[1])) << "\n";
    std::cout << fact_I(atoi(argv[1])) << "\n";

    return 0;
}

#endif