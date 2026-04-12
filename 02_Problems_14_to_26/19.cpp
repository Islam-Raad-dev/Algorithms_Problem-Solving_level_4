/*

Different In Days (Nagative Days)

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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year &&    Date1.Month < Date2.Month) ? true : (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) ? true : false;
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

void SwapDates(sDate &Date1, sDate &Date2)
{

    sDate Temp = Date1;
    Date1 = Date2;
    Date2 = Temp;

}
int GetDiffrenceInDays(sDate Date1, sDate Date2, bool IncludeEndDate = false)
{
    int Days = 0;
    short SwaoFlagValue = 0;

    if(!IsDate1LessThanDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwaoFlagValue = -1;
    }

    while (!IsDate1LessThanDate2(Date2, Date1))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

        if(SwaoFlagValue == -1)
            Days *= -1;
    }

    return (IncludeEndDate) ? ++Days : Days;
}

int main()
{
    cout <<"\n Please Enter Your Birth Date: \n\n";

    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    cout << "\n\nThe Diffrence is: " << GetDiffrenceInDays(Date1, Date2) << " Days." << endl;

    cout << "\nDiffrence (Including End Day) is: " << GetDiffrenceInDays(Date1, Date2, true) << " Days.\n"
         << endl;

    return 0;
}