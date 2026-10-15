#include<stdio.h>
#include<string.h>

void reverse_string(char *str){
    size_t len = strlen(str);
    if (len < 2) return; // No need to reverse if the string is empty or has one character

    size_t i = 0;
    size_t j = len - 1;

    while(i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(void){
    char text[256];

    printf("Enter a string to reverse: ");
    
    if (fgets(text, sizeof(text), stdin) == NULL){
        return 1; // Error reading input
    }


    // remove the newline character if present
    text[strcspn(text, "\n")] = 0;

    reverse_string(text);

    printf("Reversed string: %s\n", text);

    return 0;

}