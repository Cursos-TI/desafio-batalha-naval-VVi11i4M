#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho do tabuleiro

#define linhas 10
#define colunas 10

int main() {
    int tabuleiro[linhas][colunas];
    int agua = 0; // Valor para a agua
    int navio = 1; // Valor para os navios
    int poder = 5; // Valor para os poderes

    // Preenchendo toda a tabuleiro com a agua
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = agua;
        }
    }
    
    // Posicionando o navio na horizantal (Primeiro valor fixo e segundo varia +1 ou -1 para preencher na mesma linha)
    //tabuleiro[1][5] = navio; 
    //tabuleiro[1][5-1] = navio; 
    //tabuleiro[1][5+1] = navio; 

    for(int i = 2; i < linhas; i++) {
        for(int j = 5; j < 8; j++) {
            tabuleiro[i][j] = navio;}

    // Posicionando o navio na vertical (Primeiro valor varia +1 ou -1 para preencher na mesma coluna e segundo fixo)
    //tabuleiro[7][2] = navio; 
    //tabuleiro[7-1][2] = navio; 
    //tabuleiro[7+1][2] = navio;

    for(int i = 6; i < 9; i++) {
        for(int j = 2; j < 3; j++) {
            tabuleiro[i][j] = navio;}
        }

   // Para que a posição do navio diagonal fique como deseja, é necessário avaliar para onde ficara apontado
   // Nos casos que ficam apontados para o Nordeste (ponto central na tabuleiro; ponto central +1 e -1 & -1 e +1)
   // Nos casos que ficam apontados para o Noroeste (ponto central na tabuleiro; ponto central -1 e -1 & +1 e +1)

   // Posicionando o navio na diagonal (Ambos valores variam +1 ou -1)
   //tabuleiro[8][8] = navio; 
   //tabuleiro[8-1][8-1] = navio; 
   //tabuleiro[8+1][8+1] = navio;

   for(int i = 8; i > 7; i--){
    for(int j = 8; j > 7; j--)
    tabuleiro[i][j] = navio, tabuleiro[i-1][j-1] = navio, tabuleiro[i+1][j+1] = navio;  
   }// i = 6,7,8 e j = 6,7,8

   // Posicionando o navio na diagonal (Ambos valores variam +1 ou -1)
   //tabuleiro[5][5] = navio; 
   //tabuleiro[5+1][5-1] = navio; 
   //tabuleiro[5-1][5+1] = navio;

   for(int i = 5; i > 4; i--){
    for(int j = 5; j > 4; j--)
    tabuleiro[i][j] = navio, tabuleiro[i-1][j+1] = navio, tabuleiro[i+1][j-1] = navio;  
   }

   // Criando os poderes

   // Cone

    int pontaH = 2; // Onde será a ponta do cone na linha
    int pontaV = 3;  // Onde será a ponta do cone na coluna
    int altura = 3;  // Altura do cone 

    for (int linha = pontaH; linha < pontaH + altura; linha++) 
    {int largura = linha - pontaH; // Controla a expansao lateral
        for (int expansao = -largura; expansao <= largura; expansao++) {
            int coluna = pontaV + expansao;
            if (coluna >= 0 && coluna < colunas) { // Verifica limites
                tabuleiro[linha][coluna] = poder;
            }
        }
    }

// Cruz
int centroH = 5, centroV = 7;
for(int i = 0; i < linhas; i++) {
    for(int j = 0; j < colunas; j++) {
        // Linha horizontal do centro
        if(i == centroV && j >= centroH - 1 && j <= centroH + 1) {
            tabuleiro[i][j] = poder;
        }
        // Linha vertical do centro
        else if(j == centroH && i >= centroV - 1 && i <= centroV + 1) {
            tabuleiro[i][j] = poder;
        }
    }
}

// octaedro

int centro_oct_x = 7; // Coluna do centro
    int centro_oct_y = 2; // Linha do centro
    int raio_oct = 1;     // Tamanho do octaedro
    
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            // Calcula a distância de Manhattan para formar o diamante
            int dist = abs(i - centro_oct_y) + abs(j - centro_oct_x);
            
            // Se a distância for menor ou igual ao raio, preenche com poder
            if(dist <= raio_oct) {
                tabuleiro[i][j] = poder;
            }
        }
    }

    // Imprimindo a tabuleiro com os navios
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
}

