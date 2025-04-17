//
// Created by azmain inquaid haque on 4/17/2025.
//

#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>

class TimeSlot {
public:
    TimeSlot(const std::string& day, int startHour, int endHour);
    std::string getDay() const;
    int getStartHour() const;
    int getEndHour() const;

    bool conflictsWith(const TimeSlot& other) const;
    std::string toString() const;

private:
    std::string day; // e.g., "Monday"
    int startHour;   // 24h format, e.g., 9 for 9 AM
    int endHour;     // exclusive, e.g., 10 means ends at 10
};

#endif //TIMESLOT_H
