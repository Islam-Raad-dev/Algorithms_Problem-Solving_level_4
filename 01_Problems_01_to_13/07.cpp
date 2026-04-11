/*

Day Name in Week

*/
#include <iostream>
#include <iomanip>
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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;

    return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string DayOfWeekName(short DayOfWeekOrder)
{
    string DaysOfWeek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    return DaysOfWeek[DayOfWeekOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n\n";

    cout << "\nDate         : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order     : " << DayOfWeekOrder(Year, Month, Day);
    cout << "\nDay Name      : " << DayOfWeekName(DayOfWeekOrder(Year, Month, Day)) << endl;

    return 0;
}