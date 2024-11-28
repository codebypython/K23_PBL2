#pragma once
#define BOOKINGMANAGER_H

#include "Menu.h"
#include <iostream>
#include <fstream>
using namespace std;

class BookingManager {
public:
    bool isFieldAvailable(const string& timeSlot, const string& field);
    bool isFieldBookedByUser(const string& filePath, const string& username);

    bool isBookField(const string& timeSlot, const string& field, const string& username, const string& customerName);
    bool isCancelBookField(const string& timeSlot, const string& field, const string& username);

    void viewBookingHistory(const string& username);

    bool displayFieldsForTimeSlot(const string& timeSlot);

};