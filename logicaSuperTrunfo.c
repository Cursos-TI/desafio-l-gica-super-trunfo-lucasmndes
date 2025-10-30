#include <stdio.h>

// Desafio Super Trunfo - Comparação Avançada (2 atributos)
// - Menu 1: escolher atributo 1 (switch)
// - Menu 2: escolher atributo 2 (switch) sem repetir o 1 (menu dinâmico)
// - Comparar cada atributo (if/else; densidade: MENOR vence)
// - Somar os valores dos DOIS atributos de cada carta e decidir o vencedor (operador ternário)
// Observação: seguimos a mesma estrutura simples do código original (sem funções/structs)

int main() {

  // Variáveis das duas cartas
  char estado1, estado2;
  char codigoCarta1[4], codigoCarta2[4];
  char nomeCidade1[50], nomeCidade2[50];
  int populacao1, populacao2;
  float area1, area2;
  float pib1, pib2;
  int pontosTuristicos1, pontosTuristicos2;
  float densidade1, densidade2, pibpercapta1, pibpercapta2;

  // Entrada de dados (mesma ideia do código anterior)
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

  // Cálculos derivados
  densidade1 = populacao1 / area1;
  densidade2 = populacao2 / area2;
  pibpercapta1 = pib1 / populacao1;  // calculado mas não usado na comparação deste desafio
  pibpercapta2 = pib2 / populacao2;

  // Exibição das cartas
  printf("\n===== CARTAS CADASTRADAS =====\n");
  printf("\nCarta 1 - %s (%c)\n", nomeCidade1, estado1);
  printf("População: %d\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: %.2f bilhões\n", pib1);
  printf("Pontos Turísticos: %d\n", pontosTuristicos1);
  printf("Densidade Demográfica: %.2f hab/km²\n", densidade1);

  printf("\nCarta 2 - %s (%c)\n", nomeCidade2, estado2);
  printf("População: %d\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: %.2f bilhões\n", pib2);
  printf("Pontos Turísticos: %d\n", pontosTuristicos2);
  printf("Densidade Demográfica: %.2f hab/km²\n", densidade2);

  // ==============================
  // MENUS DINÂMICOS
  // ==============================
  // Mapeamento dos atributos (códigos "fixos"):
  // 1 - População, 2 - Área, 3 - PIB, 4 - Pontos Turísticos, 5 - Densidade Demográfica
  int opcao1, opcao2;
  int attr1 = 0, attr2 = 0; // guardam o código "fixo" do atributo escolhido

  // Menu 1
  printf("\n===== MENU - Escolha o 1o atributo =====\n");
  printf("1 - População (maior vence)\n");
  printf("2 - Área (maior vence)\n");
  printf("3 - PIB (maior vence)\n");
  printf("4 - Pontos Turísticos (maior vence)\n");
  printf("5 - Densidade Demográfica (MENOR vence)\n");
  printf("Opção: ");
  scanf("%d", &opcao1);

  switch (opcao1) {
    case 1: attr1 = 1; break;
    case 2: attr1 = 2; break;
    case 3: attr1 = 3; break;
    case 4: attr1 = 4; break;
    case 5: attr1 = 5; break;
    default:
      printf("\nOpção inválida para o primeiro atributo. Encerrando.\n");
      return 0;
  }

  // Menu 2 (dinâmico): não mostra o attr1
  printf("\n===== MENU - Escolha o 2o atributo (diferente do 1o) =====\n");
  // Para manter simples, vamos reenumerar visualmente as opções disponíveis de 1 a 4,
  // e depois traduzir para o código fixo (1..5) do atributo real.
  int mostrador = 1;
  int opcao2_visual;
  int mapa_visual_para_real1 = 0, mapa_visual_para_real2 = 0, mapa_visual_para_real3 = 0, mapa_visual_para_real4 = 0;

  if (attr1 != 1) { printf("%d - População (maior vence)\n", mostrador); mapa_visual_para_real1 = (mapa_visual_para_real1 == 0) ? 1 : mapa_visual_para_real1; mostrador++; }
  if (attr1 != 2) { printf("%d - Área (maior vence)\n", mostrador); if (mapa_visual_para_real2 == 0) mapa_visual_para_real2 = 2; else if (mapa_visual_para_real3 == 0) mapa_visual_para_real3 = 2; else mapa_visual_para_real4 = 2; mostrador++; }
  if (attr1 != 3) { printf("%d - PIB (maior vence)\n", mostrador); if (mapa_visual_para_real2 == 0) mapa_visual_para_real2 = 3; else if (mapa_visual_para_real3 == 0) mapa_visual_para_real3 = 3; else mapa_visual_para_real4 = 3; mostrador++; }
  if (attr1 != 4) { printf("%d - Pontos Turísticos (maior vence)\n", mostrador); if (mapa_visual_para_real2 == 0) mapa_visual_para_real2 = 4; else if (mapa_visual_para_real3 == 0) mapa_visual_para_real3 = 4; else mapa_visual_para_real4 = 4; mostrador++; }
  if (attr1 != 5) { printf("%d - Densidade Demográfica (MENOR vence)\n", mostrador); if (mapa_visual_para_real2 == 0) mapa_visual_para_real2 = 5; else if (mapa_visual_para_real3 == 0) mapa_visual_para_real3 = 5; else mapa_visual_para_real4 = 5; mostrador++; }

  printf("Opção: ");
  scanf("%d", &opcao2_visual);

  // Traduz a escolha visual para o código real (1..5), evitando repetir o primeiro atributo
  // Como o primeiro "slot" visual já ficou mapeado em mapa_visual_para_real1 quando População estava disponível,
  // usamos uma lógica simples baseada no número de opções não exibidas.
  // Para manter o código simples e sem funções, validamos pela faixa e pelo mapeamento preenchido acima.
  if (opcao2_visual <= 0 || opcao2_visual >= mostrador) {
    printf("\nOpção inválida para o segundo atributo. Encerrando.\n");
    return 0;
  }

  // Recupera o atributo real do segundo menu
  // Observação: como montamos os mapas incrementalmente, precisamos checar qual deles corresponde ao índice escolhido.
  // Vamos reconstruir a mesma sequência para identificar o real:
  int contador_visual = 1;
  if (attr1 != 1) { if (contador_visual == opcao2_visual) attr2 = 1; contador_visual++; }
  if (attr1 != 2) { if (contador_visual == opcao2_visual) attr2 = 2; contador_visual++; }
  if (attr1 != 3) { if (contador_visual == opcao2_visual) attr2 = 3; contador_visual++; }
  if (attr1 != 4) { if (contador_visual == opcao2_visual) attr2 = 4; contador_visual++; }
  if (attr1 != 5) { if (contador_visual == opcao2_visual) attr2 = 5; contador_visual++; }

  if (attr2 == 0 || attr2 == attr1) {
    printf("\nSeleção inválida (atributo repetido). Encerrando.\n");
    return 0;
  }

  // ==============================
  // COMPARAÇÕES INDIVIDUAIS
  // ==============================
  // Vamos obter os valores (float) de cada atributo escolhido para cada carta,
  // mostrar os números e aplicar as regras:
  // - Geral: MAIOR vence
  // - Densidade Demográfica: MENOR vence
  float valor1_attr1 = 0.0f, valor2_attr1 = 0.0f;
  float valor1_attr2 = 0.0f, valor2_attr2 = 0.0f;

  // Exibir o que é attr1
  printf("\n===== COMPARAÇÃO - ATRIBUTO 1 =====\n");
  switch (attr1) {
    case 1: // População
      printf("Atributo: População (maior vence)\n\n");
      valor1_attr1 = (float)populacao1;
      valor2_attr1 = (float)populacao2;
      printf("Carta 1 - %s: %.2f habitantes\n", nomeCidade1, valor1_attr1);
      printf("Carta 2 - %s: %.2f habitantes\n\n", nomeCidade2, valor2_attr1);
      if (valor1_attr1 > valor2_attr1) {
        printf("Vencedor no Atributo 1: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr1 > valor1_attr1) {
          printf("Vencedor no Atributo 1: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 1: Empate\n");
        }
      }
      break;

    case 2: // Área
      printf("Atributo: Área (maior vence)\n\n");
      valor1_attr1 = area1;
      valor2_attr1 = area2;
      printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, valor1_attr1);
      printf("Carta 2 - %s: %.2f km²\n\n", nomeCidade2, valor2_attr1);
      if (valor1_attr1 > valor2_attr1) {
        printf("Vencedor no Atributo 1: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr1 > valor1_attr1) {
          printf("Vencedor no Atributo 1: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 1: Empate\n");
        }
      }
      break;

    case 3: // PIB
      printf("Atributo: PIB (maior vence)\n\n");
      valor1_attr1 = pib1;
      valor2_attr1 = pib2;
      printf("Carta 1 - %s: %.2f bilhões\n", nomeCidade1, valor1_attr1);
      printf("Carta 2 - %s: %.2f bilhões\n\n", nomeCidade2, valor2_attr1);
      if (valor1_attr1 > valor2_attr1) {
        printf("Vencedor no Atributo 1: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr1 > valor1_attr1) {
          printf("Vencedor no Atributo 1: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 1: Empate\n");
        }
      }
      break;

    case 4: // Pontos Turísticos
      printf("Atributo: Pontos Turísticos (maior vence)\n\n");
      valor1_attr1 = (float)pontosTuristicos1;
      valor2_attr1 = (float)pontosTuristicos2;
      printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, valor1_attr1);
      printf("Carta 2 - %s: %.2f pontos\n\n", nomeCidade2, valor2_attr1);
      if (valor1_attr1 > valor2_attr1) {
        printf("Vencedor no Atributo 1: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr1 > valor1_attr1) {
          printf("Vencedor no Atributo 1: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 1: Empate\n");
        }
      }
      break;

    case 5: // Densidade (MENOR vence)
      printf("Atributo: Densidade Demográfica (MENOR vence)\n\n");
      valor1_attr1 = densidade1;
      valor2_attr1 = densidade2;
      printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, valor1_attr1);
      printf("Carta 2 - %s: %.2f hab/km²\n\n", nomeCidade2, valor2_attr1);
      if (valor1_attr1 < valor2_attr1) {
        printf("Vencedor no Atributo 1: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr1 < valor1_attr1) {
          printf("Vencedor no Atributo 1: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 1: Empate\n");
        }
      }
      break;
  }

  // Atributo 2
  printf("\n===== COMPARAÇÃO - ATRIBUTO 2 =====\n");
  switch (attr2) {
    case 1: // População
      printf("Atributo: População (maior vence)\n\n");
      valor1_attr2 = (float)populacao1;
      valor2_attr2 = (float)populacao2;
      printf("Carta 1 - %s: %.2f habitantes\n", nomeCidade1, valor1_attr2);
      printf("Carta 2 - %s: %.2f habitantes\n\n", nomeCidade2, valor2_attr2);
      if (valor1_attr2 > valor2_attr2) {
        printf("Vencedor no Atributo 2: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr2 > valor1_attr2) {
          printf("Vencedor no Atributo 2: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 2: Empate\n");
        }
      }
      break;

    case 2: // Área
      printf("Atributo: Área (maior vence)\n\n");
      valor1_attr2 = area1;
      valor2_attr2 = area2;
      printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, valor1_attr2);
      printf("Carta 2 - %s: %.2f km²\n\n", nomeCidade2, valor2_attr2);
      if (valor1_attr2 > valor2_attr2) {
        printf("Vencedor no Atributo 2: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr2 > valor1_attr2) {
          printf("Vencedor no Atributo 2: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 2: Empate\n");
        }
      }
      break;

    case 3: // PIB
      printf("Atributo: PIB (maior vence)\n\n");
      valor1_attr2 = pib1;
      valor2_attr2 = pib2;
      printf("Carta 1 - %s: %.2f bilhões\n", nomeCidade1, valor1_attr2);
      printf("Carta 2 - %s: %.2f bilhões\n\n", nomeCidade2, valor2_attr2);
      if (valor1_attr2 > valor2_attr2) {
        printf("Vencedor no Atributo 2: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr2 > valor1_attr2) {
          printf("Vencedor no Atributo 2: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 2: Empate\n");
        }
      }
      break;

    case 4: // Pontos Turísticos
      printf("Atributo: Pontos Turísticos (maior vence)\n\n");
      valor1_attr2 = (float)pontosTuristicos1;
      valor2_attr2 = (float)pontosTuristicos2;
      printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, valor1_attr2);
      printf("Carta 2 - %s: %.2f pontos\n\n", nomeCidade2, valor2_attr2);
      if (valor1_attr2 > valor2_attr2) {
        printf("Vencedor no Atributo 2: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr2 > valor1_attr2) {
          printf("Vencedor no Atributo 2: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 2: Empate\n");
        }
      }
      break;

    case 5: // Densidade (MENOR vence)
      printf("Atributo: Densidade Demográfica (MENOR vence)\n\n");
      valor1_attr2 = densidade1;
      valor2_attr2 = densidade2;
      printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, valor1_attr2);
      printf("Carta 2 - %s: %.2f hab/km²\n\n", nomeCidade2, valor2_attr2);
      if (valor1_attr2 < valor2_attr2) {
        printf("Vencedor no Atributo 2: Carta 1 (%s)\n", nomeCidade1);
      } else {
        if (valor2_attr2 < valor1_attr2) {
          printf("Vencedor no Atributo 2: Carta 2 (%s)\n", nomeCidade2);
        } else {
          printf("Vencedor no Atributo 2: Empate\n");
        }
      }
      break;
  }

  // ==============================
  // SOMA DOS ATRIBUTOS E VENCEDOR FINAL (operador ternário)
  // ==============================
  // Soma os valores (em float) dos dois atributos para cada carta
  float soma1 = valor1_attr1 + valor1_attr2;
  float soma2 = valor2_attr1 + valor2_attr2;

  printf("\n===== SOMA DOS ATRIBUTOS =====\n");
  printf("Soma - Carta 1 (%s): %.2f\n", nomeCidade1, soma1);
  printf("Soma - Carta 2 (%s): %.2f\n\n", nomeCidade2, soma2);

  // Operador ternário para decidir e exibir o resultado final
  (soma1 > soma2) ? printf("Resultado Final: Carta 1 (%s) venceu pela soma!\n", nomeCidade1) :
  (soma2 > soma1) ? printf("Resultado Final: Carta 2 (%s) venceu pela soma!\n", nomeCidade2) :
                    printf("Resultado Final: Empate!\n");

  return 0;
}
