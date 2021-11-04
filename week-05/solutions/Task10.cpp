#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned res=0;
    do 
    {
        res = res * 10 + n%10;
        n/=10;
    } while ( n > 0);

    std::cout << res << '\n';

    return 0;
}
