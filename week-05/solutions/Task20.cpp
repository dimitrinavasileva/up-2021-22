#include<iostream>

int main()
{
    int n;

    do
    {
        std::cin >> n;
    } while (n <= 0);

    for (int k = 2; k <= n; k++)
    {
        int sum = 1;

        for (int i = 2; i <= k / 2; i++)
            if (k % i == 0) sum += i;
        if (sum == k) std::cout << k << '\n';
    }

     return 0;
}