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

typedef struct animal {
char *name;
int leg-count;
int speed;
} animal; // we now refer to the whole struct as 'animal'

struct animal y; // this will work
animal z; // this also works

// ANONYMOUS STRUCTURE

typedef struct {
char *name;
int leg_count;
int speed;
} animal; // new name

animal z; // this alwo works

// WE CAN ALSO DO THIS:
 
typedef struct {
int x;
int y;
} point;

point p = {.x=20, .y=40};

printf("%d, %d\n", p.x, p.y);

// we can also use typedef to change the type of a variable to another type
typedef float app_float;
app_float f1, f2, f3; // everything ere is now a floating point

//If we later wnat to change the type of all those variables above, we jsut need to change the typedef we made at the top as follows

typedef long double app_float;
app_float f1, f2, f3; // Now all these become long doubles
*/