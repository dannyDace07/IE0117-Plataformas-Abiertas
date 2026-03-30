# 📄 ejercicio1.sh

Script de Bash que muestra los permisos de un archivo del sistema de forma legible y detallada, traduciendo la notación simbólica estándar (rwx) a palabras en español.

---

## ¿Cómo funciona?

El script recibe el nombre de un archivo como argumento, obtiene sus permisos usando el comando `stat` y los desglosa en tres categorías:

- **Usuario** – el propietario del archivo
- **Grupo** – el grupo asociado al archivo
- **Otros usuarios** – el resto de usuarios del sistema

Cada permiso (`r`, `w`, `x`) se traduce a su equivalente en texto: `Lectura`, `Escritura` o `Ejecución`.

---

## Requisitos

- Sistema operativo Linux/Unix
- Bash 4.0 o superior
- Comando `stat` disponible (incluido por defecto en la mayoría de distribuciones)

---

## Uso
```bash
bash ejercicio1.sh <nombre_del_archivo>
```

### Ejemplo
```bash
bash ejercicio1.sh mi_documento.txt
```

### Salida esperada
```
Permisos para el usuario:
Lectura
Escritura
Ejecución
Permisos para el grupo:
Lectura
Escritura
Error
Permisos para los usuarios:
Lectura
Error
Error
```

> `Error` indica que el permiso correspondiente **no está otorgado** (`-` en la notación simbólica).

---

## Manejo de errores

Si el archivo proporcionado no existe en el sistema, el script termina con el siguiente mensaje:
```
Error: El archivo <nombre_del_archivo> no existe en el sistema.
```

---

## Notas

- El script debe ejecutarse con permisos suficientes para leer los metadatos del archivo objetivo.
- No modifica el archivo en ningún momento; solo realiza una lectura de sus permisos.
