#include <iostream>

using namespace std;

int main()
{
   char c = 'a';
   
   cout << "Enter a character: ";
   cin >> c;
   
   if((c >= 'a') && (c <= 'z')) {
      cout << "You entered a lowercase alphabetic character." << endl;
   } else if ((c >= 'A') && (c <= 'Z')){
      cout << "You entered an uppercase alphabetic character." << endl;
   } else if ((c >= '0') && (c <= '9')){
      cout << "You entered a numeric digit." << endl;
   } else {
      cout << "You did not enter an alphanumeric character." << endl;
   }

   return 0;
}