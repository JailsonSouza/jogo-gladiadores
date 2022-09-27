/*
    Crie uma estrutura que represente um gladiador, a estrutura deve ter os membros: identificador,
    (um caractere), força, resistência e velocidade (número inteiro de 0 a 100). Crie um vetor com
    dessa estrutura (no mínimo 8 posições). Crie uma função que receba um vetor de gladiadores e 
    inicialize aleatoriamente as caracteristicas dos mesmos. OBS: os identificadores dos gladiadores
    devem ser letras maiusculas e não deve haver mais de um gladiador com o mesmo identificador

    Com base na questão anterior, crie uma função combate() que recebe como parâmetro duas estruturas
    do tipo gladiador. A função deve comparar e alterar os membros de cada estrutura como descrito
    abaixo. Na função main() use a função de combate de criar disputas entre os gladiadores, exiba os
    identificadores dos vencedores de cada comparação e mostre os valores dos membros de cada estrutura
    com os valores alterados após cada combate.

    1. O campo velocidade do primeiro é comparado ao campo velocidade do segundo
        (a) Se velocidade1 > velocidade2, então você deve diminuir a resistência do segundo em 5 pontos
        (b) Se velocidade1 < velocidade2, então você deve diminuir a resistência do primeiro em 5 pontos
        (c) Se velocidade1 == velocidade2, então não faça nada
    2. O campo força do primeiro é comparado ao campo resistência do segundo
        (a) Se força1 > resistência2, então você deve diminuir a resistência do segundo em 25 pontos.
        A função então retorna 1 informando que o primeiro venceu
        (b) Se força1 < resistência2, então você deve diminuir a resistência do primeiro em 15 pontos
        A função então retorna 2 informando que o segundo venceu
        (c) Se força1 == resistência2, a função então retorna 0 indicando que houve empate
    
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUM_GLADIADORES 10

typedef struct Gladiador{
    char identificador;
    int forca, ressistencia, velocidade;
} gladiador;

void imprimir_combate(gladiador g1, gladiador g2){
printf(" -- Gladiador %c --  -- Gladiador %c --\n", g1.identificador, g2.identificador);
        printf("| I:    %c           | I:    %c          |\n", g1.identificador, g2.identificador);
        printf("| F:    %02d          | F:    %02d         |\n", g1.forca, g2.forca);
        printf("| R:    %02d          | R:    %02d         |\n", g1.ressistencia, g2.ressistencia);
        printf("| V:    %02d          | V:    %02d         |\n", g1.velocidade, g2.velocidade);
        printf(" --------------------------------------\n");
}

int combate(gladiador *g1, gladiador *g2){
    printf("***    Combate de Gladiadores    ***\n");
        imprimir_combate(*g1, *g2);
        printf("### COMBATE INICIADO ###\n");
        if ((*g1).velocidade > (*g2).velocidade){
            printf("-> GLADIADOR %c PERDEU 5 PONTOS DE RESSISTENCIA \n", g2->identificador);
            (*g2).ressistencia -= 5;
        }else if ((*g1).velocidade < (*g2).velocidade){
            printf("-> GLADIADOR %c PERDEU 5 PONTOS DE FORCA \n", g1->identificador);
            (*g1).forca -= 5;
        }else if ((*g1).velocidade == (*g2).velocidade){
            printf("-> AMBOS OS GLADIADORES NAO SE DANIFICARAM \n");
            // fazer nada
        }

        if ((*g1).forca > (*g2).ressistencia){
            printf("-> GLADIADOR %c PERDEU 25 PONTOS DE RESSISTENCIA \n", g2->identificador);
            printf("-> GLADIADOR %c ACABOU PERDENDO O COMBATE \n", g2->identificador);
            (*g2).ressistencia -= 25;
            printf("-------------------------------------\n");
            return 1;
        }else if ((*g1).forca < (*g2).ressistencia){
            printf("-> GLADIADOR %c PERDEU 15 PONTOS DE FORCA \n", g1->identificador);
            printf("-> GLADIADOR %c ACABOU PERDENDO O COMBATE \n", g1->identificador);
            (*g1).forca -= 15;
            printf("-------------------------------------\n");
            return 2;
        }else if ((*g1).forca == (*g2).ressistencia){
            printf("-> AMBOS OS GLADIADORES NAO SE DANIFICARAM \n");
            printf("-------------------------------------\n");
            return 0;
        }
}

int main() {
    gladiador time[NUM_GLADIADORES];
    gladiador g1 = {'C', 37, 78, 40};
    gladiador g2 = {'L', 11, 57, 40};
    int result;   
    result = combate(&g1, &g2);
    if (result == 1){
        printf("-----------------------\n");
        printf("| GLADIADOR %c VENCEU |\n", g1.identificador);
        printf("-----------------------\n");
        imprimir_combate(g1, g2);
    }else if (result == 2){
        printf("-----------------------\n");
        printf("| GLADIADOR %c VENCEU |\n", g2.identificador);
        printf("-----------------------\n");
        imprimir_combate(g1, g2);
    }else if (result == 0){
        printf("----------------------------\n");
        printf("| OS GLADIADORES EMPATARAM |\n");
        printf("----------------------------\n");
        imprimir_combate(g1, g2);
    }
    return 0;
}