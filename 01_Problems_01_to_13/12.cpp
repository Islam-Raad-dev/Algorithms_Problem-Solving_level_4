/*

Add Date To Date

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

short ReadDayToAdd()
{
    short Days;

    cout << "\n\nPlease Enter A Days To Add: ";
    cin >> Days;

    return Days;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay();

    return Date;
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

short NumbrOfDaysFromBeginningOfYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(Year, i);
    }

    TotalDays += Day;

    return TotalDays;
}

sDate GetDateFromDayOrderInYear(short Year, short DateOrderInYear)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }

        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

sDate AddingDaysToDate(sDate Date, short Days)
{
    short RemainingDays = Days + NumberOfDaysInMonth(Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }

        if (Date.Month > 12)
        {
            Date.Month = 1;
            Date.Year++;
        }

        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDayToAdd();

    Date = AddingDaysToDate(Date, Days);

    cout << "Date After Adding [ " << Days << " ] Days Is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n"
         << endl;

    return 0;
}