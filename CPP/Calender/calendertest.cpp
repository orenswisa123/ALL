#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include "calender.h"

using namespace std;

int main()
{
    Calender_t cal;
    Meeting_t *meet;
    int choice = 0;
    float start, end;
    string str;
    bool flag = false;

    while (choice != -1)
    {
        cout << "*******************************\n";
        cout << " Press 1 - To insert meeting.\n";
        cout << " Press 2 - To delete meeting.\n";
        cout << " Press 3 - To find meeting.\n";
        cout << " Press 4 - To clean calendar.\n";
        cout << " Press 5 - To print.\n";
        cout << " Press 6 - To exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Please enter start of meeting: ";
            cin >> start;
            cout << "Please enter end of meeting: ";
            cin >> end;
            cout << "Please enter information of meeting: ";
            cin >> str;
            try
            {
                meet = new Meeting_t(start, end, str);
            }
            catch (string tempStr)
            {
                cout << tempStr;
                flag = true;
            }
            if (flag == false)
            {
                if (cal.insertMeeting(meet) == false)
                {
                    cout << "You can't insert a meeting, already exists at this time." << endl;
                    delete meet;
                }
            }
            flag = false;
            break;

        case 2:
            cout << "Enter start of meeting to delete: " << endl;
            cin >> start;
            if (cal.deleteMeeting(start) == false)
            {
                cout << "Not exist start meeting in " << start << " to delete." << endl;
            }
            break;

        case 3:
            cout << "Enter start of meeting to find: " << endl;
            cin >> start;
            meet = cal.findMeeting(start);
            if (meet == NULL)
            {
                cout << "Not exist meeting in " << start << " to find." << endl;
            }
            else
            {
                cout << "The begin hour is: " << meet->getStart() << endl;
                cout << "The end hour is: " << meet->getEnd() << endl;
                cout << "The message is: " << meet->getMeetSubject() << endl;
            }
            break;

        case 4:
            cal.cleanCalender();
            break;
        case 5:
            cal.printCalender();
            break;

        case 6:
            cout << "End of Program." << endl;
            choice = -1;
            break;

        default:
            cout << "Not a Valid Choice." << endl;
            cout << "Choose again." << endl;
            break;
        }
    }
    return 0;
}