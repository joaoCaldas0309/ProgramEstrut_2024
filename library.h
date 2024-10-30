#include "library.c"

// Função responsável pela criação das residências e pelo armazenamento de cada eletrodoméstico na residência criada
void registrandoResidencias();
// Função responsável por exibir todas as residências criadas
void listaResidencias();
// Função responsável por exibir e dar a opção de selecionar a residência criada para verificação de eletrodomésticos criados
float visualizarResidencia();
// Função responsável por executar a conversão de valores de Watts para kilowatts-hora
float conversaoValores();
// Função responsável pela verificação da existência e retorno de cada valor por estado definido.
// Usuário entra com um valor, compara a string de entrada com a string na condição if e retorna o valor de kWh(valores #define no início do programa) dependendo da entrada.
double valorEstado(char* opcao);
// Função responsável por efetuar o cálculo de consumos por residência e valor($) estimado da conta de luz, dependendo da quantidade de dias que o usuário enviar de entrada.
float calcular();