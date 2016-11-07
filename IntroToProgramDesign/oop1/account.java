package oop1;

public class account 
{
	private String name;
	private double balance;
	
	//need public methods to access private data
	
	public void setName(String aname)
	{
		name = aname;
	}
	public String getName()
	{
		return name;
	}
	public void deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
	}
	public double getBalance()
	{
		return balance;
	}
	public void withdraw(double amount)
	{
		if(amount > 0 && amount <= balance)
		{
			balance = balance - amount;
		}
		else
		{
			System.out.println("Error");
		}
	}
}
