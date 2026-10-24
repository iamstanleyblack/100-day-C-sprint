#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Step 1: Validate command-line arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Step 2: Open the file in read-binary mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int byte;
    size_t count = 0;

    // Step 3: Read and print the file byte by byte
    while ((byte = fgetc(file)) != EOF) {
        // Print the byte as a 2-digit uppercase hex code
        printf("%02X ", byte);
        count++;

        // Step 4: Format the output (wrap text every 16 bytes)
        if (count % 16 == 0) {
            printf("\n");
        }
    }

    if (count % 16 != 0) {
        printf("\n");
    }

    fclose(file);
    return 0;
}
