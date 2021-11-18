#include <cstdint>
#include <iostream>
#include <cstddef>

constexpr std::size_t MAX_N = 1024;

// Отговоът мисля, че е точно броят на числата, които не са си на място (arr[i] != i),
// но не мисля, че ще е много полезно това като решение

// unorder_count should be at least 1
std::size_t find_first_invalid_placed_value (const unsigned val_pos[], std::size_t val_pos_size)
{
    for(std::size_t i=1; i<val_pos_size; i++)
    {
        if(val_pos[i] != i)
            return i;
    }

    // assert fail
    // or
    // throw exception
    // or
    // return special value
    return SIZE_MAX;
}

int main()
{
    // val_pos[i] показва на коя позиция се намира числото i към сегашния момент
    // Съхраняваме го така, защото е по-удобно, иначе трябваше да обхождаме линейно масива
    unsigned val_pos[MAX_N+1];

    std::size_t n;
    std::cin>>n;

    // броят на числата, които не са си на място и трябва да бъдат разменени
    std::size_t unorder_count = 0;

    for(std::size_t i=0; i<n+1; i++)
    {
        unsigned x;
        std::cin>>x;
        val_pos[x] = i;
        if(x != i)
            ++unorder_count;
    }

    //std::cout << unorder_count + static_cast<unsigned>(val_pos[0] == 0) << std::endl;
    //return 0;
    // and call it a day

    unsigned res = 0;

    while(unorder_count>0)
    {
        if(val_pos[0] != 0)
        {
            std::size_t value_to_swap = val_pos[0];
            std::size_t new_pos_for_zero = val_pos[value_to_swap];

            // in the place of the 0 should be placed value_to_swap
            val_pos[value_to_swap] = val_pos[0]; // same as value_to_swap
            val_pos[0] = new_pos_for_zero;

            // or
            // std::swap(val_pos[0], val_pos[val_pos[0]]);

            --unorder_count;
            if(val_pos[0] == 0)
                --unorder_count;
        }
        else 
        {
            std::size_t value_to_swap = find_first_invalid_placed_value(val_pos, n);
            if(value_to_swap == SIZE_MAX)  // this should not happen
                break;  // or assert
            std::size_t new_zero_pos = val_pos[value_to_swap];
            val_pos[value_to_swap] = val_pos[0];
            val_pos[0] = new_zero_pos;

            ++unorder_count;

            // or
            // std::swap(val_pos[0], val_pos[value_to_swap]);
        }

        // one swap per iteration
        res++;
    }

    std::cout << res << std::endl;

    return 0;
}

