
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct stUser
{
    string UserName;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
};


enum enTransactionsMenueOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenue = 4
};


enum enManageUsersMenueOptions
{
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenue = 6
};


enum enMainMenueOptions
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eShowTransactionsMenue = 6,
    eManageUsers = 7,
    eExit = 8
};


enum enMainMenuePermissions
{
    eAll = -1,
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClients = 8,
    pFindClient = 16,
    pTranactions = 32,
    pManageUsers = 64
};

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";


stUser CurrentUser;
void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersMenue();
bool CheckAccessPermission(enMainMenuePermissions Permission);
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


vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; 


    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stUser ConvertUserLinetoRecord(string Line, string Seperator =
                                                "#//#")
{
    stUser User;
    vector<string> vUserData;
    vUserData = SplitString(Line, Seperator);
    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;
}
sClient ConvertLinetoRecord(string Line, string Seperator =
                                             "#//#")
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

stUser ConvertUserLinetoRecord2(string Line, string Seperator =
                                                 "#//#")
{
    stUser User;
    vector<string> vUserData;
    vUserData = SplitString(Line, Seperator);
    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);
    return User;
}
string ConvertRecordToLine(sClient Client, string Seperator =
                                               "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
string ConvertUserRecordToLine(stUser User, string Seperator =
                                                "#//#")
{
    string stClientRecord = "";
    stClientRecord += User.UserName + Seperator;
    stClientRecord += User.Password + Seperator;
    stClientRecord += to_string(User.Permissions);
    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string
                                                           FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return false;
}

bool UserExistsByUsername(string Username, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode
    if (MyFile.is_open())
    {
        string Line;
        stUser User;
        while (getline(MyFile, Line))
        {
            User = ConvertUserLinetoRecord(Line);
            if (User.UserName == Username)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}
sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);
    while (ClientExistsByAccountNumber(Client.AccountNumber,
                                       ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists,Enter another Account Number ? ";
            getline(cin >> ws, Client.AccountNumber);
    }
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}
int ReadPermissionsToSet()
{
    int Permissions = 0;
    char Answer = 'n';
    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";
    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pListClients;
    }
    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pAddNewClient;
    }
    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pDeleteClient;
    }
    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pUpdateClients;
    }
    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pFindClient;
    }
    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pManageUsers;
    }
    return Permissions;
}
stUser ReadNewUser()
{
    stUser User;
    cout << "Enter Username? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, User.UserName);
    while (UserExistsByUsername(User.UserName, UsersFileName))
    {
        cout << "\nUser with [" << User.UserName << "] already exists,Enter another Username ? ";
            getline(cin >> ws, User.UserName);
    }
    cout << "Enter Password? ";
    getline(cin, User.Password);
    User.Permissions = ReadPermissionsToSet();
    return User;
}

