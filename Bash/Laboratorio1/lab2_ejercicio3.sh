#!/bin/bash

ejecutable="$1"

# En caso de ser un archivo .sh, se espera que se agregue esto al momento de escribir el ejecutable como parámetro
./"$ejecutable" > /dev/null 2>&1

archivo_log="memoria_y_cpu.txt"
intervalo="$2"

registros() {
    Tiempo=$(date "+%Y-%m-%d %H:%M:%S")
    ID=$(pgrep "$ejecutable")
    CPU=$(ps -p "$ID" -o %cpu --no-headers)
    MEM=$(ps -p "$ID" -o %mem --no-headers)
    echo "$Tiempo $CPU $MEM" >> "$archivo_log"
}

graficar_valores() {
    gnuplot -persist <<INI
        set title "Consumo del CPU y la Memoria"
        set xlabel "Tiempo"
        set ylabel "Porcentaje"
        set xdata time
        set timefmt "%Y-%m-%d %H:%M:%S"
        set format x "%H:%M:%S"
        plot "$archivo_log" using 1:2 with lines title "CPU", \
             "$archivo_log" using 1:3 with lines title "Memoria"
INI
}


# Bucle para monitorear el proceso y registrar los datos
while ps -p $(pgrep "$ejecutable") > /dev/null 2>&1; do
    registros
    sleep "$intervalo"
    graficar_valores
done

#fin
