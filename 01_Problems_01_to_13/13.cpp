/*

Date1 Less Than Date2

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

    cout << "Please Enter A Year: ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month;

    cout << "\n\nPlease Enter A Month: ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\n\nPlease Enter A Day: ";
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

bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
}

int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    if (IsDate1BeforDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 Is Less Than Date2.";
    }

    else
    {
        cout << "\nNo, Date1 Is Not Less Than Date2.";
    }

    return 0;
}