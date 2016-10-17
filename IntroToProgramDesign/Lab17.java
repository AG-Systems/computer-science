import java.text.DecimalFormat;
import java.util.Scanner;

public class Lab17
{
	public static double bmi(double weight, int feet, double inches)
	{
		DecimalFormat dec = new DecimalFormat("#.00");
		double totalheight = (feet * 12) + inches;
		double bmitotal = (weight * 703) / Math.pow(totalheight, 2);
    	return bmitotal;
	}
	public static void main(String[] args) 
	{
		DecimalFormat dec = new DecimalFormat("#.00");
		double weight;
		int feet;
		double inches;
		char answer;
		double printbmi;
		boolean checker = true;
		Scanner input = new Scanner(System.in);
		do
		{
			System.out.print("Enter weight: ");
			weight = input.nextDouble();
			System.out.print("Enter height (feet): ");
			feet = input.nextInt();
			System.out.print("Enter height (inches): ");
			inches = input.nextDouble();
			printbmi = bmi(weight,feet,inches);
			System.out.println("Your BMI is: " + dec.format(printbmi));
			System.out.print("Another? (y/n)");
			answer = input.next().charAt(0);
			if(answer == 'n')
			{
				checker = false;
			}
		}
		while(checker);

	}

}
