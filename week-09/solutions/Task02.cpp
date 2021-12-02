#include <iostream>
#include <cstddef>
#include <algorithm>

// За повече информация на това решение, вижте решението на предната задача, то е аналогично

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

void print_array (const unsigned arr[], std::size_t arr_size)
{
    for(std::size_t i=0; i<arr_size; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

std::size_t arr_count_num (const unsigned arr[], std::size_t arr_size, unsigned num)
{
    std::size_t res=0;
    for(std::size_t i=0; i<arr_size; i++)
    {
        if(arr[i] == num)
            ++res;
    }

    return res;
}

std::size_t arr_remove_indx_inplace_inorder (unsigned arr[], std::size_t arr_size, std::size_t indx)
{
    for(std::size_t i=indx; i<arr_size-1; i++)
        arr[i] = arr[i+1];
    return arr_size-1;
}

std::size_t arr_filter_inplace_inorder_slow (unsigned arr[], std::size_t arr_size)
{
    std::size_t i=0;
    while(i<arr_size)
    {
        if(arr_count_num(arr, i, arr[i]) >= 2)
        {
            arr_size = arr_remove_indx_inplace_inorder(arr, arr_size, i);
        }
        else 
        {
            ++i;
        }
    }

    return arr_size;
}

std::size_t arr_filter_outofplace_inorder (const unsigned arr[], std::size_t arr_size, unsigned res[])
{
    std::size_t res_size=0;
    for(std::size_t i=0; i<arr_size; i++)
    {
        if(arr_count_num(res, res_size, arr[i]) <= 1)
        {
            res[res_size++] = arr[i];
        }
    }

    return res_size;
}

std::size_t arr_filter_inplace_inorder_fast (unsigned arr[], std::size_t arr_size)
{
    std::size_t res_size=0;

    for(std::size_t i=0; i<arr_size; i++)
    {
        if(arr_count_num(arr, res_size, arr[i]) <= 1)
        {
            arr[res_size++] = arr[i];
        }
    }

    return res_size;
}

int main()
{
    unsigned arr[1024];
    std::size_t arr_size = input_array(arr, 1024);
    std::size_t new_size;

    //new_size = arr_filter_inplace_inorder_slow(arr, arr_size);
    //print_array(arr, new_size);

    //unsigned res[1024];
    //new_size = arr_filter_outofplace_inorder(arr, arr_size, res);
    //print_array(res, new_size);

    new_size = arr_filter_inplace_inorder_fast(arr, arr_size);
    print_array(arr, new_size);

    return 0;
}
