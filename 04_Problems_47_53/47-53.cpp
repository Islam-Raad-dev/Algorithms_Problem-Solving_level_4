/*

More Date Problems (47-53)

*/
#include <iostream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

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

sDate DayOfWeekOrder(sDate Date)
{
}

bool IsEndOfWeek(sDate Date)
{
}

bool IsItWeekEnd(sDate Date)
{
}

bool IsItBusinessDay(sDate Date)
{
}
short DaysUntilTheEndOfTheWeek()
{
}

short DaysUntilTheEndOfTheMonth()
{
}

short DaysUntilTheEndOfTheYear()
{
}

string DayShortName(sDate Date)
{

    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return Days[Date.Day % 7];
}
sDate GetSystemDate()
{
    sDate Date;

    time_t t = time(0);
    tm *Now = localtime(&t);

    Date.Year = Now->tm_year + 1900;
    Date.Month = Now->tm_mon + 1;
    Date.Day = Now->tm_mday;

    return Date;
}

int main()
{
    sDate Date = GetSystemDate();

    cout<<"Today is: " << DayShortName(DayOfWeekOrder(Date)) << "/" << Date.Month << "/" << Date.Year << "\n";

    cout << "\nIs It End Of Week? \n";
    if (IsItWeekEnd(Date))
    {
        cout << "Yes, It's Saturday\n";
    }

    else
    {
        cout << "No, It's Not End Of Week\n";
    }

    cout << "\n\nIs It Weekend? \n";
    if (IsItWeekEnd(Date))
    {
        cout << "Yes, It's Weekend\n";
    }

    else
    {
        cout << "No, It's Not Weekend\n";
    }
    cout << "\n\nIs It Business Day? \n";
    if (IsItBusinessDay(Date))
    {
        cout << "Yes, It's Business Day\n";
    }

    else
    {
        cout << "No, It's Not Business Day\n";
    }

    cout << "\n\nDays Until The End Of The Week   : \n" << DaysUntilTheEndOfTheWeek();

    cout << "\n\nDays Until The End Of The Month  : \n" << DaysUntilTheEndOfTheMonth();

    cout << "\n\nDays Until The End Of The Year   : \n" << DaysUntilTheEndOfTheYear();

    return 0;
}
