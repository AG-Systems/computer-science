#include <iostream>
#include <ctime>
#include <cstdlib>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;

/*
Max Chakhmatov 
*/



int main() {
    int num1, num2;
    OrderedPair<> myList[10];
    
    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList[0].print();
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        myList[i].setFirst(rand() % 50);
        myList[i].setSecond(rand() % 50 + 50);
    }
    
    myList[2] = myList[0] + myList[1];
    
    if (myList[0] < myList[1]) {
        myList[0].print();
        cout << " is less than ";
        myList[1].print(); 
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++) {
        myList[i].print();
        cout << endl;
    }
    
    cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
    cin >> num1 >> num2;
    OrderedPair<int> x;
    
    /* use this before you've implemented the exception handling in the class:
    
    
    x.setFirst(num1);
    x.setSecond(num2);
    */

    // use this after you've implemented the exception handling in the class:
    try {
        x.setFirst(num1);
        x.setSecond(num2);
    } catch (OrderedPair<int>::DuplicateMemberError e) {
        x.setFirst(OrderedPair<>::DEFAULT_VALUE);
        x.setSecond(OrderedPair<>::DEFAULT_VALUE);        
    }
    
    
    cout << "The resulting OrderedPair: ";
    x.print();
    cout << endl;
}


/*
default value: (0, 0)
(15, 56)
(0, 55)
(15, 111)
(26, 69)
(39, 65)
(16, 52)
(43, 55)
(40, 79)
(31, 91)
(29, 77)
Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: 1
2
The resulting OrderedPair: (1, 2)
*/



/*
default value: (0, 0)
(44, 89)
(23, 76)
(67, 165)
(13, 81)
(20, 78)
(46, 75)
(44, 51)
(15, 98)
(30, 70)
(20, 77)
Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: 1
1
The resulting OrderedPair: (0, 0)
*/