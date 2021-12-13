#include<iostream>

int* createArray(int size)
{
	//int a[size]; // ERROR
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i]; //*(arr + i)
	}

	return arr;
}

int main()
{
	int size;
	int* arr;

	std::cin >> size;

	arr = createArray(size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " "; //*(arr + i)
	}

	delete[] arr;

	return 0;
}