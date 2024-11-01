#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo os valores de entrada máximo de cada vetor
#define MAX_RESIDENCIA 100
#define MAX_ELETRODOMESTICO 100
#define MAX_NOME 100
#define MAX_HORAS 24

// Preço médio do kWh de cada estado
// Região Norte
#define AC 0.733   // Acre
#define AM 0.820   // Amazonas
#define AP 0.722   // Amapá
#define PA 0.879   // Pará
#define RO 0.657   // Rondônia
#define RR 0.657   // Roraima
#define TO 0.762   // Tocantins
// Região Nordeste
#define AL 0.750   // Alagoas
#define BA 0.760   // Bahia
#define CE 0.709   // Ceará
#define MA 0.651   // Maranhão
#define PB 0.599   // Paraíba
#define PE 0.706   // Pernambuco
#define PI 0.743   // Piauí
#define RN 0.662   // Rio Grande do Norte
#define SE 0.646   // Sergipe
// Região Centro Oeste
#define DF 0.740   // Distrito Federal
#define GO 0.750   // Goiás
#define MT 0.795   // Mato Grosso
#define MS 0.790   // Mato Grosso do Sul
// Região Sudeste
#define ES 0.730   // Espírito Santo
#define MG 0.810   // Minas Gerais
#define RJ 0.780   // Rio de Janeiro
#define SP 0.740   // São Paulo
// Região Sul
#define PR 0.700   // Paraná
#define RS 0.780   // Rio Grande do Sul
#define SC 0.720   // Santa Catarina

#define OPCAO_SIM 's'

// Vetores para armazenar os dados
char residencia[MAX_RESIDENCIA][MAX_NOME]; // Vetor resposável pela criação de cada residencia
char eletrodomesticos[MAX_RESIDENCIA][MAX_ELETRODOMESTICO][MAX_NOME]; // Vetor responsável pelo armazenamento de cada eletrodoméstico

float potenciaEletrodomesticos[MAX_RESIDENCIA][MAX_ELETRODOMESTICO]; // Vetor resposável pelo armazenamento das potencias de cada eletrodoméstico
int horasEnergizadoDia[MAX_RESIDENCIA][MAX_HORAS]; // Vetor responsável pelo armazenamento da quantidade de horas do uso de cada eletrodoméstico
int eletrodomesticoResidencia[MAX_RESIDENCIA]; // Vetor responsável pelo armazenamento de cada eletrodoméstico por residência
int residencias = 0;

