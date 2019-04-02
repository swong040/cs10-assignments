/* (1) Use getline() to get a line of user input 
into a string. Output the line. 
Ex:

Enter text: IDK if I'll go. It's my BFF's birthday. 
You entered: IDK if I'll go. It's my BFF's birthday.

(2) Extend to search the string (using find()) for common abbreviations and 
print a list of each found abbreviation along with its decoded meaning. Ex:

Enter text: IDK if I'll go. It's my BFF's birthday. 
You entered: IDK if I'll go. It's my BFF's birthday. 
BFF: best friend forever
IDK: I don't know
Support these abbreviations:

BFF -- best friend forever
IDK -- I don't know
JK -- just kidding
TMI -- too much information
TTYL -- talk to you later
*/

#include <iostream>
#include <string>

// FIXME include string library
using namespace std;

int main() {
   
   string userInput;
   
   cout << "Enter text: " << endl;
   getline(cin, userInput);
   cout << "You entered: " << userInput << endl;
   
   if(userInput.find("BFF") != string::npos){
      userInput.replace(userInput.find("BFF"), 3, "best friend forever");
   } if (userInput.find("IDK") != string::npos){
      userInput.replace(userInput.find("IDK"), 3, "I don't know");
   } if (userInput.find("JK") != string::npos){
      userInput.replace(userInput.find("JK"), 2, "just kidding");
   } if (userInput.find("TMI") != string::npos){
      userInput.replace(userInput.find("TMI"), 3, "too much information");
   } if (userInput.find("TTYL") != string::npos){
      userInput.replace(userInput.find("TTYL"), 4, "talk to you later");
   } else {
      
   }

   cout<< "Expanded: " << userInput << endl;
   
  /* Type your code here. */
   
  return 0;
}