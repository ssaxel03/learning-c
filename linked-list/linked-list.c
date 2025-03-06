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

void remove(List *list, int value)
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

void free(List *list)
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

void print(List *list) {

    Node *current = list->head;
    size_t i = 1;

    printf("LinkedList Items\n");

    while(current != NULL) {
        printf("Item %zu: %d\n", i, current->data);
        current = current->next;
    }

}

int main()
{
}