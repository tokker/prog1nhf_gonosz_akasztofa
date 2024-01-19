#include <stdio.h>
#include <stdlib.h>
#include "listaelem.h"
#include <time.h>
#include "hosszusagot_sorsol.h"
//#include "debugmalloc.h"

int hosszusagot_sorsol(Lista *lista){
    int db = 0;
    ListaElem *mozgo = lista->elso->kov;
    while (mozgo != lista->utolso){
        ++db;
        mozgo = mozgo->kov;
    }
    int hanyadik = rand()%db;
    ListaElem *mozgo2 = lista->elso->kov;
    for (int i = 0;i<hanyadik;++i)
        mozgo2 = mozgo2->kov;
    return mozgo2->hossz;
}
