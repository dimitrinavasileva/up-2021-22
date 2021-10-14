#include<iostream>

int main()
{
	constexpr int MAX_STUDENTS_IN_GROUP{ 30 };
	constexpr int MIN_STUDENTS_IN_GROUP{ 10 };
	constexpr int MINUTES_IN_HOUR{ 60 };

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	const int usersAge{ age }; // usersAge is a runtime constant because the value isn't known until the program is run

	/*
	constexpr int myAge { age }; // compile error: age is a runtime constant, not a compile-time constant
	*/

	return 0;
}