#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Función para agregar un elemento a la parte superior de la pila
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    newNode->prev = NULL;
    if (stack->top != NULL) {
        stack->top->prev = newNode;
    }
    stack->top = newNode;
}

// Función para eliminar y devolver el elemento en la parte superior de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }
    free(temp);
    return poppedValue;
}

// Función para devolver el elemento en la parte superior de la pila sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: La pila está vacía\n");
        return -1;
    }
    return stack->top->data;
}

// Función para verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Función para imprimir el contenido de la pila
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía\n");
        return;
    }
    Node* current = stack->top;
    printf("Contenido de la pila:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}