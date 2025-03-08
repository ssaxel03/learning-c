#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 10

typedef struct Stack
{
    int *items;
    int maxSize;
    int topItemIndex;
} Stack;

int isStackEmpty(Stack *stack)
{
    return stack->topItemIndex == -1;
}

int isStackFull(Stack *stack)
{
    return stack->topItemIndex == stack->maxSize - 1;
}

void initStack(Stack *stack, int maxSize)
{
    stack->items = malloc(maxSize * sizeof(int));
    stack->maxSize = maxSize;
    stack->topItemIndex = -1;
}

void pushStack(Stack *stack, int value)
{

    if (isStackFull(stack))
    {
        printf("Couldn't push, stack is full!\n");
        return;
    }

    stack->topItemIndex++;

    stack->items[stack->topItemIndex] = value;

    printf("%d has been pushed to index %d of the stack.\n", value, stack->topItemIndex);
}

int popStack(Stack *stack)
{

    if (isStackEmpty(stack))
    {
        printf("Couldn't pop, the stack is empty!\n");
        return -1;
    }

    int topItem = stack->items[stack->topItemIndex];

    stack->topItemIndex--;

    return topItem;
}

int peekStack(Stack *stack)
{

    if (isStackEmpty(stack))
    {
        printf("Couldn't peek, the stack is empty!\n");
        return -1;
    }

    return stack->items[stack->topItemIndex];
}

void printStack(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Couldn't print, the stack is empty!\n");
        return;
    }

    printf("Stack (top to bottom)\n");

    for (int i = stack->topItemIndex; i > -1; i--)
    {
        printf("%d\n", stack->items[i]);
    }
    
}

int main()
{

    Stack *stack = malloc(sizeof(Stack));
    initStack(stack, STACK_MAX_SIZE);

    pushStack(stack, 5);
    pushStack(stack, 10);
    pushStack(stack, 15);

    printStack(stack);

    printf("Top item: %d\n", peekStack(stack));

    printf("Popped item: %d\n", popStack(stack));
    printStack(stack);

    free(stack->items);
    free(stack);

    return 0;
}