#ifndef CS_FRACTION_H
#define CS_FRACTION_H
#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include <cmath> 
#include <iostream>

using namespace std;

namespace cs_fraction {

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


            // Istream function that input fraction objects
            // Parameter out: Passes the istream function
            // Parameter right: Fraction object that wants to be inputed
         friend std::istream& operator>>(std::istream& in, 
                                       Fraction& right);

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

         void simplify();
         void simplify_helper(int base=1);
   }; 

}
#endif