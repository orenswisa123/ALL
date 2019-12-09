#include <iostream>
#include <string.h>
#include "bus_t.h"
#include"private_t.h"
using namespace std;

int main()
{
    bus_t b1;
    private_t p1;
    size_t capacity;
    int choice;
    char c;
    bool caseSensBool=false;
    bool flag = true;
    while (flag != false)
    {
        cout << "*******************************\n";
        cout << " 1 - create private\n";
        cout << " 2 - create bus.\n";
        cout << " 3 - get capacity\n";
        cout << " 4 - get car name\n";
        cout << " 5 - get car type.\n";
        cout << " 6 - get car speed.\n";
        cout << " 7 - acc.\n";
        cout << " 8 - reduce speed\n";
        cout << " 9 - get num of seats\n";
        cout << " 10 - get line num\n";
        cout << " 11 - set capacity\n";
        cout << " 12 - operator ==\n";
        cout << " 13 - operator <\n";
        cout << " 14 - Exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            private_t p2(1200);
            capacity=p1.getCapacity();
            cout<<capacity<<endl;
            break;
        }
        case 2:
        {

            break;
        }
        case 3:

            break;
        case 4:
        {

        }
            break;
        case 5:
        {

        }
            break;
        case 6:
            {

            }
            break;
        case 7:
            {

            }
            break;
        case 8:
            {

            }
            break;
        case 9:
            {

            }
            break;
        case 10:
            {

            }
            break;
        case 11:
            {

            }
            break;
        case 12:
            {

            }
            break;
        case 13:
            {

            }
            break;
        case 14:
            cout << "End of Program.\n";
            flag = false;
            break;
        default:
            cout << "Not a Valid Choice.\n";
            cout << "Choose again.\n";
            break;
        }
    }
    return 0;
}
