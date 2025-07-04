#include <stdio.h>

struct Student{
    int roll;
    char name[20];
};
int main(){
    struct Student stud, *p;
    p = &stud;
    scanf("%d", &p->roll);
    scanf(" %[^\n]s", p->name);
    printf("The roll is : %d\n", p->roll);
    printf("The name is : %s\n", p->name);
    return 0;
}