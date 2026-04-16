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

string ReadDateString(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);

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
    string DateString = ReadDateString("\nPlease Enter A Date dd/mm/yyyy: ");

    sDate Date = ConvertStringToDate(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;


    cout << "You Entered :";
    PrintStringDate(Date);

    return 0;
}