// ...existing code...
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // For Sleep
int getComputer_Choice();
int getUser_Choice();
void CheckWinner(int userchoice, int computerchoice);
const char* choiceToString(int choice);
int main() {
    srand((unsigned int)time(NULL)); // Seed for random number generation
    printf("***Welcome to Rock-Paper-Scissors Game***\n");

    int userchoice = getUser_Choice();
    int computerchoice = getComputer_Choice();
    printf("You chose: %s\n", choiceToString(userchoice));
        printf("Computer chose: %s\n", choiceToString(computerchoice));
    
        CheckWinner(userchoice, computerchoice);
    
        return 0;
    }

int getComputer_Choice() {
    int min = 1;
    int max = 3;
    int computerchoice = (rand() % (max - min + 1)) + min; // Random number between 1 and 3
    printf("Computer is making a choice...\n");
    Sleep(1000); // Simulate thinking time (milliseconds)
    printf("Computer has made its choice.\n");
    Sleep(500); // Brief pause before revealing choice
    return computerchoice;
}
int getUser_Choice() {
    int userchoice;
    do {
        printf("Enter your choice\n");
        printf("(1 for Rock, 2 for Paper, 3 for Scissors): ");
        if (scanf("%d", &userchoice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            userchoice = 0;
        }
        if (userchoice < 1 || userchoice > 3) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (userchoice < 1 || userchoice > 3);
    return userchoice;
}
void CheckWinner(int userchoice, int computerchoice) {
    if (userchoice == computerchoice) {
        printf("It's a tie!\n");
    }
    else if ((userchoice == 1 && computerchoice == 3) ||
             (userchoice == 2 && computerchoice == 1) ||
             (userchoice == 3 && computerchoice == 2)) {
        printf("You win!\n");
    }
    else {
        printf("Computer wins!\n");
    }
}

const char* choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}