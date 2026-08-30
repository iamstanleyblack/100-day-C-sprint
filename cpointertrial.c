#include<stdio.h>
int prod(int a, int b);
int sum(int a, int b);
int sub(int a, int b);
int div(int a, int b);
int main(void){
    int a;
    int b;
    int options;
    int subf;
    int divf;
    int prodf;
    int sumf;
    printf("Hello! We are going to do some calculations.\n");
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Here are the options(select one between 1 - 4):\n1. Multiply\n2. Addition\n3. Subtraction\n4. Division\n: ");
    scanf("%d", &options);
    // printf("1. Multiply\n");
    // printf("2. Addition\n");
    // printf("3. Subtraction\n");
    // printf("4. Division\n");
    switch(options){
        case 1:
        int prodf = prod(a,b);
        printf(" The product is %d\n", prodf);
        break;
        case 2:
        int sumf = sum(a,b);
        printf("The sum is %d\n", sumf);
        break;
        case 3:
        int subf = sub(a,b);
        printf("The difference is %d\n", subf);
        break;
        case 4:
        int divf = div(a,b);
        printf("The division is %d\n", divf);
        break;
    }
    return 0;
}
int prod(int a, int b){
    return a * b;
}
int sum(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int div(int a, int b){
    return a / b;
}