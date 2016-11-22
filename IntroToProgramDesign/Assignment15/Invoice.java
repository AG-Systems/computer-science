package oop;

public class Invoice {
	String partnum;
	String partdesc;
	double itemprice;
	int amount;
	
	public Invoice()
	{
		partnum = "none";
		partdesc = "none";
		itemprice = 0;
		amount = 0;
	}
	public Invoice(String num, String desc, double item, int amounted)
	{
		partnum = num;
		partdesc = desc;
		itemprice = item;
		amount = amounted;
	}
	public void setPartNumber(String str)
	{
		partnum = str;
	}
	public void setDesc(String str)
	{
		partdesc = str;
	}
	public void setAmount(int amounted)
	{
		if(amounted < 0)
		{
			amount = 0;
		}
		else
		{
			amount = amounted;
		}
	}
	public void setPrice(double price)
	{
		if(price < 0)
		{
			itemprice = 0;
		}
		else
		{
			itemprice = price;
		}
	} 
	public double getItemTotal()
	{
		System.out.println("Order Sumary: ");
		System.out.println("Quantity " + amount + " ordered of " + partnum + " - " + partdesc);
		return(itemprice * amount);
	}
}
