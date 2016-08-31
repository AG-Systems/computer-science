//Max C

//CIS254 Assignment 3

//This program will calculate the cost of material for fencing a lawn
import java.util.Scanner;
public class assignment3problem2 
{
	// learning classes. Made a method though a class to solve the materials needed and how much.
	public assignment3problem2(int length, int width, double price)
	{
		int materialneeded = length * width;
		// took the area to find out how much material I need
		double totalprice = materialneeded * price;
		// total price is material neeeded times the price
		System.out.println("Amount of fencing needed is " + materialneeded ); 
		System.out.println("Cost of fencing material is " + totalprice ); 
		// print statements :)
	} // method closing bracket 
	public static void main(String[] args) 
	{
		int length;
		int width;
		double price;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter length: ");
		length = input.nextInt();
		System.out.print("Enter width: ");
		width = input.nextInt();
		System.out.print("Enter price of fencing: ");
		price = input.nextDouble();
		// inputs
		assignment3problem2 solution = new assignment3problem2(length,width,price); 
		// made a solution object and used the function to solve the problem
		System.out.println("Made by Max C");
	} // closing main bracket

} // closing main public class
/* Testing/Runtime output

Test case 1
Enter length: 10
Enter width: 20
Enter price of fencing: 15
Amount of fencing needed is 200
Cost of fencing material is 3000.0

Test case 2
Enter length: 15
Enter width: 30
Enter price of fencing: 5
Amount of fencing needed is 450
Cost of fencing material is 2250.0

Test case 3
Enter length: 30
Enter width: 20
Enter price of fencing: 20
Amount of fencing needed is 600
Cost of fencing material is 12000.0

 
*/
