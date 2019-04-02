#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

void readData(const string&, vector<double>&, vector<double>&);	
	// passes in the name of a file and two vectors and stores in the first vector the flight-path
	// angles (first column) and in the second vector the corresponding coefficients of lift 
	// (2nd column).
double interpolation(double, const vector<double>&, const vector<double>&);
	// passes in the requested flight-path angle along with the 2 vectors of data 
	// (flight-path angles and corresponding coefficients of lift) and returns the corresponding
	// coefficient of lift.
bool isOrdered(const vector<double>&);
	// passes in the vector of flight-path angles and returns true if it stores the angles are in
	// ascending order, otherwise returns false.
void reorder(vector<double>&, vector<double>&);
	// passes in both vectors of data and then reorders the data so that the flight-path angles
	// are in ascending order while maintaining the correspondence between the flight-path angles
	// and their corresponding coefficients of lift.
	
bool angleInRange(const vector<double>& , double);
	// check if angle is in range otherwise, repeat input for flight-path angle.
bool exitFunction(const ifstream&, const string&);

	

int main(){
	string filename;
	vector<double> angle;
	vector<double> coefficient;
	ifstream inFS;
	string answer;

	double fpAngle = 0;
    // Ask the user for the name of file that contains the wind tunnel data.
	cout << "Enter name of input data file:" << endl;
	cin >> filename;

	inFS.open(filename.c_str());
	if(!inFS.is_open()){
		cout << endl << "Error opening " << filename << endl;
		return 1;
	}
	
    // Read wind-tunnel data into two parallel vectors, one vector stores the 
    // flight-path angle and the other stores the corresponding coefficient of 
    // lift for that angle.
    readData(filename, angle, coefficient);
    // Ask the user for a flight-path angle. If the angle is within the bounds of the data set, 
    // the program should then use linear interpolation (see explanation of linear interpolation 
    // below) to compute the corresponding coefficient of lift and output it.
    do{
	    if(!isOrdered(angle)){
	    	reorder(angle, coefficient);
	    }

	    // for(unsigned int i = 0; i < coefficient.size(); i++){
	    // 	cout << angle.at(i) << " " << coefficient.at(i) << endl;
	    // } cout << angle.size() << endl;
	    
	    
    	cout << interpolation(fpAngle, angle, coefficient) << endl;
    
    // Finally, ask the user if they want to enter another flight-path angle. 
	    cout << "Do you want to enter another flight-path angle? " << endl;
	    cin >> answer;
    } while(answer != "no" && answer != "No"); 

    // Repeat steps 3 and 4 if they answer yes, otherwise end the program if they answer no.

    return 0;
}

void readData(const string& filename, vector<double>& angle, vector<double>& coefficient){
	double data = 0;
	ifstream inFS;
	inFS.open(filename.c_str());
	
	while(inFS >> data){
		angle.push_back(data);
		inFS >> data;
		coefficient.push_back(data);
	}

	inFS.close();
}
// (angle, coefficient)
double interpolation(double angleInput, const vector<double>& angle, const vector<double>& coefficient){
	unsigned int i = 0;
	double interValue = 0;

	do{
	    cout << "Enter fight-path angle: " << endl;
	    cin >> angleInput;
   	} while(angleInRange(angle, angleInput) != true);

	for(i = 0; i < angle.size(); i++){
		if(angle.at(i) == angleInput){
			return coefficient.at(i);
		} else{
			if(angleInput > angle.at(i) && angleInput < angle.at(i + 1) && (i + 1) < angle.size()){
				interValue = coefficient.at(i) + (angleInput - angle.at(i)) / (angle.at(i + 1) - angle.at(i)) * (coefficient.at(i + 1) - coefficient.at(i));
			}
		}
	}
	return interValue;
}

bool isOrdered(const vector<double>& angle){
	int smallValIndex = 0;
	for(unsigned int i = 1; i < angle.size(); i++){
		if(angle.at(smallValIndex) > angle.at(i)){
			return false;
		} else{
			smallValIndex = i;
		}
	}
	return true;
}

void reorder(vector<double>& angle, vector<double>& coefficient){
	for(unsigned int i = 1; i < angle.size(); i++){
		unsigned int smallValIndex = i;
		while(smallValIndex > 0 && angle.at(smallValIndex - 1) > angle.at(smallValIndex)){
			swap(angle.at(smallValIndex), angle.at(smallValIndex - 1));
			swap(coefficient.at(smallValIndex), coefficient.at(smallValIndex - 1));

			smallValIndex = smallValIndex - 1;
		}
	}
}

bool angleInRange(const vector<double>& angle, double angleInput){
	if(angleInput >= angle.at(0) && angleInput <= angle.at(angle.size() - 1)){
		return true;
	}
	return false;
}

