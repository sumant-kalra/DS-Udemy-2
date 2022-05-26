#define TAYLOR_SERIES 0
#if TAYLOR_SERIES

#include <iostream>

/*
https://www.emathhelp.net/en/calculators/calculus-1/taylor-and-maclaurin-series-calculator/
*/

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

// Trivial approach
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

// The above two functions are not optimized because of the calls to power() and fact() functions for each value of n, which can
// be avoided if the result of (x^n/n!) term from the previous iteration can be reused.
// For example, e(x,8)
// At an intermediate iteration, we will have n = 6,
// and for n = 6 we calculate x^6/6! by calling the functions power() and fact(), which calculate these values iterating
// over the lower values of n. In the next iteration for n = 7, we calculate x^7/7! by calling the functions power() and fact()
// calculate the values iterating again over the lower values of n. So, same calculations are repeated by using this approach.
//
// The function e(x,n) can be optimized if the value of the (x^n/n!) is calculated using the results from the previous iteration
// instead of calling power() and fact() for every iteration.
//

// Optimized versions of the functions
static double e_I(double x, int n)
{
    double result = 1.0;
    double num = 1.0;
    double denom = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        num = num * x;
        denom = denom * i;
        result = result + num / denom;
    }
    return result;
}

static double e_R(double x, int n)
{
    static double num = 1.0;
    static double denom = 1.0;
    if (n == 0)
        return 1;
    double temp = e_R(x, n - 1);
    num = num * x;
    denom = denom * n;
    return temp + num / denom;
}
static double sin(double x, int n)
{
    if (n <= 0)
    {
        std::cerr << "[Error] The value of x must lie between 1 and 50\n";
        exit(-1);
    }
    if (!(n % 2))
        --n;

    if (n == 1)
        return x;

    static double numr = -1 * x * x * x;
    static double denom = 3 * 2;

    double temp = sin(x, n - 2) + numr / denom;
    numr = numr * (-1 * x * x);
    denom = denom * (n + 1) * (n + 2);
    return temp;
}

static double cos(double x, int n)
{
    if (n < 0)
    {
        std::cerr << "[Error] The value of n must lie between 0 and 50\n";
        exit(-1);
    }
    if (n % 2)
        --n;

    if (n == 0)
        return 1;

    static double numr = -1 * x * x;
    static double denom = 2;

    double temp = cos(x, n - 2) + numr / denom;
    numr = numr * (-1 * x * x);
    denom = denom * (n + 1) * (n + 2);
    return temp;
}

static double sine(double x, int n)
{
    if (n <= 0)
    {
        std::cerr << "[ERROR]: Value of n must be greater than 1\n";
        exit(-1);
    }

    if (!(n % 2))
        --n;

    double result = 0.0;
    double numr = x;
    double denom = 1.0;
    for (int i = 1; i <= n; i += 2)
    {
        result += numr / denom;
        numr *= -1 * x * x;
        denom *= (i + 1) * (i + 2);
    }
    return result;
}

static double cosine(double x, int n)
{
    if (n < 0)
    {
        std::cerr << "[ERROR] The value of n must be greater than or equal to 0\n";
        exit(-1);
    }

    if (n % 2)
        --n;

    double result = 0.0;
    double numr = 1.0;
    double denom = 1.0;

    for (int i = 0; i <= n; i += 2)
    {
        result += numr / denom;
        numr *= -1 * x * x;
        denom *= (i + 1) * (i + 2);
    }
    return result;
}

// Perform the Complexity analysis of the e_i and e_r functions

// Taylor series with Honer's rule

// Revisit the problems solved in the recursion chapter

int main(int argc, char *argv[])
{
    std::cout << e_i(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << e_r(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << e_I(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << e_R(atof(argv[1]), atoi(argv[2])) << "\n";
    return 0;
}

#endif