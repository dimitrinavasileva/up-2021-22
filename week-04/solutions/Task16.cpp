#include <iostream>

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    a = a^b;
    b = a^b;
    a = a^b;

    std::cout << a << ' ' << b << '\n';

    return 0;
}
