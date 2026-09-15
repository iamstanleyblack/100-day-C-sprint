#include<stdio.h>
int main()
{
    int a[] = {11, 22, 33, 44, 55};

    int *p = a;

    for(int i; i < 5; i++){
        printf("%d\n", a[i]);
    }
    printf("First bunch.\n");
    for(int i; i < 5; i++){
        printf("%d\n", p[i]);
    }
    printf("Second bunch.\n");
    for(int i; i < 5; i++){
        printf("%d\n", *(a + i));
    }
    printf("Third bunch.\n");
    for(int i; i < 5; i++){
        printf("%d\n", *(p + i));
    }
    printf("Fourth bunch.\n");
}