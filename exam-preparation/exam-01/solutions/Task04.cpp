#include<iostream>
#include<cstring>
using namespace std;

constexpr int ALPHABET_SIZE = 26;

void AlphaCount(const char* str)
{
	int counter = 0;
	int size = strlen(str);

	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (str[i] == char('a' + j))
			{
				counter++;
			}

			else if (str[i] == char('A' + j))
			{
				counter++;
			}
		}
		if (counter != 0)
		{
			cout << char('A' + j) << ": " << counter << " ";
			counter = 0;
		}
	}
}
int main()
{
	char arr[200];
	std::cin.getline(arr, 200);
	AlphaCount(arr);
	return 0;
}
