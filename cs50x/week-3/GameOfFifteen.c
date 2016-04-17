#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0);

int a[4][4] = 
{  
   {1, 2, 3, 4} ,   
   {5, 6, 7, 8} ,   
   {9, 10, 11, 12} ,
   {13,14,15, 0 }   
};


void playgame()
{
	while(true)
	{
		int x = 0;
		int y = 0;
		for(int x = 0; x < 4; x++)
		{
			for(int z = 0; z < 4; z++)
			{
				printf("%d  ",a[x][z]);

			}
			printf("\n");
		}
		printf("What piece do you want to move for the x and y: ");
		scanf("%s",&x);
		scanf("%s",&y);
		if(a[x][y] != 00 )
		{
			if(a[x+1][y] == 00)
			{
				SWAP(a[x][y], a[x+1][y],int);
			}
			else if(a[x][y+1] == 00)
			{
				SWAP(a[x][y], a[x][y+1],int);			
			}
			else if(a[x][y-1] == 00)
			{
				SWAP(a[x][y], a[x][y-1],int);					
			}
			else if(a[x-1][y] == 00)
			{
				SWAP(a[x][y], a[x-1][y],int);			
			}
		}
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
	// shuffle(a,16);
	playgame();		
}
