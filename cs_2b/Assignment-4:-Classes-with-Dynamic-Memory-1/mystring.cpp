#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <cmath> 
#include "mystring.h"

namespace cs_mystring {

    MyString::MyString(const char* new_string):string(nullptr) 
    {        
        size_t string_length = strlen(new_string);
        /*
        if(string_length > 0)
        {
            string = new char[string_length + 1];
            strcpy (string, new_string);
        } else {
            string = new char[1];
            string[0] = '\0';
        }
        */
        string = new char[string_length + 1];
        strcpy (string, new_string);
        
    }


    MyString::MyString(const MyString& right):string(nullptr) 
    {     
        size_t string_length = strlen(right.string);
        #if 0
        if(string_length > 0)
        {
            /* nice*/
            string = new char[string_length + 1];
            strcpy (string, right.string);
        } else {
            string = new char[1];
            string[0] = '\0';
        }  
        #endif
        
        /*
        string = new char[string_length + 1];
        strcpy (string, right.string);
        */

        assignment(right.string);     
    }

    void MyString::assignment(const char* ptr)
    {
        delete []string;
        size_t string_length = strlen(ptr);
        string = new char[string_length + 1];
        strcpy (string, ptr);      
    }

    MyString::MyString():string(nullptr) 
    {   
        /*
        string = new char[1];
        string[0] = '\0';
        */
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

    MyString& MyString::operator=(const MyString& right)
    {
        assignment(right.string);
        /*
        char * temp = new char[0];
        return temp;
        */
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


   ostream& operator<<(ostream& out, const MyString& right)
   {  
        
      out << right.string;
      return out;
   }    



}
