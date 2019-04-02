#include <iostream>
#include <algorithm>

using namespace std;

//123 132 213 231 312 321
// FIXME: Write sort function
void sort(string& str1, string& str2, string& str3){
   string temp;
   
   if(str1.at(0) < str2.at(0) && str1.at(0) < str3.at(0)){
      str1 = str1;
      if(str2.at(0) < str3.at(0)){
         str2 = str2;
         str3 = str3;
      } else{
         temp = str2;
         str2 = str3;
         str3 = temp;
      }
   } else if(str2.at(0) < str3.at(0) && str2.at(0) < str1.at(0)){
      temp = str1;
      str1 = str2;
      str2 = temp;
      if(str2.at(0) < str3.at(0)){
         str2 = str2;
         str3 = str3;
      } else{
         temp = str2;
         str2 = str3;
         str3 = temp;
      }
   } else if (str3.at(0) < str1.at(0) && str3.at(0) < str2.at(0)){
      temp = str1;
      str1 = str3;
      str3 = temp;
      if(str2.at(0) < str3.at(0)){
         str2 = str2;
         str3 = str3;
      } else{
         temp = str2;
         str2 = str3;
         str3 = temp;
      }
   }
   
   return;
}

int main() {
   string s1, s2, s3;
   cout << "Enter 3 words" << endl;
   cin >> s1 >> s2 >> s3;
   cout << endl;
   
   cout << "The words in the original order you entered them:" << endl;
   cout << s1 << endl
      << s2 << endl
      << s3 << endl;
      
   sort(s1, s2, s3);
   cout << endl << "The words in alphabetic order:" << endl;
   
   cout << s1 << endl
      << s2 << endl
      << s3 << endl;
      
   return 0;
}