#include <iostream>
// input and out
double pemdas(double num1, double num2, double num3)
{
	double result = num1 * (num2 + num3);
	return result;
}
// made a function that accepts 3 number inputs and returns the result of the equation

int main()
{
	double num1;
	double num2;
	double num3;
	// variables
	std::cout << "Input 3 numbers" << std::endl;
	std::cin >> num1;
	std::cin >> num2;
	std::cin >> num3;
	// input
	std::cout << pemdas(num1,num2,num3) << std::endl;
	// Printed out the result of pemdas function
	std::cin.ignore().get();
	// Used to see the result
}
