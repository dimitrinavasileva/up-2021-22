#include <iostream>

constexpr unsigned seconds_in_day = 24*60*60;

// uint8_t time[6] / unsigned char time[6] might be better, less unsused space
//
// unsigned time[] <=> unsigned time[6] <=> unsigned *time 
// they are all the same
void input_clock_time (unsigned time[6])
{
    char x;
    for(unsigned i=0; i<6; i++)
    {
        std::cin>>x;
        if('0' <= x && x <= '9')
            time[i] = x - '0';
        else // x == '*'
            time[i] = 11; // we mark the star as 11
    }
}

unsigned long time_to_sec (unsigned h, unsigned m, unsigned s)
{
    return ((unsigned long)h*60 + m)*60 + s;
}

// cannot implement sec_to_time at the moment :(

bool test_matching_clock (unsigned long time_in_sec, const unsigned clock_time[6])
{
    unsigned h, m, s;
    s = time_in_sec;
    m = s/60;
    s = s%60;
    h = m / 60;
    m = m % 60;
    unsigned digits_in_clock[] = 
    {
        h/10, h%10,
        m/10, m%10,
        s/10, s%10
    };
    
    for(unsigned i=0; i<6; i++)
    {
        if(clock_time[i] != 11 && clock_time[i] != digits_in_clock[i])
        {
            return false;
        }
    }

    return true;
}

void print_time (unsigned tb)
{
    unsigned h, m, s;
    s = tb;
    m = s/60;
    s = s%60;
    h = m/60;
    m = m%60;

    std::cout << (h>10 ? "" : "0") << h << ':';
    std::cout << (m>10 ? "" : "0") << m << ':';
    std::cout << (s>10 ? "" : "0") << s;
}

int main ()
{
    unsigned clock_time_begin[6], clock_time_end[6];
    unsigned th, tm, tt;
    input_clock_time(clock_time_begin);
    input_clock_time(clock_time_end);
    std::cin >> th >> tm >> tt;
    tt = time_to_sec(th, tm, tt);
    // tm = 0; th = 0;
    
    for(unsigned tb=0; tb<seconds_in_day; tb++)
    {
        unsigned te = (tb + tt) % seconds_in_day;
        if(test_matching_clock(tb, clock_time_begin) && test_matching_clock(te, clock_time_end))
        {
            print_time(tb);
            std::cout << ' ';
            print_time(te);
            std::cout << '\n';
        }
    }

    return 0;
}
