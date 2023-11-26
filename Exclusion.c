//
// Created by Ranya STITOU on 26/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "Exclusion.h"
#define MAX_EXCLUSIONS 100

t_exclusion * lirefichier_ex(){

    FILE* fichier = fopen("exclusion.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    //tableau qui contient les informations d'une opération. cette table contient le numéro de l'opération,
    // le temps de l'opération et la couleur
    t_exclusion * exclusion = (t_exclusion *) malloc(sizeof (t_exclusion) * MAX_EXCLUSIONS);

    int i=0;
    //EOF : End of File
    while (fscanf(fichier, "%d%d", &exclusion[i].op1, &exclusion[i].op2) != EOF){
        i++;
    }

    return exclusion;
}


void afficher_ex(t_exclusion * exc, int num_e){
    for (int i = 0; i<num_e ; i++){
        printf("numero d'exclusion 1 : %d \t numero d'exclusion 2 : %d\n", exc[i].op1, exc[i].op2);
    }
}