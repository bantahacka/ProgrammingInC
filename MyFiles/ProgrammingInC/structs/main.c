#include <stdio.h>
#include <stdlib.h>

int main()
{//d
    const int WORKFORCE = 3;
    const char POUNDS = 156;
    // Create the structure schema
    struct emp
    {
        int staffnum;
        char name[30];
        float salary;
        char grade;
    };
    struct emp employees[WORKFORCE];

    for(int i=0;i<WORKFORCE;i++)
    {
        printf("\nEnter employee %d's staff number: ", i+1);
        scanf("%d", &employees[i].staffnum);
        printf("\nEnter employee %d's name: ", i+1);
        scanf("%s", employees[i].name);
        printf("\nEnter employee %d's salary: ", i+1);
        scanf("%f", &employees[i].salary);
        //fflush(stdin); // NOT ALWAYS PORTABLE!
        printf("\nEnter employee %d's grade: ", i+1);
        // Put a space before %c to flush keyboard buffer to prevent carriage return from breaking stuff
        scanf(" %c", &employees[i].grade);
    }
    for (int i=0;i<WORKFORCE;i++)
    {
        printf("\n%20d %20s %20c%.2f %20c", employees[i].staffnum, employees[i].name, POUNDS,employees[i].salary, employees[i].grade);
        //printf("\nRecord %d:", i);
        //printf("\nStaff Number:%2d\nName:%18    s\nSalary:%7c%.2f\nGrade:%8c\n", employees[i].staffnum, employees[i].name, POUNDS,employees[i].salary, employees[i].grade);
    }

    //struct emp emp1 = {1000, "Tony", 15000.0f, 'Z'};

    // To access a data member, use member notation and the correct format specifier
    //printf("%10d", emp1.staffnum);
    //printf("\n%10s", emp1.name);
    //printf("\n%10.2f", emp1.salary);
    //printf("\n%10c", emp1.grade);
    //printf("\n%10lu", sizeof(emp1));

    return 0;
}
