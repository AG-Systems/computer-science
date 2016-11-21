package oop3;

import java.util.Scanner;

public class Lab26 
{
	public static Scanner input = new Scanner(System.in);
	public static int inputData(Employee[] company)
	{
        int counter = 0;
		for(int z = 0; z < company.length; z++)
        {
    		String tempname;
    		double temphours;
    		double temprate;
    		String answer;
    		System.out.print("Enter employee's name: ");
    		tempname = input.nextLine();
    		System.out.print("Enter hours worked: ");
    		temphours = input.nextDouble();
    		System.out.print("Enter hourly rate: ");
    		temprate = input.nextDouble();
    		input.nextLine(); 
    		System.out.print("\n");
    		company[z] = new Employee();
    		company[z].setName(tempname);
    		company[z].setHours(temphours);
    		company[z].setRate(temprate);
    		counter++;
        	System.out.print("Another employee? (Y/N): ");
        	answer = input.nextLine();
        	if(answer.equals("n"))
        	{
        		break;
        	}
        }
    	return counter;
	}
	static void printPayroll(Employee[] list, int num)
	{
        System.out.println("PAYROLL REPORT");
        System.out.println("Employee Name  Hours    Rate       Pay");
        double totalpay = 0;
		for (int index = 0; index < num; index++) 
		{
			 System.out.printf("        %s    %.2f   %.2f   %.2f%n",list[index].getName(), list[index].getHours(), list[index].getRate(), list[index].getPay());
			 totalpay += list[index].getPay();
			 
		}
		System.out.print("Total Payroll  $" + totalpay);
	}

	public static void main(String[] args) 
	{
		final int size = 10;
		Employee[] company = new Employee[size];
		// We can use an arraylist if you want to expand it more in the future
		int results = inputData(company);
        printPayroll(company, results);

	}

}
