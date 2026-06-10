#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include "../include/SinglyLL.h"

class CourseManager {
private:
    SinglyLL courseList;
public:
    void registerCourse(string course);
    void dropCourse(string course);
    void displayCourses();
    int getTotalCourses();
};

#endif