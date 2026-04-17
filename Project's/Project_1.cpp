/*

Bank System Project 3

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string UserFileName = "Users.txt";


void ShowMainMenu();
void ShowTransactionScreen();
void ShowLoginScreen();

enum enMainMenuOptions
{
    eShow = 1,
    eAdd = 2,
    eDelete = 3,
    eUpdate = 4,
    eFind = 5,
    eTransaction = 6,
    eMangeUsers = 7,
    eLogout = 8

};

enum enTransactionOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eShowToMainMenu = 4
};

enum enManageUsersOptions
{
    eListUsers = 1,
    eAddUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eBackToMainMenu = 6
};

enum enUserPermissions
{
    eTransactions = 1,
    eManageUsers = 2
};

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

struct cUserInfo
{
    string UserName;
    string Password;
    enUserPermissions Permissions;
};


//-------------------------------



vector<string> SplitString(string S1, string delim)
{
    vector<string> vString;
    short pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "") 
        {
            vString.push_back(sword);
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

sClientInfo ConvertLineDataToRecord(string Line, string Seperator = "#//#")
{
    sClientInfo Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.FullName = vClientData[2];
        Client.PhoneNumber = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }
    return Client;
}

string ConvertRecordToLine(sClientInfo Clint, string Sepreator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Clint.AccountNumber + Sepreator;
    stClientRecord += Clint.PinCode + Sepreator;
    stClientRecord += Clint.FullName + Sepreator;
    stClientRecord += Clint.PhoneNumber + Sepreator;
    stClientRecord += to_string(Clint.AccountBalance);
    return stClientRecord;
}

// --- Data Access Functions ---

vector<sClientInfo> LoadDataFromFile(string FileName)
{
    vector<sClientInfo> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            if (Line != "")
            {
                sClientInfo Client = ConvertLineDataToRecord(Line);
                vClients.push_back(Client);
            }
        }
        MyFile.close();
    }
    return vClients;
}

void AddClientToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

