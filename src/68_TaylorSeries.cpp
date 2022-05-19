#define TAYLOR_SERIES 1
#if TAYLOR_SERIES

#include <iostream>

static double power_2I(double p, int q)
{
    if (q < 0)
    {
        p = 1 / p;
        q = -1 * q;
    }

    double result = 1.0;

    while (q)
    {
        if (q % 2)
        {
            result = result * p;
        }
        p = p * p;
        q = q / 2;
    }
    return result;
}
static int fact_I(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

// Calculate the value of e^x using n degree polynomial from taylor's series

static double e_i(double x, int n)
{
    double result = 0.0;

    while (n > -1)
    {
        result += power_2I(x, n) / fact_I(n);
        n--;
    }

    return result;
}

static double e_r(double x, int n)
{
    if (n == 0)
        return 1;
    return e_r(x, n - 1) + power_2I(x, n) / fact_I(n);
}

// The additional function calls are unnecessary in this case as the term to be added with each iteration can be determined
// from the previous iteration easily instead of calculating it all from scratch like while calculating x^4, x^3 could be used which
// is calculated in the previous iteration.

// Write the functions again without using the functions

// Perform the Complexity analysis of the e_i and e_r functions

// Taylor series with Honer's rule

// Revisit the problems solved in the recursion chapter

int main(int argc, char *argv[])
{
    std::cout << e_i(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << e_r(atof(argv[1]), atoi(argv[2])) << "\n";
    return 0;
}

#endif