#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include <map>

#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"

using namespace std;

struct Assignment {
    Teacher *teacher;
    Course *course;
};

struct day {
    map<pair<int, int>, vector<Assignment>> period;
};

class Schedule {
public:

    Schedule(const std::vector<Teacher> &teachers);

    struct SessionRequest {
        Course course;
        int duration;
    };

    void check();
    bool backtrack(int i);
    void generateSchedule();
    bool possible();

private:
    std::vector<Teacher> teachers;
    std::vector<day> days;
    std::vector<string> weeks;
};

#endif // SCHEDULE_H