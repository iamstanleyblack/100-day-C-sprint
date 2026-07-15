// we are going to talk about if, for, while and do-while here
// we can put either a single statement to be executed or a block of statements to all be executed in a sequence after an if or while statement
// exmple of one with a single statement
// if(x == 10) printf("x is 10\n");
// we can do this simply because C is not strict about whitespaces like other languages like python are.
// if we want multiple things to happen due to a condition, we can use squirrel braces to mark a block or a compound statement
/*
if(x = 10){
    printf("x is 10\n");
    printf("And also this happens when x is 10\n");

}
    an if statement will run the one thing after the 'if' and that one thing can be a single statemetn or a block of statemetns

*/

#include<stdio.h>
#include<stdlib.h>

int main(){
//     int i = 11;
//     if(i > 10){
//         printf("Yes, i is greater than 10.\n");
//         printf("And this will also print if i is greater than 10.\n");
//     }
//     if (i <= 10) printf("i is less than or equal to 10.\n");
//     int i = 99;
//     if (i == 10)
//     printf("i is 10\n");
// else{
//     printf("i is not 10.\n");
//     printf("Frankly irritating\n");
// }
// int i = 10;
// if(i == 10)
// printf("i is 10\n");
// else if (i == 20) 
//     printf("i is 20\n");
// else if(i == 99){
//     printf("i is 99. My fav number\n");
//     printf("I cannot tell you how happy I am.\n");
//     printf("Really happy:)\n");
// }
// else
// printf("i've never heard of the i above.\n");
// The above code would work better if it were a switch. However, we should remember that the if-else can, in addition to checking equality, check ranges, variables or anything else we can craft in a conditional statement while switch statement only checks for equality
//WHILE LOOP
// It does something while a condition expressio is true
// char character = 'i';
// int count = 1;
// while(count <= 9){
//     printf("i is now %d\n", count);
//     //NOTE: & is only used when i want to store a value at some address. not when i wnat to print
//     // It should just be 'count' and not '&count' coz '&count' will print the memory address
//     // thats why i kept getting the very large numbers 
//     count++;
// }
// printf("All done");
// while(1){
//     printf("1 is always true so this will print forever resulting in an infinite loop\n");
//     break; // this will stop the infinite loop
// }

/*DO-WHILE LOOP
Do-While loop and While loop are basically the same concepts except a do-while will execute a condition before checking the condition. So even if the condition is false, it will first execute the first cycle before checking the condition.
i = 10;
while(i < 10){
printf("While i is %d\n", i); // this will not be executed because i is not les than 10
i++
}
Using a do-while statement
i = 10;
do{
printf("Do while i is %d\n", i)}; THis will be executed first and thereafter is when the condition will be checked
i++;
}while(i < 10);
printf("All done")

in both loops, the loop condition is false right from the start. so, in while, the loop fails immediately and the following block of code is never executed. With the do-while loop, the condition is checked after the block of code executes so it always executes atleast once.
*/

// For loop
// int r;
// do{
//     r = rand() % 100; // Get a random number between 0 and 99
//     printf("%d\n", r);

// } while(r != 37); // repeat until r is equiv to 37
//NB:/- The same sequence of numbers gets printed againa and again. 
// This is because rand() is a pseudorandom number generator
// that must be seeded with a different number in order to generate a different sequence
// <!--TODO: READ ABOUT SRAND()--> 
// for loop - This helps if you know the number of times you want to loop in advance. you can do the same with a while loop but a for loop keeps the code cleaner
// Printing numbers between 0 and 9, inclusive...
// Using a while statement:
// int i = 0;
// while (i < 10){
//     printf("i is %d\n", i);
//     i++;
// }
// DOING THE SAME THING WITH A FOR-LOOP
// for(int i = 0; i < 10; i++){
//     printf("i is %d\n", i); // see how this code is more compact
    // the for-loop declaration is split into 3 parts. first for initialization, second for the condition and third for what should happen at the end of the block if the loop condition is true
    // for(initialize things; loop if this is true; do this after each loop
    // just like a while loop, a for-loop will not execute even once if the loop condition starts off false
// }
// for(;;){
//     printf("Infinite"); i have read that an empty for loop will result into an infinite loop
// }
// for(;;){
//     printf("Infinite\n");
// }
// int goat_count = 2;
// switch(goat_count){
//     case 0:
//     printf("You have no goats.\n");
//     break;
//     case 1:
//     printf("You have a singular goat.\n");
//     break;
//     case 2:
//     printf("You have a brace of goats.\n");
//     break;
//     default:
//     printf("You have a bona fide plethora of goats!\n"); // in the example, the switch will jump to the case 2 and execute from there. when or if it hits a break, it jumps out of the switch. the default happens when no cases match.
// }
// switch is like an if-else statement but they have some differences as follows:
// Switch is often faster to jump to the correct code(though the spec makes no such guarantee).
//if-else can do things like relational conditionals like < and >= and floating point and other types, while switch cannot(i.e it only does comparison i.e ==)
// NB:/- ALWAYS REMEMBER TO PUT A BREAK IN A SWITCH STATEMENT IF YOU DON'T WANT IT TO FALL THROUGH
// BUT! IF YOU INTEND FOR IT TO FALL THROUGH, MAKE SURE TO LEAVE A COMMENT ON THE EXACT LINE WHERE THE FALL THROUGH WILL HAPPEN
int age;
int countyNo;
int response;
int county;
printf("How old are you? \n");
scanf("%d", &age);
printf("---------------------------------\n");
if (age < 18){
    printf("What number is you county? \n");
    scanf("%d", &county);
    printf("--------------------------------\n");
    if(county < 40){
        printf("Dear User, Your age and location do not meet the criteria. Try again after some years\n");
        printf("-------------------------------------\n");

    }
    else{
        printf("Please visit any registration office near you to seek for assistance\n");
        printf("------------------------------------------\n");
        //break;
    }
}
else{
    printf("You are eligible for the voting process.\n Please visit any registration office near you with your government details to get assistance\n");
    //break;
}
printf("Rate the quality of service: \n");
printf("1. #####\n2. ####\n3. ###\n4. ##\n5. I was not assisted\n.");
scanf("%d", &response);
printf("------------------------------\n");
switch(response){
case 1:
printf("Thank you so much\n");
break;
case 2:
printf("Thank you, we'll do better next time\n");
break;
case 3:
printf("Right in the middle : What went wrong? Write us an email\n");
break;
case 4:
printf("Write as an email\n");
break;
case 5:
printf("Call us ASAP or visit any office near you\n");
break;
}

    return 0;
}