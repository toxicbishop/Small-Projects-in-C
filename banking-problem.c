#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <windows.h> 
#include <stdbool.h>

#define MIN_BALANCE 1000.0f
#define PENALTY_FEE 5.0f

// --- Function Prototypes ---
const char* current_time_str(void);
void log_to_file(char *message); 
void format_money_indian(float amount, char *outputBuffer); 
void checkBalance(float balance);
float deposit(float balance, float amount);
float withdraw(float balance, float amount);

int main() {
    // --- STEP 1: ENABLE UTF-8 FOR RUPEE SYMBOL ---
    SetConsoleOutputCP(65001); 
    // Note: If you see a '?' or box, change your Console Font to "Consolas" or "Lucida Console"
    // ---------------------------------------------

    int choice = 0;
    float balance = 0.0f;
    char logBuffer[200]; 

    // Initial Log
    sprintf(logBuffer, "[%s] *** System Started ***\n", current_time_str());
    log_to_file(logBuffer);

    printf("*** Welcome to the Banking System (Indian Format) ***\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
        }

        float amount;
        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance = deposit(balance, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                balance = withdraw(balance, amount);
                break;
            case 4:
                printf("[%s] Exiting......\n", current_time_str());
                sprintf(logBuffer, "[%s] System Exit.\n--------------------------\n", current_time_str());
                log_to_file(logBuffer);
                Sleep(1000); 
                printf("Thank you for using the banking system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// --- UPDATED: Now adds '₹' to the start ---
// Converts 1234567 -> "₹12,34,567.00"
void format_money_indian(float amount, char *outputBuffer) {
    char temp[50];
    char result[50];
    int i, decimal_idx;
    int count = 0;
    bool firstGroupDone = false; 

    // 1. Convert float to string
    sprintf(temp, "%.2f", amount);

    // 2. Find decimal point
    char *dot = strchr(temp, '.');
    decimal_idx = (int)(dot - temp);

    // 3. Save decimal part (.00)
    char decimalPart[10];
    strcpy(decimalPart, dot);

    // 4. Build Integer part BACKWARDS
    int k = 0; 
    
    for (i = decimal_idx - 1; i >= 0; i--) {
        if (temp[i] == '-') {
            result[k++] = '-';
            continue;
        }

        result[k++] = temp[i];
        count++;

        if (i > 0 && temp[i-1] != '-') {
            if (!firstGroupDone) {
                if (count == 3) {
                    result[k++] = ',';
                    count = 0;
                    firstGroupDone = true; 
                }
            } 
            else {
                if (count == 2) {
                    result[k++] = ',';
                    count = 0;
                }
            }
        }
    }
    result[k] = '\0'; 

    // 5. Reverse back to normal
    strrev(result); 

    // 6. Combine: "₹" + Integer + Decimal
    // We print directly to outputBuffer
    sprintf(outputBuffer, "₹%s%s", result, decimalPart);
}

void log_to_file(char *message) {
    FILE *fp = fopen("banking-log.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s", message);
        fclose(fp);
    }
}

void checkBalance(float balance) {
    char msg[200];
    char mBuf[50]; 
    
    format_money_indian(balance, mBuf); 

    printf("[%s] Your current balance is:   %s\n", current_time_str(), mBuf);
    
    sprintf(msg, "[%s] ACTION: Check Balance | Balance: %s\n", current_time_str(), mBuf);
    log_to_file(msg);

    if (balance < 0) {
        printf("Warning: Your account is overdrawn!\n");
    } else if (balance < MIN_BALANCE) {
        char minBuf[50];
        format_money_indian(MIN_BALANCE, minBuf);
        printf("Alert: Balance is below %s. Consider depositing funds.\n", minBuf);
    }
}

float deposit(float balance, float amount) {
    char msg[200];
    char mAmt[50], mBal[50]; 

    if (amount < 0) {
        printf("[%s] Invalid amount.\n", current_time_str());
        return balance;
    }

    balance += amount;

    format_money_indian(amount, mAmt);
    format_money_indian(balance, mBal);

    printf("[%s] Deposited:   %s\n", current_time_str(), mAmt);
    printf("New Balance: %s\n", mBal);

    sprintf(msg, "[%s] ACTION: Deposit       | Amount: +%s | Balance: %s\n", current_time_str(), mAmt, mBal);
    log_to_file(msg);

    return balance;
}

float withdraw(float balance, float amount) {
    char msg[200];
    char mAmt[50], mBal[50];

    if (amount < 0) {
        printf("[%s] Invalid amount.\n", current_time_str());
        return balance;
    }
    
    if (amount > balance) {
        format_money_indian(amount, mAmt);
        printf("[%s] Insufficient funds.\n", current_time_str());
        
        sprintf(msg, "[%s] ERROR:  Withdraw Fail | Amount: -%s | Insufficient Funds\n", current_time_str(), mAmt);
        log_to_file(msg);
        return balance;
    }

    balance -= amount;

    format_money_indian(amount, mAmt);
    format_money_indian(balance, mBal);

    printf("[%s] Successfully withdrew: %s\n", current_time_str(), mAmt);

    sprintf(msg, "[%s] ACTION: Withdraw      | Amount: -%s | Balance: %s\n", current_time_str(), mAmt, mBal);
    log_to_file(msg);

    if (balance < MIN_BALANCE) {
        char mPen[50], mMin[50];
        format_money_indian(PENALTY_FEE, mPen);
        format_money_indian(MIN_BALANCE, mMin);

        printf("\n*** ALERT: Balance is below %s! ***\n", mMin);
        printf("*** Applying penalty charge of %s ***\n", mPen);
        
        balance -= PENALTY_FEE;
        format_money_indian(balance, mBal); 

        sprintf(msg, "[%s] SYSTEM: PENALTY FEE   | Amount: -%s | Reason: Low Balance (<%s)\n", current_time_str(), mPen, mMin);
        log_to_file(msg);
        
        printf("New Balance after penalty: %s\n\n", mBal);
    }

    return balance;
}

const char* current_time_str(void) {
    static char buf[64];
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    if (tm_info) {
        strftime(buf, sizeof(buf), "%I:%M:%S %p", tm_info);
    } else {
        sprintf(buf, "unknown-time");
    }
    return buf;
}