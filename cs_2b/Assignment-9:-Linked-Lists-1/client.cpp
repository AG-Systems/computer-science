#include <iostream>

#include "sequence.h"

using namespace std;
using namespace cs_sequence;

int main() {
	Sequence s;

	for (int i = 0; i < 6; i++) 
  {
		s.insert(i);
	}
	
	for (s.start(); s.is_item(); s.advance()) 
  {
		cout << s.current() << " ";
	}
	
	cout << endl;
	cout << "Length of linked list: " << s.size() << endl;
}