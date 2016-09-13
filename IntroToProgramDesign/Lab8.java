import java.text.DecimalFormat;
import java.util.Scanner;

public class lab8 
{
	public static void bonus(int years, int salary)
	{
		double percent;
		double total;
		// declared the variables
		if(years > 15)
		{
			percent = 0.15;
		}
		// if you worked more then 15 years then you get 15 percent of your salary
		else
		{
			if(years < 5)
			{
				percent = 0.04;
			}
			// if you worked for less then 5 years then you get 4 percent of your salary
			else
			{
				percent = 0.07;
			}
			// 5-15 years, you get 7 percent of your salary
		}
		total = (percent * salary);
		// Your bonus
		DecimalFormat dec = new DecimalFormat("#.00");
		// Decimal format to have the extra zero
		DecimalFormat perc = new DecimalFormat("###.#");
		// Decimal format to remove the extra zero
		percent = percent * 100;
		// Convert it to X%
		System.out.println("Your " + perc.format(percent) + "% bonus is $" + dec.format(total));
		// output with the decimal formatting
	}
	public static void main(String[] args) 
	{
		
		int years;
		int salary;
		// declared the variables
		Scanner input = new Scanner(System.in);
		// setup input
		System.out.print("Employee salary?");
		salary = Integer.parseInt(input.nextLine());
		// input for salary
		System.out.print("Years worked?");
		years = Integer.parseInt(input.nextLine());
		// input for years worked
		bonus(years,salary);
		// Used my bonus method
		System.out.println("Made by Max Chakhmatov");
		

	}

}

/*
Test case 1:
Employee salary?40000
Years worked?2
Your 4% bonus is $1600.00
Made by Max Chakhmatov

Test case 2:
Employee salary?50000
Years worked?5
Your 7% bonus is $3500.00
Made by Max Chakhmatov

Test case 3:
Employee salary?60000
Years worked?20
Your 15% bonus is $9000.00
Made by Max Chakhmatov

Test case 4:
Employee salary?45000
Years worked?15
Your 7% bonus is $3150.00
Made by Max Chakhmatov
*/
