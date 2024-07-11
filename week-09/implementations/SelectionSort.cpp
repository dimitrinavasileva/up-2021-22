#include <iostream>

void selectionSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
	{
            if (arr[j] < arr[minIdx])
	    {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
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

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}
