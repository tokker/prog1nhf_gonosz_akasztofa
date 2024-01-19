#include <stdio.h>
#include <stdlib.h>
#include "listaelem.h"
#include <math.h>
#include "leggyakoribb.h"
//#include "debugmalloc.h"

int *leggyakoribb(Lista *lista, char betu){
    ListaElem *mozgo = lista->elso->kov;
    int z = pow(2,mozgo->hossz);
    int *tomb = (int*) malloc(z*sizeof(int));
    for(int p = 0;p<z;++p)
        tomb[p] = 0;
    int nagy = 'A'-'a';
    while(mozgo != lista->utolso){
        int x = 0;
        for(int i = 0;i<mozgo->hossz;++i){
            if((mozgo->szo[i] == betu) | (mozgo->szo[i] == betu + nagy))
                x+= pow(2,i);
        }
        ++tomb[x];
        mozgo = mozgo->kov;
    }
    int max = 0;
    for(int k = 1;k<z;++k){
        if(tomb[max]<tomb[k])
            max = k;
    }
    int *tomb2 = (int*) malloc(lista->elso->kov->hossz*sizeof(int));
    for(int s = lista->elso->kov->hossz-1;s >= 0; --s){
        if(max >= pow(2,s)){
            max-= pow(2,s);
            tomb2[s] = 1;
        }
        else
            tomb2[s] = 0;
    }
    free(tomb);
    return tomb2;
}
