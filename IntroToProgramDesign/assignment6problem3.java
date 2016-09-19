import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment6problem3 
{
	public static void algorithm(double weight)
	{
		double cost;
		double total;
		if(weight < 2.5)
		{
			cost = 3.50;
		}
		else
		{
			if(weight <= 2.5 && weight >= 5)
			{
				cost = 2.85;
			}
			else
			{
				cost = 2.45;
			}
		}
		total = cost * weight;
		DecimalFormat dec = new DecimalFormat("#.00");
		System.out.print("\n");
		System.out.println("For a package weighing " + dec.format(weight) + " kg");
		System.out.println("Cost per kg is $" + cost);
		System.out.println("Total shipping cost: $" + dec.format(total));
		System.out.println("Made by Max C");
	}
	public static void main(String[] args) 
	{
		double weight;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the weight of the package in kg: ");
		weight = Double.parseDouble(input.nextLine());
		if(weight < 0 )
		{
			System.out.print("invalid input");
		}
		else
		{
			algorithm(weight);
		}

	}

}
/*
Test case 1
Enter the weight of the package in kg: 2

For a package weighing 2.00 kg
Cost per kg is $3.5
Total shipping cost: $7.00
Made by Max C

Test case 2
Enter the weight of the package in kg: 5

For a package weighing 5.00 kg
Cost per kg is $2.45
Total shipping cost: $12.25
Made by Max C

Test case 3
Enter the weight of the package in kg: 6

For a package weighing 6.00 kg
Cost per kg is $2.45
Total shipping cost: $14.70
Made by Max C


Test case 4
Enter the weight of the package in kg: -4
invalid input
 */
