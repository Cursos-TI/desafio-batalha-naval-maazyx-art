#include <stdio.h>
int main()
{

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0}; // AGUA=0
    int i, j, k;                 // inicializadores

    // NAVIOS
    // NAVIO NA DIAGONAL PRINCIPAL
    for (k = 0; k < 3; k++)
    {
        tabuleiro[k][k] = 3;
    }
    // NAVIO NA  DIAGONAL SECUNDARIA
    int inicio = 0;
    int tamanho = 3;
    for (k = 0; k < tamanho; k++)
    {
        int linha = inicio + k;
        int coluna = 9 - linha;
        if (linha < 10 && coluna >= 0)
        {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // NAVIO NA HORIZONTAL

    for (j = 3; j <= 5; j++)
    {
        tabuleiro[0][j] = 3;
    }
    // NAVIO NA VERTICAL
    for (i = 3; i <= 5; i++)
    {
        tabuleiro[i][9] = 3;
    }

    printf("\n TABULEIRO DE BATALHA NAVAL\n");

    for (j = 0; j < 10; j++) // letreiro
    {
        printf("  %c", linha[j]);
    }
    printf("\n");

    // tabuleiro
    //  int i;
    for (i = 0; i < 10; i++)
    { // linhas
        printf("%d ", i + 0);
        for (j = 0; j < 10; j++)
        { // coluna
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("água: 0\n");
    printf("navio: 3\n");

    return 0;
}
