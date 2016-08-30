import java.util.Scanner;

//Max C

//CIS254 Assignment 3

//This program will …
public class assignment3problem1 
{

	public static void total(double item1, double item2, double item3, double TaxRate)
	{
		double subtotal = item1 + item2 + item3;
		TaxRate = TaxRate / 100;
		double TaxPayable = TaxRate * subtotal;
		double total = TaxPayable + subtotal;
		System.out.println("The subtotal: $" + subtotal);
		System.out.println("The tax payable: $" + TaxPayable);
		System.out.println("The total: $" + total);		
	}
	public static void main(String[] args) 
	{
		double TaxRate;
		double item1;
		double item2;
		double item3;
		Scanner input = new Scanner(System.in);
		System.out.print("Taxrate?");
		TaxRate = input.nextDouble();
		System.out.print("Item 1 price?");
		item1 = input.nextDouble();
		System.out.print("Item 2 price?");
		item2 = input.nextDouble();
		System.out.print("Item 3 price?");
		item3 = input.nextDouble();
		total(item1,item2,item3,TaxRate);
		System.out.println("Made by Max C");

	}

}

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
