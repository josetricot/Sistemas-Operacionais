#!/bin/bash

echo -n "Digite o caminho do diretório (ex: /etc ou /home): "
read diretorio

# ls lista arquivos e diretórios, -l exibe detalhes
# se começa com hifem - é arquivo, se começa com d é diretório (pasta)

# grep funciona como um filtro

# COUNT é o wc, e usando -l conta só as linhas

# verifica se o diretório existe
# -d verifica se o "FILE exists and is a directory" (O arquivo existe e é um diretório)
if [ -d "$diretorio" ]; then
    
    # contagem de arquivos
    # ls -l lista tudo detalhado, grep "^-" pega as linhas que começam com hífen, wc -l conta as linhas
    # ^ siguinifica início da linha
    arquivos=$(ls -l "$diretorio" | grep "^-" | wc -l)
    
    # contagem de subdiretórios
    # mesma lógica, mas o grep "^d" pega as linhas que começam com 'd'
    subdiretorios=$(ls -l "$diretorio" | grep "^d" | wc -l)
    
    # resultados
    echo "--- Resumo do diretório: $diretorio ---"
    echo "Quantidade de arquivos: $arquivos"
    echo "Quantidade de subdiretórios: $subdiretorios"
    echo "---------------------------------------"

else
    echo "Erro: O caminho '$diretorio' não existe ou não é um diretório válido."
fi