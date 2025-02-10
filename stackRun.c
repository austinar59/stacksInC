#include "stack.h"

int main() {
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p = createStack(p, 15);
    if(p == NULL)
        return -1;
    push(p, 9);
    push(p, 7);
    int q;
    for(q = 0; q < 17; q++) {
        push(p, q);
    }
    int i;
    for(i = 0; i < p->capacity; i++)
        printPop(p);
    p = destroyStack(p);
    return 0;
}