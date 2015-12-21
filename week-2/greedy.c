#include <stdio.h>
#include <cmath>
#include <Windows.h>

int main(void)
{
	float change;
	int coins = 0;
	int stage1;
	/*
	float quator = 0.25;
	float dime = 0.10;
	float nickel = 0.5;
	float penny = 0.1;
	*/
	int quator = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;
	scanf("%d", &change);
	int convert = change * 100;
	while (convert / quator)
	{
		coins++;
		int stage1 = convert - quator;
	}
	while (convert / dime)
	{
		coins++;
		int stage1 = convert - dime;
	}
	while (convert / nickel)
	{
		coins++;
		int stage1 = convert - nickel;
	}
	while( convert / penny)
	{
		coins++;
		int stage1 = convert - penny;
	}
	printf("%d", coins);
	system("PAUSE");
}
