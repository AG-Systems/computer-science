#include <stdio.h>

void linearsearch(int key, int a[],int size)
{
	for(int z = 0; z < size; z++)
    {
        if(key == a[z])
        {
            printf("Found number. The position is: %d\n", z);
            break;
        }
    }
}

int main()
{
    int array[8] = {1,2,3,4,5,6,7,8};
    linearsearch(5,array,8);
    return 0;

}

