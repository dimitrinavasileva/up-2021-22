#include <iostream>

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
	{
            if (arr[j] > arr[j + 1])
	    {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
	{
            break;
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}
