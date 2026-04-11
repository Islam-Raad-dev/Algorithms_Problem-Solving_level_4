/*

Leap Year


*/
#include <iostream>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "Please Enter A Year: ";
    cin >> Year;

    return Year;
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

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << Year << " Is A Leap Year.\n";
    }
    else
    {
        cout << Year << " Is Not A Leap Year.\n";
    }

    return 0;
}