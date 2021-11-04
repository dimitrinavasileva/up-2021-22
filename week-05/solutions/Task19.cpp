#include<iostream>

int main()
{
    for(int a = 1; a <= 9; a++)
        for (int c = 0; c <= 9 - a; c++) //c[0;9-a]
        {
            int b = a + c;
            std::cout << a << b << c << " ";
        }

     return 0;
}