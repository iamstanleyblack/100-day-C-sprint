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

*/
