#include<iostream>

int* createArray(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	return arr;
}

void printSumMinMax(int* arr, int size)
{
	int sum = arr[0];
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < size; i++)
	{
		sum += arr[i];

		if (arr[i] > max)
		{
			max = arr[i];
		}


		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	std::cout << sum << " " << min << " " << max << '\n';
}

int main()
{
	int size;
	std::cin >> size;

	int* arr = createArray(size);

	printSumMinMax(arr, size);

	delete[] arr;
	
	return 0;
}