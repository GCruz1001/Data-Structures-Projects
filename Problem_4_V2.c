/*
AUTHOR: Goethe Cruz
FILENAME: lab_4.c
SPECIFICATION: STACKS
FOR: Cs 2413 Data Structure Section D52

------------------------------------------------------------------------------------------------------

NAME: main
INPUT: int,char
OUTPUT: char
PURPOSE: To find out whether an expression entered by a user has a matching or unmatching set of parenthesis, brackets, or braces

NAME: push
INPUT: character
OUTPUT: void
PURPOSE: check to see if there is an overflow condition and then set the top value of the stack equal 

NAME: pop
INPUT: void
OUTPUT: void
PURPOSE: check for underflow condition 
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10

//Setting initial variables and function parameters
int top = -1;
int stk[MAX];
void push(char);
char pop();

//Main Function
void main()
{
    char epression[MAX]; //Entered Expression we want to check
    char temp; //Temporary value we use in the function
    int i;
    int flag = 1; //The varaible that lets us know if the expression has matching braced or not

    //Aquire Input from user
    printf("Enter an expression: \n");
    gets(epression);

    //For Loop to Check every part of the expression entered
    for(i = 0; i < strlen(epression); i = i + 1)
    {
        //If this condition is met, push
        if(epression[i] == '(' || epression[i] == '{' || epression[i] == '[')
        {
            push(epression[i]);
        }
        //Regardless of the above condition being met or not, check this condition
        if(epression[i] == ')' || epression[i] == '}' || epression[i] == ']')
        {
            //If the top value of the stack is a -1, then the stack is empty and its automatically not matching
            if(top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if(epression[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if(epression[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if(epression[i] == ']' && (temp == '(' || temp == '{'))
                {
                    flag = 0;
                }
            }
        }
    }
    //These Conditional Statements will dictate if the expression is balanced or unbalanced by using "flag" to print yes or no
    if(top >= 0)
    {
        flag = 0;
    }
    if(flag == 1)
    {
        printf("Matching");
    }
    else
    {
        printf("Not Matching");
    }
}

//Function for inserting values into the top of the stack
void push(char c)
{
    //Conditional statement to check if the stack is full
    if(top == (MAX - 1))
    {
        printf("Stack Overflow");
    }
    //If condition is not met, add a space and set it equal to the next character entered
    else
    {
        top = top + 1;
        stk[top] = c;
    }
}

//Fucntion for deleting the top most value of the stack
char pop()
{
    //Conditional statement to check if the stack is emtpy or not
    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        return (stk[top--]);
    }
}