#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Currency {
private:
    string code;
    string name;
    string symbol;
    double rateToUSD;
    
public:
    Currency(string c, string n, string s, double r) 
        : code(c), name(n), symbol(s), rateToUSD(r) {}
    
    string getCode() const { return code; }
    string getName() const { return name; }
    string getSymbol() const { return symbol; }
    double getRate() const { return rateToUSD; }
    
    double convertToUSD(double amount) const {
        return amount * rateToUSD;
    }
    
    double convertFromUSD(double amount) const {
        return amount / rateToUSD;
    }
    
    void display() const {
        cout << left << setw(6) << code 
             << setw(25) << name  
             << setw(8) << symbol 
             << fixed << setprecision(6) << rateToUSD << endl;
    }
};

class CurrencyConverter {
private:
    vector<Currency> currencies;
    
    void initializeCurrencies() {
        // Initialize with current approximate exchange rates
        currencies.push_back(Currency("USD", "US Dollar", "$", 1.0));
        currencies.push_back(Currency("EUR", "Euro", "€", 1.08));
        currencies.push_back(Currency("GBP", "British Pound", "£", 1.27));
        currencies.push_back(Currency("JPY", "Japanese Yen", "¥", 0.0067));
        currencies.push_back(Currency("INR", "Indian Rupee", "₹", 0.012));
        currencies.push_back(Currency("CNY", "Chinese Yuan", "¥", 0.14));
        currencies.push_back(Currency("CAD", "Canadian Dollar", "$", 0.74));
        currencies.push_back(Currency("AUD", "Australian Dollar", "$", 0.66));
        currencies.push_back(Currency("CHF", "Swiss Franc", "Fr", 1.13));
        currencies.push_back(Currency("MXN", "Mexican Peso", "$", 0.058));
        currencies.push_back(Currency("BRL", "Brazilian Real", "R$", 0.20));
        currencies.push_back(Currency("KRW", "South Korean Won", "₩", 0.00075));
        currencies.push_back(Currency("RUB", "Russian Ruble", "₽", 0.011));
        currencies.push_back(Currency("AED", "UAE Dirham", "د.إ", 0.27));
        currencies.push_back(Currency("SAR", "Saudi Riyal", "﷼", 0.27));
    }
    
    Currency* findCurrency(const string& code) {
        string upperCode = code;
        transform(upperCode.begin(), upperCode.end(), upperCode.begin(), ::toupper);
        
        for (auto& curr : currencies) {
            if (curr.getCode() == upperCode) {
                return &curr;
            }
        }
        return nullptr;
    }
    
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    void displayMenu() {
        cout << "\n";
        cout << "╔═══════════════════════════════════════════════╗" << endl;
        cout << "║                                               ║" << endl;
        cout << "║       💱 CURRENCY CONVERTER MENU 💱          ║" << endl;
        cout << "║                                               ║" << endl;
        cout << "╚═══════════════════════════════════════════════╝" << endl << endl;
        cout << "  1. 💰 Convert Currency" << endl;
        cout << "  2. ⚡ Quick Conversion (USD Base)" << endl;
        cout << "  3. 🔄 Reverse Conversion Calculator" << endl;
        cout << "  4. 📋 View All Currencies" << endl;
        cout << "  5. 📊 Exchange Rate Table" << endl;
        cout << "  6. 🌍 Popular Currency Pairs" << endl;
        cout << "  7. 🚪 Exit" << endl << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
    }
    
