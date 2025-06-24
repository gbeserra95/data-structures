#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Arrays
void print_arr(int n, int *arr)
{
    for(int i = 0; i < n; i++)
        printf("%i ", arr[i]);

    printf("\n");
}

void arrcpy(int n, int *src, int *dest)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i]; 
}

// Linked Lists
queue* create_queue(void)
{
    queue *q = malloc(sizeof(queue));

    if (q == NULL)
    {
        printf("Couldn't allocate memory for queue.\n");
        return NULL;
    }

    q->head = NULL;
    q->tail = NULL;

    return q;
}

queue* enqueue(queue *q, int value)
{
    q_node *n = malloc(sizeof(q_node));

    if (n == NULL)
    {
        printf("Couldn't allocate memory for node.\n");
        return NULL;
    }

    n->value = value;
    
    if (q->tail == NULL)
    {
        q->head = n;
        q->tail = n;
        q->tail->prev = NULL;
        q->tail->next = NULL;
    }
    else
    {
        n->prev = q->tail;
        n->next = NULL;
    
        q->tail->next = n;
        q->tail = n;
    }

    return q;
}

queue* dequeue(queue *q)
{
    if (q->head == NULL)
        return q;

    if (q->head->next == NULL)
    {
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
    }
    else
    {
        q_node *n = q->head->next;
        n->prev = NULL;
    
        free(q->head);
        q->head = n;
    }

    return q;
}

void print_queue(queue *q)
{
    for (q_node *ptr = q->head; ptr != NULL; ptr = ptr->next)
        printf("%i ", ptr->value);

    printf("\n");
}

void destroy_queue(queue *q)
{
    q_node *ptr = q->head;
    while(ptr != NULL)
    {
        q_node *n = ptr->next;
        free(ptr);
        ptr = n;
    }

    free(q);
}

stack* create_stack(void)
{
    stack *s = malloc(sizeof(stack));

    if (s == NULL)
    {
        printf("Couldn't allocate memory for stack.\n");
        return NULL;
    }

    s->top = NULL;

    return s;
}

stack* push(stack *s, int value)
{
    s_node *n = malloc(sizeof(s_node));

    if (n == NULL)
    {
        printf("Couldn't allocate memory for node.\n");
        return NULL;
    }

    n->value = value;
    n->prev = s->top;
    s->top = n;

    return s;
}

stack* pop(stack *s)
{
    if (s->top == NULL)
        return s;

    s_node *n = s->top;

    s->top = n->prev;
    free(n);

    return s;
}

void print_stack(stack *s)
{
    for (s_node *ptr = s->top; ptr != NULL; ptr = ptr->prev)
        printf("%i ", ptr->value);

    printf("\n");
}

void destroy_stack(stack *s)
{
    s_node *ptr = s->top;
    while(ptr != NULL)
    {
        s_node *n = ptr->prev;
        free(ptr);
        ptr = n;
    }

    free(s);
}

// Hash Table
hash* create_hash(void) {
    hash *h = malloc(sizeof(hash));
    if (h == NULL) return NULL;

    for (int i = 0; i < HASH_MAX; i++)
        h->list[i] = NULL;

    return h;
}

unsigned int hash_code(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
        sum += key[i];
    return sum % HASH_MAX;
}

void insert(hash *h, char *key, char *value) {
    unsigned int index = hash_code(key);
    h_node *ptr = h->list[index];

    while (ptr != NULL) {
        if (strcmp(ptr->key, key) == 0) {
            printf("There is already a key with the value '%s'\n", key);
            return;
        }
        ptr = ptr->next;
    }

    h_node *node = malloc(sizeof(h_node));
    if (node == NULL) {
        printf("Couldn't allocate memory for node\n");
        return;
    }

    node->key = malloc(strlen(key) + 1);
    node->value = malloc(strlen(value) + 1);
    if (!node->key || !node->value) {
        printf("Couldn't allocate memory for key/value\n");
        free(node->key);
        free(node->value);
        free(node);
        return;
    }

    strcpy(node->key, key);
    strcpy(node->value, value);
    node->prev = NULL;
    node->next = NULL;

    ptr = h->list[index];
    if (ptr == NULL) {
        h->list[index] = node;
    } else {
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = node;
        node->prev = ptr;
    }
}

void update(hash *h, char *key, char *value) {
    unsigned int index = hash_code(key);
    for (h_node *ptr = h->list[index]; ptr != NULL; ptr = ptr->next) {
        if (strcmp(ptr->key, key) == 0) {
            free(ptr->value);
            ptr->value = malloc(strlen(value) + 1);
            if (ptr->value == NULL) {
                printf("Couldn't allocate memory for new value\n");
                return;
            }
            strcpy(ptr->value, value);
            return;
        }
    }
    printf("There is no key with the value '%s'\n", key);
}

void delete(hash *h, char *key) {
    unsigned int index = hash_code(key);
    h_node *ptr = h->list[index];

    while (ptr != NULL) {
        if (strcmp(ptr->key, key) == 0) {
            if (ptr->prev != NULL)
                ptr->prev->next = ptr->next;
            else
                h->list[index] = ptr->next;

            if (ptr->next != NULL)
                ptr->next->prev = ptr->prev;

            free(ptr->key);
            free(ptr->value);
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }

    printf("There is no key with the value '%s'\n", key);
}

char* search(hash *h, char *key) {
    unsigned int index = hash_code(key);
    for (h_node *ptr = h->list[index]; ptr != NULL; ptr = ptr->next) {
        if (strcmp(ptr->key, key) == 0)
            return ptr->value;
    }
    printf("There is no key with the value '%s'\n", key);
    return NULL;
}

void destroy_hash(hash *h) {
    for (int i = 0; i < HASH_MAX; i++)
        destroy_list(h->list[i]);
    free(h);
}

void destroy_list(h_node *n) {
    while (n != NULL) {
        h_node *next = n->next;
        free(n->key);
        free(n->value);
        free(n);
        n = next;
    }
}
