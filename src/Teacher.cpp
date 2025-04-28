#include "Teacher.h"

Teacher::Teacher(const std::string &code, const std::string &name, const std::string &designation)
    : code(code), name(name), designation(designation) {
    setPriorityFromDesignation();
}

std::string Teacher::getCode() const {
    return code;
}

std::string Teacher::getName() const {
    return name;
}

std::string Teacher::getDesignation() const {
    return designation;
}

int Teacher::getPriority() const {
    return priority;
}

void Teacher::addCourse(const Course &course) {
    courses.push_back(course);
}

const std::vector<Course> &Teacher::getCourses() const {
    return courses;
}

void Teacher::setPriorityFromDesignation() {
    if (designation == "Professor") {
        priority = 1;
    } else if (designation == "Associate Professor") {
        priority = 2;
    } else if (designation == "Lecturer") {
        priority = 3;
    } else if (designation == "Assistant Lecturer") {
        priority = 4;
    } else {
        priority = 5;
    }
}