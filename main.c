#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"



int main(){
    int option;
    do {
        printf("\n1. Cadastrar Residencia\n");
        printf("2. Listar Residencias\n");
        printf("3. Visualizar Residência\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerResidence();
                break;
            case 2:
                residenceList();
                break;
            case 3:
                visualizeResidence();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (option != 4);

    return 0;
}
