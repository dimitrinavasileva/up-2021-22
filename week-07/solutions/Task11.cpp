#include <cstddef>
#include <iostream>
#include <cmath>

// this is the moving window solution
// There is also easier naive solution

// You can also multiply k numbers and check their unique prime
// multiplies, but this would quickly overflow

constexpr std::size_t ARR_CAPACITY = 1024;
constexpr std::size_t AI_MAX = 1000000;
constexpr std::size_t SIEVE_NUM_MAX = AI_MAX;
constexpr std::size_t PRIMES_LIST_SIZE = 80000;  // 78498 must be enough  // function of AI_MAX

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


/**
 * Mark divisor_list[i] with true if the prime number prime_list[i] is prime divisor of a
 * divisor_list must be of a primes_list_size size
 */
void count_no_prime_divisiors (unsigned a, const unsigned primes_list[], std::size_t primes_list_size, bool divisor_list[])
{
    // asset that the number of primes i n the primes_list is large enough
    // assert (primes_list[primes_list_size-1] * primes_list[primes_list_size-1] >= a);

    std::size_t i;
    for(i=0; i<primes_list_size; i++)
    {
        if(a%primes_list[i] == 0)
        {
            divisor_list[i] = true;
            while (a%primes_list[i] == 0)
            {
                a /= primes_list[i];
            }
        }

        if(a == 1)
            break;
    }

    // assert ( a!=1 );
}

void vector_add (int va[], std::size_t size, const bool vb[])
{
    for(std::size_t i=0; i<size; i++)
        va[i] += static_cast<int>(vb[i]);
}


void vector_substract (int va[], std::size_t size, const bool vb[])
{
    for(std::size_t i=0; i<size; i++)
        va[i] -= static_cast<int>(vb[i]);
}

void vector_fill (bool arr[], std::size_t size, bool val)
{
    for(std::size_t i=0; i<size; i++)
        arr[i] = val;
}

std::size_t vector_count_nonzero (const int arr[], std::size_t size)
{
    std::size_t res = 0;

    for(std::size_t i=0; i<size; i++)
    {
        if(arr[i] != 0)
            res++;
    }

    return res;
}

int main()
{
    unsigned arr[ARR_CAPACITY];

    std::size_t n, k;
    std::cin>>n>>k;

    if(n>ARR_CAPACITY)
        n = ARR_CAPACITY;
    if(k>n)
        k = n;

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    unsigned primes_list[PRIMES_LIST_SIZE];  // "Magic number", bad practice
    unsigned max_required_prime = max_number(arr, n);  // calc primes up to the largets number in arr
    std::size_t primes_list_size = sieve_primes(primes_list, max_required_prime);

    int cur_div[PRIMES_LIST_SIZE] = {0};
    bool tmp_div[PRIMES_LIST_SIZE];

    for(std::size_t i=0; i<k; i++)
    {
        vector_fill(tmp_div, primes_list_size, false);
        count_no_prime_divisiors(arr[i], primes_list, primes_list_size, tmp_div);
        vector_add(cur_div, primes_list_size, tmp_div);
    }

    std::size_t res_cnt = vector_count_nonzero(cur_div, primes_list_size);
    std::size_t res_pos = 0;

    for(std::size_t i=1; i+k<=n; i++)
    {
        vector_fill(tmp_div, primes_list_size, false);
        count_no_prime_divisiors(arr[i-1], primes_list, primes_list_size, tmp_div);
        vector_substract(cur_div, primes_list_size, tmp_div);

        vector_fill(tmp_div, primes_list_size, false);
        count_no_prime_divisiors(arr[i+k-1], primes_list, primes_list_size, tmp_div);
        vector_add(cur_div, primes_list_size, tmp_div);

        std::size_t cur_cnt = vector_count_nonzero(cur_div, primes_list_size);
        if(res_cnt < cur_cnt)
        {
            res_cnt = cur_cnt;
            res_pos = i;
        }
    }

    std::cout << res_cnt << ' ' << res_pos << '\n';

    return 0;
}
