#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vector {
private:
    string* data;       // Con trỏ tới mảng dữ liệu
    size_t capacity;    // Dung lượng hiện tại của mảng
    size_t size;        // Số lượng phần tử trong mảng

public:
    // Constructor mặc định
    Vector() : data(nullptr), capacity(0), size(0) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Thêm phần tử vào cuối
    void push_back(const string& value) {
        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            string* new_data = new string[new_capacity];

            // Sao chép dữ liệu cũ sang mảng mới
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            delete[] data; // Giải phóng mảng cũ
            data = new_data;
            capacity = new_capacity;
        }

        data[size++] = value;
    }

    // Truy cập phần tử bằng chỉ số (không thay đổi)
    const string& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Truy cập phần tử bằng chỉ số (có thể thay đổi)
    string& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Xóa phần tử ở chỉ số index
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }

        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size;
    }

    // Lấy số lượng phần tử
    size_t get_size() const {
        return size;
    }

    // Kiểm tra vector rỗng
    bool empty() const {
        return size == 0;
    }
    
};
