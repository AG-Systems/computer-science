import java.util.Scanner;

public class assignment10problem2 
{

	public static void main(String[] args) 
	{
		int students;
		int tests;
		int testscore;
		double average;
		int testscorestudent = 0;
		double testscoreclass = 0;
		String name;
		Scanner input = new Scanner(System.in);
		System.out.print("How many students? ");
		students = input.nextInt();
		System.out.print("How many tests? ");
		tests = input.nextInt();
		for(int z = 1; z <= students; z++)
		{
			System.out.print("Student " + z + " name: ");
			name = input.next();
			for(int x = 1; x <= tests; x++)
			{
				System.out.print("Test " + x + ": ");
				testscore = input.nextInt();
				testscorestudent += testscore;
			}
			average = testscorestudent / tests;
			System.out.print(name + ", your average is " + average + "\n" + "\n");
			testscoreclass += average;
			average = 0;
			testscorestudent = 0;
		}
		testscoreclass = testscoreclass / 3;
		System.out.println("The class average is " + testscoreclass);
		System.out.print("Made by Max C");
	}

}
