#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

class TicTacToe {
private:
    vector<vector<char>> board;
    int gameMode;
    char currentPlayer;
    
public:
    TicTacToe() : board(3, vector<char>(3, EMPTY)), currentPlayer(PLAYER_X) {
        srand(time(nullptr));
    }
    
    void displayMenu() {
        cout << "\n";
        cout << "*****************************************\n";
        cout << "*                                       *\n";
        cout << "*        TIC-TAC-TOE GAME               *\n";
        cout << "*                                       *\n";
        cout << "*****************************************\n\n";
        
        cout << "Select Game Mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer\n";
        cout << "Enter choice (1 or 2): ";
        
        while (!(cin >> gameMode) || (gameMode != 1 && gameMode != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Enter 1 or 2: ";
        }
        
        cout << "\nBoard positions:\n";
        cout << "  1 | 2 | 3\n";
        cout << "  4 | 5 | 6\n";
        cout << "  7 | 8 | 9\n\n";
        cout << "Press Enter to start...";
        cin.ignore();
        cin.get();
    }
    
    void displayBoard() {
        cout << "\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "     |     |     \n";
        cout << "\n";
    }
    
    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY);
    }
    
    void playerMove(char player) {
        int position;
        int row, col;
        bool validMove = false;
        
        while (!validMove) {
            cout << "Enter position (1-9): ";
            
            if (!(cin >> position)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            
            if (position < 1 || position > 9) {
                cout << "Invalid position! Choose between 1-9.\n";
                continue;
            }
            
            row = (position - 1) / 3;
            col = (position - 1) % 3;
            
            if (isValidMove(row, col)) {
                board[row][col] = player;
                validMove = true;
            } else {
                cout << "Position already taken! Choose another.\n";
            }
        }
    }
    
    void computerMove() {
        // Try to win
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    if (checkWinner() == 2) {
                        return;
                    }
                    board[i][j] = EMPTY;
                }
            }
        }
        
        // Block player from winning
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    if (checkWinner() == 1) {
                        board[i][j] = PLAYER_O;
                        return;
                    }
                    board[i][j] = EMPTY;
                }
            }
        }
        
        // Take center if available
        if (board[1][1] == EMPTY) {
            board[1][1] = PLAYER_O;
            return;
        }
        
        // Take a corner
        int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
        for (int i = 0; i < 4; i++) {
            int row = corners[i][0];
            int col = corners[i][1];
            if (board[row][col] == EMPTY) {
                board[row][col] = PLAYER_O;
                return;
            }
        }
        
        // Take any available spot
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    return;
                }
            }
        }
    }
    
    int checkWinner() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != EMPTY && 
                board[i][0] == board[i][1] && 
                board[i][1] == board[i][2]) {
                return (board[i][0] == PLAYER_X) ? 1 : 2;
            }
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != EMPTY && 
                board[0][j] == board[1][j] && 
                board[1][j] == board[2][j]) {
                return (board[0][j] == PLAYER_X) ? 1 : 2;
            }
        }
        
        // Check diagonals
        if (board[0][0] != EMPTY && 
            board[0][0] == board[1][1] && 
            board[1][1] == board[2][2]) {
            return (board[0][0] == PLAYER_X) ? 1 : 2;
        }
        
        if (board[0][2] != EMPTY && 
            board[0][2] == board[1][1] && 
            board[1][1] == board[2][0]) {
            return (board[0][2] == PLAYER_X) ? 1 : 2;
        }
        
        return 0; // No winner
    }
    
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    void play() {
        displayMenu();
        bool gameOver = false;
        
        while (!gameOver) {
            clearScreen();
            displayBoard();
            
            if (currentPlayer == PLAYER_X) {
                cout << "\nPlayer X's turn\n";
                playerMove(PLAYER_X);
            } else {
                if (gameMode == 1) {
                    cout << "\nPlayer O's turn\n";
                    playerMove(PLAYER_O);
                } else {
                    cout << "\nComputer's turn (O)...\n";
                    computerMove();
                    cout << "Press Enter to continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                }
            }
            
            int winner = checkWinner();
            if (winner != 0) {
                clearScreen();
                displayBoard();
                cout << "\n";
                if (winner == 1) {
                    cout << "🎉 Player X wins! 🎉\n";
                } else {
                    if (gameMode == 1) {
                        cout << "🎉 Player O wins! 🎉\n";
                    } else {
                        cout << "🤖 Computer wins! Better luck next time!\n";
                    }
                }
                gameOver = true;
            } else if (isBoardFull()) {
                clearScreen();
                displayBoard();
                cout << "\n🤝 It's a draw! 🤝\n";
                gameOver = true;
            }
            
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
        
        cout << "\nThanks for playing!\n";
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
