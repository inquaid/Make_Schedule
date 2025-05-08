#include "Schedule.h"
#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <algorithm>
#include <stdexcept>

using namespace std;

Schedule::Schedule(const std::vector<Teacher> &teachers)
    : teachers(teachers) {
    day d1;
    for (int i = 9; i < 17; i++) {
        d1.period[{i, i + 1}];
    }
    for (int i = 0; i < 6; i++) {
        days.push_back(d1);
    }
    weeks = {"sunday", "monday", "tuesday", "wednesday", "thursday"};
}


void Schedule::check() {
    // for (auto i : weeks) cout << i << " ";
    for (int i = 0; i < days.size(); i++) {
        // cout << weeks[i]  << endl;
        for (int ts = 9; ts < 17; ts++) {
            if (days[i].period[{ts, ts + 1}].size()) {
                for (int k = 0; k < days[i].period[{ts, ts + 1}].size(); k++) {
                    cout << days[i].period[{ts, ts + 1}][k].teacher->getName()  << endl;
                }
            } // else cout << "EMPTY\n";
        }
    }
    // for (auto teacher : teacher)
    // cout << "Checking schedule..." << endl;
    // for (auto p : days[4].period) {
    //     cout << p.first.first << " " << p.first.second  << endl;
    // }
    // Assignment a1;
    //
    // days[2].period[{9, 10}].push_back(a1);
    // cout << days[2].period[{9, 10}].size() << endl;
    // cout << d1.period.size() << endl;
    // for (auto t : teachers) {
        // cout << t.getName() << " " << t.getDesignation() << " " << t.getPriority() << endl;
        // for (auto course : t.getCourses()) {
        //     cout << course.getCode() << endl;
        // }
        // cout << endl;
        // for (auto time : t.getTimeSlots()) {
        //     cout << time.getStartHour() << " " << time.getEndHour() << endl;
        // }
        // cout << endl << endl;
    // }
    // generateSchedule();
}

bool Schedule::possible() {

}


bool Schedule::backtrack(int i) {
    if (i == 0) {
        cout << "Backtracking schedule..." << endl;
        return true;
    } else {
        Teacher temp_teacher = teachers[i - 1];
        // cout << temp_teacher.getName() << endl;
        // backtrack(i - 1);
        for (auto course : temp_teacher.getCourses()) {
            vector<TimeSlot> ts = temp_teacher.getTimeSlots();
            for (auto t : ts ) {

            }
        }


    }

    return 1;
}

void Schedule::generateSchedule() {
    bool flag = backtrack(teachers.size());
    // backtrack(teachers.size());
    // cout << teachers.size() << endl;
}


// void Schedule::addTeacher(Teacher *teacher) {
//     teachers.push_back(teacher);
// }
//
// bool Schedule::backtrack(int idx, const std::vector<SessionRequest> &sessions, const std::map<std::string, Teacher*> &courseToTeacher) {
//     if (idx == sessions.size())
//         return true;
//
//     const Course &course = sessions[idx].course;
//     int duration = sessions[idx].duration;
//     Teacher* teacher = courseToTeacher.at(course.getCode());
//
//     for (const TimeSlot &ts : course.getAvailableTimeSlots()) {
//         if (ts.getDuration() != duration) continue;
//         bool conflict = false;
//         for (const auto& a : assignments) {
//             if ((a.course.getYear() == course.getYear() && a.timeSlot.conflictsWith(ts)) ||
//                 (a.teacher == teacher && a.timeSlot.conflictsWith(ts))) {
//                 conflict = true;
//                 break;
//             }
//         }
//         if (conflict) continue;
//
//         assignments.push_back({teacher, course, ts});
//         if (backtrack(idx + 1, sessions, courseToTeacher))
//             return true;
//
//         assignments.pop_back();
//     }
//
//     return false;
// }
//
// void Schedule::generateSchedule() {
//     std::vector<SessionRequest> sessions;
//     std::map<std::string, Teacher*> courseToTeacher;
//
//     std::sort(teachers.begin(), teachers.end(), [](const Teacher* a, const Teacher* b) {
//         return a->getPriority() < b->getPriority();
//     });
//
//     for (Teacher* t : teachers) {
//         for (const Course& c : t->getCourses()) {
//             courseToTeacher[c.getCode()] = t;
//             for (int dur : c.getSessionDurations()) {
//                 sessions.push_back({c, dur});
//             }
//         }
//     }
//
//     if (!backtrack(0, sessions, courseToTeacher)) {
//         throw std::runtime_error("Unable to find a conflict-free schedule");
//     }
// }
//
// void Schedule::exportCSV(const std::string &filename) const {
//     std::ofstream ofs(filename);
//     if (!ofs) return;
//
//     std::vector<std::string> days = {"SUN", "MON", "TUE", "WED", "THU"};
//     std::vector<int> hours = {8, 9, 10, 11, 12, 13, 14, 15, 16};
//
//     std::map<std::tuple<std::string, int, int>, std::string> cell;
//     for (const auto &a : assignments) {
//         int start = a.timeSlot.getStartHour();
//         int end = a.timeSlot.getEndHour();
//         for (int h = start; h < end; ++h) {
//             cell[{a.timeSlot.getDay(), h, a.course.getYear()}] = a.teacher->getCode() + " " + a.course.getCode();
//         }
//     }
//
//     ofs << "Day,Year";
//     for (int h : hours) {
//         int h1 = (h % 12 == 0 ? 12 : h % 12);
//         std::string am1 = (h < 12 ? "AM" : "PM");
//         int h2 = ((h + 1) % 12 == 0 ? 12 : (h + 1) % 12);
//         std::string am2 = ((h + 1) < 12 ? "AM" : "PM");
//         ofs << "," << h1 << " " << am1 << "-" << h2 << " " << am2;
//     }
//     ofs << "\n";
//
//     for (const auto &day : days) {
//         for (int yr = 1; yr <= 4; ++yr) {
//             ofs << day << "," << yr;
//             for (int h : hours) {
//                 ofs << ",";
//                 auto it = cell.find({day, h, yr});
//                 if (it != cell.end()) ofs << it->second;
//             }
//             ofs << "\n";
//         }
//     }
// }
//
// void Schedule::exportTeachers(const std::string &filename) const {
//     std::ofstream ofs(filename);
//     if (!ofs) return;
//
//     ofs << "Code,FullName\n";
//     for (const auto *t : teachers) {
//         ofs << t->getCode() << "," << t->getName() << "\n";
//     }
// }