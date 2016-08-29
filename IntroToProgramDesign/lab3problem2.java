// Max C

//CIS254 Lab 4

//This program will calculate the total pay of workers

import java.util.Scanner;

public class Lab3Problem2
{
  
  public static double totalpay(int regHoursWorked, int OvertimeHoursWorked,double hourWage)
  {
	  double totalpay = (regHoursWorked * hourWage) + (OvertimeHoursWorked *(hourWage*1.5));
	  System.out.println("Total pay is : $" + totalpay);	
	  return totalpay;
  }
  public static void main(String[] args)
  {
	  int regHoursWorked;
	  int OvertimeHoursWorked;
	  double hourWage;
	  Scanner input = new Scanner(System.in);
	  System.out.print("How many regular hours worked?");
	  regHoursWorked = input.nextInt();
	  System.out.print("How many overtime hours worked?");
	  OvertimeHoursWorked = input.nextInt();
	  System.out.print("What is your hourly wage?");
	  hourWage = input.nextDouble();
	  totalpay(regHoursWorked, OvertimeHoursWorked, hourWage);
	  System.out.println("Made By Max C");	  
  }
}

/* Test case 1:

How many regular hours worked?35
How many overtime hours worked?0
What is your hourly wage?10
Total pay is : $350.0
Made By Max C

Test case 2:

How many regular hours worked?40
How many overtime hours worked?20
What is your hourly wage?15.50
Total pay is : $1085.0
Made By Max C

*/
 
