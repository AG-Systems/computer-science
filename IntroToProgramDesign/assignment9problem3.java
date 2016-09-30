import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment9problem3 
{
	public static void sum(int num)
	{
		int total = 0;
		int counter = 0;
		while(counter <= num)
		{
			total += counter;
			counter++;
		}
		System.out.println("The sum of 1 to " + num + " is " + total);
	}
	public static void main(String[] args) 
	{
		int num = 0;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a positive integer: ");
		num = input.nextInt();
		while(num < 0)
		{
			System.out.print("Must greater than 0, re-enter: ");
			num = input.nextInt();
		}
		sum(num);
	}

}
