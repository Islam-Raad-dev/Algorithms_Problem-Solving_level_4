/*

Number To Text:

*/

#include <iostream>
using namespace std;

int ReadNumber()
{

    int Number;

    cout << "Please Enter A Number: ";
    cin >> Number;

    return Number;
}

string ConvertNumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Two", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thieteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eightteen", "Nineteen"};

        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifnty", "Sixnty", "Seventy", "Eightty", "Ninety"};

        return arr[Number / 10] + " " + ConvertNumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {

        return "One Hundred " + ConvertNumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return ConvertNumberToText(Number / 1000) + "Thousand " + ConvertNumberToText(Number % 1000);
    }

    if (Number >= 200 && Number <= 999)
    {
        return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
    }
}
int main()
{
    int Number = ReadNumber();

    cout << ConvertNumberToText(Number) << endl;

    return 0;
}