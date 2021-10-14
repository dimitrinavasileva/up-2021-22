#include <iostream>
//#include <limits>

int main()
{
    int h1;
    int	m1;
    int h2;
	int m2;

    char c;
    std::cin >> h1 >> c >> m1;
    std::cin >> h2 >> c >> m2;

    // the commented version is better
    // std::cin >> h1; 
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    // std::cin >> m1;
    //
    // std::cin >> h2; 
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    // std::cin >> m2;
    
    m1 += h1*60; // h1 = 0;
    m2 += h2*60; // h2 = 0;

    int diff = m2 - m1;

    std::cout << diff/60 << ':' << diff%60 << '\n';

    return 0;
}
