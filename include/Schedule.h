#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include <map>
#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"

struct Assignment {
    Teacher* teacher;
    Course course;
    TimeSlot timeSlot;
};

class Schedule {
public:
    struct SessionRequest {
        Course course;
        int duration;
    };

    void addTeacher(Teacher* teacher);
    void generateSchedule();
    void exportCSV(const std::string& filename) const;
    void exportTeachers(const std::string &filename) const;
    bool backtrack(int idx, const std::vector<SessionRequest> &sessions, const std::map<std::string, Teacher*> &courseToTeacher);

private:
    std::vector<Teacher*> teachers;
    std::vector<Assignment> assignments;
};

#endif // SCHEDULE_H