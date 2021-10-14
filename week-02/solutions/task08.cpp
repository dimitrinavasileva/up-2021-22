#include <iostream>

int main()
{
    int a;
    std::cin >> a;
    
    int c1 = a%10; a/=10;
    int c2 = a%10; a/=10;
    int c3 = a%10; a/=10;
    int c4 = a%10; a/=10;
    int c5 = a%10; //a/=10;

    std::cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << ' ' << c5 << '\n';


    return 0;
}
