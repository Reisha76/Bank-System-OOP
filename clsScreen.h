#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std; 
class clsScreen
{

protected:
	
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << endl<<endl;
        
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            PrintAccessDeniedScreen();
            return false;
        }
        else
            return true;
    }

    static void PrintAccessDeniedScreen()
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
        cout << "\n\t\t\t\t\t______________________________________\n\n";

    }

};

