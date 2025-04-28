#include "Course.h"
#include <cmath>

Course::Course(const std::string &code, const std::string &title, float credit, int year)
    : code(code), title(title), credit(credit), year(year) {
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

std::vector<int> Course::getSessionDurations() const {
    if (std::floor(credit) == credit) {
        // Theory course: credit number of 1-hour sessions
        return std::vector<int>(static_cast<int>(credit), 1);
    } else {
        // Lab course: one 3-hour session
        return {3};
    }
}

void Course::addAvailableTimeSlot(const TimeSlot &timeSlot) {
    availableTimeSlots.push_back(timeSlot);
}

const std::vector<TimeSlot> &Course::getAvailableTimeSlots() const {
    return availableTimeSlots;
}