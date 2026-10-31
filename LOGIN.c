#include<stdio.h>
#include<string.h>

#define MAX_USERS 10
#define STR_LEN 40

struct User {

char username[STR_LEN];
char password[STR_LEN];
};
int main()
{
 struct User userlist[MAX_USERS] = {
	{"alice99", "pasword123"},
	{"bobby", "secrepasword"},
	{"charlie_brown", "passsecret"}
};

char inputusername[STR_LEN];
char inputpassword[STR_LEN];
int loginSuccess = 0;

printf("--- LOGIN SCREEN ---\n");
printf("Enter username: ");
scanf("%s", inputusername);
printf("Enter your password: ");
scanf("%s", inputpassword);

for (int i = 0; i < MAX_USERS; i++){
if(strcmp(userlist[i].username, inputusername) == 0 &&
   strcmp(userlist[i].password, inputpassword) == 0) {
	loginSuccess = 1;
	break;
}
}

if (loginSuccess){
printf("\nLogin successful! Welcome back.\n");
} else {
printf("\nLogin failed. Invalid username or password. \n");
}
return 0;

}
