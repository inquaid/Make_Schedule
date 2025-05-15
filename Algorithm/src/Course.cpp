#include "Course.h"
#include <cmath>

Course::Course(const std::string &code, const std::string &title, float credit, int year, int term)
    : code(code), title(title), credit(credit), year(year), term(term) {
    if (isLabCourse()) {
        totalSessionCount = 1;
    } else {
        totalSessionCount = ceil(credit);
    }
    sessionPlotted = 0;
}

void Course::inc() {
    sessionPlotted++;
    // return sessionPlotted == totalSessionCount;
}

bool Course::done() {
    return sessionPlotted == totalSessionCount;
}

void Course::dec() {
    sessionPlotted--;
    sessionPlotted = std::max(sessionPlotted, 0);
    // return sessionPlotted == 0;
}

int Course::getSessionCount() const {
    return totalSessionCount;
}

std::string Course::getCode() const {
    return code;
}

std::string Course::getTitle() const {
    return title;
}

float Course::getCredit() const {
    return credit;
}

int Course::getYear() const {
    return year;
}

int Course::getTerm() const {
    return term;
}

bool Course::isLabCourse() const {
    char lastChar = code.back();
    if (std::isdigit(lastChar)) {
        int lastDigit = lastChar - '0';
        return lastDigit % 2 == 0;
    }
    return false;
}


std::vector<int> Course::getSessionDurations() const {
    if (isLabCourse()) {
        return {3};
    } else {
        int numSessions = static_cast<int>(credit);
        return std::vector <int>(numSessions, 1);
    }
}

void Course::addAvailableTimeSlot(const TimeSlot &timeSlot) {
    availableTimeSlots.push_back(timeSlot);
}

const std::vector<TimeSlot> &Course::getAvailableTimeSlots() const {
    return availableTimeSlots;
}