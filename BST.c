#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
} *root = NULL, *tmp = NULL, *node = NULL;

struct node *createNode(int num)
{
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 0;
    return tmp;
}

int getHeight(struct node *node)
{
    int lh = 0, rh = 0;
    if (node->left != NULL)
    {
        lh = node->left->height;
    }
    if (node->right != NULL)
    {
        rh = node->right->height;
    }
    return lh > rh ? lh : rh;
}

void addNode(struct node *node, int num)
{
    if (node == NULL)
    {
        node = createNode(num);
    }
    else
    {
        if (node->data > num)
        {
            node->right = createNode(num);
        }
        else
        {
            node->left = createNode(num);
        }
    }
    node->height = 1 + getHeight(node);
}
void display(struct node *node)
{
    if (node != NULL)
    {
        display(node->left);
        printf("%d", node->data);
        display(node->right);
    }
}

void main()
{

    int choice, num;
    while (1)
    {
        printf("\n0--Exit\n1--addNode\n2--Display\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("%d", root->height);
            printf("l-%d", root->left->height);
            printf("r-%d", root->right->height);
            exit(0);
            break;
        case 1:
            printf("Enter data : ");
            scanf("%d", &num);
            addNode(root, num);
            break;
        case 2:
            display(root);
            break;
        default:
            printf("Invalid Choice!!");
        }
    }
}