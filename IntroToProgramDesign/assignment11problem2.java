import java.security.SecureRandom;
import java.util.Scanner;

public class assignment11problem2 
{

	public static int sum(int num)
	{
		int total = 0;
		int counter = 1;
		while(counter <= num)
		{
			total += counter;
			counter++;
		}
		return total;
	}
	public static int prod(int num)
	{
		int total = 1;
		int counter = 1;
		while(counter <= num)
		{
			total = total * counter;
			counter++;
		}
		return total;
	}
	public static void main(String[] args) 
	{
		int num = 0;
		int id = 3;
		char answer;
		boolean running = true;
		boolean valid = true;
		Scanner input = new Scanner(System.in);
		
		while(valid)
		{
			running = true;
			while(running)
			{
				System.out.print("Enter S for sum, P for product, or X to exit: ");
				answer = input.next().charAt(0);
					switch(answer)
					{
						case 's':
						case 'S':
							id = 1;
							running = false;
							break;
						case 'p':
						case 'P':
							running = false;
							id = 2;
							break;
						case 'x':
						case 'X':
							valid = false;
							running = false;
							break;
						default: System.out.println("Not a valid choice");
						break;
					}
				}
				if(valid)
				{
					System.out.print("Enter a positive integer: ");
					num = input.nextInt();
					while(num < 0)
					{
						System.out.print("Must greater than 0, re-enter: ");
						num = input.nextInt();
					}
					if(id == 1)
					{
						System.out.println("The sum of 1 to " + num + " is " + sum(num));
					}
					else
					{
						System.out.println("The product of 1 to " + num + " is " + prod(num));				
					}
				}
		}
	}
}
