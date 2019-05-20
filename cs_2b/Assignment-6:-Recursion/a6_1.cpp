#include <iostream>
#include <cstring>

/* 
Max Chakhmatov
May 20, 2019

This program reverses the array by a specific range that the user inputs.
It goes down until the bounds equal to each other

*/

void reverseWithinBounds(char char_array[], int lower_bound, int higher_bound)
{
    if(lower_bound < higher_bound)
    {
        /*
        Creates a temporary char variable that holds one of the values.
        Swaps it, then sets the upper bound element to the old value
        */
        char temp;
        temp = char_array[lower_bound];
        char_array[lower_bound] = char_array[higher_bound];
        char_array[higher_bound] = temp;

        // If the difference more then one, then keep iterating
        if(higher_bound - lower_bound > 1)
        {
            reverseWithinBounds(char_array, lower_bound += 1, higher_bound -=1 );
        } else {
            // If the difference is one, then the recursion call,
            // WILL make a endless recursion loop.
            std::cout << char_array << std::endl;
        }
    } else if(lower_bound > higher_bound) {
        // If the user inputs the lower bounds and upper bounds reversed.
        // This reverses and sets it correctly.
        return reverseWithinBounds(char_array, higher_bound, lower_bound);     
    } else {
        std::cout << char_array << std::endl; // Prints the reversed string
        return;
    }
}  



void reverseCstring(char * str)
{
    // Creates a char array with the size length of c style string length
    char char_array[strlen(str) + 1];

    // Copies the values from the string into the char array 
    strcpy(char_array, str);

    // Calls the reucrsive function that will reverse the ENTIRE char array.
    reverseWithinBounds(char_array, 0, strlen(str) - 1);
}

int main()
{
    char array_test[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    reverseWithinBounds(array_test, 1, 3);
    reverseWithinBounds(array_test, 3, 1);
    reverseWithinBounds(array_test, 0, 6); 
    reverseWithinBounds(array_test, 4, 5);
    reverseWithinBounds(array_test, 2, 2);  
    reverseCstring("C++ is neat!");
    return 0;
}

/*
adcbefg
abcdefg
gfedcba
gfedbca
gfedbca
!taen si ++C
*/