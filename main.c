//
// Created by Ranya STITOU on 26/11/2023.
//

#include <stdio.h>
#include "Exclusion.h"
#include "Operations.h"
#include "Graphe.h"
#include "Precedences.h"

int main() {

    t_operation* ops = lirefichier_op();
    afficher_op(ops,31);

    t_exclusion* exc = lirefichier_ex();
    afficher_ex(exc, 20);

    t_graphe * g = initialisation_graphe(ops, exc);
    int * couleur = coloration_graphe(g);

    for(int i = 0; i<31; i++){
        printf("Couleur de %d: %d\n", ops[i].num_operation, couleur[i]);
    }

    t_precedence* prs = lirefichier_pr();
    afficher_pr(prs, 34);

    t_temps_cycle * t = lirefichier_tmps();
    afficher_tmps(t, 1);

    return 0;
}