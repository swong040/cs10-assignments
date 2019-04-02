#include <iostream>
using namespace std;

int main() {
   
   char c = 0;
   int rows = 0;
   
   cout << "Enter a character: ";
   cin >> c;
   
   cout << "Enter number of rows: " << endl;
   cin >> rows;
   
   for(int i = rows; i >= 1; --i) {
       for(int j = 1; j <= i; ++j ){
       cout << c << " ";
       }
      cout << endl;
   }
   
   return 0;
}