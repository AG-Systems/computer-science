import java.text.DecimalFormat;
import java.util.Scanner;

public class assignment6problem5 
{

	public static void main(String[] args) 
	{
		char code;
		int price;
		double percent = 0.0;
		double total;
		boolean checker = true;
		Scanner input = new Scanner(System.in);
		DecimalFormat dec = new DecimalFormat("#.00");
		while(true)
		{
			System.out.print("Enter price of product: ");
			price = input.nextInt();
			if(price > 0)
			{
				break;
			}
			else
			{
				System.out.println("Invalid, re-enter");
			}
		}
		System.out.print("Enter code: ");
		code = input.next().charAt(0);
		switch (code) 
		{
			case 'S': 
	        case 's': 
	        	percent = 0.05;
	        	break;
	        case 'M': 
	        case 'm': 
	        	percent = 0.07;
	        	break;
	        case 'L': 
	        case 'l': 
	        	percent = 0.10;
	        	break;
	        default: System.out.println("Invalid");
	        checker = false;
	        break;
		}
		if(checker)
		{
			total = (percent * price);
			System.out.println(dec.format((percent * 100)) + "% commission rate");
			System.out.println("Commission: " + dec.format(total));
			System.out.println("Made by Max C");
		}
	}

}
/*
Test case 1

Enter price of product: -5500
Invalid, re-enter
Enter price of product: 5500
Enter code: L
10.0% commission rate
Commission: 550.00

Test case 2
Enter price of product: 2850
Enter code: m
7.00% commission rate
Commission: 199.50

Test case 3
Enter price of product: 995
Enter code: S
5.00% commission rate
Commission: 49.75

Test case 4
Enter price of product: 5
Enter code: z
Invalid

*/
