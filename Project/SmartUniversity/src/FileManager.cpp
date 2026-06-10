#include "../include/FileManager.h"
#include <fstream>
#include <iostream>
using namespace std;

void FileManager::saveStudents(Student arr[], int size, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        file << arr[i].rollNo << ","
             << arr[i].name << ","
             << arr[i].department << ","
             << arr[i].cgpa << "\n";
    }
    file.close();
}

void FileManager::loadStudents(Student arr[], int& size, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }
    size = 0;
    string line;
    while (getline(file, line)) {
        Student s;
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1 + 1);
        int pos3 = line.find(',', pos2 + 1);
        s.rollNo = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.department = line.substr(pos2 + 1, pos3 - pos2 - 1);
        s.cgpa = stof(line.substr(pos3 + 1));
        arr[size++] = s;
    }
    file.close();
}