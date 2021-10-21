#include <iostream>

int main()
{
    unsigned a, b, c, d, e, f;
    std::cin>>a>>b>>c>>d>>e>>f;

    unsigned long long pr; // 8 bytes on amd64 (x86_64)
    pr = static_cast<unsigned long long>(a)*b*c*d*e*f;

    unsigned q;
    std::cin>>q;

    bool ans = ( (pr%q) == 0 );
    std::cout << static_cast<int>(ans) << std::endl;

    return 0;
}
