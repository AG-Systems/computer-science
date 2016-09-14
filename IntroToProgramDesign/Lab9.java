
import java.text.DecimalFormat;
import java.util.Scanner;

// Max C
// Lab 9
// This program will get input of what kind of ticket and calculate the total
public class lab9 {
	public static boolean checker(char choice)
	{
		switch (choice) 
		{
			case 'a': 
	        case 'A': return true;
	        case 'c': 
	        case 'C': return true;
	        case 's': 
	        case 'S': return true;
	        default: return false;
	        // if its not A,a,c,C,s,C then it will return false
		}// end of switch
	}// end of function checker
	public static void calculations(char choice, int months)
	{
		int price = 0;
		int total = 0;
		// declared variables for this function
		switch (choice) 
		{
			case 'a': 
	        case 'A': 
	        	price = 40;
	        	break;
	        case 'c': 
	        case 'C': 
	        	price = 15;
	        	break;
	        case 's': 
	        case 'S': 
	        	price = 25;
	        	break;
	        // Assigns the price according to the switch case. If a,A price then will be 40 Vice versa
		} // end of switch
		DecimalFormat dec = new DecimalFormat("#.00");
		// decimal format to get the money format
		total = price * months;
		// Calculate the total price
		System.out.println(months + " months at $" + dec.format(price) + " per month");
		System.out.println("Your total is " + dec.format(total));
		System.out.print("Made by Max C");
		// outputs with the decimal format in place
	}
	public static void main(String[] args) 
	{
		char choice;
		int months;
		// declared the variables
		Scanner input = new Scanner(System.in);
		// set up the input
		System.out.println("Health Club Membership Menu");
		System.out.println("A:  Adult");
    	System.out.println("C:  Child");
    	System.out.println("S:  Senior");
    	// List out all of the choices
    	System.out.print("Enter your choice: ");
    	choice = input.next().charAt(0);
    	// char input. 
    	if(checker(choice))
    	{
    		System.out.print("How many months? ");
    		months = input.nextInt();
    		calculations(choice,months);
    	}
    	// If the checker function returns true then it will ask for the months and caluclate the total
    	else
    	{
    		System.out.println("Error. Invalid choice");
    		// The choice was invalid.
    	} // end of the else statement
	}// end of the main function

}

/*
Test case 1:

Health Club Membership Menu
A:  Adult
C:  Child
S:  Senior
Enter your choice: a
How many months? 3
3 months at $40.00 per month
Your total is 120.00
Made by Max C

Test case 2:

Health Club Membership Menu
A:  Adult
C:  Child
S:  Senior
Enter your choice: c
How many months? 2
2 months at $15.00 per month
Your total is 30.00
Made by Max C

Test case 3:

Health Club Membership Menu
A:  Adult
C:  Child
S:  Senior
Enter your choice: s
How many months? 6
6 months at $25.00 per month
Your total is 150.00
Made by Max C

Test case 4:
Health Club Membership Menu
A:  Adult
C:  Child
S:  Senior
Enter your choice: 5
Error. Invalid choice
*/
