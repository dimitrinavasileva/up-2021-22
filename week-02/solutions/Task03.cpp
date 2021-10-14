#include<iostream>

int main()
{
	std::cout << "First number is: ";
	int firstNumber{};
	std::cin >> firstNumber;

	std::cout << "Second number is: ";
	int secondNumber{};
	std::cin >> secondNumber;

	int temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;

	std::cout << "After swap the first number is: " << firstNumber << " and the second number is: " << secondNumber << '\n';

	return 0;
}