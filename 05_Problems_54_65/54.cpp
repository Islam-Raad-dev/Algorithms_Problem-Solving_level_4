/*

Caluclate Vaction Days

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

bool IsLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month));  
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);   
}

bool IsItWeekEnd(sDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsItBusinessDay(sDate Date)
{
    return !IsItWeekEnd(Date);
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

int GetDiffrenceInDays(sDate DateFrom, sDate DateTo, bool IncludeEndDate = false)
{
    int DaysCount = 0;

    while (IsDate1LessThanDate2(DateFrom, DateTo))
    {
        if(IsItBusinessDay(DateFrom))
        {
            DaysCount++;
        }

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DaysCount;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;

    return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}


string DayShortName(short DayOfWeekOrder)
{

    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return Days[DayOfWeekOrder];
}

short CalculateVactionDays(sDate DateFrom, sDate DateTo)
{
    short Days = 0;

    while(IsDate1LessThanDate2(DateFrom, DateTo))
    {
        if (!IsItWeekEnd(DateFrom))
        {
            Days++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return Days;
}

sDate GetSystemDate()
{
    sDate Date;

    time_t t = time(0);
    tm *Now = localtime(&t);

    Date.Year = Now->tm_year + 1900;
    Date.Month = Now->tm_mon + 1;
    Date.Day = Now->tm_mday;

    return Date;
}

int main()
{
    cout <<"\nVaction Start:\n";
    sDate DateFrom = ReadFullDate();

    cout <<"\nVaction Ends: \n";
    sDate DateTo = ReadFullDate();

    cout <<"\nVaction From: " << DayShortName(DayOfWeekOrder(DateFrom)) << ", " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

    cout <<"\nVaction To: " << DayShortName(DayOfWeekOrder(DateTo)) << ", " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

    cout << "\n\nActual Vaction Days: " << CalculateVactionDays(DateFrom, DateTo) << " Day(s)\n" << endl;



    return 0;
}