#include <iostream>
#include <iomanip>
using namespace std;
int checkWin();
bool checkTie();
void playerSelection();
void printBoard();
bool isMoveValid(int coverValue);
void playerMove(int player, int coverValue);
void result ();
int board[3][3] = {0}; // global array
const int PLAYER1 = 1;
const int PLAYER2 = 4;

int main() {
    int count = 0;
    while ((checkWin() == 0) && (checkTie() == false)){ // code runs while the game is still going
        int currentPlayer;
        if (count % 2 == 0) { // this if chain is specifically for output to console
            currentPlayer = 1;
        } else {
            currentPlayer = 2;
        }
        int userInput;
        do {
            printBoard();
            cout << "Player " << currentPlayer << ": ";
            cin >> userInput;
        } while (!isMoveValid(userInput)); // forces player to make a valid move
        if (count % 2 == 0) { //specifically for input into playerMove function
            currentPlayer = PLAYER1;
        } else {
            currentPlayer = PLAYER2;
        }
        playerMove(currentPlayer, userInput);
        count++;
    }
    result();
}


void printBoard(){
    
    for (int i = 0; i < 3; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << setw(3);
            
            if (::board[i][j] == PLAYER1) { // 1 represents X
                cout << "X";
            } else if (::board[i][j] == PLAYER2) { // 4 represents O
                cout << "O";
            } else {
                cout << (3*i+j); // prints out board "cover", user will input values of board cover in player selection
            }
        }
    }
    cout << endl;
}
bool isMoveValid(int coverValue){
    if(coverValue > 8 || coverValue < 0) { // prevents invalid player input
        return false;
    }
    // converts cover value into board value to determine if the spot has been used already
    int i = coverValue / 3;
    int j = coverValue % 3;
    return ::board[i][j] == 0;
}
void playerMove(int player, int coverValue) {
   // assigns player 1 or 2 assigned value to boardValue so the board displays X or O
    int i = coverValue / 3;
    int j = coverValue % 3;
    ::board[i][j] = player;
}
int checkWin() {
    // adds up sum of rows and checks sum to determine win
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++){
            sum += board[i][j];
        }
        
        if (sum == (3 * PLAYER1)) {
            return PLAYER1;
        } else if (sum == (3*PLAYER2)) {
            return PLAYER2;
        }
    }
    // adds up sum of columns and checks sum to determine win
    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i< 3; i++){
            sum += board[i][j];
        }
        if (sum == (3 * PLAYER1)) {
            return PLAYER1;
        } else if (sum == (3*PLAYER2)) {
            return PLAYER2;
        }
    }
    
   // checks diagnols for win
    if (board[0][0] == PLAYER1) {
        if (board[1][1] == PLAYER1) {
            if (board[2][2] == PLAYER1) {
                return PLAYER1;
            }
        }
    }
    if (board[0][0] == PLAYER2) {
        if (board[1][1] == PLAYER2) {
            if (board[2][2] == PLAYER2) {
                return PLAYER2;
            }
        }
    }
    if (board[0][2] == PLAYER1) {
        if (board[1][1] == PLAYER1) {
            if (board[2][0] == PLAYER1) {
                return PLAYER1;
            }
        }
    }
    if (board[0][2] == PLAYER2) {
        if (board[1][1] == PLAYER2) {
            if (board[2][0] == PLAYER2) {
                return PLAYER2;
            }
        }
    }
    
    return 0;
}
bool checkTie() {
    // checks for tie by adding up sum of entire board to see how many spaces have been used and checking to see if win has been achieved yet
    int sum = 0;
    int win = checkWin();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            sum += board[i][j];
        }
        if ((win == 0) && sum == (4*PLAYER1 + 4*PLAYER2)) {
            return true;
        }
    }
    return false;
}
void result () {
    // Prints result of game based on checkWin() output
    if (checkWin() == PLAYER1) {
        cout << "Player 1 Wins" << endl;
    } else if (checkWin() == PLAYER2){
        cout << "Player 2 Wins" << endl;
    } else {
        cout << "It is a tie" << endl;
    }
}


