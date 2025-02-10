#include "stack.h"

//TODO: implementing realloc

//initializes data for a stack pointer passed in
Stack* createStack(Stack* s, int capacity) {

    //array for members
    int* members = (int*) malloc(capacity * sizeof(int));
    
    //checks to see if malloc actually worked
    if(members != NULL) {
        s->members = members;
        //sets top to indicate that there are no members
        s->top = -1;
        s->capacity = capacity;
        return s;
    }
    
    //returns null if member allocation failed
    return NULL;
}

//push function
int push(Stack* s, int i) {
    // checks to see that top can hold more; since getSize returns last index + 1
    // we only need to check that the size is less than the capacity
    if(getSize(s) < s->capacity) {
        //pushes member to index above top then increments
        s->members[s->top + 1] = i;
        s->top += 1;
        return 1;
    } else {
        int* members = (int*) realloc(s->members, (s->capacity + 1) * sizeof(Stack));
        if(members == NULL) {
            return 0;
        }
        s->members = members;
        s->capacity++;
        s->members[s->top + 1] = i;
        return 1;
    }
}
int pop(Stack* s) {
    //checks if there's anything to pop
    if(!isEmpty(s)) {
        int ret = s->members[s->top];
        s->top -= 1;
        return ret;
    }
    return -1;
}
int peek(Stack* s) {
    if(!isEmpty(s)) {
        return s->members[s->top];
    }
    return -1;
}
int getSize(Stack* s) {
    return s->top + 1;
}
int getCapacity(Stack* s) {
    return s->capacity;
}
bool isEmpty(Stack* s) {
    if(getSize(s) <= 0)
        return true;
    return false;
}
void printPop(Stack* s) {
    if(!isEmpty(s))
        printf("%d\n", pop(s));
    else printf("Empty stack.\n");
}

//deletes members array and then deletes s before returning NULL, with the
// intent that s be assigned to this
Stack* destroyStack(Stack* s) {
    free(s->members);
    s->members = NULL;
    free(s);
    return NULL;
}