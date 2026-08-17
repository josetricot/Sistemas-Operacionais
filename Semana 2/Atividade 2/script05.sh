#!/bin/bash

echo "=========================================================="
echo "          MONITORAMENTO DE PROCESSOS (TOP 10)             "
echo "=========================================================="

# ps (process status) visualiza processos em execução e -aux inclui todos
# usuários e detalhes de consumo de rescursos

# cut (cortar) -d para definir espaço como delimitador e -f para selecionar
# colunas

# a saída ps -aux sobre mesmo problema do free, espaços em branco
# utilizado novamente o tr -s " " para comprimir espços repetidos em um só

# imprime cabeçalho personalizado
echo "USUÁRIO | PID | %CPU | %MEM | NOME DO PROCESSO"
echo "----------------------------------------------------------"

# ps -aux lista todos os processos em execução
# tr -s " " comprime múltiplos espaços em um único espaço
# cut -d " " -f 1,2,3,4,11 corta usando o espaço como delimitador e seleciona as colunas pedidas
# head -n 11 limita a saída a 11 linhas (1 do cabeçalho original do ps + 10 processos)

ps -aux | tr -s " " | cut -d " " -f 1,2,3,4,11 | head -n 11

echo "=========================================================="
