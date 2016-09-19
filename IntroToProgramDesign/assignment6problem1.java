package homework;
import java.text.DecimalFormat;
import java.util.Scanner;

//Max C

//CIS254 Assignment 6

//This program will calculate the BMI
public class assignment6problem1
{
	public static void bmi(int weight, int feet, int inches)
	{
		DecimalFormat dec = new DecimalFormat("#.00");
		double totalheight = (feet * 12) + inches;
		double bmitotal = (weight * 703) / ((totalheight) * (totalheight));
    	// Convert everything into inches
    	System.out.println("Your BMI is: " + dec.format(bmitotal));	
    	if(bmitotal < 18.5)
    	{
    		System.out.println("Underweight");
    	}
    	else if(bmitotal >= 18.5 && bmitotal <= 24.9)
    	{
    		System.out.println("Normal");
    	}
    	else
    	{
    		System.out.println("Overweight");
    	}
    	//Print out the bmi formula with the right var's
	}// closing function bracket
	public static void main(String[] args) 
	{
		int weight;
		int feet;
		int inches;
		// declaring var
		Scanner input = new Scanner(System.in);
		System.out.print("Enter weight: ");
		weight = input.nextInt();
		System.out.print("Enter height (feet): ");
		feet = input.nextInt();
		System.out.print("Enter height (inches): ");
		inches = input.nextInt();
		// getting input
		bmi(weight,feet,inches);
		// function
		System.out.print("Made by Max C");		

	}

}
/*
Test case 1:
Enter weight: 145
Enter height (feet): 5
Enter height (inches): 5
Your BMI is: 24.13
Normal
Made by Max C

Test case 2:
Enter weight: 200
Enter height (feet): 6
Enter height (inches): 1
Your BMI is: 26.38
Overweight
Made by Max C

Test case 3:
Enter weight: 90
Enter height (feet): 5
Enter height (inches): 1
Your BMI is: 17.00
Underweight
Made by Max C

*/
