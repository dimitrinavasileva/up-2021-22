#include <iostream>
#include <cstddef>
#include <iomanip>

constexpr std::size_t ARR_MAX_SIZE = 1024;

// Функция, кято при даден сортиран масив и число, вмъква числото в масива, като го 
// запазва сортиран
std::size_t insert_into_sorted (unsigned arr[], std::size_t arr_size, unsigned val)
{
    std::size_t i=0;
    while(arr[i] < val && i < arr_size)
        i++;

    for(std::size_t p=arr_size; p>i; p--) // i is atleast 0
        arr[p] = arr[p-1];

    arr[i] = val;

    return arr_size+1;
}

// Функция, която намира медианата на масив, който обаче трябва да е сортиран преди това
unsigned double_median_from_sorted_arr (unsigned arr[], std::size_t arr_size)
{
    if(arr_size % 2 == 1)
    {
        return arr[arr_size/2]*2;
    }
    return arr[arr_size/2-1] + arr[arr_size/2];
}

// Използваме функцията insert_into_sorted, защото тя може да вкара елемент в сортиран
// масив с едно обикаляне на масива, вместо да добавяме новия елемент в края на масива
// и после да викаме някакъв сортиращ алгоритъм (примерно на мехурчето) с сложност 
// по-голяма от линейна
int main()
{
    unsigned n;
    std::cin >> n;
    unsigned arr[ARR_MAX_SIZE];
    unsigned res[ARR_MAX_SIZE];

    unsigned x;
    for(std::size_t i=0; i<n; i++)
    {
        std::cin >> x;
        insert_into_sorted(arr, i, x);
        res[i] = double_median_from_sorted_arr(arr, i+1);
    }

    for(std::size_t i=0; i<n; i++)
    {
        if(res[i] % 2 == 1)
        {
            std::cout << res[i]/2 << ".5 ";
        }
        else
        {
            std::cout << res[i]/2 << ' ';
        }
    }
    std::cout << '\n';
}
