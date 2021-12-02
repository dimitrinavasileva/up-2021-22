#include <iostream>
#include <cstddef>
#include <algorithm>
#include <iomanip>

// ... actually ... it is bubble sort
void potato_sort (unsigned seller_potato_quantity[], double seller_price[], std::size_t seller_count)
{
    bool is_modified;
    do 
    {
        is_modified = false;
        for(std::size_t i=0; i<seller_count-1; i++)
        {
            if(seller_price[i] > seller_price[i+1])
            {
                is_modified = true;
                std::swap (seller_price[i], seller_price[i+1]);
                std::swap (seller_potato_quantity[i], seller_potato_quantity[i+1]);
            }
        }
    } while (is_modified);
}


// алчен алгоритъм - най-изгодно е да купим първо най-евтините картофи и чак тогава
// по-скъпите, ако няма достатъчно от евтините
int main()
{
    unsigned k;
    std::size_t n;

    std::cin>>k;
    std::cin>>n;

    if(n>1024)
        n = 1024;

    unsigned seller_potato_quantity[1024];
    double seller_price[1024];

    for(std::size_t i=0; i<n; i++)
    {
        std::cin >> seller_potato_quantity[i] >> seller_price[i];
    }

    potato_sort(seller_potato_quantity, seller_price, n);

    double res = 0.0;
    std::size_t i=0;

    while(k>0 && i<n)
    {
        unsigned cur_buy = seller_potato_quantity[i];

        if(cur_buy > k)
            cur_buy = k;

        res += seller_price[i] * cur_buy;
        k -= cur_buy;
        ++i;
    }

    if(k>0)
    {
        std::cout << "Not enought potatos\n";
    }
    else
    {
        std::cout << std::fixed << std::setprecision(2) << res << '\n';
    }

    return 0;
}
