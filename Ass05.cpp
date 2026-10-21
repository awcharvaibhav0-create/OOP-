#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

    static int totalStudents;

public:
    Student(int rollNo, string name, float marks)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;
        totalStudents++;
    }

    inline void display()
    {
        cout << "\nRoll Number: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    static void showTotalStudents()
    {
        cout << "\nTotal Students: " << totalStudents << endl;
    }

    friend class Result;
};

int Student::totalStudents = 0;

class Result
{
public:
    void displayResult(Student s)
    {
        cout << "\n--- Student Result ---" << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;

        if (s.marks >= 40)
            cout << "Status: Pass" << endl;
        else
            cout << "Status: Fail" << endl;
    }
};

int main()
{
    int rollNo;
    string name;
    float marks;

    cout << "Enter roll number: ";
    cin >> rollNo;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter marks: ";
    cin >> marks;

    Student s1(rollNo, name, marks);

    s1.display();

    Student::showTotalStudents();

    Result r1;
    r1.displayResult(s1);

    return 0;
}
