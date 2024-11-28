#include "Account.h"

Account::Account() {}

Account::Account(string user, string pass, string name, string phone)
    : username(user), password(pass), name(name), phoneNumber(phone) {}

// kiem tra tai khoan ton tai
bool Account::accountExists(const string& filename, const string& user) {
    ifstream file(filename);
    string u, p, name, phone;
    while (getline(file, u, ',') && getline(file, p, ',') && getline(file, name, ',') && getline(file, phone)) {
        if (u == user) return true;
    }
    return false;
}

// luu tai khoan vao file
void Account::saveAccount(const string& filename) const {
    ofstream file(filename, ios::app);
    file << username << "," << password << "," << name << "," << phoneNumber << endl;
}

// lay thong tin nguoi dung
bool Account::getUserInfo(const string &filename, const string &user, const string &pass, string &name) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    string u, p, n, phone;
    while (getline(file, u, ',') && getline(file, p, ',') && getline(file, n, ',') && getline(file, phone)) {
        if (u == user && p == pass) {
            name = n;
            return true;
        }
    }
    return false;
}

bool Account::isAdminUser(const string& username, const string& filename) {
    ifstream file(filename);
    string u, pass, name, phone;

    while (getline(file, u, ',') && getline(file, pass, ',') && getline(file, name, ',') && getline(file, phone)) {
        if (u == username) {
            return true;
        }
    }

    return false;
}

