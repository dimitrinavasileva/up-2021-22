#include <iostream>
#include <cstddef>

// Това е бързото решение, което дава  отговор с едно минаване през "масива" и използва малко комбинаторика
// Може и да бъде направено и с две или три вложени цикъла
//
// Решението се базира на това, че ако имаме отрязък с еднакви числа в интервала [a, a+n-1], 
// то броят на различните отязъци е равен на (n+1)*n/2

int main()
{
    std::size_t n;
    std::cin>>n;

    unsigned last_val;
    std::size_t last_val_count;
    std::cin>>last_val;
    last_val_count = 1;

    std::size_t res = 0;
    unsigned a;
    for(std::size_t i=1; i<n; i++)
    {
        std::cin >> a;
        if(a == last_val)
            ++last_val_count;
        else
        {
            res += (last_val_count+1)*last_val_count/2;
            last_val_count = 1;
            last_val = a;
        }
    }

    // do not forget the last sequence
    res += (last_val_count+1)*last_val_count/2;

    std::cout << res << '\n';

    return 0;
}
