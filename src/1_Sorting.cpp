#include <iostream>

void swap(int &a, int &b);
void bubbleSort(int *arr, size_t size);
void insertionSort(int *arr, size_t size);
void selectionSort(int *arr, size_t size);

int main(int argc, char const *argv[])
{
    int arr[6] = {5, 9, 8, 3, 4, 7};
    // bubbleSort(arr, 6);
    // insertionSort(arr, 6);
    selectionSort(arr, 6);

    for (size_t i = 0; i < 6; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}

void swap(int &a, int &b)
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
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

void insertionSort(int *arr, size_t size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

void selectionSort(int *arr, size_t size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int indexSmallestElement = i;
        for (int j = i; j < size; ++j)
        {
            if (arr[j] < arr[indexSmallestElement])
                indexSmallestElement = j;
        }
        swap(arr[i], arr[indexSmallestElement]);
    }
}
