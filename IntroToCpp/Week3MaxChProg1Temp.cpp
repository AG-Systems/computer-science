#include <iostream>
// input and out lib
int main()
{
	int answer = 0;
	float temp = 0;
	// variables
	std::cout << "Press 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius" << std::endl;
	std::cin >> answer;
	std::cout << "Input the temp you want to convert" << std::endl;
	std::cin >> temp;
	// input
	if (answer == 1) 
	{
		 temp = temp * 1.8 + 32;
		 // T(°F) = T(°C) × 1.8 + 32
		 // Formula for C to F
	}
	else
	{
		temp = (temp - 32) * 5.0 / 9;
		// T(°C) = (T(°F) - 32) × 5/9
		// Formula for F to C
	}
	std::cout << "The new temperature is: " << temp << std::endl;
	// Output of the new temperature
	std::cin.ignore().get();
	// So the program does not end

}
