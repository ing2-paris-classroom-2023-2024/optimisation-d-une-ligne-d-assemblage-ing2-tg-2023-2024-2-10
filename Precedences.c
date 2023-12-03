//
// Created by Ambrine on 26/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_PRECEDENCE 100

t_precedence* lirefichier_pr(int * nombre_prs){
    FILE* fichier = fopen("../precedences.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier: precedence\n");
        exit(-1);
    }
    * nombre_prs = 0;

    //tableau qui contient les informations d'une opération. cette table contient le numéro de l'opération,
    t_precedence * precedences = (t_precedence*) malloc(sizeof (t_precedence) * MAX_PRECEDENCE);

    //EOF : End of File
    while (fscanf(fichier, "%d%d", &precedences[* nombre_prs].sommet_d, &precedences[* nombre_prs].sommet_f) != EOF){
        (* nombre_prs)++;
    }
    return precedences;
}

void afficher_pr(t_precedence * prs, int num){
    for (int i = 0; i<num ; i++){
        printf("la station %d precede la station %d\n", prs[i].sommet_d, prs[i].sommet_f);
    }
}

t_graphe * init_graphe(t_operation * ops, t_precedence* prs, int nombre_op, int nombre_prs){
//int nombre_operation = sizeof (ops) / sizeof ()

    t_graphe * g = (t_graphe *) malloc(sizeof (t_graphe));


    for(int i = 0; i<nombre_op; i++){
        for(int j=0; j<nombre_op; j++){
            g->matrice_ad[i][j] = 0; //pas d'opération initialement dans le graphe
        }
    }

    for(int i = 0; i<nombre_prs; i++){
        int index_op1 = get_index(ops, prs[i].sommet_d);
        int index_op2 = get_index(ops, prs[i].sommet_f);
        g->matrice_ad[index_op1][index_op2] = 1;

    }
    return g;
}

int * tri_topologique (t_graphe* g, int * pile_index, int * ordre, int nombre_operation){
    int * pile = (int*) malloc(sizeof (int) * nombre_operation);
    int * visite = (int*) malloc(sizeof (int) * nombre_operation);
    *pile_index = 0;

    for(int i =0; i<nombre_operation; i++){
        visite[i] = 0;
    }

    for (int i = 0; i < nombre_operation; i++) {
        if(visite[i] == 0 && ordre[i] == 0){
            tri_topologique_dfs(i, g, visite, pile, pile_index, nombre_operation, 0); //renvoie au dfs lorsque le somment n'a jamais été
            //visité
        }
    }

    return pile;
}

void tri_topologique_dfs (int o, t_graphe * g, int * visite, int * pile, int * pile_index, int nombre_operations, int profondeur){
    //o ==> sommet de départ du dfs
    visite[o] = profondeur;
    for(int i = 0; i<nombre_operations; i++){
        if(g->matrice_ad[o][i] != 0 && visite[i] == 0){ //[o][i] : on cherche s'il existe une relation entre le sommet o et un autre sommet du graphe
            tri_topologique_dfs(i, g, visite, pile, pile_index, nombre_operations, profondeur+1);
        }
    }

    //*pile_index = *pile_index + 1;
    pile[o]= profondeur;
}
