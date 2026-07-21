/*
we can add as many dimensions as we want to our arrays which will be stored in memory in row-major order. so in a 2D array, the first index listed indicates the row, and the second indicates the column

#include<stdio.h>
int main() {
    int row, col;
    int a[2][5] = {
        // We initialize a 2D array here
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };
for (row = 0; row < 2; row++){
    for(col = 0; col < 5; col++){
        printf("(%d, %d) = %d\n", row, col, a[row][col]);    }
}
}

// ARRAYS AND POINTERS
#include<stdio.h>
int main() {
    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0]; // p points to the array's first element

    printf("%d\n", *p); // this will print 11 since its the irst element(element 0)
    // So, p = &a[0]; is the same as p = a;
    // referring to the array name is the same as getting a pointer to the first element of the array!
}

// PASSING SINGLE DIMENSTIONAL ARRAYS TO FUNCTIONS

if you pass an array to a function, you re passing a pointer to the first element in the array
However, if the function has a pointer to the dats, it is able to manipulate that data! So changes that a function mkes to an array will be visible back out in the caller
*/

#include<stdio.h>
void double_array(int *a, int len)
{
    for(int i = 0; i < len; i++)
    a[i] *= 2;
}
int main(void)
{
    int x[5] = {1, 2, 3, 4, 5};
    double_array(x, 5);
    for(int i = 0; i < 5; i++)
    printf("%d\n", x[i]); // 
return 0;
}