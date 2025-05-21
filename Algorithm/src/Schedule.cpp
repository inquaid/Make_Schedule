#include "Schedule.h"
#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

void Schedule::check() {
    cout << "Hello World!" << endl;

    int flag = backtrack(0, 0, 0);
    // cout << flag << endl;
    // for (auto i : day_string_to_int) {
    //     cout << i.first << " " << i.second << endl;
    // }
    int indx = 0;
    Teacher *t = new Teacher("AI", "Azmain Inquaid", "Professor");
    Course *c = new Course("1012", "Introduction to Computer Science", 3, 2020, 1);
    TimeSlot *ts = new TimeSlot("monday", 14, 15);
    // cout << isValidTimeSlot(t, c, *ts) << endl;
    // cout << isValidTimeSlot(t, c, *ts) << endl;
    // Assignment a = {t, c};
    // days[1].period[{10, 11}].push_back(a);
    for (auto i: days) {
        cout << weeks[indx++] << endl;
        for (auto j: i.period) {
            cout << j.first.first << " " << j.first.second << " " << j.second.size() << endl;
            for (auto k: j.second) {
                cout << k.teacher->getName() << " " << k.course->getTitle() << endl;
            }
        }
    }
}

bool Schedule::possible(vector<Assignment> &it, Teacher *t, Course *c) {
    if (it.size() >= 4) {
        return false;
    }
    for (auto &i: it) {
        if (i.teacher == t) {
            return false;
        }
        if (i.course == c) {
            return false;
        }
        if (i.course->getYear() == c->getYear()) {
            return false;
        }
    }
    return true;
}

// Helper function to check if a time slot is valid for a course
bool Schedule::isValidTimeSlot(Teacher *t, Course *c, TimeSlot &ts) {
    if (ts.getStartHour() == 13) {
        // return false;
    }
    // cout << t->getName() << " " << c->getTitle() << " " << ts.getDay() << " " << ts.getStartHour() << " " << ts.getEndHour() << endl;
    if (c->isLabCourse()) {
        if (ts.getStartHour() != 14) {
            return false;
        }
        auto &t1 = days[day_string_to_int[ts.getDay()]].period[{ts.getStartHour(), ts.getEndHour()}];
        auto &t2 = days[day_string_to_int[ts.getDay()]].period[{ts.getStartHour() + 1, ts.getEndHour() + 1}];
        auto &t3 = days[day_string_to_int[ts.getDay()]].period[{ts.getStartHour() + 2, ts.getEndHour() + 2}];
        if (possible(t1, t, c) && possible(t2, t, c) && possible(t3, t, c)) {
            Assignment a = {t, c};
            t1.push_back(a);
            t2.push_back(a);
            t3.push_back(a);
            return true;
        } else {
            return false;
        }
    } else {
        // cout << ts.getDay() << " " << ts.getStartHour() << " " << ts.getEndHour() << endl;
        // if (ts.getStartHour() == 13) {
        //     return false;
        // }
        // cout << day_string_to_int[ts.getDay()] << endl;
        auto &it = days[day_string_to_int[ts.getDay()]].period[{ts.getStartHour(), ts.getEndHour()}];
        // cout << it.size() << endl;
        if (possible(it, t, c)) {
            Assignment a = {t, c};
            // cout << a.teacher->getName() << " " << a.course->getTitle() << endl;
            // cout << it.size() << endl;
            it.push_back(a);
            // cout << it.size() << endl;
            // cout << "Added" << endl;
            return true;
        } else {
            return false;
        }
    }
    // return true;
}

Schedule::Schedule(const std::vector<Teacher> &teachers)
    : teachers(teachers) {
    day d1;
    for (int i = 8; i < 17; i++) {
        d1.period[{i, i + 1}];
    }
    for (int i = 0; i < 5; i++) {
        days.push_back(d1);
    }
    weeks = {"sunday", "monday", "tuesday", "wednesday", "thursday"};
    for (int i = 0; i < weeks.size(); i++) {
        day_string_to_int[weeks[i]] = i;
    }
}

bool Schedule::alreadyThere(const TimeSlot &ts, const Course &c, const Teacher &t) {
    auto temp = days[day_string_to_int[ts.getDay()]];
    for (auto &i: temp.period) {
        for (auto &j: i.second) {
            if (j.course == &c or j.teacher == &t) {
                return false;
            }
        }
    }
    return true;
}

