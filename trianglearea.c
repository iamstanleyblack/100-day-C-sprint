#include<stdio.h>

int main() 

{
float base, height, area;
printf("What is the base length of the triangle?\n");
scanf("%f", &base);

printf("What is the height length of the triangle?\n");
scanf("%f", &height);

area = 0.5 * base * height;

printf("The area of the triangle is %.2f\n", area);

return 0;

}
