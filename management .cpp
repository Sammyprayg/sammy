#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define MAX_SUBJECTS 5
#define PASS_MARK 50

struct Student {
    string firstName;
    string lastName;
    int regNo;
    bool status;
    int marks[MAX_SUBJECTS];
    float average;
    string gpa;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student details:" << endl;
    cout << "First Name: ";
    cin >> newStudent.firstName;
    cout << "Last Name: ";
    cin >> newStudent.lastName;
    cout << "Registration Number: ";
    cin >> newStudent.regNo;

    cout << "Enter marks for each subject:" << endl;
    int sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> newStudent.marks[i];
        sum += newStudent.marks[i];
    }

    newStudent.average = sum / static_cast<float>(MAX_SUBJECTS);

    if (newStudent.average >= 90)
        newStudent.gpa = "A+";
    else if (newStudent.average >= 80)
        newStudent.gpa = "A";
    else if (newStudent.average >= 70)
        newStudent.gpa = "B";
    else if (newStudent.average >= 60)
        newStudent.gpa = "C";
    else if (newStudent.average >= 50)
        newStudent.gpa = "D";
    else
        newStudent.gpa = "F";

    newStudent.status = true;

    for (int i = 0; i <= MAX_SUBJECTS; i++) {
        if (newStudent.marks[i] < PASS_MARK) {
            newStudent.status = false;
            break;
        }
    }

    students.push_back(newStudent);
}

void printResultTable(const vector<Student>& students) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Reg No   Name             Average   GPA   Status" << endl;
    cout << "-----------------------------------------------------------" << endl;

    vector<Student>::const_iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        cout << setw(8) << student.regNo << " ";
        cout << setw(17) << student.firstName + " " + student.lastName << " ";
        cout << setw(9) << fixed << setprecision(2) << student.average << " ";
        cout << setw(5) << student.gpa << " ";
        cout << (student.status ? "Pass" : "Fail") << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
}

void clearData(vector<Student>& students) {
    students.clear();
    cout << "Data cleared successfully." << endl;
}

int main() {
    vector<Student> students;

    char choice;
    do {
        cout << "1. Add Student" << endl;
        cout << "2. Print Result Table" << endl;
        cout << "3. Clear Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(students);
                break;
            case '2':
                printResultTable(students);
                break;
            case '3':
                clearData(students);
                break;
            case '4':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != '4');

    return 0;
}
