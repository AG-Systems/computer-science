#include <iostream>
// input and out
int multi(int num1, int num2)
{
	return num1 * num2;
}
// made a function that accepts 2 number inputs and returns the product

int main()
{
	int num1;
	int num2;
	// variables
	std::cout << "Input 2 numbers" << std::endl;
	std::cin >> num1;
	std::cin >> num2;
	// input
	std::cout << multi(num1,num2) << std::endl;
	// Printed out the result of multi function
	std::cin.ignore().get();
	// Used to see the result
}
