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
