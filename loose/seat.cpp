#include <iostream>
using namespace std;

int main() {
   int numRows = 2;
   int numCols = 3;

   // Note: You'll need to define more variables
   char letter = 0;
   for(int i = 1; i <= numRows; ++i){
      for(char j = 'A'; j < 'A' + numCols; ++j){

         cout << i << j << " ";
      }
   }
   /* Your solution goes here  */

   cout << endl;

   return 0;
}