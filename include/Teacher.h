//
// Created by azmain inquaid haque on 4/17/2025.
//

#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Course.h"
#include "TimeSlot.h"

class Teacher {
public:
    Teacher(const std::string&code, const std::string &name, const std::string &designation);

    // Getters
    std::string getCode() const;
    std::string getName() const;

    std::string getDesignation() const;

    int getPriority() const;

    // Setters
    void setAvailableTimeSlots(const std::vector<TimeSlot> &slots);

    void addCourse(const Course &course);

    void addTimeSlot(const TimeSlot& timeSlot);

    const std::vector<TimeSlot> &getAvailableTimeSlots() const;

    const std::vector<Course> &getCourses() const;

private:
    std::string code;
    std::string name;
    std::string designation;
    int priority;

    std::vector<TimeSlot> availableTimeSlots;
    std::vector<Course> courses;

    void setPriorityFromDesignation();
};

#endif //TEACHER_H
