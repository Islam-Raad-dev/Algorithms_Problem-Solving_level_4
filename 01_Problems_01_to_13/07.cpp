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


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();


    cout << "\n\n";

    PrintMonthCalendar(Year, Month);

    return 0;
}