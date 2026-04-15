/*

Is Overlap Periods

*/
#include <iostream>
using namespace std;

struct Period1
{
    short Day;
    short Month;
    short Year;
};

struct Period2
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

Period1 ReadFullDate1()
{
    Period1 Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

Period2 ReadFullDate2()
{
    Period2 Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsOverlap(Period1 StartPeriod1, Period1 EndPeriod1, Period2 StartPeriod2, Period2 EndPeriod2)
{
    return (StartPeriod1.Year < EndPeriod2.Year) ? true : (StartPeriod1.Year   == EndPeriod2.Year && StartPeriod1.Month < EndPeriod2.Month) ? true : (StartPeriod1.Year == EndPeriod2.Year && StartPeriod1.Month == EndPeriod2.Month && StartPeriod1.Day <= EndPeriod2.Day) ? true : (EndPeriod1.Year > StartPeriod2.Year) ? true : (EndPeriod1.Year == StartPeriod2.Year && EndPeriod1.Month > StartPeriod2.Month) ? true : (EndPeriod1.Year == StartPeriod2.Year && EndPeriod1.Month == StartPeriod2.Month && EndPeriod1.Day >= StartPeriod2.Day) ? true : false;
}
int main(){

    cout << "Please Enter First Period: " << endl;

    cout << "Enter Start Period 1: " << endl;
    Period1 StartPeriod1 = ReadFullDate1();

    cout << "Enter End Period 1: " << endl;
    Period1 EndPeriod1 = ReadFullDate1();


    cout << "Please Enter Second Period: " << endl;

    cout << "Enter Start Period 2: " << endl;
    Period2 StartPeriod2 = ReadFullDate2();

    cout << "Enter End Period 2: " << endl;
    Period2 EndPeriod2 = ReadFullDate2();

    if(IsOverlap(StartPeriod1, EndPeriod1, StartPeriod2, EndPeriod2))
    {
        cout<< "Yes, The Two Periods Overlap Each Other." << endl;
    }
    else
    {
        cout<< "No, The Two Periods Do Not Overlap Each Other." << endl;
    }

    return 0;
}