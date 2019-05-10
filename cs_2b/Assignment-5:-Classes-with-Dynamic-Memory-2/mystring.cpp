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
        string = new char[string_length + 1];
        strcpy (string, new_string);
        
    }


    MyString::MyString(const MyString& right):string(nullptr) 
    {     
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

   ostream& operator<<(ostream& out, const MyString& right)
   {  
        
      out << right.string;
      return out;
   }    

   istream& operator>>(istream& in, MyString& right)
   {  
        while (isspace(in.peek())){
            in.ignore();
        }
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE);
        delete [] right.string;
        right.string = new char[strlen(temp) + 1];
        strcpy(right.string, temp);
        in >> right.string;
        return in;

       
   } 

   void MyString::read(std::istream& infile, const char right)
   {
        
        char temp[MyString::MAX_INPUT_SIZE + 1];
        infile.getline(temp, MyString::MAX_INPUT_SIZE, right);
        char * str = new char[strlen(temp)];
        strcpy(str, temp);
        
        infile >> str;       

   }


}
