#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Persona
typedef struct {
    char nombre[50];
    int edad;
    double altura;
} Persona;

// Función para comparar por nombre
int comparar_por_nombre(const void *a, const void *b) {
    return strcmp(((Persona *)a)->nombre, ((Persona *)b)->nombre);
}

// Función para comparar por edad
int comparar_por_edad(const void *a, const void *b) {
    return ((Persona *)a)->edad - ((Persona *)b)->edad;
}

// Función para comparar por altura
int comparar_por_altura(const void *a, const void *b) {
    double diferencia = ((Persona *)a)->altura - ((Persona *)b)->altura;
    return (diferencia > 0) - (diferencia < 0);
}

// Función para imprimir el arreglo de personas
void imprimir_personas(const Persona *personas, int tamano) {
    for (int i = 0; i < tamano; i++) {
        printf("Nombre: %s, Edad: %d, Altura: %.2f\n", personas[i].nombre, personas[i].edad, personas[i].altura);
    }
    printf("\n");
}

// Función para ordenar y mostrar resultados
void mostrarDatos(Persona personas[], int tamano, int (*comparar)(const void *, const void *), const char *criterio) {
    qsort(personas, tamano, sizeof(Persona), comparar);
    if (strcmp(criterio, "nombre") == 0) {
        printf("Orden alfabético por %s:\n", criterio);
    } else {
        printf("Orden por %s de menor a mayor:\n", criterio);
    }
    imprimir_personas(personas, tamano);
}

int main() {
    Persona personas[] = {
        {"Carito", 30, 160},
        {"Kusanagi", 31, 168},
        {"Luffy", 35, 175},
        {"Enzo", 20, 170},
        {"Steven", 28, 160}
    };
    int tamano = sizeof(personas) / sizeof(personas[0]);

    printf("Lista de datos:\n");
    imprimir_personas(personas, tamano);

    mostrarDatos(personas, tamano, comparar_por_nombre, "nombre");
    mostrarDatos(personas, tamano, comparar_por_edad, "edad");
    mostrarDatos(personas, tamano, comparar_por_altura, "altura");

    return 0;
}
