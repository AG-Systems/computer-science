
#include <iostream>
using namespace std;
using namespace cs_sparse;
#include "FHsparseMat.h"

#define MAT_SIZE 100000
/* typedef SparseMat<float> SpMat; */

// --------------- main ---------------
int main()
{
   SpMat mat(MAT_SIZE, MAT_SIZE, 0); // 100000 x 100000 filled with 0

   // test mutators
   mat.set(2, 5, 10);
   mat.set(2, 5, 35);   // should overwrite the 10
   mat.set(3, 9, 21);
   mat.set(MAT_SIZE, 1, 5);  // should fail silently
   mat.set(9, 9, mat.get(3, 9));  // should copy the 21 here
   mat.set(4,4, -9);
   mat.set(4,4, 0);   // should remove the -9 node entirely
   mat.set(MAT_SIZE-1, MAT_SIZE-1, 99);

   // test accessors and exceptions
   try
   {
      cout << mat.get(7, 8) << endl;
      cout << mat.get(2, 5) << endl;
      cout << mat.get(9, 9) << endl;
      cout << mat.get(-4, 7) << endl;  // should throw an exception
   }
   catch (...)
   {
      cout << "oops" << endl;
   }

   // show top left 15x15
   mat.showSubSquare(0, 15);

   // show bottom right 15x15
   mat.showSubSquare(MAT_SIZE - 15, 15);
}
