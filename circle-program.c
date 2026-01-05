#include <stdio.h>
#include <math.h>
int main() {
   double radius=0.0;
   double area=0.0;
   double surfaceArea=0.0;
   double volume=0.0;
   const double PI=3.14159;
   printf("Enter the radius of the circle: ");
   scanf("%lf", &radius);
    area = PI * pow(radius, 2);// Area = πr²
    surfaceArea = 4 * PI * pow(radius, 2); // Surface Area = 4πr²
    volume = (4.0/3.0) * PI * pow(radius, 3); // Volume = (4/3)πr³
    printf("Area: %.2lf \n", area);
    printf("Surface Area: %.2lf \n", surfaceArea);
    printf("Volume: %.2lf \n", volume);
    return 0;
}