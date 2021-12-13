#include<iostream>

void swap(int* num1, int* num2)
{
    int tmp = *num1;
    *num1 = *num2; 
    *num2 = tmp;
}

int main()
{
    int num1;
    int num2;

    std::cin >> num1 >> num2;

    swap(&num1, &num2);

    std::cout << num1 << " " << num2 << '\n';

    return 0;
}