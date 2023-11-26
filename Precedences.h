//
// Created by Ambrine on 26/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_PRECEDENCES_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_PRECEDENCES_H

typedef struct precedence{
    int sommet_d;
    int sommet_f;
}t_precedence;

t_precedence* lirefichier_pr();
void afficher_pr(t_precedence * prs, int num);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_PRECEDENCES_H
