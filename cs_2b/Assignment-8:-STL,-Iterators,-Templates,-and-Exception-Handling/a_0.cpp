#include <iostream>
#include <string>
#include <cstring>

/*
Name: Max Chakhmatov
Date: April 29 2019
Instructor:  Dave Harden
Name of file: a3_2.cpp
Description:  Asks the user how many scores the user wants to input, then sorts the 
scores in descending order and displays the scores.
Output: Displays the scores in descending order.
*/


struct highscore {
  int score;
  char name[23];
};


/*
Intalializes the array using recurssion.
The reason why initialize array recursion function is called
in the top so the array initialize the array in asceending order
( The prompts are asked in order: #1, #2, #3 etc)
*/
void initializeData(highscore scores[], int size)
{
    if(size > 0)
    {
        initializeData(scores, size - 1);
        std::cout << "Enter the name for score #" << size << ": " << std::endl;
        std::string name;
        std::cin >> name;
        std::cout << "Enter the score for score #" << size << ": " << std::endl;
        int score;
        std::cin >> score;

        scores[size - 1].score = score;
        for(int i = 0; i < name.length(); i++)
        {
            scores[size - 1].name[i] = name[i];
        }
    }
}



/*
Sorts the data by using bubble sort with recurssion.
Does it in descending order
Each recurssion call, loops through it once and swaps values
in the right order then recalls it until the base case is reached.

With recursion, the function is O(N^2) for time complexity
*/
void sortData(highscore scores[], int size)
{
    if (size <= 1)
    {
        return; 
    } 

  
    for (int i = 0; i < size - 1; i++) 
    {
        if (scores[i].score < scores[i+1].score) 
        {
             std::swap(scores[i], scores[i+1]);         
        }

    }


    return sortData(scores, size - 1);      

}


/* 
Displays the data in descending order by using recursion.
The recursion function is called first so the data can be printed
in descending order. 

Prints the top scorers statement first then prints out the array elements 
from top to bottom.

Uses recursion to loop through the array.
*/
void displayData(const highscore scores[], int size)
{
    if(size > 0)
    {
        if(size == 1)
        {
            std::cout << "Top Scorers:" << std::endl;
        }

        displayData(scores, size - 1);
        std::cout << scores[size - 1].name << ": " << scores[size - 1].score << std::endl;
        
    }

}

int main()
{
    std::cout << "How many scores will you enter?: ";
    int num_of_scores;
    std::cin >> num_of_scores;

    highscore* highscore_objects = new highscore[num_of_scores];



    //std::string* names= new std::string[num_of_scores];
    //int* scores = new int[num_of_scores];

    initializeData(highscore_objects, num_of_scores);
    
    std::cout << std::endl;

    sortData(highscore_objects, num_of_scores);
    displayData(highscore_objects, num_of_scores);

    return 0;
}
