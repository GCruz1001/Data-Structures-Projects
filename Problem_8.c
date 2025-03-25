//Write a program to count the number of digits, upper case and lower case letters, and special characters in a given string.

#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int upper_case = 0; //Counter to keep track of the upper case letters
    int lower_case = 0; //Counter to keep track of the lower case letters
    int digit_count = 0; //Counter to keep track of the digits in the string
    int special_count = 0; //Counter to keep track of the special characters in the string
    int i = 0;



    printf("Enter you string: ");
    scanf("%s", &string);

    while(string[i] != '\0')
    {
        //If statement for lower case characters
        if(string[i] >= 'a' && string[i] < 'z')
        {
            lower_case = lower_case + 1;
        }
        //If statement for Upper case letters
        else if(string[i] >= 'A' && string[i] < 'Z')
        {
            upper_case = upper_case + 1;
        }
        //If statement for numbers
        else if(string[i] > '0' && string[i] <= '9')
        {
            digit_count = digit_count + 1;
        }
        //If statment for special characters
        else
        {
            special_count = special_count + 1;
        }
        i = i + 1;
    }
    printf("\n");
    printf("Number of Upper Case letters is: %d\n Number of Lower Case letters is: %d\n Number of Digits is: %d\n Number of Special Characters is: %d\n", upper_case, lower_case, digit_count, special_count);
}
//DONE