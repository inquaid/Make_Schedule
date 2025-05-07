#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Course.h"
#include "TimeSlot.h"

class Teacher {
public:
    Teacher(const std::string &code, const std::string &name, const std::string &designation);
    std::string getCode() const;
    std::string getName() const;
    std::string getDesignation() const;
    int getPriority() const;
    void addCourse(std::vector<Course> &course);
    void addTimeSlot(std::vector<TimeSlot> &timeSlot);
    const std::vector<Course> &getCourses() const;

private:
    std::string code;
    std::string name;
    std::string designation;
    int priority;
    std::vector<Course> courses;
    std::vector<TimeSlot> timeSlots;

    void setPriorityFromDesignation();
};

#endif //TEACHER_H