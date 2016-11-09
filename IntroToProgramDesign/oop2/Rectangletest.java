package oop2;

import java.util.Scanner;
import java.text.DecimalFormat;

public class Rectangletest {

	public static Scanner input = new Scanner(System.in);
	public static DecimalFormat dec = new DecimalFormat("#.00");
	public static int menu()
	{
		int num;
		//print menu choices
		System.out.println("1 - Price of flooring");
		System.out.println("2 - Price of fencing");
		System.out.println("3 - Quit");
		//prompt for choice
		System.out.print("Enter choice: ");
		num = input.nextInt();
		//get user input using Scanner
		while(num > 3 || num < 1)
		{
			System.out.println("Error, please enter valid choice");
			num = input.nextInt();
		}
		//loop to validate that it is between 1 and 3
		
		return num;
	}
	public static void main(String[] args) 
	{
		Rectangle rect1 = new Rectangle();
		/*
		rect1.setLength(5.5);
		rect1.setWidth(5.5);
		
		System.out.println("Length is " + rect1.getLength());
		System.out.println("Width is " + rect1.getWidth());
		
		System.out.println("Area is " + rect1.getArea());
		System.out.println("Perimeter is " + rect1.getPerim());		
		
		*/
		
		int choice;
		double length;
		double width;
		double price;
		double amount;
		choice = menu();
		while(choice != 3)
		{
			switch(choice)
			{
				case 1:

					System.out.print("Enter length, in feet: ");
					length = input.nextDouble();
					rect1.setLength(length);
					System.out.print("Enter width, in feet: ");
					width = input.nextDouble();
					rect1.setWidth(width);
					System.out.print("Enter cost of flooring per square foot: ");
					price = input.nextDouble();
					rect1.setPrice(price);
					
					System.out.println("\n" + "Area to cover is " + dec.format(rect1.getArea()) + " square feet");
					amount = rect1.getArea() * price; 
					System.out.println("Total price is $" + dec.format(amount) + "\n");
					break;
				case 2:
					System.out.print("Enter length, in feet: ");
					length = input.nextDouble();
					rect1.setLength(length);
					System.out.print("Enter width, in feet: ");
					width = input.nextDouble();
					rect1.setWidth(width);
					System.out.print("Enter cost of flooring per square foot: ");
					price = input.nextDouble();
					rect1.setPrice(price);
					
					System.out.println("\n" + "Area to fencing required is " + dec.format(rect1.getPerim()) + " feet");
					amount = rect1.getPerim() * price; 
					System.out.println("Total price is $" + dec.format(amount) + "\n");
					break;
			}
			choice = menu();
		}
		System.out.println("Goodbye!");
		
	}

}

/*
First assignment 1:

Length is 5.5
Width is 5.5
Area is 30.25
Perimeter is 22.0


Test case 1:
1 - Price of flooring
2 - Price of fencing
3 - Quit
Enter choice: 1
Enter length, in feet: 10.2
Enter width, in feet: 8.1
Enter cost of flooring per square foot: 4.99

Area to cover is 82.62 square feet
Total price is $412.27

1 - Price of flooring
2 - Price of fencing
3 - Quit
Enter choice: 2
Enter length, in feet: 39.9
Enter width, in feet: 22.3
Enter cost of flooring per square foot: 10.50

Area to fencing required is 124.40 feet
Total price is $1306.20

1 - Price of flooring
2 - Price of fencing
3 - Quit
Enter choice: 3
Goodbye!
*/
