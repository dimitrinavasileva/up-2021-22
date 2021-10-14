#include <iostream>

int main()
{
    int a;
	int b;
    int	x;
    int	y;
	
    std::cin >> a >> b >> x >> y;
	
    int br = (a/x) * (b/y);
    int leftover = a*b - br*x*y;

    std::cout << br << ' ' << leftover << '\n';

    return 0;
}
