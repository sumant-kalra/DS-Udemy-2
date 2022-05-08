#define TAIL_RECURSION 1
#if TAIL_RECURSION

#include <iostream>

void fun(int n);

int main(int argc, char *argv[])
{
    fun(atoi(argv[1]));
    return 0;
}

void fun(int n)
{
    if (n > 0)
    {
        std::cout << n << "\n";
        fun(n - 1);
    }
}

#endif