#ifndef SUBLIST_H
#define SUBLIST_H

#include <iostream>
#include <vector>

using namespace std;

namespace cs_sublist {

   class Sublist
   { 
      public:
        Sublist() 
        { 
            
        } 

        ~Sublist() 
        { 
            
        }          

        void algorithm(int target, vector<int>& list)
        {
            int current_highest = list[0];
            int highest_ending = list[0];

            int left = 0;
            int right = list.size();

            for(int i = 1; i < list.size(); i++)
            {
                
                if(highest_ending + list[i] > list[i])
                {
                    highest_ending = highest_ending + list[i];
                } else {
                    highest_ending = list[i];
                    left += 1;
                }

                int temp = 0;
                if(highest_ending > current_highest)
                {
                    temp = highest_ending;
                    
                } else {
                    temp = current_highest;
                }

                if(temp <= target)
                {
                    current_highest = temp;
                }
                
            }





        }  

        void showSublist()
        {

        }

      private:

   }; 

}
#endif