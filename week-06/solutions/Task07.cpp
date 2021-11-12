#include <iostream>

bool check_property (unsigned long a)
{
    if(a > 999999UL || a < 100000UL)
        return false;   // not 6 digit
    unsigned n1, n2;
    n1 = a/1000;
    n2 = a%1000;
    if(n1 < 100 || n2 < 100) // check for n1 is not needed, we alread cheked a
        return false;

    unsigned sum = n1+n2;
    return a%sum == 0;
}

int main()
{
    unsigned long l, r;
    std::cin>>l>>r;

    unsigned long count = 0, sum = 0;

    for(unsigned long i=l; i<=r; i++)
    {
        if(check_property(i))
        {
            ++count;
            sum += i;
        }
    }

    std::cout << count << ' ' << sum << '\n';

    return 0;
}
