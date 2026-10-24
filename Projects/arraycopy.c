#include <stdio.h>

int main(void) {
    int src[5] = {1, 2, 3, 4, 5};
    int dst[5];

    // Copy by hand, within bounds
    for (int i = 0; i < 5; i++) {
        dst[i] = src[i];
    }

    // Now copy past the end
    int dst2[5];
    for (int i = 0; i < 10; i++) {   // 10 > 5: out of bounds
        dst2[i] = src[i];            // reads past src AND writes past dst2
    }

    printf("%d\n", dst2[0]);
    return 0;
}
