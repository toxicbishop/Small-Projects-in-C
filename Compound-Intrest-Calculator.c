#include<stdio.h>
#include<math.h>
int main() {
    double principal=0.0;
    double rate=0.0; 
    double time=0.0;
    int years=0;
    int times_compounded=0;
    double Total_amount=0.0;
    // Input principal Total_amount, rate of interest and time period
    printf("***compound interest calculator***\n");
    printf("Enter principal(P): ");
    scanf("%lf", &principal);
    printf("Enter interest rate (in percentage only)(R): ");
    scanf("%lf", &rate);
    rate /= 100; // Convert percentage to decimal
    printf("Enter time period (in years)(N): ");
    scanf("%d", &years);
    printf("Enter number of times interest is compounded per year: ");
    scanf("%d", &times_compounded);
    // Calculate compound interest
    Total_amount = principal * pow((1 + rate / times_compounded), times_compounded * years);
    printf("Total amount after %d years will be ₹ %.2lf\n", years, Total_amount);
    return 0;
}