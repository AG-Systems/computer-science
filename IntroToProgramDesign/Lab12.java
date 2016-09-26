package lab12;

import java.util.Scanner;

public class lab12 {

	public static void calculate(int number)
	{
		int counter = 1;
		int total = 0;
		while(counter < 13)
		{
			total = number * counter;
			System.out.println(number + "x" + counter + " = " + total);
			counter++;
		}
	}
	public static void main(String[] args) 
	{
		int number;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a number: ");
		number = input.nextInt();
		while(number < 1)
		{
			System.out.print("Must be greater than 1, re-enter: ");
			number = input.nextInt();
		}
		calculate(number);
		System.out.println("Made by Max C");
	}

}

/*
Test case 1
Enter a number: -3
Must be greater than 1, re-enter: 3
3x1 = 3
3x2 = 6
3x3 = 9
3x4 = 12
3x5 = 15
3x6 = 18
3x7 = 21
3x8 = 24
3x9 = 27
3x10 = 30
3x11 = 33
3x12 = 36

Test case 2
Enter a number: 9
9x1 = 9
9x2 = 18
9x3 = 27
9x4 = 36
9x5 = 45
9x6 = 54
9x7 = 63
9x8 = 72
9x9 = 81
9x10 = 90
9x11 = 99
9x12 = 108
*/
