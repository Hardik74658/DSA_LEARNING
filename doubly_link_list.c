#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next, *prev;
} *head = NULL, *last = NULL, *tmp = NULL, *new_node = NULL;

struct node *createnode(int data);
void insert_last();
void insert_beg();
void insert_Any_After();
void insert_Any_Before();
void delete_beg();
void delete_last();
void deleteAny();
void search();
void display();
void display_rev();

void main()
{

    int choice, data;
    while (1)
    {
        printf("\n0--Exit\n1--Insert a Node At Last\n2--Insert_Beg\n3--Delete_Beg\n4--Delete_last\n5--deleteAny\n6--Search\n7--Insert Any Before\n8--Insert Any After \n9--Display \n10--Display Reverse \nEnter Your Choice : ");
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
        case 10:
            display_rev();
            break;
        default:
            printf("\nInvalid Choice!!");
        }
    }
}

struct node *createnode(int data)
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_last()
{
    int num;
    printf("\nEnter Value : ");
    scanf("%d", &num);
    new_node = createnode(num);
    if (head == NULL)
    {
        head = new_node;
        last = head;
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}
void insert_beg()
{
    int num;
    printf("\nEnter Value : ");
    scanf("%d", &num);
    new_node = createnode(num);
    if (head == NULL)
    {
        head = new_node;
        last = head;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
void insert_Any_After()
{
    int source, num;
    bool isFound = 0;
    printf("\nEnter Source : ");
    scanf("%d", &source);
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == source)
        {
            isFound = 1;
            break;
        }
        tmp = tmp->next;
    }

    if (isFound)
    {
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = createnode(num);
        new_node->next = tmp->next;
        new_node->prev = tmp;
        tmp->next = new_node;
    }
}
void insert_Any_Before()
{
    int source, num;
    bool isFound = 0, isHead = 0;
    printf("\nEnter Source : ");
    scanf("%d", &source);
    tmp = head;
    while (tmp != NULL)
    {
        if (head->data == source)
        {
            isHead = 1;
            break;
        }
        if (tmp->data == source)
        {
            isFound = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (isHead)
    {
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = createnode(num);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    if (isFound)
    {
        printf("\nEnter value : ");
        scanf("%d", &num);
        new_node = createnode(num);
        tmp->prev->next = new_node;
        new_node->prev = tmp->prev;
        tmp->prev = new_node;
        new_node->next = tmp;
    }
}

void delete_beg()
{
    tmp = head;
    head = head->next;
    free(tmp);
}
void delete_last()
{
    last->prev->next = NULL;
    free(last);
}
void deleteAny()
{
    int num;
    printf("\nEnter Number To Delete : ");
    scanf("%d", &num);
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == num)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            break;
        }
        tmp = tmp->next;
    }
}

void search()
{
    int num;
    bool isFound = 0;
    tmp = head;
    printf("\nEnter Number To Search : ");
    scanf("%d", &num);
    while (tmp != NULL)
    {
        if (tmp->data == num)
        {
            isFound = 1;
            break;
        }
        tmp = tmp->next;
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
        tmp = head;
        while (tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
void display_rev()

{
    if (last == NULL)
    {
        printf("\nLink List Is Empty!!");
    }
    else
    {
        printf("\n");
        tmp = last;
        while (tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->prev;
        }
        printf("\n");
    }
}
