#include <iostream>

int main()
{
    unsigned a, b, c;
    std::cin>>a>>b>>c;

    unsigned t = (a+b+c)/3;

    unsigned res = 0;
    res += (c-t)*2U;
    b+=(c-t); // c=t;

    res += (b-t)*2U;
    // a+=(b-t); b=t;
    // a should now be equal to t

    std::cout << res << '\n';
    
    return 0;
}
