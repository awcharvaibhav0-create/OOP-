#include <iostream>
using namespace std;

void swapUsingReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapUsingPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;
    
    cout << "Enter two numbers for reference swapping: ";
    cin >> x >> y;

    cout << "\nBefore swapping: x = " << x << ", y = " << y << endl;

    swapUsingReference(x, y);

    cout << "After swapping: x = " << x << ", y = " << y << endl;

    int p, q;

    cout << "\nEnter two numbers for pointer swapping: ";
    cin >> p >> q;

    int *ptr = &p;

    cout << "\nAddress of p: " << &p << endl;
    cout << "Value using pointer: " << *ptr << endl;

    cout << "Before swapping: p = " << p << ", q = " << q << endl;

    swapUsingPointer(&p, &q);

    cout << "After swapping: p = " << p << ", q = " << q << endl;

    int n;

    cout << "\nEnter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size." << endl;
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;
    arr = nullptr;

    cout << "Dynamic memory released successfully." << endl;

    return 0;
}