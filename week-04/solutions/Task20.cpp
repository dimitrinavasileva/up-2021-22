#include <iostream>

int main()
{
    int n; // unsigned might also work, but -n would be ... interesting ... but it is defined behaviour in the standard
           // so, with unsigned should also work

    std::cin >> n;

    // at least with two's complement
    // -n = ~n + 1
    //
    // so n & (-n) =
    // n & ( ~n + 1)
   
    // corner case: if n == 0 then res = 0
    unsigned res;
    res = n & (-n);

    std::cout << res << std::endl;

    return 0;
}
