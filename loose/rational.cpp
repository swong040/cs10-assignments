#include <iostream>

using namespace std;


class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const; 
      void display() const; 
};

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational::Rational(){
	numerator = 0;
	denominator = 1;

	return;
} 

Rational::Rational(int top){
	numerator = top;
	denominator = 1;

	return;
}

Rational::Rational(int top, int bottom){
	numerator = top;
	denominator = bottom;

	return;
}

const Rational Rational::add(const Rational& B) const{
	int n = (numerator * B.denominator + B.numerator * denominator);
	int d = B.denominator * denominator;

	return Rational(n, d);

}

const Rational Rational::subtract(const Rational& B) const{
	int n = (numerator * B.denominator - B.numerator * denominator);
	int d = B.denominator * denominator;

	return Rational(n, d);
}

const Rational Rational::multiply(const Rational& B) const{
	int n = numerator * B.numerator;
	int d = B.denominator * denominator;

	return Rational(n, d);
}

const Rational Rational::divide(const Rational& B) const{
	int n = numerator * B.denominator;
	int d = B.numerator * denominator;

	return Rational(n, d);
}

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

void Rational::display() const{
	cout << numerator << " / " << denominator;
} 

