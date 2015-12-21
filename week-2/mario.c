#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int height;
	int hash = 0;
	int counter = 0;
	scanf("%d", &height);
	int space = height - 1;
	for(int x = 0; x < (space); x++)
	{
		counter++;
		if(x = 0)
		{
			hash = 2;
		}
		if(x < 1)
		{
			hash++;
		}
		space--;
		if(counter > 1)
		{
			for(int z = 0; z < hash; z++)
			{
				printf("#");

			}
		printf("\n");
		}
	}
}
