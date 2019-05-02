#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <cmath> 
#include "mystring.h"

namespace cs_mystring {

    MyString::MyString(char* new_string)
    {        
        if(strlen(new_string) > 0)
        {
            strcpy (string, new_string);
        } else {
            strcpy (string, "\0");
        }
        
    }

    MyString::MyString()
    {   
        strcpy (string, "\0");
    }

    MyString::~MyString() 
    { 
        delete []string; 
    } 

    int MyString::length() const
    {
        return strlen(string);
    }

    
    char& MyString::operator[](int i)
    {
        return string[i];
    }
    

    char MyString::operator[](unsigned int i) const
    {
        char val;
        val = string[i];
        return val;
    }


    bool operator<(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) > 0);
    }
    bool operator<(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) > 0);
    }
    bool operator<(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) > 0);
    }



    bool operator<=(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) >= 0);
    }
    bool operator<=(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) >= 0);
    }
    bool operator<=(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) >= 0);
    }


    bool operator>(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) <= 0);
    }
    bool operator>(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) <= 0);
    }
    bool operator>(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) <= 0);
    }


    bool operator>=(const MyString& left, const MyString& right)
    {
        return (strcmp(left.string, right.string) <= 0);
    }
    bool operator>=(const MyString& left, const char * right)
    {
        return (strcmp(left.string, right) <= 0);
    }
    bool operator>=(const char * left, const MyString& right)
    {
        return (strcmp(left, right.string) <= 0);
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


   ostream& operator<<(ostream& out, const MyString& right)
   {  
        
      out << right.string;
      return out;
   }    



}
