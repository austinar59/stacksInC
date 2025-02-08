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
void push(Stack* s, int i) {
    // checks to see that top can hold more; since getSize returns last index + 1
    // we only need to check that the size is less than the capacity
    if(getSize(s) < s->capacity) {
        //pushes member to index above top then increments
        s->members[s->top + 1] = i;
        s->top += 1;
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
}
int getSize(Stack* s) {
    return s->top + 1;
}
int getCapacity(Stack* s) {
    return s->capacity
}
bool isEmpty(Stack* s) {
    if(getSize(s) <= 0)
        return true;
    return false;
}