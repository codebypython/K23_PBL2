#include "UserManager.h"

using namespace std;

// Kiem tra username hop le
bool UserManager::isValidUsername(const string& username) {
    if (username.length() < 5) {
        return false;
    }
    for (char ch : username) {
        if (!islower(ch) && !isdigit(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}

// Kiem tra username da ton tai
bool UserManager::isUsernameTaken(const string& user) {
    return Account::accountExists("tk_khachhang.txt", user) || Account::accountExists("tk_quanly.txt", user);
}

// Kiem tra password hop le
bool UserManager::isValidPassword(const string& password) {
    return password.length() >= 6;
}

// Nhap mat khau hien thi *
string UserManager::inputPassword() {
    string pass = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r') {
            cout << endl;
            break;
        } else if (ch == '\b') {
            if (!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass += ch;
            cout << "*";
        }
    }
    return pass;
}

// Kiem tra name hop le
bool UserManager::isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return !name.empty();
}

// Kiem tra phone number hop le
bool UserManager::isValidPhone(const string& phone) {
    if (phone.length() < 10 || phone.length() > 15) {
        return false;
    }
    for (char c : phone) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Kiem tra phone number da duoc su dung
bool UserManager::isPhoneNumberTaken(const string& phone) {
    FileManager fileManager;

    Vector accounts = fileManager.readAllLines("tk_khachhang.txt");
    for (size_t i = 0; i < accounts.get_size(); ++i) {
        stringstream ss(accounts[i]);
        string username, password, name, storedPhone;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, storedPhone, ',');

        if (storedPhone == phone) {
            return true;
        }
    }
    return false;
}
