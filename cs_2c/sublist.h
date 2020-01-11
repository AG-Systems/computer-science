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
            found_perfect = false;
            sub_list_sum = 0;
        } 

        ~Sublist() 
        { 
            sub_list.clear();
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
                return;
            }
            vector<vector<int> > total_sub_lists;
            for(int i = 0; i <= list.size(); i++)
            {
                for(int j = i + 1; j <= list.size(); j++)
                {
                    cout << i << " " << j << endl;
                    total_sub_lists.push_back(vector<int>(list.begin() + i, list.begin() + j));
                }
            }
            
            int max_sub_list_sum = 0;

            for(int i = 0; i < total_sub_lists.size(); i++)
            {
                int current_sub_list_sum = 0;
                for(int j = 0; j < total_sub_lists[i].size(); j++)
                {
                    current_sub_list_sum += total_sub_lists[i][j];
                }
                if(current_sub_list_sum > max_sub_list_sum && current_sub_list_sum < target)
                {
                    max_sub_list_sum = current_sub_list_sum;
                    sub_list = total_sub_lists[i];
                }
            }
            sub_list_sum  = max_sub_list_sum;          

        }  

        void showSublist()
        {
            cout << "Sublist -----------------------------" << endl;
            cout << "Sum: " << sub_list_sum << endl;

            for(int i = 0; i < sub_list.size(); i++)
            {
                cout << "array[" << i << "] = " << sub_list[i] << endl;
            }
            cout << "found target perfectly: " << found_perfect << endl;
        }

      private:
            bool found_perfect;
            int sub_list_sum;
            vector<int> sub_list;
   }; 

}
#endif