bool Schedule::backtrack(int tIdx, int cIdx, int sIdx) {
    if (tIdx >= teachers.size()) return true;
    Teacher &t = teachers[tIdx];
    const auto &courses = t.getCourses();
    if (cIdx >= courses.size()) return backtrack(tIdx + 1, 0, 0);

    const Course &c = courses[cIdx];
    int totalSessions = c.isLabCourse() ? 1 : c.getCredit();
    if (sIdx >= totalSessions) return backtrack(tIdx, cIdx + 1, 0);
    vector<TimeSlot> remainingTimeSlots;
    for (const TimeSlot &ts: t.getTimeSlots()) {
        if (c.isLabCourse() && ts.getStartHour() != 14) continue;

        if (!alreadyThere(ts, c, t)) {
            remainingTimeSlots.push_back(ts);
            continue;
        }

        if (isValidTimeSlot(&t, const_cast<Course *>(&c), const_cast<TimeSlot &>(ts))) {
            if (backtrack(tIdx, cIdx, sIdx + 1)) return true;
            int dayIdx = day_string_to_int[ts.getDay()];
            if (c.isLabCourse()) {
                for (int d = 0; d < 3; ++d) {
                    days[dayIdx].period[{ts.getStartHour() + d, ts.getStartHour() + d + 1}].pop_back();
                }
            } else {
                days[dayIdx].period[{ts.getStartHour(), ts.getEndHour()}].pop_back();
            }
        }
    }

    vector<TimeSlot> remainingTimeSlots2;
    for (const TimeSlot &ts: remainingTimeSlots) {
        if (c.isLabCourse() && ts.getStartHour() != 14) continue;

        if (!alreadyThere(ts, c, t)) {
            remainingTimeSlots2.push_back(ts);
            continue;
        }

        if (isValidTimeSlot(&t, const_cast<Course *>(&c), const_cast<TimeSlot &>(ts))) {
            if (backtrack(tIdx, cIdx, sIdx + 1)) return true;
            int dayIdx = day_string_to_int[ts.getDay()];
            if (c.isLabCourse()) {
                for (int d = 0; d < 3; ++d) {
                    days[dayIdx].period[{ts.getStartHour() + d, ts.getStartHour() + d + 1}].pop_back();
                }
            } else {
                days[dayIdx].period[{ts.getStartHour(), ts.getEndHour()}].pop_back();
            }
        }
    }

    for (const TimeSlot &ts: remainingTimeSlots2) {
        if (c.isLabCourse() && ts.getStartHour() != 14) continue;

        // if (!alreadyThere(ts, c, t)) {
        //     remainingTimeSlots2.push_back(ts);
        //     continue;
        // }

        if (isValidTimeSlot(&t, const_cast<Course *>(&c), const_cast<TimeSlot &>(ts))) {
            if (backtrack(tIdx, cIdx, sIdx + 1)) return true;
            int dayIdx = day_string_to_int[ts.getDay()];
            if (c.isLabCourse()) {
                for (int d = 0; d < 3; ++d) {
                    days[dayIdx].period[{ts.getStartHour() + d, ts.getStartHour() + d + 1}].pop_back();
                }
            } else {
                days[dayIdx].period[{ts.getStartHour(), ts.getEndHour()}].pop_back();
            }
        }
    }

    return false;
}


void Schedule::generateSchedule() {
    // sessionRequests.clear();
    // assignments.clear();
    // yearOccupied.clear();
    // teacherOccupied.clear();
    //
    // // Generate session requests based on courses
    // for (const auto &teacher: teachers) {
    //     for (const auto &course: teacher.getCourses()) {
    //         int totalHours = static_cast<int>(course.getCredit());
    //         if (course.isLabCourse()) {
    //             sessionRequests.emplace_back(&teacher, &course, 3); // Lab
    //         } else {
    //             for (int i = 0; i < totalHours; i++) {
    //                 // Theory
    //                 sessionRequests.emplace_back(&teacher, &course, 1);
    //             }
    //         }
    //     }
    // }
    //
    // // Sort session requests: prioritize lab courses and higher credit courses
    // std::sort(sessionRequests.begin(), sessionRequests.end(),
    //           [](const auto &a, const auto &b) {
    //               const auto *courseA = std::get<1>(a);
    //               const auto *courseB = std::get<1>(b);
    //               if (courseA->isLabCourse() != courseB->isLabCourse()) {
    //                   return courseA->isLabCourse();
    //               }
    //               return courseA->getCredit() > courseB->getCredit();
    //           });

    // Attempt scheduling
    int flag = backtrack(0, 0, 0);
    // cout << flag << endl;
    if (flag) {
        std::cout << "success" << std::endl;
        exportCSV("schedule.csv");
    } else {
        std::cout << "error" << std::endl;
    }
}

void Schedule::exportCSV(const std::string &filename) const {
    std::ofstream ofs(filename);
    if (!ofs) return;

    std::vector<std::string> header_days = {"sunday", "monday", "tuesday", "wednesday", "thursday"};
    std::vector<std::string> days_abbr = {"SUN", "MON", "TUE", "WED", "THU"};
    std::vector<int> hours = {8, 9, 10, 11, 12, 13, 14, 15, 16};

    // Build a lookup table: (day, hour, year) -> "TCH CODE CRS CODE"
    std::map<std::tuple<std::string, int, int>, std::string> cell;

    for (int d = 0; d < (int) days.size(); ++d) {
        const auto &day = days[d];
        std::string day_str = header_days[d];

        for (const auto &slot: day.period) {
            int start = slot.first.first;
            int end = slot.first.second;

            for (const auto &assignment: slot.second) {
                for (int h = start; h < end; ++h) {
                    cell[{day_str, h, assignment.course->getYear()}] =
                            assignment.teacher->getCode() + " " + assignment.course->getCode();
                }
            }
        }
    }

    // Write CSV header
    ofs << "Day,Year";
    for (int h: hours) {
        int h1 = (h % 12 == 0 ? 12 : h % 12);
        std::string am1 = (h < 12 ? "AM" : "PM");
        int h2 = ((h + 1) % 12 == 0 ? 12 : (h + 1) % 12);
        std::string am2 = ((h + 1) < 12 ? "AM" : "PM");
        ofs << "," << h1 << " " << am1 << "-" << h2 << " " << am2;
    }
    ofs << "\n";

    // Write schedule data
    for (int d = 0; d < (int) header_days.size(); ++d) {
        const std::string &day_str = header_days[d];
        const std::string &abbr = days_abbr[d];

        for (int yr = 1; yr <= 4; ++yr) {
            ofs << abbr << "," << yr;
            for (int h: hours) {
                ofs << ",";
                auto it = cell.find({day_str, h, yr});
                if (it != cell.end()) {
                    ofs << it->second;
                }
            }
            ofs << "\n";
        }
    }
}
