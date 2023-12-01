//
// Created by Ranya STITOU on 26/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


t_graphe * initialisation_graphe(t_operation * ops, t_exclusion * exc, int nombre_operation, int nombre_exclusion){
    //int nombre_operation = sizeof (ops) / sizeof ()

    t_graphe * g = (t_graphe *) malloc(sizeof (t_graphe));


    for(int i = 0; i<nombre_operation; i++){
        for(int j=0; j<nombre_operation; j++){
            g->matrice_ad[i][j] = 0; //pas d'opération initialement dans le graphe
        }
    }

    for(int i = 0; i<nombre_exclusion; i++){
        int index_op1 = get_index(ops, exc[i].op1);
        int index_op2 = get_index(ops, exc[i].op2);
        g->matrice_ad[index_op1][index_op2] = 1;
        g->matrice_ad[index_op2][index_op1] = 1;

    }

    return g;
}

int * coloration_graphe(t_graphe * g){
    int nombre_operation = 31;
    int nombre_exclusion = 20;
    int couleur_affectee;
    int* couleur = (int*) malloc(sizeof (int) * nombre_operation);
    //initialisation de la couleur
    for (int i =0; i<nombre_operation; i++){
        couleur[i]= -1;
    }

    couleur[0] = 0;//initialisation du premier noeud avec couleur 0
    int * couleur_valable = (int*) malloc(sizeof (int) * nombre_operation);

    for(int i = 1; i<nombre_operation; i++){
        //affectation des autres couleurs aux autres noeuds en fonctions des couleurs disponibles
        for(int j=0; j<nombre_operation; j++){
            couleur_valable[j] = 1; // ==> dit que toutes les autres couleurs sont disponibles
        }
        for(int j=0; j<nombre_operation; j++){
            if((g->matrice_ad[i][j] != 0) && couleur[j] != -1){
                couleur_valable[couleur[j]] = 0;
            }
        }
        couleur_affectee = 0;
        for(int j = 0; j<nombre_operation ; j++){
            if(couleur_valable[j] == 1){
                couleur_affectee = j;
                break;
            }
        }
        couleur[i] = couleur_affectee;
    }
    return couleur;
}

t_graphe * init_graphe_bis(t_operation * ops, t_exclusion * exc, t_precedence * prs, int nombre_operation, int nombre_exclusion, int nombre_precedence){

    t_graphe * g = (t_graphe *) malloc(sizeof (t_graphe));


    for(int i = 0; i<nombre_operation; i++){
        for(int j=0; j<nombre_operation; j++){
            g->matrice_ad[i][j] = 0; //pas d'opération initialement dans le graphe
        }
    }

    for(int i = 0; i<nombre_exclusion; i++){ //contrainte d'exclusion qui correspond aux relations bi-directionnel de notre graphe
        int index_op1 = get_index(ops, exc[i].op1);
        int index_op2 = get_index(ops, exc[i].op2);
        g->matrice_ad[index_op1][index_op2] = 1;
        g->matrice_ad[index_op2][index_op1] = 1;
    }

    for(int i = 0; i<nombre_precedence; i++){//contrainte de précédence qui correspond aux relations uni-directionnel de notre graphe
        int index_op1 = get_index(ops, prs[i].sommet_d);
        int index_op2 = get_index(ops, prs[i].sommet_f);
        g->matrice_ad[index_op1][index_op2] = 1;

    }

    return g;
}
