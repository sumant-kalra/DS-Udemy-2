#define SUM_N 0
#if SUM_N

#include <iostream>

static int sumN_rec(int n)
{
    if (n == 1)
        return 1;
    return n + sumN_rec(n - 1);
}

static int sumN_itr(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum = sum + i;
    return sum;
}

static int sumN(int n)
{
    return n * (n + 1) / 2;
}

int main(int argc, char *argv[])
{
    std::cout << sumN_rec(atoi(argv[1])) << "\n";
    std::cout << sumN_itr(atoi(argv[1])) << "\n";
    std::cout << sumN(atoi(argv[1])) << "\n";

    return 0;
}
#endif