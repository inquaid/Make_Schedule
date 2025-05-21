import os
import subprocess
import sys
from PySide6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QPushButton, QLabel,
    QHBoxLayout, QTableWidget, QTableWidgetItem,
    QMessageBox, QHeaderView
)
import pandas as pd

import make_pdf


class SchedulerGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Schedule Generator")
        self.layout = QVBoxLayout()
        self.setLayout(self.layout)
        self.resize(1000, 700)

        base_dir = os.path.dirname(__file__)
        target_dir = os.path.join(base_dir, "..", "Algorithm", "db")
        self.teachers_filename = os.path.join(target_dir,"teachers_timeslot.csv")
        self.credits_filename = os.path.join(target_dir,"credits.csv")
        self.output_filename = os.path.join(target_dir,"final_schedule.csv")

        self.init_teacher_table()
        self.init_course_table()
        self.init_buttons()
        self.load_existing_data()

    def delete_teacher_row(self, row):
        self.teacher_table.removeRow(row)

    def delete_course_row(self, row):
        self.course_table.removeRow(row)

    def load_existing_data(self):
        # import os
        # import pandas as pd

        # Load teachers data
        if os.path.exists(self.teachers_filename):
            teachers_df = pd.read_csv(self.teachers_filename)
            self.teacher_table.setRowCount(0)  # Clear table
            for index, row in teachers_df.iterrows():
                row_idx = self.teacher_table.rowCount()
                self.teacher_table.insertRow(row_idx)
                for col_idx, col in enumerate(
                        ["designation", "name", "courses", "sunday", "monday", "tuesday", "wednesday", "thursday"]):
                    item = QTableWidgetItem(str(row[col]) if col in row else "")
                    self.teacher_table.setItem(row_idx, col_idx, item)
                delete_btn = QPushButton("Delete")
                delete_btn.clicked.connect(lambda _, r=row_idx: self.delete_teacher_row(r))
                self.teacher_table.setCellWidget(row_idx, 8, delete_btn)
        # Load credits data
        if os.path.exists(self.credits_filename):
            credits_df = pd.read_csv(self.credits_filename)
            self.course_table.setRowCount(0)  # Clear table
            for index, row in credits_df.iterrows():
                row_idx = self.course_table.rowCount()
                self.course_table.insertRow(row_idx)
                course_item = QTableWidgetItem(str(row["course"]))
                credit_item = QTableWidgetItem(str(row["credits"]))
                self.course_table.setItem(row_idx, 0, course_item)
                self.course_table.setItem(row_idx, 1, credit_item)
                delete_btn = QPushButton("Delete")
                delete_btn.clicked.connect(lambda _, r=row_idx: self.delete_course_row(r))
                self.course_table.setCellWidget(row_idx, 2, delete_btn)

    def init_teacher_table(self):
        self.teacher_label = QLabel("Teachers, Courses and TimeSlots")
        self.layout.addWidget(self.teacher_label)

        self.teacher_table = QTableWidget(0, 9)
        self.teacher_table.setHorizontalHeaderLabels([
            "Designation", "Name", "Courses",
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Delete"
        ])
        self.teacher_table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.layout.addWidget(self.teacher_table)

        add_row_btn = QPushButton("Add Teacher")
        add_row_btn.clicked.connect(self.add_teacher_row)
        self.layout.addWidget(add_row_btn)

    def add_teacher_row(self):
        row = self.teacher_table.rowCount()
        self.teacher_table.insertRow(row)

        # Add Delete button
        delete_btn = QPushButton("Delete")
        delete_btn.clicked.connect(lambda: self.delete_row(self.teacher_table, row))
        self.teacher_table.setCellWidget(row, 8, delete_btn)

    def init_course_table(self):
        self.course_label = QLabel("Course Credits")
        self.layout.addWidget(self.course_label)

        self.course_table = QTableWidget(0, 3)
        self.course_table.setHorizontalHeaderLabels(["Course", "Credit", "Delete"])
        self.course_table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.layout.addWidget(self.course_table)

        add_course_btn = QPushButton("Add Course")
        add_course_btn.clicked.connect(self.add_course_row)
        self.layout.addWidget(add_course_btn)

    def add_course_row(self):
        row = self.course_table.rowCount()
        self.course_table.insertRow(row)

        delete_btn = QPushButton("Delete")
        delete_btn.clicked.connect(lambda: self.delete_row(self.course_table, row))
        self.course_table.setCellWidget(row, 2, delete_btn)

    def delete_row(self, table, row):
        table.removeRow(row)

    def init_buttons(self):
        btn_layout = QHBoxLayout()
        self.ready_btn = QPushButton("Ready")
        self.ready_btn.clicked.connect(self.export_csvs)

        self.generate_btn = QPushButton("Generate")
        self.generate_btn.clicked.connect(self.run_algorithm)

        btn_layout.addWidget(self.ready_btn)
        btn_layout.addWidget(self.generate_btn)
        self.layout.addLayout(btn_layout)

    def export_csvs(self):
        try:
            # Export teachers_timeslots.csv
            teachers_data = []
            for row in range(self.teacher_table.rowCount()):
                row_data = []
                for col in range(8):  # Skip "Delete" column
                    item = self.teacher_table.item(row, col)
                    row_data.append(item.text() if item else "")
                teachers_data.append(row_data)

            teachers_df = pd.DataFrame(
                teachers_data,
                columns=["designation", "name", "courses", "sunday", "monday", "tuesday", "wednesday", "thursday"]
            )
            teachers_df.to_csv(self.teachers_filename, index=False)

            # Export credits.csv
            credits_data = []
            for row in range(self.course_table.rowCount()):
                course = self.course_table.item(row, 0)
                credit = self.course_table.item(row, 1)
                if course and credit:
                    credits_data.append([course.text(), credit.text()])

            credits_df = pd.DataFrame(credits_data, columns=["course", "credits"])
            credits_df.to_csv(self.credits_filename, index=False)

            QMessageBox.information(self, "Success", "CSV files generated successfully!")
        except Exception as e:
            QMessageBox.critical(self, "Error", str(e))

    def run_algorithm(self):
        try:
            QMessageBox.information(self, "Generating", "Building and running C++ scheduler...")
            project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../Algorithm"))
            build_dir = os.path.join(project_root, "build")
            exe_path = os.path.join(build_dir, "Schedule_Management")

            os.makedirs(build_dir, exist_ok=True)
            subprocess.run(["cmake", ".."], cwd=build_dir, check=True)
            subprocess.run(["cmake", "--build", "."], cwd=build_dir, check=True)
            result = subprocess.run([exe_path], cwd=build_dir, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                    text=True)
            if result.returncode != 0:
                QMessageBox.critical(self, "Error", f"Execution failed:\n{result.stderr}")
            else:
                QMessageBox.information(self, "Success", "Schedule generated successfully!")
                make_pdf.do_work()

        except subprocess.CalledProcessError as e:
            QMessageBox.critical(self, "CMake Error", f"Command failed:\n{e}")
        except Exception as e:
            QMessageBox.critical(self, "Error", str(e))



if __name__ == '__main__':
    app = QApplication(sys.argv)
    gui = SchedulerGUI()
    gui.show()
    sys.exit(app.exec())
