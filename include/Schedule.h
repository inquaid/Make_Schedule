//// include/Schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <tuple>
#include <string>
#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"
#include "Schedule.h"

// Helper struct for an assignment
struct Assignment {
    Teacher* teacher;
    Course course;
    TimeSlot timeSlot;
};

class Schedule {
public:
    void addTeacher(Teacher* teacher);
    void generateSchedule();
    void exportCSV(const std::string& filename) const;
    void exportTeachers(const std::string & filename) const;

private:
    std::vector<Teacher*> teachers;
    std::vector<Assignment> assignments;

    bool isSlotFree(const TimeSlot& slot) const;
    Teacher* getConflictingTeacher(const TimeSlot& slot) const;
};

#endif // SCHEDULE_H
