//Amanda Jhennifer Marques Vieira
// matrícula 20200831


//uma robo na posicao (0,0), a origem em um plano 2d. dada uma sequencia de seus movimentos julgue se este robo termina em (0,0), apos completar seus movimentos
//esta é a sequencia de movimentos que representam a sequencia de movimentos do robo, onde: moves[i] representa seu i-ésimo movimento.Os movimentos válidos são R(direita),L(esquerda), U(para cima), D(para baixo)
//faça uma função que retorna verdadeiro se o robo  retornar a origem após terminar todos os seus movimentos, ou falso caso contrário.
//bool judgeCircle(char*moves);

#include <stdio.h>   
#include <stdbool.h> 
#include <string.h>  

// diz se e a sequência de movimentos retorna a posição inicial
bool judgeCircle(char* moves, int x0, int y0) {
    int x = x0, y = y0; // como é 2d o plano, vou usar as coordenadas x e y do plano cartesiano

  
  printf("%d, %d\n", x, y);
    for (int i = 0; i < strlen(moves); i++) {
        if (moves[i] == 'U') {
            y++;
        } else if (moves[i] == 'D') {
            y--;
        } else if (moves[i] == 'R') {
            x++;
        } else if (moves[i] == 'L') {
            x--;
        } else {
        }
    }

  printf("%d, %d\n", x, y);
    
    // verificando se o robo volta a posição inicial
    if (x == x0 && y == y0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char moves[100]; // arranjo de caractere pra armazenar a sequencia de eventos do robo
    int x0 = 0, y0 = 0;      // coordenadas iniciais
        
    // NAO ENTENDI SE O EXERCICIO SOLICITA QUE O USUARIO POSSA INTERAGIR COM O PROGRAMA E ESCOLHER A SEQUENCIA
    // solicita que o usuário insira a sequência de movimentos do robô
    printf("Insira a sequencia de movimentos do robo: ");
    scanf("%s", moves);
    
    // verificando se o robo volta ou nao pra posicao inicial
    bool result = judgeCircle(moves, x0, y0);
    
    // RESULTADO
    if (result) {
        printf("O robo retornou a posicao inicial :D \n");
    } else {
        printf("O robo nao retornou a posicao inicial :( \n");
    }
    
    return 0;
}