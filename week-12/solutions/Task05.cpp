#include <iostream>

const int MAX_LENGTH = 100;

int strlen(const char *text)
{
    if(*text == '\0')
		return 0;
	
	return strlen(text + 1) + 1;
}

bool isPalindrome(const char *text, int size) {
    if (size <= 1)
        return true;

    return (text[0] == text[size - 1]) && isPalindrome(text + 1, size - 2);
}

int main()
{
    char word[MAX_LENGTH];
    int n;

    std::cin >> word;
    n = strlen(word);

    std::cout << (isPalindrome(word, n) ? "YES" : "NO");

    return 0;
}