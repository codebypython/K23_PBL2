#include "BookingManager.h"
using namespace std;

// kiem tra san trong
bool BookingManager::isFieldAvailable(const string& timeSlot, const string& field) {
    Menu menu;
    string filePath = "TimeSlots/" + timeSlot + "/" + field + ".txt";

    ifstream file(filePath);
    if (!file.is_open()) {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to open file " << filePath << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("STATUS: Available") != string::npos) {
            return true;
        }
    }
    return false;
}

// kiem tra nguoi dung nao da dat san
bool BookingManager::isFieldBookedByUser(const string& filePath, const string& username) {
    Menu menu;
    ifstream file(filePath);

    if (!file.is_open()) {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to open file " << filePath << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("USERNAME: ") != string::npos) {
            string bookedUsername = line.substr(line.find(": ") + 2);
            if (bookedUsername == username) {
                return true;
            }
        }
    }

    return false;
}

// kiem tra dat san thanh cong
bool BookingManager::isBookField(const string& timeSlot, const string& field, const string& username, const string& customerName) {
    Menu menu;
    string filePath = "TimeSlots/" + timeSlot + "/" + field + ".txt";

    if (!isFieldAvailable(timeSlot, field)) {
        system("cls");
        cout << "\t\t\t\t\t       THIS FIELD HAS ALREADY BEEN BOOKED. PLEASE CHECK ANOTHER FIELD!        " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }

    menu.displayBookingForm();

    string phone, paymentStatus, note;

    cout << "\033[4;55H" << customerName;
    cin.ignore();
    
    cout << "\033[5;63H";
    getline(cin, phone);
    
    cout << "\033[6;82H";
    getline(cin, paymentStatus);
    
    cout << "\033[7;64H";
    getline(cin, note);

    ofstream file(filePath, ios::trunc);
    if (file.is_open()) {
        file << "FIELD: " << field << endl;
        file << "STATUS: Booked" << endl;
        file << "PRICE: " << endl;
        file << "USERNAME: " << username << endl;
        file << "CUSTOMER: " << customerName << endl;
        file << "PHONE NUMBER: " << phone << endl;
        file << "PAYMENT DETAILS: " << paymentStatus << endl;
        file << "NOTE: " << note << endl;
        file.close();

        system("cls");
        cout << "\t\t\t\t\t                    THE FIELD HAS BEEN SUCCESSFULLY BOOKED!                   " << endl;
        menu.printRETURN();
        cin.get();
        return true;
    } else {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to write to file " << filePath << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }
}

// kiem tra huy san thanh cong
bool BookingManager::isCancelBookField(const string& timeSlot, const string& field, const string& username) {
    Menu menu;
    Account account;

    bool isAdmin = account.isAdminUser(username, "tk_quanly.txt");

    if (isFieldAvailable(timeSlot, field)) {
        system("cls");
        cout << "\t\t\t\t\t                THIS FIELD HAS NOT BEEN BOOKED. CANNOT CANCEL!                " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }

    if (!isAdmin && !isFieldBookedByUser("TimeSlots/" + timeSlot + "/" + field + ".txt", username)) {
        system("cls");
        cout << "\t\t\t\t\t                YOU DO NOT HAVE PERMISSION TO CANCEL THIS FIELD!              " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }

    string filePath = "TimeSlots/" + timeSlot + "/" + field + ".txt";
    // if (!isFieldBookedByUser(filePath, username)) {
    //     system("cls");
    //     cout << "\t\t\t\t\t                YOU DO NOT HAVE PERMISSION TO CANCEL THIS FIELD!              " << endl;
    //     menu.printRETURN();
    //     cin.ignore();
    //     cin.get();
    //     return false;
    // }

    ofstream file(filePath, ios::trunc);
    if (file.is_open()) {
        file << "FIELD: " << field << endl;
        file << "STATUS: Available" << endl;
        file.close();

        system("cls");
        cout << "\t\t\t\t\t                   THE FIELD HAS BEEN SUCCESSFULLY CANCELED!                  " << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return true;
    } else {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to write to file " << filePath << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }
}

// xem lich su dat san
void BookingManager::viewBookingHistory(const string& username) {
    Menu menu;
    FileManager fileManager;
    Vector timeSlots = fileManager.loadFields("timeslots.txt");
    Vector fields = fileManager.loadFields("fields.txt");

    bool hasHistory = false;

    system("cls");
    cout << "\t\t\t\t\t\t##############################################################" << endl;
    cout << "\t\t\t\t\t\t#                      BOOKING HISTORY                       #" << endl;
    cout << "\t\t\t\t\t\t##############################################################" << endl;

    for (size_t i = 0; i < timeSlots.get_size(); ++i) {
        string timeSlot = timeSlots[i];

        for (size_t j = 0; j < fields.get_size(); ++j) {
            string field = fields[j];
            string filePath = "TimeSlots/" + timeSlot + "/" + field + ".txt";

            ifstream file(filePath);
            if (file.is_open()) {
                string line;
                bool matchFound = false;
                while (getline(file, line)) {
                    if (line.find("USERNAME: " + username) != string::npos) {
                        matchFound = true;
                        break;
                    }
                }

                if (matchFound) {
                    hasHistory = true;
                    cout << "\n";                                                                          
                    cout << "\t\t\t\t\t\t--------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t|   Time Slot: "<< timeSlot <<"          |         Field: "<< field <<"   |" << endl;
                    cout << "\t\t\t\t\t\t--------------------------------------------------------------" << endl;

                    file.clear();
                    file.seekg(0, ios::beg);
                    while (getline(file, line)) {
                        size_t colonPos = line.find(":");
                        if (colonPos != string::npos) {
                            string key = line.substr(0, colonPos);
                            string value = line.substr(colonPos + 1);
                            cout << "\t\t\t\t\t\t   " << key << ": " << value << endl;
                        } else {
                            cout << "\t\t\t\t\t\t   " << line << endl;
                        }
                    }
                    cout << "\t\t\t\t\t\t--------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t______________________________________________________________________________" << endl;
                }
                file.close();
            }
        }
    }

    if (!hasHistory) {
        cout << "\n";
        cout << "\t\t\t\t\t                           NO BOOKING HISTORY FOUND!                          " << endl;
    }

    menu.printRETURN();
    cin.ignore();
    cin.get();
    system("cls");
}

// kiem tra neu con san trong thi in ra
bool BookingManager::displayFieldsForTimeSlot(const string& timeSlot) { 
    Menu menu;
    FileManager fileManager;

    ifstream file("fields.txt");
    if (!file.is_open()) {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to open fields data file!" << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return false;
    }
    file.close();
    
    Vector fields = fileManager.loadFields("fields.txt");
    bool hasAvailable = false;

    for (size_t i = 0; i < fields.get_size(); ++i) {
        if (isFieldAvailable(timeSlot, fields[i])) {
            if (!hasAvailable) {
                menu.printXEMSAN();
                menu.printKHUNGGIO(timeSlot);
            }
            cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t|                            " << fields[i] << "                             |" << endl;
            cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
            hasAvailable = true;
        }
    }

    return hasAvailable;
}
