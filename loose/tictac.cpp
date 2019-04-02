#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}

/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    v.at(0) = 'a';
    for(unsigned int i = 1 ; i < v.size(); i++){
        v.at(i) = v.at(i - 1) + 1;
    }

    // TODO: implement function
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    
    unsigned int vecIndex = boardPosition - 'a';
    // TODO: implement function
    return vecIndex;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    if(static_cast<unsigned int>(positionIndex) < gameBoard.size() && positionIndex > -1){
        if(gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O'){
            return true;
        }
    }
    // TODO: implement function
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {
    
    // TODO: implement function
    char boardPosition = ' ';

    do{
        cout << "Please choose a position: ";
        cin >> boardPosition;
        cout << endl;

        validPlacement(gameBoard, convertPosition(boardPosition));

    } while(validPlacement(gameBoard, convertPosition(boardPosition)) == false);

    return convertPosition(boardPosition);
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {
    //horizontal - good 
    for(int i = 0; i < 3; i++){
        if(gameBoard.at(i * 3) == 'X' && gameBoard.at(i * 3 + 1) == 'X' && gameBoard.at(i * 3 + 2) == 'X'){
            return true;
        } if(gameBoard.at(i * 3) == 'O' && gameBoard.at(i * 3 + 1) == 'O' && gameBoard.at(i * 3 + 2) == 'O'){
            return true;
        }
    }
    //vertical
    for(int i = 0; i < 3; i++){
        if(gameBoard.at(i) == 'X' && gameBoard.at(i + 3) == 'X' && gameBoard.at(i + 6) == 'X'){
            return true;
        } if(gameBoard.at(i) == 'O' && gameBoard.at(i + 3) == 'O' && gameBoard.at(i + 6) == 'O'){
            return true;
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(gameBoard.at(i + 1) == 'X' && gameBoard.at(i + 3 + 1) == 'X' && gameBoard.at(i + 6 + 1) == 'X'){
            return true;
        } if(gameBoard.at(i + 1) == 'O' && gameBoard.at(i + 3 + 1) == 'O' && gameBoard.at(i + 6 + 1) == 'O'){
            return true;
        }
    }
    //diagonal
    if(gameBoard.at(0) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(8) == 'X'){
        return true;
    } if(gameBoard.at(0) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(8) == 'O'){
        return true;
    }
    
    if(gameBoard.at(2) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(6) == 'X'){
        return true;
    } if(gameBoard.at(2) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(6) == 'O'){
        return true;
    }
    // TODO: implement function
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
    for(unsigned int i = 0; i < gameBoard.size(); i++){
        if(gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O'){
            return false;
        }
    }
    // TODO: implement function
    return true;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

    /// TODO: Initialize board to empty state
    initVector(gameBoard);
    /// TODO: Display empty board
    drawBoard(gameBoard);

    /// TODO: Play until game is over
    while(gameWon(gameBoard) != true && boardFull(gameBoard) != true){
        /// TODO: Get a play
        curPlay = getPlay(gameBoard);
        /// TODO: Set the play on the board
        /// TODO: Switch the turn to the other player
        if(whosTurn == PLAYER1){
            gameBoard.at(curPlay) = 'X';
            whosTurn = PLAYER2;
        } else{
            gameBoard.at(curPlay) = 'O';
            whosTurn = PLAYER1;
        }

        /// TODO: Output the updated board
        drawBoard(gameBoard);
    }

    /// TODO: Determine winner and output appropriate message
    if(gameWon(gameBoard) == true && whosTurn == PLAYER1){
        cout << "PLAYER 2 WINS!" << endl;
    } else if(gameWon(gameBoard) == true && whosTurn == PLAYER2){
        cout << "PLAYER 1 WINS!" << endl;
    } else {
        cout << "No one wins." << endl;
    }
    return 0;
}