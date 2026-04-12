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

bool IsLastDayInMonth(sDate Date1)
{
}

bool IsLastMonthInYear(sDate Date1)
{
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