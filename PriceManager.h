#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Cấu trúc lưu thông tin sân
struct SlotInfo {
    std::string fieldName; // Tên sân
    int price;             // Giá sân
};

// Cấu trúc lưu thông tin khung giờ
struct TimeSlot {
    std::string timeRange;                  // Khung giờ
    std::vector<SlotInfo> slotInfos;        // Danh sách thông tin sân
};

// Lớp quản lý bảng giá
class PriceManager {
public:
    void displayPriceList(const std::string& filename = "price_list.txt"); // Hiển thị bảng giá
    void editPriceList(const std::string& filename = "price_list.txt");    // Chỉnh sửa bảng giá
    void displayEdit();
private:
    void parsePriceList(const std::string& filename, std::vector<TimeSlot>& data); // Đọc dữ liệu từ file
    void savePriceList(const std::string& filename, const std::vector<TimeSlot>& data); // Ghi dữ liệu ra file
    void displayData(const std::vector<TimeSlot>& data); // Hiển thị dữ liệu
    TimeSlot* findTimeSlot(std::vector<TimeSlot>& data, const std::string& selectedTimeSlot); // Tìm khung giờ
};



