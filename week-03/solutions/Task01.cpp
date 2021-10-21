#include <iostream>

int main() 
{
	int n;

	std::cin >> n;

	std::cout << "Whole cycles: " << n / 12 << '\n';
	std::cout << "Hour: " << n % 12;

	return 0;
}