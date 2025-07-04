#include <stdio.h>

struct Student{
    int roll;
    char name[20];
};

int main(){
    int n;
    printf("Enter the number of value: ");
    scanf("%d", &n);
    struct Student stud[n];
    printf("Enter the name and roll no. of student: ");
    for(int i=0; i<n; i++){
        scanf("%d", &stud[i].roll);
        scanf(" %[^\n]s", stud[i].name);
    }
    printf("--- Student Details ---\n");
    for(int i=0; i<n; i++){
        printf("The roll of student%d is: %d\n", i+1, stud[i].roll);
        printf("The name of student%d is: %s\n", i+1, stud[i].name);
    }
    
    return 0;
}