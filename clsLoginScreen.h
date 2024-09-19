#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include <fstream>
#include "clsUtil.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short loginCounter = 0;

        do
        {
            if (LoginFaild)
            {


                loginCounter++;
                cout << "\nInvalid Username/Password!\n";
                cout << "You have " << 3 - loginCounter << "  trial(s) to login.\n\n";

                if (loginCounter == 3)
                {
                    cout << "\nSYSTEM LOCKED: 3 failed logins\n";
                    return false;
                }

            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, clsUtil::DecryptText(Password));

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

