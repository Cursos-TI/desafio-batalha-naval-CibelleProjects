#include <stdio.h>

/**
 * DESAFIO: BATALHA NAVAL - NÍVEL NOVATO
 * Objetivo: Posicionar dois navios (um horizontal e um vertical) em uma matriz 10x10.
 */

int main() {
    // 1. Definição do Tabuleiro e Constantes
    #define TAM_TABULEIRO 10
    #define TAM_NAVIO 3
    
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializando o tabuleiro com 0 (Água)
    // Requisito: "Inicialize todas as posições do tabuleiro com o valor 0"
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definição das Coordenadas (Requisito funcional)
    // Navio Horizontal: Linha 2, Colunas 2, 3, 4
    int horizontalLinha = 2, horizontalColunaInicio = 2;
    
    // Navio Vertical: Coluna 8, Linhas 5, 6, 7
    int verticalLinhaInicio = 5, verticalColuna = 8;

    // 3. Validação e Posicionamento do Navio Horizontal
    // Verifica se o navio cabe na largura do tabuleiro
    if (horizontalColunaInicio + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[horizontalLinha][horizontalColunaInicio + j] = 3;
        }
    }

    // 4. Validação e Posicionamento do Navio Vertical
    // Verifica se o navio cabe na altura e se não sobrepõe o outro
    if (verticalLinhaInicio + TAM_NAVIO <= TAM_TABULEIRO) {
        // Validação simples de sobreposição: verifica se o espaço já está ocupado por '3'
        int livre = 1;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[verticalLinhaInicio + i][verticalColuna] == 3) {
                livre = 0;
                break;
            }
        }
        
        // Se estiver livre, posiciona
        if (livre) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[verticalLinhaInicio + i][verticalColuna] = 3;
            }
        }
    }

    // 5. Exibição do Tabuleiro (Requisito funcional)
    printf("--- TABULEIRO DE BATALHA NAVAL ---\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Espaço separador para legibilidade
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    printf("\nLegenda: 0 = Agua | 3 = Navio\n");

    return 0;
}
}
