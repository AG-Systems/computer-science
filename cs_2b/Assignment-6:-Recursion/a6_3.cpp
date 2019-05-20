#include <iostream>

/*
Max Chakhmatov
May 20, 2019

This program has 2 functions. 
1) Finds the smallest number and returns the index using a simple for loop.
2) Sorts the array using recursion and modeled after the selection sort.

*/



int return_smallest_num_index(int array[], int size_of_array, int partition=0)
{
    // Self explanatory for all parameters besides partition.
    // Partition variable is used to restrict the range of the array.
    // We want to make sure we dont keep returning the same smallest num
    int smallest_num = array[partition];
    int smallest_num_index = partition;
    for(int i = partition; i < size_of_array; i++)
    {
        if(array[i] < smallest_num)
        {
            smallest_num = array[i];
            smallest_num_index = i;
        }
    }
    return smallest_num_index;
}

/*
This function runs at O(n^2)
*/
void sort_array(int array[], int size_of_array, int partition = 0)
{
    if(size_of_array == partition) // Base case
    {
        // When the array is sorted, it will print
        // all of the values in order.
        std::cout << "[ ";
        for(int i = 0; i < size_of_array; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "]" << std::endl;
        return;
    }

    // FIrst we grab the smallest number by index
    int smallest_num_index = return_smallest_num_index(array, size_of_array, partition);

    // Then we swap smallest number to the sorted section
    // The sorted section is split by partition variable
    int temp = array[partition];
    array[partition] = array[smallest_num_index];
    array[smallest_num_index] = temp;


    // Then we re call the function again until the base case is reached
    // The base case is when the parition reaches the end
    return sort_array(array, size_of_array, partition + 1);
    


}

int main()
{
    // Worst case for sorting algorithms is when the entire array is reversed.
    int array_1[11] = {10,9,8,7,6,5,4,3,2,1,0};
    sort_array(array_1, 11);

    int array_2[11] = {1,5,2,-1,7,8,3,9,11,20,30};
    sort_array(array_2, 11);

    int array_3[11] = {5,3,8,1,9,20,60,1000,500,300,20};
    sort_array(array_3, 11);

    int array_4[11] = {0,1,2,3,4,5,6,7,8,9,10};
    sort_array(array_4, 11);
    
    return 0;
}

/*
[ 0 1 2 3 4 5 6 7 8 9 10 ]
[ -1 1 2 3 5 7 8 9 11 20 30 ]
[ 1 3 5 8 9 20 20 60 300 500 1000 ]
[ 0 1 2 3 4 5 6 7 8 9 10 ]
*/