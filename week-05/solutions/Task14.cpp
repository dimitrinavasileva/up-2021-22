#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned sum_time=0, no_days=1;

    char c;
    unsigned hb, mb, he, me;
    unsigned last_end=0; // zero would never add a day

    for(unsigned i=0; i<n; ++i)
    {
        std::cin>>hb>>c>>mb>>c>>he>>c>>me;
        mb+=hb*60;
        me+=he*60;
        sum_time += ((mb <= me) ? (me - mb) : (me + 24*60 - mb));
        if(mb > me) ++no_days;
        if(mb < last_end) ++no_days;
        last_end = me;
    }

    unsigned ah = (sum_time/no_days)/60;
    unsigned am = (sum_time/no_days)%60;

    std::cout << ( ah < 10 ? "0" : "") << ah << ':'
              << ( am < 10 ? "0" : "") << am << '\n';

    return 0;
}
