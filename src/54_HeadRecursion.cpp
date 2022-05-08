#define HEAD_RECURSION 1
#if HEAD_RECURSION

#include <iostream>

static void fun_r(int n);
static void fun_i(int n);

int main(int argc, char *argv[])
{
    fun_r(atoi(argv[1]));
    fun_i(atoi(argv[1]));

    return 0;
}

void fun_r(int n)
{
    if (n > 0)
    {
        fun_r(n - 1);
        std::cout << n << "\n";
    }
}

void fun_i(int n)
{
    int i = 1;
    while (i <= n)
    {
        std::cout << i << "\n";
        ++i;
    }
}

#endif