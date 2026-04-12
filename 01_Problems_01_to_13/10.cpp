/*

Days From The Beginning of the Year

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

short ReadDay()
{
    short Day;

    cout << "\n\nPlease Enter A Day Number: ";
    cin >> Day;

    return Day;
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

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short DaysFromBeginningOfYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short m = 1; m < Month; ++m)
    {
        TotalDays += NumberOfDaysInMonth(Year, m);
    }

    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n\nNumber of days from the beginning of the year: " << DaysFromBeginningOfYear(Year, Month, Day) << endl;

    return 0;
}