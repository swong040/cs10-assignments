#include <iostream>

using namespace std;

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y);
int gcd(int a, int b);

int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

int gcd(int a, int b){
   if(b == 0){
      return a;
   } else{
      return gcd(b, a % b);
   }
}

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y){
   if(c % gcd(a, b) == 0){
      if(a % b == 0){
         x = 0;
         y = c / b;
         return true;
      } else{
         int r = a % b;
         int q = a / b;
         int u = (q * x) + y;
         int v = x;
         a = b;
         b = r;
         diophantine(a, b, c, u, v);
         x = v;
         y = u - (q * x);
         return true;
      }
   }

   return false;
}