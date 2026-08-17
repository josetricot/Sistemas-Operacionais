#!/bin/bash

echo -n "Digite um número inteiro maior que zero: "
read numero

# começa contar a partir do número 1
contador=1

# o laço roda enquanto o contador for menor ou igual (-le) ao número digitado
while [ $contador -le $numero ]; do
    
    # calcula o resto da divisão do contador atual por 2
    resto=$((contador % 2))
    
    # verifica se o resto é numericamente igual (-eq) a zero
    if [ $resto -eq 0 ]; then
        echo "O número $contador é PAR"
    else
        echo "O número $contador é ÍMPAR"
    fi
    
    # soma +1 ao contador para ir para o próximo número na próxima volta do laço
    let contador=contador+1
done
