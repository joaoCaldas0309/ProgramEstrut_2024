#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int opcao;

    do{
        printf("\n");
        printf("1. Cadastre sua Residencia\n");
        printf("2. Residencias Cadastradas\n");
        printf("3. Visualizar Residencia\n");
        printf("4. Calculo de Consumo\n");
        printf("5. Conversor de Valores\n");
        printf("6. Sair\n");
        printf("Digite sua opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            registrandoResidencias();
            break;
        case 2:
            listaResidencias();
            break;
        case 3:
            visualizarResidencia();
            break;
        case 4:
            calcular();
            break;
        case 5:
            conversaoValores();
            break;
        case 6:
            printf("Programa finalizado. Ate mais!\n");
            break;
        default:
            printf("Opcao invalida.");
            return 0;
            break;
        }
    } while (opcao != 6);
}