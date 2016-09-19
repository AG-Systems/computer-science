package homework;

import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment6problem2 
{
	public static void function(int salary, int years, int monthsales)
	{
		int bonus;
		double bonussales = 0;
		double percent;
		double total;
		double servicesales;
		if(years <= 5)
		{
			bonus = 10;
		}
		else
		{
			bonus = 20;
		}
		servicesales = bonus * years;
		if(monthsales > 5000 && monthsales < 10000)
		{
			bonussales = 0.03 * monthsales;
			
		}
		else if (monthsales > 10000)
		{
			bonussales = 0.06 * monthsales;
		}
		DecimalFormat dec = new DecimalFormat("#.00");
		total = servicesales + bonussales + salary;
		System.out.println("Base pay         $" +  dec.format(salary));
		System.out.println("Service bonus    $" +  dec.format(servicesales));
		System.out.println("Sales bonus      $" +  dec.format(bonussales));
		System.out.println("Total pay        $" +  dec.format(total));
		System.out.println("Made my Max C");
	}
	public static void main(String[] args) 
	{
		int salary;
		int years;
		int monthsales;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter monthly base salary: ");
		salary = Integer.parseInt(input.nextLine());
		System.out.print("Enter years of service: ");
		years = Integer.parseInt(input.nextLine());
		System.out.print("Enter monthly sales: ");
		monthsales = Integer.parseInt(input.nextLine()); 
		System.out.print("\n");
		function(salary, years, monthsales);
		
	}

}
/*
Test case 1
Enter monthly base salary: 700
Enter years of service: 2
Enter monthly sales: 6000

Base pay         $700.00
Service bonus    $20.00
Sales bonus      $180.00
Total pay        $900.00
Made my Max C

Test case 2
Enter monthly base salary: 800
Enter years of service: 7
Enter monthly sales: 10000

Base pay         $800.00
Service bonus    $140.00
Sales bonus      $.00
Total pay        $940.00
Made my Max C

Test case 3
Enter monthly base salary: 500
Enter years of service: 3
Enter monthly sales: 3000

Base pay         $500.00
Service bonus    $30.00
Sales bonus      $.00
Total pay        $530.00
Made my Max C
*/
