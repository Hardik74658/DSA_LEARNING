#include <stdio.h>
#include <stdlib.h>

#define S 5

int stack[S];
int top = -1;

int isFull()
{
    return (top == S - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int num)
{
    if (isFull())
    {
        printf("\n\nStack is Overflow");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n\nStack is Underflow");
    }
    else
    {
        printf("\n\nElements in Stack:");
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
}

int pop()
{
    int num = -1;
    if (isEmpty())
    {
        printf("\n\nStack is Underflow.");
    }
    else
    {
        num = stack[top];
        printf("\n%d is Popped.", num);
        top--;
    }
    return (num);
}

void main()
{
    int choice, num;
    while (1)
    {
        printf("\n\n0 For Exit \n1 For Push \n2 For Pop \n3 For Display\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\nEnter Number To Push : ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }
}