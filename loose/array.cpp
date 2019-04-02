#include <iostream>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int arraySize, int index);
void display(const double array[], int arraySize);

int main(){
	int arraySize = 10;
	double userArray[arraySize];


	cout << "Enter 10 values:" << endl;
	for(int i = 0; i < arraySize; i++){
		cin >> userArray[i];
	}
	cout << endl;
	cout << "Mean: " << mean(userArray, arraySize) << endl << endl;

	int userRemove = 0;
	cout << "Enter index of value to be removed: ";
	cin >> userRemove;
	cout << endl;

	cout << "Before removing value: "; 
	display(userArray, arraySize);
	cout << endl;

	remove(userArray, arraySize, userRemove);
	arraySize -= 1;
	
	cout << "After removing value: ";
	display(userArray, arraySize);
	cout << endl;


	return 0;
}

double mean(const double array[], int arraySize){
	double sumArray = 0;
	for(int i = 0; i < arraySize; i++){
		sumArray += array[i];
	}
	return sumArray / arraySize;
}

void remove(double array[], int arraySize, int index){
	for(int i = index; i < arraySize - 1; i++){
		array[i] = array[i + 1];
	}
}
void display(const double array[], int arraySize){
	for(int i = 0; i < arraySize - 1; i++){
		cout << array[i] << ", ";
	}
	cout << array[arraySize - 1];
}