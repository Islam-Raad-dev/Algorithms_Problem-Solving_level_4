/*

Count Overlap Days 

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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month < Date2.Month)                         ? true
                                          : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true
                                                                                                                              : false;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2)) ? true : false;
}

enum enCompareDates
{
    Before = -1,
    Equal = 0,
    After = 1
};

enCompareDates CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
    {
        return Before;
    }
    if (IsDate1EqualDate2(Date1, Date2))
    {
        return Equal;
    }
    return After;
}

bool IsOverlapPeriod(sPeriod Period1, sPeriod Period2)
{
    if (
        CompareDates(Period1.StartDate, Period2.EndDate) == After ||
        CompareDates(Period1.EndDate, Period2.StartDate) == Before)
    {
        return false;
    }
    return true;
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

bool IsDateInPeriod(sDate Date, sPeriod Period)
{
    return (CompareDates(Date, Period.StartDate) == After || CompareDates(Date, Period.StartDate) == Equal) &&
           (CompareDates(Date, Period.EndDate) == Before || CompareDates(Date, Period.EndDate) == Equal);
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

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDate = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Period.StartDate, Period.EndDate))
    {
        Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
        Days++;
    }

    return (IncludeEndDate) ? ++Days : Days;
}

sPeriod GetOverlapPeriod(sPeriod Period1, sPeriod Period2)
{
    sPeriod OverlapPeriod;

    if (!IsOverlapPeriod(Period1, Period2))
    {
        OverlapPeriod.StartDate = {0, 0, 0};
        OverlapPeriod.EndDate = {0, 0, 0};
        return OverlapPeriod;
    }

    if (IsDate1BeforeDate2(Period1.StartDate, Period2.StartDate))
    {
        OverlapPeriod.StartDate = Period2.StartDate;
    }
    else
    {
        OverlapPeriod.StartDate = Period1.StartDate;
    }

    if (IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate))
    {
        OverlapPeriod.EndDate = Period1.EndDate;
    }
    else
    {
        OverlapPeriod.EndDate = Period2.EndDate;
    }

    return OverlapPeriod;
}

int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!IsOverlapPeriod(Period1, Period2))
    {
        return 0;
    }

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if(IsDateInPeriod(Period1.StartDate, Period2))
            {
                OverlapDays++;
            }
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);

        }
    }

    else
    {
        while(IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)){
            if(IsDateInPeriod(Period2.StartDate, Period1))
            {
                OverlapDays++;
            }
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

int main()
{

    cout << "Please Enter First Period:\n " << endl;
    sPeriod Period1 = ReadFullPeriod();

    cout << "Please Enter Second Period: " << endl;
    sPeriod Period2 = ReadFullPeriod();

    cout << "Overlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;

    return 0;
}