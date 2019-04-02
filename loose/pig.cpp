#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;


//FIXME (1): Implement the printIntro function
string printIntro(){
    string intro = "Welcome to the dice game Pig!\nThe objective is to be first to score 100 points.";
    cout << intro << endl << endl;
    
    return intro;
}
//FIXME (4, 5, 6): Implement the humanTurn function
int humanTurn(string playerName, int playerScore){
    int roll = 0;
    int prevScore = playerScore;
    char userInput = ' ';
    do{
        roll = (rand() % 6) + 1;
        playerScore = playerScore + roll;
        cout << playerName << endl;
        if(roll == 1){
            cout << "You rolled a " << roll << " (PIG!)" << endl 
                 << "Your turn is over" << endl 
                 << "Your score: " << prevScore << endl;
            playerScore--;
            playerScore = prevScore;
            cout << endl;
        } else {
            cout << "You rolled a " << roll << endl
                 << "Your score: " << playerScore << endl;
                if(playerScore >= WINNING_SCORE){
                    //cout << endl;
                    return playerScore;
                }
            cout << "Do you want to roll again? (y/n): ";
            cin >> userInput;
            cout << endl;
        }
    }while((userInput != 'n') && (roll != 1) && (playerScore < WINNING_SCORE));
    return playerScore;
}
int main() {
    srand(4444);

    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    // FIXME (2): get names of players
    cout << "Player 1 - Enter your name: ";
    cin >> player1name;
    cout << endl;
    cout << "Player 2 - Enter your name: ";
    cin >> player2name;
    cout << endl;


    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
        }
        else {
            player2score = humanTurn(player2name, player2score);
        }

        //FIXME (3): switch whose turn it is
        if(turn == PLAYER1){
            turn = PLAYER2;
        } else {
            turn = PLAYER1;
        }
    }

    // FIXME (7): Output who won the game.
    string winner;
    if(player1score >= WINNING_SCORE){
        winner = player1name;
    } else {
        winner = player2name;
    }
    cout << endl << winner << " wins!" << endl;

    return 0;
}