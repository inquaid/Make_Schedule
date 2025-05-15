#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "TimeSlot.h"

class Course {
public:
    Course(const std::string &code, const std::string &title, float credit, int year, int term);
    std::string getCode() const;
    std::string getTitle() const;
    float getCredit() const;
    int getYear() const;
    int getTerm() const;
    bool isLabCourse() const;
    int getSessionCount() const;
    std::vector<int> getSessionDurations() const;
    void addAvailableTimeSlot(const TimeSlot &timeSlot);
    const std::vector<TimeSlot> &getAvailableTimeSlots() const;
    void inc();
    void dec();
    bool done();

private:
    std::string code;
    std::string title;
    float credit;
    int year, term;
    int totalSessionCount, sessionPlotted;
    std::vector<TimeSlot> availableTimeSlots;
};

#endif //COURSE_H