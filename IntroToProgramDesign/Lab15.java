import java.util.Scanner;

public class Lab15 
{

	public static void main(String[] args) 
	{
		int amount = 0;
		int days = 0;
		int totaldays = 0;
		int currentdays = 0;
		Scanner input = new Scanner(System.in);
		System.out.print("How many tellers? ");
		amount = input.nextInt();
		for(int z = 1; z < (amount+1); z++)
		{
			System.out.print("Teller "+ z + "sick days during year 1: ");
			days = input.nextInt();
			currentdays += days;
			days = 0;
			System.out.print("Teller "+ z + "sick days during year 2: ");
			days = input.nextInt();
			currentdays += days;
			days = 0;
			System.out.print("Teller "+ z + "sick days during year 3: ");
			days = input.nextInt();
			currentdays += days;
			days = 0;
			System.out.println("Total sick days for Teller "+ z + " is "+ currentdays);
			totaldays += currentdays;
			currentdays = 0;
		}
		System.out.print("The " + amount + " tellers were out sick for a total of "+ totaldays + " days during the lasts 3 years.");
		System.out.print("Made by Max C");
	}

}
