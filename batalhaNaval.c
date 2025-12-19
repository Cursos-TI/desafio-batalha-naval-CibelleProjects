#include <stdio.h>

/**
 * Desafio: Posicionando Navios no Tabuleiro (Nível Novato)
 * Objetivo: Criar um tabuleiro 10x10, posicionar dois navios (tamanho 3)
 * e exibir o resultado no console.
 */

int main() {
    // Definição do tamanho do tabuleiro e dos navios
    int rows = 10;
    int cols = 10;
    int shipSize = 3;
    
    // Matriz 10x10 representando o tabuleiro (inicializada com 0 - Água)
    int tabuleiro[10][10];

    // 1. Inicialização do Tabuleiro
    // Preenche todas as posições com 0 usando loops aninhados
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionamento do Navio Horizontal
    // Coordenadas iniciais: Linha 2, Coluna 2
    int rowH = 2, colH = 2;
    
    // Verificação simples de limite (Garante que o navio caiba na linha)
    if (colH + shipSize <= cols) {
        for (int j = 0; j < shipSize; j++) {
            tabuleiro[rowH][colH + j] = 3; // O valor 3 representa o navio
        }
    }

    // 3. Posicionamento do Navio Vertical
    // Coordenadas iniciais: Linha 5, Coluna 8
    int rowV = 5, colV = 8;
    
    // Verificação de limite e sobreposição simples
    if (rowV + shipSize <= rows) {
        for (int i = 0; i < shipSize; i++) {
            // Verifica se a posição já está ocupada (evita sobreposição)
            if (tabuleiro[rowV + i][colV] == 0) {
                tabuleiro[rowV + i][colV] = 3;
            }
        }
    }

    // 4. Exibição do Tabuleiro no Console
    printf("--- TABULEIRO DE BATALHA NAVAL ---\n\n");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Imprime o valor da posição seguido de um espaço para organização
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha ao fim de cada linha da matriz
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}