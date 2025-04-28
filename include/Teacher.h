#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Course.h"

class Teacher {
public:
    Teacher(const std::string &code, const std::string &name, const std::string &designation);
    std::string getCode() const;
    std::string getName() const;
    std::string getDesignation() const;
    int getPriority() const;
    void addCourse(const Course &course);
    const std::vector<Course> &getCourses() const;

private:
    std::string code;
    std::string name;
    std::string designation;
    int priority;
    std::vector<Course> courses;

    void setPriorityFromDesignation();
};

#endif //TEACHER_H