#include <stdio.h>

// Función que realiza la búsqueda lineal
int encontrarElemento(int lista[], int longitud, int objetivo) {
    int i = 0;
    while (i < longitud) {
        if (lista[i] == objetivo) {
            return i; // Retorna la posición si encuentra el objetivo
        }
        i++;
    }
    return -1; // Retorna -1 si no encuentra el objetivo
}

// Función que realiza la búsqueda binaria 
int busquedaBinaria(int arreglo[], int inicio, int final, int objetivo) {
    while (inicio <= final) {
        int medio = inicio + (final - inicio) / 2;
        if (arreglo[medio] == objetivo) {
            return medio; // Retorna la posición si encuentra el objetivo
        }
        if (arreglo[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            final = medio - 1;
        }
    }
    return -1; // Retorna -1 si no encuentra el objetivo
}

// Función auxiliar recursiva para la búsqueda binaria
int busquedaBinariaRecursiva(int arreglo[], int inicio, int final, int objetivo) {
    if (inicio <= final) {
        int medio = inicio + (final - inicio) / 2;
        if (arreglo[medio] == objetivo) {
            return medio; // Retorna la posición si encuentra el objetivo
        }
        if (arreglo[medio] < objetivo) {
            return busquedaBinariaRecursiva(arreglo, medio + 1, final, objetivo);
        }
        return busquedaBinariaRecursiva(arreglo, inicio, medio - 1, objetivo);
    }
    return -1; // Retorna -1 si no encuentra el objetivo
}

int main() {
    int numeros[] = {2, 4, 6, 23, 56, 79};
    
    // Calcula el número de elementos en el arreglo
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    int ValorBuscar;
    printf("Ingrese un valor entero: ");
    scanf("%d", &ValorBuscar);

    int posicion = encontrarElemento(numeros, tamano, ValorBuscar);

    // Imprime el resultado de encontrarElemento
    if (posicion != -1) {
        printf("El número %d está en la posición %d del arreglo.\n", ValorBuscar, posicion);
    } else {
        printf("Error: El número %d no fue encontrado en el arreglo.\n", ValorBuscar);
    }

    int posiciónB = busquedaBinaria(numeros, 0, tamano - 1, ValorBuscar);

    // Imprime el resultado de busquedaBinaria
    if (posiciónB != -1) {
        printf("El número %d está en la posición %d del arreglo.\n", ValorBuscar, posiciónB);
    } else {
        printf("Error: El número %d no fue encontrado en el arreglo.\n", ValorBuscar);
    }

    int posiciónBR = busquedaBinariaRecursiva(numeros, 0, tamano - 1, ValorBuscar);

    // Imprime el resultado de busquedaBinariaRecursiva
    if (posiciónBR != -1) {
        printf("El número %d está en la posición %d del arreglo.\n", ValorBuscar, posiciónBR);
    } else {
        printf("Error: El número %d no fue encontrado en el arreglo.\n", ValorBuscar);
    }

    return 0;
}
