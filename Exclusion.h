//
// Created by Ranya STITOU on 26/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H

typedef struct exclusion{
    int op1;
    int op2;
}t_exclusion;

t_exclusion * lirefichier_ex();
void afficher_ex(t_exclusion * exc, int num_e);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_EXCLUSION_H
