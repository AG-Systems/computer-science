import java.util.Scanner;
import java.text.*;
//Max C

//CIS254 Assignment 5

public class assignment5problem1

{
	public static void orders(int amount)
	{
		double price;
		// declare the var price
		if(amount < 25)
		{
			price = .50;
		}
		else
		{
			price = .30;
		}
		// If there is more then 25 then the price is 30 cents. Vice versa
		DecimalFormat dec = new DecimalFormat("#.00");
		// Decimal format so there is a extra zero
		double total = price * amount;		
		// calculated the total
		System.out.println(amount + " diskettes at $"+ dec.format(price) + " each");
		// Output how many and how much per diskettes
		System.out.println("Your total is $" + dec.format(total));
		// Print total
	}
      
	public static void main(String[] args)

      {
		Scanner input = new Scanner(System.in);
		// scanner setup
		int amount = 0;
		// declare var
		System.out.print("Welcome to Diskettes R Us" + "\n" + "Order 25 or more and save!" + "\n");
		// Typical output
		System.out.print("How many diskettes do you want to buy?");
		// input
		amount = Integer.parseInt(input.nextLine());
		orders(amount);
		// use the orders func I made
		System.out.println("Made by Max C");
		
		
          	

      } //end main

} //end class
/*
Test case 1
Welcome to Diskettes R Us
Order 25 or more and save!
How many diskettes do you want to buy?10
10 diskettes at $.50 each
Your total is $5.00
Made by Max C
 

Test case 2
Welcome to Diskettes R Us
Order 25 or more and save!
How many diskettes do you want to buy?45
45 diskettes at $.30 each
Your total is $13.50
Made by Max C

Test case 3
Welcome to Diskettes R Us
Order 25 or more and save!
How many diskettes do you want to buy?25
25 diskettes at $.30 each
Your total is $7.50
Made by Max C
 
*/
