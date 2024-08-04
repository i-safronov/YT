#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum SupportedTypes
{
    INT,
    DOUBLE,
    FLOAT,
    STRING,
    BOOL
};

struct Node
{
    struct Node *root;
    struct Node *next;
    void *data;
    enum SupportedTypes type;
    int size;
};

struct Node *create_root()
{
    struct Node *list = malloc(sizeof(struct Node));
    if (list == NULL)
    {
        puts("Allocated memory error\n");
        return NULL;
    }
    list->next = NULL;
    list->data = NULL;
    list->data = NULL;
    list->root = list;
    list->size = 0;
    return list;
}

void ale()
{
    puts("Allocated memory error\n");
}

void *add(struct Node *root, void *data, enum SupportedTypes type)
{
    if (root->size == 0)
    {
        root->data = data;
        root->type = type;
        root->next = NULL;
        ++root->size;
        return data;
    }

    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
    {
        puts("Allocated memory error\n");
        return NULL;
    }

    node->type = type;
    node->data = data;
    node->next = NULL;
    struct Node *cr = root;
    while (cr->next != NULL)
    {
        cr = cr->next;
    }

    cr->next = node;
    ++root->size;

    return data;
}

_Bool remove_node(struct Node *root, int index)
{
    if (root->size < index)
    {
        printf("Index is more than list size\n");
        return 0;
    }

    if (index < 0)
    {
        printf("Index is not positive number");
        return 0;
    }

    int idx = 0;

    struct Node *cr = root;

    while (idx++ <= index && cr->next != NULL)
    {
        cr = root->next;
    }

    if (cr->next != NULL)
    {
        struct Node *dl = root->next;
        cr->next = root->next->next;
        --root->size;
        free(dl);
        return 1;
    }
    else
    {
        printf("root->next is NULL");
        return 0;
    }
}

int compare_values(void *data1, void *data2, enum SupportedTypes type)
{
    switch (type)
    {
    case INT:
        return *(int *)data1 == *(int *)data2;
    case DOUBLE:
        return *(double *)data1 == *(double *)data2;
    case FLOAT:
        return *(float *)data1 == *(float *)data2;
    case STRING:
        return strcmp(*(char **)data1, *(char **)data2) == 0;
    case BOOL:
        return *(_Bool *)data1 == *(_Bool *)data2;
    default:
        return 0;
    }
}

_Bool remove_node_by_value(struct Node **root, void *value, enum SupportedTypes type)
{
    struct Node *tmp = *root;
    struct Node *pr = NULL;

    while (tmp != NULL)
    {
        if (compare_values(tmp->data, value, type))
        {
            if (tmp == *root)
            {
                *root = tmp->next;
            }
            else
            {
                pr->next = tmp->next;
            }
            free(tmp);
            if (*root != NULL)
            {
                --(*root)->size;
            }
            return 1;
        }
        pr = tmp;
        tmp = tmp->next;
    }

    printf("Item not found!\n");
    return 0;
}

void *get(struct Node *root, int index)
{
    if (index == 0)
        return root->data;

    struct Node *tmp = root;

    int idx = 0;

    while (tmp != NULL)
    {
        if (idx++ == index)
        {
            return tmp->data;
        }

        tmp = tmp->next;
    }

    return NULL;
}

void printf_i(struct Node *root, enum SupportedTypes type)
{
    struct Node *tmp = root;

    while (tmp != NULL)
    {
        switch (type)
        {
        case INT:
            printf("%d\n", *(int *)tmp->data);
            break;
        case DOUBLE:
            printf("%.2f\n", *(double *)tmp->data);
            break;
        case FLOAT:
            printf("%.2f\n", *(float *)tmp->data);
            break;
        case STRING:
            puts((char *)tmp->data);
            printf("\n");
            break;
        case BOOL:
            printf(*(_Bool *)tmp->data ? "true\n" : "false\n");
            break;
        }
        tmp = tmp->next;
    }
}


void free_i(struct Node **root) {
    struct Node *tmp;

    while (*root != NULL) {
        tmp = (*root)->next;
        free(*root);        
        *root = tmp;
    }
    *root = NULL;
}