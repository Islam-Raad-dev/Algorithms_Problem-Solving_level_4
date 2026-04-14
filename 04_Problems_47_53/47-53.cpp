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
sDate DaysUntilTheEndOfTheWeek()
{
}

sDate DaysUntilTheEndOfTheMonth()
{
}

sDate DaysUntilTheEndOfTheYear()
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
        cout << "Yes, It's Weekend\n";
    else
        cout << "No, It's Not Weekend\n";

    cout << "\n\nIs It Weekend: \n";
    if (IsItWeekEnd(Date))
        cout << "Yes, It's Weekend\n";
    else
        cout << "No, It's Not Weekend\n";

    cout << "\n\nIs It Business Day: \n";
    if (IsItBusinessDay(Date))
        cout << "Yes, It's Business Day\n";
    else
        cout << "No, It's Not Business Day\n";

    cout << "\n\n;

        return 0;
}
