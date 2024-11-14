#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME 256
#define TABLE_SIZE 16

typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next;
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
        else
        {
            printf("\t%i\t%s", i, hash_table[i]->name);
            if (hash_table[i]->next != NULL)
            {
                person *tmp = hash_table[i]->next;
                while (tmp != NULL)
                {
                    printf(" -- %s", tmp->name);
                    tmp = tmp->next;
                }
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
        return false;

    int index = hash(p->name);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = p;
    }
    else
    {
        person *tmp = hash_table[index];
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
    return true;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] == NULL)
        return NULL;
    if (hash_table[index]->next == NULL && strcmp(hash_table[index]->name, name) == 0)
    {
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else if (hash_table[index] != NULL)
    {
        person *tmp = hash_table[index]->next;
        person *prev = hash_table[index];
        while (tmp != NULL)
        {
            if (strcmp(tmp->name, name) == 0)
            {
                prev->next = tmp->next;
                return tmp;
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return NULL;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if (hash_table[index] == NULL)
        return NULL;
    if (hash_table[index]->next == NULL && strcmp(hash_table[index]->name, name) == 0)
    {
        return hash_table[index];
    }
    else if (hash_table[index] != NULL)
    {
        person *tmp = hash_table[index]->next;
        while (tmp != NULL)
        {
            if (strcmp(tmp->name, name) == 0)
                return tmp;
            tmp = tmp->next;
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
    person anna = {.name = "Anna", .age = 43};
    person alan = {.name = "Alan", .age = 2};
    hash_table_insert(&p1);
    hash_table_insert(&p2);
    hash_table_insert(&p3);
    hash_table_insert(&anna);
    hash_table_insert(&alan);

    person *tmp1 = hash_table_lookup("James");
    if (tmp1 != NULL)
        printf("Found James!\n");

    person *tmp2 = hash_table_lookup("Alan");
    if (tmp2 != NULL)
        printf("Found Alan!\n");

    person *tmp3 = hash_table_lookup("Osaka");
    if (tmp3 != NULL)
        printf("Found Osaka!\n");

    hash_table_delete("James");
    hash_table_delete("Alan");
    print_hash_table();
}