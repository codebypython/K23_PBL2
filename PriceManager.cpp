#include "PriceManager.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits> // Để sử dụng std::numeric_limits

using namespace std;

// Hàm tìm kiếm khung giờ
TimeSlot* PriceManager::findTimeSlot(std::vector<TimeSlot>& data, const std::string& selectedTimeSlot) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].timeRange == selectedTimeSlot) {
            return &data[i]; // Trả về con trỏ đến phần tử tìm thấy
        }
    }
    return nullptr; // Không tìm thấy
}

void PriceManager::displayPriceList(const std::string& filename) {
    vector<TimeSlot> priceData;
    parsePriceList(filename, priceData); // Đọc dữ liệu từ file
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                      Price List                             ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    displayData(priceData); // Hiển thị dữ liệu
    cout << "\t\t\t\t\t\t################################################################" << endl;
}

void PriceManager::editPriceList(const std::string& filename) {
    vector<TimeSlot> priceData;
    parsePriceList(filename, priceData); // Đọc dữ liệu từ file

    // Hiển thị danh sách khung giờ
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##                   Available Time Slots:                    ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    for (size_t i = 0; i < priceData.size(); ++i) {
        cout << "\t\t\t\t\t\t##                      "<< i + 1 <<". "<< priceData[i].timeRange <<"                        ##"<< endl;
    }
    cout << "\t\t\t\t\t\t################################################################" << endl;

    // Chọn khung giờ để chỉnh sửa
    int timeSlotIndex;
    cout << "Select a time slot to edit (1-" << priceData.size() << "): ";
    while (true) {
        cin >> timeSlotIndex;
        if (cin.fail() || timeSlotIndex < 1 || timeSlotIndex > priceData.size()) {
            cin.clear(); // Xóa lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua dòng
            cout << "Invalid selection. Please try again (1-" << priceData.size() << "): ";
        } else {
            break; // Nhập hợp lệ
        }
    }

    // Lưu khung giờ đã chọn vào biến selectedTimeSlot
    string selectedTimeSlot = priceData[timeSlotIndex - 1].timeRange;

    // Tìm khung giờ
    TimeSlot* timeSlot = findTimeSlot(priceData, selectedTimeSlot);
    if (timeSlot == nullptr) {
        cout << "Invalid time slot. Please try again." << endl;
        return;
    }

    // Hiển thị các sân trong khung giờ được chọn
    cout << "\t\t\t\t\t\t################################################################" << endl;
    cout << "\t\t\t\t\t\t##              Current Prices :     " << selectedTimeSlot << "              ##" << endl;
    cout << "\t\t\t\t\t\t################################################################" << endl;
    for (size_t i = 0; i < timeSlot->slotInfos.size(); ++i) {
        cout << "\t\t\t\t\t\t##           " << i + 1 << ". " << left << setw(10) << timeSlot->slotInfos[i].fieldName
             << " - Price: " << setw(10) << timeSlot->slotInfos[i].price << " VND" << "            ##" << endl;
    }
    cout << "\t\t\t\t\t\t################################################################" << endl;

    // Chọn sân để chỉnh sửa
    int fieldIndex;
    cout << "Select a field to edit (1-" << timeSlot->slotInfos.size() << "): ";
    while (true) {
        cin >> fieldIndex;
        if (cin.fail() || fieldIndex < 1 || fieldIndex > timeSlot->slotInfos.size()) {
            cin.clear(); // Xóa lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua dòng
            cout << "Invalid field selection. Please try again (1-" << timeSlot->slotInfos.size() << "): ";
        } else {
            break; // Nhập hợp lệ
        }
    }

    // Cập nhật giá sân
    int newPrice;
    cout << "Enter the new price for " << timeSlot->slotInfos[fieldIndex - 1].fieldName << ": ";
    while (true) {
        cin >> newPrice;
        if (cin.fail() || newPrice < 0) {
            cin.clear(); // Xóa lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua dòng
            cout << "Invalid price. Please enter a positive number: ";
        } else {
            break; // Nhập hợp lệ
        }
    }

    timeSlot->slotInfos[fieldIndex - 1].price = newPrice;
    cout << "Price updated successfully!" << endl;

    // Ghi dữ liệu lại vào file
    savePriceList(filename, priceData);
}


void PriceManager::parsePriceList(const std::string& filename, std::vector<TimeSlot>& data) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    TimeSlot currentTimeSlot;

    while (getline(file, line)) {
        // Kiểm tra nếu dòng là khung giờ (chứa ký tự '-')
        if (line.find('-') != string::npos) {
            // Nếu đã có dữ liệu của khung giờ trước đó, thêm vào danh sách
            if (!currentTimeSlot.timeRange.empty()) {
                data.push_back(currentTimeSlot);
                currentTimeSlot = TimeSlot(); // Reset khung giờ
            }
            currentTimeSlot.timeRange = line; // Lưu khung giờ mới
        } else if (!line.empty()) {
            // Xử lý dòng chứa thông tin sân và giá
            stringstream ss(line);
            SlotInfo slot;
            getline(ss, slot.fieldName, ','); // Lấy tên sân
            ss >> slot.price;                // Lấy giá sân
            currentTimeSlot.slotInfos.push_back(slot); // Thêm vào danh sách sân
        }
    }

    // Thêm khung giờ cuối cùng vào danh sách (nếu có)
    if (!currentTimeSlot.timeRange.empty()) {
        data.push_back(currentTimeSlot);
    }

    file.close();
}

void PriceManager::savePriceList(const std::string& filename, const std::vector<TimeSlot>& data) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }

    for (const auto& timeSlot : data) {
        file << timeSlot.timeRange << endl; // Ghi khung giờ
        for (const auto& slotInfo : timeSlot.slotInfos) {
            file << slotInfo.fieldName << "," << slotInfo.price << endl; // Ghi sân và giá
        }
    }

    file.close();
}

void PriceManager::displayData(const std::vector<TimeSlot>& data) {
    cout << "Price List:" << endl;
    for (const auto& timeSlot : data) {
        cout << "Time Slot: " << timeSlot.timeRange << endl;
        for (const auto& slotInfo : timeSlot.slotInfos) {
            cout << "  Field: " << slotInfo.fieldName << " - Price: " << slotInfo.price << " VND" << endl;
        }
    }
}
