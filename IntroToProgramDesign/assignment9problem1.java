import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment9problem1 
{

	public static void sale(int price)
	{
		int day = 1;
		double newprice = price;
		DecimalFormat dec = new DecimalFormat("#.00");
		System.out.println("Original Price $" + dec.format(price));
		System.out.println("Five day sale pricing:");
		System.out.println("Day      Price");
		while(day < 6)
		{
			newprice = newprice - (newprice * .10);
			System.out.println(day + "         " + dec.format(newprice));
			day++;
		}
	}
	public static void main(String[] args) 
	{
		int price = 0;
		Scanner input = new Scanner(System.in);
		while(price < 1)
		{
			System.out.print("Enter product price:");
			price = input.nextInt();
		}
		sale(price);
	}

}
