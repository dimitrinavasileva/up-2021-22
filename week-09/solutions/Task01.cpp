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

bool is_prime (unsigned a)
{
    if(a < 2)
        return false;
    if(a == 2 || a == 3)
        return true;
    if(a%2 == 0 || a%3 == 0)
        return false;

    for (unsigned i=3; i*i<=a; i+=2) 
    {
        if(a%i == 0)
            return false;
    }

    return true;
}

// премахва елемента на позиция indx от масива arr, като не запазва наредбата на масива 
// (констатно време/без да обикаля масива като разменя с последния елемент)
// връща новият размер на масива
std::size_t arr_remove_indx_inplace_outoforder (unsigned arr[], std::size_t arr_size, std::size_t indx)
{
    std::swap(arr[indx], arr[arr_size-1]);
    return arr_size-1;
}

// премахва простите числа, като използва функцията за премахване arr_remove_indx_inplace_outoforder
// (т. е. премахва елементите на масива, с едно обхождане на масива, като простите числа ги разменя с последния елемент)
std::size_t arr_filter_inplace_outoforder (unsigned arr[], std::size_t arr_size)
{
    std::size_t i=0;
    while(i<arr_size)
    {
        if(is_prime(arr[i]))
        {
            arr_size = arr_remove_indx_inplace_outoforder(arr, arr_size, i);
        }
        else 
        {
            ++i;
        }
    }

    return arr_size;
}

// премахва елемента на позиция indx от масива arr, като запазва наредбата на масива
// (обикаля масива, в най-лошият случай (indx == 0) премесва всички елементи на масива с една позиция)
// връща новият размер на масива
std::size_t arr_remove_indx_inplace_inorder (unsigned arr[], std::size_t arr_size, std::size_t indx)
{
    for(std::size_t i=indx; i<arr_size-1; i++)
        arr[i] = arr[i+1];
    return arr_size-1;
}

// премахва простите числа, като използва функцията за премахване arr_remove_indx_inplace_inorder
// Темата за времева сложност излиза доста извън този курс, но все пак може да си представите:
// В тази фунцкция имаме цикъл, който в себе си вика arr_remove_indx_inplace_inorder,
// която фунцкия също в себе си има цикъл, така получаваме два вложени цикъла, което е бавно,
// защото не махаме простите елементи с просто едно обхождане
std::size_t arr_filter_inplace_inorder_slow (unsigned arr[], std::size_t arr_size)
{
    std::size_t i=0;
    while(i<arr_size)
    {
        if(is_prime(arr[i]))
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

// премахва простите числа, като го прави с едно обхождане на масива, но запазва резултата на друго място
std::size_t arr_filter_outofplace_inorder (const unsigned arr[], std::size_t arr_size, unsigned res[])
{
    std::size_t res_size=0;
    for(std::size_t i=0; i<arr_size; i++)
    {
        if(!is_prime(arr[i]))
        {
            res[res_size++] = arr[i];
        }
    }

    return res_size;
}

// премахва простите числа, като го прави с едно обхождане на масива и няма нужда от допълнителен масив/памет
std::size_t arr_filter_inplace_inorder_fast (unsigned arr[], std::size_t arr_size)
{
    std::size_t res_size=0;

    for(std::size_t i=0; i<arr_size; i++)
    {
        if(!is_prime(arr[i]))
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

    //new_size = arr_filter_inplace_outoforder(arr, arr_size);
    //print_array(arr, new_size);

    //new_size = arr_filter_inplace_inorder_slow(arr, arr_size);
    //print_array(arr, new_size);

    //unsigned res[1024];
    //new_size = arr_filter_outofplace_inorder(arr, arr_size, res);
    //print_array(res, new_size);

    new_size = arr_filter_inplace_inorder_fast(arr, arr_size);
    print_array(arr, new_size);

    return 0;
}
