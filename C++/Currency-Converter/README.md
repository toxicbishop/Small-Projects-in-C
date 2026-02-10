# Currency Converter (C++)

A comprehensive currency converter with Object-Oriented Programming, supporting 15 major world currencies with advanced features!

## 💰 Features

### Core Features

- **15 Major Currencies** - USD, EUR, GBP, JPY, INR, CNY, CAD, AUD, CHF, MXN, BRL, KRW, RUB, AED, SAR
- **Bi-directional Conversion** - Convert between any two currencies
- **Quick USD Conversion** - Instantly see USD converted to all currencies
- **Reverse Calculation** - Calculate how much you need to get desired amount
- **Exchange Rate Table** - View all exchange rates at a glance
- **Popular Currency Pairs** - Quick access to common conversions

### C++ Advantages

- **OOP Design** - Clean `Currency` and `Converter Converter` classes
- **STL Containers** - Using `vector` for dynamic currency management
- **Type Safety** - Strong typing with getters
- **Encapsulation** - Private data with public methods
- **Modern C++** - Using STL algorithms and features

## 🌍 Supported Currencies

| Code | Currency | Symbol | Region |
|------|----------|--------|--------|
| USD | US Dollar | $ | United States |
| EUR | Euro | € | European Union |
| GBP | British Pound | £ | United Kingdom |
| JPY | Japanese Yen | ¥ | Japan |
| INR | Indian Rupee | ₹ | India |
| CNY | Chinese Yuan | ¥ | China |
| CAD | Canadian Dollar | $ | Canada |
| AUD | Australian Dollar | $ | Australia |
| CHF | Swiss Franc | Fr | Switzerland |
| MXN | Mexican Peso | $ | Mexico |
| BRL | Brazilian Real | R$ | Brazil |
| KRW | South Korean Won | ₩ | South Korea |
| RUB | Russian Ruble | ₽ | Russia |
| AED | UAE Dirham | د.إ | UAE |
| SAR | Saudi Riyal | ﷼ | Saudi Arabia |

## How to Use

### 1. Compile the Program

```bash
g++ currency-converter.cpp -o currency-converter
```

### 2. Run the Program

```bash
./currency-converter        # Linux/Mac
currency-converter.exe      # Windows
```

### 3. Enhanced Menu Options

```
  1. 💰 Convert Currency
  2. ⚡ Quick Conversion (USD Base)
  3. 🔄 Reverse Conversion Calculator
  4. 📋 View All Currencies
  5. 📊 Exchange Rate Table
  6. 🌍 Popular Currency Pairs
  7. 🚪 Exit
```

## 🆕 Advanced Features

### Reverse Conversion

**Unique to C++ version!** Calculate how much you need in one currency to get a specific amount in another.

```
Scenario: You want exactly 100 EUR. How much USD do you need?

Enter source currency: USD
Enter target currency: EUR
Enter desired amount in EUR: 100

REVERSE CALCULATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  To get: 100.00 EUR
  You need: 108.00 USD
```

### Popular Currency Pairs

Quick view of the most commonly traded currency pairs:

```
🌍 POPULAR CURRENCY PAIRS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  US Dollar to Euro
  1 USD = 0.9259 EUR

  US Dollar to British Pound
  1 USD = 0.7874 GBP

  US Dollar to Japanese Yen
  1 USD = 149.2537 JPY

  ... and more
```

## Usage Examples

### Example 1: Standard Conversion

```
Enter source currency code: GBP
Enter target currency code: JPY
Enter amount: 50

CONVERSION RESULT
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  50.00 GBP (British Pound)
           ↓
  9464.97 JPY (Japanese Yen)

  Exchange Rate: 1 GBP = 189.299410 JPY
```

### Example 2: Reverse Calculation

```
You're traveling and need exactly 50,000 JPY in Japan.
How much GBP should you exchange?

Enter source currency: GBP
Enter target currency: JPY
Enter desired amount in JPY: 50000

To get: 50000.00 JPY
You need: 264.13 GBP
```

