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
        MyString(char* new_string);  
        MyString();  
        ~MyString();

        int length() const;

        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator<(const MyString& left, const char * right);
        friend bool operator<(const char * left, const MyString& right);

        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const char * right);
        friend bool operator<=(const char * left, const MyString& right);

        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const char right[]);
        friend bool operator>(const char * left, const MyString& right);

        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const char * right);
        friend bool operator>=(const char * left, const MyString& right);

        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const char * right);
        friend bool operator==(const char * left, const MyString& right);

        friend bool operator!=(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const char * right);
        friend bool operator!=(const char * left, const MyString& right);

        friend std::ostream& operator<<(std::ostream& out, 
                            const MyString& right);

        char& operator[](int i);
        char operator[](unsigned int i) const;
             
      private:
        char* string = new char;
   }; 

}
#endif
