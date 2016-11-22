package oop;

public class InvoiceTest 
{
	public static void print(Invoice[] company, int counter, String str, String str2, double price, int amount)
	{
		company[counter].setPartNumber(str);
		company[counter].setDesc(str2);    		
		company[counter].setPrice(price);
		company[counter].setAmount(amount);
		System.out.println(company[counter].getItemTotal());		
	}
	public static void main(String[] args) 
	{
		final int size = 4;
		Invoice[] company = new Invoice[size];
        int counter = 0;
		for(int z = 0; z < 2; z++)
        {
    		company[z] = new Invoice();
        }
		print(company, 0, "AB22", "USB drive", 9.99, 2);
		print(company, 1, "Z0Z0", "Laptop", 1999.99, 5);
		company[2] = new Invoice("1337", "Desktop", 3999.99, 1);
		company[3] = new Invoice("00", "Graphics card", 600, 10); 
		for(int z = 2; z < 4; z++)
        {
    		System.out.print(company[z].getItemTotal());
        }
	}
}
