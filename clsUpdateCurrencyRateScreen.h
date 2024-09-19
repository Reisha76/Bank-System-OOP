#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{
private:

	static float _ReadRate()
	{
		float NewRate = 0;

		cout << "Enter new rate:";
		NewRate = clsInputValidate::ReadDblNumber();

		return NewRate;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency NOT Found\n";
		}
	}

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		char Answer='n';
		string CurrencyCode;

		_DrawScreenHeader("\t\t Update Currency Screen");

		cout << "Please enter currency code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, try again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency1);

		cout << "Are you sure you want to update the rate of this currency? y/n?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "Update currency rate:\n\n";
			cout << "_________________________\n\n";

			Currency1.UpdateRate(_ReadRate());

			cout << "\nCurrency rate updated successfully :)\n";
			_PrintCurrency(Currency1);
		}

	}
};

