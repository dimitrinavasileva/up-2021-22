#include <cstddef>
#include <iostream>
#include <climits>
#include <new>

void my_insert_sorted (int arr[], std::size_t arr_size, int val)
{ 
    if(arr_size==0)
    {
        arr[0] = val;
        return;
    }
    if(arr[0] > val)
        std::swap(arr[0], val);
    my_insert_sorted(arr+1, arr_size-1, val);
}

void my_sort (int arr[], std::size_t arr_size)
{
    if(arr_size <= 1)
        return;
    my_sort(arr, arr_size-1);
    my_insert_sorted(arr, arr_size-1, arr[arr_size-1]);
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
