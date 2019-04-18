#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include <cmath> 
#include "fraction.h"

namespace cs_fraction {

   void Fraction::simplify()
   {
      if(numerator > denominator)
      {
         return simplify_helper(abs(denominator));
      } else {
         return simplify_helper(abs(numerator));
      }

   }

   void Fraction::simplify_helper(int base)
   {
      if(base <= 1)
      {
         if(denominator < 0)
         {
            denominator = denominator * -1;
            if(numerator > 0)
            {
               numerator = numerator * -1;
            }

         }
         return;
      } else if(numerator % base != 0 || denominator % base != 0)
      {  
         return simplify_helper(base -= 1);
      } else {
         numerator = numerator / base;
         denominator = denominator / base;
         return simplify_helper(base);
      }
   }

   // Constructor of the Fraction class. Gets called after the object gets created.
   Fraction::Fraction(int num, int den)
   {
      // assert(den != 0); // Makes sure the fraction is not undefined 
      
      numerator = num; 
      denominator = den; 

      simplify();
   }





   // Returns the numerator of the object if user prefers to use functions over private data members.
   int Fraction::get_numerator()
   {
      return numerator;
   }





   // Returns the denominator of the object if user prefers to use functions over private data members.
   int Fraction::get_denominator()
   {
      return denominator;
   }



   // Sets the numerator of the object
   // Parameter num: The value that you pass through to set the numerator of the object.
   void Fraction::set_numerator(int num)
   {
      numerator = num; // This sets the numerator to the parameter input
      simplify();
   }




   // Sets the denominator of the object
   // Parameter den: The value that you pass through to set the denominator of the object
   void Fraction::set_denominator(int den)
   {
      denominator = den; // This sets the denominator to the parameter input
      simplify();
   }



   // Computes the addition of 2 different fractions and returns a fraction object.
   // Universal function
   // Works with whole numbers as well.
   // All inputs must be integers and returns an object. 

   // Parameter left_num: First object's numerator that gets passed through
   // Parameter left_den: First object's denominator
   // Paremter right_num: Second object's numerator
   // Parameter: right_den: Second object's denonimator
   Fraction add_fractions(int left_num, int left_den, int right_num, int right_den)
   {

      // Applies to the changes to the numerator of both fractions because...
      // when adding or substracting fractions, the bases must be the same.
      left_num = left_num * right_den;
      right_num = right_num * left_den;

      // Creates a new fraction object with the same base and the sum of the...
      // ...numerators.
      Fraction temp((left_num + right_num), (left_den * right_den)); 

      
      // returns the fraction object.
      return temp;
   }





   // Computes the difference of 2 different fractions and returns a fraction object.
   // Universal function
   // Works with whole numbers as well.
   // All inputs must be integers and returns an object. 

   // Parameter left_num: First object's numerator that gets passed through
   // Parameter left_den: First object's denominator
   // Paremter right_num: Second object's numerator
   // Parameter: right_den: Second object's denonimator
   Fraction minus_fractions(int left_num, int left_den, int right_num, int right_den)
   {
      
      
      // Applies to the changes to the numerator of both fractions because...
      // when adding or substracting fractions, the bases must be the same.
      left_num = left_num * right_den;
      right_num = right_num * left_den;

      
      // Creates a new fraction object with the same base and the difference of the...
      // ...numerators.
      Fraction temp((left_num - right_num), (left_den * right_den));

      
      // returns the fraction object.
      return temp;
   }





   // Computes the product of 2 different fractions and returns a fraction object.
   // Universal function
   // Works with whole numbers as well.
   // All inputs must be integers and returns an object. 

   // Parameter left_num: First object's numerator that gets passed through
   // Parameter left_den: First object's denominator
   // Paremter right_num: Second object's numerator
   // Parameter: right_den: Second object's denonimator
   Fraction multiply_fractions(int left_num, int left_den, int right_num, int right_den)
   {

      // Multiplies the numerators togeather and the denoninators.
      Fraction temp( (left_num * right_num), (right_den * left_den) );

      // Returns the new fraction object     
      return temp;
   }




   // Computes the division of 2 different fractions and returns a fraction object.
   // Universal function
   // Works with whole numbers as well.
   // All inputs must be integers and returns an object. 

   // Parameter left_num: First object's numerator that gets passed through
   // Parameter left_den: First object's denominator
   // Paremter right_num: Second object's numerator
   // Parameter: right_den: Second object's denonimator
   Fraction divide_fractions(int left_num, int left_den, int right_num, int right_den)
   {
      // Passes the values to the multiply fractions but flips the 2nd term...
      // ...the numerator becomes the denominator and the denominator becomes...
      // ...numerator.
      return multiply_fractions(left_num, left_den, right_den, right_num);
   }



   // Enables the user to place the object in front of a ostream function and print it cleanly
   // Input must be an object

