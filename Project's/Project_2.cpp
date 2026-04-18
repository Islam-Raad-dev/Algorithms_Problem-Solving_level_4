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

void ShowMainMenue();
void GoBackToMainMenue();
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
    eQWExit = 9
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

short ReadQuickWithdrawalOption()
{
    short Choice;

    cout << "Please Choose Quick Withdrawal Amount? [1 to 9]: ";
    cin >> Choice;

    return Choice;
}

//---------------------------------------------
// Main Menue Functions 
//---------------------------------------------

enQuickWithdrawal PerfromQuickWithdrawalOption(enQuickWithdrawal QuickWithdrawalOption)
{
    switch (QuickWithdrawalOption)
    {
    case enQuickWithdrawal::eQW20:
        break;

    case enQuickWithdrawal::eQW50:
        break;

    case enQuickWithdrawal::eQW100:
        break;

    case enQuickWithdrawal::eQW200:
        break;

    case enQuickWithdrawal::eQw400:
        break;

    case enQuickWithdrawal::eQW600:
        break;

    case enQuickWithdrawal::eQW800:
        break;

    case enQuickWithdrawal::eQW1000:
        break;

    case enQuickWithdrawal::eQWExit:
        break;

    default:    
        cout << "Invalid Option, Please Try Again.\n";
        break;
    }
}

void ShowQuickWithdrawalScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tQuick Withdraw Screen";
    cout << "\n-----------------------------------\n";

    cout << "\t[1] 20\n";
    cout << "\t[2] 50\n";
    cout << "\t[3] 100\n";
    cout << "\t[4] 200\n";
    cout << "\t[5] 400\n";
    cout << "\t[6] 600\n";
    cout << "\t[7] 800\n";
    cout << "\t[8] 1000\n";
    cout << "\t[9] Exit\n";

    PerfromQuickWithdrawalOption((enQuickWithdrawal)ReadQuickWithdrawalOption());

}

void ShowDepositScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

}

void ShowWithDrawScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

}

void ShowTotalBalancesScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tTotal Balances Screen";
    cout << "\n-----------------------------------\n";

    cout << "Total Balances = " << ShowTotalBalane<< endl;

}

void GoBackToMainMenue()
{
    cout << "\n\nPress Enter to go back to Main Menue...";
    cin.ignore();
    cin.get();

    ShowMainMenue();
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
        GoBackToMainMenue();
        break;


    case eNormalWithdrawal:
        ShowWithDrawScreen();
        GoBackToMainMenue();
        break;


    case eDeposit:
        ShowDepositScreen();
        GoBackToMainMenue();
        break;


    case eCheckBalance:
        ShowTotalBalancesScreen();
        GoBackToMainMenue();
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

bool LoadClientInfo(string AccountNumber, string PinCode)
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

            cout << "Invalid Account Number/Pin Code!\n";
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