import java.util.Scanner;

public class assignment11problem3 
{
	public static int inputScore()
	{
		Scanner input = new Scanner(System.in);
		int testscore;
		System.out.print("Enter test score: ");
		testscore = input.nextInt();
		while(testscore < 0 || testscore > 100)
		{
			System.out.print("Invalid, please re-enter: ");	
			testscore = input.nextInt();
		}
		return testscore;
	}
	public static double calcAverage(int test1, int test2 ,int test3)
	{
		double average = (test1 + test2 + test3) / 3;
		return average;
	}
	public static char calcGrade(double average)
	{
		if(average < 60)
		{
			return 'F';
		}
		else
		{
			if(average < 70)
			{
				return 'D';
			}
			else
			{
				if(average < 80)
				{
					return 'C';
				}
				else
				{
					if(average < 90)
					{
						return 'B';
					}
					else
					{
						return 'A';
					}
				}
			}
		}
	}
	public static void main(String[] args) 
	{
		boolean running = true;
		Scanner input = new Scanner(System.in);
		String answer;
		do
		{
			int test1 = inputScore();
			int test2 = inputScore();		
			int test3 = inputScore();
			System.out.println("Your average is " + calcAverage(test1, test2 ,test3));
			System.out.println("Your grade is " + calcGrade(calcAverage(test1, test2 ,test3)));
			System.out.print("Another? ");
			answer = input.next();
			
		}
		while(answer.equalsIgnoreCase("y"));
	}

}
