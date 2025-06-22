#include <stdlib.h>
#include <stdio.h>

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