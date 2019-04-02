/* (1) Get a single word of input from the user. Output the word. 
If the word contains certain characters, 
use a loop of your choosing to replace them with 
the corresponding symbols or numbers. 

Ex.
Enter word: sixteen
You entered: sixteen
New word: $!*t33n

You should support these characters:
a -- @
e -- 3
i -- !
g -- 9
s -- $
x -- *

If your word does not contain any of the above characters, 
just print the original word again.
*/

#include <iostream>
#include <string>

// FIXME include string library
using namespace std;

int main() {
   
   string userInput;
   
   cout << "Enter word: ";
   cin >> userInput;
   cout << "You entered: " << userInput << endl;
   
   int i = 0;
   while(i != userInput.length()) {
      if(userInput.at(i) == 'a') {
         userInput.replace(i,1, "@") ; 
      } else if(userInput.at(i) == 'e') {
         userInput.replace(i,1, "3") ;
      } else if(userInput.at(i) == 'i') {
         userInput.replace(i,1, "!") ;
      } else if(userInput.at(i) == 'g') {
         userInput.replace(i,1, "9") ;
      } else if(userInput.at(i) == 's') {
         userInput.replace(i,1, "$") ;
      } else if(userInput.at(i) == 'x') {
         userInput.replace(i,1, "*") ;
      } else {
         userInput;
      }
       i = i + 1;
   }
   
   cout << "New word: " << userInput << endl;
   
   /* Type your code here. */
   
   return 0;
}