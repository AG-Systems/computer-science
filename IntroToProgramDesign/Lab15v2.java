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
			for(int x = 1; x <= 3; x++)
			{
				System.out.print("Teller "+ z + " sick days during year "+ x + ": ");
				days = input.nextInt();
				currentdays += days;
				days = 0;
			}
			System.out.println("Total sick days for Teller "+ z + " is "+ currentdays + "\n");
			totaldays += currentdays;
			currentdays = 0;
		}
		System.out.println("The " + amount + " tellers were out sick for a total of "+ totaldays + " days during the lasts 3 years.");
		System.out.println("Made by Max C");
	}

}
