#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int add(int num1, int num2){
	int sum = num1 + num2;

	return sum;
}
int subtract(int num1, int num2){
	int diff = num1 - num2;

	return diff;
}

int main(){
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	int diff = 0;

	cout << "Enter the first integer: ";
	cin >> num1;
	cout << "Enter the second integer: ";
	cin >> num2;
	cout << endl << endl;

	cout << "First Integer: " << num1 << endl;
	cout << "Second Integer: " << num2 << endl;
	cout << endl;

	sum = add(num1, num2);
	diff = subtract(num1, num2);

	cout << num1 << " + " << num2 << " = " << sum << endl;
	cout << num1 << " - " << num2 << " = " << diff << endl;

	return 0;
}