#include <iostream>

unsigned gcd (unsigned a, unsigned b)
{
    unsigned c=1;  // non zero value needed
    while(c!=0)
    {
        c = a%b;
        a=b; b=c;
    }
    return a;
}

int main()
{
    unsigned n;
    std::cin>>n;

    unsigned a;
    std::cin>>a;

    unsigned res_gcd=a, res_lca=a;

    for(unsigned i=1; i<n; i++)
    {
        std::cin>>a;
        res_gcd = gcd(res_gcd, a);
        res_lca = a*res_lca/res_gcd;
    }

    std::cout << res_gcd << '\n'
              << res_lca << '\n';

    return 0;
}
