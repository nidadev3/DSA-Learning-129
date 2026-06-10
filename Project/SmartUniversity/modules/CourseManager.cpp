#include "CourseManager.h"
#include <iostream>
using namespace std;

void CourseManager::registerCourse(string course) {
    courseList.insertEnd(course);
    cout << "Course registered: " << course << endl;
}

void CourseManager::dropCourse(string course) {
    courseList.deleteNode(course);
    cout << "Course dropped: " << course << endl;
}

void CourseManager::displayCourses() {
    cout << "--- Registered Courses ---" << endl;
    courseList.display();
}

int CourseManager::getTotalCourses() {
    return courseList.getSize();
}