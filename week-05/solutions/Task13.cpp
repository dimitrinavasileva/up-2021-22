#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned a;
    std::cin >> a;

    unsigned cur_len=1, cur_val=a;  // we have one a at the moment
    unsigned res_len=0, res_val{};  // we set value that would be updated at the first possible time
                                    // everything is better than len=0, right?
                                    // we get a warning without res_val{} initializer

    for(unsigned i=1; i<n; i++)
    {   
        std::cin>>a;
        if(cur_val == a)
            cur_len++;  // we have the same value as the previous time
        else
        {
            if(res_len < cur_len)  // if we have found something better
            {
                res_len = cur_len;
                res_val = cur_val;
            }
            cur_val = a; // update to the new current
            cur_len = 1;
        }
    }

    if(res_len < cur_len)       // we checked only at state change, so check now. If the last subsequence is our answer, we check it here
    {                           // check the example:
        res_len = cur_len;      // 5
        res_val = cur_val;      // 2 2 3 3 3
    }

    std::cout << static_cast<unsigned long long>(res_len)*res_val << '\n';

    return 0;
}
