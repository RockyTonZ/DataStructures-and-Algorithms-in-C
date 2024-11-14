#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME 256
#define TABLE_SIZE 16
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strlen(name);
    int char_value = name[length / 2];
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value = (name[i] * char_value) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---------\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t<deleted>\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }

    return false;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false;
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strcmp(hash_table[index]->name, name) == 0)
        {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false; // Can't find
        if (hash_table[try] == DELETED_NODE)
            continue;

        if (strcmp(hash_table[try]->name, name) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

int main(void)
{
    init_hash_table();

    person p1 = {.name = "James", .age = 20};
    person p2 = {.name = "Sarah", .age = 25};
    person p3 = {.name = "Bashame", .age = 12};

    hash_table_insert(&p1);
    hash_table_insert(&p2);
    hash_table_insert(&p3);

    person *tmp = hash_table_lookup("James");
    if (tmp != NULL)
    {
        printf("James was found!\n");
    }
    else
    {
        printf("Not Found\n");
    }
    tmp = hash_table_lookup("Chiyo");
    if (tmp != NULL)
    {
        printf("Chiyo was found!\n");
    }
    else
    {
        printf("Not Found\n");
    }

    hash_table_delete("James");
    print_hash_table();
}