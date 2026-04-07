#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;  // Crear una pila
    stack.top = NULL;  // Inicializar la pila como vacía

    int choice;
    int value;

    do {
        // Menú de opciones para el usuario
        printf("\nOpciones:\n");
        printf("1. Push (Agregar un elemento)\n");
        printf("2. Pop (Eliminar y mostrar el elemento superior)\n");
        printf("3. Peek (Mostrar el elemento superior)\n");
        printf("4. Mostrar pila completa\n");
        printf("5. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &value);
                push(&stack, value);
                printf("Se agregó %d a la pila.\n", value);
                printStack(&stack);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Elemento extraído de la pila: %d\n", value);
                }
                printStack(&stack);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Elemento en la parte superior de la pila: %d\n", value);
                }
                break;
            case 4:
                printStack(&stack);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

        while (getchar() != '\n'); // Limpiar el buffer de entrada

    } while (choice != 5);

    return 0;
}