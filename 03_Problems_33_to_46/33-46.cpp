/*

Decrease Date Problem 33 to 46

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
    for (short i = 1; i <= Days; i++)
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

    cout<<"\nDate After: \n\n";    

        Date = IncreaseDateByOneDay(Date);
        cout << "01- One Day: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";  
        
        Date = IncreaseDateByXDays(Date, 15);
        cout << "02- Adding 15 Days: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";   
    
        Date = IncreaseDateByOneWeek(Date);
        cout << "03- One Week: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";    

        Date = IncreaseDateByXWeeks(Date, 3);
        cout << "04- Adding 3 Weeks: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

    
        Date = IncreaseDateByOneMonth(Date);
        cout << "05- One Month: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = IncreaseDateByXMonths(Date, 5);
        cout << "06- Adding 5 Months: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";  

        Date = IncreaseDateByOneYear(Date);
        cout << "07- One Year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = IncreaseDateByXYears(Date, 1);
        cout << "08- Adding 1 Year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";


        Date = IncreaseDateByXYYearFaster(Date, 10, 0, 0);
        cout << "09- Adding 10 Years: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";


        Date = IncreaseDateByOneDecade(Date, 0, 0, 0);
        cout << "10- One Decade: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    
        Date = IncreaseDateByXDecade(Date, 2, 0, 0);
        cout << "11- Two Decades: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = IncreaseDateByXDecadeFaster(Date, 3, 0, 0);
        cout << "12- Three Decades Faster: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = IncreaseDateByOneCentury(Date, 0, 0, 0);
        cout << "13- One Century: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n"; 
    
        Date = IncreaseDateByOneMillennium(Date, 0, 0, 0);
        cout<<"14- One Millennium: "<<Date.Day<<"/"<<Date.Month<<"/"<<Date.Year<<"\n";

    cout << "\n\n";
   
    return 0;   
}