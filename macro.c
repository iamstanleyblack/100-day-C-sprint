#include<stdio.h>
#include<string.h>
// struct is a collection of related members/variables
//	they can be of different data types
//	listed under one in a block of memory
//	very similar to classes in other languages but no methods

struct Player
{
char name[12];
int score;

};

int main()

{
struct Player player1;
struct Player player2;
strcpy(player1.name, "Jrishu");
player1.score = 4;

strcpy(player2.name, "Jrisha");
player2.score = 5;
printf("%s\n", player1.name);
printf("%d\n", player1.score);

printf("%s\n", player2.name);
printf("%d\n", player2.score);
}
