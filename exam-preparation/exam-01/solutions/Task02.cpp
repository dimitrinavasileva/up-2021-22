#include<iostream>

void pointsInCircle()
{
    std::cout << "Enter number for R (R > 0): ";

    double R; std::cin >> R;

    for (int x = (int)ceil(-R); x <= (int)R; x++)
    {
        for (int y = (int)ceil(-R); y <= (int)R; y++)
        {
            if (x * x + y * y <= R*R)
            {
                std::cout << "(" << x << "," << y << ")" << '\n';
            }
        }
    }

}

bool isInCircle(int x, int y)
{
    std::cout << "Enter number for R (R > 0): ";

    double R; std::cin >> R;

    for (int x = (int)ceil(-R); x <= (int)R; x++)
    {
        for (int y = (int)ceil(-R); y <= (int)R; y++)
        {
            if (x * x + y * y <= R*R)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    pointsInCircle();
	
	std::cout << std::boolalpha << isInCircle(5, 9);

    return 0;
}