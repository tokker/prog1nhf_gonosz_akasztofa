#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaelem.h"
#include <time.h>
#include "hosszusagot_sorsol.h"
#include "leggyakoribb.h"
#include <math.h>
#include "akasztofat_rajzol.h"
#include "econio.h"
#include "torlesek.h"
//#include "debugmalloc.h"

int main(void){

    srand(time(NULL));

    Lista *lista=fajlbeolvasas("magyar_ascii.txt");

    int betuk_szama = hosszusagot_sorsol(lista);
    mas_hossut_torol(betuk_szama,lista);

    printf("\n  A kezdeshez nyomj entert!\n");
    while(getchar() != '\n');

    printf("  A kitalalando szo %d betus.\n",betuk_szama);
    int j = 0;
    int x = betuk_szama;
    int betuk[26] = {0};
    char *szo = (char*) malloc(betuk_szama*sizeof(char));
    for(int i = 0;i<betuk_szama;++i)
        szo[i] = '_';

    while(x != 0 && j<10){
        printf("\n  Tippelj egy beture, ami szerinted benne van a szoban!\n  ");
        for(int w = 0; w<lista->elso->kov->hossz; ++w){
            printf("%c ", szo[w]);
        }
        printf("\n");
        int y = 0;
        for(int h = 0;h<26;++h){
            if(betuk[h] == 1)
                ++y;
        }
        if(y != 0)
            printf("\n  Felhasznalt betuk: ");
        for(int h = 0;h<26;++h){
            if(betuk[h] == 1)
                printf("%c ", 'a' + h);
        }
        printf("\n  ");

        char *beolvas = (char*) malloc(10*sizeof(char));
        scanf("\n%10s", beolvas);

        econio_clrscr();
        if(beolvas[1] != '\0'){
            printf("\n  Csak egy betut irj be!\n");
            akasztofat_rajzol(j);
            continue;
        }

        char betu = beolvas[0];
        free(beolvas);
        if((betu - 'a'<0) | (betu - 'a' >25)){
            printf("\n  Ervenytelen karakter. Kerlek az angol abc kisbetui kozul valassz!\n");
            akasztofat_rajzol(j);
            continue;
        }

        if(betuk[betu - 'a'] == 1){
            printf("\n  Ezt a betut mar felhasznaltad.\n");
            akasztofat_rajzol(j);
            continue;
        }

        betuk[betu - 'a'] = 1;
        int *gyak = leggyakoribb(lista,betu);
        int null = 0;
        for(int v = 0; v<lista->elso->kov->hossz; ++v){
            null+= gyak[v];
        }
        if(null == 0){
            printf("\n  Nem talalhato %c betu a szoban.\n", betu);
            ++j;
        }
        else {
            printf("\n  Van %c betu a szoban:\n", betu);
            for(int q = 0; q<lista->elso->kov->hossz; ++q){
                if(gyak[q] == 1){
                    if((q + 1 == 1) | (q + 1 == 5))
                        printf("  Az %d.\n",q + 1);
                    else
                        printf("  A %d.\n",q + 1);
                    --x;
                    szo[q] = betu;
                }
            }
        }

        akasztofat_rajzol(j);

        mast_torol(betu, gyak, lista);
        free(gyak);
    }

    econio_clrscr();

    if(j == 10){
        akasztofat_rajzol(j);
        printf("\n  Sajnos vesztettel :(\n");
    }
    else
        printf("\n  Gratulalok, nyertel :)\n");

    char nevelo[3];
    if((lista->elso->kov->szo[0] == 'a') | (lista->elso->kov->szo[0] == 'e') | (lista->elso->kov->szo[0] == 'i') | (lista->elso->kov->szo[0] == 'o') | (lista->elso->kov->szo[0] == 'u')){
        strcpy(nevelo,"az");
        nevelo[3] = '\0';
    }
    else{
        nevelo[0] = 'a';
        nevelo[1] = '\0';
    }

    printf("  A gondolt szo %s \"%s\" volt.\n", nevelo, lista->elso->kov->szo);

    free(szo);
    listat_felszabadit(lista);

    return 0;
}