vector<sClientInfo> SaveClientDataToFile(string FileName, vector<sClientInfo> &vClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;

    if (MyFile.is_open())
    {
        for (sClientInfo &C : vClient)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClient;
}

// --- Search & Validation ---

bool ClientExistByAccountNumber(string AccountNumber, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClientInfo Cleint;
        while (getline(MyFile, Line))
        {
            Cleint = ConvertLineDataToRecord(Line);
            if (Cleint.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClientInfo> &vClients, sClientInfo &Client)
{
    for (sClientInfo &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool FindUserByNameAndPassword(string UserName, string Password, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        vector<string> vUserData;
        while (getline(MyFile, Line))
        {
            vUserData = SplitString(Line, "#//#");
            if (vUserData.size() >= 2)
            {
                if (vUserData[0] == UserName && vUserData[1] == Password)
                {
                    MyFile.close();
                    return true;
                }
            }
        }
        MyFile.close();
    }
    return false;
}

bool MarkClintForDeleteByAccountNumber(string AccountNumber, vector<sClientInfo> &vClient)
{
    for (sClientInfo &C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

// --- UI Display Helpers ---

void PrintClientRecordLine(sClientInfo Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.FullName;
    cout << "| " << setw(12) << left << Client.PhoneNumber;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientCard(sClientInfo Client)
{
    cout << "\n-----------------------------------------------\n";
    cout << "\nThe Following is The Clint Recoed:\n";
    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPINCODE          : " << Client.PinCode;
    cout << "\nFull Name        : " << Client.FullName;
    cout << "\nPhone Number     : " << Client.PhoneNumber;
    cout << "\nAccount Blalance : " << Client.AccountBalance;
    cout << "\n";
    cout << "\n-----------------------------------------------\n";
}

// --- Input Reading Functions ---

string ReadClientAccountNumber()
{
    string AccountNumber;
    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

sClientInfo ReadNewClient()
{
    sClientInfo Client;
    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient With[" << Client.AccountNumber << "] Already Exists, Enter Andoter Account Number: ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "\nEnter Your PINCODE: ";
    getline(cin, Client.PinCode);
    cout << "\nEnter Your Full Name: ";
    getline(cin, Client.FullName);
    cout << "\nEnter Your Phone Number: ";
    getline(cin, Client.PhoneNumber);
    cout << "\nEnter Your Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

void AddNewUserScreen(){
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tAdd New User";
    cout << "\n-----------------------------------------------\n";
}
cUserInfo ReadNewUserInfo()
{
    AddNewUserScreen();
    cUserInfo User;
    char FullAccess = 'Y';

    cout << "Enter User Name: ";
    getline(cin >> ws, User.UserName);
    cout << "Enter Password: ";
    getline(cin, User.Password);

    cout << "\nDo you want To Give This User Full Accese ? (Y/N):";
        cin >> FullAccess;
          
    while (toupper(FullAccess) == 'Y');
    return User;

}
// --- Core Business Logic ---

void AddNewClients()
{
    sClientInfo Client;
    Client = ReadNewClient();
    AddClientToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClient()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:\n\n";
        AddNewClients();
        cout << "\nClirnt Added Successfuly, do you want To Add More Clients? (Y/N):";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

sClientInfo ChanceClintRecord(string AccountNumber)
{
    sClientInfo Client;
    Client.AccountNumber = AccountNumber;
    cout << "\nEnter Your PINCODE: ";
    getline(cin >> ws, Client.PinCode);
    cout << "\nEnter Your Full Name: ";
    getline(cin, Client.FullName);
    cout << "\nEnter Your Phone Number: ";
    getline(cin, Client.PhoneNumber);
    cout << "\nEnter Your Account Balance: ";
    cin >> Client.AccountBalance;
    return Client;
}

bool DeleteClintByAccountNumber(string AccountNumber, vector<sClientInfo> &vClients)
{
    sClientInfo Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\nAre you sure you want to delete this client? (Y/N): ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            MarkClintForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientDataToFile(ClientsFileName, vClients);
            vClients = LoadDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] was NOT found.\n";
    }
    return false;
}

bool UpdateClintByAccountNumber(string AccountNumber, vector<sClientInfo> &vClient)
{
    sClientInfo Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {
        PrintClientCard(Client);
        cout << "\nAre You Sure That You Want To Update This Client? (Y/N)";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClientInfo &C : vClient)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChanceClintRecord(AccountNumber);
                    break;
                }
            }
            SaveClientDataToFile(ClientsFileName, vClient);
            vClient = LoadDataFromFile(ClientsFileName);
            cout << "\n\nCleint Updated Succesfuly.\n";
            return true;
        }
    }
    else
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
    }
    return false;
}

bool DipositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClientInfo> &vCleint)
{
    char Answer = 'n';
    cout << "\nAre You Sure That You Want To Do That [" << Amount << "] To This Client? (Y/N)";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        for (sClientInfo &C : vCleint)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveClientDataToFile(ClientsFileName, vCleint);
                cout << "Done Successfuly, New Balance is: " << C.AccountBalance << endl;
                return true;
            }
        }
    }
    return false;
}

// --- Screen Flow Controls ---

void GoBackToMainMenu()
{
    cout << "\n\nPress Enter to return to Main Menu...";
    cin.ignore(100, '\n');
    cin.get();
}

void GoBackToTransactionMenu()
{
    cout << "\n\nPress Enter to return to Transaction Menu...";
    cin.ignore(100, '\n');
    cin.get();
}

// --- Specific Screen Displays ---

void ShowAllClientScreen()
{
    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\tClient List [" << vClients.size() << "] Client(s).";
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Client Available In The System!";
    else
        for (sClientInfo &Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    cout << "____________________________________________________________________________________________________\n"
         << endl;
}

void ShowAddNewClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tAdd New Client Screen";
    cout << "\n-----------------------------------------------\n";
    AddNewClient();
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------------------\n";
    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClintByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-----------------------------------------------\n";
    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    string AccountName = ReadClientAccountNumber();
    UpdateClintByAccountNumber(AccountName, vCleint);
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------------------\n";
    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    sClientInfo Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vCleint, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
    }
}

void ShowDepositScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------------------\n";
    sClientInfo Cleint;
    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    while (!FindClientByAccountNumber(AccountNumber, vCleint, Cleint))
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(Cleint);
    double Amount = 0;
    cout << "Please Enter Amount To Deposit: ";
    cin >> Amount;
    DipositBalanceToClientByAccountNumber(AccountNumber, Amount, vCleint);
}

void ShowWithdrawScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------------------\n";
    sClientInfo Cleint;
    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    while (!FindClientByAccountNumber(AccountNumber, vCleint, Cleint))
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
        AccountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(Cleint);
    double Amount = 0;
    cout << "\nPlease Enter Amount To Withdraw: ";
    cin >> Amount;
    while (Amount > Cleint.AccountBalance)
    {
        cout << "Amount Exceeds The Balance , You Can Withdraw Up To: " << Cleint.AccountBalance;
        cout << "\nPlease Enter Another Amount: ";
        cin >> Amount;
    }
    DipositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vCleint);
}

void ShowTotalBalance()
{

    system("clear");
    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    cout << "\t\t\t\t Balance List [" << vCleint.size() << "] Client(s).";
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;

    double TotalBalance = 0;
    if (vCleint.size() == 0)
        cout << "\t\t\t\tNo Client Available In The System!";
    else
    {
        for (sClientInfo &C : vCleint)
        {
            cout << "| " << setw(15) << left << C.AccountNumber;
            cout << "| " << setw(40) << left << C.FullName;
            cout << "| " << setw(12) << left << C.AccountBalance << endl;
            TotalBalance += C.AccountBalance;
        }
    }
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;
    cout << "\t\t\t\t\t\t\tTotal Balance: " << TotalBalance;
}

void ShowTotalBalanceScreen()
{
    ShowTotalBalance();
}

void ShowLoginScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n-----------------------------------------------\n";
}

void ShowListUsersScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tList Users Screen";
    cout << "\n-----------------------------------------------\n";
}

void ShowAddUserScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tAdd User Screen";
    cout << "\n-----------------------------------------------\n";
}

void ShowDeleteUserScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n-----------------------------------------------\n";
}

void ShowUpdateUserScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tUpdate User Screen";
    cout << "\n-----------------------------------------------\n";
}

void ShowFindUserScreen()
{
    system("clear");
    cout << "\n-----------------------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------------------\n";
}

void GoBackToMangeUsersMenu()
{
    cout << "\n\nPress Enter to return to Mange Users Menu...";
    cin.ignore(100, '\n');
    cin.get();
}


// --- Transaction Menu Logic ---

short ReadTransactionMenuOption()
{
    short Choose;
    cout << "Enter Your Choose [1 - 4]: ";
    cin >> Choose;
    return Choose;
}

void PerformTransactionMenuOption(enTransactionOptions TransactionOptions)
{
    switch (TransactionOptions)
    {
    case enTransactionOptions::eDeposit:
        ShowDepositScreen();
        GoBackToTransactionMenu();
        break;


    case enTransactionOptions::eWithdraw:
        ShowWithdrawScreen();
        GoBackToTransactionMenu();
        break;


    case enTransactionOptions::eTotalBalance:
        ShowTotalBalanceScreen();
        GoBackToTransactionMenu();
        break;


    case enTransactionOptions::eShowToMainMenu:
        break;


    default:
        cout << "Invalid Choose, Try Again.";
        break;
    }
}

