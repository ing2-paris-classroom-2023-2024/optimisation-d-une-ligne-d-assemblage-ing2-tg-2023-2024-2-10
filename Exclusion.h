//
// Created by Ranya STITOU on 26/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H

typedef struct operation{
    int num_operation;
    float temps_operation;
    int couleur;
}t_operation;

t_operation* lirefichier_op();
void afficher_op(t_operation * ops, int num);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H
