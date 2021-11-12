#include <iostream>

unsigned my_popcount (unsigned a)
{
    // not the fastest implementation by any means

    unsigned res = 0;
    while(a > 0)
    {
        res += (a&1);
        a >>= 1;
    }

    return res;
}

int main()
{
    unsigned l, r;
    std::cin >> l >> r;

    unsigned res=0;

    for(unsigned i=l; i<=r; i++)
        res += my_popcount(i);

    std::cout << res << '\n';

    return 0;
}
