/*

Number Of Days-Hours-Minutes-Seconds in Years

*/
#include <iostream>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "Please Enter A Year: ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
short NumberOfDays(short Year)
{
    if (IsLeapYear)
    {
        return Year / 366;
    }
    else
    {
        return Year / 365;
    }
}

short NumberOfHours(short Year)
{
    if (IsLeapYear)
    {
        return NumberOfDays(Year) * 24;
    }
    else
    {
        return NumberOfDays(Year) * 24;
    }
}

short NumberOfMinutes(short Year)
{
    if (IsLeapYear)
    {
        return NumberOfHours(Year) * 60;
    }
    else
    {
        return NumberOfHours(Year) * 60;
    }
}

short NumberOfSeconds(short Year)
{
    if (IsLeapYear)
    {
        return NumberOfMinutes(Year) * 60;
    }
    else
    {
        return NumberOfMinutes(Year) * 60;
    }
}


int main()
{
    short Year = ReadYear();

    cout << "Number Of Days In " << Year << " Is: " << NumberOfDays(Year) << endl;

    cout << "Number Of Hours In " << Year << " Is: " << NumberOfHours(Year) << endl;

    cout << "Number Of Minutes In " << Year << " Is: " << NumberOfMinutes(Year) << endl;
    
    cout << "Number Of Seconds In " << Year << " Is: " << NumberOfSeconds(Year) << endl;


    return 0;
}