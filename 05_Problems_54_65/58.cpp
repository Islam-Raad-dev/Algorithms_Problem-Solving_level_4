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

int main(){

    cout << "Please Enter First Period: " << endl;
    Period1 StartPeriod = ReadFullDate1();
    Period1 EndPeriod = ReadFullDate1();

    cout << "Please Enter Second Period: " << endl;
    Period2 SecondPeriod = ReadFullDate2();
    Period2 EndSecondPeriod = ReadFullDate2();

    cout <<

    return 0;
}