//
// Created by Ambrine on 26/11/2023.
//

#include "Precedences.h"
#define MAX_PRECEDENCE 100

t_precedence* lirefichier_pr(){
    FILE* fichier = fopen("precedences.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    int i = 0;

    //tableau qui contient les informations d'une opération. cette table contient le numéro de l'opération,
    // le temps de l'opération et la couleur
    t_precedence * precedences = (t_precedence*) malloc(sizeof (t_precedence) * MAX_PRECEDENCE);

    //EOF : End of File
    while (fscanf(fichier, "%d%d", &precedences[i].sommet_d, &precedences[i].sommet_f) != EOF){
        i++;
    }
    return precedences;
}

void afficher_pr(t_precedence * prs, int num){
    for (int i = 0; i<num ; i++){
        printf("la station %d precede la station %d\n", prs[i].sommet_d, prs[i].sommet_f);
    }
}