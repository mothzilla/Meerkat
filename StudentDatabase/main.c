#include <stdio.h>
#include <stdlib.h>

struct student {
    char firstName[50];
    int roll;
    float marks;
} s[10];

int main()
{
    //printf("Hello world!\n");
    FILE *fp;
    fp = fopen("students.txt", "w");
    int i;
    int numberOfStudents;
    printf("This database can hold up to 10 student.\nHow many students would you like to enter into the database?\n");
    scanf("%d", &numberOfStudents);
    if (numberOfStudents>10){
        printf("Too many students! Try again when you can follow directions...");
        exit(EXIT_FAILURE);
    }
    //printf("Please enter the information of 5 students:\n");

    //begin to store info
    for (i=0;i<numberOfStudents;i++) {
        s[i].roll = i+1;
        printf("For student with roll number %d, please enter first name:\n", s[i].roll);
        scanf("%s", s[i].firstName);
        printf("Please enter marks:\n");
        scanf("%f", &s[i].marks);
        fprintf(fp,"Student Name: %s\nRoll: %d\nMarks: %.2f\n", s[i].firstName, s[i].roll, s[i].marks);
        fprintf(fp,"------\n");
    }
    fclose(fp);
    printf("Information saved in student file.\nDisplaying information about current roster...\n\n");

    //displaying...
    for (i=0;i<numberOfStudents;i++){
        printf("Name: %s\nRoll: %d\nMarks: %.2f\n", s[i].firstName, s[i].roll, s[i].marks);
        printf("-----------------------------\n");
    }
    return 0;
}
