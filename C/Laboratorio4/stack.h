#ifndef STACK_H
#define STACK_H

// Definición de la estructura del nodo
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Definición de la estructura de la pila
typedef struct {
    Node* top;
} Stack;

// Prototipos de funciones
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
void printStack(Stack* stack);

#endif // STACK_H