//Infix to Postfix using stack
//Postfix Expression calculation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

//Function prototypes

void push(char ch);
char pop();
char peek();
int isOperator(char ch);
int precedence(char op);
int isRightAssociative(char op);
void infixToPostfix(char* infix);
double evaluatePostfix(char* postfix);

char stack[MAX];
int top = -1;
char postfix[MAX];
int k = 0;

//Main

int main()
{
    char infix[MAX] = "5+6-(2^3/2)-7+5^2";
    

    printf("Infix Expression : %s\n",infix);
    infixToPostfix(infix);
    printf("Postfix Expression: %s\n",postfix);
    double res = evaluatePostfix(postfix);
    printf("Result: %lf",res);
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

        if(isalnum(ch))
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

double evaluatePostfix(char* postfix)
{
    double valStack[MAX];
    int valTop = -1;
    int i;
    char ch;

    for(i = 0;postfix[i]!='\0';++i)
    {
        ch = postfix[i];

        if(isdigit(ch))
        {
            valStack[++valTop] = ch - '0';
        }

        else if(isOperator(ch))
        {
            if(valTop < 1)
            {
                printf("Invalid Expression");
                exit(1);
            }

            double rightVal = valStack[valTop--];
            double leftVal = valStack[valTop--];
            double result;

            switch(ch)
            {
                case '+': result = leftVal + rightVal;break;
                case '-': result = leftVal - rightVal;break;
                case '*': result = leftVal * rightVal;break;
                case '/': 
                    if(rightVal == 0)
                    {
                        printf("Division by zero Error\n");
                        exit(1);
                    }
                    result = leftVal/rightVal;
                    break;
                case '^':result = pow(leftVal,rightVal);break;

                default:
                    printf("Unknown Operator!\n");
                    exit(1);
            }

            valStack[++valTop] = result;
        }
    }


    if(valTop != 0)
    {
        printf("Invalid Expression!\n");
        exit(1);
    }

    return valStack[valTop];
}

