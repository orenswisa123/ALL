
#include <iostream>
#include <string>
#include "exep.h"
#include "someTests.h"
using namespace std;

int main()
{
    char ch;
    int num;
    int choice;
    bool flag = true;
    while (flag != false)
    {
        cout << "*******************************\n";
        cout << " Press 1 - To check if positive .\n";
        cout << " Press 2 - To check if Letter.\n";
        cout << " Press 3 - To exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Please enter to check if number is positive: ";
            cin >> num;
            try
            {
                ifPositive(num);
            }
            catch (TException_t<int>& e)
            {
                cout << "The number line exception is: " << e.getLineNumber() << endl;
                cout << "The name of file exception is: " << e.getFileName() << endl;
                cout << "The type of object exception is: " << e.getExeptionObject() << endl;
                cout << "The message for exeption is: " << e.getMessage() << endl;
            }
            catch (string str)
            {
                cout << str << endl;
            }
            break;

        case 2:
            cout << "Please enter to check if number is Letter: ";
            cin >> ch;
            try
            {
                ifLetter(ch);
            }
            catch (TException_t<char>& e)
            {
                cout << "The number line exception is: " << e.getLineNumber() << endl;
                cout << "The name of file exception is: " << e.getFileName() << endl;
                cout << "The exeption object is: " << e.getExeptionObject() << endl;
                cout << "The message for exeption is: " << e.getMessage() << endl;
            }
            catch (string str)
            {
                cout << str << endl;
            }
            break;
        case 3:
            cout << "End of Program.\n";
            flag = false;
            break;

        default:
            cout << "Not a Valid Choice.\n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
        }
    }
    return 0;
}
