#include <stdio.h>
#include <stdlib.h>
#include "pac.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

int ehdirecao(char direcao){
    return 
        direcao == 'a' ||
        direcao == 'w' || 
        direcao == 's' ||
        direcao == 'd';
}

void move(char direcao){

    if(!ehdirecao(direcao))return;

    int proximax = heroi.x;
    int proximay = heroi.y;
   

    switch (direcao){
        case 'a':
            proximay--;
            break;
        case 'w':
            proximax--;
            break;
        case 's':
           proximax++;
            break;
        case 'd':
           proximay++;
            break;
    }
    if(!ehvazia(&m, proximax, proximay))return;
    //sem o return caso seja maior que o mapa, pq se for nao vai ter '.'
    andanomapa(&m, heroi.x, heroi.y, proximax, proximay);

    heroi.x = proximax;
    heroi.y = proximay;
}

int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, '@');

    do{
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    }while(!acabou());


    liberamapa(&m);

}