
#include <iostream>
#include <string>
using namespace std;

// Function template to find maximum marks
template <typename T>
T findMaximum(T a, T b, T c) {
    T maximum = a;

    if (b > maximum)
        maximum = b;

    if (c > maximum)
        maximum = c;

    return maximum;
}

// Class template for student result
template <typename T>
class Student {
private:
    string name;
    int rollNo;
    T marks1, marks2, marks3;

public:
    void input() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter marks in three subjects: ";
        cin >> marks1 >> marks2 >> marks3;
    }

    void display() {
        T total = marks1 + marks2 + marks3;
        T average = total / 3.0;

        cout << "\n===== STUDENT RESULT =====" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
        cout << "Highest Marks: "
             << findMaximum(marks1, marks2, marks3) << endl;
    }
};

int main() {
    Student<float> student;

    cout << "===== COLLEGE RESULT MANAGEMENT SYSTEM ====="
         << endl;

    student.input();
    student.display();

    return 0;
}