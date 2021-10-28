#include <iostream>
#include <cstdint>

int main()
{
    int a, b, c, d, e, f;
    std::cin>>a>>b>>c>>d>>e>>f;
    std::uint32_t mask = 0;
    mask |= (UINT32_C(1) << a);
    mask |= (UINT32_C(1) << b);
    mask |= (UINT32_C(1) << c);
    mask |= (UINT32_C(1) << d);
    mask |= (UINT32_C(1) << e);
    mask |= (UINT32_C(1) << f);

    int q;
    
    {       // 1
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    {       // 2
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    {       // 3
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    {       // 4
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    {       // 5
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    {       // 6
        std::cin>>q;
        std::uint32_t maskq = 0;
        if(q < 32)
            maskq = (UINT32_C(1) << q);
        if((mask & maskq) > 0) 
            std::cout << "yes" << std::endl; // we use endl to flush, but it is not needed since cin would cause a flush
            // if q>= 32 then masq = 0, and so mask & 0 == 0
        else
            std::cout << "no" << std::endl;
            // if q>= 32 then masq = 0, and so mask & 0 == 0
    }

    return 0;
}
