#include "2.h"
#include<iostream>
using namespace std;

int main() 
{

   
    // Create string objects using different constructors
    String emptyStr; // Default constructor
    String str1("Hello"); // Alternate constructor with char* argument
    String str2(str1); // Copy constructor
    String str3(10); // Alternate constructor with int argument

    // Use the [] operator to access characters in a string
    cout << "str1[0]: " << str1[0] << endl;

    // Use the + operator to concatenate strings
    String str4 = str1 + str2;
    cout << "str4: " << str4 << endl;

    // Use the + operator to append characters to a string
    str4 = str4 + '!';
    cout << "str4: " << str4 << endl;

    // Use the + operator to append a char* to a string
    str4 = str4 + " How are you?";
    cout << "str4: " << str4 << endl;

    // Use the - operator to remove characters from a string
    String substr("ello");
    str4 = str4 - substr;
    cout << "str4: " << str4 << endl;

    // Use the ! operator to check if a string is empty
    if (!str4) {
        cout << "str4 is empty" << endl;
    } else {
        cout << "str4 is not empty" << endl;
    }

    // Use the = operator to assign one string to another
    String str5 = "Assignment operator";
    str4 = str5;
    cout << "str4: " << str4 << endl;

    return 0;
}





