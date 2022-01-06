#include <iostream>

int fibonacci(int n)
{
	if(n == 0)
		return 0;
    if (n == 1)
        return 1;
	
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
	std::cin >> n;

    std::cout << fibonacci(n) << std::endl;

    print(arr, n);
}