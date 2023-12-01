//
// Created by Ranya STITOU on 01/12/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_HEADER_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_HEADER_H

//#include "Graphe.h"
//#include "Operations.h"
//#include "Exclusion.h"
//#include "Precedences.h"
//#include "Temps_de_cycle.h"
#define MAX_OPS 100

typedef struct precedence{
    int sommet_d;
    int sommet_f;
}t_precedence;

typedef struct temps{
    int temps;
}t_temps_cycle;

typedef struct exclusion{
    int op1;
    int op2;
}t_exclusion;

typedef struct graphe {
    int matrice_ad[MAX_OPS][MAX_OPS];
    int nombre_noeud;
}t_graphe;

typedef struct operation{
    int num_operation;
    float temps_operation;
    int couleur;
}t_operation;

t_precedence* lirefichier_pr(int * nombre_prs);
void afficher_pr(t_precedence * prs, int num);
t_graphe * init_graphe(t_operation * ops, t_precedence* prs, int nombre_op, int nombre_prs);
int * tri_topologique (t_graphe* g, int * pile_index);
void tri_topologique_dfs (int o, t_graphe * g, int * visite, int * pile, int * pile_index);

t_graphe * initialisation_graphe(t_operation * ops, t_exclusion *exc, int nombre_operation, int nombre_exclusion);
t_graphe * init_graphe_bis(t_operation * ops, t_exclusion *exc, t_precedence * prs, int nombre_operation, int nombre_exclusion, int nombre_precedence);
int * coloration_graphe(t_graphe * g);

t_temps_cycle * lirefichier_tmps();
void afficher_tmps(t_temps_cycle * temps_cycle, int num);

t_exclusion * lirefichier_ex(int * nombre_ex);
void afficher_ex(t_exclusion * exc, int num_e);
//int *coloration_g_ex(t_exclusion * g, t_exclusion * exc, int * ordre);
int *coloration_g_ex(t_graphe * g, t_exclusion * exc, int * ordre);

t_operation* lirefichier_op(int * nombre_obs);
void afficher_op(t_operation * ops, int num);
int get_index(t_operation* ops, int num);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_10_HEADER_H
