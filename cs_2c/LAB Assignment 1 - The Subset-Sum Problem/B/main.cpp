// FHgraph and djikstra algorithm
// CS 2C Foothill College

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "sublist.h"
#include <time.h> 
#include "iTunes.h"
// #include "Foothill_Sort.h"

using namespace std;
using namespace cs_sublist;

int main()
{
   const int TARGET = 3600;
   vector<iTunesEntry> dataSet;
   vector<Sublist> choices;
   vector<Sublist>::iterator iter, iterBest;
   int k, j, numSets, max, array_size, masterSum;
   bool foundPerfect;

   // read the data
   // iTunesEntryReader tunes_input("itunes_file.txt");
   iTunesEntryReader tunes_input("itunes_file.txt");
   if (tunes_input.readError())
   {
      cout << "couldn't open " << tunes_input.getFileName() 
         << " for input.\n";
      exit(1);
   }

   // time the algorithm -------------------------
   clock_t startTime, stopTime; 
   startTime = clock();

   // create a vector of objects for our own use:
   array_size = tunes_input.getNumTunes();
   for (int k = 0; k < array_size; k++)
      dataSet.push_back(tunes_input[k]);

   cout << "Target time: " << TARGET << endl;

   // code provided by student
   
   // iterBest->showSublist();
   Sublist sub_list_1;
   sub_list_1.algorithm(TARGET,dataSet);
   choices.push_back(sub_list_1);
   sub_list_1.showSublist();   

   // how we determine the time elapsed -------------------
   stopTime = clock();
   // report algorithm time
   cout << "\nAlgorithm Elapsed Time: " 
      << (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC 
      << " seconds." << endl << endl;

   return 0; 
}


/* --------- OUTPUT -----------
Target time: 3600
Sublist -----------------------------
Sum: 3600
array[0] = Cowboy Casanova by Carrie Underwood(236)
array[1] = Quitter by Carrie Underwood(220)
array[2] = Russian Roulette by Rihanna(228)
array[3] = Monkey Wrench by Foo Fighters(230)
array[4] = Pretending by Eric Clapton(283)
array[5] = Bad Love by Eric Clapton(308)
array[6] = Everybody's In The Mood by Howlin' Wolf(178)
array[7] = Well That's All Right by Howlin' Wolf(175)
array[8] = Samson and Delilah by Reverend Gary Davis(216)
array[9] = Hot Cha by Roy Buchanan(208)
array[10] = Green Onions by Roy Buchanan(443)
array[11] = I'm Just a Prisoner by Janiva Magness(230)
array[12] = You Were Never Mine by Janiva Magness(276)
array[13] = Hobo Blues by John Lee Hooker(187)
array[14] = I Can't Quit You Baby by John Lee Hooker(182)
found target perfectly: 1

Algorithm Elapsed Time: 0.214 seconds.



----------------------------  */
