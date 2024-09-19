# Bank Management System (Object-Oriented Programming)

## Overview
This project is a **Bank Management System** built using Object-Oriented Programming (OOP) principles. The system allows managing bank clients, users, currencies, and transactions in a structured and modular way. It includes functionalities such as adding and deleting clients, handling deposits, withdrawals, and currency exchanges. The project is organized across multiple header and source files for better maintainability and extensibility.

## Features
- **Client Management**: Add, update, find, and delete clients.
- **User Management**: Add, update, find, and delete system users.
- **Currency Management**: View, find, and update currency rates.
- **Transactions**: Manage deposits, withdrawals, transfers, and view transaction logs.
- **Security**: Login and register system with user validation.

## File Structure

### Screens and User Interfaces

- **clsAddNewClientScreen.h**: Handles the UI for adding new clients.
- **clsAddNewUserScreen.h**: Manages the UI for adding new system users.
- **clsClientListScreen.h**: Displays a list of clients in the system.
- **clsCurrenciesListScreen.h**: Handles the listing of available currencies.
- **clsCurrencyCalculatorScreen.h**: Provides a UI for currency conversion.
- **clsDeleteClientScreen.h**: Manages the UI for deleting a client.
- **clsDeleteUserScreen.h**: Manages the UI for deleting a user.
- **clsDepositScreen.h**: UI for processing client deposits.
- **clsFindClientScreen.h**: UI for searching for clients.
- **clsFindCurrencyScreen.h**: UI for searching for currencies.
- **clsFindUserScreen.h**: UI for searching for system users.
- **clsListUsersScreen.h**: UI for listing system users.
- **clsLoginRegisterScreen.h**: UI for user login and registration management.
- **clsLoginScreen.h**: UI for the login process.
- **clsMainScreen.h**: The main UI for navigating through the system’s features.
- **clsManageUsersScreen.h**: UI for managing users (adding, updating, deleting).
- **clsTotalBalancesScreen.h**: Displays the total balance across all clients.
- **clsTransactionsScreen.h**: UI for managing client transactions.
- **clsTransferLogScreen.h**: UI for viewing transfer logs.
- **clsTransferScreen.h**: UI for processing money transfers between clients.
- **clsUpdateClientScreen.h**: UI for updating client information.
- **clsUpdateCurrencyRateScreen.h**: UI for updating the currency exchange rates.
- **clsUpdateUserScreen.h**: UI for updating user information.
- **clsWithdrawScreen.h**: UI for processing withdrawals.

### Core Functionalities

- **clsBankClient.h**: Defines the `clsBankClient` class to handle client data and related operations.
- **clsCurrency.h**: Defines the `clsCurrency` class, handling currency-related data and functions.
- **clsPerson.h**: Base class for managing shared attributes between users and clients.
- **clsUser.h**: Defines the `clsUser` class to manage system users.

### Utilities and Helpers

- **clsInputValidate.h**: Handles input validation across the system.
- **clsString.h**: Utility for handling string-related operations.
- **clsDate.h**: Utility class for managing dates.
- **clsUtil.h**: Contains general utility functions used throughout the system.

### System and Global

- **clsScreen.h**: Base class for managing screen-related functionality.
- **Global.h**: Defines global variables and constants used across the system.

### Logs and Data Files

- **Currencies.txt**: Stores information about available currencies.
- **Clients.txt**: Stores client data.
- **LoginRegister.txt**: Stores login and registration information.
- **TransferLog.txt**: Stores transaction log data.
- **Users.txt**: Stores user data.

### Main Source File

- **BankOOP.cpp**: Main source file that initiates and runs the system.

## How to Run
1. Clone the repository.
2. Open the project in a C++ development environment.
3. Compile and run the `BankOOP.cpp` file.
4. Follow the on-screen instructions to navigate through the banking system.

## Contributions
Feel free to contribute to this project by forking the repository and creating pull requests.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
