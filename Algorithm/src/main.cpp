#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <unistd.h>
#include "Teacher.h"
#include "Course.h"
#include "TimeSlot.h"
#include "Schedule.h"
using namespace std;

map <string, pair<string, int>> course_credit;
vector<string> days = {"sunday", "monday", "tuesday", "wednesday", "thursday"};

void add_courses(vector<Course> &courses, string courseCode) {
    string title = course_credit[courseCode].first;
    int credit = course_credit[courseCode].second;
    int year = courseCode[courseCode.size() - 4] - '0';
    int term = courseCode[courseCode.size() - 3] - '0';
    courses.push_back(*new Course(courseCode, title, credit, year, term));
}

void add_timeslots(vector<TimeSlot> &timeslots, string timeslot, int day) {
    // return;
    if (timeslot == "NULL") return;
    int strt = 0, end = 0;
    string temp;
    // if (timeslot[0] == ' ') {
    //     // timeslots[0] = '?';
    //     timeslot.erase(timeslot.begin());
    //     cout << timeslot << " ";
    // }
    // return;
    while (timeslot.size() and timeslot[0] == ' ') {
        timeslot.erase(timeslot.begin());
    }
    // if (!timeslot.size()) {cout <<"NULL\n"; return;}
    if (timeslot[0] == '1') {
        temp = "";
        temp += timeslot[0]; temp += timeslot[1];
        strt = stoi(temp);
        // cout << timeslot << " " << temp << endl;
        timeslot.erase(timeslot.begin(), timeslot.begin() + 3);
        end = stoi(timeslot);
        // cout << strt << " " << end << endl;
    } else {
        temp = "";
        temp += timeslot[0];
        // cout << timeslot << " " << temp << endl;
        strt = stoi(temp);
        timeslot.erase(timeslot.begin(), timeslot.begin() + 2);
        end = stoi(timeslot);
    }
    // return;
    // cout << endl;
    // cout << strt << " " << end << endl;
    if (strt < 9) strt += 12;
    if (end < 9) end += 12;
    while (strt < end) {
        timeslots.push_back(*new TimeSlot(days[day], strt, strt + 1));
        // cout << strt << " " << end << endl;
        strt++;
    }
}

int main() {

    // char cwd[1024];
    // getcwd(cwd, sizeof(cwd));
    // std::cout << "Current working directory: " << cwd << std::endl;
    // return 0;
    // ifstream in("/home/turjo-pop/Documents/Make_Schedule/Algorithm/db/teachers_timeslot.csv");
    // ifstream in_course("/home/turjo-pop/Documents/Make_Schedule/Algorithm/db/credits.csv");
    ifstream in("../db/teachers_timeslot.csv");
    ifstream in_course("../db/credits.csv");

    if (!in.is_open() or !in_course.is_open()) {
        cerr << "Unable to open file" << endl;
    }
    else cerr << "opened" << endl;

    string row;
    getline(in_course, row);
    // cout << row << endl;
    stringstream crs(row);
    while (getline(in_course, row)) {
        // cout << row << endl;
        stringstream crs(row);
        string name, title = "NULL", credit_string; int credit;
        getline(crs, name, ',');
        // getline(crs, title, ',');
        getline(crs, credit_string, ',');
        credit = stoi(credit_string);

        // cout << credit_string << endl;
        course_credit[name] = {title, credit};
    }
    // for (auto [name, id] : course_credit) {
    //     cout << name << " " << id.first << " " << id.second << endl;
    // }
    // return 0;
    // Schedule sched;
    string header;
    getline(in, header);
    // cout << header << endl;

    vector<string> cols;

    stringstream hh(header);
    while (getline(hh, row, ',')) {
        cols.push_back(row);
    }
    // for (auto col : cols) {
    //     cout << col << endl;
    // }
    vector<Teacher> teachers;
    while (getline(in, row)) {
        // cout << row << endl; continue;
        stringstream ss(row);
        vector<string> fields;
        string field;
        while (getline(ss, field, ',')) {
            if (field.empty()) field = "NULL";
            fields.push_back(field);
        }
        if (fields.size() < 4) {continue;}

        string designation = fields[0];
        string name = fields[1];
        string temp_name = name;
        string id = "";
        stringstream ss2(temp_name);
        while (ss2 >> temp_name) {
            // cout << name << endl;
            if (temp_name.size() > 3) id += temp_name[0];
        }
        Teacher *t = new Teacher(id, name, designation);

        int i = 2;
        string courseCode = fields[i++];
        vector<Course> courses;
        int year = 0, term = 0;
        if (courseCode[0] == '"') {
            courseCode.erase(courseCode.begin());
            add_courses(courses, courseCode);
            bool flag = true;
            while (flag) {
                courseCode = fields[i++];
                if (courseCode.back() == '"') {
                    courseCode.pop_back(); flag = false;
                }
                add_courses(courses, courseCode);
            }
            // return 0;
        } else {
            add_courses(courses, courseCode);
        }

        // cout << fields[i] << endl;
        // cout << fields[i + 1] << endl;
        // cout << fields[i] << endl;

        int day = 0;
        vector<TimeSlot> timeslots;
        while (i < fields.size()) {
            string timeslot = fields[i++];
            if (timeslot[0] == '"') {
                timeslot.erase(timeslot.begin());
                add_timeslots(timeslots, timeslot, day);
                // cout << timeslot << " ";

                bool flag = true;
                while (flag) {
                    timeslot = fields[i++];
                    if (timeslot.back() == '"') {
                        timeslot.pop_back(); flag = false;
                    }
                    // cout << timeslot << endl;
                   add_timeslots(timeslots, timeslot, day);
                }
            } else {
                // cout << timeslot << " ";

                add_timeslots(timeslots,timeslot, day);
            }
            day++;
        }
        // return 0;
        // for (auto i : timeslots) {
        //     cout << i.getDay() << " " << i.getStartHour() << " " << i.getEndHour() << endl;
        // }
        // for (auto i : courses) {
        //     cout << i.getCode() << " " << i.getTitle() << endl;
        // }
        // return 0;
        t->addCourse(courses);
        t->addTimeSlot(timeslots);
        teachers.push_back(*t);
        // return 0;

    }
    sort(teachers.begin(), teachers.end(),
        [](const Teacher &t1, const Teacher &t2) {
            return t1.getPriority() < t2.getPriority();
        });
    // cout << teachers.size() << endl;
    // for (auto t : teachers) {
    //     cout << t.getName() << " " << t.getDesignation() << " " << t.getPriority() << endl;
    //     for (auto course : t.getCourses()) {
    //         cout << course.getCode() << " " << course.getSessionCount() << " " << course.done() << " " << course.getCredit() << endl;
    //     }
    //     cout << endl;
    //     for (auto time : t.getTimeSlots()) {
    //         // cout << time.getDay() << " " << time.getStartHour() << " " << time.getEndHour() << endl;
    //     }
    //     // cout << t.getCourses()[0].getSessionCount() << endl;
    //     cout << endl << endl;
    // } return 0;
    Schedule *sched = new Schedule(teachers);
    // sched->check();
    sched->generateSchedule();
    // TimeSlot *ts;m    bnbbbn

    // cout << teachers[0].getCourses()[0].getTitle() << endl;
    // cout << teachers[0].getCourses()[0].getCredit() << endl;
    // cout << teachers[0].getCourses()[0].getSessionDurations()[2] << endl;

    // Schedule *sch = new Schedule(teachers);
    // sch->generateSchedule();
    // cout << "Hello World!" << endl;

    return 0;
}