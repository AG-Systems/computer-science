package oop3;

public class Employee 
{
	private String name;
	private double hours;
	private double rate;
	
	public Employee()
	{
		name = "none";
		hours = 0.0;
		rate = 0.0;
	}
	
	public void setName(String ename)
	{
		name = ename;
	}
	public void setHours(double time)
	{
		hours = time;
	}
	public void setRate(double payrate)
	{
		rate = payrate;
	}
	public String getName()
	{
		return name;
	}
	public double getHours()
	{
		return hours;
	}
	public double getRate()
	{
		return rate;
	}
	public double getPay()
	{
		
		if(hours <= 40)
		{
			return rate * hours;
		}
		else
		{
			double regularpay = 40 * rate;
			double overpay = (hours - 40) * (rate * 1.5);
			overpay += regularpay;
			return overpay;
		}
		
	}
}
