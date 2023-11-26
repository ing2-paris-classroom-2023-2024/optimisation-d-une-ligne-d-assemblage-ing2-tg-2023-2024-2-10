//
// Created by mrtnw on 26/11/2023.
//

#include "Temps_de_cycle.h"
#DEFINE MAX_TEMPS = 100

t_operation* lirefichier_tmps(){

    FILE* fichier = fopen("temps_cycle.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    int i = 0;

    t_temps_cycle * temps_cycle = (t_temps_cycle *) malloc(sizeof (t_temps_cycle) * MAX_TEMPS);

    //EOF : End of File
    while (fscanf(fichier, "%d", &temps_cycle[i].temps) != EOF){
        i++;
    }
    return temps_cycle;
}

void afficher_tmps(t_temps_cycle * temps_cycle, int num){
    for (int i = 0; i<num ; i++){
        printf("Le temps globale des opérations est : %d", temps_cycle[i].temps);
    }
}