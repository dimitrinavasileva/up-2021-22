#include <iostream>
#include <cstddef>
#include <algorithm>

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

std::size_t count_in_range (const unsigned arr[], std::size_t arr_size, unsigned a, unsigned b)
{
    std::size_t res=0;

    for(std::size_t i=0; i<arr_size; i++)
    {
        if(a <= arr[i] && arr[i] <= b)
            ++res;
    }

    return res;
}

// Наивното решение, което просто, при всяка заявка обхожда масива и намира резултата
void solution_naive()
{
    unsigned arr[1024];
    std::size_t arr_size = input_array(arr, 1024);

    unsigned q;
    std::cin>>q;
    unsigned a, b;
    for(std::size_t i=0; i<q; i++)
    {
        std::cin >> a >> b;
        
        std::cout << count_in_range(arr, arr_size, a, b) << '\n';
    }
}

// some kind of sorting algorithm ... buble sort in this case
void arr_sort (unsigned arr[], std::size_t arr_size)
{
    bool is_modified;
    do 
    {
        is_modified = false;
        for(std::size_t i=0; i<arr_size-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                is_modified = true;
                std::swap (arr[i], arr[i+1]);
            }
        }
    } while (is_modified);
}

// двоично търсене - аналог на std::lower_bound
std::size_t lower_bound (const unsigned arr[], std::size_t arr_size, unsigned val)
{
    std::size_t res = arr_size;

    std::size_t a=0, b=arr_size;
    std::size_t m;
    while(a<b)
    {
        m = a/2 + b/2;
        if(arr[m] >= val)
        {
            res = m;
            b = m;
        }
        else 
        {
            a = m+1;
        }
    }

    return res;
}

// двоично търсене - аналог на std::upper_bound
std::size_t upper_bound (const unsigned arr[], std::size_t arr_size, unsigned val)
{
    std::size_t res = arr_size;

    std::size_t a=0, b=arr_size;
    std::size_t m;
    while(a<b)
    {
        m = a/2 + b/2;
        if(arr[m] > val)
        {
            res = m;
            b = m;
        }
        else 
        {
            a = m+1;
        }
    }

    return res;
}

// "умното" решение, което щеше да е по-бързо от наивното, ако ползвахме 
// по-бърз сортиращ алгоритъм (например такъв с сложност n*log2(n))
// Идеята е, че в началото сортираме числата и после използваме 
// две двоични търсения, едното upper_bound, другото lower_bound за да намерим
// идексите на числата съответно >b и >= а и разликата им ни двава броя на числата 
// в интервала [a, b].
// Понеже това решение използва бавен сортиращ алпгоритъм, в доста частно случаи 
// е по-бързо от наивното
void solve_binary_search()
{
    unsigned arr[1024];
    std::size_t arr_size = input_array(arr, 1024);

    arr_sort(arr, arr_size);

    unsigned q;
    std::cin>>q;
    unsigned a, b;
    for(std::size_t i=0; i<q; i++)
    {
        std::cin >> a >> b;
        
        std::size_t res = 
            upper_bound(arr, arr_size, b) - lower_bound(arr, arr_size, a);

        std::cout << res << '\n';
    }
}

int main()
{
    //solution_naive();
    solve_binary_search();

    return 0;
}
