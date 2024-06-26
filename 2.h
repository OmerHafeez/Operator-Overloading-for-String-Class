#ifndef STRING_H_
#define STRING_H_


#include<iostream>
using namespace std;
class String 
{
private:
    char* data;
    int length;

public:
    // Default constructor
    String();
    // Alternate constructor that initializes length to size of str, initializes data to a new char array of size length and fills the contents of data with the contents of str.
    String( char* str) ;

    // Copy constructor
    String(const String& str) ;
    // Alternate constructor that initializes length to size and initializes data to a new char array of size.
    String(int size) ;
    
    //return the charater at index
    char& operator[](int index) ;
	
	//return the charater at index
    char& operator[](int index) const ;
	
	
// Append a string at the end of a string
String operator+(const String& str) const ;
	
	
	
// Append a character at the end of a string
String& operator+(const char& ch) ;
	
	
	
	String& operator+(char* str) ;
	
String& operator-(const String &substr);


//	String& operator-(const String &substr)

	//if string is empty
	bool operator!() const;



    // Copy assignment operator with String
    String& operator=(const String& str);
    // Copy assignment operator with char*
    String& operator=( char* str) ;
    
    
String& operator=(const string& str);



	//returns true if two strings are equal
	bool operator== (const String& str) const;

bool operator==(const string& str) const ;


	//returns true if two strings are equal
	bool operator==(char* str) const ;

int operator()(char ch) const ;


int operator()(const String& substr) const ;


int operator()(const string& str) ;


int operator()(char* str) ;

//String operator*(int multiplier) const;



// Get the length of the string
	int strLength() const;

    // Destructor
    ~String() ;
};

#endif /* STRING_H_ */
