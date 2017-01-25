#include <iostream>
// input and out lib
int main()
{
	int a[5];
	// declared array with 5 capacity
	std::cout << "Please input 5 numbers: " << std::endl;
	// input
	for(int z = 0; z < 5; z++)
	{
		int temp = 0;
		std::cin >> temp;
		a[z] = temp;
		// loop 5 times and ask for input. Uses the z counter to know where to store the answer
	}
	int sum = 0;
	// sum variable
	for(int x = 0; x < 5; x++)
	{
		std::cout << a[x] << std::endl;
		sum += a[x];
		// add each element to the sum var
	}
	std::cout << sum << std::endl;
	// print statements
	std::cout << "The average is: " << double (sum / 5) << std::endl;
	// Use typecast to temp make a double variable
	std::cin.ignore().get();
	// So you can see the results
}
