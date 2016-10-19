import java.security.SecureRandom;
import java.util.Scanner;

public class assignment11problem1 
{	
	public static void main(String[] args) 
	{
		SecureRandom rand = new SecureRandom();
		Scanner input = new Scanner(System.in);
		int num1 = 0;
		int num2 = 0;
		System.out.println("Welcome to the Math Tutor!");
		char choice;
		int answer;
		int correctanswer;
		int counter = 0;
		int totalquestions = 0;
		boolean running = true;
		while(running)
		{
			System.out.print("Select an operation (+ - / *): ");
			choice = input.next().charAt(0);
			num1 = 1 + rand.nextInt(12);
			num2 = 1 + rand.nextInt(12);
			switch (choice) 
			{
				case '+': 
						System.out.print(num1 + " + " + num2 + " = " );
						correctanswer = num1 + num2;
						answer = input.nextInt();
						if(answer == correctanswer)
						{
							System.out.println("That's right");
							counter++;
						}
						else
						{
							System.out.println("The answer is " + correctanswer);
						}
						totalquestions++;
						break;
				case '-':
						if(num2 > num1)
						{
					        num1 = num1 + num2;
					        num2 = num1 - num2;
					        num1 = num1 - num2;
						}
						System.out.print(num1 + " - " + num2 + " = " );
						correctanswer = num1 - num2;
						answer = input.nextInt();
						if(answer == correctanswer)
						{
							System.out.println("That's right");
							counter++;
						}
						else
						{
							System.out.println("The answer is " + correctanswer);
						}
						totalquestions++;
					break;
				case '/':
					num1 = num1 * num2;
					System.out.print(num1 + " / " + num2 + " = " );
					correctanswer = num1 / num2;
					answer = input.nextInt();
					if(answer == correctanswer)
					{
						System.out.println("That's right");
						counter++;
					}
					else
					{
						System.out.println("The answer is " + correctanswer);
					}
					totalquestions++;
					break;
				case '*':
					System.out.print(num1 + " * " + num2 + " = " );
					correctanswer = num1 * num2;
					answer = input.nextInt();
					if(answer == correctanswer)
					{
						System.out.println("That's right");
						counter++;
					}
					else
					{
						System.out.println("The answer is " + correctanswer);
					}
					totalquestions++;
					break;
		        	
			}
			System.out.print("Another problem?");
			choice = input.next().charAt(0);
			switch(choice)
			{
				case 'n':
				case 'N':
					running = false;
					break;
				case 'y':
				case 'Y':
					break;
			}
		}
		// 
		System.out.println("GAME STATISTICS");
		System.out.println("Number of problems: " + totalquestions);
		System.out.println("Number corect:      " +  counter);
		System.out.println("Your score is " + ((double) counter / totalquestions) * 100 + "%");
	}	
}
