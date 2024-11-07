#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int length;
    struct Node *head;
};

struct Node
{
    int data;
    struct Node *next;
};

// Functions
void insertAtBeginnig(struct LinkedList *list, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

void insertAtEnd(struct LinkedList *list, int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = d;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        struct Node *tmp = list->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void delete(struct LinkedList *list, int d)
{
    struct Node *tmp = list->head;
    struct Node *prev = NULL;

    if (tmp != NULL && tmp->data == d)
    {
        list->head = tmp->next;
        free(tmp);
        list->length--;
        return;
    }

    while (tmp != NULL && tmp->data != d)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        printf("Data not found.\n");
        return;
    }

    prev->next = tmp->next;

    free(tmp);
    list->length--;
}

void printList(struct LinkedList *list)
{
    struct Node *tmp = list->head;
    while (tmp != NULL)
    {
        printf("%i ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// Main Function
int main(void)
{
    struct LinkedList list;
    list.head = NULL;
    list.length = 0;

    insertAtBeginnig(&list, 1);
    insertAtBeginnig(&list, 2);
    insertAtBeginnig(&list, 3);
    insertAtBeginnig(&list, 4);
    insertAtEnd(&list, 8);
    delete (&list, 7);
    printList(&list);
}