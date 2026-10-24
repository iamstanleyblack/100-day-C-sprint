#include<stdio.h>
#include<stdlib.h>
int main(void)
{
float *p = malloc(sizeof *p *20); // allocating space for 20 floats, sizeof *p is same as sizeof(flaot)

for (int i = 0; i < 20; i++) //assigning the 20 floats frantional values
p[i]  = i /20.0;
float *new_p = realloc(p, sizeof *p *40); // making this array to 40 elements instead of the 20
if (new_p == NULL){
printf("Error reallocating\n");
return 1;
}
p = new_p; //
for (int i = 20; i < 40; i++){
p [i]= 1.0 + (i - 20) / 20.0;
}for (int i = 0; i < 40; i++){
printf("%f\n", p[i]);
}

free(p);
}
