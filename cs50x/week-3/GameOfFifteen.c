#include <stdio.h>
#include <stdlib.h>

int array[4][4] = 
{  
   {1, 2, 3, 4} ,   
   {5, 6, 7, 8} ,   
   {9, 10, 11, 12} ,
   {13,14,15, 16 }   
};

void swap(int array[4][4], int indexA, int indexB)
{
    for (size_t i=0;sizeof(array[0])/sizeof(array[0][0]);++i)
    {
        int temp = array[indexA][i];
        array[indexA][i] = array[indexB][i];
        array[indexB][i] = temp;
    }
}
void playgame()
{
	int x = 0;
	int y = 0;
	printf("What piece do you want to move for the x and y: ");
	scanf("%s",&x);
	scanf("%s",&y);
	if(array[x][y+1] == 16 || array[x+1][y] == 16 || array[x+1][y+1] == 16)
	{
		swap(array[x][y],x,y);		
	}
};

void shuffle(int *a, int len)
{
    int i;
    for (i = len - 1; i > 0; i--)   /* note that we traverse the array backwards */
    {
        int r = rand() % (i + 1);   /* random value from 0 to i, inclusive */
        int t = a[i];               /* swap a[i] and a[r] */
        a[i] = a[r];
        a[r] = t;
    }
}
int main()
{
	
	playgame();		
}
