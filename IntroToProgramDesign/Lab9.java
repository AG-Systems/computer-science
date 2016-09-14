package homework;

import java.text.DecimalFormat;
import java.util.Scanner;

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
        
		}
	}
	public static void calculations(char choice, int months)
	{
		int price = 0;
		int total = 0;
		switch (choice) 
		{
			case 'a': 
	        case 'A': price = 40;
	        case 'c': 
	        case 'C': price = 15;
	        case 's': 
	        case 'S': price = 25;
		}
		DecimalFormat dec = new DecimalFormat("#.00");
		total = price * months;
		System.out.print(months + "months at $" + dec.format(price) + "per month");
		System.out.println("Your total is " + dec.format(total));
	}
	public static void main(String[] args) 
	{
		char choice;
		int months;
		Scanner input = new Scanner(System.in);
		System.out.println("Health Club Membership Menu");
		System.out.println("A: Adult");
    	System.out.println("C:  Child");
    	System.out.println("S:  Senior");
    	System.out.print("Enter your choice: ");
    	choice = input.next().charAt(0);
    	if(checker(choice))
    	{
    		System.out.print("How many months? ");
    		months = Integer.parseInt(input.nextLine());
    	}
    	else
    	{
    		System.out.println("Error. Invalid choice");
    	}
	}

}
