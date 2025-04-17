//
// Created by azmain inquaid haque on 4/17/2025.
//

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    Course(const std::string &code, const std::string &title, int sessionsPerWeek, int year);
    std::string getCode() const;
    std::string getTitle() const;
    int getSessionsPerWeek() const;
    int getYear() const;

private:
    std::string code;
    std::string title;
    int sessionsPerWeek;
    int year;
};

#endif //COURSE_H
