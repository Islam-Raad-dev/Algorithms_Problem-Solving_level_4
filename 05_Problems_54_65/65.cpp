/*

Formate Date

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

vector<string> SplitString(string str, string Delimiter)
{
    vector<string> vString;

    string word = "";
    for (char x : str)
    {
        if (x == Delimiter[0])  
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
    
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string FormateDate(sDate Date)
{
    sDate FormatedDate;

    FormatedDate.Day = Date.Day;
    FormatedDate.Month = Date.Month;
    FormatedDate.Year = Date.Year;

    return FormatedDate;
}

int main()
{

    string DateString = ReadDateString("Please Enter A Date (DD/MM/YYYY): ");
    sDate Date = StringToDateSturctur(DateString);

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date) << endl;


    return 0;
}