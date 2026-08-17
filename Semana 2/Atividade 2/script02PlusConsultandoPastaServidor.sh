#!/bin/bash

echo -n "Digite o nome da pasta para verificar: "
read nome_pasta

# parâmetro -d verifica diretamente se o diretório existe no caminho especificado
if [ -d "/home/$nome_pasta" ]; then
    echo "A pasta do usuário '$nome_pasta' EXISTE no servidor."
else
    echo "A pasta do usuário '$nome_pasta' NÃO EXISTE no servidor."
fi
