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
        // Fraction add_fractions(int left_num, int left_den, int right_num, int right_den);

        friend bool operator<(const Fraction& left, 
                           const Fraction& right);
        friend bool operator<(const Fraction& left, 
                        int right);
        friend bool operator<(int left, 
                        const Fraction& right);

         friend bool operator<=(const Fraction& left, 
                     const Fraction& right);
         friend bool operator<=(const Fraction& left, 
                     int right);
         friend bool operator<=(int left, 
                     const Fraction& right);

        friend bool operator>(const Fraction& left, 
                        const Fraction& right);
        friend bool operator>(const Fraction& left, 
                        int right);
        friend bool operator>(int left, 
                        const Fraction& right);
    
         friend bool operator>=(const Fraction& left, 
                  const Fraction& right);
         friend bool operator>=(int left, 
                  const Fraction& right);
         friend bool operator>=(const Fraction& left, 
                  int right);

         friend bool operator==(const Fraction& left, 
                  const Fraction& right);
         friend bool operator==(int left, 
                  const Fraction& right);
         friend bool operator==(const Fraction& left, 
                  int right);

        friend bool operator!=(const Fraction& left, 
            const Fraction& right);
        friend bool operator!=(int left, 
            const Fraction& right);
        friend bool operator!=(const Fraction& left, 
            int right);


        friend Fraction operator+(const Fraction& left, 
                           const Fraction& right);
        friend Fraction operator+(int left, 
                           const Fraction& right);
        friend Fraction operator+(const Fraction& left, 
                           int right);


        friend Fraction operator-(const Fraction& left, 
                           const Fraction& right);
        friend Fraction operator-(int left, 
                           const Fraction& right);
        friend Fraction operator-(const Fraction& left, 
                           int right);


         friend Fraction operator*(const Fraction& left, 
                     const Fraction& right);
         friend Fraction operator*(int left, 
                     const Fraction& right);
         friend Fraction operator*(const Fraction& left, 
                     int right);

         friend Fraction operator/(const Fraction& left, 
                     const Fraction& right);
         friend Fraction operator/(int left, 
                     const Fraction& right);
         friend Fraction operator/(const Fraction& left, 
                     int right);



        friend std::ostream& operator<<(std::ostream& out, 
                                    const Fraction& right);

        Fraction operator++();
        Fraction operator++(int val);   
          
        Fraction operator--();
        Fraction operator--(int val);

        Fraction operator+=(int val);
        Fraction operator+=(const Fraction& right);

        Fraction operator*=(const Fraction& right);
        Fraction operator*=(int val);

        Fraction operator-=(const Fraction& right);
        Fraction operator-=(int val);

        Fraction operator/=(const Fraction& right);
        Fraction operator/=(int val);       

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

Fraction add_fractions(int left_num, int left_den, int right_num, int right_den)
{
   int const old_left_num = left_num;

   left_num = left_num * right_den;
   right_num = right_num * old_left_num;

   Fraction temp((left_num + right_num), (left_den * right_den));

      
   return temp;
}

Fraction minus_fractions(int left_num, int left_den, int right_num, int right_den)
{
   int const old_left_num = left_num;

   left_num = left_num * right_den;
   right_num = right_num * old_left_num;

   Fraction temp((left_num - right_num), (left_den * right_den));

      
   return temp;
}

Fraction multiply_fractions(int left_num, int left_den, int right_num, int right_den)
{

   Fraction temp( (left_num * right_num), (right_den * left_den) );     
   return temp;
}

Fraction divide_fractions(int left_num, int left_den, int right_num, int right_den)
{
   Fraction temp( (left_num * right_den), (right_den * left_num) );     
   return temp;
}

ostream& operator<<(ostream& out, const Fraction& right)
{   
    out << right.numerator << "|" << right.denominator; 
    return out;
}

bool operator<(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side < right_side;
}

bool operator<(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side < right_side; 
}

bool operator<(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side < right_side; 
}


bool operator<=(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side <= right_side;
}

bool operator<=(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side <= right_side; 
}

bool operator<=(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side <= right_side; 
}

bool operator>(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side > right_side;
}

