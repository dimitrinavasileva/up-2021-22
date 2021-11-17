#include <cstddef>
#include <iostream>

constexpr std::size_t ARR_CAPACITY = 1024;

long solution_naive_sum (const int arr[], std::size_t pos, std::size_t len)
{
    long res=0;
    for(std::size_t i=pos; i<pos+len; i++)
        res += arr[i];

    return res;
}

void solution_naive ()
{
    int arr[ARR_CAPACITY];

    std::size_t n, k;
    std::cin>>n>>k;

    // might be better to throw error
    if(n>ARR_CAPACITY)
        n = ARR_CAPACITY;
    if(k>n)
        k = n;

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    long res_sum = solution_naive_sum(arr, 0, k);
    std::size_t res_pos = 0;
    for(std::size_t i=1; i+k<=n; i++)
    {
        long cur_sum = solution_naive_sum(arr, i, k);
        if(res_sum < cur_sum)
        {
            res_sum = cur_sum;
            res_pos = i;
        }
    }
    
    std::cout << res_sum << ' ' << res_pos << '\n';
}

void solution_moving_window()
{
    int arr[ARR_CAPACITY];

    std::size_t n, k;
    std::cin>>n>>k;

    // might be better to throw error
    if(n>ARR_CAPACITY)
        n = ARR_CAPACITY;
    if(k>n)
        k = n;

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    long cur_sum=0;

    for(std::size_t i=0; i<k; i++)
        cur_sum += arr[i];

    long res_sum = cur_sum;
    std::size_t res_pos = 0;

    for(std::size_t i=1; i+k<=n; i++)
    {
        cur_sum -= arr[i-1];
        cur_sum += arr[i+k-1];

        if(res_sum < cur_sum)
        {
            res_sum = cur_sum;
            res_pos = i;
        }
    }

    std::cout << res_sum << ' ' << res_pos << '\n';
}

int main()
{
    // solution_naive();
    
    solution_moving_window();


    return 0;
}
