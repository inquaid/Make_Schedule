//
// Created by azmain inquaid haque on 4/17/2025.
//

#include "D:\program\Schedule_Management\include\Course.h"

Course::Course(const std::string &code, const std::string &title, int sessionsPerWeek, int year)
    : code(code), title(title), sessionsPerWeek(sessionsPerWeek), year(year) {
}

// Getters
std::string Course::getCode() const {
    return code;
}

std::string Course::getTitle() const {
    return title;
}

int Course::getSessionsPerWeek() const {
    return sessionsPerWeek;
}

int Course::getYear() const {
    return year;
}

