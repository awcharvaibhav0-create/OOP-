
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    virtual void display() const {
        cout << "Person Details" << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string name;
    int rollNo;
    string course;

public:
    Student(string n, int r, string c) {
        name = n;
        rollNo = r;
        course = c;
    }

    // Runtime polymorphism
    void display() const override {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }

    // Compile-time polymorphism
    void displayInfo() const {
        cout << "Student Name: " << name << endl;
    }

    void displayInfo(bool showCourse) const {
        cout << "Student Name: " << name << endl;

        if (showCourse) {
            cout << "Course: " << course << endl;
        }
    }
};

class Teacher : public Person {
private:
    string name;
    string subject;

public:
    Teacher(string n, string s) {
        name = n;
        subject = s;
    }

    // Runtime polymorphism
    void display() const override {
        cout << "\n--- Teacher Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    string studentName, course;
    string teacherName, subject;
    int rollNo;

    cout << "=== College Management System ===" << endl;

    // Student input
    cout << "\nEnter Student Name: ";
    getline(cin, studentName);

    cout << "Enter Roll Number: ";
    if (!(cin >> rollNo) || rollNo <= 0) {
        cout << "Invalid Roll Number!" << endl;
        return 1;
    }

    cin.ignore(1000, '\n');

    cout << "Enter Course: ";
    getline(cin, course);

    // Teacher input
    cout << "\nEnter Teacher Name: ";
    getline(cin, teacherName);

    cout << "Enter Subject: ";
    getline(cin, subject);

    // Create objects
    Student student(studentName, rollNo, course);
    Teacher teacher(teacherName, subject);

    // Compile-time polymorphism
    cout << "\n=== Compile-Time Polymorphism ===" << endl;

    student.displayInfo();

    cout << "\nStudent Information with Course:" << endl;
    student.displayInfo(true);

    // Runtime polymorphism
    cout << "\n=== Runtime Polymorphism ===" << endl;

    Person* person = &student;
    person->display();

    person = &teacher;
    person->display();

    return 0;
}