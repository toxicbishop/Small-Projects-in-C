#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CURRENCIES 15

// Currency structure
typedef struct {
    char code[4];
    char name[30];
    double rateToUSD;  // Conversion rate to USD
    char symbol[5];
} Currency;

// Function prototypes
void initializeCurrencies(Currency currencies[]);
void displayMenu();
void displayCurrencies(Currency currencies[]);
void convertCurrency(Currency currencies[]);
void quickConvert(Currency currencies[]);
void showExchangeRates(Currency currencies[]);
void clearScreen();
int findCurrencyIndex(Currency currencies[], const char* code);
double convertToUSD(double amount, double rate);
double convertFromUSD(double amount, double rate);

int main() {
    Currency currencies[MAX_CURRENCIES];
    initializeCurrencies(currencies);
    
    int choice;
    
    printf("\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*      💱 CURRENCY CONVERTER 💱                *\n");
    printf("*      Real-time Foreign Exchange              *\n");
    printf("*                                               *\n");
    printf("*************************************************\n\n");
    
    printf("Press Enter to continue...");
    getchar();
    
    while (1) {
        clearScreen();
        displayMenu();
        
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\n❌ Invalid input! Press Enter to continue...");
            getchar();
            continue;
        }
        getchar();
        
        if (choice == 5) {
            printf("\n👋 Thank you for using Currency Converter! Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                convertCurrency(currencies);
                break;
            case 2:
                quickConvert(currencies);
                break;
            case 3:
                displayCurrencies(currencies);
                printf("\nPress Enter to continue...");
                getchar();
                break;
            case 4:
                showExchangeRates(currencies);
                printf("\nPress Enter to continue...");
                getchar();
                break;
            default:
                printf("\n❌ Invalid choice! Please select 1-5.\n");
                printf("Press Enter to continue...");
                getchar();
        }
    }
    
    return 0;
}

void initializeCurrencies(Currency currencies[]) {
    // Initialize with current approximate exchange rates (as of 2024)
    // Note: In a real application, these would be fetched from an API
    
    strcpy(currencies[0].code, "USD");
    strcpy(currencies[0].name, "US Dollar");
    strcpy(currencies[0].symbol, "$");
    currencies[0].rateToUSD = 1.0;
    
    strcpy(currencies[1].code, "EUR");
    strcpy(currencies[1].name, "Euro");
    strcpy(currencies[1].symbol, "€");
    currencies[1].rateToUSD = 1.08;
    
    strcpy(currencies[2].code, "GBP");
    strcpy(currencies[2].name, "British Pound");
    strcpy(currencies[2].symbol, "£");
    currencies[2].rateToUSD = 1.27;
    
    strcpy(currencies[3].code, "JPY");
    strcpy(currencies[3].name, "Japanese Yen");
    strcpy(currencies[3].symbol, "¥");
    currencies[3].rateToUSD = 0.0067;
    
    strcpy(currencies[4].code, "INR");
    strcpy(currencies[4].name, "Indian Rupee");
    strcpy(currencies[4].symbol, "₹");
    currencies[4].rateToUSD = 0.012;
    
    strcpy(currencies[5].code, "CNY");
    strcpy(currencies[5].name, "Chinese Yuan");
    strcpy(currencies[5].symbol, "¥");
    currencies[5].rateToUSD = 0.14;
    
    strcpy(currencies[6].code, "CAD");
    strcpy(currencies[6].name, "Canadian Dollar");
    strcpy(currencies[6].symbol, "$");
    currencies[6].rateToUSD = 0.74;
    
    strcpy(currencies[7].code, "AUD");
    strcpy(currencies[7].name, "Australian Dollar");
    strcpy(currencies[7].symbol, "$");
    currencies[7].rateToUSD = 0.66;
    
    strcpy(currencies[8].code, "CHF");
    strcpy(currencies[8].name, "Swiss Franc");
    strcpy(currencies[8].symbol, "Fr");
    currencies[8].rateToUSD = 1.13;
    
    strcpy(currencies[9].code, "MXN");
    strcpy(currencies[9].name, "Mexican Peso");
    strcpy(currencies[9].symbol, "$");
    currencies[9].rateToUSD = 0.058;
    
    strcpy(currencies[10].code, "BRL");
    strcpy(currencies[10].name, "Brazilian Real");
    strcpy(currencies[10].symbol, "R$");
    currencies[10].rateToUSD = 0.20;
    
    strcpy(currencies[11].code, "KRW");
    strcpy(currencies[11].name, "South Korean Won");
    strcpy(currencies[11].symbol, "₩");
    currencies[11].rateToUSD = 0.00075;
    
    strcpy(currencies[12].code, "RUB");
    strcpy(currencies[12].name, "Russian Ruble");
    strcpy(currencies[12].symbol, "₽");
    currencies[12].rateToUSD = 0.011;
    
    strcpy(currencies[13].code, "AED");
    strcpy(currencies[13].name, "UAE Dirham");
    strcpy(currencies[13].symbol, "د.إ");
    currencies[13].rateToUSD = 0.27;
    
    strcpy(currencies[14].code, "SAR");
    strcpy(currencies[14].name, "Saudi Riyal");
    strcpy(currencies[14].symbol, "﷼");
    currencies[14].rateToUSD = 0.27;
}

