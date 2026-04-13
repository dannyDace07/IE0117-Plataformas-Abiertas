# Ejercicios en C — Matemáticas y Matrices

Colección de tres programas en C que cubren números triangulares, cálculo de factoriales y búsqueda de patrones en matrices binarias.

---

## Estructura

```
.
├── ejercicio1.c   # Números triangulares
├── ejercicio2.c   # Factorial de un número
└── ejercicio3.c   # Cuadrado más grande de unos en una matriz binaria
```

---

## Compilación y ejecución

Compilar cada ejercicio con `gcc`:

```bash
gcc ejercicio1.c -o ejercicio1
gcc ejercicio2.c -o ejercicio2
gcc ejercicio3.c -o ejercicio3
```

Ejecutar:

```bash
./ejercicio1
./ejercicio2
./ejercicio3
```

---

## Ejercicio 1 — Números Triangulares

**Archivo:** `ejercicio1.c`

Calcula e imprime los primeros 100 números triangulares usando la fórmula:

```
T(n) = n × (n + 1) / 2
```

### Funcionamiento

El programa no requiere ninguna entrada del usuario. Itera desde `n = 0` hasta `n = 100` y calcula el número triangular correspondiente en cada paso.

### Ejecución

```bash
./ejercicio1
```

### Salida esperada

```
Los primeros 100 números triangulares son:
0 1 3 6 10 15 21 28 36 45 55 ...
```

### Números triangulares de referencia

| n  | T(n) |
|----|------|
| 0  | 0    |
| 1  | 1    |
| 2  | 3    |
| 3  | 6    |
| 4  | 10   |
| 5  | 15   |

---

## 📄 Ejercicio 2 — Factorial

**Archivo:** `ejercicio2.c`

Calcula el factorial de un número entero ingresado por el usuario mediante un bucle iterativo.

```
n! = n × (n-1) × (n-2) × ... × 1
```

### Funcionamiento

La función `factorial(int n)` usa un bucle `while` para multiplicar de forma descendente desde `n` hasta `2`. El resultado se imprime en `main`.

### Ejecución

```bash
./ejercicio2
```

### Ejemplo de uso

```
Ingrese un número: 5
El factorial de 5 es 120
```

### Factoriales de referencia

| n | n!    |
|---|-------|
| 0 | 1     |
| 1 | 1     |
| 2 | 2     |
| 3 | 6     |
| 4 | 24    |
| 5 | 120   |
| 6 | 720   |

> ⚠️ El tipo `int` tiene un límite de representación. Para valores de `n` mayores a 12, el resultado puede desbordar el rango de `int` (máximo ~2.1 mil millones). Usar `long long` para mayor precisión.

---

## Ejercicio 3 — Cuadrado más grande de unos en matriz binaria

**Archivo:** `ejercicio3.c`

Genera una matriz binaria aleatoria (valores 0 y 1) de tamaño definido por el usuario, la muestra en pantalla, y encuentra el **cuadrado más grande formado únicamente por unos (`1`)**.

### Constantes definidas

| Constante            | Valor | Descripción                             |
|----------------------|-------|-----------------------------------------|
| `TAMAÑO_POR_DEFECTO` | 5     | Tamaño usado si el input es inválido    |
| `TAMAÑO_MÁXIMO`      | 10    | Máximo tamaño permitido para la matriz  |

### Funcionamiento

El programa se divide en tres partes:

1. **Generación:** crea una matriz `n×n` con valores aleatorios de 0 y 1 usando `rand() % 2`.
2. **Visualización:** `mostrarMatriz()` imprime la matriz fila por fila.
3. **Búsqueda:** `encontrarCuadradoMásGrande()` recorre la matriz buscando cuadrados de unos, expandiendo el tamaño mientras los bordes del cuadrado (derecho e inferior) sean todos `1`.

### Ejecución

```bash
./ejercicio3
```

### Ejemplo de uso

```
Introduzca el tamaño deseado para la matriz cuadrada (entre 1 y 10): 6

La matriz generada de forma aleatoria es:
1 0 1 1 0 1
0 1 1 1 1 0
1 1 1 1 0 1
0 1 1 1 1 1
1 0 1 1 1 0
0 1 0 1 1 1

El cuadrado más grande de unos en la matriz es de tamaño 3x3.
```

### Caso sin cuadrados

```
No se encontró ningún cuadrado de unos en la matriz.
```

> ⚠️ La generación de la matriz usa `rand()` sin semilla (`srand`), por lo que producirá la misma secuencia en cada ejecución. Para resultados distintos cada vez, agregar `srand(time(NULL))` al inicio del `main` (requiere incluir `<time.h>`).

---

## Resumen

| Ejercicio     | Concepto principal         | Entrada         | Salida                                  |
|---------------|----------------------------|-----------------|-----------------------------------------|
| `ejercicio1.c`| Números triangulares       | Ninguna         | Lista de 101 números triangulares       |
| `ejercicio2.c`| Factorial iterativo        | Un entero       | El factorial del número ingresado       |
| `ejercicio3.c`| Búsqueda en matriz binaria | Tamaño (1–10)   | Matriz aleatoria + tamaño del cuadrado  |
