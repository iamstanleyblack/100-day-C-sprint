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


*/