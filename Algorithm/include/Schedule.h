#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include <map>
#include <tuple>

#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"

using namespace std;

struct Assignment {
    Teacher *teacher;
    Course *course;
};

struct SessionAssignment {
    const Teacher* teacher;
    const Course* course;
    TimeSlot timeSlot;
};

struct day {
    map<pair<int, int>, vector<Assignment>> period;
};

class Schedule {
public:
    Schedule(const std::vector<Teacher> &teachers);

    void check();
    bool backtrack(int tIdx, int cIdx, int sIdx);
    void generateSchedule();
    bool possible(vector<Assignment> &it, Teacher *t, Course *c);
    void writeScheduleToCSV(const std::string& filename);
    bool isValidTimeSlot( Teacher *t,  Course* c,  TimeSlot& ts);
    // bool isEmpty(const std::string& day, const std::pair<int, int>& time, int year);
    void exportCSV(const std::string& filename) const;
    bool alreadyThere(const TimeSlot &ts, const Course &c, const Teacher &t);
private:
    std::map<string, int> day_string_to_int;
    std::vector<Teacher> teachers;
    std::vector<day> days;
    std::vector<std::string> weeks;
    std::vector<std::tuple<const Teacher*, const Course*, int>> sessionRequests;
    std::vector<SessionAssignment> assignments;
    std::map<std::pair<std::string, int>, std::vector<TimeSlot>> yearOccupied;
    std::map<std::pair<std::string, const Teacher*>, std::vector<TimeSlot>> teacherOccupied;
};

#endif // SCHEDULE_H