#include <iostream>
#include <string.h>
#include "string_t.h"
using namespace std;

int stringOren();
int stringOren2();

int main()
{
   //stringOren();
    stringOren2();
}
/*int stringOren()
{
    string_t str1;
    string_t str2;
    int temp_to_compare;
    char str_temp[256];
    int choice;
    bool flag = true;
    while (flag != false)
    {
        cout << "*******************************\n";
        cout << " 1 - To set string.\n";
        cout << " 2 - To print string.\n";
        cout << " 3 - To get length.\n";
        cout << " 4 - compare string.\n";
        cout << " 5 - to upper case.\n";
        cout << " 6 - to lower case.\n";
        cout << " 7 - to prepend char.\n";
        cout << " 8 - to prepend object.\n";
        cout << " 9 - to append char.\n";
        cout << " 10 - to append object.\n";
        cout << " 11 - check operator.\n";
        cout << " 12 - if contains.\n";
        cout << " 13 - get index.\n";
        cout << " 14 - << operators >>.\n";
        cout << " 15 - Exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "set string: \n";
            cin >> str_temp;
            str1.operator=(str_temp);
            break;
        case 2:
            str1.printString();
            break;
        case 3:
            cout << str1.getLen() << endl;
            break;
        case 4:
            cout << "insert another string to check" << endl;
            cin >> str_temp;
            temp_to_compare = str1.compare(str_temp);
            cout << temp_to_compare << endl;
            break;
        case 5:
            str1.toUppercase();
            break;
        case 6:
            str1.toLowercase();
            break;
        case 7:
            cout << "insert another string to check" << endl;
            cin >> str_temp;
            str1.preprend(str_temp);
            break;
        case 8:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            str1.preprend(str2);
            break;
        case 9:
            cout << "insert another string to check" << endl;
            cin >> str_temp;
            str1 += str_temp;
            break;
        case 10:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            str1 += str2;
            break;
        case 11:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            if (str1 > str2)
            {
                cout << "true" << endl;
            }
            break;
        case 12:
            cout << "enter string: \n";
            cin >> str_temp;
            if (str1.contains(str_temp) == true)
            {
                cout << "its contains!!" << endl;
            }
            break;
        case 13:
            cout << "enter index: \n";
            int index;
            cin >> index;
            cout << str1[index] << endl;
            break;
        case 14:
            cin >> str1;
            cout << str1;
            break;
        case 15:
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
}*/
int stringOren2()
{
    string_t str1;
    int temp_to_compare;
    int n1, n2;
    char str_temp[256];
    str_temp[0]='\0';
    int choice;
    char c;
    int caseSens;
    bool caseSensBool=false;
    bool flag = true;
    while (flag != false)
    {
        cout << "*******************************\n";
        cout << " 1 - To set string.\n";
        cout << " 2 - To print string.\n";
        cout << " 3 - get case sens\n";
        cout << " 4 - set case sens\n";
        cout << " 5 - compare string.\n";
        cout << " 6 - to upper case.\n";
        cout << " 7 - to lower case.\n";
        cout << " 8 - get default capacity\n";
        cout << " 9 - get object capacity\n";
        cout << " 10 - first char occur in string_t\n";
        cout << " 11 - last char occur in string_t\n";
        cout << " 12 - operator (,)\n";
        cout << " 13 - get string_t count\n";
        cout << " 14 - Exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
           /* cout << "set string: \n";
            cin >> str_temp;
            str1=str_temp;*/
            string_t str3("oren");
            str3.printString();
            break;
        }
        case 2:
        {
            str1.printString();
            break;
        }
        case 3:
            cout << string_t::getcaseSensMode() << endl;
            break;
        case 4:
        {
            cout << "enter case sens mode" << endl;
            cin >> caseSens;
            if(caseSens!=0)
            {   
                caseSensBool=true;
            }
            else if(caseSens==0)
                caseSensBool=false;
            string_t::setCaseSens(caseSensBool);
        }
            break;
        case 5:
            cout << "insert another string to check" << endl;
            cin >> str_temp;
            temp_to_compare = str1.compare(str_temp);
            cout << temp_to_compare << endl;
            break;
        case 6:
            str1.toUppercase();
            break;
        case 7:
            str1.toLowercase();
            break;
        case 8:
            cout<<string_t::getDefCapacity()<<endl;
            break;
        case 9:
            cout<<str1.getCapacity()<<endl;
            break;
        case 10:
            cout << "insert another char to check" << endl;
            cin >> c;
            cout<<str1.firstChar(c)<<endl;
            break;
        case 11:
            cout << "insert another char to check" << endl;
            cin >> c;
            cout<<str1.lastChar(c)<<endl;
            break;
        case 12:
            cout << "enter 2 numbers: \n";
            cin >>n1>>n2;
            cout<<str1(n1,n2)<<endl;
            break;
        case 13:
            cout << string_t::getCount();
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
