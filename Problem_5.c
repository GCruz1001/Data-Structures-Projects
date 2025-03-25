#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure "employee" definition, sets up all the types of variables in the main funciton
struct employee
{
    int id;
    char* name; //Name of employee
    int experience;
    int salary;
    char* department;
};

int main()
{
    //Variables for "For Loops"
    int i = 0;
    int n = 3;
    
    //Declaring use of the structure in the form of an array
    struct employee employee[n];

    //Information about all the employees before modification
    employee[0].id = 5561;
    employee[0].name = "Richard";
    employee[0].experience = 1;
    employee[0].salary = 68000;
    employee[0].department = "Product Development";

    employee[1].id = 5562;
    employee[1].name = "Callum";
    employee[1].experience = 2;
    employee[1].salary = 100000;
    employee[1].department = "Product Development";

    employee[2].id = 5563;
    employee[2].name = "Elon";
    employee[2].experience = 4;
    employee[2].salary = 150000;
    employee[2].department = "Product Development";

    //Loop for displaying the information for every employee
    printf("\t  ORIGINAL DATA\n");
    for(i = 0; i < n; i = i + 1)
    {
        printf("---------Employee %d Detail----------\n", (i+1));
        printf("I.D. = %d\n", employee[i].id);
        printf("Name: %s\n", employee[i].name);
        printf("Experience: %d\n", employee[i].experience);
        printf("Salary: %d\n", employee[i].salary);
        printf("Department: %s\n", employee[i].department);
    }

    //New altered information for the first employee
    employee[0].id = 5561;
    employee[0].name = "Richard";
    employee[0].experience = 1;
    employee[0].salary = 200000;
    employee[0].department = "Data Science";

    //Another loop for displaying the altered inforamtion of the employee
    printf("\t  ALTERED DATA\n");
    for(i = 0; i < 1; i = i + 1)
    {
        printf("---------Employee %d Detail----------\n", (i+1));
        printf("I.D. = %d\n", employee[i].id);
        printf("Name: %s\n", employee[i].name);
        printf("Experience: %d\n", employee[i].experience);
        printf("Salary: %d\n", employee[i].salary);
        printf("Department: %s\n", employee[i].department);
    }
    return 0;
}
