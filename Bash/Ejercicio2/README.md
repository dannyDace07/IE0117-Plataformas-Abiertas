# ejercicio2.sh

Script de Bash para la gestión de usuarios y grupos en sistemas Linux. Automatiza la creación de un usuario y un grupo, los vincula entre sí, y asigna permisos de ejecución sobre un archivo específico al grupo creado.

---

## ¿Cómo funciona?

El script realiza las siguientes operaciones en orden:

1. **Verifica si el usuario existe** – si no existe, lo crea con `useradd`.
2. **Verifica si el grupo existe** – si no existe, lo crea con `groupadd`.
3. **Agrega al grupo** tanto al usuario nuevo como al usuario que ejecuta el script (`$USER`), usando `usermod -aG`.
4. **Cambia el grupo propietario** del archivo indicado al nuevo grupo con `chgrp`.
5. **Otorga permiso de ejecución** sobre ese archivo a los miembros del grupo con `chmod g+x`.

---

## Requisitos

- Sistema operativo Linux/Unix
- Bash 4.0 o superior
- Privilegios de superusuario (`sudo`) para crear usuarios, grupos y modificar permisos

---

## Uso
```bash
bash ejercicio2.sh <nuevo_usuario> <nuevo_grupo> <archivo>
```

| Argumento       | Descripción                                               |
|----------------|-----------------------------------------------------------|
| `nuevo_usuario` | Nombre del usuario a crear o verificar                   |
| `nuevo_grupo`   | Nombre del grupo a crear o verificar                     |
| `archivo`       | Ruta del archivo al que se le asignará el grupo y permisos |

### Ejemplo
```bash
bash ejercicio2.sh juan desarrolladores ejercicio2.sh
```

### Salida esperada
```
el usuario juan ya existe
se ha creado el grupo desarrolladores
se han agregado el usuario default y el nuevo usuario juan a el nuevo grupo desarrolladores
```

---

## Manejo de casos existentes

| Situación                        | Comportamiento                                      |
|----------------------------------|-----------------------------------------------------|
| El usuario ya existe en el sistema  | Se notifica y **no** se intenta crear de nuevo   |
| El grupo ya existe en el sistema    | Se notifica y **no** se intenta crear de nuevo   |
| El usuario o grupo no existen       | Se crean automáticamente con `useradd`/`groupadd`|

---

## Notas

- El script suprime la salida de `usermod` con `/dev/null` para evitar mostrar su menú de opciones en consola.
- El usuario que ejecuta el script (`$USER`) también es agregado al nuevo grupo, junto con `nuevo_usuario`.
- El archivo indicado en el tercer argumento debe existir previamente; el script no lo valida ni lo crea.
- Se recomienda ejecutar con precaución en entornos de producción, ya que la creación de usuarios y grupos es una operación sensible del sistema.
