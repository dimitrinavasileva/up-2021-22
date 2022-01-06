#include <iostream>
#include <cstddef>

bool rec (unsigned cur_val, unsigned arr_mul[], unsigned short arr_mul_size, unsigned target)
{
    if(cur_val == target)
        return true;
    if(cur_val > target)
        return false;

    for(std::size_t i=0; i<arr_mul_size; i++)
    {
        bool res = rec(cur_val*arr_mul[i], arr_mul+i, arr_mul_size-i, target);
        if(res)
            return true;
    }

    return false;
}

int main()
{
    std::size_t n;
    std::cin >> n;
    if(n>20)
        return -1;
    unsigned arr[20];
    unsigned target;
    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];
    std::cin >> target;

    //TODO: special case -> target == 1
    bool res;
    if(target != 1)
    {
        res = rec(1, arr, n, target);
    }
    else
    {
        res = false;
        for(std::size_t i=0; i<n; i++)
        {
            if(arr[i] == 1)
            {
                res = true;
                break;
            }
        }
    }
    std::cout << (res ? "True" : "False") << '\n';

    return 0;
}
