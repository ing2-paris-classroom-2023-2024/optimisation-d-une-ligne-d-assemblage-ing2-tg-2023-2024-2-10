//
// Created by mrtnw on 26/11/2023.
//

#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_TEMPS 100

t_temps_cycle* lirefichier_tmps(){

    FILE* fichier = fopen("../temps_cycle.txt", "r");
    if (!fichier)
    {
        printf("Erreur de lecture fichier: temps\n");
        exit(-1);
    }
    int i = 0;

    t_temps_cycle * temps_cycle = (t_temps_cycle *) malloc(sizeof (t_temps_cycle) * MAX_TEMPS);

    //EOF : End of File
    while (fscanf(fichier, "%f", &temps_cycle[i].temps) != EOF){
        i++;
    }
    return temps_cycle;
}


void afficher_tmps(t_temps_cycle * temps_cycle, int num){
    for (int i = 0; i<num ; i++){
        printf("Le temps globale des opérations est : %f", temps_cycle[i].temps);
    }
}

int * ordonencement_temps(t_temps_cycle * temps, int nombre_operation, t_operation * ops){
    int nombre_station = 0;
    int placee;
    float temps_station[nombre_operation];
    int * resultat = (int *) malloc(sizeof (int) * nombre_operation);

    for (int i = 0; i < nombre_operation; i++) {
        temps_station[i] = 0;
        resultat[i] = -1;
    }

    t_operation * ops2 = (t_operation *) malloc(sizeof (t_operation) * nombre_operation);
    for (int i = 0; i < nombre_operation; i++) {
        ops2[i].temps_operation = ops[i].temps_operation;
        ops2[i].num_operation = ops[i].num_operation;
    }

    Tri_Croissant(ops2, nombre_operation);
    for(int i = 0; i<nombre_operation; i++){
        placee = 0;
        for (int j = 0; (j < nombre_station) && placee == 0; j++) {
            if((temps_station[j] + ops2[i].temps_operation) <= temps->temps){
                temps_station[j] += ops2[i].temps_operation;
                placee = 1;
                resultat[get_index(ops, ops2[i].num_operation)] = j ;
            }
        }
        if(placee == 0){
            temps_station[nombre_station] = ops2[i].temps_operation;
            resultat[get_index(ops, ops2[i].num_operation)] = nombre_station;
            nombre_station ++;
        }
    }
    return resultat;
}

void swap(t_operation * a, t_operation *b){
    //Intervertir le contenu des 2 variables a et b de type t_operation
    t_operation temps;
    temps.temps_operation = a->temps_operation;
    temps.num_operation = a->num_operation;

    a->temps_operation = b->temps_operation;
    a->num_operation = b->num_operation;
    b->temps_operation = temps.temps_operation;
    b->num_operation = temps.num_operation;
}

void Tri_Croissant(t_operation * array, int n) {
    //trier un tableau qui contient t_operation
    //Trier le tableau en fonction du temps d'opérations
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j].temps_operation > array[j + 1].temps_operation) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}