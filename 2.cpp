#include "2.h"
#include<iostream>
using namespace std;

    // Default constructor
    String :: String() 
    {
        data = nullptr;
        length = 0;
    }

    // Alternate constructor that initializes length to size of str, initializes data to a new char array of size length and fills the contents of data with the contents of str.
    String :: String( char* str) 
	{
        int i = 0;
        while (str[i] != '\0') {
            ++i;
        }
        length = i;
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = str[i];
        }
        data[length] = '\0';
    }

    // Copy constructor
   String ::  String(const String& str) {
        length = str.length;
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = str.data[i];
        }
        data[length] = '\0';
    }
    
    // Alternate constructor that initializes length to size and initializes data to a new char array of size.
   String ::  String(int size) {
        length = size;
        data = new char[length + 1];
        data[length] = '\0';
    }
    
    
    //return the charater at index
    char& String :: operator[](int index) {
    	return data[index];
	}
	
	
	//return the charater at index
    char& String :: operator[](int index) const {
   		return data[index];
	}
	
	
// Append a string at the end of a string
String String :: operator+(const String& str) const {
    int newLength = length + str.length;
    char* newData = new char[newLength + 1];
    for (int i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    for (int i = 0; i <= str.length; i++) {
        newData[length + i] = str.data[i];
    }
    newData[newLength] = '\0'; // Add null terminator at the end
    String result(newData); // Create a new String object with the concatenated data
    delete[] newData; // Deallocate memory to avoid memory leaks
    return result; // Return the concatenated String object
}

	
	
	
// Append a character at the end of a string
String& String :: operator+(const char& ch) {
    int newLength = length + 2;
    char* newData = new char[newLength];
    for (int i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    newData[length] = ch;
    newData[length + 1] = '\0'; // Add null terminator at the end
    delete[] data; // Deallocate old data
    data = newData; // Update data pointer
    length = newLength - 1; // Update length
    return *this; // Return reference to the modified string
}

	
	
	
	String& String ::  operator+(char* str) {
    	int len = 0;
    	while(str[len] != '\0') {
        	len++;
    	}
    	int newLength = length + len;
    	char* newData = new char[newLength + 1];
    	for (int i = 0; i < length; i++) {
        	newData[i] = data[i];
    	}
    	for (int i = 0; i <= len; i++) {
        	newData[length + i] = str[i];
    	}

    	delete[] data;
    	data = newData;
    	length = newLength;
    	return *this;
}

	
String& String :: operator-(const String &substr)
{
    int substrLength = substr.length;
    for (int i = 0; i < substr.length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (substr[i] == data[j])
            {
                data[j] = '\0'; // replace matching character with empty character
                break;
            }
        }
    }
    return *this;
}




	//if string is empty
	bool String :: operator!() const 
	{
	    	return (length == 0);
	}



    // Copy assignment operator with String
    String& String :: operator=(const String& str) {
        // Check for self-assignment
        if (this != &str) {
            // Deallocate current memory
            delete[] data;
            // Allocate new memory
            length = str.length;
            data = new char[length+1];
            // Copy data from str object to this object
            for (int i = 0; i < length; i++) {
                data[i] = str.data[i];
            }
            data[length] = '\0';
        }
        return *this;
    }

    // Copy assignment operator with char*
    String& String :: operator=( char* str) {
        // Deallocate current memory
        delete[] data;
        // Allocate new memory
        length = 0;
        while (str[length] != '\0') {
            length++;
        }
        data = new char[length+1];
        // Copy data from str to this object
        for (int i = 0; i < length; i++) {
            data[i] = str[i];
        }
        data[length] = '\0';
        return *this;
    }
    
    
String& String :: operator=(const string& str) {
    length = str.length();
    delete[] data; // Deallocate old data
    data = new char[length + 1];
    for (int i = 0; i < length; i++) {
        data[i] = str[i];
    }
    data[length] = '\0'; // Add null terminator at the end
    return *this;
}



	//returns true if two strings are equal
	bool String :: operator== (const String& str) const
	{
    	// If the lengths are not equal, the strings are not equal
    	if (length != str.length) {
       		return false;
    	}
    	// Compare the characters one by one
    	for (int i = 0; i < length; i++) {
        	if (data[i] != str.data[i]) {
            	return false;
        	}
    	}
    	return true;
	}


bool String :: operator==(const string& str) const {
    // If the lengths are not equal, the strings are not equal
    if (length != str.length()) {
        return false;
    }
    // Compare the characters one by one
    for (int i = 0; i < length; i++) {
        if (data[i] != str[i]) {
            return false;
        }
    }
    return true;
}


	//returns true if two strings are equal
	bool String :: operator==(char* str) const {
    	// Get the length of the char* string
    	int strLength = 0;
    	while(str[strLength] != '\0') {
        	strLength++;
    	}
    	// If the lengths are not equal, the strings are not equal
    	if (length != strLength) {
        	return false;
    	}
    	// Compare the characters one by one
    	for (int i = 0; i < length; i++) {
        	if (data[i] != str[i]) {
            	return false;
        	}
    	}
    	return true;
	}


int String :: operator()(char ch) const {
    for (int i = 0; i < length; i++) {
        if (data[i] == ch) {
            return i;
        }
    }
    return -1; // not found
}


int String :: operator()(const String& substr) const {
    int substrLen = substr.length;
    for (int i = 0; i <= length - substrLen; i++) {
        bool found = true;
        for (int j = 0; j < substrLen; j++) {
            if (data[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    // If the substring is not found, return -1
    return -1;
}



int  String :: operator()(const string& str) {
    int idx = -1;
    for (int i = 0; i < length; i++) {
        bool match = true;
        for (int j = 0; j < str.length(); j++) {
            if (i + j >= length || data[i + j] != str[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        // handle case where string is not found
        return -1;
    } else {
        // return the index of the first character in the match
        return idx;
    }
}



int  String :: operator()(char* str) {
    int index = -1;
    int i = 0, j = 0;
    while (data[i] != '\0') {
        if (data[i] == str[j]) {
            if (j == 0) {
                index = i;
            }
            j++;
            if (str[j] == '\0') {
                break;
            }
        }
        else {
            j = 0;
            index = -1;
        }
        i++;
    }
    return index;
}


//String operator*(int multiplier) const {
//    String result; // Create an empty String object to store the result
//    if (multiplier <= 0) {
//        return result; // Return empty string for invalid multiplier
//    }
//
//    for (int i = 0; i < multiplier; i++) {
//        result += *this; // Append the current string to the result
//    }
//
//    return result; // Return the multiplied String object
//}






// Get the length of the string
	int  String ::strLength() const
	{
        return length;
    }




    ostream& operator<<(ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // Overload >> operator for input
     istream& operator>>(istream& is, String& str) {
        // Read input as C-string
        char buffer[1000]; // Assuming maximum input length of 999 characters
        is >> buffer;

        // Determine length of input
        int len = 0;
        while (buffer[len] != '\0') {
            len++;
        }

        // Allocate memory for data
        str.length = len;
        str.data = new char[len + 1];

        // Copy input to data
        for (int i = 0; i <= len; i++) {
            str.data[i] = buffer[i];
        }

        return is;
    }

    // Destructor
    String :: ~String() 
    {
        delete[] data;
    }


