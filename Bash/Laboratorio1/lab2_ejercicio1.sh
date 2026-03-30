#!/bin/bash 

# Obtener información del proceso
ID="$1"
El_Nombre=$(ps -p "$ID" -o comm=)
El_PPID=$(ps -p "$ID" -o ppid=)
El_USER=$(ps -p "$ID" -o user=)
El_CPU=$(ps -p "$ID" -o pcpu=)
El_MEMO=$(ps -p "$ID" -o pmem=)  
El_Estado=$(ps -p "$ID" -o stat=)  
El_Path=$(ps -p "$ID" -o cmd=)

echo "ID del proceso: $ID"
echo "Nombre del proceso: $El_Nombre"
echo "ID del proceso padre: $El_PPID"
echo "Nombre del usuario: $El_USER"
echo "Porcentaje de CPU: $El_CPU"
echo "Porcentaje de memoria: $El_MEMO"  
echo "Estado: $El_Estado"  
echo "El path: $El_Path"





