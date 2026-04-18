/*

Project 2: ATM System Console Application

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
void Login();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

enum enMainMenue
{
    eQuickWithdrawal = 1,
    eNormalWithdrawal = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};

enum enQuickWithdrawal
{
    eQW20 = 1,
    eQW50 = 2,
    eQW100 = 3,
    eQW200 = 4,
    eQw400 = 5,
    eQW600 = 6,
    eQW800 = 7,
    eQW1000 = 8,
    eQWOther = 9,
    eQWExit = 10
};

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, vector<sClient> vClients, sClient &Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

//---------------------------------------------
// Main Menue Functions 
//---------------------------------------------

void ShowQuickWithdrawalScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tQuick Withdraw Screen";
    cout << "\n-----------------------------------\n";

}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

}

void ShowTotalBalancesScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tTotal Balances Screen";
    cout << "\n-----------------------------------\n";

    cout << "Total Balances = " << ShowTotalBalane<< endl;

}

//----------------------------------------------
short ReadMainMenueOption()
{
    short Choice;

    cout << "Please Choose What Do You Want To Do? [1 to 5]: ";
    cin >> Choice;

    return Choice;
}
enMainMenue PerfromMainMenueOption(enMainMenue MainMenueOption)
{
    switch (MainMenueOption)
    {

    case eQuickWithdrawal:
        ShowQuickWithdrawalScreen();
        break;


    case eNormalWithdrawal:
        ShowWithDrawScreen();
        break;


    case eDeposit:
        ShowDepositScreen();
        break;


    case eCheckBalance:
        ShowTotalBalancesScreen();
        break;

    case eLogout:
         Login();
         break;

    default:
    
        cout << "Invalid Option, Please Try Again.\n";
        break;
    
    }
}
void ShowMainMenue()
{
    system("clear");

    cout << "===========================================\n";
    cout << "\t\tATM Main Menue\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdrawal.\n";
    cout << "\t[2] Normal Withdrawal.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";

    PerfromMainMenueOption((enMainMenue)ReadMainMenueOption());
}

bool LoadUserInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode))
        return true;

    else

        return false;
}


void Login()
{
    bool LoginFaild = false;
    string AccountNumber, PinCode;

    do
    {
        system("clear");
        cout << "===========================================\n";
        cout << "\t\tLogin Screen\n";
        cout << "===========================================\n";


        if (LoginFaild)
        {

            cout << "Invalid Username/Password!\n";
        }

        cout << "Enter Your Account Number: ";
        cin >> AccountNumber;

        cout << "Enter Pin Code: ";
        cin >> PinCode;

        LoginFaild = !LoadUserInfo(AccountNumber, PinCode);
        
    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    Login();

    return 0;
}