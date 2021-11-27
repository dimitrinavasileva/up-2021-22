#include <iostream>

int main()
{
    std::size_t n;
    int matr[10][10];

    std::cin>>n;
    for(std::size_t i=0; i<n; i++)
    {
        for(std::size_t j=0; j<n; j++)
        {
            std::cin>>matr[i][j];
        }
    }

    for(int cj=(int)n-1; cj>=0; cj--)
    {
        std::size_t j=cj;
        std::size_t i=0;
        int sum=0;
        while(i<n && j<n)
        {
            sum += matr[i][j];
            i++;
            j++;
        }
        std::cout << sum << ' ';
    }

    for(std::size_t ci=1; ci<n; ci++)
    {
        std::size_t j=0;
        std::size_t i=ci;
        int sum=0;
        while(i<n && j<n)
        {
            sum += matr[i][j];
            i++;
            j++;
        }
        std::cout << sum << ' ';
    }

    std::cout << '\n';

    return 0;
}
