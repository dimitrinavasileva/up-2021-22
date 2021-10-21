#include <iostream>

int main() 
{
	int number;
	int hundreds;
    int	tens;
	int ones;

	std::cin >> number;

	hundreds = number / 100;
	tens = (number / 10) % 10;
	ones = number % 10;

	std::cout << ones + tens + hundreds;

	return 0;
}