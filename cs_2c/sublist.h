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
                cout << list[index] << endl;
                entire_sum += list[index];
            }
            if(target >= entire_sum)
            {
                sub_list = list;
                return;
            }

            	
            int highest_sum[3] = { 0,1,list.size() };  // highest sum, left_index, right_index

            for(int left_index = 1; left_index <= list.size(); left_index++)
            {
                    int left_side_sum = list[left_index];
                    int right_index = left_index += 1;
                    while (right_index < list.size() - 1)
                    {
                        if(left_side_sum == target)
                        {
                            found_perfect = true;
                            for(int index = left_side_sum; index <= right_index; index++)
                            {
                                sub_list_sum = left_side_sum;
                                sub_list.push_back(list[index]); 
                            }

                            return;

                        }
                        left_side_sum = left_side_sum + list[left_index]; 
                        right_index += 1; 
                        
                        if(left_side_sum > highest_sum[0] && left_side_sum <= target)
                        {
                            highest_sum[0] = left_side_sum;
                            highest_sum[1] = left_index;
                            highest_sum[2] = right_index;
                        }
                    }


            }
            
            sub_list_sum = highest_sum[0];
            for(int index = highest_sum[1]; index <= highest_sum[2]; index++)
            {
                sub_list.push_back(list[index]);                
            }

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
