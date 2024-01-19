#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaelem.h"
//#include "debugmalloc.h"

Lista *fajlbeolvasas(char* fajlnev){
    FILE *fp;
    fp = fopen(fajlnev , "rt");
    if (fp == NULL){
        perror("A fajlt nem sikerult megnyitni");
        return NULL;
    }
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->elso = (ListaElem*) malloc(sizeof(ListaElem));
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    ListaElem *mozgo;
    lista->elso->kov = uj;
    uj->elozo = lista->elso;
    char betu;
    while(fscanf(fp,"%c", &betu) != EOF){
        char *betuk = NULL;
        char *masolat = NULL;
        int j = 1;
        if(betu != '\n'){
            betuk = (char*) malloc((j+1) * sizeof(char));
            if (masolat != NULL){
                strcpy(betuk, masolat);
                betuk[j-1] = betu;
                betuk[j] = '\0';
            }
            else {
                betuk[0] = betu;
                betuk[1] = '\0';
            }
            masolat = (char*) malloc((j+1) * sizeof(char));
            strcpy(masolat, betuk);
            masolat[j] = '\0';
            ++j;
        }
        while(fscanf(fp,"%c", &betu) != EOF && betu != '\n'){
            free(betuk);
            betuk = (char*) malloc((j+1) * sizeof(char));
            if (masolat != NULL){
                strcpy(betuk, masolat);
                betuk[j-1] = betu;
                betuk[j] = '\0';
            }
            else {
                betuk[0] = betu;
                betuk[1] = '\0';
            }
            free(masolat);
            masolat = (char*) malloc((j+1) * sizeof(char));
            strcpy(masolat, betuk);
            masolat[j] = '\0';
            ++j;
        }
        uj->szo = (char*) malloc((j) * sizeof(char));
        strcpy(uj->szo,betuk);
        uj->szo[j-1] = '\0';
        uj->hossz = j-1;
        mozgo = uj;
        uj->kov = (ListaElem*) malloc(sizeof(ListaElem));
        uj = uj->kov;
        uj->elozo = mozgo;
        free(betuk);
        free(masolat);
    }
    lista->utolso = uj;
    lista->utolso->elozo = mozgo;
    fclose(fp);

    return lista;
}
