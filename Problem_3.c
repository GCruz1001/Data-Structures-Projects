//Due Tuesday 7/13/21
//Write a program to insert a number at a given location in an array.
#include <stdio.h>

int main()
{
    //Declaration of Variables
    int array[20];
    int n;
    int i;
    int add_num; //The number to be inserted
    int place; //The index/postion where the new number will be inserted

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter each element\n");
    //For Loop to get every element from the user
    for(i = 0; i < n; i = i + 1)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    //For Loop to print the original array
    printf("The array elements are: ");
    for(i = 0; i < n; i = i + 1)
    {
        printf("[%d]\t", array[i]);
    }
    printf("\n");

    printf("Enter the number to be inserted: \n");
    scanf("%d", &add_num);

    printf("Enter the place at which to be added: \n");
    scanf("%d", &place);

    //For Loop to select the location in the array that the user wants to replace 
    for(i = 0; i < n; i = i + 1)
    {
        if(i == place) //If the index position of the array is equal to what the user input
        {
            array[i] = add_num; //Replace the original element with the new element, at that location given by user
        }
    }
    //Print and updated array
    printf("The updated array is: ");
    for(i = 0; i < n; i = i + 1)
    {
        printf("[%d]\t", array[i]);

    }

    return 0;
}
//DONE