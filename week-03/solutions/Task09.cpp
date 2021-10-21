#include <iostream>

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    unsigned free_cells = (n-k);

    unsigned res = (free_cells+(k-1)-1)/(k-1);

    std::cout << res << '\n';
    
    return 0;
}
