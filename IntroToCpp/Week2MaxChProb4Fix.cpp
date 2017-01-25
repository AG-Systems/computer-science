#include <iostream> // you forgot the < 
using namespace std; // its better not to use namespace std

int main ( ) { // start program // you dont have capitals in the variable type. Also you forgot the comment. Needs slash
// Declare and Initialize Variables // You forgot the exta slash
int height = 0; // data type must not have any capitals
int feet = 0; // data type must not have any capitals and you forogt semicolin
int inches = 0; // data type must not have any capitals
// Prompt for height
cout << "Enter your height in inches: "; // std::cout << has that not >>.
cin >> height; // Case sensetive. Make sure variables are spelled correctly
// Calculate Height in feet and inches
feet = height / 12; // The order goes varname = value. Not the other way around
inches = height % 12;
// Print out height in feet and inches // you forgot the extra slash
cout << "You are " << feet << " feet and " << inches << "inches" ; // case sensitive. Var must match 100% with what you declared. Also you messed up << 3 times
system("pause"); // Mac user comment out this line 
return 0;

} // end of program
