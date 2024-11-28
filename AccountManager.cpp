#include "AccountManager.h"

using namespace std;

// dang ky tai khoan
void AccountManager::registerAccount(const string& filename, const string& accountType) {
    system("cls");

    UserManager userManager;
    Menu menu;
    menu.displaySignUp();

    string user, pass, name, phone;

    // Nhap username
    while (true) {
        cout << "\033[4;76H";
        cin >> user;

        if (!userManager.isValidUsername(user)) {
            cout << "\033[12;37HUSERNAME MUST BE AT LEAST 6 CHARACTERS LONG, AND CONTAIN NO SPACES OR SPECIAL CHARACTERS!" << endl;
            cout << "\033[4;76H                           " << endl;
        } else if (userManager.isUsernameTaken(user)) {
            cout << "\033[12;30H                                                                                                    " << endl;
            cout << "\033[12;60HUSERNAME ALREADY EXISTS! TRY ANOTHER ONE!" << endl;
            cout << "\033[4;76H                           " << endl;
        } else {
            cout << "\033[12;30H                                                                                                    " << endl;
            break;
        }
    }


    // Nhap password
    while (true) {
        cout << "\033[6;76H";
        pass = userManager.inputPassword();

        if (!userManager.isValidPassword(pass)) {
            cout << "\033[12;59HPASSWORD MUST BE AT LEAST 6 CHARACTERS LONG!" << endl;
            cout << "\033[6;76H                           " << endl;
        } else {
            cout << "\033[12;30H                                                                                                    " << endl;
            break;
        }
    }


    // Nhap name
    while (true) {
        cout << "\033[8;72H";
        cin.ignore();
        getline(cin, name);

        if (!userManager.isValidName(name)) {
            cout << "\033[12;66HINVALID NAME! PLEASE TRY AGAIN!" << endl;
            cout << "\033[8;72H                               " << endl;
        } else {
            cout << "\033[12;30H                                                                                                    " << endl;
            break;
        }
    }

    // Nhap phone number
    while (true) {
        cout << "\033[10;80H";
        cin >> phone;

        if (!userManager.isValidPhone(phone)) {
            cout << "\033[12;62HINVALID PHONE NUMBER! PLEASE TRY AGAIN!" << endl;
            cout << "\033[10;80H                       ";
        } else if (userManager.isPhoneNumberTaken(phone)) {
            cout << "\033[12;30H                                                                                                    " << endl;
            cout << "\033[12;60HTHIS PHONE NUMBER ALREADY REGISTERED!" << endl;
            cout << "\033[10;80H                       ";
        } else {
            cout << "\033[12;30H                                                                                                    " << endl;
            break;
        }
    }

    if (accountType == "Customer") {
        Customer newCustomer(user, pass, name, phone);
        newCustomer.saveAccount(filename);
    } else if (accountType == "Manager") {
        Manager newManager(user, pass, name, phone);
        newManager.saveAccount(filename);
    }

    system("cls");
    cout << "\t\t\t\t\t\t\t            REGISTRATION SUCCESSFUL!            " << endl;
    menu.printRETURN();
    cin.ignore();
    cin.get();
}

// dang nhap
void AccountManager::login() {
    system("cls");

    UserManager userManager;
    Account account;
    Menu menu;
    menu.displaySignIn();

    string user, pass, name;
    cout << "\033[4;76H";
    cin >> user;

    cout << "\033[6;76H";
    pass = userManager.inputPassword();

    if (account.getUserInfo("tk_quanly.txt", user, pass, name)) {
        menu.managerMenu(user, name);
    } 
    else if (account.getUserInfo("tk_khachhang.txt", user, pass, name)) {
        menu.customerMenu(user, name);
    } else {
        system("cls");
        cout << "\t\t\t\t\t\t\t       USERNAME OR PASSWORD IS INCORRECT!       " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
    }
}

