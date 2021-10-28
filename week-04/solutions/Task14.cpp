#include <iostream>
#include <cstdint> // for fixed size integers

int main()
{
    std::uint32_t a = 0; //uint_least32_t will be better
    int com, arg;

    {       // 1
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    {       // 2
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    {       // 3
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    {       // 4
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    {       // 5
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    {       // 6
        std::cin >> com >> arg;
        std::uint32_t mask = (UINT32_C(1) << arg);
        switch(com)
        {
            case 0:
                a = a | mask;
                break;
            case 1:
                a = a & (~mask);
                break;
            case 2:
                a = a ^ (mask);
                break;
        }
    }

    std::cout << a << '\n';

    return 0;
}
