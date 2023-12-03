//
// Created by Ranya STITOU on 26/11/2023.
//

#include <stdio.h>
#include "Header.h"


int main() {

    int nombre_op;
    int nombre_ex;
    int nombre_prs;

    t_operation* ops = lirefichier_op(&nombre_op);
    afficher_op(ops,31);

    t_exclusion* exc = lirefichier_ex(&nombre_ex);
    afficher_ex(exc, 20);

    t_graphe * g = initialisation_graphe(ops, exc, nombre_op, nombre_ex);
    int * couleur = coloration_graphe(g);

    for(int i = 0; i<31; i++){
        printf("Couleur de %d: %d\n", ops[i].num_operation, couleur[i]);
    }

    t_precedence* prs = lirefichier_pr(&nombre_prs);
    afficher_pr(prs, 34);

    t_temps_cycle * t = lirefichier_tmps();
    afficher_tmps(t, 1);

    t_graphe * g2 = init_graphe(ops, prs, nombre_op, nombre_prs);
    int pile_index = 0;
    printf("%d\n", pile_index);
    int * tri_topo = tri_topologique(g2, &pile_index);
    printf("%d\n", pile_index);
    for(int i = 1; i<pile_index; i++){
        printf("la valeur numero %d du graphe est : %d\n", ops[i].num_operation, ops[tri_topo[i]].num_operation);
    }




    return 0;
}

