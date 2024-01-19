

ListaElem *eleje;
    char betu = (char*) malloc(sizeof(char));
    while(fscanf(fp,"%c", betu) != EOF){
        char *betuk = NULL;
        char *masolat = NULL;
        int j =1;
        while(fscanf(fp,"%c", &betu) != EOF && betu != '\n'){
            betuk = (char*) malloc((j+1) * sizeof(char));
            if (masolat != NULL){
                strcpy(betuk, masolat);
                betuk[j-1]=betu;
                betuk[j]='\0';
            }
            else {
                betuk[0]=betu;
                betuk[1]='\0';
            }
            masolat = (char*) malloc((j+1) * sizeof(char));
            strcpy(masolat, betuk);
            masolat[j]='\0';
            ++j;
        }
        eleje = (*ListaElem) malloc(sizeof(ListaElem));

    }
}
