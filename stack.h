#ifndef STACK_H
#define STACK_H
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
        typedef struct Stack {
            int* members;
            int top;
            int capacity;
        } Stack;
        Stack* createStack(Stack*, int);
        int push(Stack*, int);
        int pop(Stack*);
        int peek(Stack*);
        int getSize(Stack*);
        int getCapacity(Stack*);
        bool isEmpty(Stack*);
        void printPop(Stack*);
        Stack* destroyStack(Stack*);
#endif
