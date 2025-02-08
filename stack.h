#ifndef STACK_H
#define STACK_H
    #import <stdbool.h>
    #import <stdlib.h>
    #import <stdio.h>
        typedef struct Stack {
            int* members;
            int top;
            int capacity;
        } Stack;
        Stack* createStack(Stack*, int);
        void push(Stack, int);
        int pop(Stack);
        int peek(Stack);
        int getSize(Stack);
        int getCapacity(Stack);
        bool isEmpty(Stack);
#endif
