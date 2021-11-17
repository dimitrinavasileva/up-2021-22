#include <iostream>
#include <cstdint>

// uint_fastN_t might be better
std::uint32_t input_switch_lamp_mask ()
{
    unsigned p;
    std::cin >> p;
    // assert(k<20);
    
    std::uint32_t res = 0;

    for(unsigned i=0; i<p; i++) 
    {
        unsigned a;
        std::cin>>a;
        a--;
        // assert(a < 20);

        res = res | (UINT32_C(1) << a);
    }

    return res;
}

void input_switch_lamps_mask (std::size_t n, std::uint32_t masks[])
{
    for(std::size_t i=0; i<n; i++)
        masks[i] = input_switch_lamp_mask();
}

bool test_all_lamps (std::uint32_t switch_on_mask, std::size_t n, std::size_t k, const std::uint32_t lamp_masks[])
{
    std::uint32_t res = 0;
    for(std::size_t i=0; i<k; i++)
    {
        if(((UINT32_C(1) << i) & switch_on_mask) != 0)
            res ^= lamp_masks[i];
    }

    return res == ((UINT32_C(1) << n) - 1);
}

unsigned my_popcount (unsigned a)
{
    unsigned res=0;
    do
    {
        if(a%2 == 1)
            res++;
        a/=2;
    } while(a!=0);  

    return res;
}

void print_result (std::size_t k, std::uint32_t switches_mask)
{
    if(switches_mask == UINT32_MAX)
    {
        std::cout << "impossible\n";
    }
    else 
    {
        for(std::size_t i=0; i<k; i++)
        {
            if(((UINT32_C(1) << i) & switches_mask) != 0)
               std::cout << i+1 << ' ';  
        }
        std::cout << '\n';
    }
}

int main()
{
    std::size_t n, k;
    std::cin >> n >> k;
    std::uint32_t lamp_masks[32];

    input_switch_lamps_mask(k, lamp_masks);

    std::uint32_t res=UINT32_MAX;                   // invalid value
    std::uint32_t res_popcnt = my_popcount(res);

    for(std::size_t switches_mask=0; switches_mask<((UINT32_C(1) << k)-1); switches_mask++)
    {
        bool ok = test_all_lamps(switches_mask, n, k, lamp_masks);
        unsigned cur_popcnt = my_popcount(switches_mask);
        if(ok && res_popcnt > cur_popcnt)
        {
            res = switches_mask;
            res_popcnt = cur_popcnt;
        }
    }

    print_result(k, res);

    return 0;
}
