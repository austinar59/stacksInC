#include "stack.h"

int main() {
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p = createStack(p, 15);
    if(p == NULL)
        return -1;
    push(p, 9);
    push(p, 7);
    int i;
    for(i = 0; i < p->capacity; i++)
        printPop(p);
    p = destroyStack(p);
    return 0;
}