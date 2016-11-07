package oop1;

import java.util.Scanner;

public class accounttest {

	public static void main(String[] args) 
	{
		// create an object
		String myname;
		double balance;
		Scanner input = new Scanner(System.in);
		account myaccount = new account();
		System.out.println("Enter name: ");
		myname = input.nextLine();
		myaccount.setName(myname);
		System.out.println("Enter balance: ");
		balance = input.nextDouble();
		myaccount.deposit(balance);
		System.out.println("My name is " + myaccount.getName());
		System.out.println("Balance is " + myaccount.getBalance());
		myaccount.deposit(100.0);
		System.out.println("Balance is " + myaccount.getBalance());
		myaccount.withdraw(100.0);
		System.out.println("Balance is " + myaccount.getBalance());
	}

}
