#include <iostream>
#include <cstddef>

unsigned nfib (unsigned n, unsigned k)
{
    if(n<k)
        return 1;
    unsigned res=0;
    for(std::size_t i=1; i<=k; i++)
    {
        res += nfib(n-i, k);
    }
    return res;
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    // Числата n и k не трябва да бъдат особено големи
    // (до около 15 примерно), защото изпълнението на 
    // програмата става разко изключително бавно с 
    // нарастването на n и k
    
    std::cout << nfib(n, k) << '\n';

    return 0;
}
