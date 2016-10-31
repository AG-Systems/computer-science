import java.security.SecureRandom;
import java.util.Arrays;

public class assignment12problem3 
{
	public static void initArray(int[] array)
	{
		int size = array.length;
		SecureRandom rand = new SecureRandom();
		for(int z = 0; z < size; z++)
		{
			array[z] = 1 + rand.nextInt(999);
		}
	}
	public static void printArray(int[] array, int columns)
	{
		int counter = 0;
		for(int z = 0; z < array.length; z++)
		{
			if(counter % columns ==  0)
			{
				System.out.print("\n");
			}
			System.out.print(array[z] + " ");
			counter++;
		}
	}
	public static int findMax(int[] array)
	{		
	    int max = 0;
		for(int i = 0; i < array.length; i++)
	    {
	        if(array[i] > max)
	        {
	        	max= array[i];
	        }
	    }
		return max;
	}
	public static int findMin(int[] array)
	{
		int min = 0;
	    for (int i = 1;  i < array.length; i++)
	    {
	        if ( array[i] < min )
	        {
	            min = array[i];
	        }
	    }
	    return min;
	}
	public static float findAvg(int[] array)
	{
		int total = 0;
		float average;
		for(int z = 0; z < array.length; z++)
		{
			total += array[z];
		}
		average = total / array.length;
		return average;
			
	}
	public static void reverseArray(int[] array1, int[] array2)
	{
		
		for(int i = 0; i < array1.length / 2; i++)
		{
		    int temp = array1[i];
		    array1[i] = array1[array1.length - i - 1];
		    array1[array1.length - i - 1] = temp;
		}	
		for(int z = 0; z < array1.length; z++)
		{
			array2[z] = array1[z];
		}
		for(int i = 0; i < array1.length / 2; i++)
		{
		    int temp = array1[i];
		    array1[i] = array1[array1.length - i - 1];
		    array1[array1.length - i - 1] = temp;
		}	
	}
	public static void main(String[] args) 
	{
		final int maxnums = 30; 
		int[] array1;
		int[] array2;
		array1 = new int[maxnums];
		array2 = new int[maxnums];	 
		initArray(array1);
		System.out.println("The numbers are: ");
		printArray(array1, 5);
		System.out.println("\n");
		System.out.println("The largest number is " + findMax(array1));
		System.out.println("The smallest number is " + findMin(array1));
		System.out.println("The average is " + findAvg(array1) + "\n");
		reverseArray(array1,array2);
		System.out.println("The reversed numbers are: ");
		printArray(array2, 5);		
		
	}

}
