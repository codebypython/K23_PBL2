#pragma once
#define USERMANAGER_H

#include "Account.h"
#include "FileManager.h"

#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;

class UserManager {
public:
    bool isValidUsername(const string& username);
    bool isUsernameTaken(const string& user);
    
    bool isValidPassword(const string& password);
    string inputPassword();

    bool isValidName(const string& name);
    
    bool isValidPhone(const string& phone);
    bool isPhoneNumberTaken(const string& phone);
};