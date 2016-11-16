package bmi;

import java.util.Scanner;

public class main {

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		Model profile = new Model();
		String answer_str = "";
		int answer_num = 0;
		do
		{
			System.out.print("Enter name or X to quit: ");
			answer_str = input.nextLine();
			if(!answer_str.equals("X"))
			{
				profile.setName(answer_str);
				System.out.print("Your age: ");
				answer_num = input.nextInt();
				profile.setAge(answer_num);
				System.out.print("Your weight: ");
				answer_num = input.nextInt();
				profile.setWeight(answer_num);
				System.out.print("Your height - feet: ");
				answer_num = input.nextInt();
				System.out.print("Your height - inches: ");
				profile.setHeight(answer_num, input.nextInt());
				
				System.out.println("\n" + "Health Profile for " + profile.getName());
				System.out.println("BMI: " + profile.getBmi());
				System.out.println("BMI Category: " + profile.getCategory());
				System.out.println("Max heart rate: " + profile.getMaxHR());
				input.nextLine(); 
			}
			
		}
		while(!answer_str.equals("X"));
		System.out.println("Goodbye!");
		
	}

}
