/*

Validate Date
 
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

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

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

bool IsItValidDate(sDate Date)
{
    if (Date.Day < 1 || Date.Month > 31)
    {
        return false;
    }
    if (Date.Month == 12)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)
            {
                return false;
            }
        }
        else
        {
            if (Date.Day > 28)
            {
                return false;
            }
        }

        short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > DaysInMonth)
        {
            return false;
        }
        return true;
    }
}

int main()
{

    cout << "Please Enter A Date: " << endl;
    sDate Date = ReadFullDate();

    if (IsItValidDate(Date))
    {
        cout << "\nYes, The Date Is Valid." << endl;
    }
    else
    {
        cout << "\nNo, The Date Is Not Valid." << endl;
    }

    return 0;
}