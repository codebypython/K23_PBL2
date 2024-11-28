#include "Menu.h"
#include <iostream>

void Menu::displayPriceMenu() {
    system("cls");
    PriceManager priceManager; // Tạo đối tượng PriceManager
    string filename = "price_list.txt"; // File dữ liệu mặc định
    int choice;

    do {
        // Hiển thị menu
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                       Price Management Menu                ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                        1. PRICE LIST                       ##" << endl;
        cout << "\t\t\t\t\t\t##                        2. EDIT PRICE LIST                  ##" << endl;
        cout << "\t\t\t\t\t\t##                        0. RETURN                           ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Xử lý lựa chọn của người dùng
        switch (choice) {
            case 1: // Hiển thị bảng giá
                system("cls");
                priceManager.displayPriceList(filename);
                break;

            case 2: // Chỉnh sửa bảng giá
                priceManager.editPriceList(filename);
                break;

            case 0: // Thoát menu
                break;

            default: // Lựa chọn không hợp lệ
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl; // Dòng trống để dễ đọc
    } while (choice != 0); // Lặp lại menu cho đến khi người dùng chọn thoát
}

void Menu::displayLogo() {
    system("cls"); 
    ifstream logoFile("logo.txt");
    if (logoFile) {
        string line;
        while (getline(logoFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "LOGO FILE NOT FOUND!" << endl;
    }
}

void Menu::displayGoodbye() {
    system("cls"); 
    ifstream logoFile("goodbye.txt");
    if (logoFile) {
        string line;
        while (getline(logoFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "GOOBYE FILE NOT FOUND!" << endl;
    }
}

void Menu::displaySignIn() {
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##                  SIGN IN                   ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       USERNAME:                            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       PASSWORD:                            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::displaySignUp() {
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##                  SIGN UP                   ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       USERNAME:                            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       PASSWORD:                            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       NAME:                                ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       PHONE NUMBER:                        ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::displayResetPass() {
    system("cls");
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##               RESET PASSWORD               ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       USERNAME:                            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       PHONE NUMBER:                        ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::displayChangePass() {
    system("cls");
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##              CHANGE PASSWORD               ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       CURRENT PASSWORD:                    ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::displayChangePhone() {
    system("cls");
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##             CHANGE PHONE NUMBER            ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       CURRENT PHONE NUMBER:                ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##       NEW PHONE NUMBER:                    ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::printRETURN() {
    cout << "\n";
    cout << "\t\t\t\t\t\t\t################################################" << endl;
    cout << "\t\t\t\t\t\t\t##          PRESS ENTER TO RETURN...          ##" << endl;
    cout << "\t\t\t\t\t\t\t################################################" << endl;
}

void Menu::displayError() {
    system("cls");
    cout << "\t\t\t\t\t\t\t                INVALID CHOICE!                 " << endl;
    printRETURN();
    cin.ignore();
    cin.get();
    system("cls");
}

void Menu::homeMenu() {
    AccountManager manager;
    int choice;

    while (true) {
        displayLogo();
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##             FOOTBALL FIELD MANAGER APPLICATION             ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                        1. SIGN IN                          ##" << endl;
        cout << "\t\t\t\t\t\t##                        2. SIGN UP                          ##" << endl;
        cout << "\t\t\t\t\t\t##                        3. FORGOT PASSWORD?                 ##" << endl;
        cout << "\t\t\t\t\t\t##                        0. EXIT                             ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.login();
                break;
            case 2:
                manager.registerAccount("tk_khachhang.txt", "Customer");
                break;
            case 3:
                manager.resetPassword("tk_khachhang.txt");
                break;
            case 0:
                displayGoodbye();
                exit(0);
            default:
                displayError();
        }
    }
}

void Menu::managerMenu(const string& username, const string& name) {
    AccountManager manager;
    FieldManager fieldManager;
    int choice;

    while (true) {
        system("cls"); 
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t                      WELCOME, "<< name << "!                   " << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                        MANAGER MENU                        ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                 1. REGISTER FOR AN ACCOUNT                 ##" << endl;
        cout << "\t\t\t\t\t\t##                 2. RESET PASSWORD                          ##" << endl;
        cout << "\t\t\t\t\t\t##                 3. BOOK A FIELD                            ##" << endl;
        cout << "\t\t\t\t\t\t##                 4. CANCEL A FIELD                          ##" << endl;
        cout << "\t\t\t\t\t\t##                 5. PRINT BILL & FREE FIELD                 ##" << endl;
        cout << "\t\t\t\t\t\t##                 6. VIEW AVAILABLE FIELDS                   ##" << endl;
        cout << "\t\t\t\t\t\t##                 7. VIEW CUSTOMER LIST                      ##" << endl;
        cout << "\t\t\t\t\t\t##                 0. LOG OUT                                 ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        cin >> choice;  

        switch (choice) {
            case 1:
                registrationMenu();
                break;
            case 2:
                resetPassMenu();
                break;
            case 3:
                fieldManager.bookField(username, name);
                break;
            case 4:
                fieldManager.cancelBookField(username);
                break;
            case 5:
                // fieldManager.printBill();
                displayPriceMenu();
                break;
            case 6:
                fieldManager.viewAvailableFields();
                break;
            case 7:
                manager.viewCustomerList();
                break;
            case 0:
                return;
            default:
                displayError();
        }
    }
}

void Menu::customerMenu(const string& username, const string& name) {
    int choice;
    FieldManager fieldManager;
    BookingManager booking;

    while (true) {
        system("cls"); 
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t                      WELCOME, "<< name << "!                   " << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                        CUSTOMER MENU                       ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                     1. BOOK A FIELD                        ##" << endl;
        cout << "\t\t\t\t\t\t##                     2. CANCEL A FIELD                      ##" << endl;
        cout << "\t\t\t\t\t\t##                     3. VIEW AVAILABLE FIELDS               ##" << endl;
        cout << "\t\t\t\t\t\t##                     4. VIEW BOOKING HISTORY                ##" << endl;
        cout << "\t\t\t\t\t\t##                     5. ACCOUNT SETTINGS                    ##" << endl;
        cout << "\t\t\t\t\t\t##                     6. PRICE MENU                          ##" << endl;
        cout << "\t\t\t\t\t\t##                     0. LOG OUT                             ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fieldManager.bookField(username, name);
                break;
            case 2:
                fieldManager.cancelBookField(username);
                break;
            case 3:
                fieldManager.viewAvailableFields();
                break;
            case 4:
                booking.viewBookingHistory(username);
                break;
            case 5:
                accountSettingsMenu(username);
                break;
            case 6:
                displayPriceMenu();   
                break;
            case 0:
                return;
            default:
                displayError();
        }
    }
}

void Menu::registrationMenu() {
    system("cls"); 
    AccountManager manager;
    int registrationChoice;

    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                   REGISTER FOR AN ACCOUNT                  ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                1. REGISTER A MANAGER ACCOUNT               ##" << endl;
    cout << "\t\t\t\t\t\t##                2. REGISTER A CUSTOMER ACCOUNT              ##" << endl;
    cout << "\t\t\t\t\t\t##                0. GO BACK                                  ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
    cin >> registrationChoice;

    switch (registrationChoice) {
        case 1:
            manager.registerAccount("tk_quanly.txt", "Manager");
            break;
        case 2:
            manager.registerAccount("tk_khachhang.txt", "Customer");
            break;
        case 0:
            system("cls");
            break;
        default:
            displayError();
    }
}

void Menu::resetPassMenu() {
    system("cls"); 
    AccountManager manager;
    int resetChoice;

    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                       RESET PASSWORD                       ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##              1. RESET MANAGER ACCOUNT PASSWORD             ##" << endl;
    cout << "\t\t\t\t\t\t##              2. RESET CUSTOMER ACCOUNT PASSWORD            ##" << endl;
    cout << "\t\t\t\t\t\t##              0. GO BACK                                    ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
    cin >> resetChoice;

    switch (resetChoice) {
        case 1:
            manager.resetPassword("tk_quanly.txt");
            break;
        case 2:
            manager.resetPassword("tk_khachhang.txt");
            break;
        case 0:
            system("cls");
            break;
        default:
            displayError();
    }
}

void Menu::printDATSAN() {
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                        BOOK A FIELD                        ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
}

void Menu::printHUYSAN() {
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                       CANCEL A FIELD                       ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
}

void Menu::printKHUNGGIO(const string& timeSlot) {
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                        "<<timeSlot<<"                         ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
}

void Menu::printXEMSAN() {
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                   VIEW AVAILABLE FIELDS                    ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
}

void Menu::displayBookingForm() {
    system("cls");
    cout << "\t\t\t\t\t--------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t|                               BOOKING DETAILS                                |" << endl;
    cout << "\t\t\t\t\t--------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t|       NAME:                                                                  |" << endl;
    cout << "\t\t\t\t\t|       PHONE NUMBER:                                                          |" << endl;
    cout << "\t\t\t\t\t|       PAYMENT DETAILS (PAID/NOT PAID):                                       |" << endl;
    cout << "\t\t\t\t\t|       NOTE (IF ANY):                                                         |" << endl;
    cout << "\t\t\t\t\t--------------------------------------------------------------------------------" << endl;
}

void Menu::customerDetailMenu(const string& username, const string& name, const string& phone) {
    FieldManager fieldManager;
    AccountManager manager;
    BookingManager booking;

    int choice;
    while (true) {
        system("cls");
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                      CUSTOMER DETAIL                       ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t   CUSTOMER: " << name << endl;
        cout << "\t\t\t\t\t\t   USERNAME: " << username << endl;
        cout << "\t\t\t\t\t\t   PHONE: " << phone << endl;
        cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                   1. VIEW BOOKING HISTORY                  ##" << endl;
        cout << "\t\t\t\t\t\t##                   2. RESET PASSWORD                        ##" << endl;
        cout << "\t\t\t\t\t\t##                   3. DELETE ACCOUNT                        ##" << endl;
        cout << "\t\t\t\t\t\t##                   0. GO BACK                               ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                booking.viewBookingHistory(username);
                break;
            case 2:
                manager.resetPassword("tk_khachhang.txt");
                break;
            case 3:
                manager.deleteAccount(username);
                break;
            case 0:
                system("cls");
                return;
            default:
                displayError();
        }
    }
}

void Menu::accountSettingsMenu(const string& username) {
    AccountManager manager;
    UserManager userManager;
    FileManager fileManager;

    int choice;
    while (true) {
        system("cls");
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                   ACCOUNT SETTINGS MENU                    ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t##                1. CHANGE PHONE NUMBER                      ##" << endl;
        cout << "\t\t\t\t\t\t##                2. CHANGE PASSWORD                          ##" << endl;
        cout << "\t\t\t\t\t\t##                3. DELETE ACCOUNT                           ##" << endl;
        cout << "\t\t\t\t\t\t##                0. GO BACK                                  ##" << endl;
        cout << "\t\t\t\t\t\t################################################################" << endl;
        cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                manager.changePhoneNumber("tk_khachhang.txt", username);
                break;
            case 2: 
                manager.changePassword("tk_khachhang.txt", username);
                break;
            case 3: {
                while (true) {
                    char confirmChoice;
                    system("cls");
                    cout << "\t\t\t\t\t\t################################################################" << endl;
                    cout << "\t\t\t\t\t\t##                       DELETE ACCOUNT                       ##" << endl;
                    cout << "\t\t\t\t\t\t################################################################" << endl;
                    cout << "\t\t\t\t\t\t##       ARE YOU SURE YOU WANT TO DELETE YOUR ACCOUNT?        ##" << endl;
                    cout << "\t\t\t\t\t\t##                  THIS CANNOT BE UNDONE!!!                  ##" << endl;
                    cout << "\t\t\t\t\t\t################################################################" << endl;
                    cout << "\t\t\t\t\t\t##                           1. YES                           ##" << endl;
                    cout << "\t\t\t\t\t\t##                           2. NO                            ##" << endl;
                    cout << "\t\t\t\t\t\t################################################################" << endl;
                    cout << "\t\t\t\t\t\t\t\t\tYOUR CHOICE: ";
                    cin >> confirmChoice;

                    if (confirmChoice == '1') {
                        manager.deleteAccount(username);
                        displayGoodbye();
                        exit(0);
                    } else if (confirmChoice == '2') {
                        system("cls");
                        break;
                    } else {
                        displayError();
                    }
                }
                break;
            }
            case 0:
                system("cls");
                return;
            default:
                displayError();
        }
    }
}
