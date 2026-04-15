/*

Is Date Within Period

*/

#include <iostream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
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

sPeriod ReadFullPeriod()
{
    sPeriod Period;

    cout << "\nPlease Enter The Start Date Of The Period: " << endl;
    Period.StartDate = ReadFullDate();

    cout << "\nPlease Enter The End Date Of The Period: " << endl;
    Period.EndDate = ReadFullDate();

    return Period;
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

bool IsLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month));  
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);   
}

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true : false;
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {

            Date.Month = 1;   
            Date.Day = 1;  
            Date.Year++; 

        }
        else
        {

            Date.Month++;  
            Date.Day = 1;

        }
    }

    else
    {

        Date.Day++;   

    }
    return Date;
}

int GetDiffrenceInDays(sDate Date1, sDate Date2, bool IncludeEndDate = false)
{
    int Days = 0;

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        Date1 = IncreaseDateByOneDay(Date1);
        Days++;
    }

    return (IncludeEndDate) ? ++Days : Days;
}

bool DateIsWithinPeriod(sDate Date,sPeriod Period)
{

}

int main()
{ 

    cout << "Please Enter Period:\n " << endl;
    sPeriod Period = ReadFullPeriod();

    cout << "Enter Date To Check: \n";
    sDate Date = ReadFullDate();

    if(DateIsWithinPeriod(Date, Period))
    {
        cout << "\nThe Date Is Within The Period." << endl;
    }
    else
    {
        cout << "\nThe Date Is Not Within The Period." << endl;
    }

    return 0;
}
