#include <iostream>

int main() 
{
	constexpr double PI = 3.14159265359;
    double radius;
    double perimeter;

	std::cout << "Enter radius: ";
	std::cin >> radius;

	perimeter = 2 * PI * radius;

	std::cout << "Length: " << perimeter;

	return 0;
}