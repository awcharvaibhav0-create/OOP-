#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int id;
    float salary;

public:

    // Default Constructor
    Employee()
    {
        name = "Not Available";
        id = 0;
        salary = 0;
    }

    // Parameterized Constructor
    Employee(string n, int i, float s)
    {
        name = n;
        id = i;
        salary = s;
    }

    // Copy Constructor
    Employee(const Employee &e)
    {
        name = e.name;
        id = e.id;
        salary = e.salary;
    }

    // Member Function
    float calculateAnnualSalary()
    {
        return salary * 12;
    }

    // Member Function
    void display()
    {
        cout << "\n-----------------------------------\n";
        cout << "Employee Name   : " << name << endl;
        cout << "Employee ID     : " << id << endl;
        cout << "Monthly Salary  : Rs. " << salary << endl;
        cout << "Annual Salary   : Rs. "
             << calculateAnnualSalary() << endl;
        cout << "-----------------------------------\n";
    }
};

int main()
{
    string name;
    int id;
    float salary;

    cout << "====================================\n";
    cout << "        EMPLOYEE PAYROLL SYSTEM\n";
    cout << "====================================\n";

    // 1. Default Constructor
    cout << "\n1. Default Constructor";

    Employee emp1;
    emp1.display();

    // Taking employee details from user
    cout << "\nEnter Employee Details\n";

    cout << "Name           : ";
    getline(cin >> ws, name);

    cout << "Employee ID    : ";
    cin >> id;

    cout << "Monthly Salary : Rs. ";
    cin >> salary;

    // 2. Parameterized Constructor
    cout << "\n2. Parameterized Constructor";

    Employee emp2(name, id, salary);
    emp2.display();

    // 3. Copy Constructor
    cout << "\n3. Copy Constructor";

    Employee emp3(emp2);
    emp3.display();

    cout << "\nProgram completed successfully.\n";

    return 0;
}