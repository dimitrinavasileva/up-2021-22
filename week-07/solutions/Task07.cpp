#include <cstddef>
#include <iostream>

constexpr std::size_t ARR_CAPACITY = 1024;

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

unsigned rotate_number (unsigned a)
{
    unsigned ra = 0;
    do
    {
        ra = ra*10 + a%10;
        a /= 10;
    } while(a!=0);

    return ra;
}

/**
 * Returns:
 * -1 if a is lexicographically less than b
 *  0 if a is lexicographically equal to b
 *  1 if a is lexicographically larger than b
 */
int compare_lexicographic (unsigned a, unsigned b)
{
    unsigned ra = rotate_number(a);
    unsigned rb = rotate_number(b);

    unsigned da, db;
    do
    {
        da = ra%10;
        db = rb%10;
        
        if(da < db) return -1;
        if(da > db) return 1;

        ra /= 10;
        rb /= 10;
    } while(ra != 0 && rb != 0);

    if(rb != 0) return -1;
    if(ra != 0) return 1;
    return 0;
}

void buble_sort_lexicographic (unsigned arr[], unsigned arr_size)
{
    if(arr_size == 0) return;

    bool swap_made;
    do
    {
        swap_made = false;

        for(std::size_t i=0; i<arr_size-1; i++)
        {
            int cmp = compare_lexicographic(arr[i], arr[i+1]);
            if( cmp > 0 ) 
            {
                swap_made = true;

                unsigned tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                // or alternatively
                // std::swap(arr[i], arr[i+1]);
            }
        }

    } while(swap_made);
}

int main()
{
    unsigned arr[ARR_CAPACITY];

    std::size_t arr_size = input_array(arr, ARR_CAPACITY);

    buble_sort_lexicographic(arr, arr_size);

    print_array(arr, arr_size);

    return 0;
}
