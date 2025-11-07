#include <stdio.h>
int main()
{

    char colunaa[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
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
                            //FORMAS

    // cruz 7
    int i_inicio = 0;                // linha inicial do tabuleiro
    int j_inicio = 0;                // coluna inicial do tatuleiro
    int linhaf = 3;                  // linha da forma
    int colunaf = 5;                 // coluna da forma
    int linhac = 1;                  // centro da linha da forma
    int colunac = 2;                 // centro da coluna da forma

    for (int i = 0; i < linhaf; i++)  //linha da forma
    { 
        int linhat = i_inicio + i;     // linha do tabuleiro

        for (int j = 0; j < colunaf; j++)   // coluna da forma
        {                              
            int colunat = j_inicio + j;    // coluna do tabuleiro

            if (i == linhac || j == colunac)
            {
                // Colisão
                if (tabuleiro[linhat][colunat] == 3)
                {
                    tabuleiro[linhat][colunat] = 1;
                }
                // agua
                else if (tabuleiro[linhat][colunat] == 0)
                {
                    tabuleiro[linhat][colunat] = 7;
                }
            }
        }
    }
    /**/ 
    // cone 5

    int l_comeco = 1; // tabuleiro
    int c_comeco = 4; // tabuleiro

    int linha_f = 3;  // forma
    int coluna_f = 5; // forma

    int centralc = 2; // centro da coluna
    for (i = 0; i < linha_f; i++)
    {
        int dist_max = i;          // limite
        int linhat = l_comeco + i; // linha tabuleiro

        for (j = 0; j < coluna_f; j++) // coluna da matriz
        {

            int dif = centralc - j;                 // indice central -j
            int distancia = (dif < 0) ? -dif : dif; // calculo de distancia

            int forma = (distancia <= dist_max) ? 5 : 0; // forma exibida

            int colunat = c_comeco + j; // coluna da tabuleiro

            if (forma == 5)
            {
                // Colisão
                if (tabuleiro[linhat][colunat] == 3)
                {
                    tabuleiro[linhat][colunat] = 1;
                }
                // agua
                else if (tabuleiro[linhat][colunat] == 0)
                {
                    tabuleiro[linhat][colunat] = forma;
                }
            }
        }
    }
    // octogono 8
    int linha1 = 7;  // linha do tabuleiro
    int coluna1 = 1; // coluna fdo tabuleiro

    int linhasdaforma = 3;  // linhas da forma
    int colunasdaforma = 5; // coluna da forma
    int centrodacoluna = 2; // Índice central

    for (i = 0; i < linhasdaforma; i++) // loop local linha
    {
        for (j = 0; j < colunasdaforma; j++) // loop local coluna
        {

            // movimento no tabuleiro
            int linhat = linha1 + i;
            int colunat = coluna1 + j;

            int figura = 0; // armazena o valor que será exibido

          
            // condição para a linha 2 (indice central-j<i)
            if (i == 1)
            {

                // calculo para medir a distancia horizontalmente
                int diferenca = centrodacoluna - j;
                int distancia_atual = (diferenca < 0) ? -diferenca : diferenca; // calculo de valor absoluto
                int distancia_maxima = i;                                       // i=1

                figura = (distancia_atual <= distancia_maxima) ? 8 : 0;//verifica forma
            }
            else
            { // Linha 1 e Linha 3
             //apenas o indice central da coluna será "pintado"
            
                figura = (j == centrodacoluna) ? 8 : 0;
            }

            if (figura == 8)
            {
                   //colisão
                if (tabuleiro[linhat][colunat] == 3)
                {
                    tabuleiro[linhat][colunat] = 1;
                }
                // agua
                else if (tabuleiro[linhat][colunat] == 0)
                {
                    tabuleiro[linhat][colunat] = figura;
                }
            }
        }
    }

    // EXIBIÇÃO DO TABULEIRO
     printf("\n TABULEIRO DE BATALHA NAVAL\n");
     printf("\n");
    for (j = 0; j < 10; j++) // letras
    {
        printf("  %c", colunaa[j]);
    }
     printf("\n");
   // printf("\n");

    for (i = 0; i < 10; i++) // tabuleiro
    {                        // linhas
        printf("%d", i + 0);
        for (j = 0; j < 10; j++)
        { // coluna
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
         //exibição de elementos
         printf("\n");
         printf("água: 0\n");
         printf("colisão entre navio e forma: 1\n");
         printf("navio: 3\n");
         printf("cone: 5\n");
         printf("cruz: 7\n");
         printf("octogono:8 \n");

    return 0;
}
