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

vector<string> SplitString(string str, char Delimiter)
{
    vector<string> vString;

    string word = "";
    for (auto x : str)
    {
        if (x == Delimiter)
        {
            vString.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    vString.push_back(word);

    return vString;
}

sDate StringToDateSturctur(string DateString)
{
    sDate Date;

    vector <string> vDate;
    
    vDate = SplitString(DateString, '/');
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

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