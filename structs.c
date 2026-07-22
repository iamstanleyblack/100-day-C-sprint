/*
A struct in C is a useer-definable type that holds multiple pieces of data
It is convenient as it provides a way to bundle multipe variables into a single one, which can be beneficial for passing variables to functions and useful for organizing data and making code more readable
We can think of a struct as a class with only data members and no methods

//How to declare a struct
struct car{
char *name;
float price;
int speed;
};
// Structs are usually defined at the global scope so that every function has access to it
the name 'struct car' is a type 
in struct car saturn; // variable 'saturn' is of type 'struct car'
to access individual fields fro the struct, we use the dot operator like this:

saturn.name = "Saturn SL/2";
saturn.price = 15999.99;
saturn.speed = 175;
printf("Name:   %s\n", saturn.name);
printf("Price(USD):     %f\n", saturn.price);
printf("Top Speed (km):     %d\n", saturn.speed);

// Struct Initializers
the better way to initialize a struct variable is by putting values in for the fields in the order they appear in the struct when you define the variable


struct car {
char *name;
float price;
int speed;
};

// Now eith an initializer we use sam field order as in the struct declaration:
struct car saturn = {"Saturn SL/2", 16000.99, 175};

printf("Name:   %s\n", saturn.name);
printf("Price:      %f\n", saturn.price);
printf("Top Speed:      %d km\n", saturn.speed);
If soeone changes the order in the struct car, it could break all the other code since the fields heere in the initializer need to be in the same order

we can also just be more specific by using
struct car saturn = {.speed=175, .name="Saturn SL/2"};

//Passing structs to functions

#include<stdio.h>

struct car {
    char *name;
    float price;
    int speed;

};
void set_price(struct car *c, float new_price) {
    // (*c)price = new_price; // works but a bit complex

    // the line above is 100% equivvalent to the one below
    c->price = new_price; 
}

// void set_price(struct car *c, float new_price)
int main() {
    struct car saturn = {.speed=175, .name="Saturn SL/2"};

    // Passing a pointer to this struct car along with a new price
    set_price(&saturn, 788.99);
    printf("Price: %f\n", saturn.price);
}

// Arrow Operator
// arrow operator help refer to fields in pointers to structs


// Copying and Returning structs
to copy struct, just assign from one to the other!
struct car a, b;
b = a; // this copies the struct
//Comparing structs
to c
*/
