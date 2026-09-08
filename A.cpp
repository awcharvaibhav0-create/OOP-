#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks[3];
    float percentage;

public:

    // Constructor
    Student()
    {
        name = "Not Available";
        rollNo = 0;
        percentage = 0;

        for (int i = 0; i < 3; i++)
        {
            marks[i] = 0;
        }

        cout << "\n[Constructor] Student object created successfully.\n";
    }

    // User-defined function to enter student details
    void inputDetails()
    {
        cout << "\n========================================\n";
        cout << "          ENTER STUDENT DETAILS\n";
        cout << "========================================\n";

        cout << "Enter student name : ";
        getline(cin >> ws, name);

        cout << "Enter roll number  : ";
        cin >> rollNo;

        for (int i = 0; i < 3; i++)
        {
            do
            {
                cout << "Enter marks for Subject(0-100) " << i + 1 << " : ";
                cin >> marks[i];

                if (marks[i] < 0 || marks[i] > 100)
                {
                    cout << "Invalid marks! Enter marks between 0 and 100.\n";
                }

            } while (marks[i] < 0 || marks[i] > 100);
        }

        calculatePercentage();

        cout << "\nStudent details saved successfully!\n";
    }

    // User-defined function to calculate percentage
    void calculatePercentage()
    {
        float total = 0;

        for (int i = 0; i < 3; i++)
        {
            total = total + marks[i];
        }

        percentage = total / 3;
    }

    // User-defined function to calculate grade
    char calculateGrade()
    {
        if (percentage >= 90)
        {
            return 'A';
        }
        else if (percentage >= 80)
        {
            return 'B';
        }
        else if (percentage >= 60)
        {
            return 'C';
        }
        else if (percentage >= 40)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    // User-defined function to display student report
    void displayDetails()
    {
        cout << "\n========================================\n";
        cout << "            STUDENT REPORT\n";
        cout << "========================================\n";

        cout << "Name        : " << name << endl;
        cout << "Roll Number : " << rollNo << endl;

        cout << "\n------------- SUBJECT MARKS ------------\n";

        cout << "Subject 1   : " << marks[0] << "/100" << endl;
        cout << "Subject 2   : " << marks[1] << "/100" << endl;
        cout << "Subject 3   : " << marks[2] << "/100" << endl;

        cout << "----------------------------------------\n";

        char grade = calculateGrade();

        cout << "Percentage  : " << percentage << "%" << endl;
        cout << "Grade       : " << grade << endl;

        if (grade == 'F')
        {
            cout << "Result      : FAIL" << endl;
        }
        else
        {
            cout << "Result      : PASS" << endl;
        }

        cout << "========================================\n";
    }

    // Destructor
    ~Student()
    {
        cout << "\n[Destructor] Student object destroyed successfully.\n";
    }
};


int main()
{
    cout << "\n";
    cout << "============================================\n";
    cout << "        STUDENT MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "           C++ OOP PRACTICAL 01\n";
    cout << "============================================\n";

    // Creating object
    Student student;

    int choice;

    do
    {
        cout << "\n--------------- MAIN MENU ----------------\n";
        cout << "1. Enter Student Details\n";
        cout << "2. Display Student Report\n";
        cout << "3. Exit\n";
        cout << "-------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            student.inputDetails();
            break;

        case 2:
            student.displayDetails();
            break;

        case 3:
            cout << "\nThank you for using Student Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please enter 1, 2 or 3.\n";
        }

    } while (choice != 3);

    return 0;
}