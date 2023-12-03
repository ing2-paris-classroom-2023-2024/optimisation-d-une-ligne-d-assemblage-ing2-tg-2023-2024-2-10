//
// Created by Ranya STITOU on 26/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_EXCLUSIONS 100

t_exclusion * lirefichier_ex(int * nombre_ex){

    FILE* fichier = fopen("../exclusion.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier: exclusion\n");
        exit(-1);
    }

    //tableau qui contient les informations d'une opération. cette table contient le numéro de l'opération,
    // le temps de l'opération et la couleur
    t_exclusion * exclusion = (t_exclusion *) malloc(sizeof (t_exclusion) * MAX_EXCLUSIONS);

    * nombre_ex = 0;
    //EOF : End of File
    while (fscanf(fichier, "%d%d", &exclusion[*nombre_ex].op1, &exclusion[*nombre_ex].op2) != EOF){
        (*nombre_ex)++;
    }

    return exclusion;
}


void afficher_ex(t_exclusion * exc, int num_e){
    for (int i = 0; i<num_e ; i++){
        printf("numero d'exclusion 1 : %d \t numero d'exclusion 2 : %d\n", exc[i].op1, exc[i].op2);
    }
}

//int *coloration_g_ex(t_graphe * g, t_exclusion * exc, int * ordre){
int *coloration_g_ex(t_graphe * g, int * ordre){
    int nombre_operation = 31;
    int nombre_exclusion = 20;
    int couleur_affectee;
    int* couleur = (int*) malloc(sizeof (int) * nombre_operation);
    //initialisation de la couleur
    for (int i =0; i<nombre_operation; i++){
        couleur[i]= -1;
    }

    couleur[ordre[0]] = 0;//initialisation du premier noeud avec couleur 0
    int * couleur_valable = (int*) malloc(sizeof (int) * nombre_operation);

    for(int i = 1; i<nombre_operation; i++){
        int u = ordre[i]; //récupérer l'ordre de i
        for(int j=0; j<nombre_operation; j++){
            couleur_valable[j] = 1; // ==> dit que toutes les autres couleurs sont disponibles
            //pour ensuite parcourir les sommets voisins et "supprimer" les sommets voisins
        }

        for(int j=0; j<nombre_operation; j++){
            if((g->matrice_ad[u][j] != 0) && couleur[j] != -1){
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

}