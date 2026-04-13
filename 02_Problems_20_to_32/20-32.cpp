/*

Increase Date Problems (20-32)
 
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

    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay();

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

bool IsLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
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

sDate IncreaseDateByXDays(sDate Date, short Days)
{
    for (short i = 0; i < Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    return IncreaseDateByXDays(Date, 7);
}

sDate IncreaseDateByXWeeks(sDate Date, short Weeks)
{
    return IncreaseDateByXDays(Date, Weeks * 7);
}
sDate IncreaseDateByXMonths(sDate Date, short Months)
{
    for (short i = 0; i < Months; i++)
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    return IncreaseDateByXMonths(Date, 1);
}

sDate IncreaseDateByXYears(sDate Date, short Years)
{
    Date.Year += Years;
    return Date;
}   

sDate IncreaseDateByOneYear(sDate Date)
{
    return IncreaseDateByXYears(Date, 1);
}

sDate IncreaseDateByXYYearFaster(sDate Date, short Years, short Months, short Days)
{
    Date = IncreaseDateByXYears(Date, Years);
    Date = IncreaseDateByXMonths(Date, Months);
    Date = IncreaseDateByXDays(Date, Days);
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date, short Years, short Months, short Days)
{
    return IncreaseDateByXYYearFaster(Date, 10, Months, Days);
}

sDate IncreaseDateByXDecade(sDate Date, short Decades, short Months, short Days)
{
    return IncreaseDateByXYYearFaster(Date, Decades * 10, Months, Days);
}

sDate IncreaseDateByXDecadeFaster(sDate Date, short Decades, short Months, short Days)
{
    return IncreaseDateByXYYearFaster(Date, Decades * 10, Months, Days);
}

sDate IncreaseDateByOneCentury(sDate Date, short Years, short Months, short Days)
{
    return IncreaseDateByXYYearFaster(Date, 100, Months, Days);
}

sDate IncreaseDateByOneMillennium(sDate Date, short Centuries, short Months, short Days)
{
    return IncreaseDateByXYYearFaster(Date, Centuries * 100, Months, Days);
}

int main()
{
    sDate Date = ReadFullDate();

    
    cout << "\n\nIncreasing Date By One Day: " << IncreaseDateByOneDay(Date).Day << "/" << IncreaseDateByOneDay(Date).Month << "/" << IncreaseDateByOneDay(Date).Year;


    cout << "\n\nIncreasing Date By One Week: " << IncreaseDateByOneWeek(Date).Day << "/" << IncreaseDateByOneWeek(Date).Month << "/" << IncreaseDateByOneWeek(Date).Year;


    cout << "\n\nIncreasing Date By One Month: " << IncreaseDateByOneMonth(Date).Day << "/" << IncreaseDateByOneMonth(Date).Month << "/" << IncreaseDateByOneMonth(Date).Year;


    cout << "\n\nIncreasing Date By One Year: " << IncreaseDateByOneYear(Date).Day << "/" << IncreaseDateByOneYear(Date).Month << "/" << IncreaseDateByOneYear(Date).Year;


    cout << "\n\nIncreasing Date By One Decade: " << IncreaseDateByOneDecade(Date, 10, 10, 1).Day << "/" << IncreaseDateByOneDecade(Date, 10, 10, 1).Month << "/" << IncreaseDateByOneDecade(Date, 10, 10, 1).Year;


    cout << "\n\nIncreasing Date By One Century: " << IncreaseDateByOneCentury(Date, 100, 10, 1).Day << "/" << IncreaseDateByOneCentury(Date, 100, 10, 1).Month << "/" << IncreaseDateByOneCentury(Date, 100, 10, 1).Year;


    cout << "\n\nIncreasing Date By One Millennium: " << IncreaseDateByOneMillennium(Date, 10, 10, 1).Day << "/" << IncreaseDateByOneMillennium(Date, 10, 10, 1).Month << "/" << IncreaseDateByOneMillennium(Date, 10, 10, 1).Year;


    cout << "\n\n";

    return 0;
}