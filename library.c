#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESIDENCE 100
#define MAX_HOUSEHOLD_APPLIANCE 100
#define MAX_NAME 50

// Vetors to store the datas
char residence[MAX_RESIDENCE][MAX_NAME];
char householdAppliance[MAX_RESIDENCE][MAX_HOUSEHOLD_APPLIANCE][MAX_NAME];

int powerHouseholdAppliance[MAX_RESIDENCE][MAX_HOUSEHOLD_APPLIANCE];
int allHouseholdAppliancePerResidence[MAX_RESIDENCE];
int totalResidence = 0;

void allMessages(int valueEntrance){
    switch (valueEntrance)
    {
    case 1:
    // This message it's from "registerResidence()" function.
        printf("O limite de residencias criadas foi atingido! \n");
        break;
    case 2:
    // This message it's from "registerResidence()" function.
        printf("Digite o nome de sua residencia: ");
        break;
    case 3:
    // This message it's from "registerResidence()" function.
        printf("O limite de eletrodomesticos cadastrados foram atingido! \n");
        break;
    case 4:
    // This message it's from "registerResidence()" function.
        printf("Digite o nome do eletrodomestico que deseja atribuir a sua resisdencia: ");
        break;
    case 5:
    // This message it's from "registerResidence()" function.
        printf("Digite a potencia (watts) do eletrodomestico: ");
        break;
    case 6:
    // This message it's from "registerResidence()" function.
        printf("Deseja adicionar outro eletrodomestico? (s/n): ");
        break;
    case 7:
    // This message it's from "residenceList()" function.
        printf("Nenhuma residencia encontrada! \n");
        break;
    case 8:
    // This message it's from "residenceList()" function.
        printf("\nLista de Residencias:\n");
        break;
    case 9:
    // This message it's from "visualizeResidence()" function.
        printf("Nenhuma residencia foi cadastrada!\n");
        break;
    case 10:
    // This message it's from "visualizeResidence()" function.
        printf("\nDigite o numero da residencia que deseja vizualizar: ");
        break;
    case 11:
    // This message it's from "visualizeResidence()" function.
        printf("Opcao invalida.\n");
        break;
    case 12:
    // This message it's from "visualizeResidence()" function.
        printf("Eletrodomesticos e suas potencias:\n");
        break;
    default:
        break;
    }
}

void registerResidence(){
    
    // Condition to verify if the register of residence has been reached
    if (totalResidence >= MAX_RESIDENCE){
        allMessages(1);
        return;
    }

    // Get the residence's name
    allMessages(2);
    scanf("%s", residence[totalResidence]);

    allHouseholdAppliancePerResidence[totalResidence] = 0;

    char option = 's';
    while (option == 's' || option == 'S'){
        // Condition to verify if the register of household appliance has been reached
        if(allHouseholdAppliancePerResidence[totalResidence] >= MAX_HOUSEHOLD_APPLIANCE){
            allMessages(3);
            break;
        }

        // Get the household appliance's name 
        allMessages(4);
        scanf("%s", householdAppliance[totalResidence][allHouseholdAppliancePerResidence[totalResidence]]);

        // Get the power of each household appliance
        allMessages(5);
        scanf("%d", &powerHouseholdAppliance[totalResidence][allHouseholdAppliancePerResidence[totalResidence]]);

        allHouseholdAppliancePerResidence[totalResidence]++;

        // Ask if the user must continues or not
        allMessages(6);
        scanf("%s", &option);
    }
    totalResidence++;    
}

void residenceList(){
    if(totalResidence == 0) {
        allMessages(7);
        return;
    }

    allMessages(8);
    for (int i = 0; i < totalResidence; i++) {
        printf("%d. %s\n", i + 1, residence[i]);
    }    
}

void visualizeResidence() {
    if(totalResidence == 0){
        allMessages(9);
        return;
    }

    residenceList();

    int option;
    allMessages(10);
    scanf("%d", &option);

    if(option < 1 || option > totalResidence) {
        allMessages(11);
        return;
    }

    int residenceIndice = option - 1;
    int allConsume = 0;

    printf("\nResidencia: %s\n", residence[residenceIndice]);
    allMessages(12);

    for (int i = 0; i < allHouseholdAppliancePerResidence[residenceIndice]; i++){
        printf("- %s (Potencia %dW)\n", householdAppliance[residenceIndice][i], powerHouseholdAppliance[residenceIndice][i]);
        allConsume += powerHouseholdAppliance[residenceIndice][i];
    }
}

