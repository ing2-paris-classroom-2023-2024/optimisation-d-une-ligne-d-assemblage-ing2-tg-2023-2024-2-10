//
// Created by Ranya STITOU on 26/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_GRAPHE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_GRAPHE_H
#define MAX_OPS 100
#include "Operations.h"
#include "Exclusion.h"

typedef struct graphe{
    int matrice_ad[MAX_OPS][MAX_OPS];
    int nombre_noeud;
}t_graphe;


t_graphe * initialisation_graphe(t_operation * ops, t_exclusion * exc);
int * coloration_graphe(t_graphe * g);


#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_GRAPHE_H
