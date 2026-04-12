/*

Date From Day Order In A Year

*/

#include <iostream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

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

    cout << "\n\nPlease Enter A Month: ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\n\nPlease Enter A Day: ";
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

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(Year, i);
    }

    TotalDays += Day;

    return TotalDays;
}

sDate GetDateFromDayOrderInYear(short Year, short DayOrder)
{
    sDate Date;

    return Date;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    short DaysOrderInYear = DaysFromBeginningOfYear(Year, Month, Day);

    cout << "\nNumber Of Days From The Beginning Of The Year is " << DaysOrderInYear << endl;

    cout << "\n\n";

    sDate Date;

    Date = GetDateFromDayOrderInYear(Year, DaysOrderInYear);
    cout << "Date For [" << DaysOrderInYear << "] Is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}