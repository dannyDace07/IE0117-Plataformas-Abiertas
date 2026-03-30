#include <stdio.h>

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i *= n;
        n = n-1;
    }
    return i;
}

int main() {
    int numero;
    printf("Ingrese un número: ");
    scanf("%d", &numero);
    int factorial_numero = factorial(numero);
    printf("El factorial de %d es %d ", numero, factorial_numero);
    return 0;
}