#include<stdio.h>

int main() {
float radius, pi, area;

pi = 3.14;
printf("What is the radius in cm?\n");
scanf("%f", &radius);

area = pi * radius * radius;
printf("The area of the circle is %f\n", area);


return 0;
}
