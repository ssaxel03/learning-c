#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

void initList(List *list)
{
    list->head = NULL;
}

void pushFront(List *list, int value)
{

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = list->head;

    list->head = newNode;
}

void pushBack(List *list, int value)
{

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }

    Node *lastNode = list->head;

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

void removeValue(List *list, int value)
{

    if (list->head == NULL)
    {
        return;
    }

    if (list->head->data == value)
    {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    previous->next = current->next;
    free(current);
}

void freeList(List *list)
{
    Node *current = list->head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}

void print(List *list)
{

    Node *current = list->head;
    size_t i = 1;

    printf("LinkedList Items\n");

    while (current != NULL)
    {
        printf("Item %zu: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

int main()
{
    List *list = malloc(sizeof(List));

    if (list == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    initList(list);

    printf("LinkedList Test Program\n\n");

    size_t opt = 0;

    while (opt != 6)
    {

        printf("Menu\n");
        printf("1 - Print list\n");
        printf("2 - Push item to front\n");
        printf("3 - Push item to back\n");
        printf("4 - Remove item\n");
        printf("5 - Free list\n");
        printf("6 - Exit\n");

        scanf("%zu", &opt);
        getchar();

        int value;

        switch (opt)
        {
        case 1:
            print(list);
            break;
        case 2:
            printf("Value to be pushed: ");
            scanf("%d", &value);
            getchar();
            pushFront(list, value);
            break;
        case 3:
            printf("Value to be pushed: ");
            scanf("%d", &value);
            getchar();
            pushBack(list, value);
            break;
        case 4:
            printf("Value to be removed: ");
            scanf("%d", &value);
            getchar();
            removeValue(list, value);
            break;
        case 5:
            freeList(list);
            break;
        case 6:
            freeList(list);
            free(list);
            break;
        default:
            printf("Input not valid\n");
            break;
        }
    }
}