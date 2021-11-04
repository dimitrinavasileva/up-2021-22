#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned a;
    std::cin >> a;
    unsigned min_val=a, max_val=a;
    unsigned long long sum=a;
    
    for(unsigned i=1; i<n; ++i)
    {
        std::cin >> a;
        sum +=a;
        if(min_val > a) min_val = a;
        if(max_val < a) max_val = a;
    }

    sum -= min_val;
    sum -= max_val;

    unsigned long long res_whole_part = ((sum*100)/(n-2))/100;
    unsigned res_fraction_part = ((sum*100)/(n-2))%100;

    std::cout << res_whole_part ;
    if(res_fraction_part >= 10 && res_fraction_part % 10 != 0) // two digits needed for res_fractional_part
        std::cout << '.' << res_fraction_part; 
    else if(res_fraction_part >= 10 && res_fraction_part % 10 == 0) // one digit needed for res_fractional_part
        std::cout << '.' << res_fraction_part/10;       
    else if(res_fraction_part >= 1)                     // two digits needed for res_fractional_part but the first is zero
        std::cout << ".0" << res_fraction_part;
    // else res_fraction_part == 0 then do nothing
    
    std::cout << '\n';

    return 0;
}
