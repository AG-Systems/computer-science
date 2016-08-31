import java.util.Scanner;

//Max C

//CIS254 Assignment 3

//This program will calculate the BMI
public class assignment3problem3 
{
	/*
	interface Valuable {
	    // use richest built-in numeric type
	    double value();
	    int extend();
	    Valuable value(double v);
	    Valuable extend(int x);
	}
	
	public static <T extends Valuable> T bmi(T weight, T feet, T inches)
	{
	    if(weight instanceof Integer)
	    {
	    	T bmi = null;
	    	int totalheight = (feet.extend() * 12) + inches.extend();
	    	System.out.println("Your BMI is: " + bmi.value(weight.extend() * 703 / (totalheight) * (totalheight)));
	    	return (T) bmi.value(weight.extend() * 703 / (totalheight) * (totalheight));
	    }
	}
	*/
	// Tried using Java Generics for the first time. Did not work.
	public static void bmi(int weight, int feet, int inches)
	{
    	double totalheight = (feet * 12) + inches;
    	// Convert everything into inches
    	System.out.println("Your BMI is: " + (weight * 703) / ((totalheight) * (totalheight)));	
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

Enter weight: 180
Enter height (feet): 5
Enter height (inches): 8
Your BMI is: 27.3659169550173


Test case 2:
Enter weight: 200
Enter height (feet): 6
Enter height (inches): 0
Your BMI is: 27.121913580246915

Test case 3: 
Enter weight: 140
Enter height (feet): 5
Enter height (inches): 4
Your BMI is: 24.0283203125

*/
