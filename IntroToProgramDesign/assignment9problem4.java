import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment9problem4 
{

	public static void main(String[] args) 
	{
		int male = 0;
		int female = 0;
		double gpa = 0;
		double malegpa = 0;
		double femalegpa = 0;
		int selector = 0;
		char gender = 0;
		boolean running = true;
		Scanner input = new Scanner(System.in);
		while(running)
		{
			selector = 0;
			System.out.print("Enter gender or x to quit: ");
			gender = input.next().charAt(0);
			switch (gender) 
			{
				case 'm': 
		        case 'M': 
		        	male++;
		        	selector = 1;
		        	break;
		        case 'f':
		        case 'F':
		        	female++;
		        	selector = 2;
		        	break;
		        case 'x':
		        case 'X':
		        	running = false;
		        	break;
		        default: System.out.print("Invalid input");
			}
			if(running)
			{
				System.out.print("Enter gpa: ");
				if(selector == 1)
				{
					gpa = input.nextDouble();
					malegpa += gpa;
					
				}
				if(selector == 2)
				{
					gpa = input.nextDouble();
					femalegpa += gpa;
				}
			}
			else
			{
				System.out.println("Male GPA average: " + (malegpa / male));
				System.out.println("Female GPA average: " + (femalegpa / female));
			}
		}

	}

}
