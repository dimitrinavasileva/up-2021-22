#include <iostream>

int main()
{
    unsigned a;
    std::cin >> a;
    unsigned bits_odd = a & 0xAAAAAAAAU;  // in binary is ...10101010
    unsigned bits_even = a & 0x55555555U; // in binary is ...01010101
    unsigned res = (bits_even << 1) | (bits_odd >> 1);

    std::cout << res << '\n';


    return 0;
}
