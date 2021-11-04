#include <iostream>

int main()
{
    unsigned n;
    std::cin>>n;
    if(n == 2 || n == 3)
        std::cout << "prime" << std::endl;
    else if(n<2 || n%2 == 0)
        std::cout << "not prime" << std::endl;
    else
    {
        bool is_prime = true;
        for(unsigned d=3; d*d <= n; d++)
        {
            if(n%d == 0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime)
            std::cout << "prime" << std::endl;
        else
            std::cout << "not prime" << std::endl;
    }


    return 0;
}
