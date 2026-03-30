#include <stdio.h>

int encontrarMinimo(int arreglo[], int tamaño) {
    // se inicializa el primer elemento como mínimo inicial
    int mínimo = arreglo[0];
    
    for (int i = 1; i < tamaño; i++) {
        mínimo = (arreglo[i] < mínimo) ? arreglo[i] : mínimo;
    }
    
    return mínimo; 
}

int encontrarMaximo(int arreglo[], int tamaño) {
    // se inicializa el primer elemento como maximo inicial
    int máximo = arreglo[0];
    
    for (int i = 1; i < tamaño; i++) {
        máximo = (arreglo[i] > máximo) ? arreglo[i] : máximo;
    }
    
    return máximo; 
}

// valor mínimo y máximo utilizando punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    // Inicializamos minimo y maximo con el primer elemento
    *minimo = *arreglo;
    *maximo = *arreglo;
    
    // Se itera sobre el arreglo para encontrar el valor mínimo y máximo
    for (int i = 1; i < longitud; i++) {
        if (*(arreglo + i) < *minimo) {
            *minimo = *(arreglo + i);
        } else if (*(arreglo + i) > *maximo) {
            *maximo = *(arreglo + i);
        }
    }
}

int main() {
    int números[] = {21, 24, 65, 3, 56, 12, 35, 15};
    
    // tamaño del arreglo
    int tamaño = sizeof(números) / sizeof(números[0]);
    
    // función para encontrar el valor mínimo
    int mínimo = encontrarMinimo(números, tamaño);
    printf("El valor mínimo en el arreglo es: %d\n", mínimo);

    // función para encontrar el valor máximo
    int máximo = encontrarMaximo(números, tamaño);
    printf("El valor máximo en el arreglo es: %d\n", máximo);
    
    int min, max;
    
    // Llamamos a la función para encontrar el valor mínimo y máximo usando punteros
    encontrarMinMax(números, &min, &max, tamaño);

    return 0;
}     