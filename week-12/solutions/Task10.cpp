#include <climits>
#include <iostream>
#include <cstddef>

unsigned count_digits (unsigned x)
{
    unsigned res=0;
    do
    {
        ++res;
        x /= 10;
    } while(x>0);
    return res;
}

unsigned pow_10 (unsigned p)
{
    unsigned res = 1;
    for(std::size_t i=0; i<p; i++)
    {
        res *= 10;
    }

    return res;
}

// we use max_num_pow10 so we can fastly remove the first digit of cur_num
unsigned rec(unsigned cur_num, unsigned max_num, unsigned max_num_pow10, unsigned short cur_used_digits_mask)
{
    if(max_num_pow10 == 0)
        return cur_num;
    unsigned res;
    short last_digit = (short)(max_num/max_num_pow10);
    {
        unsigned short last_digit_mask = (1U << (unsigned short)last_digit);
        if((cur_used_digits_mask & last_digit_mask) == 0U) // digit i is not used
        {
            res = rec(cur_num*10 + last_digit, max_num%max_num_pow10, max_num_pow10/10, cur_used_digits_mask | last_digit_mask);
            if(res != UINT_MAX)
                return res;
        }
    }
    for(short i=(short)(last_digit-1); i>=0; i--)
    {
        unsigned short i_digit_mask = (1U << (unsigned short)i);
        if((cur_used_digits_mask & i_digit_mask) != 0U) // digit i is already used
            continue;
        // (max_num_pow10-1) because if we have already decremented, we can use whatever digit we want
        res = rec(cur_num*10 + i, max_num_pow10-1, max_num_pow10/10, cur_used_digits_mask | i_digit_mask);
        if(res != UINT_MAX)
            return res;
    }

    return UINT_MAX; // Result not found
}

int main()
{
    unsigned n;
    std::cin >> n;
    unsigned n_pow10 = pow_10(count_digits(n)-1);
    
    unsigned res = rec(0, n, n_pow10, 0);

    std::cout << res << '\n';

    return 0;
}
