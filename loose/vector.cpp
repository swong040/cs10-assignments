// FIXME - VECTOR LIBRARY
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector<double>& userInput)
{
    double userDouble = 0.0;
    unsigned int i = 0;
    
    cout << "Enter numbers to populate the vector ";
    cout << "(enter any other character to end user input): "; 
    
    while (cin >> userDouble) {
        //(3) FIXME - Add numbers to vector
        userInput.push_back(userDouble);
    }
    cout << endl; 
    
    cout << "You entered: ";
    for(i = 0; i < userInput.size(); i++){
        cout << userInput.at(i) << " ";
    }
    cout << endl;
    
    //return;
}

double meanVector(const vector <double> &v) {
    double sum = 0.0;
    for(unsigned int i = 0; i < v.size(); i++){
        sum = sum + v.at(i);
    }
    double mean = sum / (v.size());
    //(4) FIXME - Calculate mean of vector numbers
    return mean;
}

double varianceVector(double vectorAvg, const vector <double> &v) {
    double sum = 0.0;
    for(unsigned int i = 0; i < v.size(); i++){
        sum += ((v.at(i) - vectorAvg) * (v.at(i) - vectorAvg)); 
    }
    double variance = sum / (v.size());
    //(5) FIXME - Calculate variance of vector numbers
    return variance;
}

double standardDeviationForVariance(double vectorVariance) {
    double stdDev = sqrt(vectorVariance);
    
    //(6) FIXME - Calculate standard deviation
    return stdDev;
}

int main() {
    //(3) FIXME - Declare vector of doubles
    double avg = 0.0;
    double var = 0.0;
    double stdDev = 0.0;
    vector<double> userInput;
    
    //(3) FIXME - Call fillVector() function
    fillVector(userInput);
    
    //(3) FIXME - Print vector values (use i variable)
    
    //(4) FIXME - Call meanVector() function
    avg = meanVector(userInput);
    //(5) FIXME - Call varianceVector() function
    var = varianceVector(avg, userInput);
    //(6) FIXME - Call standardDeviationForVariance() function
    stdDev = standardDeviationForVariance(var);
    
    cout << "The mean is: " << avg << endl;
    cout << "The variance is: " << var << endl;
    cout << "The standard deviation is: " << stdDev << endl;
    
    return 0;
}