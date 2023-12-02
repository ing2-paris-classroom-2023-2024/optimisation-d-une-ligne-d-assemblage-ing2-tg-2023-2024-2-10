//
// Created by Ranya STITOU on 26/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_OPERATION 100


t_operation* lirefichier_op(int * nombre_obs){

    FILE* fichier = fopen("../operations.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier: operations\n");
        exit(-1);
    }
    * nombre_obs = 0;

    //tableau qui contient les informations d'une opération. cette table contient le numéro de l'opération,
    // le temps de l'opération et la couleur
    t_operation * operations = (t_operation*) malloc(sizeof (t_operation) * MAX_OPERATION);

    //EOF : End of File
    while (fscanf(fichier, "%d%f", &operations[* nombre_obs].num_operation, &operations[* nombre_obs].temps_operation) != EOF){
        (* nombre_obs)++;
    }
    return operations;
}

void afficher_op(t_operation * ops, int num){
    for (int i = 0; i<num ; i++){
        printf("numero operation: %d \t temps d'execution: %f\n", ops[i].num_operation, ops[i].temps_operation);
    }
}

int get_index(t_operation* ops, int num){
    for (int i = 0; i<num; i++){
        if(ops[i].num_operation == num){
            return i;
        }
    }
    return -1;
}