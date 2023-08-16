#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
} *head, *last, *temp;

void insert_last();
void insert_beg();
void insert_Any_After();
void insert_Any_Before();
void delete_beg();
void delete_last();
void deleteAny();
void search();
void display();
void main()
{
    int choice, data;
    while (1)
    {
        printf("\n0--Exit\n1--Insert a Node At Last\n2--Insert_Beg\n3--Delete_Beg\n4--Delete_last\n5--deleteAny\n6--Search\n7--Insert Any Before\n8--Insert Any After \n9--Display\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            insert_last();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            delete_beg();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            deleteAny();
            break;
        case 6:
            search();
            break;
        case 7:
            insert_Any_Before();
            break;
        case 8:
            insert_Any_After();
            break;
        case 9:
            display();
            break;
        default:
            printf("\nInvalid Choice!!");
        }
    }
}

void insert_last()
{
    int num;
    struct node *new_node;
    printf("\nEnter Value : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        last = head;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        last = new_node;
    }
}
void insert_beg()
{
    int num;
    struct node *new_node;
    printf("\nEnter Value : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        last = head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_Any_After()
{
    int source, num;
    bool isFound = 0;
    printf("\nEnter Source : ");
    scanf("%d", &source);
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == source)
        {
            isFound = 1;
            break;
        }
        temp = temp->next;
    }

    if (isFound)
    {
        struct node *new_node;
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void insert_Any_Before()
{
    int source, num;
    struct node *p;
    bool isFound = 0, isHead = 0;
    printf("\nEnter Source : ");
    scanf("%d", &source);
    temp = head;
    while (temp != NULL)
    {
        if (head->data == source)
        {
            isHead = 1;
            break;
        }
        else if (temp->data == source)
        {
            isFound = 1;
            break;
        }
        p = temp;
        temp = temp->next;
    }

    if (isFound)
    {
        struct node *new_node;
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = temp;
        p->next = new_node;
    }
    else if (isHead)
    {
        struct node *new_node;
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = head;
        head = new_node;
    }
}

void delete_beg()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}
void delete_last()
{
    temp = head;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(last);
}
void deleteAny()
{
    int num;
    struct node *p;
    printf("\nEnter Number To Delete : ");
    scanf("%d", &num);
    p = head;
    temp = head->next;
    while (temp != NULL)
    {
        if (head->data == num)
        {
            head = head->next;
            free(p);
            break;
        }
        else if (temp->data == num)
        {
            p->next = temp->next;
            free(temp);
            break;
        }
        else
        {
            p = temp;
            temp = temp->next;
        }
    }
}

void search()
{
    int num;
    bool isFound = 0;
    temp = head;
    printf("\nEnter Number To Search : ");
    scanf("%d", &num);
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            isFound = 1;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (isFound == 1)
    {
        printf("\n%d Found", num);
    }
    else
    {
        printf("\n%d Not Found", num);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nLink List Is Empty!!");
    }
    else
    {
        printf("\n");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}