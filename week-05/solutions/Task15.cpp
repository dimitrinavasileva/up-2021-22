#include <iostream>

int main()
{
    unsigned a, b, d;
    std::cin>>a>>b>>d;
    unsigned res=0;

    for(;a<=b; ++a)
    {
        unsigned c=a;
        do
        {
            if(c%10 == d) ++res;
            c/=10;
        } while(c>0);
    }

    std::cout << res << '\n';

    return 0;
}
