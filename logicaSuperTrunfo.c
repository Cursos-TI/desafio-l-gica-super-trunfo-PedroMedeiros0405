#include <stdio.h>
#include <string.h>  // Para operações com strings, se necessário (opcional aqui, mas boa prática)

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    // Declarações das variáveis para a Carta 1
    char estado1[3];  // Código do estado como string (ex: "SP")
    char codigocarta1[5];  // Código da carta como string (ex: "001")
    char nomecidade1[100];  // Nome da cidade (pode ter espaços)
    int populacao1;  // População em habitantes
    float area1;  // Área em km²
    float pib1;  // PIB em bilhões de reais
    int pontosturisticos1;  // Número de pontos turísticos
    float densidade1;  // Densidade populacional (calculada: população / área)
    float pib_per_capita1;  // PIB per capita (calculado: (PIB * 1e9) / população, em reais)

    // Declarações das variáveis para a Carta 2
    char estado2[3];  // Código do estado como string (ex: "RJ")
    char codigocarta2[5];  // Código da carta como string (ex: "002")
    char nomecidade2[100];  // Nome da cidade (pode ter espaços)
    int populacao2;  // População em habitantes
    float area2;  // Área em km²
    float pib2;  // PIB em bilhões de reais
    int pontosturisticos2;  // Número de pontos turísticos
    float densidade2;  // Densidade populacional (calculada)
    float pib_per_capita2;  // PIB per capita (calculado)

    // Instruções iniciais
    printf("Bem vindo ao cadastro de cartas do super trunfo de paises!\n");
    printf("Vamos cadastrar os dados de duas cartas. Siga as instrucoes abaixo.\n\n");

    // Cadastro da Carta 1
    printf("*** Cadastro da carta 1 ***\n");
    printf("Digite o codigo do estado da carta 1 (ex: SP): ");
    scanf(" %2s", estado1);  // Lê até 2 caracteres para código de estado
    limpar_buffer();

    printf("Digite o codigo da carta 1 (ex: 001): ");
    scanf(" %4s", codigocarta1);  // Limita a 4 caracteres para segurança
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    scanf(" %99[^\n]", nomecidade1);  // Lê linha com espaços, limita a 99 chars
    limpar_buffer();

    printf("Digite a populacao: ");
    scanf(" %d", &populacao1);
    limpar_buffer();

    printf("Digite a area (em km²): ");
    scanf(" %f", &area1);
    limpar_buffer();

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf(" %f", &pib1);
    limpar_buffer();

    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &pontosturisticos1);
    limpar_buffer();

    // Cadastro da Carta 2
    printf("\n*** Cadastro da carta 2 ***\n");
    printf("Digite o codigo do estado da carta 2 (ex: RJ): ");
    scanf(" %2s", estado2);
    limpar_buffer();  // Limpa o buffer após a leitura do estado

    printf("Digite o codigo da carta 2 (ex: 002): ");
    scanf(" %4s", codigocarta2);
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    scanf(" %99[^\n]", nomecidade2);
    limpar_buffer();

    printf("Digite a populacao: ");
    scanf(" %d", &populacao2);
    limpar_buffer();

    printf("Digite a area (em km²): ");
    scanf(" %f", &area2);
    limpar_buffer();

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf(" %f", &pib2);
    limpar_buffer();

    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &pontosturisticos2);
    limpar_buffer();

    // Cálculos dos atributos derivados
    // Densidade Populacional: população / área (em hab/km²)
    // Nota: Assume área > 0 para evitar divisão por zero; em produção, adicionar validação
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // PIB per capita: (PIB em bilhões * 1.000.000.000) / população (em reais por habitante)
    // Isso corrige as unidades para um valor realista (ex: ~R$ 50.000)
    float total_pib1 = pib1 * 1000000000.0f;  // PIB total em reais
    float total_pib2 = pib2 * 1000000000.0f;
    pib_per_capita1 = total_pib1 / (float)populacao1;
    pib_per_capita2 = total_pib2 / (float)populacao2;

    // Exibição dos dados das cartas, incluindo os calculados
    printf("\n\n*** Carta 1 ***\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigocarta1);
    printf("Nome da cidade: %s\n", nomecidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de pontos turisticos: %d\n", pontosturisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita1);

    printf("\n*** Carta 2 ***\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigocarta2);
    printf("Nome da cidade: %s\n", nomecidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de pontos turisticos: %d\n", pontosturisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita2);

    // Lógica de comparação: Escolha hardcoded de um atributo (aqui, "Populacao")
    // Para outros atributos, basta alterar esta seção (ex: comparar area1 > area2, etc.)
    // Para Densidade, inverter a lógica (menor vence)
    printf("\n\n*** Comparacao de Cartas ***\n");
    printf("Atributo escolhido para comparacao: Populacao\n");  // Hardcoded

    // Exibe os valores para o atributo escolhido (formato do exemplo do desafio)
    printf("Carta 1 - %s (%s): %d\n", nomecidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nomecidade2, estado2, populacao2);

    // Aqui está a implementação das estruturas if e if-else para determinar o vencedor
    // Regra: Para População (e outros exceto Densidade), o maior valor vence
    if (populacao1 > populacao2) {
        // Caso 1: Carta 1 tem maior valor
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
    } else if (populacao1 < populacao2) {
        // Caso 2: Carta 2 tem maior valor (usando else if para eficiência)
        printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
    } else {
        // Caso 3: Valores iguais (empate, usando else para cobrir o resto)
        printf("Resultado: Empate!\n");
    }

    printf("\nCadastro e comparacao concluidos!\n");

    return 0;
}

