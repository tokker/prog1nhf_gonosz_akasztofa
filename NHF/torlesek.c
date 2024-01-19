#include "torlesek.h"
#include <stdio.h>
#include <stdlib.h>
#include "listaelem.h"
//#include "debugmalloc.h"

void listat_felszabadit (Lista *lista) {
    ListaElem *mozgo = lista->elso;
    while (mozgo != lista->utolso){
        ListaElem *torlendo;
        torlendo = mozgo;
        mozgo = mozgo->kov;
        if(torlendo != lista->elso)
            free(torlendo->szo);
        free(torlendo);
    }
    free(mozgo);
    free(lista);
}

void mas_hossut_torol(int n, Lista *lista){
    ListaElem *mozgo = lista->elso->kov;
    while (mozgo != lista->utolso){
        if(mozgo->hossz != n){
            ListaElem *torlendo = mozgo;
            mozgo = mozgo->kov;
            torlendo->elozo->kov = torlendo->kov;
            torlendo->kov->elozo = torlendo->elozo;
            if(torlendo != lista->elso)
                free(torlendo->szo);
            free(torlendo);
        }
        else{
            int x = 0;
            for(int i = 0;i < n;++i){
                if(((mozgo->szo[i] < 'a') | (mozgo->szo[i] > 'z')) && ((mozgo->szo[i] < 'A') | (mozgo->szo[i] > 'Z'))){
                        x = 1;
                }
            }
            if (x == 1){
                ListaElem *torlendo = mozgo;
                mozgo = mozgo->kov;
                torlendo->elozo->kov = torlendo->kov;
                torlendo->kov->elozo = torlendo->elozo;
                if(torlendo != lista->elso)
                    free(torlendo->szo);
                free(torlendo);
                }
            else
                mozgo = mozgo->kov;
        }
    }
}

void mast_torol(char betu, int *n, Lista *lista){
    ListaElem *mozgo = lista->elso->kov;
    while(mozgo != lista->utolso){
        int g = 0;
        for(int i = 0; i<mozgo->hossz; ++i){
            if((((mozgo->szo[i] == betu) | (mozgo->szo[i] == betu + ('A' - 'a')))  && n[i] == 0) | (((mozgo->szo[i] != betu) && (mozgo->szo[i] != betu + ('A' - 'a')))  && n[i] == 1)){
                g = 1;
            }
        }
        if (g == 1){
            ListaElem *torlendo = mozgo;
            mozgo = mozgo->kov;
            torlendo->elozo->kov = torlendo->kov;
            torlendo->kov->elozo = torlendo->elozo;
            if(torlendo != lista->elso)
                free(torlendo->szo);
            free(torlendo);
            }
        else
            mozgo = mozgo->kov;
    }
}
