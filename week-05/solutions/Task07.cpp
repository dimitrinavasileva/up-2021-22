#include <iostream>

int main()
{

    int start, end;

    std::cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        if (i % 3 == 0)
        {
            i++;
        }
    }

    std::cout << i;

    return 0;
}