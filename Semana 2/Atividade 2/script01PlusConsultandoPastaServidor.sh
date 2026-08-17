#!/bin/bash

echo -n "Digite o nome da pasta para verificar: "
read nome_pasta

# ls /home para listar os nomes
# grep "^$nome_pasta$" garante que o nome bate do início (^) ao fim ($)
existe=$(ls /home | grep "^$nome_pasta$" | wc -l)

if [ $existe -gt 0 ]; then
    echo "A pasta do usuário '$nome_pasta' EXISTE no servidor."
else
    echo "A pasta do usuário '$nome_pasta' NÃO EXISTE no servidor."
fi
