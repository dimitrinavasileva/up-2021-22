#include<iostream>

bool isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

void arrayW(char* str)
{
	int length = strlen(str);
	for (unsigned i = 0; i < length; i++)
	{
		if (isDigit(str[i]))
		{
			int number = 0;
			while (isDigit(str[i]))
			{
				number = number * 10 + (str[i] - '0');
				i++;
			}
			std::cout << number << '\n';
		}
	}
}
int main()
{
	char arr[200];
	std::cin.getline(arr, 200);
	std::cout << "Array:" << '\n';
	arrayW(arr);
	return 0;
}
