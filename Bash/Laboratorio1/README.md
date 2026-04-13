# 🖥️ Lab — Monitoreo de Procesos y Sistema de Archivos en Linux

Colección de scripts Bash para la administración, monitoreo y vigilancia de procesos del sistema operativo Linux, junto con un servicio `systemd` para ejecutar el monitoreo de forma persistente.

---

## Estructura del laboratorio

```
lab2/
├── lab2_ejercicio1.sh          # Inspección detallada de un proceso por PID
├── lab2_ejercicio2.sh          # Guardián automático (watchdog) de un proceso
├── lab2_ejercicio3.sh          # Monitor de CPU/Memoria con gráfica en tiempo real
├── lab2_ejercicio4.sh          # Vigilante de cambios en el sistema de archivos
└── probando_servicio.service   # Unidad systemd para el ejercicio 4
```

---

## Requisitos

- Sistema operativo: Linux (Ubuntu, Debian o similar)
- Bash `>= 3.x`
- Herramientas requeridas:

| Herramienta   | Usado en         | Instalación                         |
|---------------|------------------|-------------------------------------|
| `ps`          | Ejercicios 1 y 3 | Preinstalado                        |
| `pgrep`       | Ejercicios 2 y 3 | Preinstalado                        |
| `gnuplot`     | Ejercicio 3      | `sudo apt install gnuplot`          |
| `inotifywait` | Ejercicio 4      | `sudo apt install inotify-tools`    |
| `systemd`     | Servicio         | Preinstalado en distros modernas    |

---

## Ejercicio 1 — Inspección de proceso por PID

**Archivo:** `lab2_ejercicio1.sh`

Recibe un PID como argumento y muestra un resumen completo del proceso usando `ps`.

### Uso

```bash
./lab2_ejercicio1.sh <PID>
```

### Ejemplo

```bash
./lab2_ejercicio1.sh 1234
```

### Salida esperada

```
ID del proceso: 1234
Nombre del proceso: nginx
ID del proceso padre: 1
Nombre del usuario: www-data
Porcentaje de CPU: 0.5
Porcentaje de memoria: 1.2
Estado: S
El path: /usr/sbin/nginx -g daemon on; master_process on;
```

### Información que muestra

| Campo              | Descripción                          |
|--------------------|--------------------------------------|
| ID del proceso     | PID ingresado                        |
| Nombre del proceso | Nombre del ejecutable (`comm`)       |
| ID proceso padre   | PPID del proceso                     |
| Usuario            | Propietario del proceso              |
| % CPU              | Uso actual de CPU                    |
| % Memoria          | Uso actual de RAM                    |
| Estado             | Estado del proceso (R, S, Z, etc.)   |
| Path               | Ruta completa con argumentos (`cmd`) |

---

## Ejercicio 2 — Guardián de proceso (Watchdog)

**Archivo:** `lab2_ejercicio2.sh`

Monitorea un proceso por nombre cada 4 segundos. Si el proceso se detiene, lo **relanza automáticamente** ejecutando el comando indicado.

### Uso

```bash
./lab2_ejercicio2.sh <nombre_proceso> "<comando_para_relanzar>"
```

### Ejemplo

```bash
./lab2_ejercicio2.sh nginx "sudo systemctl start nginx"
```

### Salida esperada

```
el proceso nginx esta ejecutandose
el proceso nginx esta ejecutandose
el proceso nginx no está en ejecución     ← proceso caído
el proceso nginx esta ejecutandose        ← relanzado automáticamente
```

> ⚠️ El script corre en un bucle infinito. Para detenerlo usar `Ctrl+C` o `kill`.

---

## Ejercicio 3 — Monitor de recursos con gráfica en tiempo real

**Archivo:** `lab2_ejercicio3.sh`

Lanza un ejecutable, registra su consumo de **CPU y memoria** periódicamente en un archivo de log, y genera una **gráfica actualizada en tiempo real** con `gnuplot`. El monitoreo termina cuando el proceso finaliza.

### Uso

```bash
./lab2_ejercicio3.sh <ejecutable.sh> <intervalo_segundos>
```

### Ejemplo

```bash
./lab2_ejercicio3.sh mi_script.sh 2
```

### Archivo generado

`memoria_y_cpu.txt` — registro con el siguiente formato:

```
2024-03-15 12:00:01  0.5  1.3
2024-03-15 12:00:03  1.2  1.3
2024-03-15 12:00:05  0.8  1.4
```

