package bmi;

import java.text.DecimalFormat;

public class Model {
	private String name;
	private int age;
	private int weight;
	private int height;
	public void setName(String input)
	{
		name = input;
	}
	public void setAge(int input)
	{
		age = input;
	}
	public void setWeight(int input)
	{
		weight = input;
	}
	public void setHeight(int feet, int inches)
	{
		height = (feet * 12) + inches;
	}
	public String getName()
	{
		return name;
	}
	public int getAge()
	{
		return age;
	}
	public int getWeight()
	{
		return weight;
	}
	public double getBmi()
	{
		DecimalFormat dec = new DecimalFormat("#.0");
		double bmi = (double)(weight * 703) / ((height) * (height));
		String bmireturn = dec.format(bmi);
		return Double.parseDouble(bmireturn);
	}
	public String getCategory()
	{
		double results = getBmi();
    	if(results < 18.5)
    	{
    		// System.out.println("Underweight");
    		return "Underweight";
    	}
    	else if(results >= 18.5 && results <= 24.9)
    	{
    		// System.out.println("Normal");
    		return "Normal";
    	}
    	else if(results >= 25 && results <= 29.9)
    	{
    		// System.out.println("Overweight");
    		return "Overweight";
    	}
    	else
    	{
    		return "Obese";
    	}
	}
	
	public int getMaxHR()
	{
		
		int heartrate = 220 - age;
		return heartrate;
	}
	

}
