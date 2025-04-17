//
// Created by azmain inquaid haque on 4/17/2025.
//

#include "D:\program\Schedule_Management\include\Teacher.h"

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

void Teacher::setAvailableTimeSlots(const std::vector<TimeSlot> &slots) {
    availableTimeSlots = slots;
}

void Teacher::addCourse(const Course &course) {
    courses.push_back(course);
}

void Teacher::addTimeSlot(const TimeSlot &timeSlot) {
    availableTimeSlots.push_back(timeSlot);
}

const std::vector<TimeSlot> &Teacher::getAvailableTimeSlots() const {
    return availableTimeSlots;
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
