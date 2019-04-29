#include <iostream>
#include <string>


/*
Name: Max Chakhmatov
Date: April 29 2019
Instructor:  Dave Harden
Name of file: a3_2.cpp
Description:  Asks the user how many scores the user wants to input, then sorts the 
scores in descending order and displays the scores.
Output: Displays the scores in descending order.
*/


/*
Intalializes the array using recurssion.
The reason why initialize array recursion function is called
in the top so the array initialize the array in asceending order
( The prompts are asked in order: #1, #2, #3 etc)
*/
void initializeArrays(std::string names[], int scores[], int size)
{
    if(size > 0)
    {
        initializeArrays(names, scores, size - 1);
        std::cout << "Enter the name for score #" << size << ": " << std::endl;
        std::string name;
        std::cin >> name;
        std::cout << "Enter the score for score #" << size << ": " << std::endl;
        int score;
        std::cin >> score;
        names[size - 1] = name;
        scores[size - 1] = score;
    }
}



/*
Sorts the data by using bubble sort with recurssion.
Does it in descending order
Each recurssion call, loops through it once and swaps values
in the right order then recalls it until the base case is reached.

With recursion, the function is O(N^2) for time complexity
*/
void sortData(std::string names[], int scores[], int size)
{
    if (size <= 1)
    {
        return; 
    } 

  
    for (int i = 0; i < size - 1; i++) 
    {
        if (scores[i] < scores[i+1]) 
        {
             std::swap(scores[i], scores[i+1]);
             std::swap(names[i], names[i+1]);            
        }

    }


    return sortData(names, scores, size - 1);      

}


/* 
Displays the data in descending order by using recursion.
The recursion function is called first so the data can be printed
in descending order. 

Prints the top scorers statement first then prints out the array elements 
from top to bottom.

Uses recursion to loop through the array.
*/
void displayData(const std::string names[], const int scores[], int size)
{
    if(size > 0)
    {
        if(size == 1)
        {
            std::cout << "Top Scorers:" << std::endl;
        }

        displayData(names, scores, size - 1);
        std::cout << names[size - 1] << ": " << scores[size - 1] << std::endl;
        
    }

}


int main()
{
    std::cout << "How many scores will you enter?: ";
    int num_of_scores;
    std::cin >> num_of_scores;
    std::string* names= new std::string[num_of_scores];
    int* scores = new int[num_of_scores];

    initializeArrays(names, scores, num_of_scores);
    
    std::cout << std::endl;

    sortData(names, scores, num_of_scores);
    displayData(names, scores, num_of_scores);

    return 0;
}
