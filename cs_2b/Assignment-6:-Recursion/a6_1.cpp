#include <iostream>
#include <cstring>

void reverseWithinBounds(char char_array[], int lower_bound, int higher_bound)
{
    if(lower_bound < higher_bound)
    {
        char temp;
        temp = char_array[lower_bound];
        char_array[lower_bound] = char_array[higher_bound];
        char_array[higher_bound] = temp;
        if(higher_bound - lower_bound > 1)
        {
            reverseWithinBounds(char_array, lower_bound += 1, higher_bound -=1 );
        } else {
            std::cout << char_array << std::endl;
        }
    } else if(lower_bound > higher_bound) {
        return reverseWithinBounds(char_array, higher_bound, lower_bound);     
    } else {
        std::cout << char_array << std::endl;
        return;
    }
}  



void reverseCstring(char * str)
{
    char char_array[strlen(str) + 1]; 
    strcpy(char_array, str);
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
