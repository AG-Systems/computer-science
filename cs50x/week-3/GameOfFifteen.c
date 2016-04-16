#include <stdio.h>

int array[4][4] = 
{  
   {1, 2, 3, 4} ,   
   {5, 6, 7, 8} ,   
   {9, 10, 11, 12} ,
   {13,14,15, 16 }   
};

void playgame()
{
	int x = 0;
	int y = 0;
	printf("What piece do you want to move for the x and y: ");
	scanf("%s",&x,&y);
	printf("%d", &x);
};
int main()
{
	playgame();		
}
