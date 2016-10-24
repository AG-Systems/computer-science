import java.security.SecureRandom;
import java.util.Scanner;

// Max C
// Lab 19
// This program will gen random numbers to array and display the even ones
public class Lab19 
{
	public static void even(int nums[])
	{
		int sum = 0;
		for(int x = 0; x < nums.length; x++)
		{
			if(nums[x] % 2 == 0)
			{
				System.out.println(nums[x]);
				sum++;
			}
		}
		System.out.print("Amount of even numbers: " + sum);
	}
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		SecureRandom rand = new SecureRandom();
		int []nums = new int [5];
		nums[0] = 5;
		for(int z = 0; z < nums.length; z++)
		{
			nums[z] = rand.nextInt(101);
		}
		even(nums);

	}

}
