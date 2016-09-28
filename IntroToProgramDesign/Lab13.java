import java.util.Scanner;

public class Lab13 
{

	public static void main(String[] args) 
	{
		double pass = 0;
		double fail = 0;
		int amount;
		double students = 0;
		boolean checker = true;
		double percent = 0.0;
		Scanner input = new Scanner(System.in);
		while(checker)
		{
			amount = 0;
			System.out.print("Enter result (1 = pass, 2 = fail) or 0 to quit: ");
			amount = input.nextInt();
			if(amount == 1)
			{
				pass++;
			}
			else
			{
				if(amount == 2)
				{
					fail++;
				}
				else
				{
					if(amount == 0)
					{
						checker = false;
						students--;
					}
					else
					{
						System.out.println("Please enter a valid answer");
						students--;
					}
				}
			}
			students++;
		}
		percent = pass / students;
		System.out.println("Total students: " + (int) students);
		System.out.println((percent * 100) + " percent passed");
		System.out.println("Made by Max C");
	}

}
