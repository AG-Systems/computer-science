#include "mystring.h"
#include <iostream>
#include <cctype>

/*
Max Chakhmatov
May 20 2019

This program checks if a MyString (c style string object) is a palindrome which means it can read backwards and forward.
The palindrome function uses only recursion to determine if its true or not (c++ treats booleans as 0's and 1's).
Its non case sensitive and whitespace sensitive. It also doesn't modify the original data.
*/

using namespace cs_mystring;

/*
This function uses recurssion to determine if its a palindrome
*/
bool isAPalindrome(const MyString& str, int lower_bound, int upper_bound)
{
    if(lower_bound >= upper_bound) // Base case (when almost everything has been checked)
    {
        if(lower_bound != 0 && upper_bound != 0)
        {
            // This bassically checks for the last characters.
            return toupper(str[lower_bound]) == toupper(str[upper_bound]); 
        } else {
            return true; // Returns true if the string length is 0, ex: ""
        }
        
    } else {
        if(ispunct(str[lower_bound]) || isspace(str[lower_bound]))
        {
            /* If the element of the left side is either a space or punctional,
            it will keep increaminting the left side value until it hits a real "character"
            */
            return isAPalindrome(str, lower_bound + 1, upper_bound);
        }
        if(ispunct(str[upper_bound]) || isspace(str[upper_bound]))
        {
            /* If the element of the right side is either a space or punctional,
            it will keep increaminting the right side value until it hits a real "character"
            */
            return isAPalindrome(str, lower_bound, upper_bound - 1);
        }
        if(toupper(str[lower_bound]) == toupper(str[upper_bound])) 
        {
            /*
            Once we both reach characters that are not punctionals, and spaces,
            this will evaluate the characters by making it lower case.
            If its true, it will move up the lower bound by one and upper bound by - one.
            The base case will catch once the lower bound and upper bound the same.
            */
            return isAPalindrome(str, lower_bound + 1, upper_bound - 1);
        } else {
            // When the characters don't equal to each other
            return false; 
        }
    }
}   


int main()
{
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    int string_length = s1.length();
    std::cout << isAPalindrome(s1, 0, s1.length() - 1 )  << std::endl; // Simple test of an object

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
                 
                 
    for (int i = 0; i < 12; i++) // Test of a object array
    {
        std::cout << "string [" << i <<"] = " << strs[i] << std::endl;
        std::cout << isAPalindrome(strs[i], 0, strs[i].length() - 1 )  << std::endl;
    }

    return 0;
}


/*
0
string [0] = Wow
1
string [1] = C++ is neat!
0
string [2] = abcdefghijklmnopqsrtuvwxyz
0
string [3] = a a 
1
string [4] = A a 
1
string [5] = Able was I, ere I saw Elba
1
string [6] = Able was I, ere I saw Elba          
1
string [7] =         Able was I, ere I saw Elba
1
string [8] =         Able was I, ere I saw Elba    
1
string [9] = peanut butter
0
string [10] = racecar
1
string [11] = 
1

*/