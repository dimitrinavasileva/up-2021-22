#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned d=0;
    do 
    {
        n/=10;
        d++;
    } while ( n > 0);

    std::cout << d << '\n';

    return 0;
}
