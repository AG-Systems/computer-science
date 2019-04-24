#include <iostream>
#include <string>


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