//------------------------------------------------------------------------------------------------------------------//
// Função responsável pela criação das residências e pelo armazenamento de cada eletrodoméstico na residência criada
void registrandoResidencias(){

    system("cls");

    if(residencias >= MAX_RESIDENCIA){
        printf("Limite excedido. \n");
        return;
    }

    printf("Digite o nome de sua residencia: ");
    scanf("%s", residencia[residencias]);
    printf("---------------------------------------------------------------------------------------\n");

    eletrodomesticoResidencia[residencias] = 0;

    char opcao = OPCAO_SIM;

    while(opcao == 's' || opcao == 'S'){    
        if(eletrodomesticoResidencia[residencias] >= MAX_ELETRODOMESTICO){
            printf("Limite excedido. \n");
            return;
        }

        printf("Digite o nome do eletrodomestico: ");
        scanf("%s", eletrodomesticos[residencias][eletrodomesticoResidencia[residencias]]);

        printf("---------------------------------------------------------------------------------------\n");

        printf("Digite a potencia(kWh) de consumo deste eletrodomestico: ");
        scanf("%f", &potenciaEletrodomesticos[residencias][eletrodomesticoResidencia[residencias]]);

        printf("---------------------------------------------------------------------------------------\n");

        printf("Informe a quantidade de horas(h) estimada que o eletrodomestico eh utilizado por dia: ");
        scanf("%d", &horasEnergizadoDia[residencias][eletrodomesticoResidencia[residencias]]);

        float horasFormatadas = horasEnergizadoDia[residencias][eletrodomesticoResidencia[residencias]];

        if (horasFormatadas > 24){
            printf("Valor invalido. Informe a quantidade de horas dentro de um dia (24h): ");
            scanf("%d", &horasEnergizadoDia[residencias][eletrodomesticoResidencia[residencias]]);
        }
        
        printf("---------------------------------------------------------------------------------------\n");

        eletrodomesticoResidencia[residencias] ++;

        printf("Deseja adicionar outro eletrodomestico? (s/n): ");
        scanf("%s", &opcao);

        system("cls");
    }
    residencias ++;
}
//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------//
// Função responsável por exibir todas as residências criadas
void listaResidencias(){
    system("cls");
    if (residencias == 0){
        printf("Nenhuma residencia cadastrada. \n");
        printf("---------------------------------------------------------------------------------------\n");
        return;
    }

    printf("\nLista de residencias cadastradas: \n");
    for (int i = 0; i < residencias; i++) {
        printf("%d. %s\n", i + 1, residencia[i]);
    }
}
//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------//
// Função responsável por exibir e dar a opção de selecionar a residência criada para verificação de eletrodomésticos criados
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
        printf("---------------------------------------------------------------------------------------\n");
        printf("- %s (Potencia: %.2fkWh) | %dh de uso por dia\n", eletrodomesticos[indiceResidencia][i], potenciaEletrodomesticos[indiceResidencia][i], horasEnergizadoDia[indiceResidencia][i]);
        printf("---------------------------------------------------------------------------------------\n");
        consumoTotalHora += potenciaEletrodomesticos[indiceResidencia][i] * horasEnergizadoDia[indiceResidencia][i];
    }
    return consumoTotalHora;
}
//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------//
// Função responsável por executar a conversão de valores de Watts para kilowatts-hora
float conversaoValores(){

    system("cls");

    float num;
    float result;

    int opcao;
    
    printf("\nBem-vindo(a) ao Conversor de Valores!\n");
    
    while (opcao != 2){
        printf("\n1. De W para kWh\n");
        printf("2. Voltar ao menu principal\n");
        printf("Digite a sua opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Digite o valor (W) que deseja converter em kWh: ");
            scanf("%f", &num);

            result = (num * 1) / 1000;

            printf("O valor %.2fW equivale a %.3fkWh\n", num, result);
            break;

        case 2:
            printf("Retornando..\n");
            break;
        default:
            break;
        }
    }
    return result;
}
//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------//
// Função responsável pela verificação da existência e retorno de cada valor por estado definido.
// Usuário entra com um valor, compara a string de entrada com a string na condição if e retorna o valor de kWh(valores #define no início do programa) dependendo da entrada. 
double valorEstado(char* opcao){
    if (strcmp(opcao, "AC") == 0) return AC; // Acre
    if (strcmp(opcao, "AM") == 0) return AM; // Amazonas
    if (strcmp(opcao, "AP") == 0) return AP; // Amapá
    if (strcmp(opcao, "PA") == 0) return PA; // Pará
    if (strcmp(opcao, "RO") == 0) return RO; // Rondônia
    if (strcmp(opcao, "RR") == 0) return RR; // Roraima
    if (strcmp(opcao, "TO") == 0) return TO; // Tocantins
    if (strcmp(opcao, "AL") == 0) return AL; // Alagoas
    if (strcmp(opcao, "BA") == 0) return BA; // Bahia
    if (strcmp(opcao, "CE") == 0) return CE; // Ceará
    if (strcmp(opcao, "MA") == 0) return MA; // Maranhão
    if (strcmp(opcao, "PB") == 0) return PB; // Paraíba
    if (strcmp(opcao, "PE") == 0) return PE; // Pernambuco
    if (strcmp(opcao, "PI") == 0) return PI; // Piauí
    if (strcmp(opcao, "RN") == 0) return RN; // Rio Grande do Norte
    if (strcmp(opcao, "SE") == 0) return SE; // Sergipe
    if (strcmp(opcao, "DF") == 0) return DF; // Distrito Federal
    if (strcmp(opcao, "GO") == 0) return GO; // Goiás
    if (strcmp(opcao, "MT") == 0) return MT; // Mato Grosso
    if (strcmp(opcao, "MS") == 0) return MS; // Mato Grosso do Sul
    if (strcmp(opcao, "ES") == 0) return ES; // Espírito Santo
    if (strcmp(opcao, "MG") == 0) return MG; // Minas Gerais
    if (strcmp(opcao, "RJ") == 0) return RJ; // Rio de Janeiro
    if (strcmp(opcao, "SP") == 0) return SP; // São Paulo
    if (strcmp(opcao, "PR") == 0) return PR; // Paraná
    if (strcmp(opcao, "RS") == 0) return RS; // Rio Grande do Sul
    if (strcmp(opcao, "SC") == 0) return SC; // Santa Catarina
    return 0.0;
}
//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------//
// Função responsável por efetuar o cálculo de consumos por residência e valor($) estimado da conta de luz, dependendo da quantidade de dias que o usuário enviar de entrada.
float calcular(){

    if(residencias == 0){
        printf("Nenhuma residencia cadastradas. \n");
        return 0;    
    }

    int num;

    float consumoTotalHora = visualizarResidencia();
    float consumoTotalDia = 0;

    char opcao = OPCAO_SIM;

    while (opcao == 's' || opcao == 'S'){
        printf("Digite a quantidade de dias que deseja calcular o consumo de sua residencia: ");
        scanf("%d", &num);

        consumoTotalDia = consumoTotalHora * num;

        printf("\nEm %d dias, sua residencia tera um consumo de %.2fkWh\n", num, consumoTotalDia);

        char estado[3];

        printf("Digite a sigla do estado de sua residencia: ");
        scanf("%2s", estado);

        double valor = valorEstado(estado);

        if (valor != 0.0) {
            printf("Valor em media do kWh para o estado %s e de: R$ %.3f | Valor estimado da conta de luz mensal: R$%.2f\n", estado, valor, valor * consumoTotalDia);
        } else {
            printf("Estado não encontrado.\n");
        }

        printf("Deseja realizar um novo calculo de consumo? (s/n): ");
        scanf("%s", &opcao);
    } 
    return 0;
}