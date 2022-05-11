#define TREE_RECURSION 0
#if TREE_RECURSION

#include <iostream>

static void fun(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        fun(n - 1);
        fun(n - 1);
    }
}

int main(int argc, char *argv[])
{
    fun(atoi(argv[1]));
    std::cout << "\n";

    return 0;
}

#endif