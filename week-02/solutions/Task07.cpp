#include <iostream>

int main()
{
    char letterUpperCase{};
    char letterLowerCase{};

    std::cout << "Enter upper case letter: ";
    std::cin >> letterUpperCase;

    letterLowerCase = letterUpperCase - ('A' - 'a');

    std::cout << "Lower case letter: " << letterLowerCase;

    return 0;
}