#include <stdio.h>

int main()
{
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};

    // linha e colunaS
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3; // linha e coluna

    printf("\n TABULEIRO DE BATALHA NAVAL\n");
    // LETRAS
    int l;
    for (l = 0; l < 10; l++)
    {
        printf("  %c", linha[l]);
    }
    printf("\n");

    // tabuleiro
    int i, j;
    for (i = 0; i < 10; i++)
    { // linha
        printf("%2d", i + 1);
        for (j = 0; j < 10; j++)
        { // coluna
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
     printf("navio: 3\n");
    return 0;
}
