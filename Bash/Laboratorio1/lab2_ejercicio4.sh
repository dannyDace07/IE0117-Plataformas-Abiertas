#!/bin/bash 

Directorio=$PWD   
archivo_log="/var/log/monitoreo_directorio"


inotifywait -m -r -e create,modify,delete "$Directorio" |
    while read -r directorio evento archivo; do
        fecha=$(date "+%Y-%m-%d %H:%M:%S")
        echo "$fecha $evento en el directorio $directorio/$archivo" >> "$archivo_log"
    done 

