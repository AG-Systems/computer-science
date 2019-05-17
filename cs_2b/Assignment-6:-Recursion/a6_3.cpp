#include <iostream>



int return_smallest_num_index(int array[], int size_of_array, int partition=0)
{
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

void sort_array(int array[], int size_of_array, int partition = 0)
{
    if(size_of_array == partition)
    {
        std::cout << "[ ";
        for(int i = 0; i < size_of_array; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "]" << std::endl;
        return;
    }

    int smallest_num_index = return_smallest_num_index(array, size_of_array, partition);

    int temp = array[partition];
    array[partition] = array[smallest_num_index];
    array[smallest_num_index] = temp;


    return sort_array(array, size_of_array, partition + 1);
    


}

int main()
{
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