import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment10problem1 
{

	public static void main(String[] args) 
	{
		String name;
		int average;
		double amount;
		int total;
		int cost;
		int counter = 1;
		int totalpeople = 0;
		int totalmoney = 0;
		boolean question = false;
		char answer;
		DecimalFormat dec = new DecimalFormat("#.00");
		Scanner input = new Scanner(System.in);
		do 
		{
			System.out.print("Enter company name: ");
			name = input.nextLine();
			if(counter > 1)
			{
				input.nextLine();
			}
			System.out.print("How many registrants? ");
			amount = input.nextInt();
			if(amount <= 3 && amount >= 1)
			{
				cost = 150;
			}
			else
			{
				if(amount >= 4 && amount <= 9)
				{
					cost = 100;
				}
				else
				{
					cost = 90;
				}
			}
			counter++;
			total = (int) (cost * amount);
			totalpeople += amount;
			totalmoney += total;
			System.out.println("\n"+"INVOICE");
			System.out.println("Company: " + name);
			System.out.println("Cost per registrant: " + cost);
			System.out.println("Total for " + amount + " people: " + total);
			System.out.print("\n" + "Another registration? (y/n) ");
			answer = input.next().charAt(0);
			switch (answer) 
			{
				case 'y': 
		        case 'Y': 
		        	question = true;
		    		break;
		        case 'n': 
		        case 'N':
		        	question = false;
		        	break;
		        default: System.out.print("Invalid input");
			}
		}
		while(question);
		average = totalmoney / totalpeople;
		System.out.println("REGISTRATION SUMMARY");
		System.out.println("Number of companies registered: " + counter);
		System.out.println("Total number of people registered: " + totalpeople);
		System.out.println("Total charges: " + dec.format(totalmoney));
		System.out.print("Average charge per person: $" + dec.format(average));
	}

}
