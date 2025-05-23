
# 📅 Make_Schedule - Intelligent Course Scheduling System

A C++ and Python-based scheduling system designed to automatically generate optimal university timetables using a **backtracking algorithm**. This system takes into account complex constraints related to teachers, time slots, and course types (theory/lab), and outputs a valid, conflict-free schedule in CSV format.

## 🚀 Features

- ✅ **Constraint-Aware Scheduling**  
  Handles both hard and soft constraints related to teacher availability, course credits, lab durations, and more.

- 🧠 **Backtracking Algorithm**  
  Uses a smart backtracking approach, optimizing the schedule while respecting conflicts and constraints.

- 🧪 **Lab & Theory Handling**  
  Distinguishes between lab and theory courses (lab codes are even-numbered), ensuring proper time allocation.

- 💡 **GUI Integration (Python + PySide6)**  
  A modern, user-friendly GUI to upload data, generate schedules, and view/export results.

- 📄 **CSV Import/Export**  
  Reads teacher and course data from CSVs and exports the final schedule in a user-friendly format.

---

## 🗂️ Project Structure

```

Make\_Schedule/
│
├── algorithm/               # C++ logic (Backtracking + Scheduling)
│   ├── src/                 # C++ source files
│   ├── include/             # Header files
│   ├── db/                  # CSV input/output files
│   └── CMakeLists.txt       # CMake build setup
│
├── gui\_schedule/            # Python GUI (PySide6)
│   └── \*.py                 # GUI scripts
│
├── README.md                # Project documentation
└── LICENSE

```

---

## 📊 Input Format (CSV)

1. **teachers_timeslots_python.csv**
```

teacher\_code,day,time\_slot
T1,Monday,9
T1,Monday,10
...

```

2. **credits_python.csv**
```

course\_code,course\_name,teacher\_code,credit
101,Data Structures,T1,3
102,Physics Lab,T2,1.5
...

````

---

## 💻 Building & Running

### ⏱️ Step 1: Build C++ Scheduler

```bash
cd algorithm
mkdir -p build && cd build
cmake ..
cmake --build .
````

### 🖱️ Step 2: Run GUI

Make sure dependencies are installed:

```bash
pip install -r requirements.txt
```

Then:

```bash
cd gui_schedule
python main.py
```

---

## 📁 Output Format

On successful scheduling, a CSV named `final_schedule.csv` is created showing days as rows and time slots as columns (9 AM – 5 PM).
Each cell: `course_code [teacher_code]`

---

## 🎓 Scheduling Rules Summary

* **Theory Courses:**
  1-hour slots, distributed across the week. Credit hours define frequency.

* **Lab Courses:**
  3-hour continuous blocks, between 2 PM–5 PM.

* **Teacher Constraints:**

  * No time conflict.
  * Can teach multiple years.
  * Only teach in available slots.

* **Backtracking Logic:**
  Ensures optimal fitting using unbounded knapsack-like decision strategy.

---

## 📚 Technologies Used

* 🧠 C++17 – Core scheduling logic
* 💻 PySide6 – GUI interface
* 📊 CSV – Data input/output
* 🧰 CMake – Build system

---

## 🧾 License

This project is licensed under the MIT License.

---

## 🤝 Acknowledgments

* Inspired by classic solutions to the University Course Timetabling Problem (UCTP)
* Contributions from: Azmain Inquaid Haque

---

## 📬 Contact

📧 Email: [azmaininquaidhaque@gmail.com](mailto:azmaininquaidhaque@gmail.com)
🏫 Khulna University, CSE Discipline
🌍 Khulna, Bangladesh

```
