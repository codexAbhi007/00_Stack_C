//Stack implementation using Array

#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

//Function prototypes

int isFull();
int isEmpty();
void push(int data);
int pop();
void peek();
void display();

//Main 

int main()
{
    int choice, data;
    int flag = 1;
    int popValue;

    while(flag){
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Is Full?\n5. Is Empty?\n6. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&data);
                push(data);
                break;
            
            case 2:
                popValue = pop();
                if(popValue != 0)
                    printf("Popped Value: %d\n",popValue);
                break;
            
            case 3:
                peek();
                break;
            case 4:
                printf(isFull() ? "Stack is Full\n" : "Stack is not Full\n");
                break;
            
            case 5:
                printf(isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
                break;
            case 6:
                display();
                break;
            case 0:
                printf("Exiting\n");
                flag = 0;
                break;
            default:
                printf("Invalid Choice! Try Again\n");
        }
    }

    return 0;
}


//Function definitions

int isFull()
{
    return top == SIZE -1;
}

int isEmpty()
{
    return top == -1;
}

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow!");

    }
    else{
        stack[++top] =data;
        printf("%d pushed to stack!\n",data);
    }
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow!");
        return 0;
    }
    return stack[top--];
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is empty!");
    }
    else{
        printf("Top element is %d\n",stack[top]);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is Empty");
        return;
    }
    int i;
    for(i = 0;i <= top;++i)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}