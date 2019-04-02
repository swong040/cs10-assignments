#include <iostream>
#include <cstdlib>
//Include library necessary for rand function

using namespace std;

int main() {
    srand(3333); // Do not change the seed value.
    
    // Declare all necessary variables
    int userInput;
    int score;
    int rolls = 1;
    
    int two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0, eleven = 0, twelve = 0;
    
    cout << "Enter number of times you want to roll a pair of dice: ";
    // Get user input
    cin >> userInput;
    cout << endl;
    
    // Calculate roll counts
    do{
    int dice1 = ((rand() % 6) + 1);
    int dice2 = ((rand() % 6) + 1);
    score = dice1 + dice2;
    ++rolls;
        if(score == 2){
            two += 1;
        } else if(score == 3){
            three += 1;
        } else if(score == 4){
            four += 1;
        } else if(score == 5){
            five += 1;
        } else if(score == 6){
            six += 1;
        } else if(score == 7){
            seven += 1;
        } else if(score == 8){
            eight += 1;
        } else if(score == 9){
            nine += 1;
        } else if(score == 10){
            ten += 1;
        } else if(score == 11){
            eleven += 1;
        } else if(score == 12){
            twelve += 1;
        }
    //cout << score << endl;
    } while(rolls <= userInput);
    
    cout << "# of times each score was rolled" << endl;
    // Output roll count table
        cout << "2: " << two << endl;
        cout << "3: " << three << endl;
        cout << "4: " << four << endl;
        cout << "5: " << five << endl;
        cout << "6: " << six << endl;
        cout << "7: " << seven << endl;
        cout << "8: " << eight << endl;
        cout << "9: " << nine << endl;
        cout << "10: " << ten << endl;
        cout << "11: " << eleven << endl;
        cout << "12: " << twelve << endl;


        
        
    cout << endl;   
    cout << "Probability of rolling each possible score" << endl;
    // Output percentage table
        cout << "2: " << (static_cast<double>(two) / userInput) * 100 << "%" << endl;
        cout << "3: " << (static_cast<double>(three) / userInput) * 100 << "%" << endl;
        cout << "4: " << (static_cast<double>(four) / userInput) * 100 << "%" << endl;
        cout << "5: " << (static_cast<double>(five) / userInput) * 100 << "%" << endl;
        cout << "6: " << (static_cast<double>(six) / userInput) * 100 << "%" << endl;
        cout << "7: " << (static_cast<double>(seven) / userInput) * 100 << "%" << endl;
        cout << "8: " << (static_cast<double>(eight) / userInput) * 100 << "%" << endl;
        cout << "9: " << (static_cast<double>(nine) / userInput) * 100 << "%" << endl;
        cout << "10: " << (static_cast<double>(ten) / userInput) * 100 << "%" << endl;
        cout << "11: " << (static_cast<double>(eleven) / userInput) * 100 << "%" << endl;
        cout << "12: " << (static_cast<double>(twelve) / userInput) * 100 << "%" << endl;
    
    return 0;
}