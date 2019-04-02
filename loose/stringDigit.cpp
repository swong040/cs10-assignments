#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   bool hasDigit = false;
   string passCode;
   int valid = 0;

   passCode = "abc";
   
   // "2 5"
   // "32x"
   // "?7a"
   
   if(iasdigit(passCode.at(0))){
      hasDigit = true;
   } else if (isdigit(passCode.at(1))){
      hasDigit = true;
   } else if (isdigit(passCode.at(2))){
      hasDigit = true;
   } else {
      hasDigit = false;
   }
   /* Your solution goes here  */

   if (hasDigit) {
      cout << "Has a digit." << endl;
   }
   else {
      cout << "Has no digit." << endl;
   }

   return 0;
}