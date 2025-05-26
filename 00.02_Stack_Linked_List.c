//Stack implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

//Defining the structure
struct Node{
    int data;
    struct Node* next;
};

//Top pointer
struct Node* top = NULL;

//Function prototypes

int isEmpty();
void push(int value);
int pop();
void peek();
void display();

int main()
{
    int choice, value, poppedValue;
    int flag = 1;

    while(flag)
    {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Is empty?\n5. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            
            case 2:
                poppedValue = pop();
                if(poppedValue != 0)
                {
                    printf("Popped value is %d",poppedValue);
                }
                break;

            case 3:
                peek();
                break;
            
            case 4:
                printf(isEmpty() ? "Stack is Empty!\n" : "Stack is not Empty\n");
                break;
            
            case 5:
                display();
                break;

            case 0:
                printf("Exiting.\n");
                flag = 0;
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}

//Function definitions

int isEmpty()
{
    return top == NULL;
}

void push(int value)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if(!new)
    {
        printf("Memory Allocation failed!");
        return;
    }

    new->data = value;
    new->next = top;
    top = new;
    printf("Pushed %d to stack\n",value);
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow! Cannot pop\n");
        return 0;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");

    }
    else{
        printf("Top element is %d\n",top->data);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return ;
    }
    struct Node* temp = top;
    printf("Stack-> ");
    
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}