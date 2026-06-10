#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Student.h"
#include <string>
using namespace std;

class FileManager {
public:
    void saveStudents(Student arr[], int size, string filename);
    void loadStudents(Student arr[], int& size, string filename);
};

#endif