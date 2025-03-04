#include <stdio.h>
#include <string.h>

struct student {
    char name[128];
    int age;
    float totalMarks;
};

int main() {

    struct student student1, student2;

    char betterStudent[128];

    printf("Student 1\n");
    printf("Name: ");
    scanf("%s", student1.name);
    printf("Age: ");
    scanf("%d", &student1.age);
    printf("Total Marks: ");
    scanf("%f", &student1.totalMarks);

    printf("Student 2\n");
    printf("Name: ");
    scanf("%s", student2.name);
    printf("Age: ");
    scanf("%d", &student2.age);
    printf("Total Marks: ");
    scanf("%f", &student2.totalMarks);

    printf("\nStudent 1 Information:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Total Marks: %.2f\n", student1.totalMarks);

    printf("\nStudent 2 Information:\n");
    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("Total Marks: %.2f\n", student2.totalMarks);

    float averageMarks = (student1.totalMarks + student2.totalMarks) / 2;

    if(student1.totalMarks > student2.totalMarks) {
        strcpy(betterStudent, student1.name);
    } else {
        strcpy(betterStudent, student2.name);
    }

    printf("\nAverage Total Marks: %.2f\n", averageMarks);
    printf("The better student is %s\n", betterStudent);

    return 0;
}