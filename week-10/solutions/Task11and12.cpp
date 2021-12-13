#include <iostream>
#include <cassert>
#include <utility>

void my_sort (int *beg, int *end);

bool my_binary_search (const int *beg, const int *end, int val);

int main()
{
    int arr[7] = {4, 7, 5, 4, 8, 2, 1};
    my_sort(arr, arr+7);
    // тук трябва: arr = {1, 2, 4, 4, 5, 7, 8};
    
    for(std::size_t i=0; i<7; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    assert(my_binary_search(arr, arr+7, 3) == false);
    assert(my_binary_search(arr, arr+7, 8) == true);

    std::cout << my_binary_search(arr, arr+7, 3) << std::endl;
    std::cout << my_binary_search(arr, arr+7, 8) << std::endl;

    return 0;
}

void my_sort (int *beg, int *end)
{
    bool made_change;

    do
    {
        made_change = false;
        int *cbeg = beg+1;
        while(cbeg != end)
        {
            if(*(cbeg-1) > *cbeg)
            {
                std::swap(*(cbeg-1), *cbeg);
                made_change = true;
            }
            cbeg++;
        }

    } while(made_change);
}

// another implementation:
// https://github.com/dimitrinavasileva/up-2021-22/blob/master/week-09/implementations/BubbleSort.cpp
//void my_sort(int* beg, const int *end)
//{
//    int *arr = beg;
//    std::size_t n = end - beg; 
//    for (std::size_t i = 0; i < n - 1; i++)
//    {
//        bool swapped = false;
//        for (std::size_t j = 0; j < n - i - 1; j++)
//		{
//            if (arr[j] > arr[j + 1])
//			{
//                std::swap(arr[j], arr[j + 1]);
//                swapped = true;
//            }
//        }
//
//        if (!swapped)
//		{
//            break;
//        }
//    }
//}

bool my_binary_search (const int *beg, const int *end, int val)
{
    const int *ptr;
    std::size_t size, step;
    size = end - beg;
 
    while (size > 0) 
    {
        ptr = beg; 
        step = size / 2; 
        ptr += step; //it = it + step;
        if (*ptr < val) 
        {
            ++ptr;
            beg = ptr; 
            size -= step + 1; 
        }
        else if(*ptr == val)
        {
            return true;
        }
        else
            size = step;
    }
    return *ptr == val;
}

// another implementation:
// https://github.com/dimitrinavasileva/up-2021-22/blob/master/week-09/solutions/Task03.cpp lower_bound
//bool my_binary_search (int *beg, const int *end, int val)
//{
//    std::size_t arr_size = end - beg;
//
//    std::size_t a=0, b=arr_size;
//    std::size_t m;
//    while(a<b)
//    {
//        m = a/2 + b/2;
//        if(beg[m] > val)
//        {
//            b = m;
//        }
//        else if(beg[m] == val)
//        {
//            return true;
//        }
//        else 
//        {
//            a = m+1;
//        }
//    }
//
//    return false;
//}

