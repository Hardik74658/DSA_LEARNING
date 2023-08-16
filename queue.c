#include <stdio.h>
#include <stdlib.h>

#define S 5

int q[S];
int front = -1, rear = -1;

int isFull()
{
    return (rear == S - 1);
}

int isEmpty()
{
    return (rear == -1);
}
void insert(int num)
{
    if (isFull())
    {
        printf("\nQueue is full");
    }
    else
    {
        rear++;
        q[rear] = num;
        if (front == -1)
        {
            front = 0;
        }
    }
}

int dequeue()
{
    int num = -1;
    if (isEmpty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        num = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("\n%d deleted", num);
    }
    return num;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is Empty");
    }
    printf("\n");
    for (i = front; i <= rear; i++)
    {
        printf(" %d", q[i]);
    }
}

void main()
{
    while (1)
    {
        int choice, num;
        printf("\n0 For Exit \n1 For Insert \n2 For Delete \n3 For Display\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\nEnter Value to Insert : ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n\nInvalid Choice!!!");
        }
    }
}