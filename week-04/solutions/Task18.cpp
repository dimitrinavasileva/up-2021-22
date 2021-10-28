#include <iostream>

int main()
{
    unsigned a;
    std::cin >> a;
    unsigned bits_0 = a & 0x11111111U; // in binary is ...00010001
    unsigned bits_1 = a & 0x22222222U; // in binary is ...00100010
    unsigned bits_2 = a & 0x44444444U; // in binary is ...01000100
    unsigned bits_3 = a & 0x88888888U; // in binary is ...10001000
    unsigned res = (bits_0 << 3) | (bits_3 >> 3) | (bits_1 << 1) | (bits_2 >> 1);

    std::cout << res << '\n';


    return 0;
}
