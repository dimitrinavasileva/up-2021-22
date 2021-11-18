#include <iostream>
#include <cstddef>

constexpr std::size_t ARR_CAPACITY = 1024;

bool check_equal (const unsigned a[], std::size_t beg_a, std::size_t size, const unsigned b[], std::size_t beg_b)
{
    for(std::size_t i=0; i<size; i++)
    {
        if(a[beg_a++] != b[beg_b++])
            return false;
    }
    return true;
}


std::size_t input_array (unsigned arr[], std::size_t arr_capacity)
{
    std::size_t n;
    std::cin >> n;
    if( n > arr_capacity )      // if n is larger than the array_capacity
        n = arr_capacity;       // read only array_capacity number of integers

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    return n;
}

int main()
{
    unsigned arr_a[ARR_CAPACITY], arr_b[ARR_CAPACITY];

    std::size_t arr_a_size = input_array(arr_a, ARR_CAPACITY);
    std::size_t arr_b_size = input_array(arr_b, ARR_CAPACITY);

    std::size_t res = 0;

    for(std::size_t i=0; i+arr_a_size<=arr_b_size; i++)
    {
        if(check_equal(arr_a, 0, arr_a_size, arr_b, i))
            ++res;
    }

    std::cout << res << std::endl;

    return 0;
}

