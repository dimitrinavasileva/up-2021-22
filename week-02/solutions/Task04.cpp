#include<iostream>

int main()
{
    int length{};
    int width{};
    int perimeter{};
    int area{};

    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter width: ";
    std::cin >> width;

    perimeter = 2 * (length + width);
    area = length * width;

    std::cout << "Perimeter of rectangle is: " << perimeter << '\n';
    std::cout << "Area of rectangle is: " << area << '\n';

    return 0;
}