//Infix to Postfix using stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

//Function prototypes

void push(char ch);
char pop();
char peek();
int isOperator(char ch);
int precedence(char op);
int isRightAssociative(char op);
void infixToPostfix(char* infix);

char stack[MAX];
int top = -1;
char postfix[MAX];
int k = 0;

//Main

int main()
{
    char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-i";

    printf("Infix Expression : %s\n",infix);
    infixToPostfix(infix);
    printf("Postfix Expression: %s\n",postfix);

    return 0;
}

//Function Definitions

void push(char ch)
{
    if(top >= MAX -1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek()
{
    if(top == -1) return '\0';
    return stack[top];
}

//check if character is operator
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op)
{
    switch(op)
    {
        case '^':return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

//check right associativity
int isRightAssociative(char op)
{
    return op == '^';
}

//convert infix to postfix main logic
void infixToPostfix(char* infix)
{
    char ch;

    int i;
    for(i = 0;infix[i] != '\0'; ++i)
    {
        ch = infix[i];

        if(isalpha(ch))
        {
            postfix[k++] = ch; //append if operand
        }

        else if(ch == '(')
        {
            push(ch); //push to stack
        }

        else if(ch == ')')
        {
            while(peek()!='(')
            {
                postfix[k++] = pop(); // Pop till ( is encountered
            }
            pop(); //Pop ( as well
        }

        else if(isOperator(ch))
        {
            while(top != -1 && peek() != '(' &&
                    (precedence(peek()) > precedence(ch) ||
                    (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))){
                        postfix[k++] = pop(); 
                    }
                    push(ch);
        }
    }

    while(top != -1)
    {
        postfix[k++] = pop(); //Pop remaining operators
    }

    postfix[k] = '\0'; //Null terminator for string
}