#include <stdio.h>
#include <stdlib.h>

#define TAMAÑO_POR_DEFECTO 5
#define TAMAÑO_MÁXIMO 10

int encontrarCuadradoMásGrande(int matriz[][TAMAÑO_MÁXIMO], int n) {
    int tamañoMásGrande = 0;

    for (int fila = 0; fila < n; ++fila) {
        for (int col = 0; col < n; ++col) {
            if (matriz[fila][col] != 1)
                continue;

            int tamaño = 1;
            while (fila + tamaño < n && col + tamaño < n) {
                int i;
                for (i = 0; i <= tamaño; ++i) {
                    if (matriz[fila + i][col + tamaño] != 1 || matriz[fila + tamaño][col + i] != 1)
                        break;
                }
                if (i <= tamaño)
                    break;
                ++tamaño;
            }
            if (tamaño > tamañoMásGrande)
                tamañoMásGrande = tamaño;
        }
    }

    return tamañoMásGrande;
}

void mostrarMatriz(int matriz[][TAMAÑO_MÁXIMO], int n) {
    printf("La matriz generada de forma aleatoria es:\n");
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            printf("%d ", matriz[i][j++]);
        }
        printf("\n");
        i++;
    }
}

int main() {
    int tamaño;

    // Solicitar al usuario el tamaño de la matriz
    printf("Introduzca el tamaño deseado para la matriz cuadrada (entre 1 y %d): ", TAMAÑO_MÁXIMO);
    scanf("%d", &tamaño);

    // Verificar si el tamaño es válido
    if (tamaño < 1 || tamaño > TAMAÑO_MÁXIMO) {
        printf("Tamaño de matriz inválido. Se utilizará el tamaño predeterminado: %d.\n", TAMAÑO_POR_DEFECTO);
        tamaño = TAMAÑO_POR_DEFECTO;
    }

    // Generar una matriz aleatoria
    int matriz[TAMAÑO_MÁXIMO][TAMAÑO_MÁXIMO];
    for (int i = 0; i < tamaño * tamaño; ++i) {
        matriz[i / tamaño][i % tamaño] = rand() % 2;
    }

    // Mostrar la matriz
    mostrarMatriz(matriz, tamaño);

    // Encontrar el tamaño del cuadrado más grande de unos
    int tamañoCuadradoMásGrande = encontrarCuadradoMásGrande(matriz, tamaño);

    // Imprimir el resultado
    if (tamañoCuadradoMásGrande > 0) {
        printf("El cuadrado más grande de unos en la matriz es de tamaño %dx%d.\n", tamañoCuadradoMásGrande, tamañoCuadradoMásGrande);
    } else {
        printf("No se encontró ningún cuadrado de unos en la matriz.\n");
    }

    return 0;
}