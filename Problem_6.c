#include <stdio.h>
#include <stdlib.h>

//Defining the structure "node"
typedef struct node
{
    //data that goes into the linked list
    int data;
    struct node *next;
    struct node *prev;
}
*first_node;
*last_node;
node;

//Function to Create a Doubly Linked List
void linked_list_creation(int n)
{
    int i;
    int data; //Values that will compose our linked list creation
    struct node *new_node;

    //This is to create a new node with an input data
    if(n >= 1)
    {
        first_node = (struct node *)malloc(sizeof(struct node));
        if(first_node != NULL)
        {
            printf("Enter Data for First Node:\n");
            scanf("%d", &data);

            first_node -> data = data;
            first_node -> prev = NULL;
            first_node -> next = NULL;
            last_node = first_node;
            //Loop to input the rest of the data for the 5 varibale linked list
            for(i = 2; i <= n; i = i + 1)
            {
                new_node = (struct node *)malloc(sizeof(struct node));
                //Makes sure there is no overflow
                if(new_node != NULL)
                {
                    printf("Enter Data of %d Node: ", i);
                    scanf("%d", &data);

                    new_node -> data = data;
                    new_node -> prev = last_node;
                    new_node -> next = NULL;

                    last_node -> next = new_node;
                    last_node = new_node;
                }
                else
                {
                    printf("NO MEMORY");
                    break;
                }
            }
            printf("LINKED LIST CREATED\n");
        }
        else
        {
            printf("NO MEMORY");
        }
    }
}

//Function to insert
void insert(node** head_ptr, int new_data)
{
    //Create a new node to insert
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = new_data;
    new_node -> prev = NULL;
    new_node -> next = (*head_ptr);

    if((*head_ptr) != NULL)
    {
        (*head_ptr) -> prev = new_node;
        (*head_ptr) = new_node;
    }
}

//Function to Print
void print_linked_list(node *temp_node)
{
    while(temp_node != NULL)
    {
        printf("%d", temp_node -> data);
        temp_node = temp_node -> next;
    }
}

//Function to Reverse
void reverse_linked_list(node **head_ptr)
{
    node *temp_node = NULL;
    node *current_node = *head_ptr;

    while(current_node != NULL)
    {
        temp_node = current_node -> prev;
        current_node -> prev = current_node -> next;
        current_node -> next = temp_node;
        current_node = current_node -> prev;
    }

    if(temp_node != NULL)
    {
        *head_ptr = temp_node -> prev;
    }
}

//Function to Delete the First Node 
void delete_node(node **first_node)
{
    struct node *temp;

    if(first_node == NULL || *first_node == NULL)
    {
        return;
    }
    //Store the first node into a temporary value
    temp = *first_node;
    //Move the first node to the next node
    *first_node = (*first_node) -> next;
    //Free up the space, thereby deleting the node
    free(temp);
}

//Main Function
int main()
{
    int menu_option;
    int new_data;
    node* head = NULL;

    while(1)
    {
        printf("MENU OPTIONS\n");
        printf("\t1. Create List And Insert A Node\n");
        printf("\t2. Print Linked List\n");
        printf("\t3. Reverse Linked List\n");
        printf("\t4. Delete First Node\n");
        printf("\t5. EXIT PROGRAM\n");
        printf("What would you like to do: \n");
        scanf("%d", &menu_option);
    
        if(menu_option == 1)
        {
            printf("Enter New Data: \n");
            scanf("%d", &new_data);
            insert(&head, new_data);
        }
        else if(menu_option == 2)
        {
            printf("PRINTING LINKED LIST: \n");
            printf(head);
            printf("\n");
        }
        else if(menu_option == 3)
        {
            printf("REVERSING LINKED LIST\n");
            reverse_linked_list(&head);
        }
        else if(menu_option == 4)
        {
            printf("DELETING FIRST NODE\n");
            delete_node(first_node);
        }
        else
        {
            printf("EXITING PROGRAM\n");
            break;
        }
    }
    return 0;
}