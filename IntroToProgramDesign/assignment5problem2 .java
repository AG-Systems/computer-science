import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment5problem2 
{

	public static void calculations(int length, int width, int drawers)
	{
		int area = length * width;
		double totalprice;
		double salestax;
		double tax;
		// declared all of the vars
		if(area > 750)
		{
			totalprice = (200.00 + (30.00 * drawers) + 50);	
			// if the surface area is more then 750 then you add $50 ^
		}
		else
		{
			totalprice = (200.00 + (30.00 * drawers));
			// surface area is not more then 750
		}
		DecimalFormat dec = new DecimalFormat("#.00");
		// decimal format to add the extra zero
		salestax = 0.8 / 10;
		tax = salestax * totalprice;
		// Calculated 8 percent of the total amount
		System.out.println("Price Quote: ");
		System.out.println("Desk price" + "     " + dec.format(totalprice));
		System.out.println("Tax" + "            " + dec.format(tax));
		System.out.println("Total due" + "      " + dec.format(tax + totalprice));
		// outputs ^
	}
	public static void main(String[] args) 
	{
		int length;
		int width;
		int drawers;
		// declared the vars
		Scanner input = new Scanner(System.in);
		// input
		System.out.print("What is the length of the desk?");
		length = Integer.parseInt(input.nextLine());
		System.out.print("What is the width of the desk?");
		width = Integer.parseInt(input.nextLine());
		System.out.print("How many drawers?");
		drawers = Integer.parseInt(input.nextLine());
		// getting the input of length, width, and drawers
		calculations(length,width,drawers);
		// used the calculations function I made
		System.out.println("Made by Max C");

	}

}
/*
Test case 1:
What is the length of the desk?30
What is the width of the desk?20
How many drawers?2
Price Quote: 
Desk price     260.00
Tax            20.80
Total due      280.80
Made by Max C

Test case 2: 
What is the length of the desk?40
What is the width of the desk?25
How many drawers?4
Price Quote: 
Desk price     370.00
Tax            29.60
Total due      399.60
Made by Max C

Test case 3:
What is the length of the desk?30
What is the width of the desk?25
How many drawers?5
Price Quote: 
Desk price     350.00
Tax            28.00
Total due      378.00
Made by Max C


*/
