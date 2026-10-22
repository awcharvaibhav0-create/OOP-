#include <iostream>

#include <string>

using namespace std;

 

// Base class

class Person

{

protected:

    string name;

 

public:

    Person() : name("") {}

 

    Person(string n) : name(n) {}

 

    ~Person()

    {

        cout << "Person record closed." << endl;

    }

};

 

// Single inheritance: Student inherits from Person

class Student : public Person

{

protected:

    int rollNo;

 

public:

    Student() : Person(), rollNo(0) {}

 

    void inputStudent()

    {

        cout << "Enter student name: ";

        getline(cin, name);

        cout << "Enter roll number: ";

        cin >> rollNo;

        cin.ignore();

    }

 

    void displayStudent() const

    {

        cout << "Student Name: " << name << endl;

        cout << "Roll Number: " << rollNo << endl;

    }

 

    ~Student()

    {

        cout << "Student record closed." << endl;

    }

};

 

// Hierarchical inheritance: Teacher also inherits from Person

class Teacher : public Person

{

private:

    string subject;

 

public:

    Teacher() : Person(), subject("") {}

 

    void inputTeacher()

    {

        cout << "\nEnter teacher name: ";

        getline(cin, name);

        cout << "Enter subject: ";

        getline(cin, subject);

    }

 

    void displayTeacher() const

    {

        cout << "\n--- Teacher Details ---" << endl;

        cout << "Teacher Name: " << name << endl;

        cout << "Subject: " << subject << endl;

    }

 

    ~Teacher()

    {

        cout << "Teacher record closed." << endl;

    }

};

 

// Multilevel inheritance: Person -> Student -> Exam

class Exam : public Student

{

protected:

    float marks;

 

public:

    Exam() : Student(), marks(0.0f) {}

 

    void inputMarks()

    {

        cout << "Enter exam marks (0-100): ";

        cin >> marks;

        cin.ignore();

    }

 

    void displayMarks() const

    {

        cout << "Exam Marks: " << marks << endl;

    }

 

    ~Exam()

    {

        cout << "Exam record closed." << endl;

    }

};

 

// Independent base class for multiple inheritance

class Sports

{

protected:

    int sportsPoints;

 

public:

    Sports() : sportsPoints(0) {}

 

    void inputSportsPoints()

    {

        cout << "Enter sports points: ";

        cin >> sportsPoints;

        cin.ignore();

    }

 

    void displaySportsPoints() const

    {

        cout << "Sports Points: " << sportsPoints << endl;

    }

 

    ~Sports()

    {

        cout << "Sports record closed." << endl;

    }

};

 

// Multiple inheritance: Result inherits from Exam and Sports.

// Hybrid inheritance combines the multilevel chain and multiple inheritance.

class Result : public Exam, public Sports

{

public:

    void displayResult() const

    {

        cout << "\n--- College Student Result ---" << endl;

        displayStudent();

        displayMarks();

        displaySportsPoints();

 

        if (marks >= 40)

            cout << "Result: Pass" << endl;

        else

            cout << "Result: Fail" << endl;

    }

 

    ~Result()

    {

        cout << "Result record closed." << endl;

    }

};

 

int main()

{

    Result student;

    Teacher teacher;

 

    cout << "--- Enter Student Details ---" << endl;

    student.inputStudent();

    student.inputMarks();

    student.inputSportsPoints();

    student.displayResult();

 

    teacher.inputTeacher();

    teacher.displayTeacher();

 

    cout << "\nProgram completed." << endl;

    return 0;

}

