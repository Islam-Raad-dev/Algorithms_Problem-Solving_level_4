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
void ShowQuickWithdrawalScreen();
void ShowDepositScreen();
void ShowNormalWithdrawalScreen();
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

sClient CurrentClient;

enum enMainMenue
{
    eQuickWithdrawal = 1,
    eNormalWithdrawal = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};


vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "") vString.push_back(sWord);

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "") vString.push_back(S1);

    return vString;
}

// تحويل سطر نصي إلى سجل مستخدم
string Trim(string s)
{
    static const string whitespaces = " \t\r\n\f\v";
    size_t first = s.find_first_not_of(whitespaces);
    if (string::npos == first) return "";
    size_t last = s.find_last_not_of(whitespaces);
    return s.substr(first, (last - first + 1));
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

vector<sClient> LoadCleintsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vClients.push_back(ConvertLinetoRecord(Line));
        }
        MyFile.close();
    }

    return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient &Client)
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

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

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

short ReadQuickWithdrawalOption()
{
    short Choice;

    while (Choice < 1 || Choice > 9)
    {
        cout << "Please Choose Quick Withdrawal Amount? [1 to 9]: ";
        cin >> Choice;
    }

    return Choice;
}

//---------------------------------------------
// Main Menue Functions 
//---------------------------------------------

short GetQuickWithdrawalOption(short QuickWithdrawalOption)
{
    switch (QuickWithdrawalOption)
    {
    case 1:
        return 20;

    case 2:
        return 50;

    case 3:
        return 100;

    case 4:
        return 200;

    case 5:
        return 400;

    case 6:
        return 600;

    case 7:
        return 800;

    case 8:
        return 1000;

    default:
        return 0;
    }
}   

vector<sClient> DipositBalanceToClientByAccountNumber(string AccountNumber, double Balance, vector<sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.AccountBalance += Balance;
            return vClients;
        }
    }

    return vClients;
}
void PerfromQuickWithdrawalOption(short ReadQuickWithdrawalOption)
{
    if(ReadQuickWithdrawalOption == 9)
    {
        return;
    }

    short WithdrawBalance = GetQuickWithdrawalOption(ReadQuickWithdrawalOption);

    if(WithdrawBalance > CurrentClient.AccountBalance)
    {
        cout << "Sorry, You Don't Have Enough Balance.\n";

        cout << "\n\nPress Enter to go back to Main Menue...";
        cin.ignore();
        cin.get();


        ShowQuickWithdrawalScreen();
        return;
    }

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    DipositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawBalance * -1, vClients);

    CurrentClient.AccountBalance -= WithdrawBalance;

    
}

void ShowQuickWithdrawalScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tQuick Withdraw Screen";
    cout << "\n-----------------------------------\n";

    cout << "\t[1] 20\n \t[2] 50\n";
    cout << "\t[3] 100\n \t[4] 200\n";
    cout << "\t[5] 400\n \t[6] 600\n";
    cout << "\t[7] 800\n \t[8] 1000\n";
    cout << "\t[9] Exit\n";

    cout << "------------------------------------\n";

    cout << "Your Current Balance is: " << CurrentClient.AccountBalance << endl;

    PerfromQuickWithdrawalOption(ReadQuickWithdrawalOption());

}

void ShowDepositScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

}

void ShowNormalWithdrawalScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

}

void ShowCheckBalancesScreen()
{
    system("clear");

    cout << "\n-----------------------------------\n";
    cout << "\tCheck Balances Screen";
    cout << "\n-----------------------------------\n";

    cout << "Total Balances = " << CurrentClient.AccountBalance << endl;

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
        ShowNormalWithdrawalScreen();
        GoBackToMainMenue();
        break;


    case eDeposit:
        ShowDepositScreen();
        GoBackToMainMenue();
        break;


    case eCheckBalance:
        ShowCheckBalancesScreen();
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
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
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

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);
        
    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    Login();

    return 0;
}