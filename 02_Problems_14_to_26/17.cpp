/*

Diff In Days

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

    cout << "\nPlease Enter A Year: ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month;

    cout << "\nPlease Enter A Month: ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\nPlease Enter A Day: ";
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
        return true;
    else
        return false;
}

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month));
}

bool IsLastMonthInYear(sDate Date1)
{
    return (Date1.Month == 12);
}

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{

    return (Date1.Year < Date2.Year) ? true : false;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;

}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

short GetDiffInDays(sDate Date1, sDate Date2)
{
    short Diff = 0;

    while (!IsDate1EqualDate2(Date1, Date2))
    {
        Date1 = IncreaseDateByOneDay(Date1);
        Diff++;
    }

    return Diff;
}
int main()
{

    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    if (IsDate1LessThanDate2(Date1, Date2))
    {
        cout << "\n\nThe Diffrence is: " << GetDiffInDays(Date1, Date2) << " Days.";

        cout << "\n\nDiffrence (Including End Day) is: " << GetDiffInDays(Date1, Date2) + 1 << " Days.";
    }

    else
        cout << "\n\nDate1 Is Not Less Than Date2.";

    return 0;
}