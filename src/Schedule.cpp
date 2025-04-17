#include "Schedule.h"
#include <fstream>
#include <map>
#include <tuple>

void Schedule::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

bool Schedule::isSlotFree(const TimeSlot& slot) const {
    for (const auto& a : assignments) {
        if (a.timeSlot.conflictsWith(slot)) {
            return false;
        }
    }
    return true;
}

Teacher* Schedule::getConflictingTeacher(const TimeSlot& slot) const {
    for (const auto& a : assignments) {
        if (a.timeSlot.conflictsWith(slot)) {
            return a.teacher;
        }
    }
    return nullptr;
}

void Schedule::generateSchedule() {
    for (Teacher* teacher : teachers) {
        for (const Course& course : teacher->getCourses()) {
            int sessions = course.getSessionsPerWeek();
            for (const TimeSlot& ts : teacher->getAvailableTimeSlots()) {
                if (sessions == 0) break;
                if (isSlotFree(ts)) {
                    assignments.push_back({teacher, course, ts});
                    --sessions;
                } else {
                    Teacher* other = getConflictingTeacher(ts);
                    if (other && other->getPriority() > teacher->getPriority()) {
                        for (auto& a : assignments) {
                            if (a.timeSlot.conflictsWith(ts)) {
                                a = {teacher, course, ts};
                                --sessions;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Schedule::exportCSV(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) return;

    std::vector<std::string> days = {"SUN", "MON", "TUES", "WED", "THRUS"};
    std::vector<int> hours = {8, 9, 10, 11, 12, 13, 14, 15, 16};

    std::map<std::tuple<std::string, int, int>, std::string> cell;
    for (const auto& a : assignments) {
        cell[{a.timeSlot.getDay(), a.timeSlot.getStartHour(), a.course.getYear()}] =
            a.teacher->getCode() + " " + a.course.getCode();
    }

    ofs << "Day,Year";
    for (int h : hours) {
        int h1 = (h % 12 == 0 ? 12 : h % 12);
        std::string am1 = (h < 12 ? "AM" : "PM");
        int h2 = ((h + 1) % 12 == 0 ? 12 : (h + 1) % 12);
        std::string am2 = ((h + 1) < 12 ? "AM" : "PM");
        ofs << "," << h1 << " " << am1 << "-" << h2 << " " << am2;
    }
    ofs << "\n";

    for (const auto& day : days) {
        for (int yr = 1; yr <= 4; ++yr) {
            ofs << day << "," << yr;
            for (int h : hours) {
                ofs << ",";
                auto it = cell.find({day, h, yr});
                if (it != cell.end()) ofs << it->second;
            }
            ofs << "\n";
        }
    }

    ofs.close();
}

void Schedule::exportTeachers(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) return;

    ofs << "Code,FullName\n";
    for (const auto* t : teachers) {
        ofs << t->getCode() << "," << t->getName() << "\n";
    }

    ofs.close();
}