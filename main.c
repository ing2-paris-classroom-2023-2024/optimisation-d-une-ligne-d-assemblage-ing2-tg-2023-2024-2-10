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

    t_graphe * g3 = init_graphe_bis(ops, exc, prs, nombre_op, nombre_ex, nombre_prs);
    int * couleur_ex = coloration_g_ex(g3, tri_topo);
    for (int i = 1; i <nombre_op ; i++) {
        printf("Coloration sommet %d est: %d\n", ops[i].num_operation, couleur_ex[i]);
    }

    afficher_stations(g,ops,couleur,nombre_op);
    printf("\n\n");
    afficher_stations(g3, ops, couleur_ex, nombre_op);


    return 0;
}

void afficher_stations(t_graphe * g, t_operation * ops, int * couleur, int nombre_operation){
    int couleur_max = couleur[0];

    for (int i = 1; i <nombre_operation ; i++) {
        if(couleur[i] > couleur_max){
            couleur_max = couleur[i];
        }
    }
    for (int i = 0; i <= couleur_max; i++) {
        int n_b = 0; //nombre op
        float t = 0; //temps
        for (int j = 0; j < nombre_operation; ++j) {
            if(couleur[j] == i){
                n_b ++;
                t = t + ops[j].temps_operation;
            }
        }
        printf("--------------------------------\n");
        printf("STATION : %d     NB_OP : %d       Temps : %f  \n", (i+1), n_b, t);

        for (int j = 0; j < nombre_operation; ++j) {
            if(couleur[j] == i){
                printf("%d \t", ops[j].num_operation);
            }
        }
        printf("\n--------------------------------\n\n");
    }
}