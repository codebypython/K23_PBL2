#pragma once
#define ACCOUNTMANAGER_H

#include "Account.h"
#include "Manager.h"
#include "Customer.h"
#include "Menu.h"
#include "Vector.h"
#include "FileManager.h"
#include "UserManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>

class AccountManager {
public:
    void registerAccount(const string& filename, const string& accountType);
    void login();

    void resetPassword(const string& filename);
    
    bool isdeleteAccount(const string& filename, const string& username);
    void deleteAccount(const string& username);
    void viewCustomerList();

    void changePhoneNumber(const string& filename, const string& username);
    void changePassword(const string& filename, const string& username);
};
