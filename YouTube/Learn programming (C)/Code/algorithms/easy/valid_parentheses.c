#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

_Bool isValid(char* s) {
    int size = strlen(s); 
    if (size < 2) return 0; 
    struct Stack* stack = createStack(size);
    int idx = 0; 
    int ss = 0; 

    while (s[idx] != '\0') {
        if (s[idx] == '(' || s[idx] == '[' || s[idx] == '{') {
            push(stack, s[idx]); 
            --ss; 
        } else {
            char p = pop(stack); 
            if (s[idx] == ')' && p != '(') 
                return 0;  
            if (s[idx] == ']' && p != '[')
                return 0; 
            if (s[idx] == '}' && p != '{') 
                return 0; 
            ss++; 
        }
        ++idx;
    }

    if (ss != 0) return 0;

    return 1; 
}