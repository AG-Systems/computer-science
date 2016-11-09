package oop2;

import java.util.Scanner;

public class Rectangle 
{
	public static Scanner input = new Scanner(System.in);
	private double length;
	private double width;
	private double price;
	public void setLength(double l)
	{
		length = l;
	}
	public void setWidth(double w)
	{
		width = w;
	}
	public void setPrice(double p)
	{
		price = p;
	}
	public double getPrice()
	{
		return price;
	}
	public double getLength()
	{
		return length;
	}
	public double getWidth()
	{
		return width;
	}
	public double getArea()
	{
		return length * width;
	}
	public double getPerim()
	{
		double perim = (2 * length ) + (2 * width);
		return perim;
	}

	
}
