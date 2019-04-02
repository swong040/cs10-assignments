#include <iostream>
using namespace std;

int main() {
   int numStars = 0;
   int numPrinted = 0;

   numStars = 12;
   numPrinted = 1;

   while(numPrinted <= numStars) {
      cout << '*';
      ++numPrinted;
   }
   /* Your solution goes here  */

   cout << endl;

   return 0;
}