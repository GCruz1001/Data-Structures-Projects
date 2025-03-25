/*
AUTHOR: Goethe Cruz
FILENAME: lab_4.c
SPECIFICATION: STACKS
FOR: Cs 2413 Data Structure Section D52

------------------------------------------------------------------------------------------------------
NAME: enque
INPUT: char
OUTPUT: char
PURPOSE: Begin the queueing process of the program

NAME: de_q
INPUT: char
OUTPUT: void
PURPOSE: Check for an empty queue, then begin the enqueueing process of the program

NAME: bin_q
INPUT: char
OUTPUT: char, int
PURPOSE: Uses the strings to generate the appropriate binary numbers to the terminal

NAME: main
INPUT: int
OUTPUT: int
PURPOSE: Utilized the aforementioned functions to print the programs results

*/
#include <stdio.h>
#include <string.h>

#define MAX 20

//Defining variables used in the functions following
char q[MAX][MAX]; //The q generated using arrays
char temp[MAX]; //Temporary value
//initilizing front and rear most values of our program
int front = -1;
int rear = -1;

//function to begin the queing process
void enque(char *pointer)
{
    if(rear == (MAX - 1))
    {
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
        strcpy(q[rear], pointer);
    }
}

//Function to dequeue
char* de_q()
{
    if(front == -1)
    {
        printf("Empty Queue");
    }
    else
    {
        strcpy(temp, q[front]);
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1;
        return temp;
    }
}

//This function simply copies and prints the values in compliance with the values from main()
void bin_q()
{
    char temp_2[MAX];
    strcpy(temp, de_q());
    printf("%s\n", temp);
    strcpy(temp_2, temp);
    strcat(temp, "0");
    enque(temp);
    strcat(temp_2, "1");
    enque(temp_2);
}
5
int main()
{
    int i;
    int n;
    char temp[2] = "1";
    printf("Enter Final Value: \n");
    scanf("%d", &n);
    enque(temp);
    printf("Numbers from 1 to Final Value %d: ", n);
    
    //Use FOR loop to utilize the previous funciton
    for(i = 1; i <= n; i = i + 1)
    {
        bin_q();
    }

    return 0;
    
}