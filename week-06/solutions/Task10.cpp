#include <iostream>

// Doesn't scale very well ... example: Na, Pb
unsigned get_mass_from_element (char c) 
{
    switch(c)
    {
    case 'H':
        return 1;
        break;
    case 'C':
        return 12;
        break;
    case 'N':
        return 14;
        break;
    case 'O':
        return 16;
        break;
    default:
        return 0; // at least it is defined behaviour
        break;
    }
}

// not a very good practice, but it doesn't use arrays
unsigned get_element_mass ()
{
    char element;
    std::cin >> element;
    unsigned element_mass = get_mass_from_element(element);
    unsigned count = 0;
    char p = std::cin.peek();
    if(!('0' <= p && p <= '9'))
    {
        // next character is a element, not count
        count=1;
    }
    else
    {
        std::cin>>count; // just input it as a normal number
    }
    
    return element_mass*count;
}

int main()
{   
    unsigned res=0;
    while(std::cin.peek()!='.')
    {
        res += get_element_mass();
    }
    // std::cin.get();  // flush '.' from the stream

    std::cout << res << '\n';

    return 0;
}
