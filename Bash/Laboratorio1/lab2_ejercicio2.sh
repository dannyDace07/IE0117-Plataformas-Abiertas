#/bin/bash

proceso=$1
comando=$2
intervalo=4


probar_estado() {
    while true
    do
        if pgrep -x $1 > /dev/null 2>&1; then 
            echo "el proceso $1 esta ejecutandose"
        else
            echo "el proceso $1 no está en ejecución"
            eval $2 > /dev/null 2>&1 &
        fi
        sleep $3
    done 
}

probar_estado $proceso $comando $intervalo
