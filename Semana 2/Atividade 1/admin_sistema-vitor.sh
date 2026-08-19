#!/bin/bash

# Função para verificar o uso de memória RAM
verificar_memoria() {
    echo "--- Uso Atual da Memória ---"
    free -m
    echo "-----------------------------"
    
    # Extrai o percentual de memória usada
    local total_mem=$(free -m | awk '/Mem:/ {print $2}')
    local used_mem=$(free -m | awk '/Mem:/ {print $3}')
    local percent_used=$(( (used_mem * 100) / total_mem ))
    
    echo "Uso da memória: ${percent_used}%"
    
    # Condição IF para avaliar a situação da memória
    if [ "$percent_used" -gt 85 ]; then
        echo "Situação: ALERTA! Uso elevado de memória RAM."
    else
        echo "Situação: ADEQUADA. Uso de memória dentro dos limites normais."
    fi
}

# Laço de repetição principal
while true; do
    echo "========================================"
    echo "       ADMINISTRADOR DO SISTEMA         "
    echo "========================================"
    echo "1 - Informações do sistema"
    echo "2 - Informações do usuário"
    echo "3 - Verificar memória"
    echo "4 - Sair"
    echo "========================================"
    echo -n "Escolha uma opção: "
    read opcao

    case "$opcao" in
        1)
            echo ""
            echo "--- Informações do Sistema ---"
            echo "Nome do computador : $(hostname)"
            echo "Sistema Operacional: $(uname -o)"
            echo "Versão do Kernel   : $(uname -r)"
            echo "Data e Hora        : $(date '+%d/%m/%Y %H:%M:%S')"
            echo "------------------------------"
            echo ""
            ;;
        2)
            echo ""
            echo "--- Informações do Usuário ---"
            echo "Nome do usuário   : $USER"
            echo "UID               : $(id -u)"
            echo "Grupo Principal   : $(id -gn) (GID: $(id -g))"
            echo "Diretório pessoal : $HOME"
            echo "------------------------------"
            echo ""
            ;;
        3)
            echo ""
            verificar_memoria
            echo ""
            ;;
        4)
            echo ""
            echo "Encerrando o programa. Até logo!"
            exit 0
            ;;
        *)
            echo ""
            echo "Opção inválida! Por favor, escolha um número de 1 a 4."
            echo ""
            ;;
    esac
done
