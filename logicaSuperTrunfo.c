#include <stdio.h>

// Desafio Super Trunfo - Comparação de Cartas
// Tema 2 - Comparando Cartas com if e if-else
// Objetivo: comparar duas cartas com base em um único atributo (ex: População)

int main() {

  // Declaração das variáveis das duas cartas
  char estado1, estado2;
  char codigoCarta1[4], codigoCarta2[4];
  char nomeCidade1[50], nomeCidade2[50];
  int populacao1, populacao2;
  float area1, area2;
  float pib1, pib2;
  int pontosTuristicos1, pontosTuristicos2;
  float densidade1, densidade2, pibpercapta1, pibpercapta2;

  // Entrada de dados da primeira carta
  printf("Digite os dados da primeira cidade:\n");
  printf("Estado (letra de A a H): ");
  scanf(" %c", &estado1);
  printf("Código da Carta (Ex: A01): ");
  scanf("%s", codigoCarta1);
  printf("Nome da Cidade: ");
  scanf(" %[^\n]", nomeCidade1);
  printf("População: ");
  scanf("%d", &populacao1);
  printf("Área (em km²): ");
  scanf("%f", &area1);
  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib1);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos1);

  // Entrada de dados da segunda carta
  printf("\nDigite os dados da segunda cidade:\n");
  printf("Estado (letra de A a H): ");
  scanf(" %c", &estado2);
  printf("Código da Carta (Ex: B01): ");
  scanf("%s", codigoCarta2);
  printf("Nome da Cidade: ");
  scanf(" %[^\n]", nomeCidade2);
  printf("População: ");
  scanf("%d", &populacao2);
  printf("Área (em km²): ");
  scanf("%f", &area2);
  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib2);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos2);

  // Cálculo da densidade e PIB per capita
  densidade1 = populacao1 / area1;
  densidade2 = populacao2 / area2;
  pibpercapta1 = pib1 / populacao1;
  pibpercapta2 = pib2 / populacao2;

  // Exibição dos dados
  printf("\n===== CARTAS CADASTRADAS =====\n");
  printf("\nCarta 1 - %s (%c)\n", nomeCidade1, estado1);
  printf("População: %d\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: %.2f bilhões\n", pib1);
  printf("Pontos Turísticos: %d\n", pontosTuristicos1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
  printf("PIB per capita: %.2f\n", pibpercapta1);

  printf("\nCarta 2 - %s (%c)\n", nomeCidade2, estado2);
  printf("População: %d\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: %.2f bilhões\n", pib2);
  printf("Pontos Turísticos: %d\n", pontosTuristicos2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
  printf("PIB per capita: %.2f\n", pibpercapta2);

  // ==============================
  // COMPARAÇÃO (atributo escolhido)
  // ==============================
  // Aqui escolhemos "População" como atributo de comparação.
  // Basta trocar para "area", "pib", "densidade" ou "pibpercapta" se desejar.
  // Para densidade populacional, vence o MENOR valor.

  printf("\n===== COMPARAÇÃO DE CARTAS =====\n");
  printf("Atributo comparado: População\n\n");
  printf("Carta 1 - %s: %d habitantes\n", nomeCidade1, populacao1);
  printf("Carta 2 - %s: %d habitantes\n\n", nomeCidade2, populacao2);

  if (populacao1 > populacao2) {
      printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
  } else if (populacao2 > populacao1) {
      printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
  } else {
      printf("Resultado: Empate!\n");
  }

  return 0;
}
