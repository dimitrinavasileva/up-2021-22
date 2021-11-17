#include <iostream>

constexpr std::size_t ARR_CAPACITY = 1024;

long arr_sum (const int arr[], std::size_t pos, std::size_t len)
{
    long res=0;
    for(std::size_t i=pos; i<pos+len; i++)
        res += arr[i];

    return res;
}

int arr_min (const int arr[], std::size_t pos, std::size_t len)
{
    // assert(len >= 1);

    int res = arr[pos];
    for(std::size_t i=pos+1; i<pos+len; i++)
    {
        if(res > arr[i])
            res = arr[i];
    }

    return res;
}

int arr_max (const int arr[], std::size_t pos, std::size_t len)
{
    // assert(len >= 1);

    int res = arr[pos];
    for(std::size_t i=pos+1; i<pos+len; i++)
    {
        if(res < arr[i])
            res = arr[i];
    }

    return res;
}

long get_ans (const int arr[], std::size_t arr_size, std::size_t pos, std::size_t len)
{
    // we find the maximal value outside [pos, pos+len) and the minimal value inside [pos, pos+len)
    // and if needed, we swap them

    int max_outside;
    if(pos > 0)
        max_outside = arr_max(arr, 0, pos);
    if((pos+len)<arr_size)
    {
        int tmp = arr_max(arr, pos+len, arr_size-pos-len);
        if(pos <= 0 || tmp > max_outside)
            max_outside = tmp;
    }

    int min_inside = arr_min(arr, pos, len);

    long res = arr_sum(arr, pos, len);
    if(min_inside < max_outside)
        res = res - min_inside + max_outside;

    return res;
}

int main ()
{
    int arr[ARR_CAPACITY];

    std::size_t n, k;
    std::cin>>n>>k;

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    long res_sum = get_ans(arr, n, 0, k);
    std::size_t res_pos = 0;

    for(std::size_t i=1; i+k<=n; i++)
    {
        long cur_sum = get_ans(arr, n, i, k);
        if(res_sum < cur_sum)
        {
            res_sum = cur_sum;
            res_pos = i;
        }
    }

    std::cout << res_sum << ' ' << res_pos << '\n';
    
    return 0;
}
