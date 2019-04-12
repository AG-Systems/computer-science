#include <iostream>
#include <string>
#include <cassert>
#include <string>

/*
Name: Max Chakhmatov
Date: April 10 2019
Instructor:  Dave Harden
Name of file: a1_1.cpp
Description:  This program can create fractions and evaluate them first hand by using any basic programming arithmetic.

Input: The input is by creating any Fraction object by typing Fraction name_of_object. 
If you do not use any parameters, it will default to a 0 / 1 fraction. If you put only one parameter, it will be num / 1 
fraction. Lastly if you input 2, it will be num1 / num2.

Output: Test cases of the fraction class and the following functions of the arthmetic. 



*/

using namespace std;


class Fraction
{ 
    public:
        // Constructor function
        // Gets called after the object gets created
        Fraction(int num = 0, int den = 1);

        // Function that returns the numerator value of the object
        int get_numerator();

        // Function that returns the denominator value of the object
        int get_denominator();

        // Function that sets the object numerator
        // Parameter num: Numerator value, must be integer
        void set_numerator(int num = 0);

        // Function that sets the object denominator
        // Parameter den: Denominator value, must be integer
        void set_denominator(int den = 1);


         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator<(const Fraction& left, 
                           const Fraction& right);

         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
        friend bool operator<(const Fraction& left, 
                        int right);

         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator<(int left, 
                        const Fraction& right);

         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator<=(const Fraction& left, 
                     const Fraction& right);

         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
         friend bool operator<=(const Fraction& left, 
                     int right);


         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator<=(int left, 
                     const Fraction& right);

         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator>(const Fraction& left, 
                        const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
        friend bool operator>(const Fraction& left, 
                        int right);

         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator>(int left, 
                        const Fraction& right);
   


         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator>=(const Fraction& left, 
                  const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator>=(int left, 
                  const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
         friend bool operator>=(const Fraction& left, 
                  int right);

         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator==(const Fraction& left, 
                  const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
         friend bool operator==(int left, 
                  const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Fraction object on the left side
         // Parameter right: Intreger on the right side
         friend bool operator==(const Fraction& left, 
                  int right);
         
         
         // Operator function that compares 2 different values
         // Parameter left: Fraction on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator!=(const Fraction& left, 
            const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
        friend bool operator!=(int left, 
            const Fraction& right);


         // Operator function that compares 2 different values
         // Parameter left: Fractioj on the left side
         // Parameter right: Integer on the right side
        friend bool operator!=(const Fraction& left, 
            int right);



         // Operator function that adds 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
        friend Fraction operator+(const Fraction& left, 
                           const Fraction& right);


         // Operator function that adds 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
        friend Fraction operator+(int left, 
                           const Fraction& right);

         // Operator function that adds 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
        friend Fraction operator+(const Fraction& left, 
                           int right);


         // Operator function that minus 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
        friend Fraction operator-(const Fraction& left, 
                           const Fraction& right);


         // Operator function that minus 2 different values togeather
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
        friend Fraction operator-(int left, 
                           const Fraction& right);


         // Operator function that minus 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
        friend Fraction operator-(const Fraction& left, 
                           int right);



         // Operator function that multiplies 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
         friend Fraction operator*(const Fraction& left, 
                     const Fraction& right);



         // Operator function that multiplies 2 different values togeather
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
         friend Fraction operator*(int left, 
                     const Fraction& right);



         // Operator function that multiplies 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
         friend Fraction operator*(const Fraction& left, 
                     int right);


         // Operator function that divides 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Fraction object on the right side
         friend Fraction operator/(const Fraction& left, 
                     const Fraction& right);


         // Operator function that divides 2 different values togeather
         // Parameter left: Integer on the left side
         // Parameter right: Fraction object on the right side
         friend Fraction operator/(int left, 
                     const Fraction& right);


         // Operator function that divides 2 different values togeather
         // Parameter left: Fraction object on the left side
         // Parameter right: Integer on the right side
         friend Fraction operator/(const Fraction& left, 
                     int right);


         // Ostream function that prints fraction objects fast and easy
         // Parameter out: Passes the ostream function
         // Parameter right: Fraction object that wants to be printed
        friend std::ostream& operator<<(std::ostream& out, 
                                    const Fraction& right);

         // Operator function that incremates a fraction object by 1
        Fraction operator++();



         // Operator function that incremates a fraction object by the variable val
         // Parameter val: The right side of the ++ operator that is a integer
        Fraction operator++(int val);   



         // Operator function that subtracts a fraction object by 1
        Fraction operator--();


         // Operator function that incremates a fraction object by the variable val
         // Parameter val: The right side of the ++ operator that is a integer
        Fraction operator--(int val);

         // Operator function that incremates a fraction object by the variable val
         // Parameter val: The right side of the ++ operator that is a integer
        Fraction operator+=(int val);


         // Operator function that incremates a fraction object by another fraction...
         // ... inline
         // Parameter right: The right side of the += operator that is a fraction obj
        Fraction operator+=(const Fraction& right);



         // Operator function that multiplies a fraction object by another fraction...
         // ... inline
         // Parameter val: The right side of the *= operator that is a fraction obj
        Fraction operator*=(const Fraction& right);



         // Operator function that multiplies a fraction object by integer inline
         // Parameter val: The right side of the *= operator that is a integer
        Fraction operator*=(int val);


         // Operator function that subtracts a fraction object by another fraction...
         // ... inline
         // Parameter right: The right side of the -= operator that is a fraction obj
        Fraction operator-=(const Fraction& right);


         // Operator function that multiplies a fraction object by integer inline
         // Parameter val: The right side of the -= operator that is a integer
        Fraction operator-=(int val);


         // Operator function that divides a fraction object by another fraction...
         // ... inline
         // Parameter right: The right side of the /= operator that is a fraction obj
        Fraction operator/=(const Fraction& right);


         // Operator function that multiplies a fraction object by integer inline
         // Parameter val: The right side of the *= operator that is a integer
        Fraction operator/=(int val);       

    private:
        // The 2 data members of a fraction object
        int numerator, denominator;
}; 





// Constructor of the Fraction class. Gets called after the object gets created.
Fraction::Fraction(int num, int den)
{
    assert(den != 0); // Makes sure the fraction is not undefined 
    
    numerator = num; 
    denominator = den; 
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
}




// Sets the denominator of the object
// Parameter den: The value that you pass through to set the denominator of the object
void Fraction::set_denominator(int den)
{
    denominator = den; // This sets the denominator to the parameter input
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
    out << right.numerator << "\\" << right.denominator; 
    return out;
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
   // Adds the current fraction object context by one
   *this = add_fractions(numerator, denominator, 1, 1); 
   return *this;
}


// Function operator that post-increment a fraction object
Fraction Fraction::operator++(int)
{
   // Adds the current fraction object context by one
   Fraction temp(numerator, denominator);
   *this = add_fractions(numerator, denominator, 1, 1);
   return temp;
}



// Function operator that pre-deincrement a fraction object
Fraction Fraction::operator--()
{
   // Minues the current fraction object context by one
   *this = minus_fractions(numerator, denominator, 1, 1);
   return *this;
}



// Function operator that post-deincrement a fraction object
Fraction Fraction::operator--(int)
{
   // Minues the current fraction object context by one
   Fraction temp(numerator, denominator);
   *this = minus_fractions(numerator, denominator, 1, 1);
   return temp;
}




// Function operator that adds a fraction object to another fraction...
// ...object inline

// Parameter right: Fraction object that is the right side of the += operator
Fraction Fraction::operator+=(const Fraction& right)
{
   // Adds the current fraction object context by fraction object
   *this = add_fractions(numerator, denominator, right.numerator, right.denominator);


   return *this;
}



// Function operator that adds a integer to another fraction...
// ...object inline

// Parameter right: Integer that is the right side of the += operator
Fraction Fraction::operator+=(int val)
{
   // Adds the current fraction object context by variable val
    return add_fractions(numerator, denominator, val, 1);
}


// Function operator that minuses a fraction object to another fraction...
// ...object inline

// Parameter right: Fraction object that is the right side of the -= operator
Fraction Fraction::operator-=(const Fraction& right)
{
   // Minues the current fraction object context by Fraction object
   *this = minus_fractions(numerator, denominator, right.numerator, right.denominator);

   return *this;
}



// Function operator that minus a integer to another fraction...
// ...object inline

// Parameter right: Integer that is the right side of the -= operator
Fraction Fraction::operator-=(int val)
{
   // Minues the current fraction object context by variable val
    return minus_fractions(numerator, denominator, val, 1);
}



// Function operator that mulitplies a fraction to another fraction...
// ...object inline

// Parameter right: Fraction object that is the right side of the *= operator
Fraction Fraction::operator*=(const Fraction& right)
{
   // Multiplies the current fraction object context by fraction object
   *this = multiply_fractions(numerator, denominator, right.numerator, right.denominator);


   return *this;
}



// Function operator that mulitplies a intreger to another fraction...
// ...object inline

// Parameter right: Integer object that is the right side of the *= operator
Fraction Fraction::operator*=(int val)
{
   // Multiplies the current fraction object context by varaible val
    return multiply_fractions(numerator, denominator, val, 1);
}



// Function operator that divides a fraction to with another fraction...
// ...object inline

// Parameter right: Fraction object that is the right side of the /= operator
Fraction Fraction::operator/=(const Fraction& right)
{
   // Divides the current fraction object context by fraction object
   *this = divide_fractions(numerator, denominator, right.numerator, right.denominator);


   return *this;
}



// Function operator that divides a fraction to with integer...
// ...inline

// Parameter right: Integer object that is the right side of the /= operator
Fraction Fraction::operator/=(int val)
{
   // Divides the current fraction object context by integer val
    return divide_fractions(numerator, denominator, val, 1);
}



void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{ 
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();

}





void BasicTest()
{
    cout << "\n----- Testing basic Fraction creation & printing\n";
    
    const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21), 
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12)};
                                                   
    for (int i = 0; i < 7; i++){
        cout << "Fraction [" << i <<"] = " << fr[i] << endl;
    }
        
        

}





string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	} else {
		return "false";
	}
}


