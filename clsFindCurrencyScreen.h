#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:

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
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t\tFind Currency Screen");

		short Answer;

		cout << "Find by: [1] Code or [2] Country name ? ";
		Answer = clsInputValidate::ReadIntNumberBetween(1, 2,"\nChoose [1] Code OR [2] Country Name");

		if (Answer == 1)
		{
			string CurrencyCode;

			cout << "\nPlease enter currency code : ";
			cin >> CurrencyCode;

			clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency1);
		}
		else
		{

			string CountryName;

			cout << "\nPlease enter Country name: ";
			cin >> CountryName;

			clsCurrency Currency1 = clsCurrency::FindByCountry(CountryName);

			_ShowResults(Currency1);

		}
	}
};