// dat lai mat khau
void AccountManager::resetPassword(const string& filename) {
    system("cls");

    UserManager userManager;
    FileManager fileManager;
    Menu menu;
    resetPass:;

    while (true) {
        string username, phone, newPassword, confirmPassword;

        menu.displayResetPass();

        cout << "\033[4;76H";
        cin >> username;
        cout << "\033[6;80H";
        cin >> phone;

        // doc danh sach tai khoan
        Vector lines = fileManager.readAllLines(filename);
        bool accountFound = false;

        for (size_t i = 0; i < lines.get_size(); i++) {
            stringstream ss(lines[i]);
            string u, p, name, phoneNum;
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, name, ',');
            getline(ss, phoneNum);

            // neu tim thay tai khoan
            if (u == username && phoneNum == phone) {
                while (true) {
                    cout << "\033[8;00H";
                    cout << "\t\t\t\t\t\t\t##       NEW PASSWORD:                        ##" << endl;
                    cout << "\t\t\t\t\t\t\t################################################" << endl;
                    cout << "\033[8;80H";
                    newPassword = userManager.inputPassword();

                    // kiem tra password hop le
                    if (!userManager.isValidPassword(newPassword)) {
                        system("cls");
                        cout << "\t\t\t\t\t\t\t  PASSWORD MUST BE AT LEAST 6 CHARACTERS LONG!  " << endl;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        // system("cls");
                        goto resetPass;
                    } else {
                        cout << "\n";
                        cout << "\t\t\t\t\t\t\t##       CONFIRM NEW PASSWORD:                ##" << endl;
                        cout << "\t\t\t\t\t\t\t################################################" << endl;
                        cout << "\033[10;88H";
                        confirmPassword = userManager.inputPassword();

                        // confirm password
                        if (newPassword != confirmPassword) {
                            system("cls");
                            cout << "\t\t\t\t\t\t\t            PASSWORDS DO NOT MATCH!             " << endl;
                            menu.printRETURN();
                            cin.ignore();
                            cin.get();
                            // system("cls");
                            goto resetPass;
                        } else {
                            stringstream newLine;
                            newLine << u << "," << newPassword << "," << name << "," << phoneNum;
                            lines[i] = newLine.str();
                            accountFound = true;
                            break;
                        }
                    }
                }
                if (accountFound) break;
            }
        }

        if (accountFound) {
            fileManager.writeAllLines(filename, lines);
            system("cls");
            cout << "\t\t\t\t\t\t\t         PASSWORD UPDATED SUCCESSFULLY!         " << endl;
            menu.printRETURN();
            cin.ignore();
            cin.get();
            // system("cls");
            return;
        } else {
            system("cls");
            cout << "\t\t\t\t\t\t\t          THE ACCOUNT DOES NOT EXIST!           " << endl;
            menu.printRETURN();
            cin.ignore();
            cin.get();
            // system("cls");
            return;
        }
    }
}

// doi mat khau
void AccountManager::changePassword(const string& filename, const string& username) {
    system("cls");

    UserManager userManager;
    FileManager fileManager;
    Menu menu;
    changePass:;

    while (true) {
        string currentPassword, newPassword, confirmPassword;

        menu.displayChangePass();
        cout << "\033[4;84H";
        currentPassword = userManager.inputPassword();

        Vector lines = fileManager.readAllLines(filename);
        bool accountFound = false;

        for (size_t i = 0; i < lines.get_size(); i++) {
            stringstream ss(lines[i]);
            string u, p, name, phoneNum;
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, name, ',');
            getline(ss, phoneNum, ',');

            if (u == username && p == currentPassword) {
                while (true) {
                    cout << "\033[6;00H";
                    cout << "\t\t\t\t\t\t\t##       NEW PASSWORD:                        ##" << endl;
                    cout << "\t\t\t\t\t\t\t################################################" << endl;
                    cout << "\033[6;80H";
                    newPassword = userManager.inputPassword();

                    if (!userManager.isValidPassword(newPassword)) {
                        system("cls");
                        cout << "\t\t\t\t\t\t\t  PASSWORD MUST BE AT LEAST 6 CHARACTERS LONG!  " << endl;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        // system("cls");
                        goto changePass;
                    } else {
                        cout << "\n";
                        cout << "\t\t\t\t\t\t\t##       CONFIRM NEW PASSWORD:                ##" << endl;
                        cout << "\t\t\t\t\t\t\t################################################" << endl;
                        cout << "\033[8;88H";
                        confirmPassword = userManager.inputPassword();

                        // confirm password
                        if (newPassword != confirmPassword) {
                            system("cls");
                            cout << "\t\t\t\t\t\t\t            PASSWORDS DO NOT MATCH!             " << endl;
                            menu.printRETURN();
                            cin.ignore();
                            cin.get();
                            // system("cls");
                            goto changePass;
                        } else {
                            stringstream newLine;
                            newLine << u << "," << newPassword << "," << name << "," << phoneNum;
                            lines[i] = newLine.str();
                            accountFound = true;
                            break;
                        }
                    }
                }
                if (accountFound) break;
            }
        }
        if (accountFound) {
            fileManager.writeAllLines(filename, lines);
            system("cls");
            cout << "\t\t\t\t\t\t\t         PASSWORD UPDATED SUCCESSFULLY!         " << endl;
            menu.printRETURN();
            cin.ignore();
            cin.get();
            system("cls");
            return;
        } else {
            system("cls");
            cout << "\t\t\t\t\t\t\t       CURRENT PASSWORD IS INCORRECT!            " << endl;
            menu.printRETURN();
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }
    }
}


