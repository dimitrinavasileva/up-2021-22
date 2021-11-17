#include <cstddef>
#include <iostream>
#include <cmath>

constexpr std::size_t ARR_CAPACITY = 1024;
constexpr std::size_t AI_MAX = 1000000;
const std::size_t SIEVE_NUM_MAX = 
                static_cast<std::size_t>(std::sqrt(static_cast<double>(AI_MAX)));  // cannot be constexpr

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

unsigned max_number (const unsigned arr[], std::size_t arr_size)
{
    // assert(arr_size > 0);
    std::size_t max_num = arr[0];
    for(std::size_t i=1; i<arr_size; i++)
    {
        if(max_num < arr[i])
            max_num = arr[i];
    }
    return max_num;
}

// generate list of all primes <= max_prime
std::size_t sieve_primes (unsigned primes_list[], std::size_t max_prime)
{
    // assert(max_prime <= SIEVE_NUM_MAX);
    bool is_not_prime[SIEVE_NUM_MAX+1];  // in some cases this might be too large

    std::size_t primes_list_size=0;

    is_not_prime[0] = true;
    is_not_prime[1] = true;
    is_not_prime[2] = false;
    is_not_prime[3] = false;

    primes_list[primes_list_size++] = 2;

    // zero initialize is_not_prime and deal with the even numbers
    for(std::size_t i=4; i<=max_prime; i++)
    {
        if(i%2 == 0)
            is_not_prime[i] = true;     // i is even
        else
            is_not_prime[i] = false;
    }

    for(std::size_t i=3; i<=max_prime; i+=2)
    {
        if(!is_not_prime[i])
        {
            primes_list[primes_list_size++] = i;
            for(std::size_t j=2*i; j<=max_prime; j+=i)
                is_not_prime[j] = true;
        }
    }

   return primes_list_size; 
}

unsigned count_no_prime_divisiors (unsigned a, const unsigned primes_list[], std::size_t primes_list_size)
{
    // asset that the number of primes i n the primes_list is large enough
    // assert (primes_list[primes_list_size-1] * primes_list[primes_list_size-1] >= a);

    unsigned res = 0;

    for(std::size_t i=0; i<primes_list_size; i++)
    {
        if(a%primes_list[i] == 0)
        {
            res++;
            while (a%primes_list[i] == 0)
            {
                a /= primes_list[i];
            }
        }
        if(a == 1)
            break;
    }

    if(a != 1)  
        res++;  // a is guaranteed prime

    return res;
}

void buble_sort_prime_div (unsigned arr[], unsigned arr_size, const unsigned primes_list[], std::size_t primes_list_size)
{
    bool swap_made;
    do
    {
        swap_made = false;

        for(std::size_t i=0; i<arr_size-1; i++)
        {
            // could be made a lot faster using structs
            
            unsigned c1_div = count_no_prime_divisiors(arr[i], primes_list, primes_list_size);
            unsigned c2_div = count_no_prime_divisiors(arr[i+1], primes_list, primes_list_size);

            if(c1_div < c2_div || (c1_div == c2_div && arr[i] < arr[i+1])) 
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
    unsigned primes_list[256];  // "Magic number", bad practice, 169 should be enough
    std::size_t arr_size = input_array(arr, ARR_CAPACITY);
    unsigned max_required_prime = std::ceil(std::sqrt(max_number(arr, arr_size)));
    std::size_t primes_list_size = sieve_primes(primes_list, max_required_prime);

    buble_sort_prime_div(arr, arr_size, primes_list, primes_list_size);

    print_array(arr, arr_size);

    return 0;
}
