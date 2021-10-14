#include <iostream>

int main()
{
    char s1;
	char s2;
	char s7;
    char s8;
    int num;
    
    std::cin >> s1 >> s2 >> num >> s7 >> s8;
    
    // this might not work with non ASCII encoding
    unsigned long long id = (s1 - 'A');
	
    id = id * 26 + (s2 - 'A');
    id = id * 10000 + num;
    id = id * 26 + (s7 - 'A');
    id = id * 26 + (s8 - 'A');

    std::cout << id << '\n';

    return 0;
}
