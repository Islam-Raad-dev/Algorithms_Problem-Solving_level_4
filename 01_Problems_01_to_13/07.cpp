/*

Mount Calendar 

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
short DayOfWeekOrder(short Year, short Month, short Day)
{
    if (Month < 3)
    {
        Month += 12;
        Year -= 1;
    }

    int K = Year % 100;
    int J = Year / 100;

    return (Day + (13 * (Month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
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

string GetMonthName(short Month)
{
    string MonthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    if (Month < 1 || Month > 12)
        return "Invalid Month";

    return MonthNames[Month - 1];
}


void PrintMonthCalendar(short Year, short Month)
{
    int NumberOfDays = NumberOfDaysInMonth(Year, Month);

    int Current = DayOfWeekOrder(Year, Month, 1);

    printf("\n----------------%s ----------------\n\n",
         GetMonthName(Month).c_str());

    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < Current; i++)
        printf("     ");
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\n\n";

    PrintMonthCalendar(Year, Month);

    return 0;

}