#include<stdio.h>

int main()

{

/*int s;

s = 4;

if(s == 5){
printf("It is five\n");
}
*/

int velocity;

printf("How fast are you driving in km/h?\n");
scanf("%d", &velocity);

if(velocity > 100){
printf("Slow down! You are driving too fast.\n");
}
else if(velocity > 80){
printf("You are driving above 80km/h\n");
}return 0;
}
