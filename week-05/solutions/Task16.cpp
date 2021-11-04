#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin>>a>>b>>c>>d;
    
    for(int x=0; x*a<=d; x++)
    {
        for(int y=0; a*x+b*y<=d; y++)
        {
            int tmp = d - a*x - b*y;
            if(tmp >= 0 && tmp%c == 0)
            {
                int z = tmp/c;
                std::cout << x << ' ' << y << ' ' << z << '\n';
            }
        }
    }

    return 0;
}
