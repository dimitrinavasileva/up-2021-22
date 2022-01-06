#include <iostream>
#include <climits>

const int MAX_SIZE = 100;

int maxElement(int a, int b)
{
    return (a > b) ? a : b;
}

int maxElementOfArray(int *arr, int arr_size)
{
	if(arr_size == 0)
		return INT_MIN;
    if (arr_size == 1)
        return arr[0];
	
	int a = arr[0];
	int b = maxElementOfArray(arr + 1, arr_size - 1);

    return maxElement(a,b);
}

int main()
{
    int arr[MAX_SIZE];
	int size;
    
    std::cin >> size;

    for (int i = 0; i < size; i++)
	{
        std::cin >> arr[i];
    }

    std::cout << maxElementOfArray(arr, size);
}