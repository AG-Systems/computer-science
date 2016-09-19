import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment6problem4 
{
	
	public static void main(String[] args) 
	{
		String name;
		int rate;
		char gender;
		int age;
		boolean checker = false;
		double total = 0;
		DecimalFormat dec = new DecimalFormat("#.00");
		Scanner input = new Scanner(System.in);
		System.out.println("Thank you for requesting an insurance quote");
		System.out.print("Enter customer name: ");
		name = input.nextLine();
		System.out.print("Enter standard rate: ");
		rate = input.nextInt();
		System.out.print("Enter gender (M or F): ");
		gender = input.next().charAt(0);
		switch (gender) 
		{
			case 'm': 
	        case 'M': 
	    		System.out.print("Enter age: ");
	    		checker = true;
	    		age = input.nextInt();
	    		if(age > 25)
	    		{
	    			total = rate;
	    		}
	    		else
	    		{
	    			total = 2 * rate;
	    		}
	    		break;
	        case 'f': 
	        case 'F': 
	        	total = (0.85 * rate);
	        	checker = true;
	        	break;
	        default: System.out.print("Invalid input");
		}
		if(checker)
		{
			System.out.println("Rate Quote for " + name);
			System.out.println("Your insurance coverage will cost $" + dec.format(total));
			System.out.println("Made by Max C");
		}
	}

}
/*
Test case 1
Thank you for requesting an insurance quote
Enter customer name: John Adams
Enter standard rate: 400
Enter gender (M or F): m
Enter age: 21
Rate Quote for John Adams
Your insurance coverage will cost $800.00
Made by Max C

Test case 2
Thank you for requesting an insurance quote
Enter customer name: auriga
Enter standard rate: 600
Enter gender (M or F): f
Rate Quote for auriga
Your insurance coverage will cost $510.00
Made by Max C

Test case 3
Thank you for requesting an insurance quote
Enter customer name: Max
Enter standard rate: 500
Enter gender (M or F): m
Enter age: 30
Rate Quote for Max
Your insurance coverage will cost $500.00
Made by Max C

Test case 4
Thank you for requesting an insurance quote
Enter customer name: tested
Enter standard rate: 500
Enter gender (M or F): z
Invalid input
*/
