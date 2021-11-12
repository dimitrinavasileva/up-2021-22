#include <iostream>

bool is_leap_year (unsigned year)
{
    if(year%400==0) return true;
    if(year%100==0) return false;
    if(year%4  ==0) return true;
    return false;
}

unsigned days_per_month (unsigned month, unsigned year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        return is_leap_year(year) ? 29 : 28;
        break;
    default:
        return 0; // defined behaviour
        break;
    }
}

bool is_valid_date (unsigned day, unsigned month, unsigned year)
{
    return 1 <= month && month <= 12 &&
           1 <= day && day <= days_per_month(month, year);
}

bool is_beautiful (unsigned day, unsigned month, unsigned year)
{
    if(!is_valid_date(day, month, year)) 
        return false;

    unsigned rday, rmonth, ryear;  // reversed date
    ryear = (month%10)*1000 + (month/10)*100 + (day%10)*10 + (day/10);
    rmonth = (year/100%10)*10 + (year/1000);
    rday = (year%10)*10 + (year/10%10);

    return is_valid_date(rday, rmonth, ryear);
}

int main()
{
    unsigned day, month, year;
    std::cin>>day>>month>>year;

    std::cout << (is_beautiful(day, month, year) ? "" : "NOT ")
              << "beautiful\n";

    return 0;
}
