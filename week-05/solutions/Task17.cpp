#include <iostream>

int main()
{
    unsigned n;
    std::cin>>n; 

    for(unsigned i=0; i<n; i++)
    {
        for(unsigned j=0; j<n; j++)
        {
            if(i==j || i+j==n-1 || i == n/2 || j == n/2)
                std::cout << '*';
            else
                std::cout << '.';
        }
        std::cout << '\n';
    }

    return 0;
}