void ShowTransactionScreen()
{
    enTransactionOptions Choice;
    do
    {
        system("clear");
        cout << "\n-----------------------------------------------\n";
        cout << "\tTransaction Screen";
        cout << "\n-----------------------------------------------\n";
        cout << "\t[1] Deposit.\n";
        cout << "\t[2] Withdraw.\n";
        cout << "\t[3] Total Balance.\n";
        cout << "\t[4] Back To Main Menu.\n";
        cout << "\n-----------------------------------------------\n";
        Choice = (enTransactionOptions)ReadTransactionMenuOption();
        if (Choice == enTransactionOptions::eShowToMainMenu)
            break;
        PerformTransactionMenuOption(Choice);
    } while (Choice != enTransactionOptions::eShowToMainMenu);
}



// --- Mange User Menu Logic ---

short ReadMangeUsersMenuOption()
{
    short Choose;
    cout << "Enter Your Choose [1 - 6]: ";
    cin >> Choose;
    return Choose;
}

void PerformMangeUsersMenuOption(enManageUsersOptions MangeUsersOptions)
{
    switch (MangeUsersOptions)
    {
    case enManageUsersOptions::eListUsers:
        ShowListUsersScreen();
        GoBackToMangeUsersMenu();
        break;

    case enManageUsersOptions::eAddUser:
        ShowAddUserScreen();
        GoBackToMangeUsersMenu();
        break;

    case enManageUsersOptions::eDeleteUser:
        ShowDeleteUserScreen();
        GoBackToMangeUsersMenu();
        break;

    case enManageUsersOptions::eUpdateUser:
        ShowUpdateUserScreen();
        GoBackToMangeUsersMenu();
        break;


    case enManageUsersOptions::eFindUser:
        ShowFindUserScreen();
        GoBackToMangeUsersMenu();
        break;

    case enManageUsersOptions::eBackToMainMenu:
        GoBackToMangeUsersMenu();
        break;

    default:
        cout << "Invalid Choose, Try Again.";
        break;
    }
}

void ShowMangeUsersScreen()
{
        system("clear");
        cout << "\n-----------------------------------------------\n";
        cout << "\tManage Users Screen";
        cout << "\n-----------------------------------------------\n";
        cout << "\t[1] List Users.\n";
        cout << "\t[2] Add New User.\n";
        cout << "\t[3] Delete User.\n";
        cout << "\t[4] Update User Info.\n";
        cout << "\t[5] Find User.\n";
        cout << "\t[6] Main Menu.\n";
        cout << "\n-----------------------------------------------\n";
        PerformMangeUsersMenuOption((enManageUsersOptions)ReadMangeUsersMenuOption());
}

// --- Main Menu Logic ---

short ReadMainMenuOption()
{
    short Choose;
    cout << "Enter Your Choose [1 - 8]: ";
    cin >> Choose;
    return Choose;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOptions)
{
    switch (MainMenuOptions)
    {

    case enMainMenuOptions::eShow:
        system("clear");
        ShowAllClientScreen();
        GoBackToMainMenu();
        break;


    case enMainMenuOptions::eAdd:
        system("clear");
        ShowAddNewClientScreen();
        GoBackToMainMenu();
        break;


    case enMainMenuOptions::eDelete:
        system("clear");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;


    case enMainMenuOptions::eUpdate:
        system("clear");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;


    case enMainMenuOptions::eFind:
        system("clear");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;


    case enMainMenuOptions::eTransaction:
        system("clear");
        ShowTransactionScreen();
        break;


    case enMainMenuOptions::eMangeUsers:
        system("clear");
        ShowMangeUsersScreen();
        break;

    case enMainMenuOptions::eLogout:
        system("clear");
        ShowLoginScreen();
        break;


    default:
        cout << "\nInvalid Choose, Try Again.\n\n";
        break;
    }
}

void ShowMainMenu()
{
    system("clear");
    cout << "=================================================================\n";
    cout << "\t\t\tMain Menue Screen";
    cout << "\n=================================================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transaction.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.";

    cout << "\n=================================================================\n";
    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

void Login(){

}

int main()
{
    while (true)
    {
        Login();
    }
    return 0;
}