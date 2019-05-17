#include "mystring.h"
#include <iostream>
#include <cctype>


using namespace cs_mystring;


bool isAPalindrome(const MyString& str, int lower_bound, int upper_bound)
{
    if(lower_bound >= upper_bound)
    {
        if(lower_bound != 0 && upper_bound != 0)
        {
            return toupper(str[lower_bound]) == toupper(str[upper_bound]);
        } else {
            return true;
        }
        
    } else {
        if(ispunct(str[lower_bound]) || isspace(str[lower_bound]))
        {
            return isAPalindrome(str, lower_bound + 1, upper_bound);
        }
        if(ispunct(str[upper_bound]) || isspace(str[upper_bound]))
        {
            return isAPalindrome(str, lower_bound, upper_bound - 1);
        }
        if(toupper(str[lower_bound]) == toupper(str[upper_bound])) 
        {
            return isAPalindrome(str, lower_bound + 1, upper_bound - 1);
        } else {
            return false;
        }
    }
}   


int main()
{
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    int string_length = s1.length();
    std::cout << isAPalindrome(s1, 0, s1.length() - 1 )  << std::endl;

    const MyString strs[] = {
                 MyString("Wow"), 
                 MyString("C++ is neat!"),
                 MyString("abcdefghijklmnopqsrtuvwxyz"), 
                 MyString("a a "),
                 MyString("A a "), MyString("Able was I, ere I saw Elba"),
                 MyString("Able was I, ere I saw Elba          "),
                 MyString("        Able was I, ere I saw Elba"),
                 MyString("        Able was I, ere I saw Elba    "),
                 MyString("peanut butter"),
                 MyString("racecar"),
                 MyString(""),
    };
                 
                 
    for (int i = 0; i < 12; i++)
    {
        std::cout << "string [" << i <<"] = " << strs[i] << std::endl;
        std::cout << isAPalindrome(strs[i], 0, strs[i].length() - 1 )  << std::endl;
    }

    return 0;
}
