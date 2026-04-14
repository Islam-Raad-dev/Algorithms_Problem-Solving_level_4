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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (IsLastMonthInYear(Date.Month))
        {

            Date.Month = 12;  
            Date.Day = 31;  
            Date.Year--; 

        }
        else
        {

            Date.Month--;  
            Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month); 

        }
    }

    else
    {

        Date.Day--;   

    }
    return Date;
}

sDate DecreaseDateByXDays(sDate Date, short Days)
{
    for (short i = 1; i <= Days; i++)
    {

        Date = DecreaseDateByOneDay(Date);   

    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    return DecreaseDateByXDays(Date, 7);   
}

sDate DecreaseDateByXWeeks(sDate Date, short Weeks)
{
    return DecreaseDateByXDays(Date, Weeks * 7);
}
sDate DecreaseDateByXMonths(sDate Date, short Months)
{
    for (short i = 0; i < Months; i++)
    {

        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year--;  
        }

        else
        {
            Date.Month--;    
        }   
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    return DecreaseDateByXMonths(Date, 1);
}

sDate DecreaseDateByXYears(sDate Date, short Years)
{
    Date.Year -= Years;
    return Date;
}   

sDate DecreaseDateByOneYear(sDate Date)
{
    return DecreaseDateByXYears(Date, 1);
}

sDate DecreaseDateByXYYearFaster(sDate Date, short Years, short Months, short Days)
{
    Date = DecreaseDateByXYears(Date, Years);
    Date = DecreaseDateByXMonths(Date, Months);
    Date = DecreaseDateByXDays(Date, Days);
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date, short Years, short Months, short Days)
{
    return DecreaseDateByXYYearFaster(Date, 10, Months, Days);
}

sDate DecreaseDateByXDecade(sDate Date, short Decades, short Months, short Days)
{
    return DecreaseDateByXYYearFaster(Date, Decades * 10, Months, Days);
}

sDate DecreaseDateByXDecadeFaster(sDate Date, short Decades, short Months, short Days)
{
    return DecreaseDateByXYYearFaster(Date, Decades * 10, Months, Days);
}

sDate DecreaseDateByOneCentury(sDate Date, short Years, short Months, short Days)
{
    return DecreaseDateByXYYearFaster(Date, 100, Months, Days);
}

sDate DecreaseDateByOneMillennium(sDate Date, short Centuries, short Months, short Days)
{
    return DecreaseDateByXYYearFaster(Date, 1000, Months, Days);
}

int main()
{
    sDate Date = ReadFullDate();

    cout<<"\n\nDate After: \n\n";    

        Date = DecreaseDateByOneDay(Date);
        cout << "01- Subtract One Day: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";  
        
        Date = DecreaseDateByXDays(Date, 15);
        cout << "02- Subtract 15 Days: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";   
    
        Date = DecreaseDateByOneWeek(Date);
        cout << "03- Subtract One Week: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";    

        Date = DecreaseDateByXWeeks(Date, 3);
        cout << "04- Subtract 3 Weeks: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

    
        Date = DecreaseDateByOneMonth(Date);
        cout << "05- Subtract One Month: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = DecreaseDateByXMonths(Date, 5);
        cout << "06- Subtract 5 Months: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";  

        Date = DecreaseDateByOneYear(Date);
        cout << "07- Subtract One Year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = DecreaseDateByXYears(Date, 1);
        cout << "08- Subtract 1 Year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";


        Date = DecreaseDateByXYYearFaster(Date, 10, 0, 0);
        cout << "09- Subtract 10 Years: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";


        Date = DecreaseDateByOneDecade(Date, 0, 0, 0);
        cout << "10- Subtract One Decade: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    
        Date = DecreaseDateByXDecade(Date, 2, 0, 0);
        cout << "11- Subtract Two Decades: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = DecreaseDateByXDecadeFaster(Date, 3, 0, 0);
        cout << "12- Subtract Three Decades Faster: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

        Date = DecreaseDateByOneCentury(Date, 0, 0, 0);
        cout << "13- Subtract One Century: " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n"; 
    
        Date = DecreaseDateByOneMillennium(Date, 0, 0, 0);
        cout<<"14- Subtract One Millennium: "<<Date.Day<<"/"<<Date.Month<<"/"<<Date.Year<<"\n";

    cout << "\n\n";
   
    return 0;   
}