/*

Is Overlap Periods

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

bool IsOverlap(Period1 StartPeriod1, Period1 EndPeriod1, Period2 StartPeriod2, Period2 EndPeriod2)
{
    return 
}
int main(){

    cout << "Please Enter First Period:\n " << endl;

    Period1 Period1 = ReadFullDate1();


    cout << "Please Enter Second Period: " << endl;

    Period2 Period2 = ReadFullPeriod();

    if(IsOverlap(Period1,Period2))
    {
        cout<< "\nYes, The Two Periods Overlap Each Other." << endl;
    }
    else
    {
        cout<< "\nNo, The Two Periods Do Not Overlap Each Other." << endl;
    }

    return 0;
}