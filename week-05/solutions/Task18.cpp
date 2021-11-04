#include<iostream>

int main()
{
    int res = 0;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if(i!=j && i != k && j != k)
                {
                    res = 100 * i + 10 * j + k;
                    std::cout << res << '\n';
                }
            }
        }
    }

    return 0;
}