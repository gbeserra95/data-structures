#define HASH_MAX 100

// Array
void print_arr(int n, int *arr);
void arrcpy(int n, int *src, int *dest);

//Linked List
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

// Hash Table
typedef struct _h_node {
    char *key;
    char *value;
    struct _h_node *prev;
    struct _h_node *next;
} h_node;

typedef struct hash {
    h_node *list[HASH_MAX];
} hash;

hash* create_hash(void);
unsigned int hash_code(char *key);
void insert(hash *h, char *key, char *value);
void update(hash *h, char *key, char *value);
void delete(hash *h, char *key);
char* search(hash *h, char *key);
void destroy_hash(hash *h);
void destroy_list(h_node *n);