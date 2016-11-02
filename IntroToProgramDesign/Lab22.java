package arrays;

import java.util.Scanner;

public class lab22
{
	static Scanner input = new Scanner(System.in);
	public static float calcAvg(double[] array)
	{
		int total = 0;
		float average;
		for(int z = 0; z < array.length; z++)
		{
			total += array[z];
		}
		average = total / array.length;
		return average;
			
	}
	public static char calcGrade(double average)
	{
		if(average < 60)
		{
			return 'F';
		}
		else
		{
			if(average < 70)
			{
				return 'D';
			}
			else
			{
				if(average < 80)
				{
					return 'C';
				}
				else
				{
					if(average < 90)
					{
						return 'B';
					}
					else
					{
						return 'A';
					}
				}
			}
		}
	}
	public static void getValues(double[] array, int amount)
	{
		for(int z = 0; z < amount; z++)
		{
			System.out.print("Enter test " + (z+1) + ": ");
			array[z] = input.nextInt();
		}
	}
	public static void main(String[] args) 
	{
		boolean running = true;
		int amount = 0;
		System.out.print("How many tests? ");
		amount = input.nextInt();
		double[] array1;
		array1 = new double[amount];
		getValues(array1, amount);
		System.out.println("Your average is " + calcAvg(array1));
		System.out.println("Your grade is " + calcGrade(calcAvg(array1)));
	}

}
