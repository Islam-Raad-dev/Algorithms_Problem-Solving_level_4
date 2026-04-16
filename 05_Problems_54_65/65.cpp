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

string ReplaceWordInString(string S1, string WordToReplace, string ReplaceTo)
{
    short pos = S1.find(WordToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, WordToReplace.length(), ReplaceTo);
        pos = S1.find(WordToReplace);

    }
    return S1;
}

string FormateDate(sDate Date, string DateFormate = "DD/MM/YYYY")
{
    string FormattedDateToString = DateFormate;

    FormattedDateToString = ReplaceWordInString(DateFormate, "DD", to_string(Date.Day));

    FormattedDateToString = ReplaceWordInString(FormattedDateToString, "MM", to_string(Date.Month));
    
    FormattedDateToString = ReplaceWordInString(FormattedDateToString, "YYYY", to_string(Date.Year));

    return FormattedDateToString;
}

int main()
{

    string DateString = ReadDateString("Please Enter A Date (DD/MM/YYYY): ");

    sDate Date = StringToDateSturctur(DateString);

    cout << "\n" << FormateDate(Date) << endl;

    cout << "\n" << FormateDate(Date, "MM/DD/YYYY") << endl;

    cout << "\n" << FormateDate(Date, "YYYY/MM/DD") << endl;

    cout << "\n" << FormateDate(Date, "DD-MM-YYYY") << endl;

    cout << "\n" << FormateDate(Date, "MM-DD-YYYY") << endl;

    cout << "\n" << FormateDate(Date, "YYYY-MM-DD") << endl;


    return 0;
}