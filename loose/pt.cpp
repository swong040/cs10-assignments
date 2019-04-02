/*
Get from the user the x and y coordinates (doubles) of 2 points and then calculate the distance 
between these points using the Pythagorean theorem.

- First, get from the user the x and y coordinate values for the first point.
- Second, get from the user the x and y coordinate values for the second point.
- Finally, calculate and output the distance between these 2 points, using the Pythagorean theorem.

Recall, the Pythagorean theorem tells us you can calculate the floating-point distance between
two points [(x1, y1) & (x2, y2)] by calculating the square root of (x2 - x1) squared plus (y2 - y1) squared.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    
    cout << "Enter the x and y coordinate values for the first point: " << endl;
    cin >> x1 >> y1;
    
    cout << "Enter the x and y coordinate values for the second point: " << endl;
    cin >> x2 >> y2;
    
    double distancePT = sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
    
    cout << "The distance between the first point and the second point is " << distancePT << endl;
    
    return 0;
}
