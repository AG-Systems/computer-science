#include <iostream>
#include <string>
#include <cassert>
#include <string>


using namespace std;

/* [INSERT YOUR CODE HERE, FIRST YOUR CLASS DECLARATION, FOLLOWED BY YOUR CLASS
MEMBER FUNCTION DEFINITIONS!]
*/

class Fraction
{ 
    public:
        Fraction(int num = 0, int den = 1);
        int get_numerator();
        int get_denominator();
        void set_numerator(int num = 0);
        void set_denominator(int den = 1);
        friend bool operator<(const Fraction& left, 
                           const Fraction& right);
         friend bool operator<=(const Fraction& left, 
                     const Fraction& right);
        friend bool operator>(const Fraction& left, 
                        const Fraction& right);
         friend bool operator>=(const Fraction& left, 
                  const Fraction& right);
        friend Fraction operator+(const Fraction& left, 
                           const Fraction& right);
        friend Fraction operator-(const Fraction& left, 
                           const Fraction& right);
         friend Fraction operator*(const Fraction& left, 
                     const Fraction& right);
         friend Fraction operator/(const Fraction& left, 
                     const Fraction& right);


        Fraction operator++();
        Fraction operator++(int val);  
        Fraction operator--();
        Fraction operator--(int val);

        Fraction operator+=(const Fraction& right);
        Fraction operator*=(const Fraction& right);
        Fraction operator-=(const Fraction& right);
        Fraction operator/=(const Fraction& right);       

    private:
        int numerator, denominator;
}; 

Fraction::Fraction(int num, int den)
{
    assert(den != 0);
    
    numerator = num; 
    denominator = den; 
}


int Fraction::get_numerator()
{
    return numerator;
}

int Fraction::get_denominator()
{
    return denominator;
}

void Fraction::set_numerator(int num)
{
    numerator = num;
}

void Fraction::set_denominator(int den)
{
    denominator = den;
}

ostream& operator<<(ostream& out, const Fraction& fraction_object)
{   
    out << fraction_object.get_numerator << "|" << fraction_object.get_denominator; 
    return out;
}

bool operator<(const Fraction& left, const Fraction& right)
{
  if(left.get_numerator && right.get_numerator)
  {
   int left_side = right.get_numerator * left.get_denominator;
   int right_side = right.get_denominator * left.get_numerator;

   return left_side < right_side;
  }
  
  if(left.get_numerator)
  {
   int left_side = right * left.get_denominator;
   int right_side = right.get_denominator * 1;

   return left_side < right_side;     
  }

  if(right.get_numerator)
  {
   int left_side = right.get_numerator * 1;
   int right_side = right.get_denominator * left;

   return left_side < right_side;     
  }

}

bool operator<=(const Fraction& left, const Fraction& right)
{
  if(left.get_numerator && right.get_numerator)
  {
   int left_side = right.get_numerator * left.get_denominator;
   int right_side = right.get_denominator * left.get_numerator;

   return left_side <= right_side;
  }
  
  if(left.get_numerator)
  {
   int left_side = right * left.get_denominator;
   int right_side = right.get_denominator * 1;

   return left_side <= right_side;     
  }

  if(right.get_numerator)
  {
   int left_side = right.get_numerator * 1;
   int right_side = right.get_denominator * left;

   return left_side <= right_side;     
  }

}

bool operator>(const Fraction& left, const Fraction& right)
{

  if(left.numerator && right.numerator)
  {
   int left_side = right.numerator * left.denominator;
   int right_side = right.denominator * left.numerator;

   return left_side > right_side;
  }
  
  if(left.numerator)
  {
   // int left_side = right * left.denominator;
   int left_side = 1;
   int right_side = right.denominator * 1;
   
   return left_side > right_side;     
  }

  if(right.numerator)
  {
   int left_side = right.numerator * 1;
   // int right_side = right.denominator * left;
   int right_side = 1;
   return left_side > right_side;     
  }
}

