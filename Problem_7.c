/*
AUTHOR: Goethe Cruz
FILENAME: lab_2.c
SPECIFICATION: Simple Beginner Programming Problems (ARRAYS/STRINGS)
FOR: Cs 2413 Data Structure Section D52

------------------------------------------------------------------------------------------------------

NAME: main
INPUT: characters
OUTPUT: characters
PURPOSE: Concatenate two strings


*/
//Write a program to concatenate two strings...

#include <stdio.h>
#include <string.h>

int main()
{
    //Defining two strings
    char string_1[100];
    char string_2[100];

    printf("Enter the first string: \n");
    gets(string_1); //Must use gets, otherwise, spaces in the input would not work
    //scanf("%s", &string_1);

    printf("Enter the second string: \n");
    gets(string_2);
    //scanf("%s", &string_2);

    //Using function "strcat" to concatenate the two input strings
    strcat(string_1, string_2);

    printf("Concatenated word: %s", string_1);
    return 0;
}