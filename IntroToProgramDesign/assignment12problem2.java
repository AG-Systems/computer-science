import java.util.Scanner;
import java.text.DecimalFormat;

public class assignment12problem2 
{

	public static void main(String[] args) 
	{
		String[] candidate;
		int[] votes;
		float [] percent;
		int capacity = 5;
		int totalvotes = 0;
	    int max = 0;
	    String winner = "";
		candidate = new String[capacity];
		votes = new int[capacity];
		percent = new float[capacity];
		Scanner input = new Scanner(System.in);
		DecimalFormat dec = new DecimalFormat("#.00");
		for(int z = 0; z < capacity; z++)
		{
			System.out.print("Enter candidate name:");
			candidate[z] = input.next();
			System.out.print("Enter votes received:");
			votes[z] = input.nextInt();
			totalvotes += votes[z];
		}
		System.out.println("Candidate        Votes Received       % of Total");
		for(int z = 0; z < capacity; z++)
		{
			percent[z] = ((float) votes[z] / (float) totalvotes) * 100;
			System.out.println(candidate[z] + "         " + votes[z] + "                  " + dec.format(percent[z]));
		}
	    for(int i = 0; i < capacity; i++)
	    {
	        if(votes[i] > max)
	        {
		        max= votes[i];
		        winner = candidate[i];
	        }
	    }
		System.out.println("Total votes             " + totalvotes);
		System.out.print("The winner of the election is " + winner);
	}

}
/*

Enter candidate name:Johnson
Enter votes received:5000
Enter candidate name:Miller
Enter votes received:4000
Enter candidate name:Duffy
Enter votes received:6000
Enter candidate name:Robinson
Enter votes received:2500
Enter candidate name:Ashton
Enter votes received:1800
Candidate        Votes Received       % of Total
Johnson         5000                  25.91
Miller         4000                  20.73
Duffy         6000                  31.09
Robinson         2500                  12.95
Ashton         1800                  9.33
Total votes             19300
The winner of the election is Duffy

Enter candidate name:Max
Enter votes received:50000
Enter candidate name:Maxadorable
Enter votes received:10000
Enter candidate name:wow
Enter votes received:100
Enter candidate name:whats
Enter votes received:800
Enter candidate name:ew
Enter votes received:1452
Candidate        Votes Received       % of Total
Max         50000                  80.19
Maxadorable         10000                  16.04
wow         100                  .16
whats         800                  1.28
ew         1452                  2.33
Total votes             62352
The winner of the election is Max
*/