Columnas: `Timestamp | % CPU | % Memoria`

### Gráfica

`gnuplot` abre una ventana con dos curvas actualizadas en cada ciclo:
- 🔵 Línea CPU
- 🟠 Línea Memoria

> ⚠️ Requiere `gnuplot` instalado y entorno gráfico activo (no funciona en SSH sin X11 forwarding).

---

## Ejercicio 4 — Vigilante de cambios en directorio

**Archivo:** `lab2_ejercicio4.sh`

Monitorea en **tiempo real** el directorio actual y todos sus subdirectorios usando `inotifywait`. Registra cualquier evento de creación, modificación o eliminación de archivos en un log del sistema.

### Uso

```bash
./lab2_ejercicio4.sh
```

> El script monitorea `$PWD` (directorio desde donde se ejecuta).

### Archivo de log

`/var/log/monitoreo_directorio`

### Formato del log

```
2024-03-15 12:45:01 CREATE en el directorio /home/user/docs/nuevo_archivo.txt
2024-03-15 12:46:10 MODIFY en el directorio /home/user/docs/reporte.txt
2024-03-15 12:47:30 DELETE en el directorio /home/user/docs/borrado.txt
```

### Eventos monitoreados

| Evento   | Descripción                     |
|----------|---------------------------------|
| `CREATE` | Archivo o carpeta creada        |
| `MODIFY` | Archivo modificado              |
| `DELETE` | Archivo o carpeta eliminada     |

> ⚠️ Se necesitan permisos de escritura en `/var/log/`. Ejecutar con `sudo` si es necesario.

---

## Servicio systemd — `probando_servicio.service`

Convierte el ejercicio 4 en un **servicio del sistema** que se inicia automáticamente al encender la máquina.

### Instalación y activación

```bash
# 1. Copiar el archivo al directorio de servicios
sudo cp probando_servicio.service /etc/systemd/system/

# 2. Recargar systemd
sudo systemctl daemon-reload

# 3. Habilitar para inicio automático
sudo systemctl enable probando_servicio

# 4. Iniciar el servicio ahora
sudo systemctl start probando_servicio
```

### Comandos útiles

```bash
# Ver estado del servicio
sudo systemctl status probando_servicio

# Detener el servicio
sudo systemctl stop probando_servicio

# Deshabilitar el inicio automático
sudo systemctl disable probando_servicio

# Ver logs del servicio en tiempo real
sudo journalctl -fu probando_servicio
```

### Configuración del archivo `.service`

| Directiva          | Valor                                                      | Descripción                                  |
|--------------------|------------------------------------------------------------|----------------------------------------------|
| `Description`      | Servicio de Monitoreo de Cambios en Directorios            | Nombre que aparece en logs y status          |
| `After`            | `network.target`                                          | Espera a que la red esté lista               |
| `Type`             | `simple`                                                   | El proceso principal es el lanzado directamente |
| `ExecStart`        | `/bin/bash /home/danny_ace/Desktop/superrandom/lab2_ejercicio4.sh` | Comando de inicio              |
| `WorkingDirectory` | `/home/danny_ace/Desktop/superrandom`                      | Directorio de trabajo del script             |
| `WantedBy`         | `multi-user.target`                                        | Se activa en el arranque normal del sistema  |

> ⚠️ Si el script o el directorio cambian de ubicación, actualizar `ExecStart` y `WorkingDirectory` en el archivo `.service`.

---

## Resumen general

| Script                       | Herramienta clave | Propósito                                      |
|------------------------------|-------------------|------------------------------------------------|
| `lab2_ejercicio1.sh`         | `ps`              | Inspección detallada de un proceso             |
| `lab2_ejercicio2.sh`         | `pgrep` + `eval`  | Mantener un proceso siempre en ejecución       |
| `lab2_ejercicio3.sh`         | `ps` + `gnuplot`  | Graficar consumo de recursos en tiempo real    |
| `lab2_ejercicio4.sh`         | `inotifywait`     | Registrar cambios en el sistema de archivos    |
| `probando_servicio.service`  | `systemd`         | Ejecutar el ejercicio 4 como servicio del SO   |

---

## Permisos de ejecución

Dar permisos a todos los scripts de una vez:

```bash
chmod +x lab2_ejercicio1.sh lab2_ejercicio2.sh lab2_ejercicio3.sh lab2_ejercicio4.sh
```
