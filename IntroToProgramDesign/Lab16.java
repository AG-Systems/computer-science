package homework;

import java.security.SecureRandom;
import java.util.Scanner;

public class Lab16 
{
	public static void main(String[] args) 
	{
		SecureRandom rand = new SecureRandom();
		Scanner input = new Scanner(System.in);
		int num1 = 0;
		int num2 = 0;
		int user = 0;
		int correct = 0;
		int correctanswer = 0;
		int numofproblems = 3;
		System.out.println("Welcome to Math Tutor!");
		for(int z = 1; z <= numofproblems; z++)
		{
			System.out.println("Problem " + z + ":");
			num1 = 1 + rand.nextInt(12);
			num2 = 1 + rand.nextInt(12);
			correctanswer = num1 + num2;
			System.out.print(num1 + " + " + num2 + " = ");
			user = input.nextInt();
			if(user == correctanswer)
			{
				System.out.println("That's right");
				correct++;
			}
			else
			{
				System.out.println("The answer is " + correctanswer);
			}
		}
		System.out.print("Number correct is " + correct + " out of " + numofproblems);
	}

}