    void convertCurrency() {
        string fromCode, toCode;
        double amount;
        
        cout << "\n💱 CURRENCY CONVERSION" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        
        cout << "Enter source currency code (e.g., USD): ";
        cin >> fromCode;
        
        Currency* fromCurr = findCurrency(fromCode);
        if (!fromCurr) {
            cout << "\n❌ Currency '" << fromCode << "' not found!" << endl;
            return;
        }
        
        cout << "Enter target currency code (e.g., EUR): ";
        cin >> toCode;
        
        Currency* toCurr = findCurrency(toCode);
        if (!toCurr) {
            cout << "\n❌ Currency '" << toCode << "' not found!" << endl;
            return;
        }
        
        cout << "Enter amount: ";
        if (!(cin >> amount) || amount < 0) {
            cout << "\n❌ Invalid amount!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        
        // Convert through USD
        double usdAmount = fromCurr->convertToUSD(amount);
        double result = toCurr->convertFromUSD(usdAmount);
        
        cout << "\n";
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "                 CONVERSION RESULT" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        cout << "  " << fixed << setprecision(2) << amount << " " 
             << fromCurr->getCode() << " (" << fromCurr->getName() << ")" << endl;
        cout << "           ↓" << endl;
        cout << "  " << fixed << setprecision(2) << result << " " 
             << toCurr->getCode() << " (" << toCurr->getName() << ")" << endl << endl;
        cout << "  Exchange Rate: 1 " << fromCurr->getCode() << " = " 
             << setprecision(6) << (result / amount) << " " << toCurr->getCode() << endl;
        cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    }
    
    void quickConvertUSD() {
        double usdAmount;
        
        cout << "\n⚡ QUICK USD CONVERSION" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        cout << "Enter USD amount: $";
        
        if (!(cin >> usdAmount) || usdAmount < 0) {
            cout << "\n❌ Invalid amount!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        
        cout << "\n";
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "         $" << fixed << setprecision(2) << usdAmount << " USD converts to:" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        
        for (const auto& curr : currencies) {
            if (curr.getCode() != "USD") {
                double converted = curr.convertFromUSD(usdAmount);
                cout << "  " << left << setw(6) << curr.getCode()
                     << curr.getSymbol() << " " << setw(20) << curr.getName()
                     << ": " << right << setw(12) << fixed << setprecision(2) 
                     << converted << " " << curr.getCode() << endl;
            }
        }
        
        cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    }
    
    void reverseConversion() {
        string fromCode, toCode;
        double targetAmount;
        
        cout << "\n🔄 REVERSE CONVERSION CALCULATOR" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "   (Calculate how much you need to get desired amount)" << endl << endl;
        
        cout << "Enter source currency code: ";
        cin >> fromCode;
        
        Currency* fromCurr = findCurrency(fromCode);
        if (!fromCurr) {
            cout << "\n❌ Currency '" << fromCode << "' not found!" << endl;
            return;
        }
        
        cout << "Enter target currency code: ";
        cin >> toCode;
        
        Currency* toCurr = findCurrency(toCode);
        if (!toCurr) {
            cout << "\n❌ Currency '" << toCode << "' not found!" << endl;
            return;
        }
        
        cout << "Enter desired amount in " << toCurr->getCode() << ": ";
        if (!(cin >> targetAmount) || targetAmount < 0) {
            cout << "\n❌ Invalid amount!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        
        // Reverse calculation
        double usdAmount = toCurr->convertToUSD(targetAmount);
        double needed = fromCurr->convertFromUSD(usdAmount);
        
        cout << "\n";
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "              REVERSE CALCULATION" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        cout << "  To get: " << fixed << setprecision(2) << targetAmount 
             << " " << toCurr->getCode() << endl;
        cout << "  You need: " << needed << " " << fromCurr->getCode() << endl;
        cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    }
    
    void displayAllCurrencies() {
        cout << "\n💰 AVAILABLE CURRENCIES" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        cout << left << setw(6) << "Code" 
             << setw(25) << "Currency Name" 
             << setw(8) << "Symbol" 
             << "Rate to USD" << endl;
        cout << "────────────────────────────────────────────────────────" << endl;
        
        for (const auto& curr : currencies) {
            curr.display();
        }
    }
    
    void showExchangeRates() {
        cout << "\n📊 EXCHANGE RATE TABLE (Base: 1 USD)" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        cout << left << setw(6) << "Code" << setw(25) << "Currency" << "1 USD =" << endl;
        cout << "──────────────────────────────────────────────────────" << endl;
        
        for (const auto& curr : currencies) {
            double rate = (curr.getCode() == "USD") ? 1.0 : (1.0 / curr.getRate());
            cout << left << setw(6) << curr.getCode()
                 << setw(25) << curr.getName()
                 << fixed << setprecision(6) << rate << endl;
        }
        
        cout << "\n💡 Tip: These are approximate rates for educational purposes." << endl;
        cout << "    Real-world rates fluctuate constantly!" << endl;
    }
    
    void showPopularPairs() {
        cout << "\n🌍 POPULAR CURRENCY PAIRS" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
        
        struct Pair { string from; string to; string description; };
        vector<Pair> popularPairs = {
            {"USD", "EUR", "US Dollar to Euro"},
            {"USD", "GBP", "US Dollar to British Pound"},
            {"USD", "JPY", "US Dollar to Japanese Yen"},
            {"EUR", "GBP", "Euro to British Pound"},
            {"USD", "INR", "US Dollar to Indian Rupee"},
            {"USD", "CNY", "US Dollar to Chinese Yuan"},
            {"GBP", "EUR", "British Pound to Euro"},
            {"USD", "CAD", "US Dollar to Canadian Dollar"}
        };
        
        for (const auto& pair : popularPairs) {
            Currency* fromCurr = findCurrency(pair.from);
            Currency* toCurr = findCurrency(pair.to);
            
            if (fromCurr && toCurr) {
                double usd = fromCurr->convertToUSD(1.0);
                double rate = toCurr->convertFromUSD(usd);
                
                cout << "  " << pair.description << endl;
                cout << "  1 " << pair.from << " = " << fixed << setprecision(4) 
                     << rate << " " << pair.to << endl << endl;
            }
        }
    }
    
public:
    CurrencyConverter() {
        initializeCurrencies();
    }
    
    void run() {
        cout << "\n";
        cout << "*************************************************" << endl;
        cout << "*                                               *" << endl;
        cout << "*      💱 CURRENCY CONVERTER 💱                *" << endl;
        cout << "*      Real-time Foreign Exchange              *" << endl;
        cout << "*                                               *" << endl;
        cout << "*************************************************" << endl << endl;
        
        cout << "Press Enter to continue...";
        cin.get();
        
        int choice;
        
        while (true) {
            clearScreen();
            displayMenu();
            
            cout << "Enter your choice (1-7): ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n❌ Invalid input! Press Enter to continue...";
                cin.get();
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (choice == 7) {
                cout << "\n👋 Thank you for using Currency Converter! Goodbye!" << endl;
                break;
            }
            
            switch (choice) {
                case 1:
                    convertCurrency();
                    break;
                case 2:
                    quickConvertUSD();
                    break;
                case 3:
                    reverseConversion();
                    break;
                case 4:
                    displayAllCurrencies();
                    break;
                case 5:
                    showExchangeRates();
                    break;
                case 6:
                    showPopularPairs();
                    break;
                default:
                    cout << "\n❌ Invalid choice! Please select 1-7." << endl;
            }
            
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
};

int main() {
    CurrencyConverter converter;
    converter.run();
    return 0;
}
