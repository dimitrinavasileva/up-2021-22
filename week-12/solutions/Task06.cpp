#include <cstddef>
#include <iostream>
#include <climits>
#include <new>

std::size_t my_min (int arr[], std::size_t arr_size)
{
    if(arr_size == 0)
        return INT_MIN;  // at least defined behaviour, maybe throw exception here
    if(arr_size == 1)
        return 0;
    std::size_t min_pos_rest = my_min(arr+1, arr_size-1) + 1; // we add one, because we shift our array by one
    int min_rest = arr[min_pos_rest];
    if(arr[0] <= min_rest)
        return 0;
    return min_pos_rest;
}

void my_sort (int arr[], std::size_t arr_size)
{
    if(arr_size <= 1)
        return;
    std::size_t min_pos = my_min(arr, arr_size);
    // we put the smallest element in the beggining of the array, and sort the rest
    std::swap(arr[0], arr[min_pos]);
    my_sort(arr+1, arr_size-1);
}

int main()
{
    std::size_t n;
    std::cin >> n;
    int *arr = new int[n];
    for(std::size_t i=0; i<n; i++)
        std::cin >> arr[i];

    my_sort(arr, n);

    for(std::size_t i=0; i<n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';


    delete[] arr;

    return 0;
}