bool operator>=(const Fraction& left, const Fraction& right)
{

  if(left.numerator && right.numerator)
  {
   int left_side = right.numerator * left.denominator;
   int right_side = right.denominator * left.numerator;

   return left_side >= right_side;
  }
  
  if(left.numerator)
  {
   // int left_side = right * left.denominator;
   int left_side = 1;
   int right_side = right.denominator * 1;
   
   return left_side >= right_side;     
  }

  if(right.numerator)
  {
   int left_side = right.numerator * 1;
   // int right_side = right.denominator * left;
   int right_side = 1;
   return left_side >= right_side;     
  }
}


Fraction operator+(const Fraction& left, 
                     const Fraction& right)
{
   Fraction left_side_clone;
   Fraction right_side_clone;

   if(left.get_numerator && right.get_numerator)
   {
       right_side_clone.denominator = right.denominator * left.denominator;
       right_side_clone.numerator = left.denominator * right.numerator;

       left_side_clone.denominator = right.denominator * left.denominator;
       left_side_clone.numerator = right.denominator * left.numerator;

      Fraction temp(left_side_clone.numerator + right_side_clone.numerator, left_side_clone.denominator);
      return temp;
   
   }
}

Fraction operator*(const Fraction& left, 
                     const Fraction& right) // INCOMPLETE
{
   Fraction left_side_clone;
   Fraction right_side_clone;

   if(left.get_numerator && right.get_numerator)
   {
       right_side_clone.denominator = right.denominator * left.denominator;
       right_side_clone.numerator = left.denominator * right.numerator;

       left_side_clone.denominator = right.denominator * left.denominator;
       left_side_clone.numerator = right.denominator * left.numerator;

      Fraction temp(left_side_clone.numerator + right_side_clone.numerator, left_side_clone.denominator);
      return temp;
   
   }
}

Fraction operator/(const Fraction& left, 
                     const Fraction& right) // INCOMPLETE
{
   Fraction left_side_clone;
   Fraction right_side_clone;

   if(left.get_numerator && right.get_numerator)
   {
       right_side_clone.denominator = right.denominator * left.denominator;
       right_side_clone.numerator = left.denominator * right.numerator;

       left_side_clone.denominator = right.denominator * left.denominator;
       left_side_clone.numerator = right.denominator * left.numerator;

      Fraction temp(left_side_clone.numerator + right_side_clone.numerator, left_side_clone.denominator);
      return temp;
   
   }
}



Fraction operator-(const Fraction& left, 
                     const Fraction& right)
{
   Fraction left_side_clone;
   Fraction right_side_clone;

   if(left.get_numerator && right.get_numerator)
   {
       right_side_clone.denominator = right.denominator * left.denominator;
       right_side_clone.numerator = left.denominator * right.numerator;

       left_side_clone.denominator = right.denominator * left.denominator;
       left_side_clone.numerator = right.denominator * left.numerator;

      Fraction temp(left_side_clone.numerator - right_side_clone.numerator, left_side_clone.denominator);
      return temp;
   
   }
}
/*
Fraction Fraction::add_fractions(left_num, left_den, right_num, right_den)
{
   Fraction left_side_clone;
   Fraction right_side_clone;

   right_side_clone.denominator = right.denominator * left.denominator;
   right_side_clone.numerator = left.denominator * right.numerator;

   left_side_clone.denominator = right.denominator * left.denominator;
   left_side_clone.numerator = right.denominator * left.numerator;

   Fraction temp(left_side_clone.numerator + right_side_clone.numerator, left_side_clone.denominator);

      
   return temp;
}
*/


Fraction Fraction::operator++()
{
   Fraction temp(denominator, denominator);
   operator+(temp, left);
   return temp + left;

}

Fraction Fraction::operator++(int val)
{
   Fraction temp(val, denominator);
   return temp + left;
}

Fraction Fraction::operator--()
{
   Fraction temp(denominator, denominator);
   return temp - left;

}

Fraction Fraction::operator--(int val)
{
   Fraction temp(val, denominator);
   return temp - left;
}

Fraction Fraction::operator+=(const Fraction& right)
{
   *this = *this + right;

   // or:
   //feet += right.feet;
   //inches += right.inches;
   //simplify();

   return *this;
}


void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
    /* 
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
    */

   Fraction f1;

	cout << f1;
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


