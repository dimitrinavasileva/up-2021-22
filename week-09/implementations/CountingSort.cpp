#include <iostream>

constexpr int MAX = 32;
constexpr int MIN = -32;
constexpr int OFFSET = -MIN;

void countingSort(int* arr, int n)
{
    int cnt[MAX + OFFSET + 1];
    for (int i = 0; i <= MAX + OFFSET; i++)
	{
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
	{
        cnt[arr[i] + OFFSET]++;
    }

    int idx = 0;
    for (int i = 0; i <= MAX + OFFSET; i++)
	{
        while (cnt[i]--)
		{
            arr[idx++] = i - OFFSET;
        }
    }
}

void printArray(int* arr, int n)
{
    if (n > 0)
	{
		std::cout << arr[0] << " ";
	}
	
    for (int i = 1; i < n; i++)
	{
        std::cout << arr[i] << " ";
    }
	
    std::cout << '\n';
}

int main()
{
    int n = 7;
    int arr[] = {3, 12, 8, -2, 7, 19, -1};

    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}