   // Parameter right: The object that is the right side of the << 
   ostream& operator<<(ostream& out, const Fraction& right)
   {   
      // prints the numerator then the slash then the denominator of the fraction object
      if(right.denominator == 1)
      {
         out << right.numerator;
      }
      else if(right.numerator == 0)
      {
         out << "0";
      }
      else if(right.numerator > right.denominator)
      {
         int primary_num = right.numerator / right.denominator;
         int remainder = right.numerator % right.denominator;

         if(remainder != 0)
         {
            out << primary_num << "+" << remainder << "/" << right.denominator;
         } else {
            out << primary_num;
         }

      } else {
         out << right.numerator << "/" << right.denominator; 
      }
      return out;

   }


   istream& operator>>(istream& in, Fraction& right)
   {
      while(!in.eof())
      {
        if (in.peek() == 43){ // + symbol
            // 
            cout << "it wokred!" << endl;
        } else if (in.peek() == 47){ /*   / symbol  */
            // 
        } else {
            // 
        }
        in.ignore();  
      }
      return in;
   }


   // Less then operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator<(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;
      
      return left_side < right_side;
   }




   // Less then operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator<(int left, const Fraction& right)
   {  
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side < right_side; 
   }




   // Less then operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer 
   bool operator<(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side < right_side; 
   }






   // Less then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator<=(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;

      return left_side <= right_side;
   }



   // Less then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator<=(int left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side <= right_side; 
   }





   // Less then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer 
   bool operator<=(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side <= right_side; 
   }



   // Greator then operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator>(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;

      return left_side > right_side;
   }





   // Greator than to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator>(int left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side > right_side; 
   }




   // Greator then operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer 
   bool operator>(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side > right_side; 
   }




   // Greator then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator>=(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;

      return left_side >= right_side;
   }





   // Greator then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator>=(int left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side >= right_side; 
   }





   // Greator then or equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer 
   bool operator>=(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side >= right_side; 
   }





   // Equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator==(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;

      return left_side == right_side;
   }




   // Equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator==(int left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side == right_side; 
   }




   // Equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer
   bool operator==(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side == right_side; 
   }






   // Does not equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator fraction object
   // Parameter right: Right hand side of the operator fraction object
   bool operator!=(const Fraction& left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int right_side = left.denominator * right.numerator;
      int left_side = left.numerator * right.denominator;

      return left_side != right_side;
   }





   // Does not equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is a integer 
   // Parameter right: Right hand side of the operator fraction object
   bool operator!=(int left, const Fraction& right)
   {
      // Does cross multiplication to compare values
      int left_side = left * right.denominator;
      int right_side = 1 * right.numerator;

      return left_side != right_side; 
   }





   // Does not equal to operator that computes each "side" of the fraction...
   // ...to determine which side is bigger that is fully accurate

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer
   bool operator!=(const Fraction& left, int right)
   {
      // Does cross multiplication to compare values
      int left_side = left.numerator * 1;
      int right_side = left.denominator * right;

      return left_side != right_side; 
   }





   // Operation function that adds fraction object to another fraction object

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is fraction object
   Fraction operator+(const Fraction& left, 
                        const Fraction& right)
   {
      // Returns the new object that is added togeather
      return add_fractions(left.numerator, left.denominator, right.numerator, right.denominator); 
   }



   // Operation function that adds integer to another fraction object

   // Parameter left: Left hand side of the operator that is a integer
   // Parameter right: Right hand side of the operator that is fraction object
   Fraction operator+(int left, 
                        const Fraction& right)
   {
      // Returns the new object that is added togeather
      return add_fractions(left, 1, right.numerator, right.denominator); 
   }



   // Operation function that adds fraction object to integer

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer
   Fraction operator+(const Fraction& left, 
                        int right)
   {
      // Returns the new object that is added togeather
      return add_fractions(left.numerator, left.denominator, right, 1);
   }




   // Operation function that subtracts fraction object to another fraction object

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator-(const Fraction& left, 
                        const Fraction& right)
   {
      // Returns the new object that is subtracted togeather
      return minus_fractions(left.numerator, left.denominator, right.numerator, right.denominator); 
   }



   // Function operator that subtracts a number from a fraction object

   // Parameter left: Left hand side of the operator that is a integer
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator-(int left, 
                        const Fraction& right)
   {
      // Returns the new object that is subtracted togeather
      return minus_fractions(left, 1, right.numerator, right.denominator); 
   }


   // Function operator that subtracts a fraction object with a integer

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a integer
   Fraction operator-(const Fraction& left, 
                        int right)
   {
      // Returns the new object that is subtracted togeather
      return minus_fractions(left.numerator, left.denominator, right, 1); 
   }




   // Function operator that multiplies a fraction object with another fraction

   // Parameter left: Left hand side of the operator that is fraction object
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator*(const Fraction& left, 
                        const Fraction& right)
   {
      // Returns the new object that is multiplied togeather
      return multiply_fractions(left.numerator, left.denominator, right.numerator, right.denominator);
   }



   // Function operator that multiplies a fraction object with integer

   // Parameter left: Left hand side of the operator that is integer
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator*(int left, 
                        const Fraction& right) 
   {
      // Returns the new object that is multiplied togeather
      return multiply_fractions(left, 1, right.numerator, right.denominator);
   }



   // Function operator that multiplies a fraction object with integer

   // Parameter left: Left hand side of the operator that is a fraction object
   // Parameter right: Right hand side of the operator that is a integer
   Fraction operator*(const Fraction& left, 
                        int right) 
   {
      // Returns the new object that is multiplied togeather
      return multiply_fractions(left.numerator, left.denominator, right, 1);
   }



   // Function operator that divides a fraction object with another fraction

   // Parameter left: Left hand side of the operator that is a fraction object
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator/(const Fraction& left, 
                        const Fraction& right) 
   {
      // Returns the new object that is divided togeather
      return divide_fractions(left.numerator, left.denominator, right.numerator, right.denominator);
   }




   // Function operator that divides a integer with fraction

   // Parameter left: Left hand side of the operator that is a integer
   // Parameter right: Right hand side of the operator that is a fraction object
   Fraction operator/(int left, 
                        const Fraction& right)
   {
      // Returns the new object that is divided togeather
      return divide_fractions(left, 1, right.numerator, right.denominator);
   }




   // Function operator that divides a integer with fraction

   // Parameter left: Left hand side of the operator that is a fraction object
   // Parameter right: Right hand side of the operator that is a integer
   Fraction operator/(const Fraction& left, 
                        int right) 
   {
      // Returns the new object that is divided togeather
      return divide_fractions(left.numerator, left.denominator, right, 1);
   }






   // Function operator that pre-increment a fraction object
   Fraction Fraction::operator++()
   {
      simplify();
      // Adds the current fraction object context by one
      *this = add_fractions(numerator, denominator, 1, 1); 
      return *this;
   }


   // Function operator that post-increment a fraction object
   Fraction Fraction::operator++(int)
   {
      simplify();
      // Adds the current fraction object context by one
      Fraction temp(numerator, denominator);
      *this = add_fractions(numerator, denominator, 1, 1);
      return temp;
   }



   // Function operator that pre-deincrement a fraction object
   Fraction Fraction::operator--()
   {
      simplify();
      // Minues the current fraction object context by one
      *this = minus_fractions(numerator, denominator, 1, 1);
      return *this;
   }



   // Function operator that post-deincrement a fraction object
   Fraction Fraction::operator--(int)
   {
      // Minues the current fraction object context by one
      simplify();
      Fraction temp(numerator, denominator);
      *this = minus_fractions(numerator, denominator, 1, 1);
      return temp;
   }




   // Function operator that adds a fraction object to another fraction...
   // ...object inline

   // Parameter right: Fraction object that is the right side of the += operator
   Fraction Fraction::operator+=(const Fraction& right)
   {
      simplify();
      // Adds the current fraction object context by fraction object
      *this = add_fractions(numerator, denominator, right.numerator, right.denominator);

      

      return *this;
   }



   // Function operator that adds a integer to another fraction...
   // ...object inline

   // Parameter right: Integer that is the right side of the += operator
   Fraction Fraction::operator+=(int val)
   {
      simplify();
      // Adds the current fraction object context by variable val
      return add_fractions(numerator, denominator, val, 1);
   }


   // Function operator that minuses a fraction object to another fraction...
   // ...object inline

   // Parameter right: Fraction object that is the right side of the -= operator
   Fraction Fraction::operator-=(const Fraction& right)
   {
      simplify();
      // Minues the current fraction object context by Fraction object
      *this = minus_fractions(numerator, denominator, right.numerator, right.denominator);

      return *this;
   }



   // Function operator that minus a integer to another fraction...
   // ...object inline

   // Parameter right: Integer that is the right side of the -= operator
   Fraction Fraction::operator-=(int val)
   {
      simplify();
      // Minues the current fraction object context by variable val
      return minus_fractions(numerator, denominator, val, 1);
   }



   // Function operator that mulitplies a fraction to another fraction...
   // ...object inline

   // Parameter right: Fraction object that is the right side of the *= operator
   Fraction Fraction::operator*=(const Fraction& right)
   {
      simplify();
      // Multiplies the current fraction object context by fraction object
      *this = multiply_fractions(numerator, denominator, right.numerator, right.denominator);


      return *this;
   }



   // Function operator that mulitplies a intreger to another fraction...
   // ...object inline

   // Parameter right: Integer object that is the right side of the *= operator
   Fraction Fraction::operator*=(int val)
   {
      simplify();
      // Multiplies the current fraction object context by varaible val
      return multiply_fractions(numerator, denominator, val, 1);
   }



   // Function operator that divides a fraction to with another fraction...
   // ...object inline

   // Parameter right: Fraction object that is the right side of the /= operator
   Fraction Fraction::operator/=(const Fraction& right)
   {
      simplify();
      // Divides the current fraction object context by fraction object
      *this = divide_fractions(numerator, denominator, right.numerator, right.denominator);


      return *this;
   }



   // Function operator that divides a fraction to with integer...
   // ...inline

   // Parameter right: Integer object that is the right side of the /= operator
   Fraction Fraction::operator/=(int val)
   {
      simplify();
      // Divides the current fraction object context by integer val
      return divide_fractions(numerator, denominator, val, 1);
   }

}