void RelationTest()
{
    cout << "\n----- Testing relational operators between Fractions\n";

    const Fraction fr[] =  {Fraction(3, 6), Fraction(1,2), Fraction(-15,30), 
                            Fraction(1,10), Fraction(0,1), Fraction(0,2)};

    for (int i = 0; i < 5; i++) {
          cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
          cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
          cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
          cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
          cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
          cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
          cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between Fractions and integers\n";
    Fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;
    
    Fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;  
}





void BinaryMathTest()
{    
    cout << "\n----- Testing binary arithmetic between Fractions\n";
    
    const Fraction fr[] = {Fraction(1, 6), Fraction(1,3), 
                           Fraction(-2,3), Fraction(5), Fraction(-4,3)};

    for (int i = 0; i < 4; i++) {
          cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
          cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
          cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
          cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }

    cout << "\n----- Testing arithmetic between Fractions and integers\n";
    Fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;
     
    Fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{    
    cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";
    
    Fraction fr[] = {Fraction(1, 6), Fraction(4), 
                     Fraction(-1,2), Fraction(5)};

    for (int i = 0; i < 3; i++) {
          cout << fr[i] << " += " << fr[i+1] << " = ";
          cout << (fr[i] += fr[i+1]) << endl;
          cout << fr[i] << " -= " << fr[i+1] << " = ";
          cout << (fr[i] -= fr[i+1]) << endl;
          cout << fr[i] << " *= " << fr[i+1] << " = ";
          cout << (fr[i] *= fr[i+1]) << endl;
          cout << fr[i] << " /= " << fr[i+1] << " = ";
          cout << (fr[i] /= fr[i+1]) << endl;
    }
   
    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    Fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    Fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}
