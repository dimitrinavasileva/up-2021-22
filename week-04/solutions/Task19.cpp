#include <iostream>

int main()
{
    unsigned a;
    std::cin >> a;

    bool is_power2 = ((a & (a-1)) == 0) && (a != 0); // a is corner case
                                                     // (a-1) is safe because integer underflow is defined

    if(!is_power2)
        std::cout << a << " is NOT power of 2\n";
    else
    {
        unsigned res=0;
        // assumes unsigned is 4 bytes
        if(a & 0xFFFF0000U) res+=16;
        if(a & 0xFF00FF00U) res+=8;
        if(a & 0xF0F0F0F0U) res+=4;
        if(a & 0xCCCCCCCCU) res+=2;
        if(a & 0xAAAAAAAAU) res+=1;
        std::cout << a << " is power of 2\n";
        std::cout << a << " = 2^" << res << '\n';
    }

    return 0;
}
