#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <algorithm>

/*
Name: Max Chakhmatov
Date: June 2 2019
Instructor:  Dave Harden
Name of file: a8_1.cpp
Description:  Asks the user how many scores the user wants to input, then sorts the 
scores in descending order and displays the scores.
Output: Displays the scores in descending order.
*/



/* Highscore struct that holds 2 data members
   int score for the score
   name which is a c style string. 
*/
struct highscore {
  int score;
  char name[23];
};



/*
Initializes the data by using a vector iterator.
*/
void initializeData(std::vector<highscore>& scores)
{
        int index = 0;
        for (std::vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++) 
        {
            
            std::cout << "Enter the name for score #" << ( index + 1 )<< ": " << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Enter the score for score #" << ( index + 1 ) << ": " << std::endl;
            int score;
            std::cin >> score;

            /*
            Uses a for loop to replace the name attribute character by character
            */
            for(int z = 0; z < name.length(); z++)
            {
               (*i).name[z] = name[z]; 
            }

            (*i).score = score;
            index += 1;
        }       



}



/*
Uses selection sort and vector iterator to sort the scores.
This sorting function is O(N^2) for time.
*/
void sortData(std::vector<highscore>& scores)
{   
    int global_index = 0; // GLobal index variable is used for outer loop
    for (std::vector<highscore>::iterator iter1 = scores.begin(); iter1 != scores.end(); iter1++) 
    {  
        // Each iteration I start with the first element that is partioned.
        int min_index = global_index;
        int min_score = iter1[min_index].score;
        int index = 0; // Index variable is used for the inner loop.

        // This loop finds the smallest element and keeps track of the index.
        for (std::vector<highscore>::iterator iter2 = scores.begin() + (global_index + 1); iter2 != scores.end(); iter2++) 
        {
            if((*iter2).score < min_score)
            {
                min_score = (*iter2).score;
                min_index = index;
            }
            index += 1;
        }
        global_index += 1;         

        // Swaps the smallest element with whatever global index is it.
        // Global index acts like a partition.
        std::swap((*iter1).score, (scores[min_index].score));
        std::swap((*iter1).name, (scores[min_index].name));
    }

    std::reverse(scores.begin(), scores.end()); // Makes the array to descending order.
 
}


/*
This function displays the data using const vector iterators.
Simple for loop iteration.
*/
void displayData(const std::vector<highscore>& scores)
{
    std::cout << "Top Scorers:" << std::endl;
    for (std::vector<highscore>::const_iterator i = scores.begin(); i != scores.end(); i++) 
    {
        std::cout << (*i).name << ": " << (*i).score << std::endl;
    }

}

int main()
{
    std::cout << "How many scores will you enter?: ";
    int num_of_scores;
    std::cin >> num_of_scores;


    std::vector<highscore> highscore_objects(num_of_scores); 



    initializeData(highscore_objects);
    
    std::cout << std::endl;

    sortData(highscore_objects);
    displayData(highscore_objects);

    return 0;
}