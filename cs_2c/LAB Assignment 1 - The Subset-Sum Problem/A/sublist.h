#ifndef SUBLIST_H
#define SUBLIST_H

#include <iostream>
#include <vector>
#include <numeric> 

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

        void algorithm(int target, vector<int>& list)
        {
            sub_list.clear();
            int entire_sum = 0;
            for(int index = 0; index < list.size(); index++)
            {
                entire_sum += list[index];
            }
            if(target >= entire_sum)
            {
                sub_list = list;
                global_sub_list_sum = entire_sum;
                return;
            }
            vector<vector<int> > total_sub_lists;
            vector<int> temp; 
            temp.push_back(list[0]);
            total_sub_lists.push_back(temp);
            

            for(int i = 1; i < list.size(); i++)
            {
                int j = 0;
                int col_size = total_sub_lists.size();
                for(int j = 0; j < col_size; j++)
                {
                    int current_sub_list_sum = accumulate(total_sub_lists[j].begin(), total_sub_lists[j].end(), 0);
                    if(current_sub_list_sum + list[i] <= target)
                    {
                        vector<int> temp = total_sub_lists[j];
                        temp.push_back(list[i]);
                        total_sub_lists.push_back(temp);
                    }
                    if(current_sub_list_sum + list[i] == target)
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
                    int current_sub_list_sum = accumulate(total_sub_lists[i].begin(), total_sub_lists[i].end(), 0);
                    if(current_sub_list_sum > highest_sum && current_sub_list_sum <= target)
                    {
                        highest_sum =  current_sub_list_sum;
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
                cout << "array[" << i << "] = " << sub_list[i] << endl;
            }
            cout << "found target perfectly: " << found_perfect << endl;
        }

      private:
            bool found_perfect;
            int global_sub_list_sum;
            vector<int> sub_list;

            void debug(vector<int>& list)
            {
                cout << "debug: =====================" << endl;
                for(int i = 0; i < list.size(); i++)
                {
                    cout << list[i] << endl;
                }
                cout << "debug end: =====================" << endl;
            }
   }; 

}
#endif
