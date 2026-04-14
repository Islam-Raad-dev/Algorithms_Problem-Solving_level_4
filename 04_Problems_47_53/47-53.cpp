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

sDate TodayIs()
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
}
int main()
{
    sDate Date = GetSystemDate();

    Date = TodayIs();

    cout << "\nIs It End Of Week: \n";
    if (IsItWeekEnd(Date))
    {
        cout << "Yes, It's Weekend\n";
    }

    else
    {
        cout << "No, It's Not Weekend\n";
    }

    cout << "\n\nIs It Weekend: \n";
    if (IsItWeekEnd(Date))
    {
        cout << "Yes, It's Weekend\n";
    }

    else
    {
        cout << "No, It's Not Weekend\n";
    }
    cout << "\n\nIs It Business Day: \n";
    if (IsItBusinessDay(Date))
    {
        cout << "Yes, It's Business Day\n";
    }

    else
    {
        cout << "No, It's Not Business Day\n";
    }

    cout << "\n\nDays Until The End Of The Week: \n";
    Date = DaysUntilTheEndOfTheWeek();

    cout << "\n\nDays Until The End Of The Month: \n";
    Date = DaysUntilTheEndOfTheMonth();

    cout << "\n\nDays Until The End Of The Year: \n";
    Date = DaysUntilTheEndOfTheYear();

    return 0;
}
