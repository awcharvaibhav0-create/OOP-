
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Student {
private:
    string name;
    string course;
    string prn;

public:
    Student(string n, string c, string p)
        : name(move(n)), course(move(c)), prn(move(p)) {}

    void display() const {
        cout << "Student Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "PRN: " << prn << endl;
    }
};

int main() {
    string name, course, prn;

    cout << "===== STUDENT RECORD TRANSFER SYSTEM =====" << endl;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter course name: ";
    getline(cin, course);

    cout << "Enter PRN: ";
    getline(cin, prn);

    if (name.empty() || course.empty() || prn.empty()) {
        cout << "Error: Student details cannot be empty." << endl;
        return 1;
    }

    Student temporaryStudent(
        move(name), move(course), move(prn)
    );

    cout << "\n--- Temporary Student Record ---" << endl;
    temporaryStudent.display();

    Student permanentStudent(move(temporaryStudent));

    cout << "\n--- Permanent Student Record ---" << endl;
    permanentStudent.display();

    cout << "\nStudent record transferred successfully!" << endl;

    return 0;
}
