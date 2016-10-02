import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment9problem5 
{

	public static void main(String[] args) 
	{
		String name;
		int amount = 0;
		int counter = 1;
		double hours = 0.0;
		double rate = 0.0;
		double total = 0.0;
		double pay = 0.0;
		double overtime = 0.0;
		DecimalFormat dec = new DecimalFormat("#.00");
		Scanner input = new Scanner(System.in);
		System.out.print("How many employees? ");
		amount = input.nextInt();
		while(amount < 1)
		{
			System.out.print("Must be 1 or more, re-enter: ");	
			amount = input.nextInt();
		}
		while(counter < (amount + 1))
		{
			System.out.print("Employee " + counter + " name: ");
			name = input.nextLine();
			input.nextLine();
			System.out.print("Employee " + counter + " hours: ");
			hours = input.nextDouble();
			System.out.print("Employee " + counter + " rate: ");
			rate = input.nextDouble();
			if(hours > 40)
			{
				overtime = (int) (hours - 40.0); 
				hours = hours - overtime;
			}
			double regularpay = (hours * rate);
			double overtimepay = (overtime * (rate * 1.5));
			pay = regularpay + overtimepay;
			System.out.println("Gross pay for "+ name +  "is " + pay + "\n");
			total += pay;
			counter++;
		}
		System.out.println("Total payroll is " + dec.format(total));
		System.out.println("Made by Max C");
	}

}
