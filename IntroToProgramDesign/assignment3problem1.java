import java.util.Scanner;

//Max C

//CIS254 Assignment 3

//This program will calculate the total of items with tax
public class assignment3problem1 
{

	// method that cauclates the total of everything
	public static void total(double item1, double item2, double item3, double TaxRate)
	{
		// calculate the subtotal
		double subtotal = item1 + item2 + item3;
		TaxRate = TaxRate / 100;
		// convert the taxrate into a percent
		double TaxPayable = TaxRate * subtotal;
		// Get the tax amount
		double total = TaxPayable + subtotal;
		// Get the total amount
		System.out.println("The subtotal: $" + subtotal);
		System.out.println("The tax payable: $" + TaxPayable);
		System.out.println("The total: $" + total);		
		// print statements ^
	} // closing bracket for total func
	public static void main(String[] args) 
	{
		double TaxRate;
		double item1;
		double item2;
		double item3;
		// declaring var's
		Scanner input = new Scanner(System.in);
		// setting up the scanner input
		System.out.print("Taxrate?");
		TaxRate = input.nextDouble();
		System.out.print("Item 1 price?");
		item1 = input.nextDouble();
		System.out.print("Item 2 price?");
		item2 = input.nextDouble();
		System.out.print("Item 3 price?");
		item3 = input.nextDouble();
		// got all input
		total(item1,item2,item3,TaxRate);
		// Used the total func
		System.out.println("Made by Max C");

	} // closing bracket for main

} // closing bracket for the public class 

/* Testing/Runtime output

Test case 1
Taxrate?7
Item 1 price?22
Item 2 price?10
Item 3 price?15
The subtotal: $47.0
The tax payable: $3.2900000000000005
The total: $50.29
Made by Max C

 

Test case 2
Taxrate?5
Item 1 price?10
Item 2 price?20
Item 3 price?30
The subtotal: $60.0
The tax payable: $3.0
The total: $63.0
Made by Max C

Test case 3
Taxrate?8
Item 1 price?19.50
Item 2 price?22.95
Item 3 price?32.75
The subtotal: $75.2
The tax payable: $6.016
The total: $81.21600000000001
Made by Max C
Test case 3

 
*/
