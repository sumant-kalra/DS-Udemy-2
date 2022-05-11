#define NESTED_RECURSION 1
#if NESTED_RECURSION

#include <iostream>

static int fun(int n)
{
    if (n > 100)
        return n - 10;

    return fun(fun(n + 11));
}

int main(int argc, char *argv[])
{
    std::cout << fun(atoi(argv[1])) << "\n";

    return 0;
}

#endif