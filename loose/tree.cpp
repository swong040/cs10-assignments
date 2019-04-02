#include <iostream>
using namespace std;

int main() {
    int trunkHeight = 0;
    int trunkWidth = 0;
    int leafWidth = 0;
    
    cout << "Enter trunk height: ";
    cin >> trunkHeight;
    cout << "Enter trunk width: ";
    cin >> trunkWidth;
    
    while ((trunkWidth % 2) == 0) {
        cout << "Please enter an odd number for the width " << endl;
        cin >> trunkWidth;
    }
    
    cout << "Enter leaves width: ";
    cin >> leafWidth;
    
    while ((leafWidth % 2) == 0) {
        cout << "Please enter an odd number for the width " << endl;
        cin >> leafWidth;
    }

    cout << endl;

    for(int i = 1; i <= (leafWidth/2 + 1); ++i){
        for(int k = leafWidth/2; k >= i ; --k){
            cout << " ";
        }
        for(int j = 1; j < i * 2; ++j){
            cout << "*";
        }
        cout << endl;
    }
    

    // // Draw leaves
    // cout << "  *  " << endl;
    // cout << " *** " << endl;
    // cout << "*****" << endl;


    for(int i = 1; i <= trunkHeight; ++i){
        for(int j = 1; j <= leafWidth/3 ; ++j){
            cout << " ";
        }
        for(int j = 1; j <= trunkWidth; ++j){
            cout << "*";
        }
        cout << endl;
    }
    // // Draw trunk
    // cout << " *** " << endl;
    // cout << " *** " << endl;
    // cout << " *** " << endl;
    // cout << " *** " << endl;

    return 0;
}