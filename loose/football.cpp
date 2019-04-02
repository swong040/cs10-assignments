
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string playerName1;
    string playerName2;
    string playerName3;
    
    int yardsGained1;
    int yardsGained2;
    int yardsGained3;
    
    cout << "Enter player 1's name:" << endl;
    cin >> playerName1;
    cout << "Enter player 1's yards gained:" << endl;
    cin >> yardsGained1;
    cout << "Enter player 2's name:" << endl;
    cin >> playerName2; 
    cout << "Enter player 2's yards gained:" << endl;
    cin >> yardsGained2;
    cout << "Enter player 3's name:" << endl;
    cin >> playerName3;
    cout << "Enter player 3's yards gained:" << endl;
    cin >> yardsGained3;
    
    cout << endl;

    cout << "Player 1 - " << playerName1 << ": " << yardsGained1 << endl;
    cout << "Player 2 - " << playerName2 << ": " << yardsGained2 << endl;
    cout << "Player 3 - " << playerName3 << ": " << yardsGained3 << endl;
    
    if((yardsGained1 > yardsGained2) && (yardsGained2 > yardsGained3)) {
        cout << "1. " << playerName1 << ": " << yardsGained1 << endl;
        cout << "2. " << playerName2 << ": " << yardsGained2 << endl;
        cout << "3. " << playerName3 << ": " << yardsGained3 << endl;
    } else if((yardsGained2 > yardsGained3) && (yardsGained3 > yardsGained1)) {
        cout << "1. " << playerName2 << ": " << yardsGained2 << endl;
        cout << "2. " << playerName3 << ": " << yardsGained3 << endl;
        cout << "3. " << playerName1 << ": " << yardsGained1 << endl;
    } else if((yardsGained3 > yardsGained1) && (yardsGained1 > yardsGained2)) {
        cout << "1. " << playerName3 << ": " << yardsGained3 << endl;
        cout << "2. " << playerName1 << ": " << yardsGained1 << endl;
        cout << "3. " << playerName2 << ": " << yardsGained2 << endl;
    } else if((yardsGained1 > yardsGained3) && (yardsGained3 > yardsGained2)) {
        cout << "1. " << playerName1 << ": " << yardsGained1 << endl;
        cout << "2. " << playerName3 << ": " << yardsGained3 << endl;
        cout << "3. " << playerName2 << ": " << yardsGained2 << endl;
    } else if((yardsGained2 > yardsGained1) && (yardsGained1 > yardsGained3)) {
        cout << "1. " << playerName2 << ": " << yardsGained2 << endl;
        cout << "2. " << playerName1 << ": " << yardsGained1 << endl;
        cout << "3. " << playerName3 << ": " << yardsGained3 << endl;
    } else {
        cout << "1. " << playerName3 << ": " << yardsGained3 << endl;
        cout << "2. " << playerName2 << ": " << yardsGained2 << endl;
        cout << "3. " << playerName1 << ": " << yardsGained1 << endl;
    }

    return 0;   
}