#include<iostream>

int main()
{
    int n;

    do
    {
        std::cout << "Enter possitive number: ";
        std::cin >> n;
    } while(n <= 0);

    int size = 0;
    int curr = n;

    while (curr != 0)
    {
        size++;
        curr /= 10;
    }

    int k;

    do
    {
        std::cout << "Enter a number from 1 to " << size << ":";
    } while (k < 1 || k > size);

    int i = 1;
    for (int j = 1; j <= k - 1; j++)
    {
        i *= 10;
    }

    int resNum = n / (i * 10) * i + n % i;

    std::cout << "The result number is " << resNum << '\n';

    return 0;
}