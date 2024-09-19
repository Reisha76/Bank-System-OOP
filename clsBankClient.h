#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "C:/Users/abdel/source/repos/stringLibrary/stringLibrary/clsString.h"

using namespace std;

class clsBankClient:public clsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
    bool _MarkedForDeletion = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator="#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }
            MyFile.close();
        }

        return vClients;
    }

    static string _ConvertClientObjectToLine(clsBankClient Client,string Seperator="#//#")
    {
        string ClientRecord = "";

        ClientRecord += Client.FirstName + Seperator;
        ClientRecord += Client.LastName + Seperator;
        ClientRecord += Client.Email + Seperator;
        ClientRecord += Client.Phone + Seperator;
        ClientRecord += Client.AccountNumber() + Seperator;
        ClientRecord += Client.PinCode + Seperator;
        ClientRecord += to_string(Client.AccountBalance);

        return ClientRecord;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient& C : vClients)
            {
                if (C.MarkedForDeletion() == true)
                    continue;

                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;

            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsBankClient> vClients;

        vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  DataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }

    }

    string _PrepareTransferRecord(float Amount,clsBankClient DestinationClient,string UserName,string Seperator = "#//#")
    {
        string TransferRecord = "";

        clsBankClient Sender = Find(AccountNumber());
        
        TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferRecord += AccountNumber() + Seperator;
        TransferRecord += DestinationClient.AccountNumber() + Seperator;
        TransferRecord += to_string(Amount) + Seperator;
        TransferRecord += to_string(AccountBalance) + Seperator;
        TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferRecord += UserName;

        return TransferRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferRecord(Amount, DestinationClient, UserName);

        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    struct stTransferLogRecord;


    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;

        vector <string> vTransferLogRecordLine = clsString::Split(Line, Seperator);
        TransferLogRecord.DateTime = vTransferLogRecordLine[0];
        TransferLogRecord.SourceAccountNumber = vTransferLogRecordLine[1];
        TransferLogRecord.DestinationAccountNumber = vTransferLogRecordLine[2];
        TransferLogRecord.Amount = stod(vTransferLogRecordLine[3]);
        TransferLogRecord.srcBalanceAfter = stod(vTransferLogRecordLine[4]);
        TransferLogRecord.destBalanceAfter = stod(vTransferLogRecordLine[5]);
        TransferLogRecord.UserName = vTransferLogRecordLine[6];

        return TransferLogRecord;

    }

public:

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;
    };

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
        _AccountNumber = AccountNumber;
		_Mode = Mode;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeletion()
    {
        return _MarkedForDeletion;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }*/

    static clsBankClient Find(string AccountNumber)
    {
        //vector <clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);//read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                //vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector <clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);//read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    enum enSaveResults{svFailedEmptyObject=0,svSucceeded=1,svFailedAccountNumberExists=2};

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
            
            return enSaveResults::svFailedEmptyObject;
            break;

        case clsBankClient::UpdateMode:
            
            _Update();
            return enSaveResults::svSucceeded;
            break;

        case clsBankClient::AddNewMode:

            if (clsBankClient::IsClientExist(_AccountNumber))//check if accNum already exists in file
                return enSaveResults::svFailedAccountNumberExists;
            else
            {
                _AddNew();
                _Mode = UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
    }

    static clsBankClient GetAddNewObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClients;
        vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == this->AccountNumber())
            {
                C._MarkedForDeletion = true;
                break;
            }
            
        }
        _SaveClientsDataToFile(vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName)
    {
        if (Amount > DestinationClient.AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        
        _RegisterTransferLog(Amount, DestinationClient, UserName);

    
        return true;
    }

    static vector <stTransferLogRecord> GetTransferLogList()
    {
    
        vector <stTransferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTransferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;


    }

};

