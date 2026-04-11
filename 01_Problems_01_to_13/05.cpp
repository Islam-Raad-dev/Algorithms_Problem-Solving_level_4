/*

Number Of Days-Hours-Minutes-Seconds in Months

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

short ReadMonth()
{
    short Month;

    cout << "\n\nPlease Enter A Month Number: ";
    cin >> Month;

    return Month;
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
short NumberOfDaysinMonth(short Year, short Month)
{
    switch (Month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;

    case 4: case 6: case 9: case 11:
        return 30;

    case 2:
        return IsLeapYear(Year) ? 29 : 28;
    default:
        return 0;
    }
}

short NumberOfHoursinMonth(short Year, short Month)
{
    return NumberOfDaysinMonth(Year, Month) * 24;
}

int NumberOfMinutesinMonth(short Year, short Month)
{
    return NumberOfHoursinMonth(Year, Month) * 60;
}

int NumberOfSecondsinMonth(short Year, short Month)
{
    return NumberOfMinutesinMonth(Year, Month) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\n\n";

    cout << "Number Of Days In " << Month << " Is: " << NumberOfDaysinMonth(Year, Month) << endl;

    cout << "Number Of Hours In " << Month << " Is: " << NumberOfHoursinMonth(Year, Month) << endl;

    cout << "Number Of Minutes In " << Month << " Is: " << NumberOfMinutesinMonth(Year, Month) << endl;

    cout << "Number Of Seconds In " << Month << " Is: " << NumberOfSecondsinMonth(Year, Month) << endl;


    return 0;
}