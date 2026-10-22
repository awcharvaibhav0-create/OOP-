#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main()
{
    int choice;
    float real1, imag1, real2, imag2;

    cout << "============================================\n";
    cout << "          COMPLEX NUMBER CALCULATOR\n";
    cout << "============================================\n";

    do
    {
        cout << "\n1. Add Complex Numbers";
        cout << "\n2. Exit";
        cout << "\n--------------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter first complex number\n";
            cout << "Real part      : ";
            cin >> real1;

            cout << "Imaginary part : ";
            cin >> imag1;

            cout << "\nEnter second complex number\n";
            cout << "Real part      : ";
            cin >> real2;

            cout << "Imaginary part : ";
            cin >> imag2;

            Complex first(real1, imag1);
            Complex second(real2, imag2);

            Complex result = first + second;

            cout << "\n============================================\n";
            cout << "              CALCULATION\n";
            cout << "============================================\n";

            cout << "First Number  : ";
            first.display();

            cout << "\nSecond Number : ";
            second.display();

            cout << "\n--------------------------------------------\n";
            cout << "Addition      : ";
            result.display();

            cout << "\n============================================\n";
        }
        else if (choice == 2)
        {
            cout << "\nThank you for using the calculator.\n";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 2);

    return 0;
}
