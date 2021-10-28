#include <iostream>

int main()
{
    int a, b, c;
    std::cin>>a>>b>>c;
    if(a==b && b==c)
    {
        std::cout << a << b << c << '\n';
    }
    else if(b == c)
    {
        std::cout << a << b << c << a << '\n';
    }
    else if(a == b)
    {
        std::cout << a << b << c << b << a << '\n';
    }
    else if(a == c)
    {
        std::cout << a << b << c << '\n'; // same as a==b && b==c
    }
    else
    {
        std::cout << a << b << c << b << a << '\n'; // same as a == b
    }

    return 0;
}
