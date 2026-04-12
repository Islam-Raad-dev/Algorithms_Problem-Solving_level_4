/*

Last Day, Last Month

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

bool IsLastDayInMonth(sDate Date1)
{
    
    return (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month)) ? true : false;
    
}

bool IsLastMonthInYear(sDate Date1)
{

    return (Date1.Month == 12) ? true : false;

}

int main()
{
    sDate Date1 = ReadFullDate();

    if (IsLastDayInMonth(Date1))
    {
        cout << "\nYes, The Day Is Last Day In The Month.";
    }

    else
    {
        cout << "\nNo, The Day Is Not Last Day In The Month.";
    }

    if (IsLastMonthInYear(Date1))
    {
        cout << "\nYes, The Month Is Last Month In The Year.";
    }

    else
    {
        cout << "\nNo, The Month Is Not Last Month In The Year.";
    }

    return 0;
}