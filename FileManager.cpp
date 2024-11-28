#include "FileManager.h"

// Them san vao file
Vector FileManager::loadFields(const string& filePath) {
    Menu menu;
    Vector fields;
    ifstream file(filePath);

    if (!file.is_open()) {
        system("cls");
        cout << "\t\t\t\t\t\tERROR: Unable to open file " << filePath << endl;
        menu.printRETURN();
        cin.ignore();
        cin.get();
        return fields;
    }

    string field;
    while (getline(file, field)) {
        fields.push_back(field);
    }

    file.close();
    return fields;
}

// Doc tat ca cac dong tu file vao vector
Vector FileManager::readAllLines(const string& filename) {
    ifstream file(filename);
    Vector lines;

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    return lines;
}

// Ghi tat ca cac dong tu vector vao file
void FileManager::writeAllLines(const string& filename, const Vector& lines) {
    ofstream file(filename, ios::trunc);
    for (size_t i = 0; i < lines.get_size(); i++) {
        file << lines[i] << endl;
    }
    file.close();
}