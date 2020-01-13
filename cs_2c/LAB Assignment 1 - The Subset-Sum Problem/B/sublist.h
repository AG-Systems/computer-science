#ifndef SUBLIST_H
#define SUBLIST_H

#include <iostream>
#include <vector>
#include <numeric> 
#include "iTunes.h"

using namespace std;

namespace cs_sublist {

   class Sublist
   { 
      public:
        Sublist() 
        { 
            found_perfect = false;
            global_sub_list_sum = 0;
        } 

        ~Sublist() 
        { 
            sub_list.clear();
            global_sub_list_sum = 0;
            found_perfect = false;
        }          

        void algorithm(int target, vector<iTunesEntry>& list)
        {
            sub_list.clear();
            int entire_sum = 0;
            for(int index = 0; index < list.size(); index++)
            {
                entire_sum += list[index].getTime();
            }
            if(target >= entire_sum)
            {
                sub_list = list;
                global_sub_list_sum = entire_sum;
                return;
            }
            vector<vector<iTunesEntry> > total_sub_lists; // 
            vector<iTunesEntry> temp; 
            temp.push_back(list[0]);
            total_sub_lists.push_back(temp);


            for(int i = 1; i < list.size(); i++)
            {
                int j = 0;
                int col_size = total_sub_lists.size();
                for(int j = 0; j < col_size; j++)
                {
                    int current_sub_list_sum = 0;
                    for(int k = 0; k < total_sub_lists[j].size(); k++)
                    {
                        current_sub_list_sum += total_sub_lists[j][k].getTime();
                    }


                    if(current_sub_list_sum + list[i].getTime() <= target)
                    {
                        vector<iTunesEntry> temp = total_sub_lists[j];
                        temp.push_back(list[i]);
                        total_sub_lists.push_back(temp);
                    }
                    if(current_sub_list_sum + list[i].getTime() == target)
                    {
                        found_perfect = true;
                        global_sub_list_sum = target;
                        break;
                    }
                }
                
                if(found_perfect)
                {
                    break;
                }
            }


            int highest_sum = 0;
            int highest_sum_index = 0;
            if(found_perfect)
            {
                sub_list = total_sub_lists[total_sub_lists.size() - 1];
            } else {
                for(int i = 0; i < total_sub_lists.size(); i++)
                {
                    int current_sub_list_sum = 0;
                    for(int j = 0; j < total_sub_lists[i].size(); j++)
                    {
                        current_sub_list_sum += total_sub_lists[i][j].getTime();
                    }

                    if(current_sub_list_sum > highest_sum && current_sub_list_sum <= target)
                    {
                        highest_sum = current_sub_list_sum;
                        highest_sum_index = i;
                    }
                }

                sub_list = total_sub_lists[highest_sum_index];
                global_sub_list_sum = highest_sum;

            }

        }  

        void showSublist()
        {
            cout << "Sublist -----------------------------" << endl;
            cout << "Sum: " << global_sub_list_sum << endl;

            for(int i = 0; i < sub_list.size(); i++)
            {
                cout << "array[" << i << "] = " << sub_list[i].getTitle();
                cout << " by " << sub_list[i].getArtist() << "(";
                cout << sub_list[i].getTime() << ")" << endl;
            }
            cout << "found target perfectly: " << found_perfect << endl;
        }

      private:
            bool found_perfect;
            int global_sub_list_sum;
            vector<iTunesEntry> sub_list;

   }; 

}
#endif
