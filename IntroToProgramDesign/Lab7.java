package test;
// Max C
// This program will calculate the productprice and apply the discount
// Lab 7
import java.util.Scanner;

public class retailstore 
{
	// Made a calculate function.
	public static void calculate(int productprice, int purchased)
	{
		double undicsountedtotal = productprice * purchased;
		double discount,discountamount,totalsale;
		// initialize the subtotal by multiplaying the product price and the amount purchased
		if(undicsountedtotal >= 500.0)
		{
			discount = 0.05;
		}
		// Boolean statement. If the subtotal is more then $500 then the discount is 5 percent
		else
		{
			discount = 0.03;
		}
		// Boolean statement. If the subtotal is less then $500 then the discount is 3 percent
		discountamount = undicsountedtotal * discount;
		// Get the dollar amount of the discount from the subtotal
		totalsale = undicsountedtotal - discountamount;
		// Get the total amount including the discount
		System.out.printf("The subtotal is: $%,.2f%n", undicsountedtotal);
		// Print out the subtotal
		System.out.printf("The Discount is: $%,.2f%n", discountamount);
		// Print out the discount in dollar
		System.out.printf("The total is: $%,.2f%n", totalsale);
		// Print out the total sale
		
	}
	public static void main(String[] args) 
	{
		int productprice;
		int purchased;
		// declared the variables
		Scanner input = new Scanner(System.in);
		// Set up input scanner
		System.out.print("Enter the product price: ");
		productprice = Integer.parseInt(input.nextLine());
		// Get input of productprice
		System.out.print("Enter quantity purchased: ");
		purchased = Integer.parseInt(input.nextLine());
		// Get input of quantity purchased
		calculate(productprice, purchased);
		// use the calculate function with the productprice and the amount of purchased
		System.out.print("Programmed by Max C");
	}

}
/* Test case 1:
 * Enter the product price: 20
Enter quantity purchased: 10
The subtotal is: $200.00
The Discount is: $6.00
The total is: $194.00
Programmed by Max C

Test case 2:
Enter the product price: 40
Enter quantity purchased: 20
The subtotal is: $800.00
The Discount is: $40.00
The total is: $760.00
Programmed by Max C

Test case 3:
Enter the product price: 100
Enter quantity purchased: 5
The subtotal is: $500.00
The Discount is: $25.00
The total is: $475.00
Programmed by Max C

 * */
