#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h> 

// Move cursor to specific coordinates to prevent flickering
void setCursorPosition(int x, int y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

// Hides the blinking cursor for a cleaner look
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int main() {
    time_t rawtime;
    struct tm *pTime;
    bool isrunning = true;
    
    char timeBuffer[50];
    char dateBuffer[100];

    hideCursor();
    system("cls"); 
    
    printf("=== DIGITAL CLOCK ===\n\n");

    while (isrunning) {
        time(&rawtime);
        pTime = localtime(&rawtime);

        // --- 1. Current Time (Standard 12-hour) ---
        strftime(timeBuffer, 50, "%I:%M:%S %p", pTime);

        // --- 2. Full Date (Custom Format) ---
        // %A = Full Day Name (e.g., Wednesday)
        // %d = Day (14)
        // %m = Month (01)
        // %Y = Year (2026)
        // %I:%M:%S %p = 12-hour time
        strftime(dateBuffer, 100, "%A %d-%m-%Y %I:%M:%S %p", pTime);

        setCursorPosition(0, 2); 

        printf("Current Time: %s\n", timeBuffer);
        printf("Full Date   : %s    ", dateBuffer); // Spaces at end to clear old text

        Sleep(1000); 
    }

    return 0;
}