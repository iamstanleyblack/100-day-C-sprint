#include<stdio.h>
struct Student{
int id;
char name[20];
float marks;
};

int main(){
struct Student s1 = {101, "Rahul", 89.5};
struct Student s2;

FILE *fp;

fp = fopen("student.txt", "wb"); 
fwrite(&s1, sizeof(struct Student), 1, fp); // fwrite(ptr, size, count, file_pointer
fclose(fp);

fp = fopen("student.txt", "rb");
fread(&s2, sizeof(struct Student), 1, fp); // fwrite(ptr, size, counter, file_poitner)
//ptr means ponter to the data we want to write or read
// size is teh size of eahch data element
// count is the nmber of elements to write or read
// file pointer is the ponter to the opened file

fclose(fp);

printf("ID: %d\n", s2.id);
printf("Name: %s\n", s2.name);
printf("Marks: %.1\n", s2.marks);

return 0;

}
