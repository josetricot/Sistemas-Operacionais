#!/bin/bash

echo "--- Verificação de Memória RAM ---"

# free mostra detalhes de uso da ram, extrai diretamento do arquivo
# /proc/meminfo usei o -m para mostrar em Mbytes

# cut (cortar) é uma ferramento de edição que corta por colunas
# ou símbolos, usei o -d para marcar o espaço e -f para selecionar as
# colunas

# o free formata com vários espações em branco mas o cut vê 3 espaçõs
# seguidos e acha que tem 3 colunas vazias ali
# para resolver usei -s do tr (translate) para transformar vários espaços
# em apenas 1, assim o cut não se perde

# free fgera dados, grep pega só a linha da RAM, tr limpa espaços duplos
# e o cut pega só o que interessa

# memória total (coluna 2)
# free -m (em MB) -> grep pega a linha da memória -> tr limpa os espaços -> cut pega o 2º campo
mem_total=$(free -m | grep "Mem:" | tr -s " " | cut -d " " -f 2)

# memória utilizada (coluna 3)
mem_utilizada=$(free -m | grep "Mem:" | tr -s " " | cut -d " " -f 3)

# memória disponível (coluna 7)
mem_disponivel=$(free -m | grep "Mem:" | tr -s " " | cut -d " " -f 7)

# resultados
echo "Memória Total: ${mem_total} MB"
echo "Memória Utilizada: ${mem_utilizada} MB"
echo "Memória Disponível: ${mem_disponivel} MB"
echo "----------------------------------"