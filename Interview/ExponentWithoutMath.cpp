#include <iostream>

int power(int a, int b)
{
	int total = 1;
	for(int z = 0; z < b; z++)
	{
		total *= a;
	}
    return total;
}

int main()
{
    std::cout << power(5,3) << std::endl;
}
