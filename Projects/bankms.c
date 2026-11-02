#include<stdio.h>
#include<math.h>
//MAKING A BANKING MANAGEMENT SYSTEM

//USER HAS SOME MONEY IN THEIR BANK ACCOUNT
//OPTIONS:
//- WITHDRAW
//- DEPOSIT
//- BORROW
//- REPAY
//- SHOW BALANCE
//1. PRINT A WELCOME MESSAGE
//2. PROVIDE THE OPTIONS
//3. PERFORM THE REQUESTED SERVICE
//4. PRINT GOODBYE
int SERVICE;
int balance = 35000;
int borrow;
int repay;
int withdraw;
int deposited;
int deficit;
int DEPOSIT(){
printf("How much would you like to deposit? \n");
scanf("%d", &deposited);
balance = balance + deposited;
}
int BORROW(){
printf("How much would you like to borrow? \n");
scanf("%d", &borrow);
int deficit = borrow;
}
int REPAY(){
printf("How much would you like to pay back? \n");
scanf("%d", &repay);
int repayed = repay;
}
int WITHDRAW(){
printf("How much would you like to withdraw? \n");
scanf("%d", &withdraw);
balance = balance - withdraw;
printf("Your new balance is %d\n", balance);
if(balance <= 0){
printf("You have insufficient balance! Top up your account to proceed with the withdrawal\n");
}

int main(){
while(1){
printf("################\n");
printf("#####WELCOME####\n");
printf("#######TO########\n");
printf("#######THE#######\n");
printf("######BANK#######\n");
printf("Here are all the services we currenlty have:\n1. Check balance\n2. Deposit money\n3. Borrow money\n4. Repay money\n5. Withdraw\n");
printf("What would you like to do today?(1-5)\n");
scanf("%d", &SERVICE);
if (SERVICE == 1){
printf("Your balance is %d\n", balance);
}
else if (SERVICE == 2){
DEPOSIT();
printf("Your current balance is %d\n", balance);
}
else if (SERVICE == 3){
if (balance != 0){
printf("I am sorry but you cannot borrow when you have money in your account.\n");
}
}
else if (SERVICE == 4){
}
else if (SERVICE == 5){
WITHDRAW();
}
}
return 0;
}
