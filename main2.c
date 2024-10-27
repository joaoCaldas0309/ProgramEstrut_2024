#include "library2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int option;

    do{
        printf("\n");
        printf("1. Cadastrar nova residencia\n");
        printf("2. Residencias Cadastradas\n");
        printf("3. Visualizar Residencia\n");
        printf("4. Calcular o consumo da residencia\n");
        printf("5. Sair\n");
        printf("Digite sua opceao: ");

        scanf("%d", &option);

        switch (option)
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
            printf("Ate mais!");
            return 0;
            break;
        default:
            printf("Opcao invalida.");
            return 0;
            break;
        }
    } while (option != 5);
}