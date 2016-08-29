// Max

//CIS254 Lab 4

//This program will calculate total amount of money earned and the total amount of tickets.

import java.util.Scanner;

public class lab3
{
  public static int totaltickets(int adult_tickets, int child_tickets)
  {
	  int totaltickets = adult_tickets + child_tickets;
	  System.out.println("The total amount of tickets are: " + totaltickets);
	  return totaltickets;
  }
  public static double ticketsales(int adult_tickets, int child_tickets)
  {
	  int childsales = child_tickets * 5;
	  int adultsales = adult_tickets * 9;
	  double ticketsales = adultsales + childsales;
	  System.out.println("The total price is: $" + ticketsales);
	  return ticketsales;
  }
  public static void main(String[] args)
  {
	  int adult_tickets;
	  int child_tickets;
	  Scanner input = new Scanner(System.in);
	  System.out.print("How many adult tickets?");
	  adult_tickets = input.nextInt();
	  System.out.print("How many child tickets?");
	  child_tickets = input.nextInt();	
	  ticketsales(adult_tickets,child_tickets);
	  totaltickets(adult_tickets,child_tickets);
	  System.out.println("Made By Max");	  
  }
}
