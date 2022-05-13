#define POWER_N 1
#if POWER_N

#include <iostream>

static double power_1R(double p, int q)
{
    if (q < 0)
    {
        p = 1 / p;
        q = -1 * q;
    }

    if (q == 0)
        return 1;

    return p * power_1R(p, q - 1);
}

static double power_1I(double p, int q)
{
    if (q < 0)
    {
        p = 1 / p;
        q = -1 * q;
    }

    double result = 1.0;

    while (q)
    {
        result = result * p;
        q--;
    }
    return result;
}

static double power_2R(double p, int q)
{
    if (q < 0)
    {
        p = 1 / p;
        q = -1 * q;
    }

    if (q == 0)
        return 1;

    if (q % 2)
        return p * power_2R(p, q - 1);
    else
    {
        double temp = power_2R(p, q / 2);
        return temp * temp;
    }
}

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

int main(int argc, char *argv[])
{
    std::cout << power_1R(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << power_1I(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << power_2R(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << power_2I(atof(argv[1]), atoi(argv[2])) << "\n";

    return 0;
}

#endif