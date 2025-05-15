#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>

class TimeSlot {
public:
    TimeSlot(const std::string& day, int startHour, int endHour);
    std::string getDay() const;
    int getStartHour() const;
    int getEndHour() const;
    int getDuration() const;
    bool conflictsWith(const TimeSlot& other) const;
    std::string toString() const;

private:
    std::string day;
    int startHour;
    int endHour;
};

#endif //TIMESLOT_H