// kiem tra xoa tai khoan thanh cong
bool AccountManager::isdeleteAccount(const string& filename, const string& username) {
    FileManager fileManager;
    Vector lines = fileManager.readAllLines(filename);
    bool accountFound = false;

    for (size_t i = 0; i < lines.get_size(); ++i) {
        stringstream ss(lines[i]);
        string currentUsername, password, name, phone;

        getline(ss, currentUsername, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');

        if (currentUsername == username) {
            lines.erase(i);
            accountFound = true;
            break;
        }
    }

    if (accountFound) {
        fileManager.writeAllLines(filename, lines);
        return true;
    }

    return false;
}

// xoa tai khoan
void AccountManager::deleteAccount(const string& username) {
    AccountManager manager;
    Menu menu;

    string filename = "tk_khachhang.txt";

    if (manager.isdeleteAccount(filename, username)) {
        system("cls");
        cout << "\t\t\t\t\t\t                 ACCOUNT DELETED SUCCESSFULLY!                " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
    } else {
        system("cls");
        cout << "\t\t\t\t\t\t               ERROR: Unable to delete account!               " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
    }
}

// xem danh sach khach hang
void AccountManager::viewCustomerList() {
    Menu menu;
    system("cls");

    ifstream file("tk_khachhang.txt");
    if (!file.is_open()) {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to open customer data file!" << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return;
    }

    string line, username, password, name, phone;
    Vector customers;

    while (getline(file, line)) {
        customers.push_back(line);
    }
    file.close();

    while (true) {
        system("cls");
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                       CUSTOMER LIST                        ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;

        for (size_t i = 0; i < customers.get_size(); ++i) {
            stringstream ss(customers[i]);
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');

            cout << "\t\t\t\t\t\t" << i + 1 << "---------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t|   CUSTOMER: " << name << endl;
            cout << "\t\t\t\t\t\t|   USERNAME: " << username << endl;
            cout << "\t\t\t\t\t\t|   PHONE: " << phone << endl;
            cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
        }

        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##\tCHOOSE A CUSTOMER BY INDEX (1-" << customers.get_size() << ") OR 0 TO GO BACK:    ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            system("cls");
            return;
        } else if (choice > 0 && choice <= customers.get_size()) {
            stringstream ss(customers[choice - 1]);
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');

            menu.customerDetailMenu(username, name, phone);
        } else {
            menu.displayError();
        }
    }
}

// thay doi so dien thoai
void AccountManager::changePhoneNumber(const string& filename, const string& username) {
    system("cls");

    UserManager userManager;
    FileManager fileManager;
    Menu menu;

    while (true) {
        string newPhone, password;

        Vector lines = fileManager.readAllLines(filename);
        bool accountFound = false;

        for (size_t i = 0; i < lines.get_size(); i++) {
            stringstream ss(lines[i]);
            string u, p, name, phone;
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, name, ',');
            getline(ss, phone);

            if (u == username) {
                while (true) {
                    system("cls");
                    menu.displayChangePhone();
                    cout << "\033[4;88H" << phone;
                    cout << "\033[6;84H";
                    cin >> newPhone;

                    if (newPhone == phone) {
                        system("cls");
                        cout << "\t\t\t\t\t\t\tNEW PHONE NUMBER CANNOT BE THE SAME AS THE OLD ONE!" << endl;
                        Menu menu;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        return;
                    }

                    if (!userManager.isValidPhone(newPhone)) {
                        system("cls");
                        cout << "\t\t\t\t\t\t\t     INVALID PHONE NUMBER! PLEASE TRY AGAIN!    " << endl;
                        Menu menu;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        return;
                    } else if (userManager.isPhoneNumberTaken(newPhone)) {
                        system("cls");
                        cout << "\t\t\t\t\t\t\t      THIS PHONE NUMBER ALREADY REGISTERED!     " << endl;
                        Menu menu;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        return;
                    }

                    cout << "\033[8;00H";
                    cout << "\t\t\t\t\t\t\t##       VERIFY YOUR PASSWORD:                ##" << endl;
                    cout << "\t\t\t\t\t\t\t################################################" << endl;
                    cout << "\033[8;88H";
                    password = userManager.inputPassword();

                    if (password == p) {
                        stringstream newLine;
                        newLine << u << "," << p << "," << name << "," << newPhone;
                        lines[i] = newLine.str();
                        accountFound = true;

                        fileManager.writeAllLines(filename, lines);

                        system("cls");
                        cout << "\t\t\t\t\t\t\t       PHONE NUMBER UPDATED SUCCESSFULLY!       " << endl;
                        Menu menu;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        return;
                    } else {
                        system("cls");
                        cout << "\t\t\t\t\t\t\t  INCORRECT PASSWORD! PHONE NUMBER NOT UPDATED! " << endl;
                        Menu menu;
                        menu.printRETURN();
                        cin.ignore();
                        cin.get();
                        return;
                    }
                }
            }
        }

        if (!accountFound) {
            system("cls");
            cout << "\t\t\t\t\t\t\t          THE ACCOUNT DOES NOT EXIST!           " << endl;
            Menu menu;
            menu.printRETURN();
            cin.ignore();
            cin.get();
            return;
        }
    }
}

