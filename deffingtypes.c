/*
we use typedef to make an alias for an existing type
for example;
typedef int antelope; // here we are just making antelope to be an alias for int type
antelope x = 10; // thus antelope will do the same function as int in this assingment statemetnt

typedef int antelope, bagel, mushroom; // therse are all ints
typedef follows the scping rules including(block scope, file scope)

how can we use the typedef? where do we apply it? 
smetimes a struct will be typedefed to a new name so we don't need to type th eword struct over and over

for example
struct anial{
char *name;
int leg_count, speed;
};

typedef struct animal animal;
struct animal y; // this will work
anial z; // this will also work because 'animal' is just an alias

*/