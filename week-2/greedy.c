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
	scanf("%f", &change);
	long long convert = change * 100;
	while (convert / quator)
	{
		coins++;
		convert = convert - quator;
	}
	while (convert / dime)
	{
		coins++;
		convert - dime;
	}
	while (convert / nickel)
	{
		coins++;
		convert - nickel;
	}
	while( convert / penny)
	{
		coins++;
		convert - penny;
	}
	printf("%d", coins);
	system("PAUSE");
}
