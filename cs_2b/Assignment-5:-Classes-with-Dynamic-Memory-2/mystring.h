#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include <cmath> 
#include <iostream>


using namespace std;

namespace cs_mystring {

   class MyString
   { 
      public:
        MyString(const char* new_string);  
        /*
            pre:  const C style string is passed.
            post: Construct the object.
        */

        MyString(const MyString& right);  
        /*
            pre:  const C style string is passed.
            post: Construct the object.
        */

        MyString(); 
        /*
            post: Construct the object with no parameter.
        */

        ~MyString(); 
        /*
            post: Deconstructor that deletes the data member and sets data to null.
        */     
        int length() const;  
        /*
            post: Return the length of the data member c style string.
        */

        friend bool operator<(const MyString& left, const MyString& right);
        // post: Returns true if left < right, false otherwise.
        friend bool operator<(const MyString& left, const char * right);
        // post: Returns true if left < right, false otherwise.
        friend bool operator<(const char * left, const MyString& right);
        // post: Returns true if left < right, false otherwise.
        friend bool operator<=(const MyString& left, const MyString& right);
        // post: Returns true if left <= right, false otherwise.
        friend bool operator<=(const MyString& left, const char * right);
        // post: Returns true if left <= right, false otherwise.
        friend bool operator<=(const char * left, const MyString& right);
        // post: Returns true if left <= right, false otherwise.
        friend bool operator>(const MyString& left, const MyString& right);
        // post: Returns true if left > right, false otherwise.
        friend bool operator>(const MyString& left, const char right[]);
        // post: Returns true if left > right, false otherwise.
        friend bool operator>(const char * left, const MyString& right);
        // post: Returns true if left > right, false otherwise.
        friend bool operator>=(const MyString& left, const MyString& right);
        // post: Returns true if left >= right, false otherwise.
        friend bool operator>=(const MyString& left, const char * right);
        // post: Returns true if left >= right, false otherwise.
        friend bool operator>=(const char * left, const MyString& right);
        // post: Returns true if left >= right, false otherwise.
        friend bool operator==(const MyString& left, const MyString& right);
        // post: Returns true if left == right, false otherwise.
        friend bool operator==(const MyString& left, const char * right);
        // post: Returns true if left == right, false otherwise.
        friend bool operator==(const char * left, const MyString& right);
        // post: Returns true if left == right, false otherwise.
        friend bool operator!=(const MyString& left, const MyString& right);
        // post: Returns true if left != right, false otherwise.
        friend bool operator!=(const MyString& left, const char * right);
        // post: Returns true if left != right, false otherwise.
        friend bool operator!=(const char * left, const MyString& right);
        // post: Returns true if left != right, false otherwise.
        friend std::ostream& operator<<(std::ostream& out, 
                            const MyString& right);
        // post: returns the data member that is printed able
        friend std::istream& operator>>(std::istream& in, 
                                       MyString& right);
        // post: Uses the extraction operator.
        char& operator[](size_t i);
        /*
          pre: Passes a unsigned integer
          post: Returns the accessed referrence character for modification
        */
        const char& operator[](size_t i) const;
        /*
          pre: Passes a unsigned integer
          post: Returns the character as a value
        */
        MyString& operator=(const MyString& right);
        /*
          pre: Passes a my string object
          post: Sets the left side of the object value to the right
        */
        MyString& operator=(const char * right);
        /*
          pre: Passes a const c style string
          post: Sets the left side of the object value to the right
        */
        friend MyString operator+(const MyString& left, const MyString& right);
        /*
          pre: Both must be objects
          post: Concerates the left value with the right
        */

        friend MyString operator+(const MyString& left, const char * right);
        /*
          pre: Left must be object, right must be a c style string
          post: Concerates the left value with the right value.
        */
        friend MyString operator+(const char * left, const MyString& right);
        /*
          pre: Right must be object, left must be a c style string
          post: Concerates the left value with ther ight
        */
        MyString& operator+=(const MyString& right);
        /*
          pre: Mystring object must be on the right side
          post: Concerates the left value with the right
        */
        MyString& operator+=(const char * right);
        /*
          pre: C style string must be passed
          post: Concerates the left value with the right
        */
        void read(std::istream& infile, const char right);     
        /*
          pre: istream object and a char character must be passed
        */
        static const int MAX_INPUT_SIZE = 127;

      private:
        void assignment(const char* ptr);
        char* string;
   }; 

}
#endif