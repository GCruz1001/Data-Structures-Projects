#include <stdio.h>
//Write a program to find a pair of elements with sum "k" in an unsorted array

int main()
{
    //Defining Variables
    int array[100];
    int k = 0; //Sum
    int i, j = 0;
    int size; //Size of array
    int count = 0; //Counter for pairs

    printf("Enter desired sum: \n");
    scanf("%d", &k);

    printf("Enter the size of the array: \n");
    scanf("%d", &size);

    printf("Enter each element: \n");
    for(i = 0; i < size; i = i + 1)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    printf("The array elements are: ");
    for(i = 0; i < size; i = i + 1)
    {
        printf("[%d]\t", array[i]);
    }
    printf("\n");

    //For every iteration of pairs, check if their sum is equal to the disired sum, k
    for(i = 0; i < size; i = i + 1)
    {
        for(j = 0; j < size; j = j + 1)
        {
            //If they are, print the sum and increment the counter
            if(array[i] + array[j] == k)
            {
                printf("Sum of Pair (%d, %d) = %d", array[i], array[j], k);
                printf("\n");
                count = count + 1;
            }
            
        }
    }
    printf("The Number of the paired elements with sum %d is %d\n", k, count);
    printf("End Program");
    return 0;
    

}
//DONE