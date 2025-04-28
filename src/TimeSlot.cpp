#include "TimeSlot.h"

TimeSlot::TimeSlot(const std::string &day, int startHour, int endHour)
    : day(day), startHour(startHour), endHour(endHour) {
}

std::string TimeSlot::getDay() const {
    return day;
}

int TimeSlot::getStartHour() const {
    return startHour;
}

int TimeSlot::getEndHour() const {
    return endHour;
}

int TimeSlot::getDuration() const {
    return endHour - startHour;
}

bool TimeSlot::conflictsWith(const TimeSlot &other) const {
    if (day != other.day) return false;
    return !(endHour <= other.startHour || startHour >= other.endHour);
}

std::string TimeSlot::toString() const {
    return day + " " + std::to_string(startHour) + ":00 - " + std::to_string(endHour) + ":00";
}