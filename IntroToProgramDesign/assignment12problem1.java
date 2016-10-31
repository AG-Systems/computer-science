import java.util.Scanner;

public class assignment12problem1 
{

	public static void main(String[] args) 
	{
		int[] ratings;
		int answer = 0;
		Scanner input = new Scanner(System.in);
		ratings = new int[5];
		
		while(answer != -1)
		{
			System.out.print("Enter rating (0 to 4)or -1 to quit: ");
			answer = input.nextInt();
			while(answer > 4 || answer < -1)
			{
				System.out.print("Invalid, must be 0 to 4.  Re-enter: ");
				answer = input.nextInt();
			}
			if(answer <= 4 && answer >= 0)
			{
				ratings[answer]++;
			}
		}
		System.out.println("Ratings   Summary " + "\n" + "Rating    Count");
		for(int z = 0; z < ratings.length; z++)
		{
			System.out.println(z + "           " + ratings[z]);
		}
	}

}
