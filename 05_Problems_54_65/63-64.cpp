/*

Read / Print Date String

*/
#include <iostream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

string ReadDateString()
{
    string DateString;

    cout << "\nPlease Enter A Date String: ";
    cin >> DateString;

    return DateString;
}

sDate ConvertStringToDate(string DateString)
{
    sDate Date;

    Date.Day = stoi(DateString.substr(0, 2));
    Date.Month = stoi(DateString.substr(3, 2));
    Date.Year = stoi(DateString.substr(6, 4));

    return Date;
}

void PrintStringDate(sDate Date)
{
    cout << "\nThe Date Is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{
    string DateString = ReadDateString();

    sDate Date = ConvertStringToDate(DateString);

    cout << "\nThe Date Is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    PrintStringDate(Date);

    return 0;
}