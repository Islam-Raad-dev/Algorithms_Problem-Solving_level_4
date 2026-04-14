/*

Is Date 1 After Date 2?

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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year > Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month > Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day) ? true : false;
}

int main(){

    sDate Date1 = ReadFullDate();

    sDate Date2 = ReadFullDate();

    if(IsDate1AfterDate2(Date1, Date2))
    {
        cout << "\nYes, Date 1 is after Date 2.";
    }
    else
    {
        cout << "\nNo, Date 1 is not after Date 2.";
    }

    return 0;
}