#include <iostream>
#include <cstddef>
#include <limits>
#include <cctype>
#include <cstring>

// returns the size of the word beggining on position beg_pos
std::size_t word_size (const char str[], std::size_t beg_pos, std::size_t str_size)
{
    std::size_t res=0;
    // it is very important that beg_pos < str_size is before std::isspace
    // unsigned char cast is needed for isspace function
    while(beg_pos < str_size && std::isspace((unsigned char)(str[beg_pos])) == 0)
    {
        ++res;
        ++beg_pos;
    }

    return res;
}

int main()
{
    std::size_t k;
    std::cin >> k;
    char str[1024];
    // ignore everything until newline
    // needed because cin >> k does not read the newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(str, 1024);
    std::size_t str_size = std::strlen(str);

    std::size_t cur_pos=0;
    std::size_t res=0;

    while(cur_pos < str_size)
    {
        std::size_t cur_word_size = word_size(str, cur_pos, str_size);
        if(cur_word_size == k)
            ++res;
        cur_pos += cur_word_size+1;
    }

    std::cout << res << '\n';

    return 0;
}
