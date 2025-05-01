#include <iostream>
#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"
#include "Schedule.h"

int main() {
    // Define Courses
    Course ComputerFundamentalsLab("071402CSE1100", "Computer Fundamentals Laboratory", 0.5, 1);
    ComputerFundamentalsLab.addAvailableTimeSlot(TimeSlot("SUN", 14, 17)); // 3h
    ComputerFundamentalsLab.addAvailableTimeSlot(TimeSlot("WED", 14, 17)); // 3h

    Course StructuredProgramming("071402CSE1101", "Structured Programming", 3, 1);
    StructuredProgramming.addAvailableTimeSlot(TimeSlot("MON", 11, 12));   // 1h
    StructuredProgramming.addAvailableTimeSlot(TimeSlot("TUE", 9, 10));    // 1h
    StructuredProgramming.addAvailableTimeSlot(TimeSlot("THU", 11, 12));   // 1h

    Course StructuredProgrammingLab("071402CSE1102", "Structured Programming Laboratory", 0.5, 1);
    StructuredProgrammingLab.addAvailableTimeSlot(TimeSlot("THU", 14, 17)); // 3h
    StructuredProgrammingLab.addAvailableTimeSlot(TimeSlot("FRI", 14, 17)); // 3h

    Course DiscreteMath("071402CSE1103", "Discrete Mathematics", 2, 1);
    DiscreteMath.addAvailableTimeSlot(TimeSlot("SUN", 10, 11));            // 1h
    DiscreteMath.addAvailableTimeSlot(TimeSlot("TUE", 9, 10));             // 1h
    DiscreteMath.addAvailableTimeSlot(TimeSlot("TUE", 10, 11));             // 1h
    DiscreteMath.addAvailableTimeSlot(TimeSlot("THU", 9, 10));             // 1h

    Course Calculus("054102Math1151", "Calculus", 3, 1);
    Calculus.addAvailableTimeSlot(TimeSlot("SUN", 11, 12));                // 1h
    Calculus.addAvailableTimeSlot(TimeSlot("MON", 9, 10));                 // 1h
    Calculus.addAvailableTimeSlot(TimeSlot("WED", 9, 10));                 // 1h

    Course Physics("053302Phy1151", "Physics", 3, 1);
    Physics.addAvailableTimeSlot(TimeSlot("SUN", 9, 10));                  // 1h
    Physics.addAvailableTimeSlot(TimeSlot("TUE", 12, 13));                 // 1h
    Physics.addAvailableTimeSlot(TimeSlot("WED", 10, 11));                 // 1h

    Course PhysicsLab("053302Phy1152", "Physics Laboratory", 0.5, 1);
    PhysicsLab.addAvailableTimeSlot(TimeSlot("MON", 14, 17));              // 3h
    PhysicsLab.addAvailableTimeSlot(TimeSlot("WED", 14, 17));              // 3h

    Course English("023102Eng1151", "English", 2, 1);
    English.addAvailableTimeSlot(TimeSlot("SUN", 12, 13));                 // 1h
    English.addAvailableTimeSlot(TimeSlot("THU", 12, 13));                 // 1h

    Course EnglishLab("023102Eng1152", "English Skills Laboratory", 0.5, 1);
    EnglishLab.addAvailableTimeSlot(TimeSlot("TUE", 14, 17));              // 3h
    EnglishLab.addAvailableTimeSlot(TimeSlot("FRI", 14, 17));              // 3h

    // Create Teachers
    Teacher farhan("MFS", "Md. Farhan Sadique", "Lecturer");
    Teacher mondal("MSM", "Dr. Manishankar Mondal", "Associate Professor");
    Teacher arif("ASM", "Dr. Abu Shamim Mohammad Arif", "Professor");
    Teacher firoz("SFA", "Dr. Sarder Firoz Ahmmed", "Professor");
    Teacher parvez("MSP", "Md. Shohel Parvez", "Associate Professor");
    Teacher shahin("ARS", "Dr. Abdur Rahman Shahin", "Professor");

    // Assign courses to teachers
    farhan.addCourse(ComputerFundamentalsLab);

    mondal.addCourse(StructuredProgramming);
    mondal.addCourse(StructuredProgrammingLab);

    arif.addCourse(DiscreteMath);

    firoz.addCourse(Calculus);

    parvez.addCourse(Physics);
    parvez.addCourse(PhysicsLab);

    shahin.addCourse(English);
    shahin.addCourse(EnglishLab);

    // Build & run scheduler
    Schedule sched;
    sched.addTeacher(&farhan);
    sched.addTeacher(&mondal);
    sched.addTeacher(&arif);
    sched.addTeacher(&firoz);
    sched.addTeacher(&parvez);
    sched.addTeacher(&shahin);

    try {
        sched.generateSchedule();
        sched.exportCSV("routine.csv");
        sched.exportTeachers("teachers.csv");
        std::cout << "Schedule generated! Check routine.csv and teachers.csv\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}