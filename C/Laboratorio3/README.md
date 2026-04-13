# Ejercicios en C — Búsqueda y Valores Extremos en Arreglos

Dos programas en C que implementan algoritmos clásicos de búsqueda y de localización de valores mínimo y máximo en arreglos.

---

## Estructura

```
.
├── ej1.c   # Búsqueda lineal y binaria (iterativa y recursiva)
└── ej2.c   # Mínimo y máximo con funciones tradicionales y punteros
```

---

## Compilación y ejecución

```bash
gcc ej1.c -o ej1
gcc ej2.c -o ej2

./ej1
./ej2
```

---

## Ejercicio 1 — Algoritmos de Búsqueda

**Archivo:** `ej1.c`

Implementa y compara tres estrategias de búsqueda sobre el mismo arreglo fijo: `{2, 4, 6, 23, 56, 79}`.

### Funciones implementadas

| Función                      | Tipo        | Descripción                                                                 |
|------------------------------|-------------|-----------------------------------------------------------------------------|
| `encontrarElemento()`        | Lineal      | Recorre el arreglo de inicio a fin hasta encontrar el valor                 |
| `busquedaBinaria()`          | Binaria     | Divide el arreglo a la mitad en cada paso de forma iterativa (bucle `while`)|
| `busquedaBinariaRecursiva()` | Binaria     | Igual que la anterior pero usando llamadas recursivas                       |

Todas retornan el **índice** del elemento encontrado, o `-1` si no existe en el arreglo.

### Ejecución

```bash
./ej1
```

### Ejemplo — valor encontrado

```
Ingrese un valor entero: 23
El número 23 está en la posición 3 del arreglo.   ← búsqueda lineal
El número 23 está en la posición 3 del arreglo.   ← búsqueda binaria iterativa
El número 23 está en la posición 3 del arreglo.   ← búsqueda binaria recursiva
```

### Ejemplo — valor no encontrado

```
Ingrese un valor entero: 99
Error: El número 99 no fue encontrado en el arreglo.
Error: El número 99 no fue encontrado en el arreglo.
Error: El número 99 no fue encontrado en el arreglo.
```

### Comparación de algoritmos

| Algoritmo        | Complejidad | Requiere arreglo ordenado | Implementación  |
|------------------|-------------|---------------------------|-----------------|
| Lineal           | O(n)        | No                        | Iterativa       |
| Binaria          | O(log n)    | Sí                        | Iterativa       |
| Binaria recursiva| O(log n)    | Sí                        | Recursiva       |

> ⚠️ El arreglo `{2, 4, 6, 23, 56, 79}` ya está ordenado, condición necesaria para que la búsqueda binaria funcione correctamente.

---

## Ejercicio 2 — Mínimo y Máximo en un Arreglo

**Archivo:** `ej2.c`

Encuentra el valor mínimo y máximo del arreglo fijo `{21, 24, 65, 3, 56, 12, 35, 15}` usando dos enfoques distintos.

### Funciones implementadas

| Función             | Enfoque    | Descripción                                                              |
|---------------------|------------|--------------------------------------------------------------------------|
| `encontrarMinimo()` | Retorno    | Recorre el arreglo comparando con un mínimo acumulado usando el operador ternario `?:` |
| `encontrarMaximo()` | Retorno    | Igual que el anterior pero buscando el mayor valor                       |
| `encontrarMinMax()` | Punteros   | Calcula ambos valores en una sola pasada modificando variables externas mediante punteros |

### Ejecución

```bash
./ej2
```

### Salida esperada

```
El valor mínimo en el arreglo es: 3
El valor máximo en el arreglo es: 65
```

### Diferencia entre enfoques

| Enfoque     | Cómo devuelve el resultado              | Pasadas sobre el arreglo |
|-------------|-----------------------------------------|--------------------------|
| Funciones independientes (`encontrarMinimo` / `encontrarMaximo`) | Valor de retorno (`return`) | 2 pasadas (una por función) |
| `encontrarMinMax()` con punteros | Modifica variables externas vía `*minimo` y `*maximo` | 1 sola pasada |

> El enfoque con punteros es más eficiente ya que recorre el arreglo una única vez para obtener ambos resultados simultáneamente.

---

## Resumen

| Ejercicio | Concepto principal              | Entrada       | Salida                                    |
|-----------|---------------------------------|---------------|-------------------------------------------|
| `ej1.c`   | Búsqueda lineal y binaria       | Un entero     | Posición del elemento o mensaje de error  |
| `ej2.c`   | Mínimo y máximo con punteros    | Ninguna       | Valor mínimo y máximo del arreglo         |
