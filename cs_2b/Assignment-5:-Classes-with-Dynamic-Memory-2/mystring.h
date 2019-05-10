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
        MyString(const MyString& right);  
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

        friend std::istream& operator>>(std::istream& in, 
                                       MyString& right);
        char& operator[](size_t i);
        const char& operator[](size_t i) const;

        MyString& operator=(const MyString& right);
        MyString& operator=(const char * right);

        friend MyString operator+(const MyString& left, const MyString& right);
        friend MyString operator+(const MyString& left, const char * right);
        friend MyString operator+(const char * left, const MyString& right);

        MyString& operator+=(const MyString& right);
        MyString& operator+=(const char * right);

        void read(std::istream& infile, const char right);
        
        static const int MAX_INPUT_SIZE = 127;

      private:
        void assignment(const char* ptr);
        char* string;
   }; 

}
#endif
