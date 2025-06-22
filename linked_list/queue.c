#include <stdio.h>
#include <stdlib.h>

#include "../helpers.h"

int main(void)
{
    queue *q = create_queue();

    if (q == NULL)
        return 1;

    int n = 10;
    for (int i = 0; i < n; i++)
    {
        q = enqueue(q, 10 * i);

        if (q == NULL)
            return 2;
    }

    print_queue(q);

    n = 2;
    for (int i = 0; i < n; i++)
    {
        q = dequeue(q);
        
        if (q == NULL)
            return 2;
    }

    print_queue(q);
    destroy_queue(q);
}