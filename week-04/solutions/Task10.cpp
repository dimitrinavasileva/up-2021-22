#include <iostream>

int main()
{

    int number1, number2;

    std::cin >> number1 >> number2;

    // a > 0 - 0 .....
    // b > 0 - 0 .....

    // a > 0 - 0 .....
    // b < 0 - 1 .....

    // a < 0 - 1 .....
    // b < 0 - 1 .....

    // a < 0 - 1 .....
    // b > 0 - 0 .....

    // -1   = 1 111111111111111111111111111111111111111111111111111111111111111
    //       ^
    // 100  = 0 000000000000000000000000000000000000000000000000000000001100100
    //        -----------------------------------------------------------------
    //        1 111111111111111111111111111111111111111111111111111111110011011 = -101 < 0

    // -100 = 1 111111111111111111111111111111111111111111111111111111110011100
    //       ^  
    // -200 = 1 111111111111111111111111111111111111111111111111111111100111000
    //        -----------------------------------------------------------------   
    //        0 000000000000000000000000000000000000000000000000000000010100100 = 164 > 0

    if ((number1 ^ number2) < 0) 
    {
        std::cout << "TRUE";
    } 
    else 
    {
        std::cout << "FALSE";
    }

    return 0;
}