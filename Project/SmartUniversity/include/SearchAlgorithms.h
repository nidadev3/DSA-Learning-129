#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include "Student.h"

class SearchAlgorithms {
public:
    int linearSearch(Student arr[], int n, int rollNo);
    int binarySearch(Student arr[], int n, int rollNo);
};

#endif