// Arrays
void print_arr(int n, int *arr);
void arrcpy(int n, int *arr1, int *arr2);

//Linked Lists
typedef struct _q_node
{
    int value;
    struct _q_node *prev;
    struct _q_node *next;
}
q_node;

typedef struct _s_node
{
    int value;
    struct _s_node *prev;
}
s_node;


typedef struct queue
{
    q_node *head;
    q_node *tail;
}
queue;

queue* create_queue(void);
queue* enqueue(queue *q, int value);
queue* dequeue(queue *q);
void print_queue(queue *q);
void destroy_queue(queue *q);

typedef struct stack
{
    s_node *top;
}
stack;

stack* create_stack(void);
stack* push(stack *s, int value);
stack* pop(stack *s);
void print_stack(stack *s);
void destroy_stack(stack *s);