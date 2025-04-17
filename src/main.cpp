// src/main.cpp
#include <iostream>
#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"
#include "Schedule.h"

int main() {
    // 1) Create courses: code, title, sessions/week, year
    Course os("CSE301", "Operating Systems", 2, 3);
    Course dsa("CSE201", "Data Structures",    3, 4);

    // 2) Create teachers: code, full name, priority
    Teacher prof("MAR", "Prof. Md. Anisur Rahman",        "Professor");
    Teacher lect("SAH", "Mr. Sheikh Alamgir Hossain",    "Associate Professor");

    // 3) Assign courses
    prof.addCourse(os);
    lect.addCourse(dsa);

    // 4) Assign available slots (must match your CSV days)
    prof.addTimeSlot(TimeSlot("SUN",    9, 10));
    prof.addTimeSlot(TimeSlot("WED",10, 11));

    lect.addTimeSlot(TimeSlot("SUN",   9, 10));  // conflict
    lect.addTimeSlot(TimeSlot("TUES",11, 12));
    lect.addTimeSlot(TimeSlot("THRUS", 9, 10));

    // 5) Build and run scheduler
    Schedule sched;
    sched.addTeacher(&prof);
    sched.addTeacher(&lect);
    sched.generateSchedule();

    // 6) Export only to CSV (no printSchedule)
    sched.exportCSV("routine.csv");

    sched.exportTeachers("teachers.csv");
    std::cout << "Wrote routine.csv\n";
    return 0;
}
