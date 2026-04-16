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