#include <iostream>

int main()
{
    unsigned a, b;
    std::cin>>a>>b;

    unsigned res = (a+b-1)/b;

    std::cout << res << '\n';
    
    return 0;
}
