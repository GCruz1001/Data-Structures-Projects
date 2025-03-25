/*
AUTHOR: Goethe Cruz
FILENAME: lab_4.c
SPECIFICATION: STACKS
FOR: Cs 2413 Data Structure Section D52

------------------------------------------------------------------------------------------------------
NAME: create_tree
INPUT: double pointer, num
OUTPUT: void
PURPOSE: Revursive Function that keep sinserting the value into the left or right children

NAME: level_counter
INPUT: pointer root
OUTPUT: void
PURPOSE: This function serves to count the number of levels given by the user specified nodes

NAME: print_level
INPUT: pointer root, integer level
OUTPUT: void
PURPOSE: Utilized in display_tree

NAME: display_tree
INPUT: pointer root
OUTPUT: void
PURPOSE: Displays the tree created with the help of level_counter and print_level

NAME: small_search
INPUT: pointer node
OUTPUT: void
PURPOSE: Searches for the smallest value and identifies it
 
NAME: delete_smallest
INPUT: pointer root, int key
OUTPUT: void
PURPOSE: Utilizes small_search to delete that smallest node

NAME: node_search
INPUT: pointer node, int key
OUTPUT: void
PURPOSE: search for the node, option number 5

NAME: main
INPUT: pointer root, int menu_option, int num, int input_val, int value
OUTPUT: void
PURPOSE: Menu-Driven program to give the user various options regarding trees, utilized all above functions

*/
//Creating a tree in c
//Recordings are found on blackboard collaborate under the menu, click on recordings
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} tree_node;

void create_tree(tree_node **root, int num) //Recursive Function that keeps inserting the value into the left or right children
{
    //if the root node is empty
    if((*root) == NULL)
    {
        //we fill in starting with the root, then if the left child is empty, assign it a number, if its filled, go to the right child, etc
        *root = (tree_node *)malloc(sizeof(tree_node));
        (*root) -> data = num;
        (*root) -> left = NULL;
        (*root) -> right = NULL;
    }
    else
    {
        //here the left child is always less than the root and the right child is always larger than the root, thats how the proffesor built this
        if(num < (*root) -> data)
        {
            create_tree(&((*root) -> left), num);
        }
        else
        {
            create_tree(&((*root) -> right), num);
        }
    }
}
    //function used in "display_tree" function
void level_counter(tree_node *root)
{
    int left_max;
    int right_max;
    if(root == NULL)
    {
        return 0;
    }
    left_max = 1 + level_count(root -> left);
    right_max = 1 + level_count(root -> right);
    //this will return the maximum number of the child level
    if(left_max > right_max)
    {
        return left_max;
    }
    else
    {
        return right_max;
    }
} //This function assumes that the tree created can be skewed, as in more on the left or right side of the tree and returns which side has the greater
    //number of nodes



//function used in "display_tree" function
void print_level(tree_node *root, int level)
{   
    if(root != NULL && level == 0)
    {
        printf("%d\n", root -> data);
    }
    else if(root != NULL)
    {
        print_level(root -> left, level - 1);
        print_level(root -> right, level - 1);
    }
}
void display_tree(tree_node *root)
{
    //counts the number of levels within the previoiusly built tree
    int level = level_counter(root);
    for(int i = 0; i < level; i = i + 1)
    {
        printf("\n");
        print_level(root, i);
    }
}

//Function to search for the smallest value and return it
void small_search(struct node *node)
{
    struct node* current = node;
    while(current && current -> left != NULL)
    {
        current = current -> left;
    }
    return current;
}

//Function that deletes the smallest found value
void delete_smallest(struct node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    //If the key value is greater than the roots value, then delete the node that lies in the left tree
    if(key < root->key)
    {
        root -> left = delete_smallest(root -> left, key);
    }
    //If the key value is smaller than the roots value, then delete the node that lies in the right sub tree
    else if(key > root -> key)
    {
        root -> right = delete_smallest(root -> right, key);
    }
    else
    {
        //These conditional statments account for nodes with one or no children
        if(root -> left == NULL)
        {
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        //This accounts for nodes with two children
        struct node* temp = small_search(root -> right);
        root -> key = temp -> key;
        //Utilize function to delete the smallest value
        root -> right = delete_smallest(root -> right, temp -> key);
    }
    return root;
}

void node_search(struct node* node, int key)
{
    if(node == NULL)
    {
        return false;
    }
    if(node -> data == key)
    {
        return true;
    }

    int rest1 = node_search(node -> left, key);
    if(rest1)
    {
        return true;
    }
    int rest2 = node_search(node -> right, key)
    
}

//do-while loop to keep asking user after they selected a choice
int main(void)
{
    tree_node *root = NULL;
    int menu_option;
    int num; //random value to fill tree nodes
    int input_val; //User defined number of nodes
    int value; 

    do
    {
        printf("Menu Choices: \n");
        printf("1. Create integer binary tree\n");
        printf("2. Display Tree \n");
        printf("3. Delete Smallest Node\n");
        printf("4. Display Tree After Deletion\n");
        printf("5. Search For A Given Value And Show Tracing\n");
        printf("Enter Choice, 0 to exit: \n");
        
        scanf("%d", &menu_option);

        switch(menu_option)
        {
            case 1:
                printf("How many nodes to insert?\n");
                scanf("%d", &input_val);

                for(int i = 0; i < input_val; i = i + 1)
                {
                    num = rand()%100;
                    printf("Insert %d to tree", num);
                    create_tree(&root, num); //input value of the function 'create tree'
                }
            case 2:
                printf("Displaying Tree\n");
                display_tree(root);
                break;
            
            case 3:
                printf("Deleting Smallest Node");
                delete_smallest();
            case 4:
                printf("Displaying Tree After Deletion");
                display_tree(root);
                break;
            //case 5:

            
        }
    }
    while(menu_option != 0);
    printf("Ending Program");
}
//all the funcitons should be outside the main function, i messed up
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct node* createNode(value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode -> item = value;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

//Insert on the left of the node
struct node* inserLeft(struct node* root, int value)
{
    root -> left = createNode(value);
    return root -> left;
}

//Insert on the right of the node
struct node* insertRight(struct node* root, int value)
{
    root -> right = createNode(value);
    return root -> right;
}

int main()
{
    stuct node *root = createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root -> left, 4);

    
}

//Creating random values
#include <time.h>
int random()
{
    printf("Enter n for the number of nodes: ");
    srand(time(NULL));

    for(1 to n)
    {
        int r = rand() % 100; //generate random numbers 0 to 100
    }
}


For this problme we need:

1. switch (options)
2. create node function
3. display tree function
4. remove node function
5. search tree
6. find largest/smallest node

Test on 07/26/21
cover trees and heaps
*/