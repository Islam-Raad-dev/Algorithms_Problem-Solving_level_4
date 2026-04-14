/*

Is Date 1 After Date 2 ?

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

int main(){

    cout <<"\nEnter Date 1:\n";
    sDate Date1 = ReadFullDate();

    cout <<"\nEnter Date 2:\n";
    sDate Date2 = ReadFullDate();

    if(IsDate1AfterDate2(Date1, Date2))
    {
        cout << "\nYes, Date 1 is after Date 2." << endl;
    }
    else
    {
        cout << "\nNo, Date 1 is not after Date 2." << endl;
    }

    return 0;
}