### Example 3: Quick USD Snapshot

```
Enter USD amount: $1000

$1000.00 USD converts to:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  EUR    € Euro                  :       925.93 EUR
  GBP    £ British Pound         :       787.40 GBP
  JPY    ¥ Japanese Yen          :    149253.73 JPY
  INR    ₹ Indian Rupee          :     83333.33 INR
  ... and 10 more currencies
```

## Code Structure

```cpp
class Currency {
private:
    string code;
    string name;
    string symbol;
    double rateToUSD;
    
public:
    Currency(string c, string n, string s, double r);
    double convertToUSD(double amount) const;
    double convertFromUSD(double amount) const;
    void display() const;
    // Getters for all properties
};

class CurrencyConverter {
private:
    vector<Currency> currencies;
    
    void initializeCurrencies();
    Currency* findCurrency(const string& code);
    void displayMenu();
    void convertCurrency();
    void quickConvertUSD();
    void reverseConversion();
    void showPopularPairs();
    
public:
    CurrencyConverter();
    void run();
};
```

## 📊 Technical Details

### OOP Design Benefits

1. **Encapsulation**
   - Currency data is private
   - Access through public methods
   - Prevents invalid state

2. **Reusability**
   - Currency class can be reused
   - Easy to extend functionality
   - Clean separation of concerns

3. **Maintainability**
   - Changes isolated to classes
   - Easy to add new currencies
   - Simple to test components

### Conversion Algorithm

All conversions use USD as intermediary:

```cpp
// Converting from Currency A to Currency B
double usdAmount = currencyA.convertToUSD(amount);
double result = currencyB.convertFromUSD(usdAmount);
```

## Learning Concepts

- **Object-Oriented Programming** - Classes, objects, encapsulation
- **STL Containers** - `vector` for dynamic arrays
- **STL Algorithms** - `transform` for string manipulation
- **String Handling** - C++ `string` class
- **Const Correctness** - `const` methods and parameters
- **Memory Management** - Automatic with RAII
- **Input Validation** - Using `cin` with error handling
- **Precision Formatting** - `iomanip` for decimal display

## Customization

### Adding a New Currency

1. Update `initializeCurrencies()`:

```cpp
currencies.push_back(Currency("THB", "Thai Baht", "฿", 0.029));
```

1. That's it! The vector automatically resizes!

### Adding New Features

Easy to extend with OOP:

```cpp
class CurrencyConverter {
    // Add new method
    void showHistoricalRates() {
        // Implementation
    }
};
```

## Real-World Applications

- **Forex Trading Platforms** - Professional currency exchange
- **E-commerce Sites** - Multi-currency pricing
- **Travel Apps** - Budget calculators
- **Banking Systems** - International transfers
- **Investment Portfolios** - Multi-currency tracking

## Performance

- **Fast Lookups** - O(n) search through currencies
- **Memory Efficient** - Only stores necessary data
- **Scalable** - Easy to add more currencies
- **Type Safe** - Compile-time error checking

## Comparison: C vs C++

| Feature | C Version | C++ Version |
|---------|-----------|-------------|
| Menu Options | 5 | 7 |
| Reverse Calc | ❌ | ✅ |
| Popular Pairs | ❌ | ✅ |
| OOP Design | ❌ | ✅ |
| Dynamic Arrays | Fixed array | `vector` |
| String Handling | C-strings | `std::string` |
| Code Lines | ~450 | ~480 |

## Future Enhancements

- 🌐 API integration for live rates
- 📈 Historical data and trends
- 💹 Rate alerts and notifications
- 💾 Favorite pairs configuration
- 📊 Conversion history tracking
- 🧮 Fee/commission calculator
- 📱 Multi-amount batch conversion

Enjoy the power of C++ with currency conversion! 💱
