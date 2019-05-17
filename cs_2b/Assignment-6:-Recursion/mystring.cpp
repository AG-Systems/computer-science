/*
    Max Chakhmatov
    CS_2B
    Assignment 5

    This program has a custom C style string function class. It uses dynamic memory and effeciently allocates memory.
    Contains some basic functions like read which is a cin.getline like function.

*/


#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <cmath> 
#include "mystring.h"

namespace cs_mystring {

    /*
        Constructor with a parameter c style string passed in.

    */
    MyString::MyString(const char* new_string):string(nullptr) 
    {        
        size_t string_length = strlen(new_string);
        string = new char[string_length + 1];
        strcpy (string, new_string);
        
    }




    /*
        Constructor with a MyString object passed in.

    */
    MyString::MyString(const MyString& right):string(nullptr) 
    {     
        assignment(right.string);     
    }




    /*
    Deletes the current data member pointer data to make sure no memory leaks happen.
    Then resizes and adds +1 to space for the null end pointer.
    Then copies the data to the data member.
    */
    void MyString::assignment(const char* ptr)
    {
        delete []string;
        size_t string_length = strlen(ptr);
        string = new char[string_length + 1];
        strcpy (string, ptr);      
    }




    MyString::MyString():string(nullptr) 
    {   
        assignment("");
    }





    MyString::~MyString() 
    { 
        delete []string; 
        string = NULL;
    } 



    int MyString::length() const
    {
        return strlen(string);
    }

    

    // ARRAY LIKE OPERATORS
    char& MyString::operator[](size_t i)
    {
        assert(i < strlen(string));
        return string[i];
    }
    




    const char& MyString::operator[](size_t i) const
    {
        assert(i < strlen(string));
        return string[i];
    }



    // RELATIONAL OPERATORS
    MyString& MyString::operator=(const MyString& right)
    {
       assignment(right.string);
       return *this;

    }




    MyString& MyString::operator=(const char* right)
    {
       assignment(right);
       return *this;    
    }
    



    bool operator<(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) < 0);
    }





    bool operator<(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) < 0);
    }






    bool operator<(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) < 0);
    }



    bool operator<=(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) <= 0);
    }






    bool operator<=(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) <= 0);
    }





    bool operator<=(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) <= 0);
    }


    bool operator>(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) > 0);
    }





    bool operator>(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) > 0);
    }





    bool operator>(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) > 0);
    }




    bool operator>=(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) >= 0);
    }




    bool operator>=(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) >= 0);
    }





    bool operator>=(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) >= 0);
    }


    bool operator==(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) == 0);
    }





    bool operator==(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) == 0);
    }





    bool operator==(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) == 0);
    }




    bool operator!=(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) != 0);
    }




    bool operator!=(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) != 0);
    }




    bool operator!=(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) != 0);
    }




    // ARITHMETIC OPERATORS
    MyString operator+(const MyString& left, const MyString& right)
    {
        MyString result;
        delete [] result.string;
        size_t string_length = strlen(left.string) + strlen(right.string);
        result.string = new char[string_length + 1];
        strcpy(result.string, left.string);
        strcat(result.string, right.string);
        return result;
    }





    MyString operator+(const MyString& left, const char * right)
    {
        MyString result;
        delete [] result.string;
        size_t string_length = strlen(left.string) + strlen(right);
        result.string = new char[string_length + 1];
        strcpy(result.string, left.string);
        strcat(result.string, right);
        return result;
    }





    MyString operator+(const char * left, const MyString& right)
    {
        MyString result;
        delete [] result.string;
        size_t string_length = strlen(left) + strlen(right.string);
        result.string = new char[string_length + 1];
        strcpy(result.string, left);
        strcat(result.string, right.string);
        return result;
    }




    // ARITHMETIC OPERATORS
    MyString& MyString::operator+=(const MyString& right)
    {
        *this = *this + right.string;    
        return *this;




    }




    MyString& MyString::operator+=(const char * right)
    {
        *this = *this + right;    
        return *this;
    }



    // OUTPUT OPERATORS
   ostream& operator<<(ostream& out, const MyString& right)
   {  
        
      out << right.string;
      return out;
   }    




    // EXTRACTION OPERATOR
   istream& operator>>(istream& in, MyString& right)
   {    
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE, ' ');
        delete [] right.string;
        right.string = new char[strlen(temp) + 1];
        strcpy(right.string, temp);
        in >> right.string;
        return in;  
   } 



    /*
        Creates a temporary non dyanimic char array with a size of 127 (+ 1 for null pointer)
        Gets the inputted data from the right parameter. 
        Rezises the data member by deleting the existing data and resizing by the temp char size.
    */
   void MyString::read(std::istream& infile, const char right)
   {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        infile.getline(temp, MyString::MAX_INPUT_SIZE, right);
        delete []string;
        string = new char[strlen(temp) + 1];
        strcpy (string, temp); 
   }


}


/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] = 
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next    
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing apple to 
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing  to Banana
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing Banana to Banana
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing why to wackity
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
*/