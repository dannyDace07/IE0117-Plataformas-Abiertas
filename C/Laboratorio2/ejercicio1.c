#include <stdio.h>

int main() {
    int n, resultado;

    printf("Los primeros 100 números triangulares son:\n");
    for (n = 0; n <= 100; ++n) {
        resultado = n * (n + 1) / 2;
        printf("%d ", resultado);
    }

    return 0;
}

