#include <iostream>
#include <algorithm> 
#include <stdlib.h>
#include <time.h>
#include <random>
#include <ctime>        
#include <cstdlib> 
#include <cstddef>


void shuffle(int a[][4]) 
{ 
     srand(time(NULL)); 
     std::random_shuffle(&a[0][0], &a[0][0] + 4*4); 
};
int a[4][4] = 
{  
   {1, 2, 3, 4} ,   
   {5, 6, 7, 8} ,   
   {9, 10, 11, 12} ,
   {13,14,15, 00 }   
};

int winninga[4][4] =
{
   {1, 2, 3, 4} ,   
   {5, 6, 7, 8} ,   
   {9, 10, 11, 12} ,
   {13,14,15, 00 }   
};

bool win()
{
	if(a == winninga)
	{
		std::cout << "You won! " << std::endl;
		return true;
	}
	if(a != winninga)
	{
		return false;
	}
}
void playgame(int a[4][4])
{
	shuffle(a);
	win();
	int x = 0;
	int y = 0;
	while(true)
	{
		for(int z = 0; z < 4; z++)
		{
			for(int x = 0; x < 4; x++)
			{
				std::cout <<  a[z][x] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		std::cout << "Please pick a position X-Y: " << std::endl;
		std::cin >> x;
		std::cin >> y;
		std::cout << "\n" << "The number you have choose was: " << a[x][y] << std::endl; 
		if(a[x][y] != 00 )
		{
			if(a[x+1][y] == 00)
			{
				std::swap(a[x][y], a[x+1][y]);
			}
			else if(a[x][y+1] == 00)
			{
				std::swap(a[x][y], a[x][y+1]);			
			}
			else if(a[x][y-1] == 00)
			{
				std::swap(a[x][y], a[x][y-1]);					
			}
			else if(a[x-1][y] == 00)
			{
				std::swap(a[x][y], a[x-1][y]);			
			}
		}
		else
		{
			std::cout << "Please pick the number that is not null " << std::endl;
		}
	}
}

int main()
{
	playgame(a);
	std::cin.get();
}
