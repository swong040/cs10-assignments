#include <iostream>
using namespace std;

int main() {
   
   char c = 0;
   int rows = 0;
   
   cout << "Enter a character: ";
   cin >> c;
   
   cout << "Enter number of rows: " << endl;
   cin >> rows;
   
   for(int i = 1; i <= rows; ++i){
      for(int j = rows; j > i; --j) {
         cout << "  ";
      }
      for(int k = 1; k <= i; ++k){
         cout << c << " ";
      }
      cout << endl;
   }
   
   return 0;
}