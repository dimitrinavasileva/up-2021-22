#include <iostream>

unsigned calculate_move_time (unsigned cur_pos, unsigned next_pos, unsigned time_down, unsigned time_up)
{
    if(cur_pos <= next_pos)
        return (next_pos-cur_pos)*time_up;
    else // cur_pos > next_pos
        return (cur_pos-next_pos)*time_down;
}

int main()
{
    unsigned time_down, time_up;
    unsigned n;
    std::cin>>time_down>>time_up;
    std::cin>>n;

    unsigned res = 0;

    unsigned cur_pos;
    std::cin>>cur_pos;

    for(unsigned i=0; i<n; i++)
    {
        unsigned next_pos;
        std::cin>>next_pos;
        res += calculate_move_time(cur_pos, next_pos, time_down, time_up);
        cur_pos = next_pos;
    }

    std::cout << res << '\n';

    return 0;
}
