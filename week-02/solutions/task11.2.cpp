#include <iostream>

int main()
{
    // char s1, s2, s7, s8;
    // int num;
    // 
    // std::cin >> s1 >> s2 >> num >> s7 >> s8;
    // 
    // // this might not work with non ASCII encoding
    // unsigned long long id = (s1 - 'A');
    // id = id * 26 + (s2 - 'A');
    // id = id * 10000 + num;
    // id = id * 26 + (s7 - 'A');
    // id = id * 26 + (s8 - 'A');

    unsigned long long id;
    std::cin >> id;

    char s1;
	char s2;
    char s7;
    char s8;
    int num;

    // this might not work with non ASCII encoding
    s8 = id%26 + 'A'; id/=26;
    s7 = id%26 + 'A'; id/=26;
    num = id%10000; id/= 10000;
    s2 = id%26 + 'A'; id /= 26;
    s1 = id%26 + 'A'; // id /= 26;

    std::cout << s1 << s2 << num << s7 << s8 << '\n';

    return 0;
}
