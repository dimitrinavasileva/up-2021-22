#include <iostream>

// премахва множителите p от записа на a като произведение и го връща
unsigned remove_mult (unsigned a, unsigned p)
{
    while(a%p == 0)
        a/=p;
    return a;
}

bool check_property (unsigned a)
{
    for(unsigned i=2; i<=20; i++)
    {
        a = remove_mult(a, i);
        if(a == 1) break;
    }
    return a == 1;
}

int main()
{
    unsigned n;
    std::cin>>n;

    unsigned i = 0;
    while(true)
    {   
        if(n>i+1)
        {
            if(check_property(n-i))
            {
                std::cout << n-i << '\n';
                break;
            }
        }

        if(check_property(n+i))
        {
            std::cout << n+i << '\n';
            break;
        }
        
        i++;
    }

    return 0;
}
