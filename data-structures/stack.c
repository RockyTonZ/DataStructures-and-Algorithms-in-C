#include <stdio.h>

struct Stack
{
    int items[10];
    int top;
};

// Initializes the stack to be empty
void init(struct Stack *s)
{
    s->top = -1;
}

// Checks if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Checks if the stack is full
int isFull(struct Stack *s)
{
    return s->top == 10 - 1;
}

// Pushes a new item onto the stack
void push(struct Stack *s, int data)
{
    if (isFull(s))
    {
        printf("The stack is full\n");
        return;
    }
    s->items[++(s->top)] = data;
}

// Pops an item from the stack
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Main function to demonstrate stack operations
int main(void)
{
    struct Stack stack;
    init(&stack);

    // Attempt to pop from an empty stack
    pop(&stack);

    // Push elements onto the stack
    for (int i = 0; i < 10; i++)
    {
        push(&stack, i);
    }

    // Attempt to push onto a full stack
    push(&stack, 10);

    // Pop all elements from the stack
    while (!isEmpty(&stack))
    {
        printf("Popped: %d\n", pop(&stack));
    }

    pop(&stack);

    return 0;
}
