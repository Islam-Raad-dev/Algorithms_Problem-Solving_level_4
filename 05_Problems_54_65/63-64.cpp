/*

Read / Print Date String

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

string ReadDateString(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
}

sDate StringToDateSturctur(string DateString)
{
    sDate Date;

    vector

    Date.Day = stoi(DateString.substr(0, 2));
    Date.Month = stoi(DateString.substr(3, 2));
    Date.Year = stoi(DateString.substr(6, 4));

    return Date;
}

void DateToString(sDate Date)
{
    cout << "\nThe Date Is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{
    string DateString = ReadDateString("\nPlease Enter A Date dd/mm/yyyy: ");

    sDate Date = StringToDateSturctur(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;


    cout << "You Entered :";
    DateToString(Date);

    return 0;
}