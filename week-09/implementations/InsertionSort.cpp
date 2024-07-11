#include <iostream>

void insertionSort(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
	{
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
	
    std::cout << '\n';
}

int main()
{
    int n = 7;
    int arr[] = {3, 12, 8, -2, 7, 19, -1};

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

