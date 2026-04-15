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

bool IsOverlap(sPeriod Period1, sPeriod Period2)
{
    return (IsDate1BeforeDate2(Period1.StartDate, Period2.EndDate) && IsDate1AfterDate2(Period1.EndDate, Period2.StartDate)) || (IsDate1EqualDate2(Period1.StartDate, Period2.EndDate) || IsDate1EqualDate2(Period1.EndDate, Period2.StartDate));
}
int main(){

    cout << "Please Enter First Period:\n " << endl;
    sPeriod Period1 = ReadFullPeriod();

    cout << "Please Enter Second Period: " << endl;
    sPeriod Period2 = ReadFullPeriod();

    if(IsOverlap(Period1,Period2))
    {
        cout<< "\nYes, The Two Periods Overlap." << endl;
    }
    else
    {
        cout<< "\nNo, The Two Periods Do Not Overlap." << endl;
    }

    return 0;
}