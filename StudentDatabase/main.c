#include <stdio.h>
#include <stdlib.h>

struct student {
    char firstName[50];
    int roll;
    float marks;
} s[5];

int main()
{
    //printf("Hello world!\n");
    int i;
    printf("Please enter the information of 5 students:\n");

    //begin to store info
    for (i=0;i<5;i++) {
        s[i].roll = i+1;
        printf("For student with roll number %d, please enter first name:\n", s[i].roll);
        scanf("%s", s[i].firstName);
        printf("Please enter marks:\n");
        scanf("%f", &s[i].marks);
    }
    printf("Displaying information about current roster...\n");

    //displaying...
    for (i=0;i<5;i++){
        printf("Name: %s\nRoll: %d\nMarks: %.2f\n", s[i].firstName, s[i].roll, s[i].marks);
        printf("-----------------------------\n");
    }
    return 0;
}
