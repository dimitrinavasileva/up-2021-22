#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    bool is4digit = ((1000 <= n) && (n <= 9999));

    unsigned c1, c2, c3, c4;
    c1 = n/1000;
    c2 = (n/100)%10;
    c3 = (n/10)%10;
    c4 = n%10;

    bool is137 = (c1 == 1 || c1 == 3 || c1 == 7) &&
                 (c2 == 1 || c2 == 3 || c2 == 7) &&
                 (c3 == 1 || c3 == 3 || c3 == 7) &&
                 (c4 == 1 || c4 == 3 || c4 == 7);


    bool is024 = (c1 == 0 || c1 == 2 || c1 == 4) &&
                 (c2 == 0 || c2 == 2 || c2 == 4) &&
                 (c3 == 0 || c3 == 2 || c3 == 4) &&
                 (c4 == 0 || c4 == 2 || c4 == 4);

    bool res = ( is4digit && (is137 || is024) );

    std::cout << static_cast<int>(res) << std::endl;
    

    return 0;
}
