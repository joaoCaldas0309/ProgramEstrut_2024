#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Setting maximous values input
#define MAX_RESIDENCIA 100
#define MAX_ELETRODOMESTICO 100
#define MAX_NOME 100
#define MAX_HORAS 24

#define DIA 24

#define OPCAO_SIM 's'
#define OPCAO_NAO 'n'

// Vector to store the datas
char residencia[MAX_RESIDENCIA][MAX_NOME]; // Creating the responsible vector to set the residences
char eletrodomesticos[MAX_RESIDENCIA][MAX_ELETRODOMESTICO][MAX_NOME]; // Creating the responsible vector to set the household appliance

float potenciaEletrodomesticos[MAX_RESIDENCIA][MAX_ELETRODOMESTICO];
int horasEnergizadoDia[MAX_RESIDENCIA][MAX_HORAS];
int eletrodomesticoResidencia[MAX_RESIDENCIA];
int residencias = 0;

void registrandoResidencias(){

    if(residencias >= MAX_RESIDENCIA){
        printf("Limite excedido. \n");
        return;
    }

    printf("Digite o nome de sua residencia: ");
    scanf("%s", residencia[residencias]);

    eletrodomesticoResidencia[residencias] = 0;

    char opcao = OPCAO_SIM;
    while(opcao == 's' || opcao == 'S'){
        
        if(eletrodomesticoResidencia[residencias] >= MAX_ELETRODOMESTICO){
            printf("Limite excedido. \n");
            return;
        }

        printf("Digite o nome do eletrodomestico: ");
        scanf("%s", eletrodomesticos[residencias][eletrodomesticoResidencia[residencias]]);

        printf("Digite a potencia(kWh) de consumo deste eletrodomestico: ");
        scanf("%f", &potenciaEletrodomesticos[residencias][eletrodomesticoResidencia[residencias]]);

        printf("Informe a quantidade de horas(h) estimada que o eletrodomestico eh utilizado por dia: ");
        scanf("%d", &horasEnergizadoDia[residencias][eletrodomesticoResidencia[residencias]]);
        
        eletrodomesticoResidencia[residencias] ++;

        printf("Deseja adicionar outro eletrodomestico? (s/n): ");
        scanf("%s", &opcao);
    }
    residencias ++;
}

void listaResidencias(){
    if (residencias == 0){
        printf("Nenhuma residencia cadastrada. \n");
        return;
    }

    printf("\nLista de residencias cadastradas: \n");
    for (int i = 0; i < residencias; i++) {
        printf("%d. %s\n", i + 1, residencia[i]);
    }
}

float visualizarResidencia(){
    if(residencias == 0){
        printf("Nenhuma residencia cadastrada. \n");
        return 0;
    }

    listaResidencias();

    int opcao;
    printf("\nDigite o numero da residencia que deseja visualizar: ");
    scanf("%d", &opcao);

    if(opcao < 1 || opcao > residencias){
        printf("Opcao invalida. \n");
        return 0;
    }

    int indiceResidencia = opcao - 1;

    float consumoTotalHora = 0;

    printf("\nResidencia: %s\n", residencia[indiceResidencia]);
    printf("Eletrodomesticos e suas potencia: \n");

    for (int i = 0; i < eletrodomesticoResidencia[indiceResidencia]; i++){
        printf("- %s (Potencia: %.2fW) | %dh de uso por dia\n", eletrodomesticos[indiceResidencia][i], potenciaEletrodomesticos[indiceResidencia][i], horasEnergizadoDia[indiceResidencia][i]);
        consumoTotalHora += potenciaEletrodomesticos[indiceResidencia][i] / 1000;
    }
    return consumoTotalHora;
}

float calcular(){

    int num;

    float consumoTotalHora = visualizarResidencia();
    float consumoTotalDia = 0;

    char opcao = 's';

    while (opcao != 's' || opcao != 'S'){
        printf("Digite a quantidade de dias que deseja calcular o consumo de sua residencia: ");
        scanf("%d", &num);

        consumoTotalDia = consumoTotalHora * (num * DIA);

        printf("\nEm %d dias, sua residencia tera um consumo de %.2fkWh\n", num, consumoTotalDia);
        printf("Deseja realizar um novo calculo de consumo? (s/n): ");
        scanf("%s", &opcao);
    } 
    
    return 0;
}

