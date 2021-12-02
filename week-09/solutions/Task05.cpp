#include <iostream>
#include <cstddef>
#include <algorithm>
#include <cstring>

constexpr std::size_t STR_MAX_SIZE = 21; // 20 + 1 for the \0

// sort strings using lexicographical compare
void str_sort (char strs[][STR_MAX_SIZE], std::size_t strs_size)
{
    bool is_modified;
    do 
    {
        is_modified = false;
        for(std::size_t i=0; i<strs_size-1; i++)
        {
            if(std::strcmp(strs[i], strs[i+1]) > 0)
            {
                is_modified = true;
                std::swap (strs[i], strs[i+1]);
            }
        }
    } while (is_modified);
}

void str_substr (char dest[], const char str[], std::size_t begin, std::size_t end)
{
    std::size_t i=0;
    while(begin < end)
    {
        dest[i] = str[begin];
        ++begin;
        ++i;
    }
    dest[i] = '\0';
}

// генерираме и сортираме абсолютно всички поднизове
// и използваме това, че еднаквите поднизове, ще са на съседни
// позиции в сортирания низ
int main()
{
    char str[STR_MAX_SIZE];
    std::cin >> str;
    std::size_t n = std::strlen(str);

    char substrs[(STR_MAX_SIZE+1)*STR_MAX_SIZE/2][STR_MAX_SIZE];
    std::size_t substr_size=0;

    for(std::size_t i=0; i<n; i++)
    {
        for(std::size_t j=i+1; j<=n; j++)
        {
            str_substr(substrs[substr_size], str, i, j);
            ++substr_size;
        }
    }

    str_sort(substrs, substr_size);

    std::size_t res=1;
    for(std::size_t i=1; i<substr_size; i++)
    {
        if(std::strcmp(substrs[i-1], substrs[i]) != 0)
            ++res;
    }

    std::cout << res << '\n';

    return 0;
}
