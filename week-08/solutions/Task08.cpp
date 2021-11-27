#include <iostream>
#include <cstring>
#include <cstddef>
#include <cctype>

int digit_word_to_digit (const char num[])
{
    if(std::strncmp(num, "zero", 4) == 0)
        return 0;
    if(std::strncmp(num, "one", 3) == 0)
        return 1;
    if(std::strncmp(num, "two", 3) == 0)
        return 2;
    if(std::strncmp(num, "three", 5) == 0)
        return 3;
    if(std::strncmp(num, "four", 4) == 0)
        return 4;
    if(std::strncmp(num, "five", 4) == 0)
        return 5;
    if(std::strncmp(num, "six", 3) == 0)
        return 6;
    if(std::strncmp(num, "seven", 5) == 0)
        return 7;
    if(std::strncmp(num, "eight", 5) == 0)
        return 8;
    if(std::strncmp(num, "nine", 4) == 0)
        return 9;
    return -1;
}

std::size_t digit_to_word_digit_size (unsigned num)
{
    switch (num)
    {
    case 0:
        return std::strlen("zero");
    case 1:
        return std::strlen("one");
    case 2:
        return std::strlen("two");
    case 3:
        return std::strlen("three");
    case 4:
        return std::strlen("four");
    case 5:
        return std::strlen("five");
    case 6:
        return std::strlen("six");
    case 7:
        return std::strlen("seven");
    case 8:
        return std::strlen("eight");
    case 9:
        return std::strlen("nine");
    default:
        return 0;
    }
}

void my_strcpy (char dst[], const char src[], std::size_t src_pos, std::size_t cpy_size)
{
    std::size_t i;
    for(i=0; i<cpy_size; i++)
    {
        if(src[src_pos+i] == '\0') 
            break;
        dst[i] = src[src_pos+i];
    }
    dst[i] = '\0'; // very important :)
}

void str_to_lower (char str[])
{
    std::size_t str_pos=0;
    while(str[str_pos] != '\0')
    {
        str[str_pos] = (char)std::tolower((unsigned char)str[str_pos]);
        ++str_pos;
    }
}

int get_num (char str[], std::size_t pos, std::size_t str_size)
{
    char digit_cpy[8]; // 8 should be enough for all digit words
    my_strcpy(digit_cpy, str, pos, std::min((std::size_t)7, str_size - pos));
    str_to_lower(digit_cpy);
    return digit_word_to_digit(digit_cpy);
}

int main()
{
    char str[1024];
    char res[1024];
    std::cin.getline(str, 1024);

    std::size_t str_size = std::strlen(str);
    std::size_t str_pos=0, res_pos=0;
   
    while(str_pos < str_size)
    {
        int num = get_num(str, str_pos, str_size);
        if(0 <= num && num <= 9)
        {
            res[res_pos] = (char)num+'0';
            res_pos++;
            str_pos += digit_to_word_digit_size(num);
        }
        else
        {
            res[res_pos] = str[str_pos];
            ++res_pos;
            ++str_pos;
        }
    }

    res[res_pos] = '\0';
    std::cout << res << '\n';

    return 0;
}
