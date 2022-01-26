#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void liberamapa(MAPA* m){ //(*m),linhas/ (*) acessar conteudo
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocamapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * m->colunas+1);
    }
}

void lemapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Erro na leitura de mapa\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for(int i = 0; i < m->linhas; i++ ){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}
void imprimemapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontramapa(MAPA* m, POSICAO* p, char c){

    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}
int ehvazia(MAPA* m, int x,int y){
    return m->matriz[x][y] == '.';
}
void andanomapa(MAPA* m, int heroix, int heroiy, int proxx, int proxy){
    char heroi = m->matriz[heroix][heroiy];
    m->matriz[heroix][heroiy] = '.';
    m->matriz[proxx][proxy] = heroi;    
}