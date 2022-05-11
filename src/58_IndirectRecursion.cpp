#define INDIRECT_RECURSION 0
#if INDIRECT_RECURSION

#include <iostream>

static void funA(int n);
static void funB(int n);

int main(int argc, char *argv[])
{
    funA(atoi(argv[1]));
    std::cout << "\n";
    return 0;
}

static void funA(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        funB(n - 1);
    }
}

static void funB(int n)
{
    if (n > 1)
    {
        std::cout << n << " ";
        funA(n / 2);
    }
}

#endif
