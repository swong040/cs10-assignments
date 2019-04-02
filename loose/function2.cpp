#include <iostream>
using namespace std;

// FIXME (3) multiply function
void multiply(double num1, double num2, double& prod){
   prod = num1 * num2;
   return;
}
// FIXME (5) divide function
void divide(double num1, double num2, double& quot){
   quot = num1 / num2;
   return;
}


int main() {
   double num1 = 0;
   double num2 = 0;
   double prod = 0; //product of numbers
   double quot = 0; //quotient of numbers

   // FIXME (1) Prompt user for ints and print them
   cout << "Enter the first float point number: ";
   cin >> num1;
   cout << endl;
   cout << "Enter the second float point number: ";
   cin >> num2;
   cout << endl;
   
   cout << "First float point number: " << num1 << endl
        << "Second float point number: " << num2 << endl
        << endl;
   //Call multiply function
   multiply(num1, num2, prod);

   // FIXME (2) Call divide function
   divide(num1, num2, quot);

   // FIXME (4) Output result of num1 * num2
   cout << num1 << " * " << num2 << " = " << prod << endl;

   // FIXME (6) Output result of num1 / num2
   cout << num1 << " / " << num2 << " = " << quot << endl;


   return 0;
}
