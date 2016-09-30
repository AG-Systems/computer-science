import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment9problem2 
{
	public static void math(double base, int exponent)
	{
		DecimalFormat dec = new DecimalFormat("###.#");
		double total = 1;
		int counter = 0;
		while(counter < exponent)
		{
			total *= base;
			counter++;
		}
		System.out.println( dec.format(base) + " raised to the power of " + exponent + " = " + dec.format(total));
	}
	public static void main(String[] args) 
	{
		double base;
		int exponent;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter base: ");
		base = input.nextDouble();
		System.out.print("Enter exponent: ");
		exponent = input.nextInt();
		while(exponent < 2)
		{
			System.out.print("Must be 2 or greater, re-enter: ");
			exponent = input.nextInt();			
		}
		math(base, exponent);
	}

}
