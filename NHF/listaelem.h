#ifndef LISTAELEM_H_INCLUDED
#define LISTAELEM_H_INCLUDED

typedef struct ListaElem {
    char *szo;
    struct ListaElem *kov;
    struct ListaElem *elozo;
    int hossz;
} ListaElem;

typedef struct Lista {
    ListaElem *elso;
    ListaElem *utolso;
} Lista;

Lista *fajlbeolvasas(char* fajlnev);

#endif // LISTAELEM_H_INCLUDED
