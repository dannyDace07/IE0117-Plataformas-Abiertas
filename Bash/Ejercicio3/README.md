# Generador de Informes de Logs

Script de Bash para filtrar y generar informes a partir de un archivo de registro (`logs.txt`), con soporte para filtrado por modo de funcionamiento y/o fecha.

---

## Requisitos

- Sistema operativo: Linux / macOS o cualquier entorno con Bash
- Bash `>= 3.x`
- `awk` instalado (disponible por defecto en la mayoría de sistemas Unix)
- Archivo `logs.txt` ubicado en el mismo directorio desde donde se ejecuta el script

---

## Uso

```bash
./script.sh (-h) (-m MODO) (-d FECHA)
```

### Opciones

| Opción        | Descripción                                                                 |
|---------------|-----------------------------------------------------------------------------|
| `-h`          | Muestra el menú de ayuda                                                    |
| `-m MODO`     | Filtra por modo de funcionamiento (ver modos disponibles más abajo)        |
| `-d FECHA`    | Filtra por fecha en formato `YYYY-MM-DD`                                    |

### Modos disponibles para `-m`

| Modo               | Descripción                          |
|--------------------|--------------------------------------|
| `servidor_web`     | Registros del servidor web           |
| `base_de_datos`    | Registros de base de datos           |
| `proceso_batch`    | Registros de procesos por lotes      |
| `aplicación`       | Registros de la aplicación           |
| `monitoreo`        | Registros de monitoreo del sistema   |

---

## Ejemplos de uso

**Filtrar por modo en todas las fechas:**
```bash
./script.sh -m servidor_web
```

**Filtrar por fecha en todos los modos:**
```bash
./script.sh -d 2024-03-15
```

**Filtrar por modo y fecha específicos:**
```bash
./script.sh -m base_de_datos -d 2024-03-15
```

**Mostrar ayuda:**
```bash
./script.sh -h
```

---

## Formato esperado del archivo `logs.txt`

El archivo de logs debe estar ubicado en el directorio de trabajo actual (`$PWD/logs.txt`). Cada línea debe seguir el siguiente formato:

```
[ FECHA  HORA  NIVEL  MODO  MENSAJE ]
```

Ejemplo:
```
[ 2024-03-15 12:45:01 INFO servidor_web Solicitud GET procesada exitosamente ]
[ 2024-03-15 13:10:22 ERROR base_de_datos Conexión rechazada por timeout ]
```

> El script usa `awk` para comparar la **columna 1** con la fecha (`[ FECHA`) y la **columna 5** con el modo.

---

## Errores comunes

| Mensaje de error                                  | Causa                                              |
|---------------------------------------------------|----------------------------------------------------|
| `Error: Se debe especificar al menos una opción`  | No se pasó `-m` ni `-d`                            |
| `Opción inválida: -X`                             | Se usó una opción no reconocida                    |
| `La opción -X necesita un argumento.`             | Se pasó `-m` o `-d` sin valor                      |

---

## Permisos de ejecución

Si el script no tiene permisos de ejecución, otórgarlos con:

```bash
chmod +x script.sh
```

---

## Notas

- Si se omiten ambas opciones `-m` y `-d`, el script mostrará un error y terminará.
- El archivo de logs se busca siempre como `logs.txt` en el directorio actual de trabajo.