void displayMenu() {
    printf("\n");
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║                                               ║\n");
    printf("║       💱 CURRENCY CONVERTER MENU 💱          ║\n");
    printf("║                                               ║\n");
    printf("╚═══════════════════════════════════════════════╝\n\n");
    printf("  1. 💰 Convert Currency\n");
    printf("  2. ⚡ Quick Conversion (USD Base)\n");
    printf("  3. 📋 View All Currencies\n");
    printf("  4. 📊 Exchange Rate Table\n");
    printf("  5. 🚪 Exit\n\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

void displayCurrencies(Currency currencies[]) {
    printf("\n💰 AVAILABLE CURRENCIES\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    printf("%-6s %-25s %-8s %s\n", "Code", "Currency Name", "Symbol", "Rate to USD");
    printf("────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < MAX_CURRENCIES; i++) {
        printf("%-6s %-25s %-8s %.6f\n", 
               currencies[i].code,
               currencies[i].name,
               currencies[i].symbol,
               currencies[i].rateToUSD);
    }
}

void convertCurrency(Currency currencies[]) {
    char fromCode[4], toCode[4];
    double amount, result;
    int fromIndex, toIndex;
    
    printf("\n💱 CURRENCY CONVERSION\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    
    printf("Enter source currency code (e.g., USD): ");
    scanf("%3s", fromCode);
    
    // Convert to uppercase
    for (int i = 0; fromCode[i]; i++) {
        fromCode[i] = toupper(fromCode[i]);
    }
    
    fromIndex = findCurrencyIndex(currencies, fromCode);
    if (fromIndex == -1) {
        printf("\n❌ Currency '%s' not found!\n", fromCode);
        printf("Press Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    printf("Enter target currency code (e.g., EUR): ");
    scanf("%3s", toCode);
    
    for (int i = 0; toCode[i]; i++) {
        toCode[i] = toupper(toCode[i]);
    }
    
    toIndex = findCurrencyIndex(currencies, toCode);
    if (toIndex == -1) {
        printf("\n❌ Currency '%s' not found!\n", toCode);
        printf("Press Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    printf("Enter amount: ");
    if (scanf("%lf", &amount) != 1 || amount < 0) {
        printf("\n❌ Invalid amount!\n");
        while (getchar() != '\n');
        printf("Press Enter to continue...");
        getchar();
        return;
    }
    
    // Convert to USD first, then to target currency
    double usdAmount = convertToUSD(amount, currencies[fromIndex].rateToUSD);
    result = convertFromUSD(usdAmount, currencies[toIndex].rateToUSD);
    
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("                 CONVERSION RESULT\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    printf("  %.2f %s (%s)\n", amount, currencies[fromIndex].code, currencies[fromIndex].name);
    printf("           ↓\n");
    printf("  %.2f %s (%s)\n\n", result, currencies[toIndex].code, currencies[toIndex].name);
    printf("  Exchange Rate: 1 %s = %.6f %s\n", 
           currencies[fromIndex].code,
           result / amount,
           currencies[toIndex].code);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void quickConvert(Currency currencies[]) {
    double usdAmount;
    
    printf("\n⚡ QUICK USD CONVERSION\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    printf("Enter USD amount: $");
    
    if (scanf("%lf", &usdAmount) != 1 || usdAmount < 0) {
        printf("\n❌ Invalid amount!\n");
        while (getchar() != '\n');
        printf("Press Enter to continue...");
        getchar();
        return;
    }
    
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("         $%.2f USD converts to:\n", usdAmount);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    
    for (int i = 1; i < MAX_CURRENCIES; i++) {  // Start from 1 to skip USD
        double converted = convertFromUSD(usdAmount, currencies[i].rateToUSD);
        printf("  %-6s %s %-20s: %12.2f %s\n",
               currencies[i].code,
               currencies[i].symbol,
               currencies[i].name,
               converted,
               currencies[i].code);
    }
    
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void showExchangeRates(Currency currencies[]) {
    printf("\n📊 EXCHANGE RATE TABLE (Base: 1 USD)\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    printf("%-6s %-25s %s\n", "Code", "Currency", "1 USD =");
    printf("──────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < MAX_CURRENCIES; i++) {
        if (strcmp(currencies[i].code, "USD") == 0) {
            printf("%-6s %-25s 1.000000\n",
                   currencies[i].code,
                   currencies[i].name);
        } else {
            double rate = 1.0 / currencies[i].rateToUSD;
            printf("%-6s %-25s %.6f\n",
                   currencies[i].code,
                   currencies[i].name,
                   rate);
        }
    }
    
    printf("\n💡 Tip: These are approximate rates for educational purposes.\n");
    printf("    Real-world rates fluctuate constantly!\n");
}

int findCurrencyIndex(Currency currencies[], const char* code) {
    for (int i = 0; i < MAX_CURRENCIES; i++) {
        if (strcmp(currencies[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

double convertToUSD(double amount, double rate) {
    return amount * rate;
}

double convertFromUSD(double amount, double rate) {
    return amount / rate;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
