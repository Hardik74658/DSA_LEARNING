#include <stdio.h>
#include <stdlib.h>

#define S 5

// int pq[S] = {10, 15, 22, 85, 98};
int pq[S];
int rear = -1;
int front = -1;
int i, j, temp;

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
        pq[rear] = num;
        if (front == -1)
        {
            front = 0;
        }
    }
}
void find()
{
    int i, count = 0, num;
    if (isEmpty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("Enter Number to Check : ");
        scanf("%d", &num);
        for (i = 0; i < S; i++)
        {
            if (pq[i] == num)
            {
                printf("%d found", pq[i]);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\n%d is not Available", num);
        }
    }
}
void sort()
{
    for (i = 0; i < S; i++)
    {
        for (j = i; j < S; j++)
        {
            if (pq[j] % 2 == 0 && pq[i] % 2 != 0)
            {
                temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
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
        sort();
        num = pq[front];
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
    sort();
    for (i = front; i <= rear; i++)
    {
        printf(" %d", pq[i]);
    }
}

void main()
{
    while (1)
    {
        int choice, num;
        printf("\n0 For Exit \n1 For Insert \n2 For Delete \n3 For Display\n4 For Search\nEnter Your Choice : ");
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
        case 4:
            find();
            break;
        default:
            printf("\n\nInvalid Choice!!!");
        }
    }
}