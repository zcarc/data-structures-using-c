
#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

int main ()
{
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 10);
    SPush(&stack, 20);
    SPush(&stack, 30);
    SPush(&stack, 40);

    while(!SIsEmpty(&stack))
        printf("%d\n", SPop(&stack));

    free(stack.plist);

    return 0;
}