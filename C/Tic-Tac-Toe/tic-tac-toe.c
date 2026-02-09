#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int checkWinner(char board[3][3]);
int isBoardFull(char board[3][3]);
void playerMove(char board[3][3], char player);
void computerMove(char board[3][3]);
int isValidMove(char board[3][3], int row, int col);
void clearScreen();

int main() {
    char board[3][3];
    int gameMode;
    int gameOver = 0;
    char currentPlayer = PLAYER_X;
    int winner;
    
    srand(time(NULL));
    
    printf("\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*        TIC-TAC-TOE GAME               *\n");
    printf("*                                       *\n");
    printf("*****************************************\n\n");
    
    printf("Select Game Mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &gameMode);
    
    while (gameMode != 1 && gameMode != 2) {
        printf("Invalid choice! Enter 1 or 2: ");
        scanf("%d", &gameMode);
    }
    
    initializeBoard(board);
    
    printf("\nBoard positions:\n");
    printf("  1 | 2 | 3\n");
    printf("  4 | 5 | 6\n");
    printf("  7 | 8 | 9\n\n");
    printf("Press Enter to start...");
    getchar();
    getchar();
    
    while (!gameOver) {
        clearScreen();
        displayBoard(board);
        
        if (currentPlayer == PLAYER_X) {
            printf("\nPlayer X's turn\n");
            playerMove(board, PLAYER_X);
        } else {
            if (gameMode == 1) {
                printf("\nPlayer O's turn\n");
                playerMove(board, PLAYER_O);
            } else {
                printf("\nComputer's turn (O)...\n");
                computerMove(board);
                printf("Press Enter to continue...");
                getchar();
            }
        }
        
        winner = checkWinner(board);
        if (winner != 0) {
            clearScreen();
            displayBoard(board);
            printf("\n");
            if (winner == 1) {
                printf("🎉 Player X wins! 🎉\n");
            } else {
                if (gameMode == 1) {
                    printf("🎉 Player O wins! 🎉\n");
                } else {
                    printf("🤖 Computer wins! Better luck next time!\n");
                }
            }
            gameOver = 1;
        } else if (isBoardFull(board)) {
            clearScreen();
            displayBoard(board);
            printf("\n🤝 It's a draw! 🤝\n");
            gameOver = 1;
        }
        
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void displayBoard(char board[3][3]) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
    printf("\n");
}

int checkWinner(char board[3][3]) {
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

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[3][3], char player) {
    int position;
    int row, col;
    int validMove = 0;
    
    while (!validMove) {
        printf("Enter position (1-9): ");
        scanf("%d", &position);
        
        if (position < 1 || position > 9) {
            printf("Invalid position! Choose between 1-9.\n");
            continue;
        }
        
        row = (position - 1) / 3;
        col = (position - 1) % 3;
        
        if (isValidMove(board, row, col)) {
            board[row][col] = player;
            validMove = 1;
        } else {
            printf("Position already taken! Choose another.\n");
        }
    }
}

void computerMove(char board[3][3]) {
    int row, col;
    
    // Try to win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                if (checkWinner(board) == 2) {
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
                if (checkWinner(board) == 1) {
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
        row = corners[i][0];
        col = corners[i][1];
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

int isValidMove(char board[3][3], int row, int col) {
    return (board[row][col] == EMPTY);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
