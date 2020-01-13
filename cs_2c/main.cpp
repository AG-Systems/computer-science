// FHgraph and djikstra algorithm
// CS 2C Foothill College

#include <iostream>
#include <string>
#include <vector>
#include<iterator>
#include "sublist.h"

using namespace std;
using namespace cs_sublist;

int main()
{
   int TARGET = 180;
   vector<int> dataSet;
   vector<Sublist> choices;
   /*
   vector<Sublist>::iterator iter, iterBest;
   int k, j, numSets, max, masterSum;
   bool foundPerfect;
   */

   dataSet.push_back(20); 
   dataSet.push_back(12); 
   dataSet.push_back(22);
   dataSet.push_back(15); 
   dataSet.push_back(25);
   dataSet.push_back(19); 
   dataSet.push_back(29);
   dataSet.push_back(18);
   dataSet.push_back(11); 
   dataSet.push_back(13); 
   dataSet.push_back(17);
   // choices.clear();
   cout << "test 1: " << endl;
   cout << "Target time: " << TARGET << endl;
   Sublist sub_list_1;
   sub_list_1.algorithm(TARGET,dataSet);
   choices.push_back(sub_list_1);
   sub_list_1.showSublist();
   // iterBest->showSublist();




   cout << "test 2: " << endl;
   cout << "Target time: " << 179 << endl;
   Sublist sub_list_2;
   sub_list_2.algorithm(179,dataSet);
   choices.push_back(sub_list_2);
   sub_list_2.showSublist();   


   cout << "test 3: " << endl;
   cout << "Target time: " << 5000 << endl;
   Sublist sub_list_3;
   sub_list_3.algorithm(5000,dataSet);
   choices.push_back(sub_list_3);
   sub_list_3.showSublist();   

   dataSet.clear();
   dataSet.push_back(3);
   dataSet.push_back(20);
   dataSet.push_back(9);
   dataSet.push_back(5);
   dataSet.push_back(7);
   dataSet.push_back(18);
   
   TARGET = 37;

   cout << "test 4: " << endl;
   cout << "Target time: " << TARGET << endl;
   Sublist sub_list_4;
   sub_list_4.algorithm(TARGET,dataSet);
   choices.push_back(sub_list_4);
   sub_list_4.showSublist();   

   return 0; 
}
