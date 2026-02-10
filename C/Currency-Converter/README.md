# Currency Converter

A comprehensive currency converter supporting 15 major world currencies with real-time conversion capabilities!

## 💰 Features

- **15 Major Currencies** - USD, EUR, GBP, JPY, INR, CNY, CAD, AUD, CHF, MXN, BRL, KRW, RUB, AED, SAR
- **Bi-directional Conversion** - Convert between any two currencies
- **Quick USD Conversion** - Instantly see USD converted to all currencies
- **Exchange Rate Table** - View all exchange rates at a glance
- **User-Friendly Interface** - Clean, menu-driven design
- **Accurate Calculations** - Precision decimal handling

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
gcc currency-converter.c -o currency-converter
```

### 2. Run the Program

```bash
./currency-converter        # Linux/Mac
currency-converter.exe      # Windows
```

### 3. Menu Options

```
  1. 💰 Convert Currency
  2. ⚡ Quick Conversion (USD Base)
  3. 📋 View All Currencies
  4. 📊 Exchange Rate Table
  5. 🚪 Exit
```

## Usage Examples

### Example 1: Convert USD to EUR

```
Enter source currency code: USD
Enter target currency code: EUR
Enter amount: 100

CONVERSION RESULT
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  100.00 USD (US Dollar)
           ↓
  92.59 EUR (Euro)

  Exchange Rate: 1 USD = 0.925926 EUR
```

### Example 2: Quick USD Conversion

```
Enter USD amount: $50

$50.00 USD converts to:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  EUR    € Euro                  :        46.30 EUR
  GBP    £ British Pound         :        39.37 GBP
  JPY    ¥ Japanese Yen          :      7462.69 JPY
  INR    ₹ Indian Rupee          :      4166.67 INR
  CNY    ¥ Chinese Yuan          :       357.14 CNY
  ... and more
```

### Example 3: Convert INR to GBP

```
Enter source currency code: INR
Enter target currency code: GBP
Enter amount: 10000

CONVERSION RESULT
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  10000.00 INR (Indian Rupee)
           ↓
  94.49 GBP (British Pound)

  Exchange Rate: 1 INR = 0.009449 GBP
```

## 📊 Technical Details

### Conversion Algorithm

All conversions go through USD as the base currency:

1. **Convert source to USD**: `amount × rateToUSD`
2. **Convert USD to target**: `usdAmount ÷ targetRateToUSD`

Example: Converting 100 EUR to JPY

- EUR to USD: 100 × 1.08 = 108 USD
- USD to JPY: 108 ÷ 0.0067 = 16,119.40 JPY

### Exchange Rates

**Note**: The exchange rates in this program are **approximate** and for **educational purposes only**.

In a real-world application, you would:

- Fetch rates from APIs (e.g., exchangerate-api.com, fixer.io)
- Update rates regularly
- Handle API errors and rate limits

## Learning Concepts

- **Structures** - Using `struct` to organize currency data
- **Arrays** - Managing multiple currency records
- **Functions** - Modular code organization
- **String Handling** - Currency code manipulation
- **Decimal Precision** - Financial calculations
- **Menu-Driven Programs** - User interface design
- **Data Validation** - Input error handling

## Customization

### Adding New Currencies

To add a new currency, update the `initializeCurrencies()` function:

```c
strcpy(currencies[15].code, "SGD");
strcpy(currencies[15].name, "Singapore Dollar");
strcpy(currencies[15].symbol, "$");
currencies[15].rateToUSD = 0.74;  // Example rate
```

Don't forget to update `MAX_CURRENCIES` constant!

### Updating Exchange Rates

Modify the `rateToUSD` values in `initializeCurrencies()`:

```c
currencies[1].rateToUSD = 1.10;  // Updated Euro rate
```

## Real-World Applications

While this is an educational project, currency converters are used in:

- **E-commerce** - International shopping sites
- **Travel** - Budgeting for international trips
- **Finance** - Foreign exchange trading
- **Banking** - International money transfers
- **Business** - International trade calculations

## Limitations

⚠️ **Important Notes**:

- Exchange rates are hardcoded (not live)
- Rates don't include bank fees or spreads
- No historical data or rate trends
- Simplified rounding (real forex uses more precision)

## Future Enhancements

Possible improvements:

- 🌐 Live API integration for real-time rates
- 📈 Historical rate charts
- 💹 Rate change alerts
- 💾 Save favorite currency pairs
- 📱 Batch conversion for multiple amounts
- 🧮 Commission/fee calculator

## Example Use Cases

1. **Travel Planning**
   - Budget your trip expenses
   - Compare costs across countries
   - Calculate how much to exchange

2. **Online Shopping**
   - Convert prices from foreign websites
   - Compare international prices
   - Calculate total cost in your currency

3. **Investment**
   - Track foreign stock values
   - Calculate forex returns
   - Compare international markets

4. **Education**
   - Learn about global currencies
   - Understand exchange rates
   - Practice financial mathematics

Enjoy converting currencies! 💱
