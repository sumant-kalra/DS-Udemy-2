#include <iostream>

void sort_swap(int &a, int &b);
void bubbleSort(int *arr, size_t size);

int main(int argc, char const *argv[])
{
    int arr[6] = {5, 9, 8, 3, 4, 7};
    bubbleSort(arr, 6);

    for (size_t i = 0; i < 6; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}

void sort_swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, size_t size)
{
    bool isSorted = true;
    for (size_t i = 0; i < size - 1; ++i)
    {
        isSorted = true;
        for (size_t j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                sort_swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}
