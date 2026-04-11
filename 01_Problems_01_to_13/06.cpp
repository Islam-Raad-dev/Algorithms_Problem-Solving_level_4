/*

Number Of Days-Hours-Minutes-Seconds in Months (Short Version)

*/
#include <iostream> 
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
    if(Month < 1 || Month > 12)
    return 0;

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (IsLeapYear(Year))
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\n\n";

    cout << "Number Of Days In " << Month << " Is: " << NumberOfDaysinMonth(Year, Month) << endl;

    cout << "Number Of Hours In " << Month << " Is: " << NumberOfHoursinMonth(Year, Month) << endl;

    cout << "Number Of Minutes In " << Month << " Is: " << NumberOfMinutesinMonth(Year, Month) << endl;

    cout << "Number Of Seconds In " << Month << " Is: " << NumberOfSecondsinMonth(Year, Month) << endl;


    return 0;
}