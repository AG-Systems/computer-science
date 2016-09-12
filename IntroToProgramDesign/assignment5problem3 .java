import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment5problem3 
{
	public static void algorithm(String name, double hours, double rate)
	{	
		int overtime = 0;
		double regularpay;
		double overtimepay;
		double grosspay;
		double deduction;
		double netpay;
		// declared all of the vars
		if(hours > 40)
		{
			overtime = (int) (hours - 40.0);
			// did a typecast of double minus int 
		}
		// if you worked more then 40 hours a week then you get the net overtime hours
		regularpay = (40 * rate);
		overtimepay = (overtime * (rate * 1.5));
		grosspay = regularpay + overtimepay;
		deduction = .15 * grosspay;
		netpay = grosspay - deduction;
		// all of the caluclations. Regular pay is hours time rate. Overtime is overtime hours * (1.5 of the rate). 
		// deducition is the 15 percent of the totalpay. Netpay is the totalpay minus the deduction. 
		DecimalFormat dec = new DecimalFormat("#.00");
		//Decimalformat to insert that extra zero in
		System.out.println("\n" + "Payroll Report for " + name);
		System.out.println("==============");
		System.out.println("Regular Pay: " + dec.format(regularpay));
		System.out.println("Overtime Pay: " + dec.format(overtimepay));
		System.out.println("Gross Pay: " + dec.format(grosspay));
		System.out.println("Deductions: " + dec.format(deduction));
		System.out.println("Net pay: " + dec.format(netpay));
		// Outputs. Dec.format is the decimal formatting
		
	}
	public static void main(String[] args) 
	{
		String name;
		double hours;
		double rate;
		// declared the vars
		Scanner input = new Scanner(System.in);
		// setup scaner
		System.out.print("Enter the employee's name: ");
		name = input.nextLine();
		// Had to do .nextline because its a string so no need for parsing
		System.out.print("Enter the number of hours worked this week: ");
		hours = Double.parseDouble(input.nextLine());
		System.out.print("Enter the hourly rate: ");
		rate = Double.parseDouble(input.nextLine());
		// got all input
		algorithm(name,hours,rate);
		// used a method I have made
		System.out.println("Made by Max C");

	}

}
/*
 Test case 1:
 Enter the employee's name: John Smith
Enter the number of hours worked this week: 45
Enter the hourly rate: 15.50

Payroll Report for John Smith
==============
Regular Pay: 620.00
Overtime Pay: 116.25
Gross Pay: 736.25
Deductions: 110.44
Net pay: 625.81
Made by Max C


Test case 2:
Enter the employee's name: Max
Enter the number of hours worked this week: 25.5
Enter the hourly rate: 10.25

Payroll Report for Max
==============
Regular Pay: 410.00
Overtime Pay: .00
Gross Pay: 410.00
Deductions: 61.50
Net pay: 348.50
Made by Max C


Test case 3:
Enter the employee's name: maxadorable
Enter the number of hours worked this week: 40
Enter the hourly rate: 20.75

Payroll Report for maxadorable
==============
Regular Pay: 830.00
Overtime Pay: .00
Gross Pay: 830.00
Deductions: 124.50
Net pay: 705.50
Made by Max C

 
 
 
 */
