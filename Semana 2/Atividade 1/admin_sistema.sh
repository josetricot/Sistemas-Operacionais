#!/bin/bash

mostrar_menu() {
    echo "========================================"
    echo "       ADMINISTRADOR DO SISTEMA"
    echo "========================================"
    echo "1 - Informações do sistema"
    echo "2 - Informações do usuário"
    echo "3 - Verificar memória"
    echo "4 - Sair"
    echo "========================================"
    echo -n "Escolha uma opção: "
    # o cursor fica na minha linha do texto
}

valor_digitado=0

while [ "$valor_digitado" != "4" ]; do
    mostrar_menu
    read valor_digitado
    echo ""

    case $valor_digitado in
        1)
            echo "--- Informações do Sistema ---"
            echo "Nome do computador: $(hostname)"
            echo "Sistema operacional: $(uname -o)"
            echo "Versão do kernel: $(uname -r)"
            echo "Data e hora: $(date)"
            echo "------------------------------"
            echo ""
            ;;

        2)
            echo "--- Informações do Usuário ---"
            echo "Nome do usuário: $(whoami)"
            echo "UID: $(id -u)"
            echo "Grupo: $(id -gn)"
            echo "Diretório pessoal: $HOME"
            echo "------------------------------"
            echo ""
            ;;

        3)
            echo "--- Verificação de Memória ---"
            # parâmetro -m mostra o resultado em Mbytes
            free -m 
            echo ""

            # -m exibe em MB e awk filta para pegar somente numero, NR foca apenas na segunda linha
            # print4 quarta coluna
            memoria_livre=$(free -m | awk 'NR==2{print $4}')

            if [ "$memoria_livre" -lt 200 ]; then
                echo "ALERTA: Situação inadequada! Memória RAM livre está muito baixa ($memoria_livre MB)."
            else
                echo "OK: Situação adequada. Memória RAM livre suficiente ($memoria_livre MB)."
            fi
            echo "------------------------------"
            echo ""
            ;;

        4)
            echo "Encerrando o programa!"
            ;;

        *)
            echo "Opção inválida! Por favor, escolha um número de 1 a 4."
            echo ""
            ;;
    esac
done