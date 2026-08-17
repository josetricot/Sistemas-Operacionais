#!/bin/bash

echo -n "Digite o nome de um usuário para verificar: "
read nome_usuario

# CAT, GREP e COUNT(wc)
# cat leitura, grep procura expecificamente, wc conta caracteres, linhas e palavras
# -l pois conta linhas
# | envia saída de um comendo como entrada de outro
# script funciona tanto no computador quando no servidor
# /etc/passwd é o arquivo do sistema ontem onde o linux guarda os nomes todos usuários criados
# ^ significa início da linha e : o fim do nome
existe=$(cat /etc/passwd | grep "^$nome_usuario:" | wc -l)

# -gt significa "greater than" (maior que)
if [ $existe -gt 0 ]; then
    echo "O usuário '$nome_usuario' EXISTE no sistema."
else
    echo "O usuário '$nome_usuario' NÃO EXISTE no sistema."
fi
