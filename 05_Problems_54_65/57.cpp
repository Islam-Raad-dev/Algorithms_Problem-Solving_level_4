/*

Comparse Date Function:

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
      
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true : false;
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
    if(IsDate1BeforeDate2(Date1, Date2))
    {
        return Before;
    }
    if(IsDate1EqualDate2(Date1, Date2))
    {
        return Equal;
    }
        return After;

}

int main(){

    cout <<"\nEnter Date 1:\n";
    sDate Date1 = ReadFullDate();

    cout <<"Enter Date 2:\n";
    sDate Date2 = ReadFullDate();

    cout <<"\nCompare Result = " << CompareDates(Date1, Date2) << "\n";

    return 0;
}