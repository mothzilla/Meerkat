#include <stdio.h>
#include <stdlib.h>

int i = 0;

struct student {
    char firstName[50];
    int roll;
    float marks;
} s[25];

void addStudent() {
    //char firstName[50];
    //int roll;
    //float marks;

    printf("Please enter student's first name:\n");
    scanf("%s", &s[i].firstName);
    //printf("Please enter student's roll number:\n");
    //scanf("%d", &s[i].roll);
    s[i].roll = i;
    printf("Please enter student's marks:\n");
    scanf("%f", &s[i].marks);

    i = i + 1;
}

void findStudentByRoll() {
    int roll;
    printf("Please enter a valid roll number:\n");
    scanf("%d", &roll);
    int found = 0;
    int j;
    for (j=0;j<i;j++){
        if (s[j].roll == roll) {
                printf("\nStudent found!\n\n");
                printf("Student Name: %s\nRoll: %d\nMarks: %.2f\n\n", s[j].firstName, s[j].roll, s[j].marks);
                found = 1;
                break;
        }
    }
    if (found == 0) {
        printf("\nStudent not found.\n\n");
    }
}

void modifyStudent() {
    int roll;
    int choice;
    int found = 0;
    printf("Please enter the roll number of the student you wish to modify:\n");
    scanf("%d", &roll);
    int j;
    for (j=0;j<i;j++){
        if (s[j].roll == roll){
            //printf("\nStudent found!\n\n");
            printf("Student Name: %s\nRoll: %d\nMarks: %.2f\n\n", s[j].firstName, s[j].roll, s[j].marks);
            found = 1;
            break;
        }
    }
    if (found == 0){
        printf("Student with roll %d not found. Returning to menu.\n", roll);
        return;
    }
    printf("You may modify \n1. Name of Student \n2. Marks of Student\nWhich would you like to modify?\n");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("Please enter new name for student:\n");
            scanf("%s", &s[j].firstName);
            break;
        case 2:
            printf("Please enter new marks for student:\n");
            scanf("%f", &s[j].marks);
            break;
        default:
            printf("Invalid input. Returning to menu...\n");
            break;

    }
}

void deleteStudent() {
    int found = 0;
    int j;
    int k;
    int roll;
    printf("Please enter the roll number of the student you wish to delete:\n");
    scanf("%d", &roll);

    for (j=0;j<i;j++){
        if (s[j].roll == roll){
            found = 1;
            for (k=j; k<i; k++){
                s[k] = s[k+1];
            }
            printf("Student deleted.\n");
            i--;
            for (j=0;j<=i;j++){
                s[j].roll=j;
            }
        }
    }

    if (found == 0) {
        printf("Student not found. Returning to menu...\n");
        return;
    }
}

void displayStudentRoster() {

    printf("\nDisplaying information about current roster...\n\n");
    //displaying...
    int k;
    for (k=0;k<i;k++){
        printf("Name: %s\nRoll: %d\nMarks: %.2f\n", s[k].firstName, s[k].roll, s[k].marks);
        printf("-----------------------------\n");
    }
}

void printRoster() {

    char fileName[50];
    int j;

    printf("Please enter a name for the file (followed by .txt):\n");
    scanf("%s", &fileName);
    FILE *fp;
    fp = fopen(fileName, "w");

    for (j=0;j<i;j++) {
        fprintf(fp,"Student Name: %s\nRoll: %d\nMarks: %.2f\n", s[j].firstName, s[j].roll, s[j].marks);
        fprintf(fp,"------\n");
    }

    fclose(fp);

}

int main()
{
    //printf("Hello world!\n");
    //FILE *fp;
    //fp = fopen("students.txt", "w");
    //int i;
    int choice;
    //int numberOfStudents;

    while (choice != 7){
        printf("This database can hold up to 25 students.\nPlease select an operation.\n\n");
        printf("1. Create New Student\n2. Lookup Existing Student Using Rollcall\n");
        printf("3. Modify Existing Student\n4. Delete Student\n5. Display Roster\n6. Print Roster\n7. Exit Menu\n");
        //scanf("%d", &numberOfStudents);
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            findStudentByRoll();
            break;
        case 3:
            modifyStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            displayStudentRoster();
            break;
         case 6:
            printRoster();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
            //exit(EXIT_FAILURE)
            break;
        }
    }

    exit(EXIT_SUCCESS);
}