bool operator>(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side > right_side; 
}

bool operator>(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side > right_side; 
}

bool operator>=(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side >= right_side;
}

bool operator>=(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side >= right_side; 
}

bool operator>=(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side >= right_side; 
}

bool operator==(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side == right_side;
}

bool operator==(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side == right_side; 
}

bool operator==(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side == right_side; 
}

bool operator!=(const Fraction& left, const Fraction& right)
{
   int left_side = right.numerator * left.denominator;
   int right_side = left.numerator * right.denominator;

   return left_side != right_side;
}

bool operator!=(int left, const Fraction& right)
{
   int left_side = right.numerator * 1;
   int right_side = left * right.denominator;

   return left_side != right_side; 
}

bool operator!=(const Fraction& left, int right)
{
   int left_side = right * left.denominator;
   int right_side = left.denominator * 1;

   return left_side != right_side; 
}

Fraction operator+(const Fraction& left, 
                     const Fraction& right)
{
    return add_fractions(left.numerator, left.denominator, right.numerator, right.denominator);
}

Fraction operator+(int left, 
                     const Fraction& right)
{
    return add_fractions((left * right.denominator), right.denominator, right.numerator, right.denominator);
}

Fraction operator+(const Fraction& left, 
                     int right)
{
    return add_fractions(left.numerator, left.denominator, (left.numerator * right), left.denominator);
}


Fraction operator-(const Fraction& left, 
                     const Fraction& right)
{
   return minus_fractions(left.numerator, left.denominator, right.numerator, right.denominator); 
}

Fraction operator-(int left, 
                     const Fraction& right)
{
   return minus_fractions(left, 1, right.numerator, right.denominator); 
}

Fraction operator-(const Fraction& left, 
                     int right)
{
   return minus_fractions(left.numerator, left.denominator, right, 1); 
}



Fraction operator*(const Fraction& left, 
                     const Fraction& right)
{
    return multiply_fractions(left.numerator, left.denominator, right.numerator, right.denominator);
}
Fraction operator*(int left, 
                     const Fraction& right) 
{
    return multiply_fractions(left, 1, right.numerator, right.denominator);
}
Fraction operator*(const Fraction& left, 
                     int right) 
{
    return multiply_fractions(left.numerator, left.denominator, right, 1);
}


Fraction operator/(const Fraction& left, 
                     const Fraction& right) 
{
   return divide_fractions(left.numerator, left.denominator, right.numerator, right.denominator);
}
Fraction operator/(int left, 
                     const Fraction& right)
{
   return divide_fractions(left, 1, right.numerator, right.denominator);
}
Fraction operator/(const Fraction& left, 
                     int right) 
{
   return divide_fractions(left.numerator, left.denominator, right, 1);
}






Fraction Fraction::operator++()
{
   return add_fractions(numerator, denominator, denominator, denominator);
}

Fraction Fraction::operator++(int val)
{
    return add_fractions(numerator, denominator, ( denominator * val), denominator);
}


Fraction Fraction::operator--()
{
    return minus_fractions(numerator, denominator, denominator, denominator);
}

Fraction Fraction::operator--(int val)
{
    return minus_fractions(numerator, denominator, ( denominator * val), denominator);
}

Fraction Fraction::operator+=(const Fraction& right)
{
   *this = *this + right;


   return *this;
}

Fraction Fraction::operator+=(int val)
{
    return add_fractions(numerator, denominator, ( denominator * val), denominator);
}

Fraction Fraction::operator-=(const Fraction& right)
{
   *this = *this + right;


   return *this;
}

Fraction Fraction::operator-=(int val)
{
    return minus_fractions(numerator, denominator, ( denominator * val), denominator);
}

Fraction Fraction::operator*=(const Fraction& right)
{
   *this = *this + right;


   return *this;
}

Fraction Fraction::operator*=(int val)
{
    return multiply_fractions(numerator, denominator, ( denominator * val), denominator);
}

Fraction Fraction::operator/=(const Fraction& right)
{
   *this = *this + right;


   return *this;
}

Fraction Fraction::operator/=(int val)
{
    return divide_fractions(numerator, denominator, ( denominator * val), denominator);
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

