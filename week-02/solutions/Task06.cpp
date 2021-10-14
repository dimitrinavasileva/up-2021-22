#include <iostream>

int main() 
{
	
    std::cout << "Enter letter: ";
    char letter{};
    std::cin >> letter;

    std::cout << "ASCII code is: ";
    std::cout << static_cast<int>(letter);

    return 0;
}