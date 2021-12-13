#include <iostream>

// Effective modern c++, requires C++14
template<typename T>       // declaration only for TD;
class TD;                  // TD == "Type Displayer"

// Типът може да бъде видян в грешките генерирани от компиалтора.

// +0 е нужно за да получим array to pointer decay

int main ()
{
    
    const int a[10];
    TD<decltype(a+0)>();
    //DEDUCE_TYPE(a); -> const int *v;


    const int b[10][20];
    TD<decltype(b+0)>(); 
    //DEDUCE_TYPE(b); -> int const (*v)[20];



    const int *c[10][30];
    TD<decltype(c[3]+0)>(); 
    //DEDUCE_TYPE(c[3]); -> const int **v;



    const int (*d)[10][30];
    TD<decltype(d+0)>(); 
    //DEDUCE_TYPE(d); -> int const (*v)[10][30]



    const int * const e[10][30];
    TD<decltype(e[5]+0)>(); 
    //DEDUCE_TYPE(e[5]); -> const int *const * v;



    const int * const *f[10][30];
    TD<decltype(f+0)>(); 
    //DEDUCE_TYPE(f); -> const int *const *(*)[30];

    return 0;
}
