#include <stdio.h>
#include <stdlib.h>

#include "../helpers.h"

int main(void)
{
    stack *s = create_stack();

    if (s == NULL)
        return 1;

    int n = 10;
    for (int i = 0; i < n; i++)
    {
        s = push(s, 10 * i);

        if (s == NULL)
            return 2;
    }

    print_stack(s);

    n = 2;
    for (int i = 0; i < n; i++)
    {
        s = pop(s);
        
        if (s == NULL)
            return 2;
    }

    print_stack(s);
    destroy_stack(s);
}