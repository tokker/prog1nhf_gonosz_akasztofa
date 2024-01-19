#include <stdio.h>
#include "akasztofat_rajzol.h"
//#include "debugmalloc.h"

void akasztofat_rajzol(int j){
    if(j>4)
        printf("     _ _ _\n");
    else
        printf("\n");
    if(j>5)
        printf("    |     |\n");
    else if (j>3)
        printf("    |\n");
    else
        printf("\n");
    if(j>6)
        printf("    |     O\n");
    else if (j>3)
        printf("    |\n");
    else
        printf("\n");
    if(j>7)
        printf("    |    \\ /\n");
    else if (j>2)
        printf("    |\n");
    else
        printf("\n");
    if(j>8)
        printf("    |     |\n");
    else if (j>2)
        printf("    |\n");
    else
        printf("\n");
    if(j>9)
        printf("    |    / \\\n");
    else if (j>1)
        printf("    |\n");
    else
        printf("\n");
    if (j>1)
        printf("    |\n");
    else
        printf("\n");
    if(j!=0)
        printf("   / \\ \n");
}



