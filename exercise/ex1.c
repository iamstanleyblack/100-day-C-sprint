#include<stdio.h>
int main(int argc, char *argv[])
{	int condition = 23;
	int answer;
	char name[20];
	printf("#########################\n");
	printf("#########WELCOME#########\n");
	printf("#########################\n");
	printf("What's your name? \n");
	fgets(name, sizeof(name), stdin);
	printf("Enter the secret number: \n");
	scanf("%d", &answer);
	if (answer == condition){
	printf("Woohoo! Yay %s, you've got the correct number.\n", name);
	} else{
	printf("Oh no! Please try again later.\n");
	}
	return 0;
}
